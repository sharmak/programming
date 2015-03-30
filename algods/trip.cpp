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

#define REP(i,a) for(i=0;i<a;i++)
#define FOR(i,a,b) for(i=a;i<b;i++)
#define VE vector<int>
#define SZ size()
#define PB push_back

int main() {
    int  people;
    cin >> people;
    vector<float> expenditure;
    int i;
    REP(i, people) {
        float value;
        cin >> value;
        expenditure.push_back(value);
    }
    std::sort(expenditure.begin(), expenditure.end());
    #ifdef DEBUG
    REP(i, people) {
        cout << expenditure[i] << endl;
    }
    #endif
    float average_exp = accumulate(expenditure.begin(), 
                                   expenditure.end(), 0.0) 
                                / expenditure.size();
    #ifdef DEBUG
    cout << average_exp << endl;
    #endif
    int end = people - 1;
    int start = 0;
    float money_movement = 0.0;
    while (start < end) {
        #ifdef DEBUG
        cout << "Start = " << start << endl;
        cout << "End   = " << end << endl;
        #endif
        float less_paid_by_start = average_exp - expenditure[start];
        float more_paid_by_end  =  expenditure[end] - average_exp;
        #ifdef DEBUG
        cout << "Less paid by " << start <<  " " << less_paid_by_start << endl;
        cout << "More paid by " << end <<  " " << more_paid_by_end << endl;
        #endif
        if (more_paid_by_end > less_paid_by_start) {
            expenditure[start] += less_paid_by_start;
            expenditure[end] -= less_paid_by_start;
            start = start + 1;
            money_movement += less_paid_by_start;
        } else if (less_paid_by_start > more_paid_by_end) {
            expenditure[start] += more_paid_by_end;
            expenditure[end]   -= more_paid_by_end;
            end = end - 1;
            money_movement += more_paid_by_end;
        } else {
            expenditure[start] += more_paid_by_end;
            expenditure[end]   -= more_paid_by_end;
            start = start + 1;
            end = end - 1;
            money_movement += more_paid_by_end;
        }
    }
    #ifdef DEBUG
    REP(i, people) {
        cout << expenditure[i] << endl;
    }
    #endif
    cout << "Money movement " << money_movement << endl;
    return 0;
}
