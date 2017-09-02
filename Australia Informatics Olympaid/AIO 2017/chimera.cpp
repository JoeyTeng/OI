// Chimera II (chimera)
#include <iostream>
#include <fstream>
#include <string>
#define INFILE "chimin.txt"
#define OUTFILE "chimout.txt"

std::ifstream cin(INFILE);
std::ofstream cout(OUTFILE);

int main() {
    int len = 0;
    std::string S;
    std::string T;
    std::string D; // D for destination
    int mutation = -1;
    int current_chain = -1;
    
    cin >> len >> S >> T >> D;
    
    for (int i = 0; i < len; ++i) {
        if (S[i] != D[i] && T[i] != D[i]) {
            cout << "PLAN FOILED" << std::endl;
            return 0;
        }
        if (S[i] == D[i] && T[i] == D[i]) {
            continue;
        }
        if (S[i] == D[i]) {
            if (current_chain != 0) {
                current_chain = 0;
                ++mutation;
            }
        } else if (T[i] == D[i]) {
            if (current_chain != 1) {
                current_chain = 1;
                ++mutation;
            }
        }
    }
    
    cout << "SUCCESS\n" << mutation << std::endl;
}