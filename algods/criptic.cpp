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

string makeMappingString(string s) {
    map<char, char> charMap;
    char startChar = 'a';
    string out = "";
    for (auto j=0; j < s.length(); ++j) {
        map<char, char>::iterator it = charMap.find(s[j]);
        if (it != charMap.end()) {
            out.push_back(charMap[s[j]]);
        } else {
            charMap[s[j]] = startChar;
            out.push_back(startChar);
            startChar += 1;
        }
    }
    return out;
}

map<string, vector<string> > createMapForDict(set<string> s) {
    map<string, vector<string> > M;
    for (auto i = s.begin(); i != s.end(); ++i) {
        string s_ =  *i;
        string out = makeMappingString(s_);
        M[out].push_back(s_);
    }
    return M;
}

map<string, vector<string> > createMapFromInput(set<string> s,
                                                const map<string, vector<string> > &  M) {
    map<string, vector<string> > out;
    for (auto i=s.begin(); i != s.end(); ++i) {
        string mapString = makeMappingString(*i);
        out[*i] = M.at(mapString);
    }
    return out;
}

int main() {
    set<string> S = {"and", "dict", "jane", "puff", "spot", "yertle"};
    map<string, vector<string> > dictM;
    dictM = createMapForDict(S);
    set<string> I = {"bjvg", "xsb", "hxsn", "xsb", "qymm", "xsb", "rqat", "xsb", "pnetfn"};
    map<string, vector<string> > inputMap;
    inputMap = createMapFromInput(I, dictM);
    for(auto it = inputMap.begin(); it != inputMap.end(); ++it) {
        vector<string> v = it->second;
        vector<string>::iterator vecit;
        cout << it->first << " => ";
        for(vecit = v.begin(); vecit != v.end(); ++vecit) {
            cout << *vecit << " " ;
        }
        cout << endl;
    }
  
}
