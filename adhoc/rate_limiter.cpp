#include <chrono>
#include <iostream>
#include <memory>
#include <mutex>
#include <thread>
#include <vector>

using namespace std;

// A rate limiter restricts the number of actions (e.g., API calls, requests) a
// client can perform in a given time window.

// Example Use Cases:
// API usage (e.g., 1000 requests per minute)
// Login attempts (e.g., max 5 tries every 10 minutes)
// Message sending rate

// The Token Bucket is a flexible and commonly used algorithm for rate limiting.
// - Imagine a bucket that can hold up to N tokens.
// - Tokens are added at a fixed rate (e.g., 1 token per second).
// - When a request comes in:
//    - If there’s a token, you take one and proceed.
//    - If the bucket is empty, you reject the request or delay it.

class TokenBucket {
private:
  double tokens;
  const double maxTokens;
  const double refillRate;
  chrono::steady_clock::time_point lastRefillTime;
  mutex mtx;

public:
  TokenBucket(double maxTokens, double refillRate)
      : tokens(maxTokens), maxTokens(maxTokens), refillRate(refillRate) {
    lastRefillTime = chrono::steady_clock::now();
  }

  bool allowRequest() {
    lock_guard<mutex> lock(mtx);

    auto now = chrono::steady_clock::now();
    chrono::duration<double> elapsed = now - lastRefillTime;

    double tokensToAdd = elapsed.count() * refillRate;
    if (tokensToAdd > 0) {
      tokens = min(maxTokens, tokens + tokensToAdd);
      lastRefillTime = now;
    }

    if (tokens >= 1.0) {
      tokens -= 1.0;
      return true;
    } else {
      return false;
    }
  }
};

// Simulate client threads trying to make requests
void simulateClient(TokenBucket &bucket, int clientId) {
  for (int i = 0; i < 10; ++i) {
    if (bucket.allowRequest()) {
      cout << "Client " << clientId << ": Request allowed\n";
    } else {
      cout << "Client " << clientId << ": Request denied\n";
    }
    this_thread::sleep_for(chrono::milliseconds(100));
  }
}

int main() {
  TokenBucket limiter(5, 1.0); // 5 tokens max, 1 token/sec

  vector<thread> threads;

  // Launch 5 client threads
  for (int i = 0; i < 5; ++i) {
    threads.emplace_back(simulateClient, ref(limiter), i);
  }

  for (auto &t : threads) {
    t.join();
  }

  return 0;
}
