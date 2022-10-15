#include <bits/stdc++.h>
#include <stack>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'isBalanced' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string isBalanced(string s) 
{
int len=s.length();
string y="YES";
string n="NO";
stack<char> sta;
for(int i=0; i<len; i++)
{
    if((s[i]=='{')||(s[i]=='[')||(s[i]=='('))
    {
        char st=s[i];
        sta.push(st);
    }
    else 
    {
    if(s[i]=='}')
    {
     if(sta.empty()||sta.top()!='{')
     {
        return n;
     }
     else 
     {
     sta.pop();
     }
    }
    if(s[i]==')')
    {
     if(sta.empty()||sta.top()!='(')
     {
        return n;
     }
     else 
     {
     sta.pop();
     }
    }
    if(s[i]==']')
    {
     if(sta.empty()||sta.top()!='[')
     {
        return n;
     }
     else 
     {
     sta.pop();
     }
    }
    }
    continue;   
    }
if(sta.empty()==1)
    {
    return y;
    }
else 
    {
     return n;
    }      
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
