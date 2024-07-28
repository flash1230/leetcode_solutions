/* https://leetcode.com/problems/second-minimum-time-to-reach-destination
2045. Second Minimum Time to Reach Destination
Hard
BFS
*/
class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        //find least number of edges between 1 and n
        //find second least with max one more turn
        //if found return second one, else add two turns to first, ez
        vector<int> visited(n);
        vector<vector<int>> graph(n);
        for(auto i: edges)
        {
            graph[i[0]-1].push_back(i[1]-1);
            graph[i[1]-1].push_back(i[0]-1);
        }
        queue<int> bfs;
        bfs.push(0);
        int curr = 1;
        // visited[0]=true;
        int next=0;
        int level = 0;
        int k=1;
        bool found1 = false, found2 = false;
        while(k>0 &&!bfs.empty())
        {
            int a = bfs.front();
            bfs.pop();
            visited[a] = true;
            for(int i: graph[a])
            {
                if(i == n-1)
                {
                    if(found1)
                    {
                        found2 = true;
                        level++;
                        break;
                    }
                    else
                    {
                        found1 = true;
                        k=2;
                    }
                }
                if(!visited[i])
                {
                    bfs.push(i);
                    visited[i]=true;
                    next++;
                }
            }
            curr--;
            if(curr == 0)
            {
                if(found1)
                    k--;
                    if(k==0)
                    {
                        break;
                    }
                curr = next;
                next = 0;
                level++;
            }
            if(found2)
                break;
        }
        if(!found2)
            level+=2;
        cout<<level;
        cout<<found2;
            int ans = time;
            for(int i =1; i<level;i++)
            {
                int a = ans/change;
                int b = ans%change;
                if(a%2)
                {
                    // ans+=time;
                    ans+=(change-b);

                }
                ans+=time;
                // else
                    // ans+=time;
            }
        return ans;
    }
};