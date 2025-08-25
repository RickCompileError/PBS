// Time: add-O(1), count-O(n), Space: O(n)
class DetectSquares {
private:
    unordered_map<int, unordered_map<int,int>> um;

public:
    DetectSquares() {

    }

    void add(vector<int> point) {
        um[point[0]][point[1]]++;
    }

    int count(vector<int> point) {
        int x1 = point[0], y1 = point[1];
        int count = 0;

        for (auto& [y2, freq]: um[x1]) {
            int len = y1 - y2;

            if (len == 0) {
                continue;
            }

            int x3 = x1 + len;
            int x4 = x1 - len;

            count += freq * um[x3][y1] * um[x3][y2];
            count += freq * um[x4][y1] * um[x4][y2];
        }

        return count;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
