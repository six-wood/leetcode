/*
 * @lc app=leetcode.cn id=49 lang=cpp
 * @lcpr version=21917
 *
 * [49] 字母异位词分组
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
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<int>> map;
        string str;
        for (int i = 0; i < strs.size(); ++i)
        {
            str = strs[i];
            sort(str.begin(), str.end());
            map[str].push_back(i);
        }
        vector<vector<string>> out;
        vector<string> s;
        for (auto &m : map)
        {
            for (int i : m.second)
            {
                s.push_back(strs[i]);
            }
            out.push_back(s);
            s.resize(0);
        }
        return out;
    }
};
// @lc code=end

/*
// @lcpr case=start
// ["eat", "tea", "tan", "ate", "nat", "bat"]\n
// @lcpr case=end

// @lcpr case=start
// [""]\n
// @lcpr case=end

// @lcpr case=start
// ["a"]\n
// @lcpr case=end

 */
