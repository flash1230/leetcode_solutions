/* https://leetcode.com/problems/sort-array-by-increasing-frequency
1636. Sort Array by Increasing Frequency
Easy
Sorting Map
*/
class Solution
{
public:
    vector<int> frequencySort(vector<int> &nums)
    {
        unordered_map<int, int> freq;
        for (auto i : nums)
            freq[i]++;
        sort(nums.begin(), nums.end(), [&freq](int a, int b)
             {
            if(freq[a]!=freq[b])
                return freq[a]<freq[b];
            return a>b; });
        return nums;
    }
};