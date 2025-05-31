#include "job_queue.hpp"
#include <chrono>
#include <iostream>
#include <thread>

// g++ -std=c++17 -pthread main.cpp job_queue.cpp -o job_queue
int main() {
  JobQueue queue(4);

  for (int i = 1; i <= 10; i++) {
    queue.EnqueuJob([i] {
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
      std::cout << "Processing job #" << i << " in thread "
                << std::this_thread::get_id() << "\n";
    });
  }

  std::this_thread::sleep_for(std::chrono::seconds(2));
  std::cout << "Shutting down...\n";
  queue.Shutdown();

  return 0;
}