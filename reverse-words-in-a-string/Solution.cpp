#include <stack>

class Solution
{
public:
    void reverseWords(string &s) 
    {
        stack<string> str_storge;
        string tmp;
        for (auto itr = s.begin(); itr != s.end(); ++itr)
        {
            auto c = *itr;
            if (c == ' ' && !tmp.empty())
            {
                str_storge.push(tmp);
                str_storge.push(" ");
                tmp.clear();
            }
            else if (c != ' ')
            {
                tmp.push_back(c);
            }
        }
        
        if (!tmp.empty())
        {
            str_storge.push(tmp);
            tmp.clear();
        }
        else if (!str_storge.empty())
        {
            str_storge.pop();
        }
        
        s.clear();
        while (!str_storge.empty())
        {
            string & str = str_storge.top();
            s.append(str);
            str_storge.pop();
        }
    }
};