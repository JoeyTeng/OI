#include <bits/stdc++.h>

int B = 0;
int L = 0;
int D = 0;

std::vector<int> score;
std::vector<int> days;
std::vector<int> ship;
std::vector<std::vector<int>> library;

/*
int cmp(const std::pair<int, std::pair<int, int>> &left,
        const std::pair<int, std::pair<int, int>> &right) {
    return (left.first < right.first) ||
           (left.first == right.first &&
            left.second.second < right.second.second);
}
*/

void input() {
    std::cin >> B >> L >> D;
    for (auto i = 0; i < B; ++i) {
        int tmp;
        std::cin >> tmp;
        score.push_back(tmp);
    }

    for (auto i = 0; i < L; ++i) {
        int N;
        int T;
        int M;
        std::vector<int> books;

        std::cin >> N >> T >> M;
        days.push_back(T);
        ship.push_back(M);
        for (auto j = 0; j < N; ++j) {
            int book;
            std::cin >> book;
            books.push_back(book);
        }

        std::sort(
            books.begin(), books.end(), [&](auto l, auto r) -> auto {
                return score[l] > score[r];
            });
        library.push_back(books);
    }
}

auto &scheduling() {
    auto &schedule = *(new std::vector<int>());
    /*
    schedule.push_back(1);
    schedule.push_back(0);
    // */
    // /*
    // heuristic function for maximum score earned by i-th lib when using j days
    // to scan (including sign-up period)
    std::vector<std::vector<int>> D_potential;

    for (auto i = 0; i < library.size(); ++i) {
        auto pointer = 0;
        std::vector<int> total;

        for (auto j = 0; j < days[i]; ++j) {
            total.push_back(0);
        }
        for (auto j = days[i]; j < D; ++j) {
            total.push_back(total.back());
            for (auto k = 0; k < ship[i]; ++k, ++pointer) {
                if (pointer >= library[i].size()) {
                    break;
                }
                total.back() += score[library[i][pointer]];
                /*
                std::cerr << "   - lib " << i << " day " << j << " book " << k
                          << " subtotal " << total.back() << std::endl;
                // */
            }
        }
        D_potential.push_back(total);
    }
    // */
    std::cerr << " - finish calculating D_potential" << std::endl;
    /*
    for (auto &row : D_potential) {
        for (auto cell : row) {
            std::cerr << cell << ' ';
        }
        std::cerr << std::endl;
    }
    // */
    // /*
    std::map<int, std::pair<int, std::pair<int, int>>> f;
    for (auto j = 0; j < D; ++j) {
        f[j] = std::make_pair(D_potential[0][D - j], std::make_pair(-1, 0));
    }

    for (auto i = 1; i < library.size(); ++i) {
        if (i % 50 == 0) {
            std::cerr << " - using " << i << "-th library" << std::endl;
        }
        auto period = days[i];
        for (auto j = D; j >= period; --j) {
            int prev_s = f[j - period].first;
            int prev = f[j - period].second.second;
            int new_s = prev_s + D_potential[i][D - j];

            if (new_s > f[j].first) {
                f[j] = std::make_pair(new_s, std::make_pair(prev, i));
            }
            /*
            std::cerr << "   - lib(" << i << ") -> day(" << j
                      << "): " << f[j].first << std::endl;
            // */
        }
    }

    int maximum = 0;
    int index = -1;
    for (auto &it : f) {
        /*
        std::cerr << it.first << " (" << it.second.first << ", "
                  << it.second.second.first << " -> " << it.second.second.second
                  << ")" << std::endl;
        // */
        if (it.second.first > maximum) {
            index = it.first;
            maximum = it.second.first;
        }
    }
    /*
    std::cerr << " - Maximum " << maximum << " at day " << index << std::endl;
    // */
    while (f.find(index) != f.end()) {
        auto prev = f[index].second.first;
        auto curr = f[index].second.second;
        schedule.push_back(curr);
        index -= days[curr];
    }
    std::reverse(schedule.begin(), schedule.end());
    // */
    /*
    std::vector<std::pair<int, int>> potential;
    for (auto i = 0; i < library.size(); ++i) {
        auto &lib = library[i];
        auto value = 0;
        auto useable_days = D - days[i];
        auto books = std::min((int)lib.size(), useable_days * ship[i]);

        for (auto j = 0; j < books; ++j) {
            value += score[lib[j]] * score[lib[j]];
        }
        value = ship[i] * value;
        value /= days[i] * days[i] * days[i];

        potential.push_back(std::make_pair(value, i));
    }
    std::sort(potential.begin(), potential.end(), std::greater<>());
    for (auto &it : potential) {
        schedule.push_back(it.second);
    }
    */

    return schedule;
}

