/* https://leetcode.com/problems/maximum-swap/
670. Maximum Swap
Medium
Greedy
*/
class Solution
{
public:
    int maximumSwap(int num)
    {
        if (num < 10)
            return num;
        string numStr = to_string(num);
        int maxDigitIndex = -1, swapIdx1 = -1, swapIdx2 = -1;
        for (int i = numStr.size() - 1; i >= 0; --i)
        {
            if (maxDigitIndex == -1 || numStr[i] > numStr[maxDigitIndex])
                maxDigitIndex = i;
            else if (numStr[i] < numStr[maxDigitIndex])
            {
                swapIdx1 = i;
                swapIdx2 = maxDigitIndex;
            }
        }
        if (swapIdx1 != -1 && swapIdx2 != -1)
            swap(numStr[swapIdx1], numStr[swapIdx2]);

        return stoi(numStr);
    }
};