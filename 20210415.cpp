#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string input[2];
    cin >> input[0];
    cin >> input[1];

    int dp[input[0].length() + 1][input[1].length() + 1];
    for (int i = 0; i <= input[0].length(); i++) {
        dp[i][0] = i;
    }
    for (int i = 0; i <= input[1].length(); i++) {
        dp[0][i] = i;
    }

    for (int i = 1; i <= input[0].length(); i++) {
        for (int j = 1; j <= input[1].length(); j++) {
            if (input[0][i - 1] == input[1][j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]);
                dp[i][j] = min(dp[i][j], dp[i][j - 1]);
                dp[i][j] += 1;
            }
        }
    }

    cout << dp[input[0].length()][input[1].length()] << endl;
}
