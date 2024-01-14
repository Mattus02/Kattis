// Problem: https://open.kattis.com/problems/ballotboxes

#include <iostream>
#include <queue>

using namespace std;

struct City {
    int population;
    int ballots;
};

bool operator<(City a, City b) {
    return (double)a.population / a.ballots < (double)b.population / b.ballots;
}

int main() {
    int N, B;
    while (cin >> N >> B && N != -1) {
        priority_queue<City> pq;
        int pop;
        while (N--) {
            cin >> pop;
            pq.push({pop, 1});
            B--;
        }
        while (B--) {
            City curr = pq.top();
            pq.pop();
            curr.ballots++;
            pq.push(curr);
        }
        int compensation = pq.top().population % pq.top().ballots != 0 ? 1 : 0;
        cout << (pq.top().population / pq.top().ballots) + compensation << endl;
    }
}