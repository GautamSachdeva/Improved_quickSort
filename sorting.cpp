#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;


int count;

int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  int count;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
    if(a[i] == x){
    	count++;
	}
  }
  swap(a[l], a[j]);
  return j;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  count = 0;
  int m = partition2(a, l, r);

  randomized_quick_sort(a, l, m - 1 - count);
  randomized_quick_sort(a, m + 1, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
