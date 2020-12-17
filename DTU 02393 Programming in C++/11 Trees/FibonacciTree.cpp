#include <iostream>
#include <vector>

using namespace std;

class FibonacciTree {
    
public:
	FibonacciTree(FibonacciTree * left, FibonacciTree * right, int value);
    int size();             // size of the tree
    int depth();           // height of the tree
    int leafs();           // number of leafs in the tree (the number of constants)
    void traverse_pre(vector<int> &);    // print nodes in pre-order (prefix notation)

    
public:		
    FibonacciTree *left;
    FibonacciTree *right;
    int value;
};


FibonacciTree::FibonacciTree(FibonacciTree * left, FibonacciTree * right, int value){
	this->left=left;
	this->right=right;
    this->value=value;
}

int FibonacciTree::size(void){
    if(left != nullptr && right != nullptr){
        return 1 + left->size() + right->size();
    }
    else{
        return 1;
    }  
}


void FibonacciTree::traverse_pre(vector<int> & fibNumbers){
    fibNumbers.push_back(value);
    if(left != nullptr){
        left -> traverse_pre(fibNumbers);
        if(right != nullptr){
            right -> traverse_pre(fibNumbers);
        }
    }
}

int FibonacciTree::depth(void){
    if(left != nullptr && right != nullptr){
		return 1 + max(left->depth(),right->depth());
	}
    else{
        return 1;
    }
}

int FibonacciTree::leafs(void){
    if(left != nullptr && right != nullptr){
		return left->leafs() + right->leafs();
	}
    else{
        return 1;
    }
}

FibonacciTree * fibonacci(unsigned int n){
    if(n<=1){
        int fibNumber = 1;
        FibonacciTree *node = new FibonacciTree(nullptr, nullptr, fibNumber);
        return node;
    }
    else{
        FibonacciTree * left = fibonacci(n-1);
        FibonacciTree * right = fibonacci(n-2);
        int fibNumber = left->value + right->value;
        FibonacciTree *node = new FibonacciTree(left, right, fibNumber);
        return node;
    }
}


int main(){
    unsigned int n;
    cin >> n;

    FibonacciTree *topNode = fibonacci(n);

    // Call traversing in pre-order
    vector<int> fibNumbers;
    cout << "Call tree in pre-order: ";
    topNode->traverse_pre(fibNumbers);
    for(int x: fibNumbers){
       cout << x << " ";
    }
    cout << endl;

    // Call tree size
    cout << "Call tree size: ";
    cout << topNode->size() << endl;

    // Call tree depth
    cout << "Call tree depth: ";
    cout << topNode->depth() << endl;

    // Call tree leafs
    cout << "Call tree leafs: ";
    cout << topNode->leafs() << endl;

    return 0;
}

