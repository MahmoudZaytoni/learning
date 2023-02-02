#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#include <assert.h>
using namespace std;


class BinaryTree {

private:
    char data;
    BinaryTree *left;
    BinaryTree *right;

    bool is_just_num() {
        if (data >= '0' && data <= '9')
            return true;
        return false;
    }

public:
    BinaryTree(char data) :
        data(data) {
        }

    BinaryTree(string postifx) {
        stack<BinaryTree*> tree;
        for (int i = 0; i < postifx.length(); i++) {
            BinaryTree *cur = new BinaryTree(postifx[i]);
            if (!isdigit(cur->data)) {
                cur->right = tree.top();
                tree.pop();
                cur->left = tree.top();
                tree.pop();
            }
            tree.push(cur);
        }
        BinaryTree *root = tree.top();
        tree.pop();
        this->data = root->data;
        this->left = root->left;
        this->right = root->right;
    }

    BinaryTree(deque<char> &preorder, deque<char> &inorder, int inorder_start = 0, int inorder_end = -1) {
        if (inorder_end == -1)
            inorder_end = (int)inorder.size() - 1;

        data = preorder.front();
        preorder.pop_front();

        for (int split = inorder_start; split <= inorder_end; split++) {
            if (inorder[split] == data) {
                if (inorder_start < split)
                    left = new BinaryTree(preorder, inorder, inorder_start, split-1);
                if (split < inorder_end)
                    right = new BinaryTree(preorder, inorder, split+1, inorder_end); 
            }
        }
    }

    BinaryTree(queue<pair<int,int>> &preorder_queue) {
        // pair< value, is_leaf>
        pair<int,int> p = preorder_queue.front();
        preorder_queue.pop();
        data = p.first;
        if (!p.second){
            left = new BinaryTree(preorder_queue);
            right = new BinaryTree(preorder_queue);
        }

    }

    ~BinaryTree() {
        clear();
    }

    void clear() {
        if (left) {
            delete left;
            left = nullptr;
        }
        if (right) {
            delete right;
            right = nullptr;
        }
        cout << "Destroy at --> " << this << "\n";
    }

    void print_In_order() {
        if (left)
            left->print_In_order();
        if (data == ' ')
            cout << "x" << " ";
        cout << data << " ";
        if (right) 
            right->print_In_order();
    }

    void print_preorder() {
        cout << data << " ";
        if (left)
            left->print_preorder();
        if (right) 
            right->print_preorder();
    }
    
    void print_In_order_itertaive() {
        stack<pair<BinaryTree*, bool>> nodes;
        nodes.push(make_pair(this,false));

        while(!nodes.empty()) {
            BinaryTree *current = nodes.top().first;
            bool is_done = nodes.top().second;
            nodes.pop();
            if (is_done)
                cout << current->data << " ";
            else {
                if (current->right)
                    nodes.push(make_pair(current->right,false));
                nodes.push(make_pair(current, true));
                if (current->left)
                    nodes.push(make_pair(current->left,false));
            }
        }
        cout << "\n";
    }

