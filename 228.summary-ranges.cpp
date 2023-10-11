/*
 * @lc app=leetcode.cn id=228 lang=cpp
 * @lcpr version=21913
 *
 * [228] 汇总区间
 */

// @lc code=start
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        int slow_ptr = 0, fast_ptr = 0;
        vector<string> res;
        for (; fast_ptr < nums.size(); fast_ptr++)
        {
            if (fast_ptr + 1 < nums.size() && nums[fast_ptr + 1] == nums[fast_ptr] + 1)
            {
                continue;
            }
            else
            {
                if (slow_ptr == fast_ptr)
                {
                    res.push_back(to_string(nums[slow_ptr]));
                }
                else
                {
                    res.push_back(to_string(nums[slow_ptr]) + "->" + to_string(nums[fast_ptr]));
                }
                slow_ptr = fast_ptr + 1;
            }
        }
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [0,1,2,4,5,7]\n
// @lcpr case=end

// @lcpr case=start
// [0,2,3,4,6,8,9]\n
// @lcpr case=end

 */
