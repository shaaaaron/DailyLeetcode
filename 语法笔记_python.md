# python

## 基础
- str.substr(str.size()) 对应空字符串，不会报错
- 注意累加、相乘int会不会越界，需要需要使用long long
- 力口的判题策略是相同类生命一次，但是方法调用多次。因此使用全局变量需要重新初始化
- 全局变量在函数中使用需要global，否则相当于重新定义变量
- Python 中调用类函数需要使用self.前缀，并在函数参数中传入self
- 由于python中没有设置return的参数类型。所以`return visited[state]==1` 不能不要==1，否则返回的就是1(int)而不是true(bool)
- python中位操作和c++相同
- python没有三目运算符`?:`，但你可以使用行内的`if else`
- python中可以使用形如`if 0<=i+di<m and 0<=j+dj<n:`的判断，c++中则不可
- 迷宫/地图四个方向的遍历可以使用元组的迭代，`for di,dj in [(-1,0), (1,0), (0,1), (0,-1)]:`
- python中列表和np都是浅拷贝
- python3.6(?)之后支持下划线分割整数，增强了可读性，但leetcode不支持
- python在range逆序使用时，最后添加一个-1，最右边元素同样无法取到
- 如果结果要模$10^9+7$，则可以`(int)(1E9+7.1)`进行初始化
  - 结果和中间结果计算的时候都需要%PRIME，并且使用longlong防止加法和乘法导致的溢出。如果减法使用(a-b+PRIME)%PRIME保证结果是正数
- 提交leetcode时需要注释cout，否则会超时
- substr长度为非负数，因为类型是size_t
- str.substr(1); 默认substr到最后
- python中使用`chr`和`ord`能够进行字符和ascii序号的转化
- 字符转int，例如'0'转为0. 
    - c++使用str[i]-'0'。
    - python使用int(str[i])，可以直接类型转化
- python中由于数学运算不严格限制宽度，因此没有INT_MAX
- 在本地/2是浮点数除法，在leetcode上是整数除法，可能是因为return的是整数除法的结果，由于python版本产生了不同的结果。建议整数除法//2,浮点数除法/2.(有小数点)
- 类中的函数声明和调用都需要self
- `for j in range(len(nums)):` 如果循环如上通过range遍历，那么在循环中修改j没用！
- 下面是一个lambda函数的写法，应该包含
    ```
    auto getTwoNum = [&]() -> std::tuple<int, int> { // 访问当前作用域中的所有变量，返回值写法有点奇怪
        int y = s.top(); s.pop();
        int x = s.top(); s.pop();
        return {x, y}; // 返回一个包含两个整数的tuple
    };
    ```
- 1<<n就是$2^{n}$.c++中的左移位数必须是非负数，不能左移-1。位移运算符的优先级相当低
- C++ 的vector可以`ans.insert(ans.end(),left.begin(),left.end());`来把一个vector追加到另一个后面
- c++ `reverse(a.begin(), a.end())`可以反转数组，请注意不需要赋值
- `if(root)`就是判断root是不是空
- c++迭代器可以通过`iter--`, `iter=iter-1`进行更改

## 运算符优先级
下面是c++运算符，优先级从高到低
```c++
!       // 逻辑非
~       // 按位取反
*/%     // 乘除 
+-      // 加减
<< >>   // 位移

<= < >= >   // 比较运算符
== !=       // 比较运算符

&       // 按位运算
^
|

&&      // 逻辑
||

,       // 逗号
```
注意`位移`、`比较运算符`、`按位运算`的顺序
> 例如`x&1==0`先`比较`再`按位与`，正确的应该使用`(x&1)==0`
## 浮点数
python 
```python
import math
math.floor(2.7)
math.ceil(2.7)
math.isqrt(10) # 3，计算平方根下取整
```
C++中floor和ceil能返回整数，但是没有isqrt，只能根据返回的浮点数取证。

## 数学运算
```python
import math
math.pow(x,y)
math.log(x, base) # 不指定base默认为e
math.log2(x) 
math.log10(x) 
math.sqrt(x)

math.e,math.pi # 数学常数
```

```c++
#include <cmath>
pow(x,y)
log(x)  // 以e为底
log2(x)  
log10(x)
  
log(x)/log(2) // 换底公式
sqrt(x)
exp(1), atan(1)*4 // 不提供常数，需要手动计算
```

## 整数
```python
def lcm(a, b):
    return abs(a*b) // math.gcd(a, b)
```
c++同样通过`numeric`中的gcd辅助计算

也可以实现辗转相除法
## 随机数
```python
num = random.random() # [0,1)之间的随机浮点数
num = random.randint(a, b)  # [a,b]之间的随机整数
num = random.uniform(a, b)  # [a,b)之间的随机浮点数
```

```c++
rand()%100 // 生成[0，100)的整数
rand()/(RAND_MAX + 1.0) // 生成[0,1)d的随机浮点数
```

## 字符串
常见的python字符串操作包括：
```python
n*"a"   # 构造字符串，n可以为0返回空串
str.find('a')   # 查找字符，如果没找到返回-1.注意c++返回npos，python返回-1
```
- 大小写转化：
```python
# 转换为小写
lower = text.lower()
# 转换为大写
upper = text.upper()
```
- 字符串转数字
```python
str_num = "456"
str_pi = "3.14159"

# 字符串转数字
num = int(str_num)
pi = float(str_pi)
```
- 数字转字符串：
```python
num = 123
pi = 3.14159

# 数字转字符串
str_num = str(num)
str_pi = str(pi)
```
## 内置数组

- 内置数组支持迭代器：C++中内置数组支持迭代器的使用，例如下面的方法是合理的
```c++
int arr[] = {1, 2, 3, 4, 5};
for(auto it = std::begin(arr); it != std::end(arr); ++it) {
    std::cout << *it << " ";
}
```
理所当然的，你也可以使用algorithm/numeric中其他使用迭代器的函数对内置数组运算，如max_element/accumulare。

- 内置数组初始化：可以使用 C++ 的 algorithm 库中的 `fill` 函数，
```c++
int dp[80][80][80];
fill(&dp[0][0][0], &dp[0][0][0] + 80*80*80, INT_MIN);
```
## algorithm

- count：C++`count(s.begin(), a.end(), '1')`统计容器中指定字符的数量,python
`s.count('a')`统计字符串中指定字符的数量
- 区间排序：`ranges = sorted(ranges, key= lambda x: (x[0], x[1]))`根据lambda函数提供的元组/int，从小到大按顺序排列。关键字如果有多个，先根据第一个然后一次向后

- 对于无序数组，使用sort(coins.begin(), coins.end())进行排序，默认从小到大排序

  使用lambda函数比较简单，方括号内表示捕获变量

  ``` 
  std::sort(people.begin(), people.end(), [](const Person& a, const Person& b) {
      return a.age < b.age;
  });
  
  std::sort(strings.begin(), strings.end(), [](const std::string& a, const std::string& b) {
      return a.length() < b.length();
  });
  ```

## 列表
- 乘法运算：使用`[1]*n`可以正确，但是`[ [1,2], [3,4] ]*n`则不可以。原因是前者其中的对象是不可变，后者其中为可变对象。

## 字典

- 初始化：key和value可以是任意类型

  ```
  my_dict = {1: 100, 2: 200, 3: 300}
  ```

- 访问和修改：

  - 如果key可能不存在，使用`dict.get(key)`，不存在则返回None。不能用于修改。可以额外指定默认返回值
  - 如果key一定存在，使用`dict[key]`，可以用于修改

- 删除键值：`del my_dict[key] `或者`memo.pop(key, None)`。前者不返回元素。如果不添加None，找不到元素会返回异常

## vector
- 使用`b.resize(n, 0)`进行resize，0只会被用来对新添加的元素初始化，如果resize被用来减小响亮的大小，多余的元素会被丢弃。
- 可以直接`a=b;`进行拷贝构造赋值
## np

- `dp = np.full((n+5,n+5),0,dtype=int) `初始化显式写为int，否则可能返回浮点数出错



# 数据结构
## 栈
查看栈顶元素之前需要保证栈非空

python没有栈，使用列表
- 添加元素append
- 删除元素pop
- 查看栈顶元素s[-1]
- 栈的大小len(s)
- 是否为空len(s)==0

