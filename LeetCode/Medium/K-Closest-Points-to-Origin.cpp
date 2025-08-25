// Max Heap, Time: O(nlogk), Space: O(k)
#define dis pair<double,vector<int>>

class Comparison {
public:
    bool operator()(const dis& a, const dis& b) {
        return a.first < b.first;
    }
};

class Solution {
public:
    double calDistance(vector<int>& point) {
        return point[0]*point[0] + point[1]*point[1];
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<dis, vector<dis>, Comparison> pq;

        for (auto& point: points) {
            pq.push({calDistance(point), point});
            if (pq.size() > k) pq.pop();
        }

        vector<vector<int>> closets;
        while (!pq.empty()) {
            closets.push_back(pq.top().second);
            pq.pop();
        }

        return closets;
    }
};

// Brute Force, sort, Time: O(nlogn)

// Min Heap, Time: O(nlogn), Space; O(n)

// Quick Select, pivot sort, Time: Average O(n), Worst O(n^2)
class Solution {
private:
    double euclidean(vector<int>& point) {
        return point[0]*point[0] + point[1]*point[1];
    }

    int partition(vector<vector<int>>& points, int l, int r) {
        int pivotIdx = r;
        double pivotDist = euclidean(points[pivotIdx]);

        int i = l;
        for (int j = l; j < r; j++) {
            if (euclidean(points[j]) < pivotDist) {
                swap(points[i], points[j]);
                i++;
            }
        }

        swap(points[i], points[pivotIdx]);
        return i;
    }

public:

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int l = 0, r = points.size() - 1;
        int pivot = points.size();

        while (pivot != k) {
            pivot = partition(points, l, r);
            if (pivot < k) {
                l = pivot + 1;
            } else {
                r = pivot - 1;
            }
        }

        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};
