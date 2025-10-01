#include "tree.h"



int hello() {
    return 5;
}

/* makes an employee node given a name, add LL for children */
Node* makeNode(char* name) {
    Node* node = (Node*)malloc(sizeof(Node));
    assert(node);
    strcpy(node->name, name);
    node->children.head = NULL;
    return node;
}

/* adds a node as a child of another node */
void addChild(Node* parent, Node* child) {
    ChildNode* childNew = (ChildNode*)malloc(sizeof(ChildNode));
    assert(childNew);

    // wire the child
    childNew->child = child;
    childNew->next = NULL;

    //get to end of children list and add
    if (parent->children.head == NULL) {
        parent->children.head = childNew;
    }else {
        ChildNode* currNode = parent->children.head;
        while (currNode->next) {
            currNode = currNode->next;
        }
        // add here
        currNode->next = childNew;
    }
}

/* find a child so later can track back parent */

ChildNode* findChild(Node* start, char* name){
    if (start == NULL || start->children.head == NULL) {
        return NULL;
    }else {
        ChildNode* currChild = start->children.head;
        while (currChild) {
            Node* child = currChild->child;
            if (strcmp(child->name, name) == 0) {
                return currChild;
            }else {
                ChildNode* keepGoing = findChild(child, name);
                if (keepGoing) {
                    return keepGoing;
                }
                currChild = currChild->next;
            }
        }
    }
    return NULL;

}