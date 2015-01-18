#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <set>
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


#include <boost/dynamic_bitset.hpp>
boost::dynamic_bitset<> bs(64, 2);

string jolly_jumper(const vector<int> & v) {
    int sizeBitSet = v.size() - 1;
    boost::dynamic_bitset<> bs(sizeBitSet, 0);
    for (int i=1; i < v.size(); i++) {
        int diff = abs(v[i] - v[i-1]);
        if (diff > sizeBitSet)
            return "not jolly";
        else
            bs.set(diff-1);
    }
    if (bs.count() != sizeBitSet)
        return "not jolly";
    return "jolly";

}

int main() {
    vector< vector<int> >  V;
    /*****************************************************
     * Read lines example
    ******************************************************
     string tmp;
    while(getline(std::cin, tmp)) {
        vector<int> nums;
        stringstream ss(tmp);
        int ti;
        while(ss >> ti) 
            nums.push_back(ti);
        V.push_back(nums);
    }
    ********************************************************/
    int n;
    while(cin >> n) {
        vector<int> data(n, 0);
        for (int i=0; i < n; i++)
            cin >> data[i];
        V.push_back(data);
    }

    for (int i=0; i < V.size(); i++) {
        cout << jolly_jumper(V[i]) << endl;
    }
    return 0;
}
