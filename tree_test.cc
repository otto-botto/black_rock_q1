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