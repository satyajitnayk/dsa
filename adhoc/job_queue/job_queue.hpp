#pragma once

#include <atomic>
#include <condition_variable>
#include <functional>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>

class JobQueue {
public:
  using Job = std::function<void()>;

  JobQueue(size_t num_workers);
  ~JobQueue();

  void EnqueuJob(Job job);
  void Shutdown();

private:
  void WorkerLoop();

  std::queue<Job> jobs_;
  std::mutex mtx_;
  std::condition_variable cv_;
  std::vector<std::thread> workers_;
  std::atomic<bool> stop_;
};