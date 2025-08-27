// Time: O(10^(n/2)*n), Space: O(n)
class Solution {
private:
    long long factorial[11]{0};

    void calculateFactorial() {
        factorial[0] = factorial[1] = 1;
        for (int i = 2; i <= 10; i++) {
            factorial[i] = factorial[i - 1] * i;
        }
    }

    long long combination(string& str, int n) {
        long long base = factorial[n];

        for (auto& c: str) {
            base /= factorial[c - 'a'];
        }

        if (str[0] != 'a') {
            int zeros = str[0] - 'a' - 1;
            int zeroBase = factorial[n - 1];
            for (int i = 1; i <= 9; i++) {
                zeroBase /= factorial[str[i] - 'a'];
            }
            zeroBase /= factorial[zeros];
            base -= zeroBase;
        }

        return base;
    }

    void filterPalindrome(vector<string>& palins, vector<string>& new_palins) {
        unordered_set<string> exist;

        for (string& str: palins) {
            vector<int> freq(10, 0);
            string freqStr = "";

            for (char& c: str) {
                freq[c - '0']++;
            }
            for (int i = 0; i <= 9; i++) {
                freqStr += 'a' + freq[i];
            }
            if (exist.find(freqStr) != exist.end()) {
                continue;
            }
            new_palins.push_back(freqStr);
            exist.insert(freqStr);
        }
    }

    void generatePalindrome(string& base, int idx, vector<string>& palins, int& k) {
        // check
        if (idx >= (base.size() + 1) / 2) {
            if (stoll(base) % k == 0) {
                palins.push_back(base);
            }
            return;
        }

        // backtracking
        for (char i = '0'; i <= '9'; i++) {
            if (idx == 0 && i == '0') {
                continue;
            }
            base[idx] = i;
            base[base.size() - idx - 1] = i;
            generatePalindrome(base, idx + 1, palins, k);
        }
    }

public:
    long long countGoodIntegers(int n, int k) {
        string base(n, '0');
        vector<string> palins;
        vector<string> uniquePalins;

        // calculate factorial
        calculateFactorial();

        // generate palindrome that can divisible by k
        generatePalindrome(base, 0, palins, k);

        // generate unique frequency palindrome
        filterPalindrome(palins, uniquePalins);

        // find combination
        long long comb = 0;
        for (string& palin: uniquePalins) {
            comb += combination(palin, n);
        }

        return comb;
    }
};
