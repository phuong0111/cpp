/*
ID: xpthptc2
TASK: milk2
LANG: C++
*/

#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

pair<int, int> time_interval[5000];
int main() {
    freopen("milk2.out", "w", stdout);
    freopen("milk2.in", "r", stdin);

    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> time_interval[i].first >> time_interval[i].second;
    sort(time_interval, time_interval + n);

    int lower = time_interval[0].first;
    int upper = time_interval[0].second;
    int max_continous_interval_time = upper - lower;
    int max_discontinuous_interval_time = 0;
    for (int i = 0; i < n; i++) {
        if (time_interval[i].first <= upper) upper = max(upper, time_interval[i].second);
        else {
            max_discontinuous_interval_time = max(max_discontinuous_interval_time, time_interval[i].first - upper);
            max_continous_interval_time = max(max_continous_interval_time, upper - lower);
            lower = time_interval[i].first;
            upper = time_interval[i].second;
        }
    }
    cout << max_continous_interval_time << " " << max_discontinuous_interval_time << "\n";
}