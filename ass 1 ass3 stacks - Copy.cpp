
// Develop a menu driven program demonstrating the following operations on a Stack using array:
// (i) push(), (ii) pop(), (iii) isEmpty(), (iv) isFull(), (v) display(), and (vi) peek().
#include <iostream>
using namespace std;

int stack[50], top = -1, n;

void push(int val)
{
  if (top == n - 1)
    cout << "Stack Overflow\n";
  else
  {
    top++;
    stack[top] = val;
  }
}

void pop()
{
  if (top == -1)
    cout << "Stack Underflow\n";
  else
  {
    cout << "Popped: " << stack[top] << "\n";
    top--;
  }
}

void isEmpty()
{
  if (top == -1)
    cout << "Stack is Empty\n";
  else
    cout << "Stack is not Empty\n";
}

void isFull()
{
  if (top == n - 1)
    cout << "Stack is Full\n";
  else
    cout << "Stack is not Full\n";
}

void display()
{
  if (top == -1)
    cout << "Stack is Empty\n";
  else
  {
    for (int i = top; i >= 0; i--)
      cout << stack[i] << " ";
    cout << "\n";
  }
}

void peek()
{
  if (top == -1)
    cout << "Stack is Empty\n";
  else
    cout << "Top Element: " << stack[top] << "\n";
}

int main()
{
  int choice, val;
  cout << "Enter size of stack: ";
  cin >> n;
  while (1)
  {
    cout << "\n1.Push 2.Pop 3.isEmpty 4.isFull 5.Display 6.Peek 7.Exit\n";
    cout << "Enter choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
      cout << "Enter value: ";
      cin >> val;
      push(val);
      break;
    case 2:
      pop();
      break;
    case 3:
      isEmpty();
      break;
    case 4:
      isFull();
      break;
    case 5:
      display();
      break;
    case 6:
      peek();
      break;
    case 7:
      return 0;
    default:
      cout << "Invalid Choice\n";
    }
  }
}
