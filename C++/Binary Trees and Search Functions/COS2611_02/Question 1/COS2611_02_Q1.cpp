// COS2611 Skeleton for Assessment 3
#include <iostream>
#include <fstream>
#include <string>
#include<vector>

//Add your student name and student number
//Reyaaz Birch
//56714270
//


using namespace std;

class TreeNode
{
//keep this class as is
public:

    int value;          //key or data
    TreeNode* left;
    TreeNode* right;

    //constructors

    TreeNode() {
        value = 0;
        left = NULL;
        right = NULL;
    } //default constructor

    TreeNode(int v) {
        value = v;
        left = NULL;
        right = NULL;
    } //parametrized constructor

}; //TreeNode


class BST
{
public:
    TreeNode* root;

    //member functions

    BST() {
        root = NULL;
    }

    bool isTreeEmpty()
    {
        if (root == NULL)
            return true;   //the tree is empty
        else
            return false;  //the tree is not empty
    }

    void insertNode(TreeNode* new_node) {
        if (root == NULL) {
            root = new_node;
         } //insert the root node
        else {
            TreeNode* temp = root;
            while (temp != NULL) {
                if (new_node->value == temp->value) {
                    cout << "Value Already exist," <<
                        "Insert another value!" << endl;
                    return;
                }
                else if ((new_node->value < temp->value) && (temp->left == NULL)) {
                    temp->left = new_node;  //insert value to the left
                    break;
                }
                else if (new_node->value < temp->value) {
                    temp = temp->left;
                }
                else if ((new_node->value > temp->value) && (temp->right == NULL)) {
                    temp->right = new_node;  //insert value to the right
                    break;
                }
                else {
                    temp = temp->right;
                }
            }
        }
    } //insertNode

    int heightOfTree(TreeNode* r) {
        //provide the code to determine the height of the tree.
		//return value to the calling procedure
		if (r == NULL)
        return 0;

        // Recursively calculate the height of the left and right subtrees.
        int leftHeight = heightOfTree(r->left);
        int rightHeight = heightOfTree(r->right);

        // Return the maximum of the left and right subtree heights, plus 1 for the current node.
        return max(leftHeight, rightHeight) + 1;
}


    void printPreorder(TreeNode* r) //(current node, Left, Right)
    {
		//provide the code for the preorder binary tree traversal function
		//print the results to the console
        if (r != NULL) {
            cout << r->value << " ";   // Print the current node
            printPreorder(r->left);    // Recursively traverse left subtree
            printPreorder(r->right);   // Recursively traverse right subtree
    }
}//printPreorder

    void printInorder(TreeNode* r) //  (Left, current node, Right)
    {
        //provide the code for the inorder binary tree traversal function
		//print the results to the console
       if (r != NULL) {
        printInorder(r->left);     // Recursively traverse left subtree
        cout << r->value << " ";   // Print the current node
        printInorder(r->right);    // Recursively traverse right subtree
    }

}//printInorder

    void printPostorder(TreeNode* r) //left, right, root
    {
        //provide the code for the postorder binary tree traversal function
		//print the results to the console
		if (r != NULL) {
        printPostorder(r->left);   // Recursively traverse left subtree
        printPostorder(r->right);  // Recursively traverse right subtree
        cout << r->value << " ";   // Print the current node
    }
}// printPostorder

    TreeNode *searchForNode(int v) {
        if (root == NULL) {
            return root;
        }
        else {
            TreeNode* temp = root;
            while (temp != NULL) {
                if (v == temp->value) {
                    return temp;
                }
                else if (v < temp->value) {
                    temp = temp->left;
                }
                else {
                    temp = temp->right;
                }
            }
            return NULL;
        }
    }

    TreeNode* minValueNode(TreeNode* node) {
        TreeNode* current = node;
        /* loop down to find the leftmost leaf */
        while (current->left != NULL) {
            current = current->left;
        }
        return current;
    }



