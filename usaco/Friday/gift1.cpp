/*
ID: xpthptc2
TASK: friday
LANG: C++
*/

#include <iostream>
using namespace std;

int days_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int cnt[7] = {0, 0, 0, 0, 0, 0, 0};

int main() {
    freopen("friday.out", "w", stdout);
    freopen("friday.in", "r", stdin);

    int n; cin >> n;
    int init_day = 0;
    // init_day += 12; 
    for(int i = 0; i < n; i++) {
        int curr_year = 1900 + i;
        for(int j = 0; j < 12; j++) {
            cnt[(init_day % 7)]++;
            int leap = (j == 1 and curr_year % 4 == 0 and (curr_year % 100 != 0 or curr_year % 400 == 0));
            init_day += (days_in_month[j] + leap);
        }
    }

    for (int i = 0; i < 6; i++) cout << cnt[i] << " ";
    cout << cnt[6] << "\n";
    return 0;
}