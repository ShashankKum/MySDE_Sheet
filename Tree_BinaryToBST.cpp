//Given a Binary Tree, convert it to a Binary Search Tree.
  The conversion must be done in such a way that keeps the original structure of Binary Tree.
  
//We can do it using the trick that inorder traversal of binary search tree is a sorted array.
  1. We get the inorder traversal of Binary tree in an array. O(N) time
  2. We than sort the array. O(NlogN) time
  3. We than do the inorder traversal of the tree and one by one replace it with elements in array.
  
  //basic algo to depict it -> 
  
	  int i=0;
      void recur(TreeNode* root, int arr[]){
	      if(root==NULL)  return;
		  recur(root->left);
		  root->val = arr[i++];
		  recur(root->right);
	  }