#include <bits/stdc++.h>

void print(std::vector<std::vector<double>> dist, std::vector<std::vector<int>> next) {
  const auto size = next.size();
  for (auto i = 0; i < size; ++i) {
    for (auto j = 0; j < size; ++j) {
      if (i != j) {
        auto u = i + 1;
        auto v = j + 1;
        std::cout << "(" << u << " -> " << v << ", " << dist[i][j]
          << ", ";
        std::stringstream path;
        path << u;
        do {
          u = next[u - 1][v - 1];
          path << " -> " << u;
        } while (u != v);
        std::cout << path.str() << ")" << std::endl;
      }
    }
  }
}

void solve(std::vector<std::vector<double>> dist, const int num_vertices) {
  // std::bitset<10000> row_inf(0), col_inf(0);
  register unsigned int t, r, s, i, k, j;
  std::vector<std::vector<int>> next(num_vertices);
  for (i=0; i<num_vertices; ++i)
    next[i].resize(num_vertices);
  for (i = 0; i < num_vertices; ++i) {
    for (j = 0; j < num_vertices; ++j) {
      if (i != j) {
        next[i][j] = j + 1;
      }
    }
  }
  auto start = std::chrono::high_resolution_clock::now();
  for (j = 0; j < num_vertices; ++j) {
    // row_inf.reset();
    // col_inf.reset();
    // for (int m=0; m<num_vertices; m++) {
    //   if (dist[m][j]==INT_MAX)
    //     row_inf[m] = 1;
    //   if (dist[j][m]==INT_MAX)
    //     col_inf[m] = 1;
    // }
    for (i = 0; i < num_vertices; ++i) {
      r = dist[i][j];
      if (r==INT_MAX) {
        continue;
      }
      for (k = 0; k < num_vertices; ++k) {
        t = dist[j][k];
        if (t==INT_MAX || i==j || k==j) {
          continue;
        }
        s = dist[i][k];
        if (s > r + t) {
          s = r + t;
          next[i][k] = next[i][j];
        }
      }
    }
  }
  // print(dist, next);
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

  std::ofstream myfile("ra_output.txt");
  myfile << duration.count();
  myfile.close();
}

int main (int argc, char **argv) {
  auto n = atoi(argv[1]);
  std::vector<std::vector<double>> w(n);
  for (auto i=0; i<n; ++i) {
    w[i].resize(n);
  }
  int temp;
  std::ifstream myfile("input.txt", std::ios::in);
  for (auto i=0; i<n; ++i)
    for (auto j=0; j<n; ++j) {
      myfile>>temp;
      w[i][j] = temp;
      if (w[i][j]==0)
        w[i][j] = INT_MAX;
    }

  auto num_vertices = n;

  solve (w, num_vertices);
  // cin.ignore();
  // cin.get();
  return 0;
}
