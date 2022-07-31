You are given a rectangular cake of size h x w and two arrays of integers horizontalCuts 
and verticalCuts where:
horizontalCuts[i] is the distance from the top of the rectangular cake to the ith 
horizontal cut and similarly, and verticalCuts[j] is the distance from the left of the rectangular
 cake to the jth vertical cut.
Return the maximum area of a piece of cake after you cut at each horizontal and vertical position
provided in the arrays horizontalCuts and verticalCuts. Since the answer can be a large number,
return this modulo 109 + 7.

Approach: Optimal

1. Sort the arrays, then compute the maximum difference between two consecutive elements 
for horizontal cuts and vertical cuts.
2. The answer is the product of these maximum values in horizontal cuts and vertical cuts.

CODE:
int maxArea(int h, int w, vector<int>& H, vector<int>& V) {
    int x = 1000000007;
    sort(H.begin(), H.end());
    sort(V.begin(), V.end());
    int l=0,r=0;
    for(int i=0;i<H.size()-1;++i) {
        l = max(l,H[i+1]-H[i]);
    }
    l = max(l,H[0]);
    l = max(l,h-H[H.size()-1]);
    for(int i=0;i<V.size()-1;++i) {
        r = max(r,V[i+1]-V[i]);
    }
    r = max(r,V[0]);
    r = max(r,w-V[V.size()-1])
    return ((long)l*r)%x;
}

=>Time O(hlogh)+O(wlogw) & space O(h) O(w)