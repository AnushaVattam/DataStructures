
//File Name: prog05_A04701078.zip
//BST.cpp
//Author: Anusha Vattam
//Date: 19 September, 2015
//Assignment Number: 05
//CS3358.04 Fall 2015
//Instructor: Vangelis Metsis
 //Program is  to understand Binary Search Trees  operations such as  Insertion Deletion ,Freeing the BST,Printing.

#include <iostream>
#include <cstdlib>
using namespace std;


struct TreeNode {
    int key;
    TreeNode *left, *right;
};


// Allocates and returns a binary tree node with a given key value
TreeNode* get_bin_tree_node(int val) {
    TreeNode* p = new TreeNode;

    if (p == NULL)
    return NULL;
    p->key = val;
    p->left = p->right = NULL;
    return p;
}


// inserts the key k in the binary search tree rooted at r
// returns the root of the tree after the insertion
TreeNode* bst_insert(int k, TreeNode* r) {
    TreeNode *p, *q, *prev = NULL;

    p = r;
    while (p != NULL) {
        if (p->key == k) {
            cout << "\nThe key " << k << " already exists in the tree. No insertion.\n";
            return r;
        }
        prev = p;
        if (k < p->key) p = p->left;
        else p = p->right;
    }

    /* allocate a new node and set its field key equal to k */
    if ((q = get_bin_tree_node(k)) == NULL) {
        cout << "...out of memory. Insertion aborted.\n";
        return r;
    }

    /* link the new node in the tree */
    if (prev == NULL)
        r = q; /* 1st node = tree root */

    else if (k < prev->key)
        prev->left = q; /* link as left child */
    else prev->right = q; /* link as right child */

    cout << "\nThe key " << k <<" was successfully inserted.\n";
    return r;
}


// returns the parent of a node whose key is k and r is the root of the tree
TreeNode* parent(int k, TreeNode* r) {
    if ((r->left != NULL && r->left->key == k)
        || (r->right != NULL && r->right->key == k))
        return r;
    if (k < r->key)
        return (parent(k, r->left));
    else

        return (parent(k, r->right));

}
// Finds the Max element //
TreeNode* findMax(TreeNode* r)
{
    if(r== NULL)
        return NULL;
    else if (r->right == NULL)
        return r;
    else return findMax(r->right);
}

//  To Search a key in the binary search tree and returns a pointer to the node
// with this key or NULL if the key was not found
TreeNode* bst_search(int k, TreeNode* r) {

    // Base Cases: root is null or key is present at root
    if (r == NULL )
	       return NULL;

    else if(k < r->key)
            return (bst_search(k,r->left));

    else if( k > r->key)
            return (bst_search(k,r->right));
    else
        cout<< "the searching key is found and key ==" << k << endl;
        return r;



}



// deletes the key k from the binary search tree rooted at r
// returns a pointer to the root of the tree after the deletion
TreeNode* bst_delete(int k, TreeNode* r) {
    //TODO: IMPLEMENT

    TreeNode *d, *prev = NULL;
    d = r;
    int left, right = 0;
    while ((d != NULL) && (d->key != k))
    {
        left = right = 0;
        prev = d;
        if (k < d->key)
        {
            left = 1;
            d = d->left;
        }
        else if (k > d->key)
        {
            right = 1;
            d = d->right;
        }
        else if (k == d->key)
            break;
    }

    if (d == NULL)
    {
        cout << "Cannot delete " << k << ".Value is not found" << endl;
        return r;
    }
    cout << "found value " << d->key << endl;

    if ( (d->left == NULL) && (d->right == NULL))
    {
        cout << "all null" << endl;

        if (left == 1)
        {
            prev->left = NULL;
            left = 0;
        }
        else
        {
            cout << "right delete" << endl;
            prev->right = NULL;
            right = 0;
        }
    }
    else if (d->right == NULL)
    {
        cout << "right null" << endl;
        if (d == r)
        {
            d = d->left;
        }
        else if ( left = 1)
        {
            prev->left = d->left;
            left = 0;
        }
        else
        {
            prev->right = d->left;
            right = 0;
        }

    }
    else
    {
        //cout << "enter the dragon" << endl;

        TreeNode *prePrev, *prev, *small = NULL;
        prePrev = d->right;
        prev = prePrev->left;
       // cout << "after prev" << prev << endl;
        if (prev != NULL)
            small = prev->left;
        //cout << "after small" << small << endl;
        while (small != NULL)
        {
            //cout << "in while" << endl;
            prePrev = prev;
            prev = small;
            small = small->left;
        }
        //cout << "prev key" << endl;
       // cout << "d key" << endl;
        if (prev == NULL)
        {
            d->key = prePrev->key;
            d->right = prePrev->right;
        }
        else
        {
        d->key = prev->key;
        //cout << "here 1" << endl;
        prePrev->left = prev->right;
        }
    }

        cout<< "The  Deleted  key ==" << k << endl;
        return r;
}


