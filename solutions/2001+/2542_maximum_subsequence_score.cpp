/* https://leetcode.com/problems/maximum-subsequence-score/
2542. Maximum Subsequence Score
Medium
Sorting Heap
*/
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector <pair <int, int>> v;
        for(int i = 0;i<n;i++){
            v.push_back(make_pair(nums1[i], nums2[i]));
        }
        sort(v.begin(), v.end(), [](const auto& x, const auto& y)
                {
                    return x.second > y.second;
                }
            );
        priority_queue<int, vector<int>, greater<int>> gq;
        long long sum =0;
        for(int i = 0; i<k;i++){
            gq.push(v[i].first);
            sum+=v[i].first;
        }
        long long res = sum * v[k-1].second;
        for(int i =k;i<n;i++) {
            sum += v[i].first - gq.top();
            gq.pop();
            gq.push(v[i].first);
            res = max(res,sum * v[i].second);
        }
        return res;
    }
};