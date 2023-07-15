/* https://leetcode.com/problems/evaluate-reverse-polish-notation/
150. Evaluate Reverse Polish Notation
Medium
*/
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> s;
        for (int i = 0; i < tokens.size(); i++)
        {
            if (tokens[i] == "+" || tokens[i] == "*" || tokens[i] == "/" || tokens[i] == "-")
            {
                int r = s.top();
                s.pop();
                int l = s.top();
                s.pop();
                if (tokens[i] == "+")
                    s.push(l + r);
                else if (tokens[i] == "-")
                    s.push(l - r);
                else if (tokens[i] == "/")
                    s.push(l / r);
                else
                    s.push(l * r);
            }
            else
                s.push(stoi(tokens[i]));
        }
        return s.top();
    }
};