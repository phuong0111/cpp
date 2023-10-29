#include <math.h>

#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <set>
#include <utility>
#include <vector>
using namespace std;

typedef long long ll;
const int MAX = 5e6 + 5;
const int MOD = 1e9 + 7;


int main() {
    // freopen("inp.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    // B
    // int n, k;
    // cin >> n >> k;
    // // n =  12; k= 4;
    // string res = "";
    // bool check = true;
    // while (k > 0 && check)
    // {
    //     int i;
    //     for (int i = 9; i > 0; i--) {
    //         if (n%i == 0) {
    //             res = char(i + '0') + res;
    //             k--; 
    //             n /= i;
    //             break;
    //         }
    //     }
    //     if (i == 0) check = false;
    // }
    // check ? cout << res : cout << -1;

    // I
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    
    
    
    return 0;
}

