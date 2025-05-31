// Worker Threads that process jobs from a shared Job Queue.
// Jobs are submitted to the queue from the main thread.
// Worker threads wait for jobs, process them, and exit cleanly when told to
// stop.
#include "job_queue.hpp"
#include <iostream>

JobQueue::JobQueue(size_t num_workers) : stop_(false) {
  for (size_t i = 0; i < num_workers; ++i) {
    workers_.emplace_back(&JobQueue::WorkerLoop, this);
  }
}

void JobQueue::EnqueuJob(Job job) {
  {
    std::lock_guard<std::mutex> lock(mtx_);
    jobs_.push(std::move(job));
  }
  cv_.notify_one();
}

void JobQueue::WorkerLoop() {
  while (true) {
    Job job;
    {
      std::unique_lock<std::mutex> lock(mtx_);
      cv_.wait(lock, [this] { return stop_ || !jobs_.empty(); });

      if (stop_ && jobs_.empty())
        return;

      job = std::move(jobs_.front());
      jobs_.pop();
    }

    job();
  }
}

void JobQueue::Shutdown() {
  {
    std::lock_guard<std::mutex> lock(mtx_);
    stop_ = true;
  }
  cv_.notify_all();
  for (auto &worker : workers_) {
    if (worker.joinable())
      worker.join();
  }
}

JobQueue::~JobQueue() { Shutdown(); }