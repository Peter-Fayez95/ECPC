#include<bits/stdc++.h>
using namespace std;


int succ[1005];

//detect cycle in functional graphs
//graph is represented as successor array
void floyd() {
    // let s be graph start (indegree = 0)
    int s;
    int a = succ[s];
    int b = succ[a];

    // move a once, b twice
    while(a != b) {
        a = succ[a];
        b = succ[succ[b]];
    }

    a = s;
    while(a != b) {
        a = succ[a];
        b = succ[b];
    }
    // first cycle node = a
    int fir = a;

    // calculate cycle length
    b = succ[a];
    int len = 1; 
    while(a != b) {
        b = succ[b];
        len++;
    }
}