// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2511 lang=cpp
 * @lcpr version=21913
 *
 * [2511] 最多可以摧毁的敌人城堡数目
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
    int captureForts(vector<int> &forts)
    {
        int fast = 0, slow = -1;
        int fast_bak = forts.size() - 1;
        int slow_bak = forts.size();
        int count = 0;
        for (; fast < forts.size(); ++fast)
        {
            if (forts[fast] == 1)
            {
                slow = fast;
            }
            else if (forts[fast] == -1 & slow >= 0)
            {
                count = max(count, fast - slow - 1);
                slow = -1;
            }
            if (forts[fast_bak] == 1)
            {
                slow_bak = fast_bak;
            }
            else if (forts[fast_bak] == -1 & slow_bak < forts.size())
            {
                count = max(count, slow_bak - fast_bak - 1);
                slow_bak = forts.size();
            }
            --fast_bak;
        }

        return count;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=captureForts
// paramTypes= ["number[]"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// [1,0,0,-1,0,0,0,0,1]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,1,-1]\n
// @lcpr case=end

 */
