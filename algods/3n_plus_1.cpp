#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <set>
using namespace std;

//#define DEBUG
#define REP(i,a) for(i=0;i<a;i++)
#define FOR(i,a,b) for(i=a;i<b;i++)
#define VE vector<int>
#define SZ size()
#define PB push_back

// Memoize the result of recursive to avoid 
// recomputing the data again if it is already computed.
map<int, int> M;


// Function to find cycle length (with memoization)
int findCycleLengthRecusrive(int val) {
    if (val == 1)
        return 1;
    else {
        int cycleLength = 1;
        if (val % 2 == 0) 
            cycleLength += findCycleLengthRecusrive(val / 2);
        else
            cycleLength += findCycleLengthRecusrive(val * 3 + 1);

        // Remember the cycle length
        M[val] = cycleLength;
        return cycleLength;
    }
}

// Regualar function to find cycle length
int findCycleLength (int val) {
    int cycleLength = 1;
    while (val != 1) {
        cycleLength++;
        if (val % 2 == 0) {
            val /= 2;
        } else {
            val = val *3 + 1;
        }
    }
    return cycleLength;
}

int  three_n_plus_one_problem(int i, int j) {
    int curr = i;
    int maxCycleLength = 1;
    while (curr <= j) {
        int cycleLength;
        if (M.find(curr) == M.end()) {
            cycleLength = findCycleLengthRecusrive(curr);
        } else {
            #ifdef DEBUG
            std::cout << "Already solved " << curr << std::endl;
            #endif
            cycleLength = M[curr];
        }
        //int cycleLength = findCycleLengthRecusrive(curr);
        if (cycleLength > maxCycleLength)
            maxCycleLength = cycleLength;
        ++curr;
    }
    #ifdef DEBUG
    std::cout << maxCycleLength << std::endl;
    for (auto& kv : M) {
       std::cout << kv.first << " " << kv.second << std::endl;
    }
    #endif
    return maxCycleLength;
}

int main()  {
    int i,j;
    cin >>  i >> j;
    int out = three_n_plus_one_problem(i,j);
    cout << i << " " << j << " " << out << std::endl;

    cin >>  i >> j;
    out = three_n_plus_one_problem(i,j);
    cout << i << " " << j << " " << out << std::endl;

    cin >>  i >> j;
    out = three_n_plus_one_problem(i,j);
    cout << i << " " << j << " " << out << std::endl;

    cin >>  i >> j;
    out = three_n_plus_one_problem(i,j);
    cout << i << " " << j << " " << out << std::endl;

    return 0;
}
