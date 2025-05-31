// Design a hit counter which counts the number of hits received in the past 5
// minutes

// hit(timestamp) – Shows a hit at the given timestamp.
// getHits(timestamp) – Returns the number of hits received in the past 5
// minutes (300 seconds) (from currentTimestamp) Each function accepts a
// timestamp parameter (in seconds granularity)
#include <iostream>
#include <queue>
using namespace std;

class HitCounter {
private:
  int hits[300] = {0};
  int times[300] = {0};

public:
  void hit(int timestamp) {
    int idx = timestamp % 300;
    if (times[idx] != timestamp) {
      times[idx] = timestamp;
      hits[idx] = 1;
    } else {
      hits[idx]++;
    }
  }

  int getHits(int timestamp) {
    int count = 0;
    for (int i = 0; i < 300; i++) {
      if (times[i] > timestamp - 300) {
        count += hits[i];
      }
    }
    return count;
  }
};

int main() {
  HitCounter counter = HitCounter();

  // hit at timestamp 1.
  counter.hit(1);

  // hit at timestamp 2.
  counter.hit(2);

  // hit at timestamp 3.
  counter.hit(3);

  // // get hits at timestamp 4, should return 3.
  cout << counter.getHits(4) << "\n";

  // hit at timestamp 300.
  counter.hit(300);

  // get hits at timestamp 300, should return 4.
  cout << counter.getHits(300) << "\n";

  // get hits at timestamp 301, should return 3.
  cout << counter.getHits(301) << "\n";

  return 0;
}
