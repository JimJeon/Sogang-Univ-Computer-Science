#define BUFSIZE 31

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef struct node {
  int data;
  struct node *link;
} node;
typedef node* node_pointer;

void push(node_pointer *head, int data);
int pop(node_pointer *head);

int main(void) {
  int result[BUFSIZE] = {0,};
  int i, j = 0;
  char temp = 0;
  bool flag = false;
  // variables for buffering
  char buffer[BUFSIZE+1] = {0,};
  int n_input = 0;
  char c = 0;
  // variables for stack
  node_pointer top = NULL;

  fgets(buffer, sizeof(buffer), stdin);
  if(buffer[BUFSIZE]) {
    fprintf(stderr, " ERROR: buffer overflow\n");
    exit(EXIT_FAILURE);
  }

  n_input = strlen(buffer);

  for(i = 0; i < n_input - 1; ++i) {
    if(flag) break;
    c = *(buffer + i);
    switch(c) {
      case '(':
      case '[':
        // push to stack
        push(&top, c);
        j += 1;
        break;
      case ')':
        temp = pop(&top);
        j -= 1;
        if(temp == '(' && j>=0) {
          result[j] += 2 * (result[j+1] == 0?1:result[j+1]);
          result[j+1] = 0;
        } else {
          result[0] = 0;
          flag = true;
        }
        break;
      case ']':
        // pop from stack
        temp = pop(&top);
        j -= 1;
        if(temp == '[' && j>=0) {
          result[j] += 3 * (result[j+1] == 0?1:result[j+1]);
          result[j+1] = 0;
        } else {
          result[0] = 0;
          flag = true;
        }
        break;
      default:
        fprintf(stderr, " ERROR: Wrong character found\n");
        exit(EXIT_FAILURE);
    }
  }
  if(top != NULL) result[0] = 0;
  printf("%d\n", result[0]);
  while(top != NULL) pop(&top);
  exit(EXIT_SUCCESS);
}
void push(node_pointer *head, int data) {
  node_pointer new_node = calloc(1, sizeof(*new_node));
  new_node->data = data;
  new_node->link = *head;
  *head = new_node;
}
int pop(node_pointer *head) {
  int ret = 0;
  node_pointer garbage = *head;
  if(*head == NULL) {
    fprintf(stderr, " ERROR: Stack is empty\n");
    return 0;
  }
  ret = (*head)->data;
  *head = (*head)->link;
  free(garbage);
  return ret;
}
