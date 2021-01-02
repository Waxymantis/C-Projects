#include <iostream>
#include <vector>

using namespace std;

#include <iostream>
#include <vector>
#include <map>

using namespace std;

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

// Juan Carlos Juárez 
//Binary Tree Node Manipulation

   Node* connect(Node* root) {
        if(root==nullptr) return root;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int sizeQ=q.size();
            Node* prev= new Node(-1);
            for(int i=0; i<sizeQ; i++){
                Node* curr=q.front();
                q.pop();
                if(i==0){
                    curr->next=nullptr;
                    prev=curr;
                }else{
                    curr->next=prev;
                    prev=curr;
                }
                if(curr->right!=nullptr) q.push(curr->right);
                if(curr->left!=nullptr) q.push(curr->left);
            }
        }
        return root;
  }
int main() {
  
}