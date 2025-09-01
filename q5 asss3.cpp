// Write a program for the evaluation of a Postfix expression.
#include <iostream>
using namespace std;

int evaluatePostfix(string expr)
{
  stack<int> st;

  for (int i = 0; i < expr.length(); i++)
  {
    char ch = expr[i];

    if (isspace(ch))
      continue;

    if (isdigit(ch))
    {

      st.push(ch - '0');
    }
    else
    {

      int val2 = st.top();
      st.pop();
      int val1 = st.top();
      st.pop();

      switch (ch)
      {
      case '+':
        st.push(val1 + val2);
        break;
      case '-':
        st.push(val1 - val2);
        break;
      case '*':
        st.push(val1 * val2);
        break;
      case '/':
        st.push(val1 / val2);
        break;
      case '^':
      {
        int res = 1;
        for (int j = 0; j < val2; j++)
          res *= val1;
        st.push(res);
        break;
      }
      }
    }
  }

  return st.top();
}

int main()
{
  string postfix;
  cout << "Enter Postfix Expression (single digit operands): ";
  getline(cin, postfix);

  int result = evaluatePostfix(postfix);
  cout << "Result: " << result << endl;

  return 0;
}
