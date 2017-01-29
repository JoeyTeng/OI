// honey

#include<bits/stdc++.h>

int main() {
    int N = 0;
    int M = 0;
    int K = 0;

    std::vector<int> heap;

    std::cin >> N >> M >> K;

    std::istream_iterator<int> int_cin(std::cin);
    std::istream_iterator<int> int_end;

    heap.assign(int_cin, int_end);

    std::make_heap(heap.begin(), heap.end());  // max heap

    int64_t honey = 0;

    while (K && heap[0]) {
        if (heap[0] > M) {
            int residual = heap[0] - std::min(K, heap[0] / M) * M;
            honey += heap[0] - residual;
            K -= std::min(K, heap[0] / M);

            std::pop_heap(heap.begin(), heap.end());
            heap.back() = residual;
        } else {
            honey += heap[0];
            --K;

            std::pop_heap(heap.begin(), heap.end());
            heap.back() = 0;
        }
        std::push_heap(heap.begin(), heap.end());
    }

    std::cout << honey << std::endl;

    return 0;
}
