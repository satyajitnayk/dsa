Design an algorithm that collects daily price quotes for some stock and returns
the span of that stock"'"s price for the current day.

The span of the stock"'"s price today is defined as the maximum number of consecutive 
days (starting from today and going backward) for which the stock price was less than or equal to today"'"s price.

For example, if the price of a stock over the next 7 days were [100,80,60,70,60,75,85],
then the stock spans would be [1,1,1,2,1,4,6]

Approach 1: BF

=> Time O(n^2) & space O(1) // neglecting space to return ans

vector<int> ans(n,0);
for(int i=0;i<n;++i){
  int cnt = 1;
  for(int j=i;j>=0;j--){
    if(A[j] <= A[i]) cnt++;
    else break;
  }
  ans[i] = cnt;
}

Approach 2: Optimized -> Using stack

       0   1  2   3  4  5  6
A    [100,80,60,70,60,75,85]
                |
                | Store index of next greater to left
                |
X    [-1, 0,  1,  1, 3, 1, 0]
                |
                |  i-X[i] , with exception for any X[i] = -1 =>X[i] = 1 (No smaller found to left)
                |
     [1, 1,  1, 2,  1, 4, 
     
=> O(n) time & O(1) space 

stack<pair<int,int>> s;
vector<int> ngl(n,0);
for(int i=0;i<n;++i) {
  auto [index, value] = s.top();
  if(s.size()==0) ngl.push_back(-1);
  else if(value > A[i]) ngl.push_back(index);
  else if(s.size() > 0 && value <= A[i]) {
    while(s.size() > 0 && s.top().second <= A[i]) s.pop();
    if(s.size() == 0) ngl.push_back(-1);
    else ngl.push_back(s.top().first);
  }
  s.push({i,A[i]});
}