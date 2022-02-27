#include <bits/stdc++.h> 
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

const int mod = 1e9 + 7;

int main()
{
    fast_cin();
    ll n, p;
    cin >> n >> p;
    v32 v;
    unordered_set<int> vset;
    for(int it=1;it<=n;it++) {
        int a;
        cin >> a;
        v.push_back(a);
        vset.insert(a);
    }
    sort(v.begin(), v.end());
    for (int x : v) {
        int i = x;
        bool rm = false;
        bool end = false;
        while (!(i == 0 || end)) {
            if (i % 4 == 0) {
                // x = 4y
                i = i >> 2;
                if (vset.find(i) != vset.end()) {
                    rm = true;
                }
            } else if (i % 4 == 1 || i % 4 == 3) {
                // x = 2y + 1
                i = i >> 1;
                if (vset.find(i) != vset.end()) {
                    rm = true;
                }
            } else {
                end = true;
            }
        }
        if (rm) {
            vset.erase(x);
        }
    }
    v.clear();
    v64 cnt(40, 0), dp(p);
    for (int i : vset) {
        cnt[__lg(i)]++;
    }
    long ans = 0;
    for (int i = 0; i < p; i++) {
        dp[i] += (long)(i > 0 ? dp[i-1] : 0);
        dp[i] += (long)(i > 1 ? dp[i-2] : 0);
        dp[i] += (long)(i > 39 ? 0 : cnt[i]);
        dp[i] = dp[i] % mod;
        ans += dp[i];
        ans = ans % mod;
    }
    cout << ans;
    return 0;
}