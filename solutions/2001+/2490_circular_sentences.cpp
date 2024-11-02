/*https://leetcode.com/problems/circular-sentence/
2490. Circular Sentence
Easy
*/
class Solution
{
public:
    bool isCircularSentence(string sentence)
    {
        int l = sentence.size();
        if (sentence[0] != sentence[l - 1])
            return false;
        for (int i = 1; i < l - 1; i++)
        {
            if (sentence[i] == ' ')
            {
                if (sentence[i - 1] != sentence[i + 1])
                    return false;
            }
        }
        return true;
    }
};