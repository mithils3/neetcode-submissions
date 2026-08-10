#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <stack>
using namespace std;

class MinStack
{
public:
    MinStack()
    {
    }
    stack<int> s;
    stack<int> min;

    void push(int val)
    {
        s.push(val);
        if (min.empty())
        {
            min.push(val);
        }
        else
        {
            if (val < min.top())
            {
                min.push(val);
            }
            else
            {
                min.push(min.top());
            }
        }
    }

    void pop()
    {
        s.pop();
        min.pop();
    }

    int top()
    {
        return s.top();
    }

    int getMin()
    {
        return min.top();
    }
};
