class MedianFinder {
private:
    priority_queue<double> maxheap;
    priority_queue<double, vector<double>, greater<double>> minheap;
    int size;
public:
    MedianFinder() {
        size = 0;
    }
    
    void addNum(int num) {
        //empty case
        if (maxheap.empty() && minheap.empty()) {
            maxheap.push(num);
            size++;
            return;
        }

        if (num > maxheap.top()) { //if more than largest from left array
            minheap.push(num); //add to right partition of the array
        } else {
            maxheap.push(num);
        }

        //check we still have valid size for both array partitions
        if (minheap.size() > maxheap.size() + 1) {
            double ele = minheap.top();
            minheap.pop();
            maxheap.push(ele);
        } else if (maxheap.size() > minheap.size() + 1) {
            double ele = maxheap.top();
            maxheap.pop();
            minheap.push(ele);
        }

        size++;
    }
    
    double findMedian() {
        if (size % 2 == 0) {
            return (maxheap.top() + minheap.top()) / 2;
        } else { //odd size
            if (maxheap.size() > minheap.size()) {
                return maxheap.top();
            } else {
                return minheap.top();
            }
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */