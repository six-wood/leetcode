// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1020 lang=cpp
 * @lcpr version=
 *
 * [1020] 飞地的数量
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
    int numEnclaves(vector<vector<int>> &grid)
    {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int count = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1 && !visited[i][j])
                {
                    count += dfs(grid, visited, {i, j});
                }
            }
        }
        return count;
    }
    int bfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, pair<int, int> pos)
    {
        int m = grid.size();
        int n = grid[0].size();
        int flag = 0, count = 0;
        queue<pair<int, int>> q;
        q.push(pos);
        visited[pos.first][pos.second] = true;
        ++count;

        while (!q.empty())
        {
            auto cur = q.front();
            q.pop();
            for (auto &dir : dirs)
            {
                int x = cur.first + dir[0];
                int y = cur.second + dir[1];
                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1 && !visited[x][y])
                {
                    q.push({x, y});
                    visited[x][y] = true;
                    ++count;
                }

                if (x < 0 || x >= m || y < 0 || y >= n)
                {
                    flag = -1;
                }
            }
        }
        if (flag == -1)
            return 0;
        else
            return count;
    }
    int dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, pair<int, int> pos)
    {
        int m = grid.size();
        int n = grid[0].size();
        int flag = 0, count = 0;
        stack<pair<int, int>> s;
        s.push(pos);
        ++count;
        visited[pos.first][pos.second] = true;

        while (!s.empty())
        {
            auto cur = s.top();
            s.pop();
            for (auto &dir : dirs)
            {
                int x = cur.first + dir[0];
                int y = cur.second + dir[1];
                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1 && !visited[x][y])
                {
                    s.push({x, y});
                    ++count;
                    visited[x][y] = true;
                }

                if (x < 0 || x >= m || y < 0 || y >= n)
                {
                    flag = -1;
                }
            }
        }
        if (flag == -1)
            return 0;
        else
            return count;
    }

private:
    int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
};
// @lc code=end

/*
// @lcpr case=start
// [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]\n
// @lcpr case=end

 */
