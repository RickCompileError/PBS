// Time: O(nlogn), Space: O(n)
class SmallestInfiniteSet {
public:

    set<int> s;

    SmallestInfiniteSet() {
        for (int i = 1; i <= 1000; i++) s.insert(i);
    }
    
    int popSmallest() {
        int num = *s.begin();
        s.erase(s.begin());
        return num;
    }
    
    void addBack(int num) {
        s.insert(num);
    }
};

// Time: O(2/n ^ 2), Space: O(n)
class SmallestInfiniteSet {
public:

    int numList[1001];
    int pos;

    SmallestInfiniteSet() {
        memset(numList, 0, sizeof(numList));
        pos = 1;
    }
    
    int popSmallest() {
        int small = pos;
        numList[pos] = 1;
        while (pos < 1001 && numList[pos]) pos++;
        return small;
    }
    
    void addBack(int num) {
        numList[num] = 0;
        if (pos > num) pos = num;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */