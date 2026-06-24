struct Node {
    int val;
    Node* next;
    int minVal;

    Node(int val) {
        this->val = val;
        this->next = nullptr;
    }
};

class MinStack {
public:
    Node* first;

    MinStack() {
        first = nullptr;
    }
    
    void push(int value) {
        if (first == nullptr) {
            first = new Node(value);
            first->minVal = value;
        } else {
            Node* aux = first; //save og first
            int currMin = first->minVal; //minVal of that first

            first = new Node(value); //define new first
            first->next = aux; //attack new first to og

            //define new minVal for stack up to that point
            if (value < currMin) {
                first->minVal = value;
            } else {
                first->minVal = currMin;
            }
        }
    }
    
    void pop() {
        Node* aux = first;
        first = first->next;
        delete aux;
    }
    
    int top() {
        return first->val;
    }
    
    int getMin() {
        return first->minVal;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */