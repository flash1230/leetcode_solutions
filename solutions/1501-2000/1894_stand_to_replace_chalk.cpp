/* https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/
1894. Find the Student that Will Replace the Chalk
Medium
Binary Search Prefix Sum
*/
class Solution
{
public:
    int chalkReplacer(vector<int> &chalk, int k)
    {
        if (k < chalk[0])
            return 0;
        vector<long> pref(chalk.size());
        pref[0] = chalk[0];
        for (int i = 1; i < chalk.size(); i++)
        {
            pref[i] = chalk[i] + pref[i - 1];
            if (k < pref[i])
                return i;
        }
        k %= pref.back();
        return binarySearch(pref, k);
    }
    int binarySearch(vector<long> &arr, int k)
    {
        int low = 0, high = arr.size() - 1;
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] <= k)
                low = mid + 1;
            else
                high = mid;
        }
        return high;
    }
};