def find_insert_positions(arr, target):
    # 找到小于或等于target的最大元素的位置
    def lower_bound(arr, target):
        left, right = 0, len(arr) - 1
        while left <= right:
            mid = (left + right) // 2
            if arr[mid] <= target:
                left = mid + 1
            else:
                right = mid - 1
        return right  # 注意这里返回right

    # 找到大于target的最小元素的位置
    def upper_bound(arr, target):
        left, right = 0, len(arr) - 1
        while left <= right:
            mid = (left + right) // 2
            if arr[mid] <= target:
                left = mid + 1
            else:
                right = mid - 1
        return left  # 注意这里返回left
    
    position_leq = lower_bound(arr, target)  # 小于或等于target的最大元素的位置
    position_gt = upper_bound(arr, target)  # 大于target的最小元素的位置
    
    return position_leq, position_gt

# 示例
arr = [1, 2, 4, 4, 4, 4, 4, 4, 5, 6, 8]
target = 4
positions = find_insert_positions(arr, target)
print("小于或等于给定值的最大元素的插入位置:", positions[0], arr[positions[0]])
print("大于给定值的最小元素的插入位置:", positions[1], arr[positions[1]])


import bisect

# 示例列表
a = [1, 2, 2,2,2,2,2, 3, 4, 5, 6]

def bisect_left(arr, x):
    left, right = 0, len(arr) - 1  # 初始化right为最后一个有效索引
    while left <= right:  # 当left超过right时，结束循环
        mid = (left + right) // 2  # 计算中点
        if arr[mid] < x:
            left = mid + 1  # 移动左边界
        else:
            right = mid - 1  # 移动右边界
    return left  # 返回left作为插入点

# 使用 bisect_left 查找元素的位置
x = 2
# pos = bisect.bisect_left(a, x)
pos = bisect_left(a, x)
print(f'The leftmost position to insert, not greater than {x}, is {pos}')
# 如果位置在列表范围内，则可以直接访问
if pos < len(a):
    print(f'Found at {pos}:', a[pos])
