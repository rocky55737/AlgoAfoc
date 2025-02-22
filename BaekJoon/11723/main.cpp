#include <iostream>
#include <bitset>
#include <string>
#include <ios>

class NewSet {
public:
    NewSet() : set() {}

    void add(const int value) {
        set.set(value - 1);
    }

    void remove(const int value) {
        set.reset(value - 1);
    }

    int check(const int value) const {
        return set.test(value - 1);
    }

    void toggle(const int value) {
        set.flip(value - 1);
    }

    void all() {
        set.set();
    }

    void empty() {
        set.reset();
    }

private:
    std::bitset<20> set;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int command_num;
    std::cin >> command_num;
    NewSet set;

    for (int i = 0; i < command_num; i++) {
        std::string command;
        std::cin >> command;

        int value;
        if (command == "add" || command == "remove" || command == "check" || command == "toggle") {
            std::cin >> value;
        }

        if (command == "add") {
            set.add(value);
        } else if (command == "remove") {
            set.remove(value);
        } else if (command == "check") {
            std::cout << set.check(value) << '\n';
        } else if (command == "toggle") {
            set.toggle(value);
        } else if (command == "all") {
            set.all();
        } else if (command == "empty") {
            set.empty();
        }
    }

    return 0;
}