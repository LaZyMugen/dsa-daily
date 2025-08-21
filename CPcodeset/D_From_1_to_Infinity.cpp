#include "bits/stdc++.h"
#define int long long
#define uint unsigned long long
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define fr(i,n) for(int i=0; i<(n); i++)
#define rep(i,a,n) for(int i=(a); i<=(n); i++)
#define nl cout<<"\n"
#define dbg(var) cout<<#var<<"="<<var<<" "
#define all(v) v.begin(),v.end()
#define sz(v) (int)(v.size())
#define srt(v)  sort(v.begin(),v.end())         // sort 
#define mxe(v)  *max_element(v.begin(),v.end())     // find max element in vector
#define mne(v)  *min_element(v.begin(),v.end())     // find min element in vector
#define unq(v)  v.resize(distance(v.begin(), unique(v.begin(), v.end())));
// make sure to sort before applying unique // else only consecutive duplicates would be removed 
#define bin(x,y)  bitset<y>(x) 
using namespace std;
int MOD=1e9+7;      // Hardcoded, directly change from here for functions!



void modadd(int &a , int b) {a=((a%MOD)+(b%MOD))%MOD;}
void modsub(int &a , int b) {a=((a%MOD)-(b%MOD)+MOD)%MOD;}
void modmul(int &a , int b) {a=((a%MOD)*(b%MOD))%MOD;}
// ================================== take ip/op like vector,pairs directly!==================================
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
// ===================================END Of the input module ==========================================

#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
using i128 = __int128_t;

// function to compute sum of digits from 1 to n
long long digitSum(long long n) {
    if (n < 0) return 0;
    if (n == 0) return 0;
    long long res = 0;
    long long factor = 1;
    while (factor <= n) {
        long long lower = n % factor;
        long long cur = (n / factor) % 10;
        long long higher = n / (factor * 10);

        res += higher * 45 * factor;
        res += cur * (cur - 1) / 2 * factor;
        res += cur * (lower + 1);

        factor *= 10;
    }
    return res;
}

void solve() {
    int t;
    cin >> t;
    while (t--) {
        long long k;
        cin >> k;

        long long ans = 0;
        long long start = 1;
        int d = 1;

        while (true) {
            long long cnt = 9 * start;       // numbers with d digits
            long long blockDigits = cnt * d; // total digits in this block
            if (k > blockDigits) {
                // take whole block
                long long L = start;
                long long R = start * 10 - 1;
                ans += digitSum(R) - digitSum(L - 1);
                k -= blockDigits;
                start *= 10;
                d++;
            } else {
                // we are inside this block
                long long fullNums = k / d;
                long long extraDigits = k % d;
                long long L = start;
                long long R = start + fullNums - 1;
                if (fullNums > 0)
                    ans += digitSum(R) - digitSum(L - 1);
                if (extraDigits > 0) {
                    string s = to_string(start + fullNums);
                    for (int i = 0; i < extraDigits; i++)
                        ans += s[i] - '0';
                }
                break;
            }
        }

        cout << ans << "\n";
    }
}


int32_t main()
{
 
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
 solve();
    return 0;
}
