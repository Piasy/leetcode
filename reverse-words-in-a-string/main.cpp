#include <iostream>
#include <vector>
#include <string>

using namespace std;

void reverseWords(string &s);

int main(int argc, char **argv)
{
    string s(argv[1]);
    reverseWords(s);
    return 0;
}

void reverseWords(string &s)
{
    cout << s << endl;
    vector<string> v;
    string tmp = "";
    for (int i = 0; i < s.length(); i ++)
    {
        if (s[i] != ' ')
        {
            tmp += s[i];
        }
        else if (tmp.length() != 0)
        {
            v.push_back(tmp);
            tmp = "";
        }
    }
    if (tmp != "")
    {
        v.push_back(tmp);
        tmp = "";
    }
    s = "";
    if (v.size() == 0)
    {
        return;
    }

    for (int i = v.size() - 1; i > 0; i --)
    {
        s += v[i] + " ";
    }
    s += v[0];
    cout << s << endl;
}
