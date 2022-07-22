//
// Created by zombo on 7/18/2022.
//
#include <iostream>
#include "advent2021.h"
using namespace std;

namespace Solutions {

    void day01_part1(vector<int> *pVector);
    void day01_part2(vector<int> *pVector);

    void day01(vector<string> *puzzleInput){
        cout << "Day 2\n";

        auto formatted = new vector<int>();
        for (const auto &item : *puzzleInput){
            formatted->push_back(stoi(item));
        }

        day01_part1(formatted);
        day01_part2(formatted);
    }

    void day01_part1(vector<int> *pVector) {
        int previousDepth = INT_MAX;
        int count = 0;
        for (auto &i : *pVector) {
            if(previousDepth <= i){
                count++;
            }
            previousDepth = i;
        }

        cout << "\tResult: " << count << "\t\t -> Answer: 1316\n";
    }

    void day01_part2(vector<int> *pVector) {
        int count = 0;

        int prev = INT_MAX;
        for (auto i = 1; i < pVector->size() - 1; i++) {
            int current = pVector->at(i - 1) + pVector->at(i) + pVector->at(i + 1);

            if(prev != INT_MAX) {
                if(current > prev){
                    count++;
                }
            }

            prev = current;
        }
        cout << "\tResult: " << count << "\t\t -> Answer: 1344\n";
    }
}