/*
 * @lc app=leetcode.cn id=695 lang=cpp
 * @lcpr version=30102
 *
 * [695] 岛屿的最大面积
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
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int maxArea = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1 && visited[i][j] == false)
                    // maxArea = max(maxArea, dfs(grid, visited, {i, j}, 0));
                    maxArea = max(maxArea, bfs(grid, visited, {i, j}, 0));
            }
        }
        return maxArea;
    }
    int dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, pair<int, int> pos, int count)
    {
        visited[pos.first][pos.second] = true;
        count++;
        for (int i = 0; i < 4; i++)
        {
            int x = pos.first + dir[i][0], y = pos.second + dir[i][1];
            if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && !visited[x][y] && grid[x][y] == 1)
            {
                visited[x][y] = true;
                count = dfs(grid, visited, {x, y}, count);
            }
        }
        return count;
    }
    int bfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, pair<int, int> pos, int count)
    {
        queue<pair<int, int>> q;
        q.push(pos);
        visited[pos.first][pos.second] = true;
        while (!q.empty())
        {
            auto cur = q.front();
            q.pop();
            count++;
            for (int i = 0; i < 4; i++)
            {
                int x = cur.first + dir[i][0], y = cur.second + dir[i][1];
                if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && !visited[x][y] && grid[x][y] == 1)
                {
                    visited[x][y] = true;
                    q.push({x, y});
                }
            }
        }
        return count;
    }

private:
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
};
// @lc code=end

/*
// @lcpr case=start
// [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,0,0,0,0,0,0,0]]\n
// @lcpr case=end

 */
