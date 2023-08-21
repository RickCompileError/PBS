// Complexity: O(n^2), Space: O(n)
// Not good
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string ans = "";
        for (int i = str1.size(); i > 0; i--){
            string subStr1 = str1.substr(0, i);

            if (str1.size() % i != 0) continue;
            bool legal = true;
            for (int j = 0; j < str1.size() && legal; j += i){
                legal = (str1.compare(j, i, subStr1) == 0);
            }
            if (!legal) continue;

            if (str2.size() % i != 0) continue;
            legal = true;
            for (int j = 0; j < str2.size() && legal; j += i){
                legal = (str2.compare(j, i, subStr1) == 0);
            }
            if (!legal) continue;
            ans = subStr1;
            break;
        }
        return ans;
    }
};

// Complexity: O(logn), Space: O(1) [Note: gcd by subtract is O(n), gcd by divide is O(log(a+b)), gcd by binary is O(logn)]
// GCD concept, if there has a common substr in two strings, it must satisfy a + b = b + a
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        return (str1 + str2 == str2 + str1) ? str1.substr(0, gcd(str1.size(), str2.size())) : "";
    }
};