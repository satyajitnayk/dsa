You are given a list of songs where the ith song has a duration of time[i] seconds.

Return the number of pairs of songs for which their total duration in seconds is divisible by 60.
Formally, we want the number of indices i, j such that i < j with (time[i] + time[j]) % 60 == 0.

Solution:
Approach 1: BruteForce 
Time O(n^2) & space O(1)

Approach2 : Optimal
Time O(n) & space O(1)

*Notes:
1.We only need to consider each song length modulo 60. r = time[i] % 60
2.We can count the number of songs with (length % 60) equal to r, 
  and store that in an array of size 60.

##CODE:

int numPairsDivisibleBy60(vector<int>& time) {
    int count = 0;
    int n = time.size();
    int m[61] = {0};
    for(int i=0; i < n; ++i) {
        time[i] %= 60;
        m[time[i]]++;
    }
    for(int i=0; i < n; ++i) {
        cout << count << " ";
        m[time[i]]--;
        int target = (60 - time[i])%60;
        if(m[target] > 0) {
            count+= m[target];
        }
    }
    return count;
}