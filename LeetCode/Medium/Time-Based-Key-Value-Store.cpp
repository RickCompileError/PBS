#define data pair<int, string>

// Binary Search
class TimeMap {
private:
    map<string, vector<data>> m;

public:
    TimeMap() {
        m.clear();
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        vector<data> &v = m[key];

        if (v.empty()) {
            return "";
        }
        
        int left = 0, right = v.size() - 1, mid;
        int midTime;

        while (left <= right) {
            mid = left + (right - left) / 2;
            midTime = v[mid].first;

            if (midTime <= timestamp) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return right >= 0 ? v[right].second : "";
    }
};

// Upper Bound Concept
class TimeMap {
private:
    map<string, vector<data>> m;

public:
    TimeMap() {
        m.clear();
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        vector<data> &v = m[key];
        int cur = 0, nxt;
        int sz = v.size(), step;

        while (sz > 0) {
            step = sz / 2;
            nxt = cur + step;
            if (timestamp >= v[nxt].first) {
                cur = nxt + 1, sz -= step + 1;
            } else {
                sz = step;
            }
        }

        return cur - 1 >= 0 ? v[cur - 1].second : "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
