#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
#include <assert.h>
using namespace std;

struct Node {
    Node *left {};
    Node *right{};
    char data {};

    Node(int data) :
        data(data) {
        }
};

class BinaryTree {
private:
    int data;
    BinaryTree *left;
    BinaryTree *right;

public:
    BinaryTree(int data) :
        data(data) {
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
        cout << data << " ";
        if (right) 
            right->print_In_order();
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
};

void print_In_order(Node* current) {
    if (!current)
        return;
    Node *temp_left = current->left;
    Node *temp_rigth = current->right;
    print_In_order(current->left);
    cout << current->data;
    print_In_order(current->right);
}


int main()
{
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

    //print_In_order(multiply);
    BinaryTree bt(5);
    bt.add({1, 2, 3}, {'L', 'R', 'L'});
    bt.add({1, 4}, {'L', 'L'});
    bt.add({6, 7}, {'R', 'L'});
    cout << "All Tree : "; bt.print_In_order(); cout << endl;
    cout << "All Tree : "; bt.print_In_order_itertaive(); cout << endl;
    cout << "Total Nodes: " << bt.total_nodes() << endl;
    cout << "Height : " << bt.tree_hight() << endl;
    cout << "max node: " << bt.tree_max() << endl;
    cout << "Leafes nodes: " << bt.leafs_count() << endl;
    cout << "Check if 5 exist " << bt.if_exists(5) << endl;
    cout << "Check if 10 exist " << bt.if_exists(10) << endl;
    cout << "Check if tree perfect " << bt.is_perfect() << endl;
    cout << "Check if tree prefect with formuala " << bt.is_perfect_formula() << endl;
    cout << "Left boundry "; bt.traverse_left_boundry(); cout << endl;
    return 0;
}
