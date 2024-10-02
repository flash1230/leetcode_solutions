/* https://leetcode.com/problems/rank-transform-of-an-array
1331. Rank Transform of an Array
Easy
Sorting
*/
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int, int>> temp;
        for(int i = 0; i<n; i++)
            temp.push_back({arr[i], i});
        sort(temp.begin(), temp.end());
        vector<int> ans(n);
        if(n==0)
            return ans;
        int printer = 1;
        ans[temp[0].second] = 1;
        for(int i = 1; i<n; i++)
        {
            if(temp[i].first == temp[i-1].first)
                ans[temp[i].second] = printer;
            else
                ans[temp[i].second] = ++printer;
        }
        return ans;
    }
};