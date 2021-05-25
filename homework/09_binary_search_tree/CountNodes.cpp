/****************************************************************************
 *
 * Homework: Implement three functions for counting tree nodes
 *
 * File Name:  CountNodes.cpp
 * Name:       Adam Taylor
 * Course:     CPTR 242
 * Date:       5/25/2021
 * Time Taken: 1 hour
 *
 */
#include "TreeType.h"
// Post: Number of leaf nodes in the tree is returned.
// Calls recursive function to count the number of leaf nodes.
int TreeType::CountLeaves() {
  // TODO Implement function
  return CountLeavesRecusive(root);
}
int TreeType::CountLeavesRecusive(TreeNode *tree) {
  // TODO Implement function
  if (tree == NULL) {
    return 0;
  } else if (tree->left == NULL && tree->right == NULL) {
    return 1;
  } else {
    return CountLeavesRecusive(tree->left) + CountLeavesRecusive(tree->right);
  }
}

// Calls recursive function SingleCount to count the number of
//   nodes with only one child.
int TreeType::CountSingleChildren() {
  // TODO Implement function
  return CountSingleChildrenRecusive(root);
}
int TreeType::CountSingleChildrenRecusive(TreeNode *tree) {
  // TODO Implement function
  if (tree == NULL) {
    return 0;
  } else if ((tree->left == NULL && tree->right != NULL) ||
             (tree->left != NULL && tree->right == NULL)) {
    return 1;
  } else {
    return CountSingleChildrenRecusive(tree->left) +
           CountSingleChildrenRecusive(tree->right);
  }
}
// Pre:  tree has been initialized.
// Post: Return value = the number of nodes in tree that
//       contain values that are greater than value.
int TreeType::CountGreaterThan(ItemType value) {
  // TODO Implement function
  int total = 0;
  FindItemGreaterThan(root, value, total);
  return total;
}
void TreeType::FindItemGreaterThan(TreeNode *tree, ItemType value, int &total) {
  if (tree != NULL) {
    FindItemGreaterThan(tree->left, value, total);
    if (tree->info > value) {
      total++;
    }
    FindItemGreaterThan(tree->right, value, total);
  }
}