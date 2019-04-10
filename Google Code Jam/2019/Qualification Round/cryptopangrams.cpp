/*
 * @Author: Joey Teng
 * @Email:  joey.teng.dev@gmail.com
 * @Filename: cryptopangrams.cpp
 * @Last modified by:   Joey Teng
 * @Last modified time: 06-Apr-2019
 */
#include <bits/stdc++.h>

class BigInt {
public:
  std::list<int> data;
  int base;
  BigInt() : base(10) { data.clear(); }
  BigInt(std::string _num, int _base = 10) {
    data.clear();
    base = _base;
    for (auto i : _num) {
      if (i >= '0' && i <= '9') {
        data.push_back(int(i) - int('0'));
      }
    }
  }

  auto begin() { return data.begin(); }
  auto end() { return data.end(); }

  auto rbegin() { return data.rbegin(); }
  auto rend() { return data.rend(); }

  auto empty() { return data.empty(); }
  auto size() { return data.size(); }
  void resize(std::list<int>::size_type count, int value = 0) {
    data.resize(count, value);
  }

  int &front() { return data.front(); }
  void push_front(int value) { data.push_back(value); }
  void pop_front() { data.pop_front(); }

  void trim() {
    while (this->size() > 1 && this->front() == 0) {
      this->pop_front;
    }

    for (auto it = this->rbegin(); it != std::prev(this->rend());
         std::advance(it, 1)) {
      *(std::next(it)) += (*it) / this->base;
      *it %= this->base;
    }

    while (!this->empty() && this->front() >= this->base) {
      this->push_front(this->front() / this->base);
      this->front() %= this->base;
    }
  }

  BigInt operator*(BigInt multiplier) {
    BigInt result;
    result.resize(this->size() + multiplier.size());

    for (auto ait = this->rbegin(), cit = result.rbegin(); ait != this->rend();
         std::advance(ait, 1), std::advance(cit, 1)) {
      for (auto [bit, ci] = std::tuple{multiplier.rbegin(), 0};
           bit != multiplier.rend(); std::advance(bit, 1), ++ci) {
        *(std::next(cit, ci)) = ((*ait) * (*bit)) % this->base;
        *(std::next(cit, ci + 1)) += ((*ait) * (*bit)) / this->base;
      }
    }

    result.trim();
  }
  BigInt operator*(int multiplier) {
    BigInt result;
    result.resize(this->size() +
                  int(std::ceil(std::log(multiplier) / std::log(this->base))));

    for (auto ait = this->rbegin(), cit = result.rbegin(); ait != this->rend();
         std::advance(ait, 1), std::advance(cit, 1)) {
      *cit = ((*ait) * multiplier) % this->base;
      *(std::next(cit, 1)) += ((*ait) * multiplier) / this->base;
    }

    result.trim();
  }
  BigInt operator/(BigInt divider) {}
  BigInt operator%(BigInt divider) {}
  bool operator<(BigInt operand) {}
  bool operator==(BigInt operand) {}
};

int main() {
  int T = 0;
  std::cin >> T;
  for (int t = 1; t <= T; ++t) {
    int n = 0;
    int l = 0;
    std::cin >> n >> l;
  }

  return 0;
}
