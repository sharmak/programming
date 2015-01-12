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

template <class T>
int  printMatrix(const vector< vector<T> >& outMatrix)  {
    cout << "=========================================" << endl;
    int i = 0;
    int j = 0;
    int  R = outMatrix.size();
    REP(i, R) {
        int C = outMatrix[i].size();
        REP(j, C) {
            cout << " " << outMatrix[i][j] ;
        }
        cout << endl;
    }
    cout << "=========================================" << endl;
}

int main() {
    int R, C;
    cin >> R;
    cin >> C;
    #ifdef DEBUG
        cout << R << "X" << C << endl;
    #endif
    int i = 0;
    int j = 0;
    vector< vector<char> > inputMatrix;
    REP(i, R) {
        char c;
        vector<char> row;
        REP (j, C) {
            cin >> c;
            row.push_back(c);
        }
        inputMatrix.PB(row);
    }
    vector < vector<int> > outMatrix;
    REP (i, R) {
        vector<int> row;
        row.assign(C, 0);
        outMatrix.push_back(row);
    }
    #ifdef DEBUG
        printMatrix(inputMatrix);
        printMatrix(outMatrix);
    #endif
    REP(i, R) {
        REP(j, C) {
            if (inputMatrix[i][j] ==  '*') {
                if (i < R-1)
                    outMatrix[i+1][j] += 1;
                if (i > 0)
                    outMatrix[i-1][j] += 1;
                if (j > 0)
                    outMatrix[i][j-1] += 1;
                if (j < C-1)
                    outMatrix[i][j+1] += 1;
                if (i > 0 && j > 0)
                    outMatrix[i-1][j-1] += 1;
                if (i < R-1 && j < C-1)
                    outMatrix[i+1][j+1] += 1;
                if (i > 0 && j < C-1)
                    outMatrix[i-1][j+1] += 1;
                if (i < R-1 && j > 0)
                    outMatrix[i+1][j-1] += 1;

            }
        }
    #ifdef DEBUG
        printMatrix(outMatrix);
    #endif
    }
    #ifdef DEBUG
        printMatrix(outMatrix);
    #endif
    REP(i, R) {
        int rowSize = outMatrix[i].size();
        REP(j, rowSize) {
            if (inputMatrix[i][j] == '*') {
                cout << " " << "*";
            } else {
                cout << " " << outMatrix[i][j];
            }
        }
        cout << endl;
    }

}
