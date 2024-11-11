/* https://leetcode.com/problems/prime-subtraction-operation/description/
2601. Prime Subtraction Operation
Medium
Greedy
*/
class Solution
{
public:
    unordered_set<int> primes;
    bool isPrime(int n)
    {
        if (n % 2 == 0 || n % 3 == 0)
            return false;
        for (int i = 5; i * i <= n; i += 6)
        {
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        }
        primes.insert(n);
        return true;
    }
    bool primeSubOperation(vector<int> &nums)
    {
        primes.insert(2);
        primes.insert(3);
        int maxn = -1;
        for (int i : nums)
            maxn = max(i, maxn);
        for (int i = 5; i < maxn; i++)
            isPrime(i);
        for (int j = nums[0] - 1; j > 1; j--)
        {
            if (primes.contains(j))
            {
                nums[0] -= j;
                break;
            }
        }
        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = nums[i] - nums[i - 1] + 1; j > 1; j--)
            {
                if (primes.contains(j))
                {
                    if (nums[i] - j > nums[i - 1])
                    {
                        nums[i] -= j;
                        break;
                    }
                }
            }
            if (i != 0 && nums[i] <= nums[i - 1])
                return false;
        }
        return true;
    }
};