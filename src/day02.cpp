//
// Created by zombo on 7/18/2022.
//
#include <iostream>
#include "advent2021.h"
using namespace std;

namespace Solutions {

    struct instruction {
        int value;
        char dir;
    };

    void day02_part1(vector<instruction> *pVector);
    void day02_part2(vector<instruction> *pVector);

    void day02(vector<string> *puzzleInput){
        cout << "Day 2\n";

        auto formatted = new vector<instruction>();
        for (const auto &item : *puzzleInput){
            struct instruction p;
            p.dir = item[0];
            p.value = (item[item.size()-1]) - '0';
            formatted->push_back(p);
        }

        day02_part1(formatted);
        day02_part2(formatted);
    }

    void day02_part1(vector<instruction> *pVector) {
        int pos = 0;
        int depth = 0;

        for (const auto &item : *pVector){
            switch (item.dir) {
                case 'f':
                    pos += item.value;
                break;
                case 'd':
                    depth += item.value;
                    break;
                case 'u':
                    depth -= item.value;
                break;
            }
        }

        cout << "\tResult: " << pos * depth << "\t\t -> Answer: 2147104\n";
    }

    void day02_part2(vector<instruction> *pVector) {
        int pos = 0;
        int depth = 0;
        int aim = 0;

        for (const auto &item : *pVector){
            switch (item.dir) {
                case 'f':
                    pos += item.value;
                    depth += (aim * item.value);
                    break;
                case 'd':
                    aim += item.value;
                    break;
                case 'u':
                    aim -= item.value;
                    break;
            }
        }

        cout << "\tResult: " << pos * depth << "\t -> Answer: 2044620088\n";
    }
}