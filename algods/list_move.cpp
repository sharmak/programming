
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <deque>
#include <sstream>
#include <bitset>
using namespace std;

//#define DEBUG
#define REP(i,a) for(i=0;i<a;i++)
#define FOR(i,a,b) for(i=a;i<b;i++)
#define VE vector<int>
#define SZ size()
#define PB push_back

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())

void printQueue(deque<int> first) {
     for (auto it = first.cbegin(); it != first.cend(); ++it)
        cout << ' ' << *it;
     cout << endl;
}
int solve(string  first, string temp, string  second, int n) {
    if (n == 1) {
        cout << "Move " << first  << " element " << "to "  <<  second << " end " << endl;
        int val = first.back();
        first.pop_back();
        second.push_back(val);
    } else {
        solve(first, second, temp, n-1);
        cout << "Move "  << " element from " << first  << " to " << second << endl;
        solve(temp, second, first, n-1);
    }
}

int main() {
    solve("F", "T", "S", 3);

}
