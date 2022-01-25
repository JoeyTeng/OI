#include <functional>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  vector<double> medianSlidingWindow(vector<int> &nums, int k) {
    // initialisation
    vector<double> ret;
    vector<int> first_k(nums.begin(), next(nums.begin(), k));
    sort(first_k.begin(), first_k.end());

    const size_t mid = k >> 1;
    const size_t right = k - mid;
    // A max heap
    priority_queue<int> smaller_heap(first_k.begin(),
                                     next(first_k.begin(), mid), less<int>());
    // A min heap
    priority_queue<int, vector<int>, greater<int>> greater_heap(
        next(first_k.begin(), mid), first_k.end(), greater<int>());

    // values to be removed from smaller_heap
    priority_queue<int> tbr_s;
    // values to be removed from greater_heap
    priority_queue<int, vector<int>, greater<int>> tbr_g;

    // loop
    const int ret_len = nums.size() - k + 1;
    for (size_t i = 0; i < ret_len; ++i) {
      const auto next = nums[i + k];
      const auto oldest = nums[i];
      if (k & 1) {
        // when odd, greater_heap.size() == smaller_heap.size() + 1
        ret.push_back(greater_heap.top());
      } else {
        ret.push_back(greater_heap.top() / 2.0 + smaller_heap.top() / 2.0);
      }

      const auto median = ret.back();

      if (oldest < median) {
        tbr_s.push(oldest);
      } else {
        tbr_g.push(oldest);
      }

      if (next < median) {
        smaller_heap.push(next);
      } else {
        greater_heap.push(next);
      }

      if (oldest < median && next >= median) {
        // shift 1 from greater to smaller
        smaller_heap.push(greater_heap.top());
        greater_heap.pop();
      } else if (oldest >= median && next < median) {
        greater_heap.push(smaller_heap.top());
        smaller_heap.pop();
      }

      // cleanup tbr
      while (!tbr_s.empty() && tbr_s.top() == smaller_heap.top()) {
        tbr_s.pop();
        smaller_heap.pop();
      }

      while (!tbr_g.empty() && tbr_g.top() == greater_heap.top()) {
        tbr_g.pop();
        greater_heap.pop();
      }
    }

    if (k & 1) {
      // when odd, greater_heap.size() == smaller_heap.size() + 1
      ret.push_back(greater_heap.top());
    } else {
      ret.push_back(greater_heap.top() / 2.0 + smaller_heap.top() / 2.0);
    }

    return ret;
  }
};

int main() {
  vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
  int k = 3;
  vector<double> expected = {1.00000, -1.00000, -1.00000,
                             3.00000, 5.00000,  6.00000};
  auto ret = Solution().medianSlidingWindow(nums, k);
  for (int i = 0; i < expected.size(); ++i) {
    if (abs(ret[i] - expected[i]) > 1e-5) {
      return -1;
    }
  }

  return 0;
}
