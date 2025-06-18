#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <cctype>
#include <map>

using namespace std;

int main()
{
  string expression_str;
  cin >> expression_str;
  map<char, int> operator_rank = {
    {'(', 0},
    {')', 0},
    {'*', 1},
    {'/', 1},
    {'+', 2},
    {'-', 2}
  };
  stack<char> operator_stack;
  vector<char> print_buffter;
  for (size_t i = 0; i < expression_str.size(); i++)
  {
    if (isalpha(expression_str[i]))
    {
      print_buffter.push_back(expression_str[i]);
    }
    else
    {
      if (expression_str[i] == ')')
      {
        while (operator_stack.top() != '(')
        {
          print_buffter.push_back(operator_stack.top());
          operator_stack.pop();
        }
        operator_stack.pop();
      }
      else if (operator_stack.empty() || operator_stack.top() == '(' || operator_rank[expression_str[i]] < operator_rank[operator_stack.top()])
      {
        operator_stack.push(expression_str[i]);
      }
      else
      {
        while (!operator_stack.empty() && operator_stack.top() != '(' && operator_rank[expression_str[i]] >= operator_rank[operator_stack.top()])
        {
          print_buffter.push_back(operator_stack.top());
          operator_stack.pop();
        }
        operator_stack.push(expression_str[i]);
      }
    }
  }
  while (!operator_stack.empty())
  {
    print_buffter.push_back(operator_stack.top());
    operator_stack.pop();
  }
  for (char i : print_buffter)
  {
    cout << i;
  }
  cout << "\n";
  return 0;
}