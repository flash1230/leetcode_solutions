/* https://leetcode.com/problems/maximum-distance-in-arrays/
624. Maximum Distance in Arrays
Medium
Greedy
*/
class Solution {
public:
    int maxDistance(vector<vector<int>>& array) {
        int small = array[0][0];
        pair<int, int> smallest, ss, biggest, bb;
        if(array[0][0]<array[1][0])
        {
            smallest = {0, array[0][0]};
            ss = {1, array[1][0]};
        }
        else
        {
            smallest = {1, array[1][0]};
            ss = {0, array[0][0]};
        }
        if(array[0][array[0].size()-1]> array[1][array[1].size()-1])
        {
            biggest = {0, array[0][array[0].size()-1]};
            bb = {1, array[1][array[1].size()-1]};
        }
        else
        {
            biggest = {1, array[1][array[1].size()-1]};
            bb = {0, array[0][array[0].size()-1]}; 
        }
        for(int i = 2; i<array.size(); i++)
        {
            if(array[i][0]<smallest.second)
            {
                ss = smallest;
                smallest = {i, array[i][0]};
            }
            else if(array[i][0]<ss.second)
                ss = {i, array[i][0]};
            if(array[i][array[i].size()-1] > biggest.second)
            {
                bb = biggest;
                biggest = {i, array[i][array[i].size()-1]};
            }
            else if(array[i][array[i].size()-1] > bb.second)
                bb = {i, array[i][array[i].size()-1]};
        }
        if(biggest.first!=smallest.first)
            return biggest.second - smallest.second;
        return max(biggest.second - ss.second, bb.second - smallest.second);
    }
};