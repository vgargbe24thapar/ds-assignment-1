// Write a program that checks if an expression has balanced parentheses.
#include <iostream>
using namespace std;
bool balanced(string s)
{
  stack<char> st;

  int n = s.length();

  int i = 0;
  while (i < n)
  {
    if (s[i] == '(' || s[i] == '[' || s[i] == '{')
    {
      st.push(s[i]);
    }
    else if (!st.empty())
    {
      if ((s[i] == ')' && st.top() == '(') || (s[i] == ']' && st.top() == '[') || (s[i] == '}' && st.top() == '{'))
      {
        st.pop();
      }
    }
    i++;
  }
  return st.empty();
}
int main()
{
  string s;

  cout << "Enter String:";
  cin >> s;

  cout << balanced(s);

  return 0;
}
