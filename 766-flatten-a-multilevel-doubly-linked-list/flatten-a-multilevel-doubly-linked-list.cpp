/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    pair<Node*, Node*> flat(Node* head) { //we will return a vector with (start, end) of the level we are in
        //create aux var = head
        Node* aux = head;
        //set start = head as well;
        //end = start for the moment
        Node* start = head;
        Node* end = head;
        //iterate while aux->next != nullptr
        while(aux->next != nullptr || aux->child != nullptr) {
            //if aux has a child
            if (aux->child != nullptr) {
                //(nextStart, nextEnd) = flat(child) //we will set the child as the ghead of it's level
                pair<Node*, Node*> nxtLevelLimits = flat(aux->child);
                Node* nextStart = nxtLevelLimits.first;
                Node* nextEnd = nxtLevelLimits.second;
                //attach next level to current level
                Node* currNext = aux->next;
                aux->next = nextStart;
                nextStart->prev = aux;
                //set child to null
                aux->child = nullptr;
                //attach end of next level to curr level
                if (currNext != nullptr) {
                    nextEnd->next = currNext;
                    currNext->prev = nextEnd;
                }
            }

            if (aux->next != nullptr) {
                aux = aux->next;
            }
        }

        end = aux;
        
        pair<Node*, Node*> res = {start, end};
        return {start, end};
    }   

    Node* flatten(Node* head) {
        if (!head) return nullptr;
        pair<Node*, Node*> res = flat(head);
        return res.first;
    }
};