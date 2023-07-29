// Problem: https://open.kattis.com/problems/basicprogramming1

#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long u64;

void case7(vector<int>& A, int N) {

    int idx = 0;

    for (;;) {

        if (idx >= N) {
            cout << "Out";
            return;
        } else if (idx == N-1) {
            cout << "Done";
            return;
        } else if (A[idx] == -1) {
            cout << "Cyclic";
            return;
        }

        int old_idx = idx;
        idx = A[idx];
        A[old_idx] = -1;
    }  
}

int main() {

    int N, t;
    cin >> N >> t;

    vector<int> A(N);
    
    for (int i = 0; i < N; ++i) cin >> A[i];

    switch (t) {

        case 1:
            cout << 7 << endl;
            return 0;
        case 2:
            if (A[0] > A[1]) cout << "Bigger" << endl;
            else if (A[0] == A[1]) cout << "Equal" << endl;
            else cout << "Smaller" << endl;
            return 0;
        case 3:
            if (A[0] > A[1]) swap(A[0], A[1]);
            if (A[1] > A[2]) swap(A[1], A[2]);
            if (A[0] > A[1]) swap(A[0], A[1]);
            cout << A[1] << endl;
            return 0;
        case 4: {
            u64 sum = 0;
            for (int i : A) sum += i;
            cout << sum << endl;
            return 0;
        }
        case 5: {
            u64 sum = 0;
            for (int i : A) if (i % 2 == 0) sum += i;
            cout << sum << endl;
            return 0;
        }
        case 6:
            for (int i : A) cout << (char)((i % 26) + 97);
            return 0;
        case 7:
            case7(A, N);
            return 0;
    }
}