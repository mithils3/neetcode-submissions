#include <vector>
#include <string>
#include <stack>
using namespace std;
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> numbers;
        for (string &s : tokens)
        {
            if (s == "+" || s == "-" || s == "/" || s == "*")

            {
                int numOne = numbers.top();
                numbers.pop();
                int numTwo = numbers.top();
                numbers.pop();
                switch (s[0])
                {
                case '+':
                {

                    numbers.push(numOne + numTwo);
                    break;
                }
                case '-':
                {
                    numbers.push(numTwo - numOne);
                    break;
                }
                case '/':
                {
                    numbers.push(numTwo / numOne);
                    break;
                }
                case '*':
                {
                    numbers.push(numTwo * numOne);
                    break;
                }
                default:
                    break;
                }
            }
            else {
                numbers.push(stoi(s));
            }
        }
        return numbers.top();
    }
};
