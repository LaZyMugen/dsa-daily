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

long long dealCost(int x) {
    // cost for one deal of size 3^x
    // cost(x) = 3^(x+1) + x * 3^(x-1)
    long long p = 1;
    for (int i = 0; i < x; i++) p *= 3;
    long long cost = p * 3 + (x == 0 ? 0 : (long long)x * (p / 3));
    return cost;
}

void solve() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;

        // step 1: convert to base-3
        vector<int> digits;
        long long tmp = n;
        while (tmp > 0) {
            digits.push_back(tmp % 3);
            tmp /= 3;
        }

        // step 2: ensure each digit <= 1 (carry when needed)
        // this simulates upgrading deals
        for (int i = 0; i < (int)digits.size(); i++) {
            if (digits[i] >= 2) {
                int carry = digits[i] / 2;  // push excess upward
                digits[i] = digits[i] % 2;
                if (i + 1 == digits.size()) digits.push_back(0);
                digits[i + 1] += carry;
            }
        }

        // step 3: compute total cost
        long long ans = 0;
        for (int i = 0; i < (int)digits.size(); i++) {
            if (digits[i]) ans += dealCost(i);
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
