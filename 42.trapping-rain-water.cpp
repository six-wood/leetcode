/*
 * @lc app=leetcode.cn id=42 lang=cpp
 * @lcpr version=21913
 *
 * [42] 接雨水
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
    int trap(vector<int> &height)
    {
        /*原理
        从右向左看，当前位置的雨水高度取决于左边最高的柱子高度、当前柱子高度
        从左向右看，当前位置的雨水高度取决于右边最高的柱子高度、当前柱子高度
        因此，当前位置的雨水 = min(左边最高的柱子高度, 右边最高的柱子高度) - 当前柱子高度
        */
        // 双指针
        int pm = 0, sm = 0;
        // 前缀最大值
        vector<int> preMax(height.size(), 0);
        // 后缀最大值
        vector<int> sufMax(height.size(), 0);
        // 计算前缀最大值
        for (int i = 0; i < height.size(); i++)
        {
            preMax[i] = max(height[i], pm);
            pm = preMax[i];
        }
        // 计算后缀最大值
        for (int i = height.size() - 1; i >= 0; i--)
        {
            sufMax[i] = max(height[i], sm);
            sm = sufMax[i];
        }
        // 计算雨水
        int ans = 0;
        for (int i = 0; i < height.size(); i++)
        {
            ans += min(preMax[i], sufMax[i]) - height[i];
        }

        /*优化空间复杂度
        min(左边最高的柱子高度, 右边最高的柱子高度)可以用提前比较，因为最大值不会降低
        */
        // 双指针
        int l = 0, r = height.size() - 1;
        // 左边最大值
        int lm = 0;
        // 右边最大值
        int rm = 0;
        // 计算雨水
        ans = 0;
        while (l < r)
        {
            // 左边最大值小于右边最大值，左边最大值决定当前位置的雨水
            if (height[l] < height[r])
            {
                // 左边最大值大于当前柱子高度，当前位置无雨水
                if (height[l] > lm)
                {
                    lm = height[l];
                }
                // 左边最大值小于当前柱子高度，当前位置有雨水
                else
                {
                    ans += lm - height[l];
                }
                l++;
            }
            // 左边最大值大于右边最大值，右边最大值决定当前位置的雨水
            else
            {
                // 右边最大值大于当前柱子高度，当前位置无雨水
                if (height[r] > rm)
                {
                    rm = height[r];
                }
                // 右边最大值小于当前柱子高度，当前位置有雨水
                else
                {
                    ans += rm - height[r];
                }
                r--;
            }
        }

        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [0,1,0,2,1,0,1,3,2,1,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [4,2,0,3,2,5]\n
// @lcpr case=end

 */
