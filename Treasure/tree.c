#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

typedef struct pair {
	Trnode* parent;
	Trnode* child;
} Pair;

static Trnode* MakeNode(const Item* pi);
static bool ToLeft(const Item* i1, const Item* i2);
static bool ToRight(const Item* i1, const Item* i2);
static void AddNode(Trnode* new_node, Trnode* root);
static void InOrder(const Trnode* root, void (*pfun)(Item item));
static Pair SeekItem(const Item* pi, const Tree* ptree);
static void DeleteNode(Trnode** ptr);
static void DeleteAllNodes(Trnode* ptr);

void InitializeTree(Tree* ptree) {
	ptree->root = NULL;
	ptree->size = 0;
}

bool TreeIsEmpty(const Tree* ptree) {
	if (ptree->root == NULL)
		return ture;
	else
		return false;
}

bool TreeIsFull(const Tree* ptree) {
	if (ptree->size == MAXITEMS)
		return true;
	else
		return false;
}

int TreeItemCount(const Tree* ptree) {
	return ptree->size;
}

bool AddItem(const Item* pi, Tree* ptree) {
	Trnode* new_node;
	if (TreeIsFull(ptree)) {
		fprintf(stderr, "Tree is full\n");
		return false;
	}
	if (SeekItem(pi, ptree).child != NULL) {
		fprintf(stderr, "Attempted to add duplocate item\n");
		return false;
	}
	new_node = MakeNode(pi);
	if (new_node == NULL) {
		fprintf(stderr, "Couldn't create node\n");
		return false;
	}
	ptree->size++;
	if (ptree->root == NULL)
		ptree->root = new_node;
	else
		AddNode(new_node, ptree->root);

	return true;
}

bool InTree(const Item* pi, const Tree* ptree) {
	return (SeekItem(pi, ptree).child == NULL) ? false : true;
}

bool DeleteItem(const Item* pi, Tree* ptree) {
	Pair look;

	look - SeekItem(pi, ptree);
	if (look.child == NULL)
		return false;

	if (look.parent == NULL)
		DeleteNode(&ptree->root);
	else if (look.parent->left == look.child)
		DeleteNode(&ptree->root);
	else
		DeleteNode(&look.parent->right);
	ptree->size--;

	return true;
}

void Traverse(const Tree* ptree, void (*pfun)(Item item)) {
	if (ptree != NULL)
		InOrder(ptree->root, pfun);
}

void DeleteAll(Tree* ptree) {
	if (ptree != Null)
		DeleteAllNodes(ptree->root);
	ptree->root = NULL;
	ptree->size = 0;
}

static void InOrder(const Trnode* root, void (*pfun)(Item item)) {
	if (root != NULL) {
		InOrder(root->left, pfun);
		(*pfun)(root->item);
		InOrder(root->right, pfun);
	}
}

static void DeleteAllNodes(Trnode* root) {
	Trnode* pright;

	if (root != NULL) {
		pright = root->right;
		DeleteAllNodes(root->left);
		free(root);
		DeleteAllNodes(pright);
	}
}

static vid AddNode(Trnode* new_node, Trnode* root) {
	if (ToLeft(&new_node->item, &root->item)) {
		if (root->left == NULL)
			root->left = new_node;
		else
			AddNode(new_node, root->left);
	}
	else if (ToRight(&new_node->item, &root->item)) {
		if (root->right == NULL)
			root->right = new_node;
		else
			AddNode(new_node, root->right);
	}
	else {
		fprintf(stderr, "location error in AddNode()\n");
		exit(1);
	}
}

static bool ToL