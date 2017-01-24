// cablecar

#include<bits/stdc++.h>

template<typename T>
    int scan(T begin, T end);

int main(){
    int N = 0;

    std::cin >> N;

    std::istream_iterator<int> int_cin(std::cin);
    std::istream_iterator<int> int_end;
    std::vector<int> h(int_cin, int_end);

    std::cout << std::max(scan(h.begin(), h.end()), scan(h.rbegin(), h.rend())) << std::endl; // Do it in both direction. See testcase self 4
    // Do in both direction could cover all exceptional cases with simplest scanning process.

    return 0;
}

template<typename T>
    int scan(T begin, T end){

    int max_length = 0;
    int length = 0; // Merged length till now
    int length_extend = 0; // Possible length at the right of second high
    int height_left = 0; // First High
    int height_right = 0; //Second High

    for (auto it = begin; it != end; ++it){
        int height = *it;

        if (height >= height_left){ // First case. Reset all
            height_left = height;
            height_right = 0;
            max_length = std::max(max_length, length + length_extend + 1); // Important! +1 here to include the mountain at the right side! Do not +1 for all the cases if the rightest mountain is lower (in case that the mountain ends)
            length = 0;
            length_extend = 0;
        } else {
            ++length_extend;
        }
    }

    return max_length;
}

