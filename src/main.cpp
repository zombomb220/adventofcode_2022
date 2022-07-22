#include <chrono>
#include <fcntl.h>
#include <ctime>
#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>
#include "advent2021.h"

using namespace std;
using namespace Solutions;

static const advent_t advent2021[] = {
        {day01, "../input/day01.txt"},
        {day02, "../input/day02.txt"},
};

static vector<string>* load_input(const std::string &filename);

int main() {

    double total_time = 0;

    for (auto &advent : advent2021) {
        vector<string> *puzzleInput = load_input(advent.input_file);

        auto t0 = chrono::steady_clock::now();
        (*advent.fn)(puzzleInput);
        auto elapsed = chrono::steady_clock::now() - t0;

        puzzleInput->clear();

        total_time += elapsed.count();
        printf("[%ld μs]\n", int64_t(elapsed.count() * 1e-3));
    }
    printf("Total: %ld μs\n", int64_t(total_time * 1e-3));

    return 0;
}

static vector<string>* load_input(const std::string &filename) {
    ifstream input;
    input.open(filename);
    assert(input.is_open());

    auto *v = new vector<string>();
    v->reserve(1000);

    while(!input.eof()){
        string line;
        std::getline(input, line);
        v->push_back(line);
    }

    input.close();

    return v;
}
