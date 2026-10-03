struct Node {
    int value;
    Node* prev;
    Node* next;

    Node(int value, Node* prev, Node* next) {
        this->value = value;
        this->prev = prev;
        this->next = next;
    }

    Node(int value) {
        this->value = value;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

class MaxStack {
public:
    Node* dummyHead = new Node(INT_MAX);
    Node* dummyTail = new Node(INT_MIN);
    map<int, vector<Node*>> nodes; //ordered, can use upper bound, and same nodes

    MaxStack() {
        dummyHead->next = dummyTail; 
        dummyTail->prev = dummyHead;
    }
    
    void push(int x) {
        Node* newNode = new Node(x, dummyHead, dummyHead->next);
        Node* aux = dummyHead->next;
        dummyHead->next = newNode;
        aux->prev = newNode;
        nodes[x].push_back(newNode);
    }
    
    //N<->dh<->5<->1<->5<->dt<->N
    int pop() {
        Node* aux = dummyHead->next;
        int value = aux->value;

        dummyHead->next = aux->next;
        aux->next->prev = dummyHead;

        nodes[value].pop_back();
        if (nodes[value].empty()) {
            nodes.erase(value);
        }

        delete aux;
        return value;
    }
    
    int top() {
        return dummyHead->next->value;
    }
    
    int peekMax() {
        return nodes.rbegin()->first;
    }
    int popMax() {
        int valToDel = nodes.rbegin()->first; //max element
        Node* nodeToDel = nodes[valToDel].back();

        //delete node
        nodeToDel->prev->next = nodeToDel->next;
        nodeToDel->next->prev = nodeToDel->prev;

        nodes[valToDel].pop_back();
        if (nodes[valToDel].empty()) {
            nodes.erase(valToDel);
        }

        delete nodeToDel;
        return valToDel;
    }
};

/**

null <- 5 <-> 2 <-> 7 <-> 2 <-> 5 <-> 8 <-> 6-> null

 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */