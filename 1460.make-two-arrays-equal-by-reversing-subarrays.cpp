/*
 * @lc app=leetcode.cn id=1460 lang=cpp
 * @lcpr version=30122
 *
 * [1460] 通过翻转子数组使两个数组相等
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        sort(target.begin(),target.end());
        sort(arr.begin(),arr.end());
        return arr==target;
    }
};


// 对于序列容器（如 std::vector、std::deque、std::list 等），比较操作会按顺序比较容器中的元素，如果所有元素都相同并且顺序一致，那么这两个容器被认为是相等的。

// 对于关联容器（如 std::set、std::map、std::multiset、std::multimap 等），比较操作不仅比较元素，还考虑到了容器内部的排序规则。如果两个容器中的元素数量相同，并且每个键值对都等价（键相等且值相等），那么这两个容器被认为是相等的。

// 对于无序关联容器（如 std::unordered_set、std::unordered_map、std::unordered_multiset、std::unordered_multimap 等），比较操作会检查两个容器是否含有相同数量的元素，以及对应的键值对是否存在相等的元素。由于这些容器是基于哈希的，元素的顺序并不重要。

// 请注意，对于自定义类型的元素，要正确比较两个容器中的元素，这些类型必须支持相等比较操作。

// 总结一下，大多数 STL 容器都可以使用 == 和 != 进行比较，但是容器中元素的类型也必须支持这些比较操作。同时，对于无序容器，元素的相对顺序并不影响比较结果。
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4]\n[2,4,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [7]\n[7]\n
// @lcpr case=end

// @lcpr case=start
// [3,7,9]\n[3,7,11]\n
// @lcpr case=end

 */

