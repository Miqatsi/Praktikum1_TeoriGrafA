#include <bits/stdc++.h>
using namespace std;

void backtrackAll(int curr_idx, int target_len, const vector<int> &nums,
                  const vector<int> &length_at, vector<int> &current_path,
                  vector<vector<int>> &all_paths) {
    current_path.push_back(nums[curr_idx]);

    if (target_len == 1) {
        vector<int> full_path = current_path;
        reverse(full_path.begin(), full_path.end());
        all_paths.push_back(full_path);
    } else {
        for (int prev = curr_idx - 1; prev >= 0; --prev) {
            if (nums[prev] < nums[curr_idx] &&
                length_at[prev] == target_len - 1) {
                backtrackAll(prev, target_len - 1, nums, length_at,
                             current_path, all_paths);
            }
        }
    }

    current_path.pop_back();
}

vector<vector<int>> getAllLongestIncreasingSubsequencePaths(vector<int> &nums) {
    int n = nums.size();
    if (n == 0)
        return {};

    vector<int> tails;
    vector<int> length_at(n, 1);

    for (int k = 0; k < n; ++k) {
        int x = nums[k];
        int l = 0, r = tails.size();
        while (l < r) {
            int m = (l + r) / 2;
            if (tails[m] < x)
                l = m + 1;
            else
                r = m;
        }

        if (l == tails.size()) {
            tails.push_back(x);
        } else {
            tails[l] = x;
        }

        length_at[k] = l + 1;
    }

    int max_len = tails.size();

    vector<vector<int>> all_paths;
    vector<int> current_path;

    // Bracktacking to check
    for (int i = 0; i < n; ++i) {
        if (length_at[i] == max_len) {
            backtrackAll(i, max_len, nums, length_at, current_path, all_paths);
        }
    }

    return all_paths;
}

int main() {
    cout << "Longest monotonically increasing sequence\n";
    cout << "===========================================\n";
    cout << "Input your array : ";
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> a;
    int num;
    while (ss >> num)
        a.push_back(num);
    auto res = getAllLongestIncreasingSubsequencePaths(a);
    for (auto x : res) {
        for (auto z : x) {
            cout << z << " ";
        }
        cout << "\n";
    }
}
