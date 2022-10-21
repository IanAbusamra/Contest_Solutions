class Solution {
    const int mod = 1e9 + 7;
public:
    int countTexts(string pressedKeys) {
        long long ans = 1;
        int n = pressedKeys.length();
        for(long long i = 0; i < n; i++) {
            char cc = pressedKeys[i];
            long long start = i;
            while(i + 1 < n && pressedKeys[i+1] == cc) {
                i++;
            }
            if(cc == '1') continue;
            if(cc == '7' || cc == '9') {
                long long l = i - start + 1;
                vector<long long> dp(l + 1);
                dp[0] = 1;
                for(int z = 1; z <= l; z++) {
                    for(int sb = 1; sb <= 4; sb++) {
                        if(z - sb >= 0) dp[z] += dp[z - sb];
                        dp[z] %= mod;
                    }
                    dp[z] %= mod;
                }
                ans *= dp[l];
                ans %= mod;
            }
            else {
                long long l = i - start + 1;
                vector<long long> dp(l + 1);
                dp[0] = 1;
                for(int z = 1; z <= l; z++) {
                    for(int sb = 1; sb <= 3; sb++) {
                        if(z - sb >= 0) dp[z] += dp[z - sb];
                        dp[z] %= mod;
                    }
                    dp[z] %= mod;
                }
                ans *= dp[l];
                ans %= mod;
            }
        }
        
        return ans % mod;
    }
};
