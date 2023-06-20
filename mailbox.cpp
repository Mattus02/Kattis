// Problem: https://open.kattis.com/problems/mailbox

#include <stdio.h>
#include <algorithm>

#define BIG 9999

int mem[11][101][101];

int rec(int boxes, int start, int end)
{
    if (start == end)
        return 0;
   
    if (mem[boxes][start][end] == 0) { 
        if (boxes == 1) {
            int val = (end*(end+1)/2) - (start*(start+1)/2);
            mem[boxes][start][end] = val;
            return val; 
        }
        int curr = BIG;
        for (int i = start+1; i <= end; ++i) {
            curr = std::min(curr, i+std::max(rec(boxes-1, start, i-1), rec(boxes, i, end)));
        }
        mem[boxes][start][end] = curr;
    }
    return mem[boxes][start][end];
}

int main()
{
    int tests;
    scanf("%d", &tests);

    while (tests--)
    {
        int boxes, crackers;
        scanf("%d %d", &boxes, &crackers);
        printf("%d\n", rec(boxes, 0, crackers));
    }
}

