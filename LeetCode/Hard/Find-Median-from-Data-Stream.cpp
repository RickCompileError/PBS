// Two pq to find the middle value, add: O(logn), get: O(1)
class MedianFinder {
private:
    // For picking maximum value in left array
    priority_queue<int, vector<int>, less<int>> maxHeap;
    // For picking minimum value in right array
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int size;

public:
    MedianFinder() {
        size = 0;
    }
    
    void addNum(int num) {
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }

        if (maxHeap.size() >= minHeap.size() + 2) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() >= maxHeap.size() + 2) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

        size++;
    }
    
    double findMedian() {
        if (size % 2) {
            return maxHeap.size() > minHeap.size() ? maxHeap.top() : minHeap.top();
        }
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
