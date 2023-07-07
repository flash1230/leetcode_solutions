/* https://leetcode.com/problems/shortest-path-to-get-all-keys
864. Shortest Path to Get All Keys
Hard
Graph
BFS
*/
class Solution
{
public:
    int rows, cols;
    struct es
    {
        pair<int, int> position;
        string keys;
        int steps;
        int collected;
    };

    bool in_range(int i, int j)
    {
        if (i > rows - 1 || i < 0)
        {
            return false;
        }
        if (j > cols - 1 || j < 0)
        {
            return false;
        }
        return true;
    }

    int shortestPathAllKeys(vector<string> &grid)
    {
        int required = 0;
        rows = grid.size();
        cols = grid[0].size();
        queue<es> q;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (islower(grid[i][j]))
                {
                    required++;
                }
                if (grid[i][j] == '@')
                {
                    q.push(es{{i, j}, "", 0, 0});
                    visited[i][j] = true;
                }
            }
        }
        vector<vector<bool>> prevVisited;
        while (!q.empty())
        {
            es t = q.front();
            q.pop();
            int i = t.position.first;
            int j = t.position.second;
            for (int a = 0; a < 4; a++)
            {
                int ii, jj;
                if (a == 0)
                {
                    ii = i + 1;
                    jj = j;
                }
                else if (a == 1)
                {
                    ii = i - 1;
                    jj = j;
                }
                else if (a == 2)
                {
                    ii = i;
                    jj = j + 1;
                }
                else
                {
                    ii = i;
                    jj = j - 1;
                }
                if (in_range(ii, jj) && !visited[ii][jj])
                {
                    if (islower(grid[ii][jj]))
                    {
                        if (t.collected + 1 == required)
                        {
                            return t.steps + 1;
                        }
                        prevVisited = visited;
                        for(int k=0;k<rows;k++){
                            for(int g=0;g<cols;g++){
                                visited[i][j] = false;
                            }
                        }
                        visited[ii][jj] = true;
                        q.push(es{{ii, jj}, t.keys + grid[ii][jj], t.steps + 1, t.collected + 1});
                    }
                    else if (grid[ii][jj] == '.')
                    {
                        q.push(es{{ii, jj}, t.keys, t.steps + 1, t.collected});
                    }
                    else if (isupper(grid[ii][jj]))
                    {
                        char c = tolower(grid[ii][jj]);
                        if (t.keys.find(c) != string::npos)
                        {
                            q.push(es{{ii, jj}, t.keys, t.steps + 1, t.collected});
                            for (int k = 0; k < rows; k++)
                            {
                                for (int g = 0; g < cols; g++)
                                {
                                    if(prevVisited[i][j]){
                                        visited[i][j] = true;
                                    }
                                }
                            }
                        }
                    }
                    else
                    {
                    }
                    visited[ii][jj] = true;
                }
            }
        }
        return -1;
    }
};