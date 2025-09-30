#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

//TODO: remove gtest function
int hello(void);


struct Node;

typedef struct ChildNode {
    struct Node* child;
    struct ChildNode* next;
}ChildNode;

typedef struct List {
    struct ChildNode* head;
}List;

typedef struct Node {
    char name[100];
    List children;
}Node;


Node* makeNode(char* name);
void addChild(Node* parent, Node* child);


