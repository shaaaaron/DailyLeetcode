import numpy as np
import argparse
from gurobipy import *
from tqdm import trange
import math
import time
import functools

def timer(func):
    """函数计时装饰器"""
    @functools.wraps(func)
    def wrapper_timer(*args, **kwargs):
        start_time=time.perf_counter()
        result = func(*args, **kwargs)
        end_time=time.perf_counter()
        run_time=end_time-start_time
        print(f"运行时间：{run_time:.4f}秒")
        return result
    return wrapper_timer


def haversine(lat1, lon1, lat2, lon2):
    R = 6371  # 地球半径，单位为公里
    phi1 = math.radians(lat1)
    phi2 = math.radians(lat2)
    delta_phi = math.radians(lat2 - lat1)
    delta_lambda = math.radians(lon2 - lon1)
    a = math.sin(delta_phi/2)**2 + math.cos(phi1) * math.cos(phi2) * math.sin(delta_lambda/2)**2
    c = 2 * math.atan2(math.sqrt(a), math.sqrt(1-a))
    distance = R * c
    return distance

def read_tsp(filename):
    with open(filename, 'r') as f:
        lines = f.readlines()

    edge_weight_type = None
    nodes = []
    weights = []
    edge_weights = False
    dimension = 0
    for line in lines:
        if line.startswith("EDGE_WEIGHT_TYPE"):
            edge_weight_type = line.split()[-1]
        if line.startswith("DIMENSION"):
            dimension = int(line.split()[-1])
        if line.startswith("NODE_COORD_SECTION"):
            edge_weights = True
            continue
        if edge_weights and edge_weight_type == "GEO":
            if line.strip() == "EOF":
                break
            parts = line.split()
            index = int(parts[0])
            lat = float(parts[1])
            lon = float(parts[2])
            nodes.append((lat, lon))
        if line.startswith("EDGE_WEIGHT_SECTION"):
            edge_weights = True
            continue
        if edge_weights and edge_weight_type == "EXPLICIT":
            if line.strip() == "DISPLAY_DATA_SECTION" or line.strip() == "EOF":
                break
            weights.extend(map(int, line.split()))
    
    if edge_weight_type == "GEO":
        weights = np.zeros((dimension, dimension))
        for i in range(dimension):
            for j in range(dimension):
                if i != j:
                    weights[i][j] = haversine(nodes[i][0], nodes[i][1], nodes[j][0], nodes[j][1])
    elif edge_weight_type == "EXPLICIT":
        weights_matrix = np.zeros((dimension, dimension))
        k = 0
        for i in range(dimension):
            for j in range(i + 1, dimension):
                weights_matrix[i][j] = weights[k]
                weights_matrix[j][i] = weights[k]
                k += 1
        weights = weights_matrix
    
    return weights

@timer
def solve_tsp_with_gurobi(weights):
    print("start solving tsp with gurobi...")
    model = Model("tsp")

    n = weights.shape[0]
    vars = {}
    for i in range(n):
        for j in range(i):
            vars[i,j] = model.addVar(obj=weights[i,j], vtype=GRB.BINARY, name='e'+str(i)+'_'+str(j))
            vars[j,i] = vars[i,j]

    for i in range(n):
        model.addConstr(sum(vars[i,j] for j in range(n) if j != i) == 2)

    model.setObjective(quicksum(vars[i,j] * weights[i,j] for i in range(n) for j in range(i)), GRB.MINIMIZE)

    model.optimize()

    solution = model.getAttr('x', vars)
    selected = [(i,j) for i,j in vars.keys() if solution[i,j] > 0.5]
    print("Selected edges in the optimal tour:")
    print(selected)
    return model.objVal

@timer
def solve_tsp_with_dp(weights):
    print("start solving tsp with dp...")
    n = len(weights)
    dp = [[float('inf')] * (1 << n) for _ in range(n)]
    dp[0][1] = 0

    for mask in trange(1 << n, desc="Processing masks"):
        for i in range(n):
            if not (mask & (1 << i)):
                continue
            for j in range(n):
                if mask & (1 << j):
                    continue
                dp[j][mask | (1 << j)] = min(dp[j][mask | (1 << j)], dp[i][mask] + weights[i][j])

    min_cost = min(dp[i][(1 << n) - 1] + weights[i][0] for i in range(n))
    print("Minimum cost using DP:", min_cost)
    return min_cost

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--filename', type=str, default="./txt/burma14.tsp", help='TSP file name')
    args = parser.parse_args()

    weights = read_tsp(args.filename)

    # warm up
    gurobi_cost = solve_tsp_with_gurobi(weights)
    gurobi_cost = solve_tsp_with_gurobi(weights)
    gurobi_cost = solve_tsp_with_gurobi(weights)
    dp_cost = solve_tsp_with_dp(weights)
    print(f"Gurobi cost: {gurobi_cost}")
    print(f"DP cost: {dp_cost}")

if __name__ == '__main__':
    main()

# python3 tsp.py --filename ./txt/bayg29.tsp;
# python3 tsp.py --filename ./txt/bays29.tsp;
# python3 tsp.py --filename ./txt/burma14.tsp;
# python3 tsp.py --filename ./txt/fri26.tsp;
# python3 tsp.py --filename ./txt/gr17.tsp;
# python3 tsp.py --filename ./txt/gr21.tsp;
# python3 tsp.py --filename ./txt/gr24.tsp;
# python3 tsp.py --filename ./txt/gr48.tsp;
# python3 tsp.py --filename ./txt/ulysses16.tsp;
# python3 tsp.py --filename ./txt/ulysses22.tsp;