/* https://leetcode.com/problems/number-of-atoms
726. Number of Atoms
Hard
Hash Map
*/
class Solution
{
public:
    map<string, int> help(string s, long long n)
    {
        map<string, int> final;
        string stree = "";
        string nom = "";
        int brack = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                if (stree.size())
                {

                    if (nom.size())
                        final[stree] += (n * stoi(nom));
                    else
                        final[stree] += n;
                }
                stree = "";
                nom = "";
                string mini = "";
                brack++;
                i++;
                while (brack > 0)
                {
                    if (s[i] == ')')
                    {
                        brack--;
                        if (brack == 0)
                            break;
                    }
                    if (s[i] == '(')
                        brack++;
                    mini += s[i++];
                }
                i++;
                string number = "";
                while (i < s.length() && isdigit(s[i]))
                {
                    number += s[i];
                    i++;
                }
                i--;
                map<string, int> temp;
                if (number.length())
                    temp = help(mini, stoi(number));
                else
                    temp = help(mini, 1);
                for (auto i : temp)
                    final[i.first] += (n * i.second);
            }
            else if (isupper(s[i]))
            {
                if (stree.size())
                {
                    if (nom.size())
                        final[stree] += (n * stoi(nom));
                    else
                        final[stree] += n;
                    stree = "";
                    stree += s[i];
                    nom = "";
                }
                else
                    stree += s[i];
            }
            else if (islower(s[i]))
                stree += s[i];
            else
                nom += s[i];
        }
        if (stree.size())
        {
            if (nom.size())
                final[stree] += (n * stoi(nom));
            else
                final[stree] += n;
        }
        return final;
    }

    string countOfAtoms(string formula)
    {
        map<string, int> final;
        final = help(formula, 1);
        string ans = "";
        for (auto i : final)
        {
            ans += i.first;
            if (i.second > 1)
                ans += to_string(i.second);
        }
        return ans;
    }
};