    void print_In_order_iterative2() {
        stack<BinaryTree*> st;
        BinaryTree *cur = this;
        while (!st.empty() || cur) {
            while (cur) {
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            cout << cur->data << " ";
            st.pop();
            cur = cur->right;
        }
        cout << endl;
    }

    void print_inorder_expression() {
        if (left) {
            if (!left->is_just_num()) // true if not a number
                cout << "(";
            left->print_inorder_expression();
            if (!left->is_just_num())
                cout << ")";
        }

        cout << data << " ";

        if (right) {
            if (!right->is_just_num())
                cout << "(";
            right->print_inorder_expression();
            if (!right->is_just_num())
                cout << ")";
        }
    }

    void level_order_traversal() {
        queue<BinaryTree*> nodes;
        nodes.push(this);

        while (!nodes.empty()) {
            BinaryTree *cur = nodes.front();
            nodes.pop();

            cout << cur->data << " ";
            if (cur->left)
                nodes.push(cur->left);
            if (cur->right)
                nodes.push(cur->right);
        }
        cout << "\n";
    }

    void print_nodes_level(int level) {
        if (level == 0) 
            cout << data << " ";
        else if (level) {
            if (left)
                left->print_nodes_level(level - 1);
            if (right)
                right->print_nodes_level(level - 1);
        }
    }

    void level_order_traversal_recursive() {
        int h = tree_hight();

        for (int level = 0; level <= h; level++) {
            print_nodes_level(level);
        }
    }

    void level_order_spiral() {
        deque<BinaryTree*> dq;
        dq.push_back(this);

        int level = 0;
        bool forward_level = true;
        while (!dq.empty()) {
            int sz = dq.size();
            while (sz--) {
                BinaryTree *cur;

                if (forward_level) {
                    cur = dq.front();
                    dq.pop_front();

                    if (cur->left)
                        dq.push_back(cur->left);
                    if (cur->right)
                        dq.push_back(cur->right);
                } else {
                    cur = dq.back();
                    dq.pop_back();

                    if (cur->right)
                        dq.push_front(cur->right);
                    if (cur->left)
                        dq.push_front(cur->left);
                }
                cout << cur->data << " ";
            }
            forward_level = !forward_level;
            level++;
        }
        cout << "\n";
    }

    void add(vector<int> values, vector<char> direction) {
        assert(values.size() == direction.size());
        BinaryTree *cur = this;
        for (int i = 0; i < direction.size(); i++) {
            if (direction[i] == 'L') {
                if (!cur->left) 
                    cur->left = new BinaryTree(values[i]);
                else 
                    assert(cur->left->data == values[i]);
                cur = cur->left;
            } else {
                if (!cur->right) 
                    cur->right = new BinaryTree(values[i]);
                else 
                    assert(cur->right->data == values[i]);
                cur = cur->right;
            }
        }
    }

    int tree_max() {
        int mx = data;
        if (left)
            mx = max(mx,left->tree_max());
        if (right)
            mx = max(mx,right->tree_max());
        return mx;
    }

    int tree_hight() {
        int res = 0;
        if (left)
            res = max(res, 1 + left->tree_hight());
        if (right)
            res = max(res, 1 + right->tree_hight());
        return res;
    }

    int total_nodes() {
        int total = 1;
        if (left)
            total += left->total_nodes();
        if (right)
            total += right->total_nodes();
        return total;
    }

    int leafs_count() {
        int res = !left && !right;
        if (left) 
            res += left->leafs_count();
        if (right)
            res += right->leafs_count();
        return res;
    }

    bool if_exists(int value) {
        bool res = (data == value);
        if (!res && left)
            res = left->if_exists(value);
        if (!res && right)
            res = right->if_exists(value);
        return res; 
    }

    bool is_perfect(int h = -1) {
        if (h == -1)
            h = tree_hight();

        if (!left && !right)
            return h == 0;
        
        if (left && !right || !left && right)
            return false;

        return left->is_perfect(h-1) && right->is_perfect(h-1);

    }

    bool is_perfect_formula() {
        int h = tree_hight();
        int n = total_nodes();
        return (pow(2, h + 1) - 1 == n);
    }

    void traverse_left_boundry() {
        cout << data << " ";
        if (left) 
            left->traverse_left_boundry(); 
        else if (right) 
            right->traverse_left_boundry();
    }

    pair<int,int> tree_diameter() {
        pair<int,int> res = make_pair(0,0);
        
        if (!left && !right)
            return res;

        pair<int,int> left_diam{0,0};
        pair<int,int> right_diam{0,0};

        if (left)
            left_diam = left->tree_diameter(), res.first += 1 + left_diam.second; // hight of left
        if (right)
            right_diam = right->tree_diameter(), res.first += 1 + right_diam.second; // hight of right

        res.first = max(res.first, max(left_diam.first, right_diam.first));
        res.second = 1 + max(left_diam.second, right_diam.second);
        return res;
    }

    int tree_diameter_v2(int &res) {
        if (!this)
            return 0;
        int l = left->tree_diameter_v2(res);
        int r = right->tree_diameter_v2(res);
        res = max(res, l+r);
        return max(l,r) + 1;
    }
    
    int tree_diameter_v3(int &res) {
        int l = 0, r = 0;
        if (left)
            l = 1 + left->tree_diameter_v3(res);
        if (right)
            r = 1 + right->tree_diameter_v3(res);
        res = max(res, l+r);
        return max(l,r);
    }

    bool is_complete() {
        queue<BinaryTree*> q;
        q.push(this);
        bool no_more_allowed = false;
        while (!q.empty()) {
            BinaryTree *cur = q.front();
            q.pop();
            if (cur->left) {
                if (no_more_allowed)
                    return 0;
                q.push(cur->left);
            } else
                no_more_allowed = true;
            
            if (cur->right) {
                if (no_more_allowed)
                    return 0;
                q.push(cur->right);
            } else
                no_more_allowed = true;
        }
        return 1;
    }
};

struct Node {
    char data {};
    Node *left;
    Node *right;

