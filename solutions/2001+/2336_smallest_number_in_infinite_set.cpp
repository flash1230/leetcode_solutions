/* https://leetcode.com/problems/smallest-number-in-infinite-set/
2336. Smallest Number in Infinite Set
Medium
Design Set
*/
class SmallestInfiniteSet
{
public:
    int cur;
    set<int> s;
    SmallestInfiniteSet()
    {
        cur = 1;
    }

    int popSmallest()
    {
        if (s.size())
        {
            int res = *s.begin();
            s.erase(res);
            return res;
        }
        else
        {
            cur++;
            return cur - 1;
        }
    }

    void addBack(int num)
    {
        if (cur > num)
        {
            s.insert(num);
        }
    }
};