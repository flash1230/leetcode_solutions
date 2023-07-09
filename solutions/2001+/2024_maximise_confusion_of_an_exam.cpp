/* https://leetcode.com/problems/maximize-the-confusion-of-an-exam/
2024. Maximize the Confusion of an Exam
Medium
Sliding Window
*/
class Solution1
{
public:
    int solve(string &answerKey, int k, char c)
    {
        int start = 0;
        int end = 0;
        queue<int> q;
        int ans = 0;
        while (end < answerKey.length())
        {
            if (answerKey[end] == c)
                ans = max(ans, end - start + 1);
            else
            {
                q.push(end);
                if (q.size() > k)
                {
                    start = q.front() + 1;
                    q.pop();
                }
                else
                    ans = max(ans, end - start + 1);
            }
            end++;
        }
        return ans;
    }

    int maxConsecutiveAnswers(string answerKey, int k)
    {
        return max(solve(answerKey, k, 'T'), solve(answerKey, k, 'F'));
    }
};

class Solution2
{
public:
    int maxConsecutiveAnswers(string s, int k)
    {
        int l = s.length();
        if (l < 2)
            return 1;
        int i = 0, j = 0;
        int cur = 0, ans = 0;
        unordered_map<char, int> hash;
        while (j < l)
        {
            hash[s[j]]++;
            cur = max(cur, hash[s[j]]);
            if ((j - i + 1) - cur > k)
            {
                hash[s[i]]--;
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};

class Solution3
{
public:
    int maxConsecutiveAnswers(string s, int k)
    {
        int start = 0;
        int end = 0;
        int t = 0;
        int f = 0;
        int ans = 0;
        while (end < s.length())
        {
            if (s[end] == 'T')
            {
                t++;
                if (t <= k || f <= k)
                    ans = max(ans, end - start + 1);
            }
            else
            {
                f++;
                if (f <= k || t <= k)
                    ans = max(ans, end - start + 1);
            }
            while (t > k && f > k)
            {
                if (s[start] == 'T')
                    t--;
                else
                    f--;
                start++;
            }
            end++;
        }
        return ans;
    }
};