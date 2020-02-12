#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Node{
    public:

    int data =0;
    vector<Node *> childs;
    Node(int data){
        this->data =data;
    }
};

Node *createTree(vector<int>&arr){
    stack<Node*> st;
    Node *root = nullptr;

    for(int i=0; i<arr.size(); i++){

        if(arr[i] != -1){
            Node *node= new Node(arr[i]);
            if(i==0)
                root = node;
            st.push(node);
        }

        else {
            Node *node = st.top();
            st.pop();
            st.top()->childs.push_back(node);
        }
    }


    return root;

}

void display(Node *node){

    cout<< node->data<< "->";
    for(Node *n: node->childs)
    {
        cout<<n->data<< " ,";
    }
    cout<<endl;

    for(Node *n: node->childs){
        display(n);
    }
}


//basic..............................

int size(Node *root){
    int s=0;
    for(Node*n:root->childs){
        s +=size(n);
    }
    return s + 1;
}

int height(Node *root){
    int h=-1;
    for(Node*n: root->childs){
        h = max(h, height(n));
    }

    return h+1;
}

bool find(Node *root, int data){
    if(root->data == data){
        return true;
    }
    bool res= false;
    for(Node*n: root->childs){
        res = res || find(n, data);
    }
    return res;
}

//better method
bool rootToNodePath_01(Node* root, int data, vector<Node *> &path){

    if(root->data == data){
        path.push_back(root);
        return true;
    }

    path.push_back(root);
    bool res = false;

    for(Node *n: root->childs){
        res =  res || rootToNodePath_01(n, data, path);
    }

    if(!res)
        path.pop_back();

    return res;
}

vector <Node*> rootToNodePath_02(Node*node, int data){
    if(node->data == data){
        vector<Node *> base;
        base.push_back(node);
        return base;
    }

    vector <Node*> myAns;
    for(Node*n: node->childs){

        vector<Node*> recAns = rootToNodePath_02(n, data);
        for(Node *child: recAns){
            myAns.push_back(child);
        }
        if(recAns.size() !=0){
            break;
        }
    }

    return myAns;
}

vector<Node *> rootToNodePath_03(Node*node, int data){
    if(node->data == data){
        vector<Node *> base;
        base.push_back(node);
        return base;
    }
    //complete this
}

//to check if tree is symmetric or not
bool isMirror(Node *node1, Node* node2){

    //node1->data != node2->data it'll check if data is also mirrored besides structure
    if(node1->childs.size()!= node2->childs.size() && node1->data != node2->data)
        return false;
    

    for(int i=0, j = node1->childs.size()-1; i<=j; i<i++, j--){
        bool res = isMirror(node1->childs[i], node2->childs[j]);
        if(res == false)
            return false;
    }

    return true;
}

//linearise the generic tree(all nodes form a line in pre-order)


//flatten the generic tree(all children have one node in pre-order)



void solve(){
    vector<int> arr = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 100, -1, 110, -1, -1, 90, -1, 40, 120, 140, -1, 150, -1, -1, -1};
    Node *node = createTree(arr);
    display(node);
}

int main(){
    solve();
    return 0;
}
