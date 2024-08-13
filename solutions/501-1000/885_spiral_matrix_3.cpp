/* https://leetcode.com/problems/spiral-matrix-iii/
885. Spiral Matrix III
Medium
*/
class Solution {
public:
    int maxc = 0, maxr = 0, minc = 101, minl = 101;
    vector<int> outOfBound(vector<vector<bool>> &visited, int x, int y, int direction)
    {
        vector<int> res(3);
        if(direction == 0)
        {
            if(maxr<visited.size()-1)
            {
                res[0]=maxr+1;
                res[1]=y;
                res[2]=2;
            }
            if(minc>0)
            {
                res[0]=visited[0].size()-1;
                res[1]=minc-1;
                res[2]=3;
            }
            if(minr>0)
            {
                res[0]=minr-1;
                res[1]=0;
                res[2]=0;
            }
        }
        else if(direction == 1)
        {
            if(minc>0)
            {
                res[0]=visited[0].size()-1;
                res[1]=minc-1;
                res[2]=3;
            }
            if(minr>0)
            {
                res[0]=minr-1;
                res[1]=0;
                res[2]=0;
            }
            if(maxc<visited[0].size()-1)
            {
                res[0]=0;
                res[1]=maxc+1;
                res[2]=1;
            }
        }
        else if(direction == 2)
        {
            if(minr>0)
            {
                res[0]=minr-1;
                res[1]=0;
                res[2]=0;
            }
            if(maxc<visited[0].size()-1)
            {
                res[0]=0;
                res[1]=maxc+1;
                res[2]=1;
            }
            if(maxr<visited.size()-1)
            {
                res[0]=maxr+1;
                res[1]=y;
                res[2]=2;
            }
        }
        else
        {
            if(maxc<visited[0].size()-1)
            {
                res[0]=0;
                res[1]=maxc+1;
                res[2]=1;
            }
            if(maxr<visited.size()-1)
            {
                res[0]=maxr+1;
                res[1]=y;
                res[2]=2;
            }
            if(minc>0)
            {
                res[0]=visited[0].size()-1;
                res[1]=minc-1;
                res[2]=3;
            }
        }
        return res;
    }
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int direction = 0;
        /*
        0 right
        1 down
        2 left
        3 up
        */
        int size = 2; //size of spiral to increase
        int counter = 0; //visited in current direction
        int cur = 0; //
        int total = 0; //total number of nodes marked
        while(total!=(rows*cols))
        {
            visited[cStart][rStart] = true;
            total++;
            counter++;
            if(counter == size)
            {
                cur++;
                counter = 1;
            }
            if(cur == 2)
            {
                direction=(direction+1)%4;
                size++;
                cur = 0;
            }
            switch(direction)
            {
                case 1:
                    rStart++;
                    if(rStart == rows)
                    {
                        vector<int> temp = outOfBound(visited, rStart-1, cStart, direction);
                        rStart = temp[0];
                        cStart = temp[1];
                        if(temp[2] == (direction+3)%4 )
                            cur = cur == 0 ? 1 : 0;
                        if(temp[1] == (direction+2)%4 )
                            n++;
                        else
                            n+=2;
                        counter = n-counter; // tbc
                    }
                case 2:
                    cStart--;
                    if(cStart == -1)
                    {
                        vector<int> temp = outOfBound(visited, rStart, cStart+1, direction);
                        rStart = temp[0];
                        cStart = temp[1];
                        if(temp[2] == (direction+3)%4 )
                            cur = cur == 0 ? 1 : 0;
                        if(temp[1] == (direction+2)%4 )
                            n++;
                        else
                            n+=2;
                    }
                case 3:
                    rStart--;
                    if(rStart == -1)
                    {
                        vector<int> temp = outOfBound(visited, rStart+1, cStart, direction);
                        rStart = temp[0];
                        cStart = temp[1];
                        if(temp[2] == (direction+3)%4 )
                            cur = cur == 0 ? 1 : 0;
                        if(temp[1] == (direction+2)%4 )
                            n++;
                        else
                            n+=2;
                    }
                default:
                    cStart++
                    if(cStart == cols)
                    {
                        vector<int> temp = outOfBound(visited, rStart, cStart-1, direction);
                        rStart = temp[0];
                        cStart = temp[1];
                        if(temp[2] == (direction+3)%4 )
                            cur = cur == 0 ? 1 : 0;
                        if(temp[1] == (direction+2)%4 )
                            n++;
                        else
                            n+=2;
                    }
            }
        }
    }
};