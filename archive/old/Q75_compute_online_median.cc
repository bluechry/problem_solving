// You want to compute the running median of a sequence of numbers.
// The sequence is presented to you in a streaming fashion - you cannot back up
// to read an earlier value, and you need to output the median after reading in
// each new element. For example, if the input is 1, 0, 3, 5, 2, 0, 1
// the output is 1, 0.5, 1, 2, 2, 1.5, 1.
// Design an algorithm for computing the running median of a sequence.

#include <algorithm>
#include <chrono>
#include <iostream>
#include <sstream>
#include <queue>

using namespace std;

using Time = chrono::time_point<chrono::steady_clock>;

inline auto GetTime() {
  return chrono::steady_clock::now();
}

inline auto GetElapsedTime(Time start, Time end) {
  return chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

// Solution #1
//   하나의 원소가 들어올 때마다 insertion sort를 사용하여 정렬한 후,
//   median을 구한다.
//   새로운 원소는 이미 정렬이 되어있는 원소들 사이에 끼워넣어지는데,
//   이 때의 insertion sort의 complexity는 O(N)이다.
//   (Partially sorted array를 insertion sorting하는데 드는 비용은 O(N)이다.)
//
// Time Complexity: O(N) per one element.
//
// Space Complexity: O(N) for the array of elements.

void InsertionSort(vector<int>* elems_ptr) {
  vector<int>& elems = *elems_ptr;
  for (int i = 1; i < elems.size(); ++i) {
    for (int j = i; j > 0; --j) {
      if (elems[j - 1] > elems[j]) {
        swap(elems[j - 1], elems[j]);
      } else {
        break;
      }
    }
  }
}

void FindOnlineMedian(istringstream* is) {
  vector<int> elems;
  int num;
  while (*is >> num) {
    elems.emplace_back(num);
    InsertionSort(&elems);

    if (elems.size() & 0x1) {
      cout << elems[elems.size() / 2] << " ";
    } else {
      int mid = elems.size() / 2;
      cout << (elems[mid - 1] + elems[mid]) * 0.5 << " ";
    }
  }
  cout << endl;
}

// Solution #2
//   max heap과 min heap, 두 개의 heap을 두어,
///  * max heap에 ceil(N/2) 개의 median 보다 작거나 같은 원소들을,
//   * min heap에 floor(N/2)개의 median 보다 큰 원소들을 저장한다.
//
//   새로운 원소가 들어오면,
//   * 원소가 max_heap.top() 보다 작거나 같으면 max_heap()에 저장한다.
//   * 그 외의 경우엔 min_heap()에 저장한다.
//
//   원소를 저장한 후 heap size를 re-balancing한다.
//   * max_heap.size() > min_heap.size() + 1 이면,
//     max_heap에서 최대 원소를 pop한 후 min_heap에 삽입한다.
//   * min_heap.size() < min_heap.size() 이면,
//     min_heap에서 최소 원소를 pop한 후 max_heap에 삽입한다.
//
//   Rebalancing이 끝난 후 median을 구하여 출력한다.
//   * max_heap.size() == min_heap.size() 이면 각 heap의 top 원소를 더한 후
//     2로 나눈 값을 반환한다.
//   * max_heap.size() > min_heap.size() 이면 max_heap의 top 원소를 반환한다.
//
// Time Complexity: O(logN) per one element.
//
// Space Complexity: O(N) for both min_heap and max_heap.

void FindOnlineMedian2(istringstream* is) {
  priority_queue<int, vector<int>, less<int>> max_heap;
  priority_queue<int, vector<int>, greater<int>> min_heap;

  int num;
  while (*is >> num) {
    if (max_heap.empty()) {
      max_heap.emplace(num);
    } else if (max_heap.top() >= num) {
      max_heap.emplace(num);
    } else {
      min_heap.emplace(num);
    }

    if (max_heap.size() > min_heap.size() + 1) {
      min_heap.emplace(max_heap.top());
      max_heap.pop();
    } else if (max_heap.size() < min_heap.size()) {
      max_heap.emplace(min_heap.top());
      min_heap.pop();
    }

    if (min_heap.size() == max_heap.size()) {
      cout << (max_heap.top() + min_heap.top()) * 0.5 << " ";
    } else {
      cout << max_heap.top() << " ";
    }
  }
  cout << endl;
}

int main() {
  istringstream is("1 0 3 5 2 0 1");
  FindOnlineMedian(&is);

  istringstream is2("1 0 3 5 2 0 1");
  FindOnlineMedian2(&is2);
  return 0;
}
