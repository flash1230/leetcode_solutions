/* https://leetcode.com/problems/maximize-score-after-n-operations
1799. Maximize Score After N Operations
Hard
DP Bit Manipulation
*/
class Solution {
public:
    bool isBitSet(int& num, int bitIdx)
    {
        if ((num & (1 << bitIdx)) != 0) 
            return true;
        return false;
    }
    void setBit(int& num, int bitIdx)
    {
        num = num | (1 << bitIdx);
    }
    int solve(  vector<vector<int>> &gcd,
                unordered_map<int, int> &map,
                int &visited,
                int operation
        )
        {
            int n = gcd.size();
            if(map.count(visited)) {
                return map[visited];
            }
            int res = 0;
            for(int i = 0; i<n-1; i++) {
                if(isBitSet(visited, i)) 
                    continue;
                for(int j = i+1; j<n;j++) {
                    if(isBitSet(visited, j))
                        continue;
                    int newVisited = visited;
                    setBit(newVisited, i);
                    setBit(newVisited, j);
                    int current = operation * gcd[i][j];
                    int next = solve(gcd, map, newVisited,operation + 1);
                    res = max(res, current + next);
                }
            }
            return map[visited] = res;
        }

    int maxScore(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> gcd(n, vector<int>(n));
        for(int i =0;i<n;i++) {
            for(int j = 0;j<n;j++) {
                gcd[i][j] = __gcd(nums[i], nums[j]);
            }
        }
        int visited = 0;
        unordered_map<int, int> map;
        return solve(gcd, map, visited, 1);
    }
};