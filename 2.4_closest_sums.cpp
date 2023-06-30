// Problem: https://open.kattis.com/problems/closestsums

#include <bits/stdc++.h>

using namespace std;

int bin_search(vector<int>& nums, int start, int target)
{
    start += 1;
    int end = nums.size()-1;
    int diff = INT_MAX;
    while(start <= end){
        int mid = (start+end)/2;
        if(nums[mid] == target){
            return 0;
        }
        if(abs(diff) > abs(nums[mid]-target)){
            diff = nums[mid]-target;
        }
        if(nums[mid] > target){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return diff;
}

int closest_sum(vector<int>& nums, int q)
{
    int diff = nums[0]+nums[1]-q;
    for(int i = 0; i < nums.size()-1; ++i){
        if(nums[i] > q){
            break;
        }
        int target = q-nums[i];
        int tmp_diff = bin_search(nums, i, target);
        if(abs(diff) > abs(tmp_diff)){
            diff = tmp_diff;
        }
    }
    return q+diff;
}

int main()
{
    int n;
    int c = 1;
    while(cin >> n)
    {
        vector<int> nums(n);
        for(int i = 0; i < n; ++i){
            cin >> nums[i];
        }
        sort(nums.begin(), nums.end());
        int m,q;
        cin >> m;
        printf("Case %d:\n", c);
        while(m--){
            cin >> q;
            printf("Closest sum to %d is %d.\n", q, closest_sum(nums, q));
        }
        ++c;
    }
}
