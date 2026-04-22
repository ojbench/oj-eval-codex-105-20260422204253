#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m;
    if(!(cin >> n >> m)) return 0;
    if (m <= 0) {
        cout << fixed << setprecision(2) << 0.00 << "\n";
        return 0;
    }
    if (m > n) {
        cout << fixed << setprecision(2) << 0.00 << "\n";
        return 0;
    }

    long long R = n - m; // stop once remaining <= R (i.e., eaten >= m)
    int N = (int)n;
    vector<long double> E(N+1, 0.0L);
    vector<long double> S(N+1, 0.0L); // prefix sums of E

    for (int k = 0; k <= (int)min<long long>(R, N); ++k) {
        E[k] = 0.0L;
        S[k] = (k? S[k-1] : 0.0L) + E[k];
    }
    for (int k = (int)R + 1; k <= N; ++k) {
        long double prevSum = (k-1 >= 0 ? S[k-1] : 0.0L);
        E[k] = 1.0L + prevSum / (long double)k; // uniform over x in [1..k], j = k-x in [0..k-1]
        S[k] = S[k-1] + E[k];
    }

    long double ans = E[N];
    cout << fixed << setprecision(2) << (double)ans << "\n";
    return 0;
}
