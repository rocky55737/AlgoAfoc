#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


int main()
{
    int n;
    std::cin >> n;

    std::vector<std::string> words(n);
    for (int i = 0; i < n; i++)
    {
      std::cin >> words[i];
    }

    std::sort(words.begin(), words.end(), [](const std::string& a, const std::string& b) {
      if (a.length() == b.length())
        return a < b;
      return a.length() < b.length();
    });

    words.erase(std::unique(words.begin(), words.end()), words.end());

    for (const auto& word : words)
    {
      std::cout << word << std::endl;
    }

    return 0;
}