/* https://leetcode.com/problems/implement-queue-using-stacks/
232. Implement Queue using Stacks
Easy
Stack
*/
class MyQueue
{
public:
    stack<int> st1, st2;
    
    MyQueue()
    {
    }

    void push(int x)
    {
        st1.push(x);
    }

    int pop()
    {
        while (!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }
        int temp = st2.top();
        st2.pop();
        while (!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }
        return temp;
    }

    int peek()
    {
        while (!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }
        int temp = st2.top();
        while (!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }
        return temp;
    }

    bool empty()
    {
        return st1.empty();
    }
};