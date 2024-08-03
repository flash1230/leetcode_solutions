/* https://leetcode.com/problems/filling-bookcase-shelves/
1105. Filling Bookcase Shelves
Medium
DP
*/
class Solution
{
public:
    int minHeightShelves(vector<vector<int>> &books, int shelfWidth)
    {
        vector<int> dp(books.size() + 1);
        dp[0] = 0;
        dp[1] = books[0][1];
        for (int i = 1; i <= books.size(); i++)
        {
            int rem = shelfWidth - books[i - 1][0];
            int maxHeight = books[i - 1][1];
            dp[i] = dp[i - 1] + maxHeight;
            for (int j = i - 1; j > 0 && rem - books[j - 1][0] >= 0; j--)
            {
                rem -= books[j - 1][0];
                maxHeight = max(maxHeight, books[j - 1][1]);
                dp[i] = min(dp[i], dp[j - 1] + maxHeight);
            }
        }
        return dp[books.size()];
    }
};