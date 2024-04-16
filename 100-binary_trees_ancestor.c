#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor node, or NULL if no common ancestor was found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	const binary_tree_t *temp_first = first;
	const binary_tree_t *temp_second = second;
	size_t depth_first = 0, depth_second = 0;

	if (first == NULL || second == NULL)
		return (NULL);

	while (temp_first->parent != NULL)
	{
		temp_first = temp_first->parent;
		depth_first++;
	}

	while (temp_second->parent != NULL)
	{
		temp_second = temp_second->parent;
		depth_second++;
	}

	temp_first = first;
	temp_second = second;

	while (depth_first > depth_second)
	{
		temp_first = temp_first->parent;
		depth_first--;
	}

	while (depth_second > depth_first)
	{
		temp_second = temp_second->parent;
		depth_second--;
	}

	while (temp_first != temp_second)
	{
		temp_first = temp_first->parent;
		temp_second = temp_second->parent;
	}

	return ((binary_tree_t *)temp_first);
}

