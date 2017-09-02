/**
 * @Author: Joey Teng <Toujour>
 * @Date:   31-Aug-2017
 * @Email:  joey.teng.dev@gmail.com
 * @Filename: coconut.cpp
 * @Last modified by:   Toujour
 * @Last modified time: 31-Aug-2017
 */



// Concealed Coconut
// #include <iostream>
#include <fstream>
#include <cmath>
#define INFILE "cocoin.txt"
#define OUTFILE "cocoout.txt"

std::ifstream cin(INFILE);
std::ofstream cout(OUTFILE);

int main() {
    int64_t Ix = 0;
    int64_t Iy = 0;
    int64_t Id = 0;
    int64_t Cx = 0;
    int64_t Cy = 0;
    int64_t Cd = 0;

    cin >> Ix >> Iy >> Id >> Cx >> Cy >> Cd;

    int64_t dist = ((Ix - Cx) * (Ix - Cx) + (Iy - Cy) * (Iy - Cy));
    int64_t rad = (Id + Cd) * (Id + Cd);
    int64_t bigger = std::max(Id, Cd);
    int64_t smaller = std::min(Id, Cd);

    // std::cout << dist << ' ' << rad << ' ' << bigger << ' ' << smaller << std::endl;

    if (dist <= rad && (std::sqrt(dist) + smaller) >= bigger) {
        cout << "yes" << std::endl;
    } else {
        cout << "no" << std::endl;
    }

    return 0;
}
