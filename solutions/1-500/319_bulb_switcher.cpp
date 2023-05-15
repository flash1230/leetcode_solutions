/* https://leetcode.com/problems/bulb-switcher
319. Bulb Switcher
Medium
Maths
*/
class Solution {
public:
    int bulbSwitch(int n) {
        if(n<2) {
            return n;
        }
        else {
            return sqrt(n);
        }
    }
};