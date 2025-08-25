// map with pq, O(nlogn)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> m;
        for (auto& i: nums) m[i]++;

        priority_queue<pair<int,int>, vector<pair<int,int>>, less<>> pq;
        for (auto& i: m) pq.emplace(i.second, i.first);

        vector<int> ans;
        while (k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};

// quicksearch, extend of quick sort, O(n), Worst O(n^2)
class Solution {
private:
    vector<int> unique;
    map<int,int> count;

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        for (auto& i: nums) count[i]++;

        for (auto& i: count) unique.push_back(i.first);

        quickSelect(0, unique.size() - 1, k);

        vector<int> ans(k);
        copy(unique.begin(), unique.begin() + k, ans.begin());
        return ans;
    }

    void quickSelect(int l, int r, int k) {
        if (l == r) return;

        int pivot = l + rand() % (r - l + 1);

        pivot = sort(l, r, pivot);

        if (k == pivot) {
            return;
        }
        else if (k < pivot) {
            quickSelect(l, pivot - 1, k);
        }
        else if (k > pivot) {
            quickSelect(pivot + 1, r, k);
        }
    }

    int sort(int l, int r, int pivot) {
        int feq = count[unique[pivot]];

        swap(unique[pivot], unique[r]);

        int idx = l;
        for (int i = l; i <= r; i++) {
            if (count[unique[i]] > feq) {
                swap(unique[i], unique[idx]);
                idx++;
            }
        }

        swap(unique[r], unique[idx]);
        return idx;
    }
};
