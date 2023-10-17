/*
 * @lc app=leetcode.cn id=797 lang=cpp
 * @lcpr version=21917
 *
 * [797] 所有可能的路径
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
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        dfs(graph, 0);
        return paths;
    }
    void dfs(vector<vector<int>> &graph, int i)
    {
        for (int j : graph[i])
        {
            path.push_back(j);
            if (j == graph.size() - 1)
                paths.emplace_back(path);
            dfs(graph, j);
            path.pop_back();
        }

        return;
    }

private:
    vector<vector<int>> paths;
    vector<int> path = {0};
};
// @lc code=end

/*
// @lcpr case=start
// [[1,2],[3],[3],[]]\n
// @lcpr case=end

// @lcpr case=start
// [[4,3,1],[3,2,4],[3],[4],[]]\n
// @lcpr case=end

 */
