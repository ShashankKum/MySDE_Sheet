
 //Merge two balanced BST into one balanced BST in O(m+n) time where first BST has n nodes and second one has m nodes.
 //We can achieve this using ->
   1. Get the inorder traversal of first BST this will take O(n) time.
   2. Get the inorder traversal of second BST this will take O(m) time.
   3. Merge both the sorted arrays this will take O(m+n) time.
   4. Using this sorted array create a balanced binary tree, by recursively using middle element as root and left part as left subtree,
      and right part as right subtree.