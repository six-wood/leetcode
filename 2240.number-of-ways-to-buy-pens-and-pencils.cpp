// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2240 lang=cpp
 * @lcpr version=21913
 *
 * [2240] 买钢笔和铅笔的方案数
 */
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
// @lc code=start
class Solution
{
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2)
    {
        int maxCost = max(cost1, cost2);
        int minCost = min(cost1, cost2);
        int maxNum = total / maxCost;
        int minNum = total / minCost;
        long long ans = 0;
        for (int i = 0; i <= maxNum; i++)
        {
           ans += (total - i * maxCost) / minCost + 1;
        }
        return ans;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=20\n10\n5\n
// paramTypes= ["number","number","number"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// 20\n10\n5\n
// @lcpr case=end

// @lcpr case=start
// 5\n10\n10\n
// @lcpr case=end

 */
