// Problem: https://open.kattis.com/problems/basicprogramming2

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

bool binaryFind(vector<int>& A, int toFind) {

    int first = 0;
    int last = A.size() - 1;
    int mid;

    while (first < last) {
        mid = first + (last - first)/2;
        if (A[mid] == toFind) return true;
        if (A[mid] < toFind) {
            first = mid+1;
        } else {
            last = mid-1;
        }  
    }
    return false;
}

void case1(vector<int>& A) {

    sort(begin(A), end(A));
    for (int i = 0; i < A.size(); ++i) {
        if (A[i] > 7777) {
            cout << "No";
            return;
        }
        int toFind = 7777 - A[i];
        if (binaryFind(A, toFind)) {
            cout << "Yes";
            return;
        }
    }
}

void case2(vector<int>& A) {

    unordered_set<int> found;
    for (int i : A) {
        if (found.find(i) != found.end()) {
            cout << "Contains duplicate";
            return;
        }
        found.insert(i);
    }
    cout << "Unique";
}

void case3(vector<int>& A) {

    unordered_map<int, int> count;
    for (int i : A) {
        count[i] += 1;
        if (count[i] > A.size()/2) {
            cout << i;
            return;
        }
    }
    cout << -1;
}

void case4(vector<int>& A) {

    sort(begin(A), end(A));
    if (A.size() % 2 == 1) {
        cout << A[A.size()/2];
    } else {
        cout << A[A.size()/2 - 1] << ' ' << A[A.size()/2];
    }
}

void case5(vector<int>& A) {

    sort(begin(A), end(A));
    for (int i : A) {
        if (i >= 100 && i <= 999) cout << i << ' ';
    }
}

int main() {

    int N, t;
    cin >> N >> t;

    vector<int> A(N);

    for (int i = 0; i < N; ++i) cin >> A[i];
    
    if (t == 1)      case1(A);
    else if (t == 2) case2(A);
    else if (t == 3) case3(A);
    else if (t == 4) case4(A);
    else if (t == 5) case5(A);


}
