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

//shorter one
class MedianFinder {
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        max_pq.push(num);
        min_pq.push(max_pq.top());
        max_pq.pop();
        if (min_pq.size() > max_pq.size() + 1)
        {
            max_pq.push(min_pq.top());
            min_pq.pop();
        }
    }
    
    double findMedian() {
        if (max_pq.size() == min_pq.size())
            return (max_pq.top() + min_pq.top()) / 2.0;
        else
            return min_pq.top();
    }
private:
    priority_queue<int> max_pq;
    priority_queue<int, vector<int>, greater<int>> min_pq;
};
