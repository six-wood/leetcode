/*
 * @lc app=leetcode.cn id=128 lang=cpp
 * @lcpr version=21917
 *
 * [128] 最长连续序列
 */
using namespace std;
#include <algorithm>
// #include <array>
// #include <bitset>
// #include <climits>
// #include <deque>
// #include <functional>
// #include <iostream>
// #include <list>
// #include <queue>
// #include <stack>
// #include <tuple>
// #include <unordered_map>
#include <unordered_set>
// #include <utility>
#include <vector>
// @lc code=start
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> set;
        for (int num : nums)
        {
            set.insert(num);
        }
        int longestStreak = 0;
        for (int num : set)
        {
            if (!set.count(num - 1))
            {
                int currentStreak = 1;
                int currentNum = num;
                while (set.count(currentNum + 1))
                {
                    ++currentNum;
                    ++currentStreak;
                }
                longestStreak = max(currentStreak, longestStreak);
            }
        }
        return longestStreak;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [100,4,200,1,3,2]\n
// @lcpr case=end

// @lcpr case=start
// [0,3,7,2,5,8,4,6,0,1]\n
// @lcpr case=end

 */
