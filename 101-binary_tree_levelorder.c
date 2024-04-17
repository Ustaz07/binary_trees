/**
 * dequeue - Dequeues a node from the queue
 * @front: Pointer to the front of the queue
 * Return: Pointer to the dequeued node
 */
const binary_tree_t *dequeue(queue_t **front)
{
    const binary_tree_t *node;

    if (*front == NULL)
        return NULL;

    node = (*front)->node;
    queue_t *temp = *front;
    *front = (*front)->next;
    free(temp);

    return node;
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

