// Problem: https://open.kattis.com/problems/guessthedatastructure

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int ops;
    while(cin >> ops)
    {
        bool cbs = true, cbq = true, cbpq = true;
        stack<int> s;
        queue<int> q;
        priority_queue<int> pq;
        while(ops--)
        {
            int type, val;
            cin >> type >> val;
            if(type == 1){
                s.push(val);
                q.push(val);
                pq.push(val);
            }
            else{
                if(s.empty()){
                    cbs = cbq = cbpq = false;
                    while(ops--){
                        cin >> type >> val;
                    }
                    break;
                }
                if(s.top() != val)
                    cbs = false;
                if(q.front() != val)
                    cbq = false;
                if(pq.top() != val)
                    cbpq = false;
                s.pop();
                q.pop();
                pq.pop();
            }
        }
        if((cbs and cbq) or (cbs and cbpq) or (cbq and cbpq)){
            printf("not sure\n");
        }
        else if(cbs){
            printf("stack\n");
        }
        else if(cbq){
            printf("queue\n");
        }
        else if(cbpq){
            printf("priority queue\n");
        }
        else{
            printf("impossible\n");
        }
    }
}
