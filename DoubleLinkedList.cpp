/*Zachary Firth
Data Structures & Algorithm Analysis COP3530
7/24/22
Program: DoubleLinkedList
Purpose: To create a double linked list of n nodes that are entered by the user, to delete a node at the end of the
list, and to insert a node at the beginning of the list with data the user enters.
*/

#include <iostream>
using namespace std;

//Function prototypes

///Setup of each node for a double linked list
struct dlinklist {
    struct dlinklist* left;
    int data;
    struct dlinklist* right;
};
typedef struct dlinklist node;
node* start = NULL;

node* getnode()  //Sets up a new node for the double linked list.
{
    node* newnode;
    newnode = (node*)malloc(sizeof(node));
    if (newnode) {
        cout << "Enter your data: ";
        cin >> newnode->data;
        newnode->left = NULL;
        newnode->right = NULL;
    }
    return newnode;
}

void createlist(int n)  //Forms a double linked list with the information entered by the user
{
    int i;
    node* newnode;
    node* temp;
    for (i = 0; i < n; i++)
    {
        newnode = getnode();
        if (start == NULL)
        {
            start = newnode;
        }
        else
        {
            if (newnode) {
                temp = start;
                while (temp->right)
                    temp = temp->right;
                temp->right = newnode;
                newnode->left = temp;
            }
        }
    }
}

void traverseList(node *start)  //Prints out the data of each node in the double linked list
{
    cout << "The contents of this list from left to right are:" << endl;
    if (start == NULL){
        cout << "Empty list";
        return;
    }
    else {
        while (start != NULL)
        {
            cout << start->data << " ";
            start = start->right;
        }
    }
}

void deleteEndNode(node *start)  //Deletes the last node of the double linked list
{
    if (start == NULL)
    {
        cout << "\nEmpty list" << endl;
        return;
    }
    node *temp, * prev;
    temp = start;
    while (temp->right) 
        temp = temp->right;
    temp->left->right = NULL;
    free(temp);
}

void insertBeginNode()  //Inserts a node at the beginning of the double linked list
{
    node* newnode;
    newnode = getnode();
    if (start == NULL)
    {
        start = newnode;
    }
    else {
        newnode->right = start;
        start->left = newnode;
        start = newnode;
    }
}

//Main
int main()
{
    int n;
    cout << "Enter the total number of nodes: ";
    cin >> n;
    createlist(n);
    traverseList(start);
    cout << endl;
    deleteEndNode(start);
    cout << "The end node has been deleted from the list." << endl;
    traverseList(start);
    cout << endl;
    insertBeginNode();
    cout << "A new node has been inserted at the begining of this list." << endl;
    traverseList(start);

    return 0;
}


