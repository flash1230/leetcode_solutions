/* https://leetcode.com/problems/sort-the-jumbled-numbers
2191. Sort the Jumbled Numbers
Medium
Sorting
*/
class Solution
{
public:
    vector<int> sortJumbled(vector<int> &mapping, vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), [&mapping](int a, int b)
             {
            int a1=0, b1 = 0;
            int multi=1;
            if(a<10)
                a1 = mapping[a];
            else
            {
                while(a>0)
                {
                    a1+=multi*mapping[a%10];
                    multi*=10;
                    a/=10;
                }
            }
            multi = 1;
            if(b<10)
                b1 = mapping[b];
            else
            {
                while(b>0)
                {
                    b1+=multi*mapping[b%10];
                    multi*=10;
                    b/=10;
                }
            }
            return a1<b1; });
        return nums;
    }
};