// Time: O(n), Space: O(n)
class Solution {
public:
    bool checkValidString(string s) {
        int sz = s.size();
        stack<int> leftPos;
        stack<int> starPos;

        for (int i = 0; i < sz; i++) {
            if (s[i] == '(') {
                leftPos.push(i);
            } else if (s[i] == ')') {
                if (!leftPos.empty()) {
                    leftPos.pop();
                } else if (!starPos.empty()) {
                    starPos.pop();
                } else {
                    return false;
                }
            } else {
                starPos.push(i);
            }
        }

        while (!leftPos.empty() && !starPos.empty()) {
            if (leftPos.top() > starPos.top()) {
                return false;
            }
            leftPos.pop();
            starPos.pop();
        }

        return leftPos.empty();
    }
};

// Time: O(n), Space: O(1)
class Solution {
public:
    bool checkValidString(string s) {
        int leftMin = 0, leftMax = 0;

        for (auto& i: s) {
            if (i == '(') {
                leftMin++;
                leftMax++;
            } else if (i == ')') {
                leftMin--;
                leftMax--;
            } else {
                leftMin--;
                leftMax++;
            }
            if (leftMax < 0) {
                return false;
            }
            if (leftMin < 0) {
                leftMin = 0;
            }
        }

        return leftMin == 0;
    }
};
