/**
 * @Author: Joey Teng <Toujour>
 * @Date:   31-Aug-2017
 * @Email:  joey.teng.dev@gmail.com
 * @Filename: snake.cpp
 * @Last modified by:   Toujour
 * @Last modified time: 31-Aug-2017
 */



// Snake Charmer (snake)
#include <iostream>
#include <fstream>
#include <cmath>
#define INFILE "snakein.txt"
#define OUTFILE "snakeout.txt"

std::ifstream cin(INFILE);
std::ofstream cout(OUTFILE);

int main() {
    int X = 0;
    int Y = 0;

    cin >> X >> Y;

    int dec = std::min(std::abs(X), std::abs(Y));
    int pos = (X * Y < 0) ? -1 : ((X * Y == 0) ? 0 : 1);

    if (X > 0) {
        if (Y > 0) {
            X -= dec;
            Y -= dec;
        } else if (Y < 0) {
            X -= dec;
            Y = -Y - dec;
            cout << "RR";
            --dec;
        }
    } else if (X < 0) {
        if (Y > 0) {
            X = -X - dec;
            Y -= dec;
        } else if (Y < 0) {
            X = -X - dec;
            Y = -Y - dec;
            cout << "LL";
            --dec;
        }
    }

    if (pos == 1) {
        for (int i = 0; i < dec; ++i) {
            cout << "RL";
        }
    } else if (pos == -1) {
        for (int i = 0; i < dec; ++i) {
            cout << "LR";
        }
    }

    if (Y > 0) {
        cout << "RLL";
        X = Y - 1;
        Y = 0;
    } else if (Y < 0) {
        cout << "RRR";
        X = Y + 1;
        Y = 0;
    }
    // std::cout << X << ' ' << Y << std::endl;
    if (X > 0) {
        for (int i = 0; i < (X / 2); ++i) {
            cout << "RRLL";
        }
        if (X % 2) {
            cout << "R";
        }
    } else if (X < 0) {
        for (int i = 0; i > (X / 2); --i) {
            cout << "LLRR";
        }
        if (X % 2) {
            cout << "L";
        }
    }
    cout << std::endl;

    return 0;
}
