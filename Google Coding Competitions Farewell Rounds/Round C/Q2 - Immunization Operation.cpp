#include <bits/stdc++.h>

int main() {
  int T = 0;
  std::cin >> T;
  for (int t = 1; t <= T; ++t) {
    int v = 0, m = 0;
    std::cin >> v >> m;
    std::map<int64_t, std::vector<int>> ps;
    for (int i = 0; i < v; ++i) {
      int p = 0;
      std::cin >> p;
      ps[p].push_back(i);
    }
    std::map<int64_t, std::vector<int>> ds;
    for (int i = 0; i < v; ++i) {
      int d = 0;
      std::cin >> d;
      ds[d].push_back(i);
    }
    std::set<int64_t> holding;

    std::cout << "Case #" << t << ":";

    int64_t curr = 0;
    for (int i = 0; i < m; ++i) {
      int delivered = 0;
      int64_t x = 0;
      std::cin >> x;

      auto p_it = ps.lower_bound(curr);
      auto p_end = ps.upper_bound(curr + x);
      auto d_it = ds.lower_bound(curr);
      auto d_end = ds.upper_bound(curr + x);
      if (x < 0) {
        p_it = ps.upper_bound(curr);
        if (p_it == ps.end() || p_it->first != curr) {
          p_it--;
        }
        d_it = ds.upper_bound(curr);
        if (d_it == ds.end() || d_it->first != curr) {
          d_it--;
        }
        p_end = ps.lower_bound(curr + x);
        p_end--;
        d_end = ds.lower_bound(curr + x);
        d_end--;
      }

      //   std::cerr << " from " << curr << " to " << curr + x << std::endl;
      //   std::cerr << " p_end " << p_end->first << " d_end " << d_end->first
      //             << std::endl;
      curr = curr + x;
      while (p_it != p_end || d_it != d_end) {
        while (p_it != p_end && (p_it->first < d_it->first || d_it == d_end)) {
          int collected = 0;
          auto &vacc = p_it->second;
          for (auto p : vacc) {
            holding.insert(p);
            collected++;
            // std::cerr << " - pick p " << p << std::endl;
          }
          vacc.clear();
          if (x > 0) {
            p_it++;
          } else {
            p_it--;
          }
          //   std::cerr << "pick p " << p_it->first << " picked " << collected
          //             << std::endl;
        }
        if (d_it != d_end) {
          //   std::cerr << "dlvr d " << d_it->first << " " << delivered
          //             << std::endl;
          const auto &to_deliver = d_it->second;
          for (auto p : to_deliver) {
            const auto it = holding.find(p);
            if (it != holding.end()) {
              delivered++;
              holding.erase(it);
            }
          }
          //   std::cerr << "dlvr d " << d_it->first << " " << delivered
          //             << std::endl;
          if (x > 0) {
            d_it++;
          } else {
            d_it--;
          }
        }
      }
      std::cout << ' ' << delivered;
    }
    std::cout << std::endl;
  }
}
