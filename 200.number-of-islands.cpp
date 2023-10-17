// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=200 lang=cpp
 * @lcpr version=30102
 *
 * [200] 岛屿数量
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
class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int ans = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == '1' && !visited[i][j])
                {
                    // bfs(grid, visited, {i, j});
                    dfs(grid, visited, {i, j});
                    ++ans;
                }
            }
        }
        return ans;
    }
    void bfs(vector<vector<char>> &grid, vector<vector<bool>> &visited, pair<int, int> pos)
    {
        queue<pair<int, int>> q;
        q.push(pos);
        visited[pos.first][pos.second] = true;
        while (!q.empty())
        {
            auto p = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i)
            {
                int x = p.first + this->dir[i][0];
                int y = p.second + this->dir[i][1];
                if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == '1' && !visited[x][y])
                {
                    q.push({x, y});
                    visited[x][y] = true;
                }
            }
        }
    }
    void dfs(vector<vector<char>> &grid, vector<vector<bool>> &visited, pair<int, int> pos)
    {
        visited[pos.first][pos.second] = true;
        for (int i = 0; i < 4; ++i)
        {
            int x = pos.first + this->dir[i][0];
            int y = pos.second + this->dir[i][1];
            if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == '1' && !visited[x][y])
            {
                visited[x][y] = true;
                dfs(grid, visited, {x, y});
            }
        }
    }

private:
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
};
// @lc code=end

/*
// @lcpr case=start
// [["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]\n
// @lcpr case=end

// @lcpr case=start
// [["1","1","0","0","0"],["1","1","0","0","0"],["0","0","1","0","0"],["0","0","0","1","1"]]\n
// @lcpr case=end

 */
