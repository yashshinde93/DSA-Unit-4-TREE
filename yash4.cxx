#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

struct Node {
int id;
Node* left;
Node* right;
};

class BST {
Node* root;

Node* insertNode(Node* r, int id) {  
    if (r == NULL) {  
        Node* n = new Node;  
        n->id = id;  
        n->left = NULL;  
        n->right = NULL;  
        return n;  
    }  
    if (id < r->id)  
        r->left = insertNode(r->left, id);  
    else if (id > r->id)  
        r->right = insertNode(r->right, id);  
    return r;  
}  

int height(Node* r) {  
    if (r == NULL)  
        return 0;  
    int lh = height(r->left);  
    int rh = height(r->right);  
    return 1 + (lh > rh ? lh : rh);  
}  

void inorder(Node* r) {  
    if (r != NULL) {  
        inorder(r->left);  
        cout << r->id << " ";  
        inorder(r->right);  
    }  
}  

void destroy(Node* r) {  
    if (r != NULL) {  
        destroy(r->left);  
        destroy(r->right);  
        delete r;  
    }  
}

public:
BST() { root = NULL; }
~BST() { destroy(root); }

void insert(int id) { root = insertNode(root, id); }  
int getHeight() { return height(root); }  

void display() {  
    inorder(root);  
    cout << endl;  
}  

// returns number of comparisons made; found is set to true/false  
int search(int id, bool &found) {  
    Node* temp = root;  
    int comparisons = 0;  
    found = false;  
    while (temp != NULL) {  
        comparisons++;  
        if (id == temp->id) {  
            found = true;  
            break;  
        }  
        temp = (id < temp->id) ? temp->left : temp->right;  
    }  
    return comparisons;  
}

};

void printList(const vector<int>& v) {
for (size_t i = 0; i < v.size(); i++)
cout << v[i] << " ";
cout << endl;
}

int main() {
vector<int> ids;
vector<int> sortedIds, shuffledIds;
BST* sortedTree = NULL;
BST* shuffledTree = NULL;
int choice;

do {  
    cout << "\n=== Voter ID Management System ===\n";  
    cout << "1. Enter Voter IDs\n";  
    cout << "2. Build BSTs (Sorted and Shuffled)\n";  
    cout << "3. Display Heights\n";  
    cout << "4. Display Voter IDs\n";  
    cout << "5. Search Voter ID\n";  
    cout << "6. Exit\n";  
    cout << "Enter your choice: ";  
    cin >> choice;  

    switch (choice) {  
        case 1: {  
            int n;  
            cout << "How many voter IDs? ";  
            cin >> n;  
            ids.clear();  
            for (int i = 1; i <= n; i++) {  
                int id;  
                cout << "Enter ID " << i << ": ";  
                cin >> id;  
                if (find(ids.begin(), ids.end(), id) != ids.end())  
                    cout << "Duplicate ID ignored!\n";  
                else  
                    ids.push_back(id);  
            }  
            cout << ids.size() << " voter IDs stored.\n";  
            break;  
        }  
        case 2: {  
            if (ids.empty()) {  
                cout << "Please enter voter IDs first!\n";  
                break;  
            }  
            delete sortedTree;  
            delete shuffledTree;  
            sortedTree = new BST;  
            shuffledTree = new BST;  

            sortedIds = ids;  
            sort(sortedIds.begin(), sortedIds.end());  

            shuffledIds = ids;  
            mt19937 gen(42);  
            shuffle(shuffledIds.begin(), shuffledIds.end(), gen);  

            for (size_t i = 0; i < sortedIds.size(); i++)  
                sortedTree->insert(sortedIds[i]);  
            for (size_t i = 0; i < shuffledIds.size(); i++)  
                shuffledTree->insert(shuffledIds[i]);  

            cout << "Sorted order   : ";  
            printList(sortedIds);  
            cout << "Shuffled order : ";  
            printList(shuffledIds);  
            cout << "Both BSTs built successfully!\n";  
            break;  
        }  
        case 3:  
            if (sortedTree == NULL) {  
                cout << "Please build the BSTs first!\n";  
                break;  
            }  
            cout << "Height of BST (sorted IDs)   : "  
                 << sortedTree->getHeight() << endl;  
            cout << "Height of BST (shuffled IDs) : "  
                 << shuffledTree->getHeight() << endl;  
            break;  
        case 4:  
            if (sortedTree == NULL) {  
                cout << "Please build the BSTs first!\n";  
                break;  
            }  
            cout << "Inorder (sorted BST)   : ";  
            sortedTree->display();  
            cout << "Inorder (shuffled BST) : ";  
            shuffledTree->display();  
            break;  
        case 5: {  
            if (sortedTree == NULL) {  
                cout << "Please build the BSTs first!\n";  
                break;  
            }  
            int id;  
            bool f1, f2;  
            cout << "Enter voter ID to search: ";  
            cin >> id;  
            int c1 = sortedTree->search(id, f1);  
            int c2 = shuffledTree->search(id, f2);  
            if (f1)  
                cout << "Voter ID found!\n";  
            else  
                cout << "Voter ID not found!\n";  
            cout << "Comparisons in sorted BST   : " << c1 << endl;  
            cout << "Comparisons in shuffled BST : " << c2 << endl;  
            break;  
        }  
        case 6:  
            cout << "Exiting program...\n";  
            break;  
        default:  
            cout << "Invalid choice!\n";  
    }  
} while (choice != 6);  

delete sortedTree;  
delete shuffledTree;  
return 0;

}