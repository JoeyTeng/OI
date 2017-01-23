// cablecar

#include<bits/stdc++.h>

int main(){
    int N = 0;
    int max_length = 0;
    int length = 0;
    int length_extend = 0; // Possible length at the right of second high
    int height_left = 0; // First High
    int height_right = 0; //Second High

    std::cin >> N;
    for (int i = 0; i < N; ++i){
        int height;
        std::cin >> height;

        if (height >= height_left){
            // Wrong. Need to be modified.
            // Exception: Leftest mountain is the highest && the rightest mountain (last mountain) is not the second highest one. 
            // Solution: Record maximum height and second max, applying diff processing logic.
            height_left = height;
            height_right = 0;
            max_length = std::max(length + length_extend + 1, max_length); // Important! +1 here to include the mountain at the right side! Do not +1 for all the cases if the rightest mountain is lower (in case that the mountain ends)
            length = 0;
            length_extend = 0;
        } else if (height >= height_right){
            height_right = height;
            length += length_extend + 1; // Important also. Include this new mountain
            length_extend = 0;
        } else {
            ++length_extend;
        }
    }

    max_length = std::max(max_length, length); // Important: Update the result if none of the cases above are fitted. E.g. The rightest mountain is not the highest.
    if (N == 1){ // Possible Trick
        max_length = 0;
    }

    std::cout << max_length << std::endl;

    return 0;
}

