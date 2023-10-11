/*
 * @lc app=leetcode.cn id=57 lang=cpp
 * @lcpr version=21913
 *
 * [57] 插入区间
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        int left = newInterval[0];
        int right = newInterval[1];
        bool placed = false;
        vector<vector<int>> ans;
        for (const auto &interval : intervals)
        {
            if (interval[0] > right)
            {
                // 在插入区间的右侧且无交集
                if (!placed)
                {
                    ans.push_back({left, right});
                    placed = true;
                }
                ans.push_back(interval);
            }
            else if (interval[1] < left)
            {
                // 在插入区间的左侧且无交集
                ans.push_back(interval);
            }
            else
            {
                // 与插入区间有交集，计算它们的并集
                left = min(left, interval[0]);
                right = max(right, interval[1]);
            }
        }
        if (!placed)
        {
            ans.push_back({left, right});
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[1,3],[6,9]]\n[2,5]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2],[3,5],[6,7],[8,10],[12,16]]\n[4,8]\n
// @lcpr case=end

// @lcpr case=start
// []\n[5,7]\n
// @lcpr case=end

// @lcpr case=start
// [[1,5]]\n[2,3]\n
// @lcpr case=end

// @lcpr case=start
// [[1,5]]\n[2,7]\n
// @lcpr case=end

 */
