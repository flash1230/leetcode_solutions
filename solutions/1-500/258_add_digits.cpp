/* https://leetcode.com/problems/add-digits/
258. Add Digits
Easy
*/
class Solution {
public:
    int addDigits(int num) {
        return (num-1)%9 + 1;
    }
};