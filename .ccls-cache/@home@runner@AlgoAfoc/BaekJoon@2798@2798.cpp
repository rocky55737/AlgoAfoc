#include <iostream>
#include <vector>

int main() {
  std::vector<int> cards;
  int card, cards_num, sum_limit;
  int max_sum, tmp_sum;

  max_sum = 0;
  std::cin >> cards_num >> sum_limit;
  for (int i = 0; i < cards_num; i++) {
    std::cin >> card;
    cards.push_back(card);
  }
  for (int i = 0; i < cards_num - 2; i++) {
    for (int j = i + 1; j < cards_num - 1; j++) {
      for (int k = j + 1; k < cards_num; k++) {
        tmp_sum = cards[i] + cards[j] + cards[k];
        if (max_sum < tmp_sum && tmp_sum <= sum_limit)
          max_sum = tmp_sum;
      }
    }
  }
  for (int i = 0; i < cards_num; i++)
    std::cout << cards[i] << " ";
  std::cout << std::endl;
  // std::cout << max_sum << std::endl;
  return 0;
}