// Time: O(logn), Space: O(logn)
class Solution {
private:
    int SQ[10]{0, 1, 4, 9, 16, 25, 36, 49, 64, 81};

public:
    bool isHappy(int n) {
        set<int> visited;

        while (n != 1 && visited.find(n) == visited.end()) {
            visited.insert(n);

            int s = 0;
            while (n > 0) {
                s += SQ[n % 10];
                n /= 10;
            }
            n = s;
        }

        return n == 1;
    }
};

// Fast & Slow pointer, Floyd's Cycle-Finding Algorithm
// Time: O(logn), Space: O(1)
class Solution {
private:
    int SQ[10]{0, 1, 4, 9, 16, 25, 36, 49, 64, 81};

    int digitSquareSum(int n) {
        int s = 0;

        while (n > 0) {
            s += SQ[n % 10];
            n /= 10;
        }

        return s;
    }

public:
    bool isHappy(int n) {
        int slow = n, fast = digitSquareSum(n);

        while (slow != fast) {
            fast = digitSquareSum(digitSquareSum(fast));
            slow = digitSquareSum(slow);
        }

        return slow == 1;
    }
};
