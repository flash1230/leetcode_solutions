/* https://leetcode.com/problems/maximum-score-from-removing-substrings
1717. Maximum Score From Removing Substrings
Medium
Stack
*/
class Solution
{
public:
    stack<char> st;
    int last(bool isA, int add)
    {
        if (st.empty())
            return 0;
        int res = 0;
        char prev;
        int extra = 0;
        char x = 'b', y = 'a';
        if (isA)
        {
            x = 'a';
            y = 'b';
        }
        while (1)
        {
            if (st.top() != x)
            {
                st.pop();
                if (st.empty())
                    return res;
            }
            else
            {
                prev = x;
                st.pop();
                break;
            }
        }
        while (!st.empty())
        {
            if (st.top() == y)
            {
                if (prev == x)
                {
                    res += add;
                    st.pop();
                    if (extra > 0)
                        extra--;
                    else
                    {
                        if (st.empty())
                            break;
                        prev = st.top();
                        st.pop();
                    }
                }
                else
                    st.pop();
            }
            else
            {
                prev = st.top();
                if (prev = x)
                    extra++;
                st.pop();
            }
        }
        return res;
    }
    int maximumGain(string s, int x, int y)
    {
        int ans = 0;
        char c1 = 'a', c2 = 'b';
        if (x < y)
        {
            c1 = 'b';
            c2 = 'a';
        }
        for (char c : s)
        {
            if (c != 'a' && c != 'b')
            {
                if (!st.empty())
                    ans += last(c1 == 'a', min(x, y));
                continue;
            }
            if (st.empty())
            {
                st.push(c);
                continue;
            }
            if (c == c2 && st.top() == c1)
            {
                ans += max(x, y);
                st.pop();
            }
            else
                st.push(c);
        }
        if (!st.empty())
            ans += last(c1 == 'a', min(x, y));
        return ans;
    }
};