class MedianFinder {
    priority_queue<int> left; //max heap
    priority_queue<int, vector<int>, greater<int>> right; //min heap
    int size;
public:
    MedianFinder() {
        this->size = 0;
    }
    
    void addNum(int num) {
        if (left.empty() && right.empty()) {
            left.push(num);
            size++;
            return;
        }

        if (num > left.top()) {
            right.push(num);
        } else { //num < left.top()
            left.push(num);
        }

        if (right.size() > left.size() + 1) {
            //take rights min to be the next left max value
            int rightMin = right.top();
            right.pop();

            left.push(rightMin);
        } else if (left.size() > right.size() + 1) { //right.size() < left.size() + 1
            int leftMax = left.top();
            left.pop();

            right.push(leftMax);
        }

        size++;
    }
    
    double findMedian() {
        if (size % 2 == 0) { //even size
            return (left.top() + right.top()) / 2.0;
        } else {
            if (left.size() > right.size()) {
                return left.top();
            } else {
                return right.top();
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