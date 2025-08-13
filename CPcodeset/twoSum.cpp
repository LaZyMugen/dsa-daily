#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    unordered_map<int, int> mp; // value -> index
    for (int i = 0; i < n; i++) {
        int complement = target - nums[i];
        if (mp.count(complement)) {
            cout << mp[complement] << " " << i << "\n";
            return 0;
        }
        mp[nums[i]] = i;
    }
    cout << "No solution\n";
    return 0;
}
