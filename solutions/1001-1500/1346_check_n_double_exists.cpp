/* https://leetcode.com/problems/check-if-n-and-its-double-exist/
1346. Check If N and Its Double Exist
Easy
Map
*/
class Solution
{
public:
    bool checkIfExist(vector<int> &arr)
    {
        unordered_set<int> nums;
        nums.insert(arr[0]);
        for (int i = 1; i < arr.size(); i++)
        {
            if (nums.contains(2 * arr[i]))
                return true;
            if (arr[i] % 2 == 0 && nums.contains(arr[i] / 2))
                return true;
            nums.insert(arr[i]);
        }
        return false;
    }
};