//
// Created by Kagura on 2023/7/23.
//
#include <iostream>
#include "../Reg.h"

int main() {
    LPBYTE lpData = nullptr;
    getUserPath(lpData);
    std::cout << "getUserPath: " << lpData << std::endl;

    LSTATUS result = setUserPath(lpData);
    std::cout << "setUserPath: " << lpData << std::endl;
    return 0;
}
