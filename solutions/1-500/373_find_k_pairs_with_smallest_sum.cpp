/* https://leetcode.com/problems/find-k-pairs-with-smallest-sums
373. Find K Pairs with Smallest Sums
Medium
Priority Queue
*/
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums0, vector<int>& nums1, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int, vector<int>>> pq;
        for(int i = 0;i<nums0.size();i++){
            for(int j = 0;j<nums1.size();j++){
                if(pq.size()<k){
                    vector<int> t{nums0[i], nums1[j]};
                    pq.push(make_pair(nums0[i]+nums1[j], t));
                }
                else{
                    if(pq.top().first> nums0[i]+nums1[j]){
                        pq.pop();
                        vector<int> t{nums0[i], nums1[j]};
                        pq.push(make_pair(nums0[i]+nums1[j], t));
                    }
                    else{
                        break;
                    }
                }
            }
        }
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};