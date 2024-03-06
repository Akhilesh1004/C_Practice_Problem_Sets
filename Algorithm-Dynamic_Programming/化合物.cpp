#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int countCompounds(string str) {
    int n = str.size();
    vector<long long> dp1(n + 1, 0);
    vector<long long> dp2(n + 1, 0);

    // 初始化
    dp1[0] = 1;
    dp2[0] = 1;

    // 遍歷字串
    for (int i = 0; i < n; i++) {
        if (str[i] == 'A') {
            dp1[i + 1] = (dp1[i] + dp2[i]) % MOD;
            dp2[i + 1] = dp2[i];
        } else {
            dp1[i + 1] = dp1[i];
            dp2[i + 1] = (dp1[i] + dp2[i]) % MOD;
        }
    }

    return (dp1[n] + dp2[n]) % MOD -2;
}

int main() {
    string str;
    cin >> str;
    cout << countCompounds(str) << endl;
    return 0;
}

/*#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int countCompounds(string str) {
    int n = str.size();
    //init
    vector<long long> dp1(n + 1, 0);
    vector<long long> dp2(n + 1, 0);

    // travel
    for (int i = 0; i < n; i++) {
        if (str[i] == 'A') {
            dp1[i + 1] = (dp1[i] + dp2[i] + 1) % MOD;
            dp2[i + 1] = dp2[i];
        } else {
            dp1[i + 1] = dp1[i];
            dp2[i + 1] = (dp1[i] + dp2[i] + 1) % MOD;
        }
    }

    return (dp1[n] + dp2[n]) % MOD;
}

int main() {
    string str;
    cin >> str;
    cout << countCompounds(str) << endl;
    return 0;
}
*/