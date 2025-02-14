/* https://leetcode.com/problems/product-of-the-last-k-numbers/
1352. Product of the Last K Numbers
Medium
Prefix Sum
*/
class ProductOfNumbers
{
public:
    vector<int> prods;
    int last_zero = -1;
    ProductOfNumbers()
    {
    }

    void add(int num)
    {
        if (num == 0)
            last_zero = prods.size();
        if (prods.empty() || prods.back() == 0)
            prods.push_back(num);
        else
            prods.push_back(num * prods.back());
    }

    int getProduct(int k)
    {
        int n = prods.size();
        if (last_zero >= n - k)
            return 0;
        if (n == k)
            return prods[n - 1];
        if (n > k && prods[n - k - 1] == 0)
            return prods[n - 1];
        else
            return prods[n - 1] / prods[n - k - 1];
    }
};