// LunchBox

#include<vector>
#include<iostream>
#include<algorithm>

int main(){
    int N = 0;
    int m = 0;
    std::vector<int> k;

    std::cin >> N >> m;
    for (int i = 0; i < m; ++i){
        int tmp;
        std::cin >> tmp;

        k.push_back(tmp);
    }

    std::sort(k.begin(), k.end());

    int count = 0;
    std::vector<int>::iterator it = k.begin();

    while (it != k.end() && N >= *it){
        N -= *it;
        ++count;
        it++;
    }

    std::cout << count << std::endl;

    return 0;
}
