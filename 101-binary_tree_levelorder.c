#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_levelorder - Goes through a binary tree using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 *
 * Description: If tree or func is NULL, do nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	/* Allocate memory for an array of tree nodes */
	const binary_tree_t **nodes = malloc(sizeof(binary_tree_t *) * 1024);
	if (nodes == NULL)
		return;

	int front = 0, rear = 0;
	nodes[rear++] = tree;

	/* Traverse the tree in level-order */
	while (front < rear)
	{
		const binary_tree_t *current = nodes[front++];

		/* Call the function with the value of the current node */
		func(current->n);

		/* Enqueue left child if exists */
		if (current->left != NULL)
			nodes[rear++] = current->left;

		/* Enqueue right child if exists */
		if (current->right != NULL)
			nodes[rear++] = current->right;
	}

	/* Free allocated memory */
	free(nodes);
}

