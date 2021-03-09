/**********************************************
 * Data Structure #8 open lab
 * Threaded Binary Tree
 *
 * last updated on May 25th, 2016 by Jim Jeon
 **********************************************/

/**********************************************
 * Things to be updated
 * 1. double insert handling
 * 2. inserting alphabet which already exists
 * 3. rename variables for my style
 * 4. remove global variables
 * 5. inserting charater which is not an alphabet
 * 6. extra error handling
 **********************************************/

#define BUFSIZE 20

#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node {
  int value;
  bool leftThread;
  bool rightThread;
  struct node *leftChild;
  struct node *rightChild;
} node;
typedef node* nodePointer;

nodePointer tree = NULL;

nodePointer getNewNode(char alphabet);
nodePointer search_node(char alphabet, nodePointer root);
bool insertLeft(char alphabet, nodePointer new_node);
bool insertRight(char alphabet, nodePointer new_node);
bool delete_tree(nodePointer root);
void print_as_preorder(nodePointer root);
void print_as_postorder(nodePointer root);
void print_as_inorder(nodePointer root);

int main(void) {
  char buf[BUFSIZE+1];

  short int operator;
  char loperand, roperand;

  bool flag = false;

  tree = getNewNode('-');
  tree->leftChild = tree;
  tree->rightChild = tree;

  while(true) {
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%hd %c %c", &operator, &loperand, &roperand);
    switch(operator) {
      case 0: 
        if(!insertLeft (loperand, getNewNode(roperand))) {
          fprintf(stderr, " ERROR: something wrong!\n");
          exit(EXIT_FAILURE);
        }
        break;
      case 1: 
        if(!insertRight(loperand, getNewNode(roperand))) {
          fprintf(stderr, " ERROR: something wrong!\n");
          exit(EXIT_FAILURE);
        }
        break;
      case 2: 
        flag = true;
        break;
      default:
        fprintf(stderr, " ERROR: wrong operator!!\n");
        continue;
    }
    if(flag) break;
  }

  printf("\npreorder\n");
  print_as_preorder(tree->leftChild);
  printf("\ninorder\n");
  print_as_inorder(tree->leftChild);
  printf("\npostorder\n");
  print_as_postorder(tree->leftChild);
  printf("\n");

  if(!delete_tree(tree->leftChild)) {
    fprintf(stderr, " ERROR: deleting empty tree\n");
    exit(EXIT_FAILURE);
  }
  free(tree);

  exit(EXIT_SUCCESS);
}

nodePointer getNewNode(char alphabet) {
  nodePointer new_node = calloc(1, sizeof(node));
  new_node->value = alphabet;
  new_node->leftThread = false;
  new_node->rightThread = false;
  new_node->leftChild = NULL;
  new_node->rightChild = NULL;
  return new_node;
}
nodePointer search_node(char alphabet, nodePointer root) {
  nodePointer tmp_node = NULL;

  if(root->value == alphabet) return root;

  if(!root->leftThread)
    if(tmp_node = search_node(alphabet, root->leftChild)) return tmp_node;
  if(!root->rightThread)
    if(tmp_node = search_node(alphabet, root->rightChild)) return tmp_node;
  return NULL;
}
bool insertLeft(char alphabet, nodePointer new_node) {
  nodePointer tmp_node = NULL;
  if(new_node == NULL) return false;

  tmp_node = search_node(alphabet, tree);

  new_node->leftThread = true;
  new_node->leftChild = tmp_node->leftChild; 

  tmp_node->leftThread = false;
  tmp_node->leftChild = new_node;

  new_node->rightThread = true;
  new_node->rightChild = tmp_node;
  return true;
}
bool insertRight(char alphabet, nodePointer new_node) {
  nodePointer tmp_node = NULL;
  if(new_node == NULL) return false;

  tmp_node = search_node(alphabet, tree);

  new_node->rightThread = true;
  new_node->rightChild = tmp_node->rightChild;

  tmp_node->rightThread = false;
  tmp_node->rightChild = new_node;

  new_node->leftThread = true;
  new_node->leftChild = tmp_node; 
  return true;
}
bool delete_tree(nodePointer root) {
  if(!root) return false;
  if(!root->leftThread) delete_tree(root->leftChild);
  if(!root->rightThread) delete_tree(root->rightChild);
  free(root);
  return true;
}
void print_as_preorder(nodePointer root) {
  printf("%c ", root->value);
  if(!root->leftThread) print_as_preorder(root->leftChild);
  if(!root->rightThread) print_as_preorder(root->rightChild);
}
void print_as_postorder(nodePointer root) {
  if(!root->leftThread) print_as_postorder(root->leftChild);
  if(!root->rightThread) print_as_postorder(root->rightChild);
  printf("%c ", root->value);
}
void print_as_inorder(nodePointer root) {
  nodePointer tmp = NULL;

  tmp = root;
  while(tmp->rightChild != tree) {
    while(!tmp->leftThread) tmp = tmp->leftChild;
    
    printf("%c ", tmp->value);
    tmp = tmp->rightChild;
    
    printf("%c ", tmp->value);
    tmp = tmp->rightChild;
  }
  printf("%c ", tmp->value);
}
