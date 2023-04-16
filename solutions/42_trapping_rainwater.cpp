/* https://leetcode.com/problems/trapping-rain-water/
42. Trapping Rain Water
Hard
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int n =height.size();
        // vector<int> left(n);
        // vector<int> right(n);
        // int leftm = 0, rightm = 0;
        // for(int i =0;i<n;i++) {
        //     left[i] = max(leftm, height[i]);
        //     leftm = left[i];
        // }
        // int ans=0;
        // for(int i =n-1;i>-1;i--) {
        //     right[i] = max(rightm, height[i]);
        //     rightm = right[i];
        //     ans+= min(left[i], right[i]) - height[i];
        // }
        // return ans;
        // int n =height.size();
        if (n <= 2){
            return 0;
        }
        int maxLeft = height[0], maxRight = height[n-1];
        int left = 1, right = n - 2, ans = 0;
        while (left <= right) {
            if (maxLeft < maxRight) {
                if (height[left] > maxLeft)
                    maxLeft = height[left];
                else
                    ans += maxLeft - height[left];
                left ++;
            } else {
                if (height[right] > maxRight)
                    maxRight = height[right];
                else
                    ans += maxRight - height[right];
                right --;
            }
        }
        return ans;
        
    }
};