    TreeNode* deleteNode(TreeNode* r, int v) {
        // base case
        if (r == NULL) {
            return NULL;
        }
        // If the key to be deleted is smaller than the root's key,
        // then it lies in left subtree
        else if (v < r->value) {
            r->left = deleteNode(r->left, v);
        }
        // If the key to be deleted is greater than the root's key,
        // then it lies in right subtree
        else if (v > r->value) {
            r->right = deleteNode(r->right, v);
        }
        // if key is same as root's key, then This is the node to be deleted
        else {
            // node with only one child or no child
            if (r->left == NULL) {
                TreeNode* temp = r->right;
                delete r;
                return temp;
            }
            else if (r->right == NULL) {
                TreeNode* temp = r->left;
                delete r;
                return temp;
            }
            else {
                // node with two children: Get the inorder successor (smallest
                // in the right subtree)
                TreeNode* temp = minValueNode(r->right);
                // Copy the inorder successor's content to this node
                r->value = temp->value;
                // Delete the inorder successor
                r->right = deleteNode(r->right, temp->value);
                //deleteNode(r->right, temp->value);
            }
        }
        return r;
    }

    void readFromFileData(string thePath) {
        //Open text file and read data into an array
		//Do not change anything
        fstream myFile(thePath + "data.txt", ios_base::in);
        int nextVal;
        string tp;
        if (myFile.is_open()) {
            string tp;
            while (getline(myFile, tp)) {
                nextVal = stoi(tp);
                cout << nextVal << " ";
                TreeNode* new_node = new TreeNode(); //create the instance in the heap-memory (pointer) - can be seen global and stays in memory
                new_node->value = nextVal;
                insertNode(new_node);
            }
        }
    }

}; //BST = binary search tree - nodes are added at the end of the tree (lowest level)


int main()
{
	//do not change anything in main()
    string thePath = "C:\\data\\";

    BST obj;
    int option, val;

    //Open text file and read data to test with
    fstream myFileTest(thePath + "datatest.txt", ios_base::in);
    int searchForNode1, searchForNode2, nodeToDelete;

    myFileTest >> searchForNode1 >> searchForNode2 >> nodeToDelete;

    cout << "Sorted Binary Trees!\n";

    cout << "MENU \n \n";

    do {

        cout << "\n\n";
        cout << "Choose an option, 0 to stop \n";
        cout << " 1. Read Nodes from file \n";
        cout << " 2. Search Node \n";
        cout << " 3. Delete Node \n";
        cout << " 4. Print BST values \n";
        cout << " 5. Height of tree \n";
        cout << " 6. Clear the screen \n";
        cout << " 0. Exit \n";

        cin >> option;
        TreeNode* new_node = new TreeNode(); //create the instance in the heap-memory (pointer) - can be seen global and stays in memory

        switch (option) {
        case 0:
			break;
        case 1:
            obj.readFromFileData(thePath);  //read the initial values from a text file C:\\data\\data.txt
            break;
        case 2:
            //search for first node
            cout << "SEARCH FOR " << searchForNode1 << " \n";

			val =  searchForNode1;

            new_node = obj.searchForNode(val);              //iterative search
            //new_node = obj.searchForNodeIt(obj.root,val)  //recursive search - you can decide whether you want to do an iterative or recursive search
            if (new_node != NULL) {
                cout << " Value found \n";
            }
            else {
                cout << " Value not found \n";
            }

            //search for second node
            cout << "SEARCH FOR " << searchForNode2 << " \n";
            val = searchForNode2;

            new_node = obj.searchForNode(val);              //iterative search
            //new_node = obj.searchForNodeIt(obj.root,val)  //recursive search - you may decide between iterative and recursive search
            if (new_node != NULL) {
                cout << " Value found \n";
            }
            else {
                cout << " Value not found \n";
            }
			break;

        case 3:
            cout << "DELETE NODE " << nodeToDelete << " \n"; break;
            val = nodeToDelete;
            new_node = obj.searchForNode(val);
            if (new_node != NULL) {
                obj.deleteNode(obj.root, val);
                cout << "OBJECT DELETED \n";
            }
            else {
                cout << "OBJECT NOT FOUND \n";
            }
            break;

        case 4:
            cout << "PRINT BST VALUES \n";
            //obj.print2D(obj.root, 5);

            cout << "PRINT INORDER TRAVERSAL\n";
            obj.printInorder(obj.root);
            cout << "\n\n";

            cout << "PRINT PREORDER TRAVERSAL\n";
            obj.printPreorder(obj.root);
            cout << "\n\n";

            cout << "PRINT POSTORDER TRAVERSAL \n";
            obj.printPostorder(obj.root);
            cout << "\n\n";
            break;

        case 5:
            cout << "HEIGHT OF TREE \n";
            cout << obj.heightOfTree(obj.root);
            cout << "\n\n";
            break;

        case 6:
			system("cls");
			break;

		default:
			cout << "Select from the menu \n";
			break;
        }

    } while (option != 0);

    return 0;
}