C++的栈需要`#include <stack>`
- 添加元素push
- 删除元素pop
- 查看栈顶元素top
- 栈的大小size()
- 是否为空empty
c++的栈std::stack的top()函数返回的是栈顶元素的引用，但是并不允许直接修改该引用。如果要修改栈顶元素，需要先将栈顶元素弹出，然后再将修改后的元素推入栈顶
## 优先队列
C++
`priority_queue<int, vector<int>> left_heap(left.begin(), left.end());`使已有的vec对优先队列进行初始化，默认大顶堆，`top`是最大元素，添加`greater<int>`参数使用小顶堆
> 这是因为默认使用less<int\>。而使用less会从大到小排序， 使用greater是从小到大排序。从前往后会越来越great
> 而不是我所理解a>=b，很怪
- 常用操作push、pop、top

python
```python 
import heapq
heap = []

heapq.heappush(heap, 10)
heapq.heappush(heap, 1)
top_element = heap[0]
top_element = heapq.heappop(heap)
```
headpq需要加入heap作为参数，并且heappop提供返回值。没有top提供顶部的访问，但是可以通过列表索引直接访问

如果需要定义class的比较方法，请实现元素的`__lt__`方法（小于比较）和`__eq__`方法（等于比较），并且使用`functools.total_ordering`，python装饰器会帮助你缺省的实现
> 产生的方法会比直接实现更多的比较方法稍微复杂一些。在性能敏感的应用中，直接实现所有必要的比较方法可能更为有效
```python
from functools import total_ordering

@total_ordering
class Item:
    def __init__(self, value):
        self.value = value
    
    def __lt__(self, other):
        return self.value < other.value
    
    def __eq__(self, other):
        return self.value == other.value

# 现在，Item类有了完整的比较功能
item1 = Item(5)
item2 = Item(10)
item3 = Item(5)

print(item1 < item2)  # True
print(item1 <= item2) # True, 通过total_ordering提供
print(item1 > item2)  # False
print(item1 >= item3) # True, 通过total_ordering提供
print(item1 == item3) # True
print(item1 != item2) # True, 通过total_ordering提供
```
## 双端队列
python的双端队列如下
> 注意pop和push都是队尾，不是一个队头一个队尾
```python
from collections import deque
dq=deque()
append(), appendleft(), pop(), popleft()
dq[0], dq[-1], len(dq)
```
C++ 的双端队列如下

```c++
#include <deque>

deque<int> dq;
dq.push_back(), dq.push_front(), dq.pop_back(), dq.pop_front()
dq.size(), dq.front(), dq.end()
```

## 有序集合
python中标准库没有 有序集合，C++中可以通过set<int\>实现有序集合，底层是红黑树实现
```c++
set<int> rec;
auto iter=rec.lower_bound(x); // 同样可以使用lower_bound返回迭代器
rec.insert(1);    //  插入元素，如果已有则不会操作
rec.erase(1);     // 删除对应值的元素
s1.erase(s1.begin()); // 删除迭代器指向的元素
rec.find(1)!=rec.end(); // 查找元素是否存在
rec.clear();      // 清空
rec.lower_bound();
rec.upper_bound(); // 内部就有二分的接口，返回迭代器，分别指向向第一个不小于给定值的元素和第一个大于给定值的元素
```
- 如果erase的元素不存在不会报错

## map
c++中的map分为map和unordered_map。

std::map：
- 实现：通常实现为红黑树，一个自平衡二叉搜索树。这意味着它的元素总是按照键的排序顺序存储。
- 时间复杂度：查找、插入、删除的时间复杂度都是O(log n)。

std::unordered_map
- 实现：基于哈希表实现。它使用哈希函数将键映射到存储桶中，不保证元素的顺序。
- 时间复杂度：平均是O(1)，最坏是O(n)

不同的接口在于map提供了lower_bound和upper_bound。

两种边里方法如下
```c++
for (const auto &pair : umap) {
    std::cout << pair.first << " => " << pair.second << '\n';
}

for (auto it = myMap.begin(); it != myMap.end(); ++it) {
std::cout << it->first << " => " << it->second << std::endl;
}
```
