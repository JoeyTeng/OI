/*
 * @Author: Joey Teng
 * @Email:  joey.teng.dev@gmail.com
 * @Filename: slideshow.cpp
 * @Last modified by:   Joey Teng
 * @Last modified time: 01-Mar-2019
 */
#include <algorithm>
#include <vector>
#include <utility>
#include <tuple>
#include <map>
#include <cmath>
#include <cstring>
#include <string>
#include <set>
#include <stack>
#include <climits>
#include <queue>
#include <functional>
#include <iostream>
#include <ctime>
#include <fstream>

int N;
std::vector<std::pair<int, int> > slideshow; //a ordered array of all the indicies of the pics
std::vector<std::vector<int> > pics;
std::vector<bool> horizontal; //True if it is horizontal
std::map<std::string, int> tags;
// std::map<std::pair<std::pair<int, int>, std::pair<int, int> >, int> score;

int CalculateSingleScore(const std::vector<int> & picA, const std::vector<int> & picB) {
    std::set<int> A(picA.begin(), picA.end());
    std::set<int> B(picB.begin(), picB.end());
    std::set<int> cross;

    for (auto a : A) {
        auto pos = B.find(a);
        if (pos != B.end()) {
            cross.insert(a);
        }
    }
    return std::min(std::min(A.size() - cross.size(), B.size() - cross.size()), cross.size());
}

void input() {
    std::cin >> N;
    std::string H(1, 'H');

    for (int i = 0; i < N; ++i) {
        std::string tmp;
        std::vector<int> current_tags;

        std::cin >> tmp;
        if (tmp == H) {
            horizontal.push_back(true);
        } else {
            horizontal.push_back(false);
        }

        int ttmp;
        std::cin >> ttmp;
        for (int j = 0; j < ttmp; ++j) {
            std::cin >> tmp;
            auto it = tags.find(tmp);

            if (it != tags.end()) {
                current_tags.push_back(it -> second);
            } else {
                tags.insert(std::make_pair(tmp, tags.size()));
                current_tags.push_back(tags.size() - 1);
            }
        }
        pics.push_back(current_tags);
    }
}

// void Preprocessing() {
//     for (int i = 0; i < pics.size(); ++i) {
//         for (int j = i + 1; j < pics.size(); ++j) {
//             if (!horizontal[i] || !horizontal[j]) {
//                 continue;
//             }

//             if (horizontal[i] && horizontal[j]) {
//                 int tmp_score = CalculateSingleScore(pics[i], pics[j]);
//                 score.insert(std::make_pair(std::make_pair(std::make_pair(i, -1), std::make_pair(j, -1)), tmp_score));
//             }
//         }
//     }
// }

void anneal() {
    std::srand(std::time(0));
    std::time_t start = std::time(0);
    double T = 100;
    double TM = 1e-4;
    double c = 0.995;

    int score = 0;
    auto best = slideshow;

    while (T > TM) {
        int A = std::rand() % slideshow.size();
        int B = std::rand() % slideshow.size();

        if (slideshow[A].second != -1)
    }

    while (T > TM) {
        int now = 0;
        std::printf("%.5lf %d %.5lf\n", T, score, now);
        int cnt=0;
        for (int i = 0; i < slideshow.size(); i++) {
            if (horizontal[i] == horizontal[j]) {
                double now = modu();
                int t = dv[i];
                dv[i] = dv[j];
                double td = modu(), p = randd();
                if (td >= now || exp((td - now) / T) > p) {
                    //printf("%.5lf %.5lf\n",exp((td - now) / T), p);
                    //if (++cnt>=(n<<3)) break;
                    continue;
                }
                dv[i] = t;
            }
        }

        T *= c;
    }
}

int main() {
    input();
    // for (auto pic : pics) {
    //     for (auto tag : pic) {
    //         std::cout << tag << ' ';
    //     }
    //     std::cout << std::endl;
    // }
    // Preprocessing();
    return 0;
}