const auto simulation(const std::vector<int> &schedule) {
    int day = D;
    std::set<int> signed_up;
    std::set<int> scanned;
    std::vector<int> pointers;
    std::vector<int> picked;
    std::vector<std::vector<int>> &result =
        *(new std::vector<std::vector<int>>());

    for (auto i = 0; i < schedule.size(); ++i) {
        auto next = schedule[i];
        auto period = days[next];
        if (day < period) {
            break;
        }

        if (i % 50 == 0) {
            std::cerr << " - signing " << i << "-th library (" << next << ")"
                      << " with period " << period << std::endl;
        }

        if (signed_up.find(next) != signed_up.end()) {
            /*
            std::cerr << "ERROR: repetitive signed up: library " << next
                      << std::endl;
            // */
            /*
            for (auto lib : schedule) {
                std::cerr << lib << ' ';
            }
            std::cerr << std::endl;
            // */
            continue;
            // exit(-1);
        }

        day -= period;
        pointers.push_back(0);
        picked.push_back(next);
        signed_up.insert(next);
        result.push_back(*(new std::vector<int>()));

        for (auto j = 0; j < picked.size(); ++j) {
            auto lib = picked[j];
            auto &books = library[lib];
            auto max_books = pointers[j] + period * ship[lib];

            // std::cerr << " - simulating library " << lib << " of " <<
            // max_books
            //           << " books max (ship: " << ship[lib] << ")" <<
            //           std::endl;

            for (auto k = pointers[j]; k < max_books; ++k, ++pointers[j]) {
                if (k >= books.size()) {
                    break;
                }
                if (scanned.find(books[k]) != scanned.end()) {
                    max_books++;
                    continue;
                }

                result[j].push_back(books[k]);
                scanned.insert(books[k]);
                // std::cerr << "   - scan book " << books[k] << std::endl;
            }
        }
    }

    /*
    std::cerr << " - picked: ";
    for (auto i : picked) {
        std::cerr << i << ' ';
    }
    std::cerr << std::endl;
    // */

    std::cerr << " - simulate remaining " << day << " days" << std::endl;
    auto period = day;
    for (auto j = 0; j < picked.size(); ++j) {
        auto lib = picked[j];
        auto &books = library[lib];
        auto max_books = pointers[j] + period * ship[lib];

        // std::cerr << " - simulating library " << lib << " of " <<
        // max_books
        //           << " books max (ship: " << ship[lib] << ")" <<
        //           std::endl;

        for (auto k = pointers[j]; k < max_books; ++k, ++pointers[j]) {
            if (k >= books.size()) {
                break;
            }
            if (scanned.find(books[k]) != scanned.end()) {
                max_books++;
                continue;
            }

            result[j].push_back(books[k]);
            scanned.insert(books[k]);
            // std::cerr << "   - scan book " << books[k] << std::endl;
        }
    }
    return std::make_pair(picked, result);
}

void output(const std::vector<int> &schedule,
            const std::vector<std::vector<int>> &result) {
    int count = 0;
    for (auto i = 0; i < result.size(); ++i) {
        if (result[i].size() == 0) {
            count++;
        }
    }

    std::cout << result.size() - count << std::endl;
    for (auto i = 0; i < result.size(); ++i) {
        if (result[i].size() == 0) {
            continue;
        }
        std::cout << schedule[i] << ' ' << result[i].size() << std::endl;

        for (auto book : result[i]) {
            std::cout << book << ' ';
        }
        std::cout << std::endl;
    }
}

int main() {
    std::cerr << "input" << std::endl;
    input();
    /*
    auto max_days = 0;
    for (auto day : days) {
        max_days = std::max(max_days, day);
    }
    auto max_ship = 0;
    for (auto i = 0; i < L; ++i) {
        max_ship =
            std::max(max_ship, std::min(ship[i], (int)library[i].size()));
    }
    std::cerr << " - insight:\n   max ship: " << max_ship
              << "\n   max days: " << max_days << std::endl;
    // */
    /*
    for (auto lib : library) {
        std::cerr << std::endl << "Library:\n";
        for (auto index : lib) {
            std::cerr << index << " (" << score[index] << ")" << std::endl;
        }
    }
    // */
    /*
    std::cerr << " - ship" << std::endl;
    for (auto shipping : ship) {
        std::cerr << shipping << ' ';
    }
    std::cerr << std::endl;
    //*/
    // /*
    std::cerr << "schedule" << std::endl;
    auto &schedule = scheduling();

    std::cerr << "simulation" << std::endl;
    auto &result = simulation(schedule);

    std::cerr << "output" << std::endl;
    output(result.first, result.second);
    // */

    std::vector<std::pair<int, std::pair<int, int>>> f;
    std::set<int> appeared;

    // for (auto i = 0; i < N; ++i) {
    //     auto type = s[i];
    //     auto size = f.size();

    //     if (i % 50 == 0) {
    //         std::cerr << i << "-th iteration" << std::endl;
    //     }

    //     for (auto j = 0; j < size; ++j) {
    //         auto prev = f[j];
    //         auto new_sum = prev.first + type;
    //         if (new_sum <= M && appeared.find(new_sum) == appeared.end())
    //         {
    //             f.push_back(std::make_pair(
    //                 new_sum, std::make_pair(prev.second.second, i)));
    //             appeared.insert(new_sum);
    //         }
    //     }

    //     f.push_back(std::make_pair(type, std::make_pair(-1, i)));
    //     appeared.insert(type);

    //     sort(f.begin(), f.end(), cmp);
    // }

    // std::set<int> delivered;
    // // TODO: DEBUG:
    // for (auto i : appeared) {
    //     std::cerr << " " << i;
    // }
    // std::cerr << std::endl;

    // std::cerr << "output" << std::endl;

    // std::vector<int> combination;
    // auto it = f.back();
    // do {
    //     auto i = it.second.second;
    //     auto prev = it.second.first;
    //     // std::cout << "prev: " << prev << " i: " << i << std::endl;

    //     combination.push_back(i);

    //     it = *std::lower_bound(
    //         f.begin(), f.end(),
    //         std::make_pair(it.first - s[i], std::make_pair(prev, prev)),
    //         cmp);
    // } while (it.second.first != -1);
    // combination.push_back(it.second.second);
    // std::sort(combination.begin(), combination.end());

    // std::cout << combination.size() << std::endl;
    // for (auto index : combination) {
    //     std::cout << index << ' ';
    // }
    // std::cout << std::endl;

    // // TODO: DEBUG
    // // for (auto i : f) {
    // //     std::cout << i.first << ' ' << i.second.first << " -> "
    // //               << i.second.second << std::endl;
    // // }

    return 0;
}
