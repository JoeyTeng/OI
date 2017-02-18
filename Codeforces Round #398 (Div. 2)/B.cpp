// The Queue

#include<bits/stdc++.h>

int main() {
    int n = 0;
    int64_t t = 0;
    int64_t ts = 0;
    int64_t tf = 0;

    std::cin >> ts >> tf >> t >> n;
    int64_t Q = 0;
    int64_t last = 0;
    int64_t ans = 0;
    int64_t ans_Q = INT_MAX;
    std::istream_iterator<int> int_cin(std::cin);
    std::istream_iterator<int> int_end;
    std::list<int> input(int_cin, int_end);
    input.sort();

    last = input.front();
    input.pop_front();
    ans = last - 1;
    ans_Q = ts - ans;
    if (ans_Q < 0) {
        ans_Q = 0;
        ans = ts;
    }
    Q += t;
    last = std::max(last, ts);

    for (int i = 0; i < n - 1; ++i) {
        int64_t tmp = input.front();
        input.pop_front();
        int64_t wait = std::max(Q + last - tmp, int64_t(0));
        if (wait + tmp >= tf) {
            break;
        }
        // std::cout << "tmp " << tmp << " w " << wait << " Q " << Q << " a " << ans << " aQ " << ans_Q << std::endl;

        if (ans_Q > wait) {
            ans = tmp - 1;
            ans_Q = wait;
        }
        Q = wait + t;
        last = std::max(tmp, ts);
    }
    std::cout << ans << std::endl;

    return 0;
}
