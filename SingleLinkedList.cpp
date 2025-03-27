/*Zachary Firth
Data Structures & Algorithm Analysis COP3530
7/245/22
Program: SingleLinkedList
Purpose: To create a single linked list of n nodes that are entered by the user and to delete and insert
a node in the middle of the single linked list which the user inputs for each process.
*/

#include <iostream>
using namespace std;

//Setup of each node for a single linked list
struct slinklist {
    int data;
    slinklist* next;
};
typedef struct slinklist node;
node* start = NULL;

//Function prototypes

node* getNode()  //Sets up a new node for the single linked list.
 {
    node* newnode;
    newnode = (node*)malloc(sizeof(node));
    if (newnode) {
        cout << "Enter your data: ";
        cin >> newnode->data;            //Takes in data for a node
        newnode->next = NULL;
    }
        return newnode;
}

void createList(int n)  //Forms a single linked list with the information entered by the user
{
    int i;
    node* newnode;
    node* temp;
    for (i = 0; i < n; i++)
    {
        newnode = getNode();
        if (start == NULL) {
            start = newnode;
        }
        else
        {
            temp = start;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }
}

int countNode(node* start)  //Recursive function for counting nodes in a single linked list
{
        if (start == NULL)
            return 0;
        else
            return(1 + countNode(start->next));  
}

void deleteMidNode(node* start)  //Deletes a specific node in the middle which the user enters
{
    int ctr = 1, pos, nodectr;
    node* temp, * prev;
    if (start == NULL)
    {
        cout << "\nList is empty" << endl;
        return;
    }
    else {
        cout << "\nEnter the position of an intermediate node you want to delete: ";
        cin >> pos;
        nodectr = countNode(start);
        if(pos > nodectr)
        {
            cout << "\nThis node does not exist";
        }
        if (pos > 1 && pos < nodectr)
        {
            temp = start;
            prev = start;
            while (ctr < pos)
            {
                prev = temp;
                temp = temp->next;
                ctr++;
            }
            prev->next = temp->next;
            free(temp);
            cout << "The node has been deleted." << endl;
        }
        else {
            cout << "Invalid position";
        }
    }
}

void insertMidNode(node* start)  //Inserts a node with data somewhere in the middle of the linked list
{
    node* newnode, * temp, * prev;
    int ctr = 1, nodectr, pos;
    newnode = getNode();
    cout << "Enter an intermediate position of where you want to insert a node: ";
    cin >> pos;
    nodectr = countNode(start);
    if (pos > 1 && pos < nodectr)
    {
        temp = start;
        prev = start;
        while (ctr < pos) {
            prev = temp;
            temp = temp->next;
            ctr++;
        }
        prev->next = newnode;
        newnode->next = temp;
    }
    else
    {
        cout << pos << "is not a middle position" << endl;
    }
}

void traverseList(node* start)  //Prints out the data of each node in the single linked list
{
    while (start != NULL) {
        cout << start->data << " ";
        start = start->next;
    }
}

//Main
int main()
{
    int n;
    cout << "Enter the total number of nodes: ";
    cin >> n;
    createList(n);
    cout << "The list created from the data entered in is: " << endl;
    traverseList(start);
    deleteMidNode(start);
    cout << "The new list after deleting the selected node is: " << endl;
    traverseList(start);
    cout << endl;
    insertMidNode(start);
    traverseList(start);
    return 0;
}


