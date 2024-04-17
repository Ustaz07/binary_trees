#include "binary_trees.h"
#include <stdlib.h>

/**
 * struct queue_s - Structure for a queue node
 * @node: Pointer to a binary tree node
 * @next: Pointer to the next node in the queue
 */
typedef struct queue_s
{
    const binary_tree_t *node;
    struct queue_s *next;
} queue_t;

/**
 * enqueue - Enqueues a node in the queue
 * @rear: Pointer to the rear of the queue
 * @node: Pointer to the node to be enqueued
 * Return: Pointer to the newly enqueued node
 */
queue_t *enqueue(queue_t *rear, const binary_tree_t *node)
{
    queue_t *new_node = malloc(sizeof(queue_t));
    if (new_node == NULL)
        return NULL;

    new_node->node = node;
    new_node->next = NULL;

    if (rear == NULL)
        return new_node;

    rear->next = new_node;
    return new_node;
}

/**
 * dequeue - Dequeues a node from the queue
 * @front: Pointer to the front of the queue
 * Return: Pointer to the dequeued node
 */
const binary_tree_t *dequeue(queue_t **front)
{
    if (*front == NULL)
        return NULL;

    const binary_tree_t *node = (*front)->node;
    queue_t *temp = *front;
    *front = (*front)->next;
    free(temp);

    return node;
}

/**
 * free_queue - Frees a queue
 * @front: Pointer to the front of the queue
 */
void free_queue(queue_t *front)
{
    while (front != NULL)
    {
        queue_t *temp = front;
        front = front->next;
        free(temp);
    }
}

/**
 * binary_tree_levelorder - Traverses a binary tree using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    if (tree == NULL || func == NULL)
        return;

    queue_t *front = NULL, *rear = NULL;
    const binary_tree_t *current;

    rear = enqueue(rear, tree);
    while (front != NULL)
    {
        current = dequeue(&front);
        func(current->n);
        if (current->left != NULL)
            rear = enqueue(rear, current->left);
        if (current->right != NULL)
            rear = enqueue(rear, current->right);
    }

    free_queue(front);
}

