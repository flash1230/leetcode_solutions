/* https://leetcode.com/problems/number-of-rectangles-that-can-form-the-largest-square/
1725. Number Of Rectangles That Can Form The Largest Square
Easy
Array
*/
class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        map<int,int> min_lengths;
        for(int i =0; i<rectangles.size();i++) {
            int temp = min(rectangles[i][0], rectangles[i][1]);
            if(min_lengths.find(temp) == min_lengths.end())
                min_lengths[temp] = 1;
            else
                min_lengths[temp] += 1;
        }
        return min_lengths.rbegin()->second;
    }
};