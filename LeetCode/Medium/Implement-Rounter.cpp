// Time: O(n), Space: O(n)
#define ll long long
class Router {
private:
    int memoryLimit;
    unordered_map<ll, vector<int>> packets;
    unordered_map<int, vector<int>> destinations;
    queue<ll> q;

    ll encode(int s, int d, int t) {
        return ((ll)s << 40) | ((ll)d << 20) | t;
    }

    int lowerBound(vector<int>& times, int target) {
        return (int)(lower_bound(times.begin(), times.end(), target) - times.begin());
    }

    int upperBound(vector<int>& times, int target) {
        return (int)(upper_bound(times.begin(), times.end(), target) - times.begin());
    }

public:
    Router(int memoryLimit) {
        this -> memoryLimit = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        ll encodedID = encode(source, destination, timestamp);

        if (packets.find(encodedID) != packets.end()) {
            return false;
        }

        if (q.size() == memoryLimit) {
            forwardPacket();
        }

        packets[encodedID] = {source, destination, timestamp};
        destinations[destination].push_back(timestamp);
        q.push(encodedID);

        return true;
    }
    
    vector<int> forwardPacket() {
        if (q.empty()) {
            return {};
        }
        auto& id = q.front();
        vector<int> topPacket = packets[id];
        packets.erase(id);
        destinations[topPacket[1]].erase(destinations[topPacket[1]].begin());
        q.pop();
        return topPacket;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        auto it = destinations.find(destination);
        if (it == destinations.end() || it -> second.empty()) {
            return 0;
        }

        vector<int>& times = it -> second;

        return upperBound(times, endTime) - lowerBound(times, startTime);
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */
