// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=56 lang=cpp
 * @lcpr version=21913
 *
 * [56] 合并区间
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {

        auto less = [&](vector<int> &v1, vector<int> &v2)
        {
            return v1[0] < v2[0];
        };

        sort(intervals.begin(), intervals.end(), less);

        int fast_ptr = 0;
        vector<vector<int>> merged(0);
        vector<int> result(intervals[0]);
        for (; fast_ptr < intervals.size(); ++fast_ptr)
        {

            if (fast_ptr + 1 < intervals.size() &&
                result[1] >= intervals[fast_ptr + 1][0])
            {
                result[1] = max(intervals[fast_ptr + 1][1], result[1]);
            }
            else
            {
                merged.emplace_back(result);
                if (fast_ptr + 1 < intervals.size())
                    result = intervals[fast_ptr + 1];
            }
        }
        return merged;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[1,3],[2,6],[8,10],[15,18]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,4],[4,5]]\n
// @lcpr case=end

 */
