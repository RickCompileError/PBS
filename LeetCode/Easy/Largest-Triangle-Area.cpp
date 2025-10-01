// area = sqrt(s*(s-a)*(s-b)*(s-c))
class Solution {
private:
    double getSideLength(vector<int>& a, vector<int>& b) {
        return sqrt(pow(a[0] - b[0], 2) + pow(a[1] - b[1], 2));
    }

    double getArea(double a, double b, double c) {
        double s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int sz = points.size();
        double mxArea = 0;

        for (int i = 0; i < sz; i++) {
            for (int j = i + 1; j < sz; j++) {
                for (int k = j + 1; k < sz; k++) {
                    double a = getSideLength(points[i], points[j]);
                    double b = getSideLength(points[i], points[k]);
                    double c = getSideLength(points[j], points[k]);
                    mxArea = max(mxArea, getArea(a, b, c));
                }
            }
        }

        return mxArea;
    }
};

// another formula
class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double max_area = 0.0;
        int n = points.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    int x1 = points[i][0], y1 = points[i][1];
                    int x2 = points[j][0], y2 = points[j][1];
                    int x3 = points[k][0], y3 = points[k][1];
                    double area = 0.5 * abs(x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2));
                    max_area = max(max_area, area);
                }
            }
        }
        return max_area;
    }
};
