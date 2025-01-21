// O(n)
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char,int> labels;
        for (auto& task: tasks) {
            labels[task]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        for (auto const& [key, value]: labels) {
            pq.push({0, value});
        }

        int timer = 0;
        int gap = n + 1;
        while (!pq.empty()) {
            if (pq.top().first > timer++) {
                continue;
            }

            pair<int,int> task = pq.top(); pq.pop();
            task.second--;
            
            if (task.second > 0) {
                pq.push({task.first + gap, task.second});
            }
        }

        return timer;
    }
};

// Math way, O(n)
// The core concept is we are trying to put all the task in the idle time
// And if there is no idle time and still have tasks, then the time will be equal to the amount of tasks
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> v(26, 0);
        for (auto& task: tasks) {
            v[task - 'A']++;
        }

        int maxTask = *max_element(v.begin(), v.end());
        int maxCount = 0;
        for (auto i: v) {
            if (i == maxTask) {
                maxCount++;
            }
        }

        int time = (maxTask - 1) * (n + 1) + maxCount;
        return max(time, (int)tasks.size());
    }
};
