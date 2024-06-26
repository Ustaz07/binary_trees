#include "binary_trees.h"
#include <stdlib.h>

/**
 * bst_remove - Removes a node from a Binary Search Tree.
 * @root: A pointer to the root node of the tree.
 * @value: The value to remove from the tree.
 *
 * Return: A pointer to the new root node of the tree after removing the
 * desired value, or NULL if the value was not found in the tree.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	if (root == NULL)
		return NULL;

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else {
		if (root->left == NULL) {
			bst_t *right_child = root->right;
			free(root);
			return right_child;
		} else if (root->right == NULL) {
			bst_t *left_child = root->left;
			free(root);
			return left_child;
		} else {
			bst_t *successor = root->right;
			while (successor->left != NULL)
				successor = successor->left;
			root->n = successor->n;
			root->right = bst_remove(root->right, successor->n);
		}
	}
	return root;
}

