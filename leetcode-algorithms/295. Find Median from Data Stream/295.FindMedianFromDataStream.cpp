class MedianFinder {
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        if (small.empty() || num >= small.top())
            small.push(num);
        else
            large.push(num);
        if (small.size() > large.size() + 1)
        {
            large.push(small.top());
            small.pop();
        }
        else if (large.size() > small.size())
        {
            small.push(large.top());
            large.pop();
        }
    }
    
    double findMedian() {
        if (small.size() == large.size())
            return (small.top() + large.top()) / 2.0;
        else
            return small.top();
    }
private:
    priority_queue<int, vector<int>, greater<int>> small;
    priority_queue<int> large;
};

