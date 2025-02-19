#include <iostream>
#include <stack>
#include <string>

class NewStack : public std::stack<int>
{
public:
  void push(int value)
  {
    std::stack<int>::push(value);
  }

  int pop()
  {
    if (std::stack<int>::empty())
    {
      return -1;
    }
    else
    {
      int value = std::stack<int>::top();
      std::stack<int>::pop();
      return value;
    }
  }

  int size()
  {
    return std::stack<int>::size();
  }

  int empty()
  {
    return std::stack<int>::empty();
  }

  int top()
  {
    if (std::stack<int>::empty())
    {
      return -1;
    }
    else
    {
      return std::stack<int>::top();
    }
  }
};

int main() 
{
  int command_num;
  std::cin >> command_num;
  NewStack stack;
  for (int i = 0; i < command_num; i++)
  {
    std::string command;
    std::cin >> command;
    if (command == "push")
    {
      int value;
      std::cin >> value;
      stack.push(value);
    }
    else if (command == "pop")
    {
      std::cout << stack.pop() << std::endl;
    }
    else if (command == "size")
    {
      std::cout << stack.size() << std::endl;
    }
    else if (command == "empty")
    {
      std::cout << stack.empty() << std::endl;
    }
    else if (command == "top")
    {
      std::cout << stack.top() << std::endl;
    }
  }
  return 0;
}