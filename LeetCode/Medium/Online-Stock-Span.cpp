// Time: O(n), Space: O(n)
class StockSpanner {
private:
    stack<pair<int,int>> s;

public:
    StockSpanner() {
    }

    int next(int price) {
        int day = 1;
        while (this->s.size() && this->s.top().first <= price) {
            day += this->s.top().second;
            this->s.pop();
        }
        this->s.push({price, day});
        return day;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
