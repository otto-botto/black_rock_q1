#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

//TODO: remove gtest function
int hello(void);


struct Node;

typedef struct ChildNode {
    struct Node* child;
    struct Node* parent;
    struct ChildNode* next;
}ChildNode;

typedef struct List {
    struct ChildNode* head;
}List;

typedef struct Node {
    char name[100];
    List children;
    struct Node* parent;
}Node;


Node* makeNode(char* name);
void addChild(Node* parent, Node* child);
ChildNode* findChild(Node* parent, char* name);
int distBoss(ChildNode* child);


