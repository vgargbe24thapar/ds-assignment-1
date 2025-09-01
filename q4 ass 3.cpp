// Write a program to convert an Infix expression into a Postfix expression.
#include <iostream>
using namespace std;
int priority(char ch)
{
  if (ch == '^')
    return 3;
  if (ch == '*' || ch == '/')
    return 2;
  if (ch == '+' || ch == '-')
    return 1;
  return -1;
}
string intopost(string s)
{
  int i = 0;
  string ans = "";
  stack<char> st;
  while (i < s.length())
  {
    if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
      ans += s[i];

    else if (s[i] == '(')
      st.push(s[i]);

    else if (s[i] == ')')
    {
      while (!st.empty() && st.top() != '(')
      {
        ans = ans + st.top();
        st.pop();
      }
      st.pop();
    }

    else
    {
      while (!st.empty() && priority(s[i]) <= priority(st.top()))
      {
        ans = ans + st.top();
        st.pop();
      }
      st.push(s[i]);
    }

    i++;
  }
  while (!st.empty())
  {
    ans = ans + st.top();
    st.pop();
  }

  return ans;
}
int main()
{
  string s = "a+b*(c^d-e)";

  string ans = intopost(s);
  cout << ans;
  return 0;
}
