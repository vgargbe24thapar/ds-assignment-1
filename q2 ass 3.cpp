// Given a string, reverse it using STACK. For example “DataStructure” should be output as
// “erutcurtSataD.”
#include <iostream>
#include <string>
using namespace std;

int main()
{
  string s, rev = "";
  cout << "Enter a string: ";
  cin >> s;

  char stack[100];
  int top = -1;

  for (int i = 0; i < s.length(); i++)
  {
    stack[++top] = s[i];
  }

  while (top != -1)
  {
    rev += stack[top--];
  }

  cout << "Reversed string: " << rev << endl;
  return 0;
}
