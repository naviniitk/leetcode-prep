/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return NULL;
        queue<Node *> q;
        root->next = NULL;
        q.push(root); // push root into queue

        while(!q.empty()) {
            vector<Node*> v;
            int j = 0;
            int s = q.size();
            for(int i = 0; i < s; ++i) {
                Node * temp = q.front();
                q.pop();
                v.push_back(temp); // here all the elements of a level are pushed from left to right
                if(temp->left) q.push(temp->left); // here first left then right, when the loop runs again, their left and right are also pushed so basically one level if pushed to array from left to right
                if(temp->right) q.push(temp->right);
            }
            for(j = 0; j < v.size() - 1; ++j){
                v[j]->next = v[j+1];
            }
            v[j] = NULL;
        }
        return root;
    }
};
