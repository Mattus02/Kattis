// Problem: https://open.kattis.com/problems/froshweek

#include <iostream>
#include <vector>

using namespace std;

unsigned long long count = 0;
vector<int> students;

void MergeStep(int start_l, int end_l, int start_r, int end_r) {

    int curr_l = start_l;
    int curr_r = start_r;
    vector<int> temp;

    for (int i = start_l; i <= end_r; ++i) {
        if (curr_l <= end_l && (students[curr_l] < students[curr_r] || curr_r > end_r)) {
            count += curr_r - start_r;
            temp.push_back(students[curr_l]);
            curr_l += 1;
        } else {
            temp.push_back(students[curr_r]);
            curr_r += 1;
        }
    }

    for (int i = 0; i < temp.size(); ++i) {
        students[start_l + i] = temp[i];
    }
}

void MergeSort(int start, int end) {

    if (start == end) return;

    int mid = (start + end) / 2;
    MergeSort(start, mid);
    MergeSort(mid+1, end);
    MergeStep(start, mid, mid+1, end);
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    students = vector<int>(n);

    for (int i = 0; i < n; ++i) {
        cin >> students[i];
    }

    MergeSort(0, n-1);

    cout << count;
}