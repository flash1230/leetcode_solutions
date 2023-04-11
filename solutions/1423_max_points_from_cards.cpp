/* https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
1423. Maximum Points You Can Obtain from Cards
Medium
*/
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size() - k;
        int total = 0;
        int subsum = 0;
        int minsum = 0;
        for(int i =0;i<cardPoints.size();i++) {
            total+=cardPoints[i];
            if(i<n) {
                minsum = total;
                subsum = total;
            }
            else {
                subsum = subsum + cardPoints[i] - cardPoints[i - n];
                minsum = min(minsum, subsum);
            }
        }
        return total - minsum;
    }
};