/*
ID: xpthptc2
TASK: gift1
LANG: C++
*/

#include <iostream>
#include <map>
using namespace std;

#define MAXPEOPLE 10

int npeople;
string names[MAXPEOPLE];
int totals[MAXPEOPLE];

int lookup(string name) {
    for (int i = 0; i < npeople; i++) {
        if (name == names[i]) {
            return i;
        }
    }
}

int main() {
    int giver, receiver;
    freopen("gift1.out", "w", stdout);
    freopen("gift1.in", "r", stdin);
    
    int np;
    cin >> np;
    for (int i = 0; i < np; i++) {
        cin >> names[npeople++];
    }
    for (int i = 0; i < np; i++) {
        int amt, ng;
        string name;
        cin >> name >> amt >> ng;
        giver = lookup(name);
        for (int j = 0; j < ng; j++) {
            cin >> name;
            receiver = lookup(name);
            totals[giver] -= amt / ng;
            totals[receiver] += amt / ng;
        }
    }
    for (int i = 0; i < np; i++) {
        cout << names[i] << " " << totals[i] << endl;
    }
    exit(0);
}
// password: sae35gv;
