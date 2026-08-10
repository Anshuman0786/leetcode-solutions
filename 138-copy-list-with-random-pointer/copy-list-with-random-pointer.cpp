/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;

        unordered_map<Node*, Node*> map;

        // Pass 1: create clone for every node, map original -> clone
        Node* curr = head;
        while (curr != NULL) {
            map[curr] = new Node(curr->val);
            curr = curr->next;
        }

        // Pass 2: wire up next and random using the map
        curr = head;
        while (curr != NULL) {
            map[curr]->next = map[curr->next];       // NULL maps to NULL naturally
            map[curr]->random = map[curr->random];
            curr = curr->next;
        }

        return map[head];
    }
};