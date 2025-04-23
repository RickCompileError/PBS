class Solution {
private:
    int digitSum(int n) {
        return n ? n % 10 + digitSum(n / 10) : 0;
    }

public:
    int countLargestGroup(int n) {
        unordered_map<int,int> um;
        int largestSize = -1;
        int group = 0;

        for (int i = 1; i <= n; i++) {
            um[digitSum(i)]++;
        }

        for (auto& [k,v]: um) {
            if (largestSize < v) {
                largestSize = v;
                group = 0;
            }
            group += (largestSize == v);
        }

        return group;
    }
};

// Optimized
class Solution {
private:
    int digitSum(int n) {
        return n ? n % 10 + digitSum(n / 10) : 0;
    }

public:
    int countLargestGroup(int n) {
        int digit[37]{};
        int largest = -1;
        int group = 0;

        for (int i = 1; i <= n; i++) {
            largest = max(largest, ++digit[digitSum(i)]);
        }

        for (auto& i: digit) {
            group += i == largest;
        }

        return group;
    }
};
