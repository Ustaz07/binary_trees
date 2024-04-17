#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree
 * @tree: A double pointer to the root node of the BST to insert the value
 * @value: The value to store in the node to be inserted
 *
 * Return: A pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node, *current;

	if (tree == NULL)
		return (NULL);

	/* If the tree is empty, create a new node and make it the root */
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	current = *tree;

	/* Traverse the tree to find the appropriate position to insert */
	while (current)
	{
		if (value < current->n)
		{
			if (current->left == NULL)
			{
				new_node = binary_tree_node(current, value);
				current->left = new_node;
				return (new_node);
			}
			current = current->left;
		}
		else if (value > current->n)
		{
			if (current->right == NULL)
			{
				new_node = binary_tree_node(current, value);
				current->right = new_node;
				return (new_node);
			}
			current = current->right;
		}
		else
		{
			/* If the value is already present in the tree, ignore */
			return (NULL);
		}
	}

	return (NULL); /* Should not reach here */
}

