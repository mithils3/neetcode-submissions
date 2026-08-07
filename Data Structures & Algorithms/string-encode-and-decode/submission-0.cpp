#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    string encode(vector<string> &strs)
    {
        string output;
        for (string s : strs){
            output += to_string(s.size()) + "_" + s;
        }
        return output;
    }

    vector<string> decode(string s)
    {
        vector<string> output;
        string buffer;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '_') {
                int length = stoi(buffer);
                output.push_back(s.substr(i+1,length));
                buffer.clear();
                i += length;

            } else {
                buffer += s[i];
            }

        }
        return output;
    }
};
