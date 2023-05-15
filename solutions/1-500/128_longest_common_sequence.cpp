/* https://leetcode.com/problems/longest-consecutive-sequence/
128. Longest Consecutive Sequence
Medium
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n<2) {
            return n;
        }
        map<int, bool> isP;
        for(int i = 0;i<n;i++) {
            isP[nums[i]] = true;
        }
        int cur_len =1, maxx = 1, cur = isP.begin()->first;
        auto x = isP.begin();
        x++;
        for(; x!=isP.end(); x++) {
            if(x->first - cur == 1){
                cur_len++;
            }else {
                maxx = max(maxx, cur_len);
                cur_len = 1;
            }
            cur = x->first;
        }
        return max(maxx, cur_len);
    }
};