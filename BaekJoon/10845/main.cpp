#include <iostream>
#include <queue>
#include <string>

class NewQueue : public std::queue<int>
{
public:
  void push(int x)
  {
    std::queue<int>::push(x);
  }

  int pop()
  {
    if (std::queue<int>::empty())
    {
      return -1;
    }
    int front = std::queue<int>::front();
    std::queue<int>::pop();
    return front;
  }

  int size()
  {
    return std::queue<int>::size();
  }

  int empty()
  {
    return std::queue<int>::empty();
  }

  int front()
  {
    if (std::queue<int>::empty())
    {
      return -1;
    }
    return std::queue<int>::front();
  }

  int back()
  {
    if (std::queue<int>::empty())
    {
      return -1;
    }
    return std::queue<int>::back();
  }
};

int main() 
{
  int command_num;
  std::cin >> command_num;
  std::string command;
  NewQueue queue;
  for (int i = 0; i < command_num; i++)
  {
    std::cin >> command;
    if (command == "push")
    {
      int x;
      std::cin >> x;
      queue.push(x);
    }
    else if (command == "pop")
    {
      std::cout << queue.pop() << std::endl;
    }
    else if (command == "size")
    {
      std::cout << queue.size() << std::endl;
    }
    else if (command == "empty")
    {
      std::cout << queue.empty() << std::endl;
    }
    else if (command == "front")
    {
      std::cout << queue.front() << std::endl;
    }
    else if (command == "back")
    {
      std::cout << queue.back() << std::endl;
    }
  }
  return 0;
}