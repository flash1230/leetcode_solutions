/* https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/
1491. Average Salary Excluding the Minimum and Maximum Salary
Easy
*/
class Solution
{
public:
    double average(vector<int> &salary)
    {
        double average = 0;
        int mini = min(salary[0], salary[1]);
        int maxi = max(salary[0], salary[1]);
        for (int i = 2; i < salary.size(); i++)
        {
            if (mini > salary[i])
            {
                average = (((i - 2) * average) + mini) / (i - 1);
                mini = salary[i];
            }
            else if (maxi < salary[i])
            {
                average = (((i - 2) * average) + maxi) / (i - 1);
                maxi = salary[i];
            }
            else
                average = (((i - 2) * average) + salary[i]) / (i - 1);
        }
        return average;
    }
};