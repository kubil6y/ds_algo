# Trees

## Terminology

-   root - the most parent node
-   height - the longest path from the root the most child node
-   binary tree - a tree in which has at most 2 children, at least 0 children
-   general tree - a tree with 0 or more children
-   binary search tree - a tree in which has a specific ordering to the nodes and at most 2 children
-   leaves - a node without children
-   balanced tree - a tree is perfectly balanced when any node's left and right children have the same height
-   branching factor - the amount of children a tree has

## Traversal Visualizations

-   [Pre-Order Traversal](https://www.youtube.com/watch?v=8xue-ZBlTKQ)
-   [In-Order Traversal](https://www.youtube.com/watch?v=4_UDUj1j1KQ)
-   [Post-Order Traversal](https://www.youtube.com/watch?v=4Xo-GtBiQN0)
-   [Breadth First Search](https://www.youtube.com/watch?v=n1K14n58Ghw)
-   [Depth First Search](https://www.youtube.com/watch?v=AaLHehZeYdE)

Tree Notes:

-   In-Order traversal with binary search tree will return an ordered array.
-   In languages with memory management using Post-Order traversal makes it easier to clean up nodes.
-   When implementing a Breadth-First Search using an array list will result in O(n2) because of shift/unshift. Always use a real queue.

NOTE: Tries are generally used for caching mechanisms and autocomplete.
You can use preorder traversal to get alphabetical order

```py
def preorder(root):
    if not root:
        return None
    process(root)
    preorder(root.left)
    preorder(root.right)


def inorder(root):
    if not root:
        return None
    inorder(root.left)
    process(root)
    inorder(root.right)


def postorder(root):
    if not root:
        return None
    postorder(root.left)
    postorder(root.right)
    process(root)
```
