/* https://leetcode.com/problems/asteroid-collision/
735. Asteroid Collision
Medium
Stack
*/
class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        stack<int> st;
        int n = asteroids.size();
        int i = 0;
        while (i < n)
        {
            if (st.empty() || asteroids[i] > 0)
                st.push(asteroids[i]);
            else
            {
                while (!st.empty())
                {
                    if (st.top() < 0)
                    {
                        st.push(asteroids[i]);
                        break;
                    }
                    if (asteroids[i] < -st.top())
                    {
                        st.pop();
                        if (st.empty())
                        {
                            st.push(asteroids[i]);
                            break;
                        }
                    }
                    else if (st.top() == -asteroids[i])
                    {
                        st.pop();
                        break;
                    }
                    else
                        break;
                }
            }
            i++;
        }
        n = st.size();
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--)
        {
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};