//In order to get the minimum swaps required to convert a BT to BST we need to take care that -> 
//Inoreder traversal of a BST is same as sorting the array containing node values.
//so get the inorder traversal of current BT.
//Than follow the same logic as minimum swaps to get a sorted array.
//It will take O(NlogN) time and O(N) extra space.