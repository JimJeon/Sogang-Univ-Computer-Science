#define BUFSIZE 15

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node_t {
  int data;
  struct node_t* lchild;
  struct node_t* rchild;
} node_t;
typedef node_t* node_pointer_t;

node_pointer_t get_new_node(int data);
node_pointer_t search_bst(node_pointer_t root, int data);
node_pointer_t search_parent(node_pointer_t child, int data);
bool insert_bst(node_pointer_t *root, int data);
bool delete_bst(node_pointer_t root, int data);
void print_inorder_bst(node_pointer_t root);
void print_preorder_bst(node_pointer_t root);
void print_postorder_bst(node_pointer_t root);

int main(void) {
  char buf[BUFSIZE];
  int operator, operand;
  bool terminal_flag = false;
  node_pointer_t root;

  while(!terminal_flag) {
    operator = -1;
    operand = -1;
    fgets(buf, BUFSIZE-2, stdin);
    sscanf(buf, "%d %d", &operator, &operand);

    switch(operator) {
      case 0:
        if(!insert_bst(&root, operand)) {
          fprintf(stderr, " [!] insertion failed, end program\n");
          exit(EXIT_FAILURE);
        }
        break;
      case 1:
        if(!delete_bst(root, operand)) {
          fprintf(stderr, " [!] deletion failed, end program\n");
          exit(EXIT_FAILURE);
        }
        break;
      case 2:
        print_preorder_bst(root);
        printf("\n");
        print_inorder_bst(root);
        printf("\n");
        print_postorder_bst(root);
        printf("\n");
        break;
      case 3:
        terminal_flag = true;
        continue;
      default:
        fprintf(stderr, " ERROR: wrong operator\n");
        continue;
    }
  }

  exit(EXIT_SUCCESS);
}
node_pointer_t get_new_node(int data) {
  node_pointer_t new_node = calloc(1, sizeof(*new_node));
  new_node->data = data;
  return new_node;
}
node_pointer_t search_bst(node_pointer_t root, int data) {
  node_pointer_t pre_node = NULL;
  node_pointer_t tmp_node = root;
  while(tmp_node) {
    if(tmp_node->data == data) return tmp_node;
    else if(tmp_node->data < data) {
      pre_node = tmp_node;
      tmp_node = tmp_node->rchild;
      continue;
    }
    else if(tmp_node->data > data) {
      pre_node = tmp_node;
      tmp_node = tmp_node->lchild;
      continue;
    }
  }
  return tmp_node;;
}
node_pointer_t search_parent(node_pointer_t root, int data) {
  node_pointer_t pre_node = NULL;
  node_pointer_t tmp_node = root;
  if(!tmp_node) {
    fprintf(stderr, " ERROR: root is NULL\n");
    return NULL;
  }
  while(tmp_node) {
    if(tmp_node->data == data) return pre_node;
    else if(tmp_node->data < data) {
      pre_node = tmp_node;
      tmp_node = tmp_node->rchild;
      continue;
    } else if(tmp_node->data > data) {
      pre_node = tmp_node;
      tmp_node = tmp_node->lchild;
      continue;
    }
  }
  return pre_node;
}
bool insert_bst(node_pointer_t *root, int data) {
  node_pointer_t tmp_node = NULL;
  node_pointer_t new_node = NULL;

  tmp_node = search_bst(*root, data);
  if(tmp_node) { 
    fprintf(stderr, " ERROR: same data already exist\n");
    return false;
  }
  new_node = get_new_node(data);
  if(!new_node) {
    fprintf(stderr, " ERROR: memory is full\n");
    return false;
  }
  if(!*root) {
    *root = new_node;
    return true;
  }
  tmp_node = search_parent(*root, data);
  if(tmp_node->data < data) tmp_node->rchild = new_node;
  else if(tmp_node->data > data) tmp_node->lchild = new_node;
  return true;
}
bool delete_bst(node_pointer_t root, int data) {
  node_pointer_t tmp_node = NULL;
  node_pointer_t pre_node = NULL;
  node_pointer_t max_node = NULL;
  
  tmp_node = search_bst(root, data);
  pre_node = search_parent(root, data);

  if(tmp_node->rchild&&tmp_node->lchild) {
    pre_node = tmp_node;
    max_node = tmp_node->lchild;
    while(max_node->rchild) {
      pre_node = max_node;
      max_node = max_node->rchild;
    }
    tmp_node->data = max_node->data;
    if(pre_node->rchild->data == max_node->data) pre_node->rchild = max_node->lchild;
    else pre_node->lchild = max_node->lchild;
    free(max_node);
  } else if((max_node = tmp_node->rchild)||(max_node = tmp_node->lchild)) {
    if(pre_node->rchild&&pre_node->rchild->data == data) pre_node->rchild = max_node;
    else pre_node->lchild = max_node;
    free(tmp_node);
  } else {
    if(pre_node->rchild&&pre_node->rchild->data == data) pre_node->rchild = NULL;
    else pre_node->lchild = NULL;
    free(tmp_node);
  }
  return true;
}
void print_inorder_bst(node_pointer_t root) {
  if(!root) return;
  print_inorder_bst(root->lchild);
  printf("%d ", root->data);
  print_inorder_bst(root->rchild);
}
void print_preorder_bst(node_pointer_t root) {
  if(!root) return;
  printf("%d ", root->data);
  print_preorder_bst(root->lchild);
  print_preorder_bst(root->rchild);
}
void print_postorder_bst(node_pointer_t root) {
  if(!root) return;
  print_postorder_bst(root->lchild);
  print_postorder_bst(root->rchild);
  printf("%d ", root->data);
}