// prints all the keys of the binary search tree (inorder)
void print_binary_tree(int h, TreeNode *r) {
    //TODO: IMPLEMENT


    if (r != NULL)
    {
        print_binary_tree(h, r->left);
        cout<<r->key<<"  ";
        print_binary_tree(h, r->right);
    }
}


// Postorder freeing of the binary search tree
void free_binary_tree(TreeNode *r) {
    //TODO: IMPLEMENT
        if (!r)
            return;
        free_binary_tree(r->left);
        free_binary_tree(r->right);

        delete r;
}

// Prints a user choice menu
void print_menu() {
    cout << "\n";
    cout << "Type 1 to insert an integer\n";
    cout << "     2 to delete an integer\n";
    cout << "     3 to search for an integer in the tree\n";
    cout << "     4 to print the tree\n";
    cout << "     5 to free the nodes of the tree\n";
    cout << "     6 to print this menu of tree commands\n";
    cout << " or  any other number to exit.\n";
}


// gets the user choice and returns as an integer
int get_choice() {
    int i;
    cout << "Command> ";
    cin >> i;

    while (i == 6) {
        print_menu();
        cout << "Command> ";
        cin >> i;
    }
    return i;
}


// main method
int main(int argc, char** argv) {
    int i, choice;
    TreeNode *treeroot;

    treeroot = NULL; /* empty tree */

    print_menu();
    choice = get_choice(); /* handles choice = 6 */

    while (choice > 0 && choice < 6) {
        switch (choice) {
            case 1: cout << "Enter a number: "; /* insertion */
                cin >> i;
                treeroot = bst_insert(i, treeroot);
                break;
            case 2: if (treeroot == NULL) /* deletion */{
                    cout << "\nThe tree is empty. There is nothing to delete.\n";
            }
                else {
                    cout << "Enter a number: ";
                    cin >> i;
                    treeroot = bst_delete(i, treeroot);
                }
                break;
            case 3: cout << "Enter a number: "; /* search */
                cin >> i;

                if (bst_search(i, treeroot) != NULL)
                {
                    cout << "The number was found in the tree.\n";
                }
                else
                {
                    cout << "The number was not found.\n";
                }
                break;
            case 4: /* print */
                if (treeroot != NULL)
                    print_binary_tree(0, treeroot);
                else
                    cout << "\nThe tree is empty. There is nothing to print.\n";
                break;
            case 5: /* free nodes */
                if (treeroot != NULL) {
                    free_binary_tree(treeroot);
                    treeroot = NULL;
                } else
                    cout << "\nThe tree is empty. There is nothing to free.\n";
                break;
            default: /* not needed */
                break;
        }
        cout << "\n";
        cout << "Type 1 to 5 for a command on a binary search tree,\n";
        cout << "6 for the menu of commands, or any other number to exit.\n";
        choice = get_choice(); /* handles choice = 6 */
    }
    cout << "\nProgram completed.\n";

    return (EXIT_SUCCESS);
}
