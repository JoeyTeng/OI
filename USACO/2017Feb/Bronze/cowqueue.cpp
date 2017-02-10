// cowqueue

#define TASK std::string("cowqueue")
#include<bits/stdc++.h>

struct Data {
    Data(int coming, int duration) {
        this -> coming = coming;
        this -> duration = duration;
    }
    friend int operator<(const Data& left, const Data& right);

    int coming;
    int duration;
};
int operator<(const Data& left, const Data& right) {
    return (left.coming == right.coming) ? (left.duration > right.duration) : (left.coming < right.coming);
}

std::ifstream fin(TASK + ".in");
std::ofstream fout(TASK + ".out");

int main() {
    int N = 0;
    int counting = 0;
    std::vector<Data> cow;
    fin >> N;
    

    for (int i = 0; i < N; ++i) {
        int coming = 0;
        int duration = 0;
        fin >> coming >> duration;
        cow.push_back(Data(coming, duration));
    }
    std::sort(cow.begin(), cow.end());
    for (auto i : cow) {
        int coming = i.coming;
        int duration = i.duration;
        counting += std::max(coming - counting, 0) + duration;
    }

    fout << counting << std::endl;

    return 0;
}
