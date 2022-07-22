//
// Created by zombo on 7/18/2022.
//

#ifndef ADVENTOFCODE_ADVENT2021_H
#define ADVENTOFCODE_ADVENT2021_H

#include <string>
#include <array>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdint>
#include <cstring>
#include <unordered_map>
#include <functional>
#include <cmath>
#include <vector>

using namespace std;

namespace Solutions {

    struct advent_t {
        void (*fn)(vector<string>*);
        std::string input_file;
    };

    void day01(vector<string> *puzzleInput);
    void day02(vector<string> *puzzleInput);
}
#endif //ADVENTOFCODE_ADVENT2021_H