    Node(int data) :
        data(data) {
        }
};

class BinaryTree_nodes {
    Node *root;
public:

    void print_In_order(Node *cur) {
        if (!cur)
            return;
        if (cur->left)
            print_In_order(cur->left);
        cout << cur->data << " ";
        if (cur->right)
            print_In_order(cur->right);
    }
};

void main2() {
    Node* plus = new Node('+');
    plus->left = new Node('2');
    plus->right = new Node('3');


    Node* div = new Node('/');
    div->left = new Node('8');
    div->right = new Node('4');

    Node* minus = new Node('-');
    minus->left = new Node('9');
    minus->right = div;

    Node* multiply = new Node('*');
    multiply->left = plus;
    multiply->right = minus;

    BinaryTree_nodes bt;
    bt.print_In_order(multiply);
}


int main()
{

    //BinaryTree bt("534*2^+");
    //bt.add({1, 2, 3}, {'L', 'R', 'L'});
    //bt.add({1, 4}, {'L', 'L'});
    //bt.add({6, 7}, {'R', 'L'});
    BinaryTree bt("23+4*");
    cout << "Tree In order: "; bt.print_In_order(); cout << endl;
    cout << "Tree In order iterative: "; bt.print_In_order_itertaive(); cout << endl;
    cout << "Tree In order iterative2: ";bt.print_In_order_iterative2(); cout << endl;
    cout << "Tree In order Expression: "; bt.print_inorder_expression(); cout << endl;
    cout << "Tree leverl Order: "; bt.level_order_traversal_recursive(); cout << endl;
    cout << "Tree level Order Spirat: "; bt.level_order_spiral(); cout << endl;
    cout << "Tree Preorder: "; bt.print_preorder(); cout << endl;

    cout << "Total Number Nodes: " << bt.total_nodes() << endl;
    cout << "Height : " << bt.tree_hight() << endl;
    cout << "max node: " << bt.tree_max() << endl;
    cout << "Leafes nodes: " << bt.leafs_count() << endl;

    cout << "Check if 5 exist " << bt.if_exists(5) << endl;
    cout << "Check if 10 exist " << bt.if_exists(10) << endl;
    cout << "Check if tree perfect " << bt.is_perfect() << endl;
    cout << "Check if tree prefect with formuala " << bt.is_perfect_formula() << endl;

    cout << "Left boundry "; bt.traverse_left_boundry(); cout << endl;
    pair<int,int> d = bt.tree_diameter();
    cout << "Tree Diamter " << d.first << "\n";
    int diam = 0;
    bt.tree_diameter_v2(diam);
    cout << diam << "\n" ;
    diam = 0;
    bt.tree_diameter_v3(diam);
    cout << diam << "\n";

    //////////////////////////////////////////////////
    deque<char> preorder;
    preorder.push_back('*');
    preorder.push_back('2');
    preorder.push_back('+');
    preorder.push_back('3');
    preorder.push_back('4');
    deque<char> inorder;
    inorder.push_back('2');
    inorder.push_back('+');
    inorder.push_back('3');
    inorder.push_back('*');
    inorder.push_back('4');
    BinaryTree bt2(preorder, inorder);
    cout << "bt2 : inorder: ";
    bt2.print_In_order();
    cout << endl;
    cout << "bt2" << bt2.is_complete() << endl;

    ////////////////////////////////////////////
    queue<pair<int,int>> q;
    q.push({'1',0});
    q.push({'2',0});
    q.push({'3',1});
    q.push({'4',1});
    q.push({'5',0});
    q.push({'6',1});
    q.push({'7',1});
    BinaryTree bt3(q);
    bt3.print_preorder();
    cout << "bt3" << bt3.is_complete() << endl;
    return 0;
}
