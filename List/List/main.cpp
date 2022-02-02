#include <iostream>
#include "List.h"

int main() {

    List<int> list;

    list.push_back(11);
    list.push_back(22);
    list.push_back(33);
    list.push_back(44);

    for (size_t i = 0; i < list.GetSize(); i++) {
        std::cout << list[i] << std::endl;
    }

    list.pop_back();

    std::cout << "--------" << std::endl;
    for (size_t i = 0; i < list.GetSize(); i++) {
        std::cout << list[i] << std::endl;
    }

    return 0;
}
