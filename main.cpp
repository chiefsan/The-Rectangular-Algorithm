#include<bits/stdc++.h>

using namespace std;
using namespace std::chrono;

int ** randGraph(int n) {
    int **a=new int*[n];
    for(int i=0;i<n;i++) {
        a[i]=new int[n];
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(i==j) {
                a[i][j]=0;
            }
            else {
                a[i][j]=rand()%1000+1;
            }
          }
      }
    return (a);
}

int main () {
  int n = 800;
  int **a=randGraph(n);
  ofstream myfile("input.txt");
  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++) {
      myfile<< a[i][j] << ' ';
  }
  myfile.close();
  system("g++ -o fw floyd-warshall.cpp");
  system("g++ -o ra rectangular.cpp");

  auto start = high_resolution_clock::now();
  system("fw 800");
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cout << "Time taken by function fw: " << duration.count() << " microseconds" << endl;

  start = high_resolution_clock::now();
  system("ra 800");
  stop = high_resolution_clock::now();
  duration = duration_cast<microseconds>(stop - start);
  cout << "Time taken by function ra: " << duration.count() << " microseconds" << endl;


}
