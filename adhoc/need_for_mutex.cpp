#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

using namespace std;

mutex mtx;

int counter = 0; // Shared resource

void increment(int times) {
  lock_guard<mutex> lock(mtx);
  for (int i = 0; i < times; ++i) {
    ++counter;
  }
}

// Issue with out mutex: Each thread tries to increment counter 100000 times.
//  Since all threads share the same counter, they interleave and often
//  overwrite each other’s increments. The result is less than expected.

int main() {
  const int num_threads = 10;
  const int increments_per_thread = 100000;

  vector<thread> threads;

  // Launch multiple threads
  for (int i = 0; i < num_threads; ++i) {
    threads.emplace_back(increment, increments_per_thread);
  }

  // Join all threads
  for (auto &t : threads) {
    t.join();
  }

  cout << "Expected counter value: " << num_threads * increments_per_thread
       << "\n";
  cout << "Actual counter value:   " << counter << "\n";

  return 0;
}
