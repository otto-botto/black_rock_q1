#include "gtest/gtest.h"

extern "C" {
#include "tree.h"
}

TEST(Trees, HelloTest) {
    EXPECT_EQ(5, hello());
}

TEST(Trees, MakeNodeTest) {
    char name[] = "Melanie";
    Node* node = makeNode(name);
    fprintf(stderr,"%s\t", node->name);
    EXPECT_STREQ(node->name, name);
}

TEST(Trees, AddChildTest) {
    char employee[] = "Melanie";
    char manager[] = "Scarlett";
    Node* parent = makeNode(manager);
    Node* child = makeNode(employee);
    addChild(parent, child);
    EXPECT_STREQ(parent->name, "Scarlett");
    EXPECT_STREQ(parent->children.head->child->name, "Melanie");
    EXPECT_EQ(parent->children.head->next, nullptr);
}

TEST(Trees, FindChildTest) {
    char em1[] = "Mike";
    char em2[] = "David";
    char em3[] = "Terry";
    char em4[] = "Kyle";
    char em5[] = "Kenny";
    char em6[] = "Ben";
    char em7[] = "Jon";
    char em8[] = "Scott";
    char em9[] = "Chris";

    Node* Nem1 = makeNode(em1);
    Node* Nem2 = makeNode(em2);
    Node* Nem3 = makeNode(em3);
    Node* Nem4 = makeNode(em4);
    Node* Nem5 = makeNode(em5);
    Node* Nem6 = makeNode(em6);
    Node* Nem7 = makeNode(em7);
    Node* Nem8 = makeNode(em8);
    Node* Nem9 = makeNode(em9);

    addChild(Nem1, Nem2);
    addChild(Nem2, Nem3);
    addChild(Nem2, Nem4);
    addChild(Nem2, Nem5);
    addChild(Nem4, Nem6);
    addChild(Nem5, Nem7);
    addChild(Nem7, Nem8);
    addChild(Nem8, Nem9);

    ChildNode* childFound = findChild(Nem2, em8);
    ChildNode* childFound2 = findChild(Nem2, em6);
    EXPECT_STREQ(childFound->child->children.head->child->name, "Chris");
    EXPECT_EQ(childFound2->child->children.head, nullptr);



}