#define MAX_BUF         100
#define C_QUEUE_SIZE    20

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>


// stack data structure
typedef struct stack {
  int data;
  struct stack *link;
} stack;
typedef struct stack* stackPointer;
// queue data structure
typedef struct queue {
  int data;
  struct queue *link;
} queue;
typedef struct queue* queuePointer;
// circular queue data structure
typedef struct c_queue {
  int data;
  struct c_queue *link1;
  struct c_queue *link2;
} c_queue;
typedef struct c_queue* cQueuePointer;

// Global Variables
stackPointer top = NULL;
queuePointer front = NULL, rear = NULL;
cQueuePointer c_front = NULL, c_rear = NULL;


bool input(const char* filename, int *buf);
bool output(void);
bool make_stack(int *buf);
bool make_queue(int *buf);
bool make_circle(int *buf);
bool stack_push(int data);
int stack_pop(void);
bool queue_push(int data);
int queue_pop(void);
bool c_queue_push(int data);
int c_queue_pop(void);
void delete_all_memory(void);


int main(void) {
  int buf[MAX_BUF] = {0,};

  if( !input("input.txt", buf) ) {
    fprintf(stderr, "ERROR: file open error or buffer overflow\n");
    delete_all_memory();
    exit(EXIT_FAILURE);
  }
  if(!make_stack(buf)) {
    fprintf(stderr, "ERROR: memory allocation failed\n");
    delete_all_memory();
    exit(EXIT_FAILURE);
  }
  if(!make_queue(buf)) {
    fprintf(stderr, "ERROR: memory allocation failed\n");
    delete_all_memory();
    exit(EXIT_FAILURE);
  }
  if(!make_circle(buf)) {
    fprintf(stderr, "ERROR: memory allocation failed or Queue size overflow\n");
    delete_all_memory();
    exit(EXIT_FAILURE);
  }
  output();

  exit(EXIT_SUCCESS);
}
bool input(const char* filename, int *buf) {
  // initialized
  FILE* fp = fopen(filename, "r");
  int counter = 0;
  // not initialized
  int data;

  while( fscanf(fp, "%d", &data) != EOF ) {
    if( counter >= MAX_BUF ) return false;
    buf[++counter] = data;
  }
  buf[0] = counter;
  fclose(fp);
  return true;
}
bool output(void) {
  FILE *fp = NULL;
  stack* tmp_stack = top;
  queue* tmp_queue = front;
  c_queue* tmp_c_queue = c_front;

  fp = fopen("b.txt", "a");
  if( fp == NULL ) return false;
  while( tmp_stack != NULL ) {
    fprintf(fp, "%d ", tmp_stack->data);
    tmp_stack = tmp_stack->link;
  }
  fclose(fp);

  fp = fopen("c.txt", "a");
  if( fp == NULL ) return false;
  while( tmp_queue != NULL ) {
    fprintf(fp, "%d ", tmp_queue->data);
    tmp_queue = tmp_queue->link;
  }
  fclose(fp);

  fp = fopen("d.txt", "a");
  if( fp == NULL ) return false;
  while( true ) {
    fprintf(fp, "%d ", tmp_c_queue->data);
    if(tmp_c_queue == c_rear) break;
    tmp_c_queue = tmp_c_queue->link1;
  }
  fclose(fp);
  return true;
}
bool make_stack( int *buf) {
  int command = 0, operand = 0;
  int i = 0;

  for(i = 1; i <= buf[0]; ++i) {
    switch(buf[i]) {
      case 0:
        if( !stack_push(buf[++i]) ) return false;
        break;
      case 1:
        stack_pop();
        break;
      default:
        break;
    }
  }
  return true;
}
bool make_queue(int *buf) {
  int command = 0, operand = 0;
  int i = 0;

  for(i = 1; i <= buf[0]; ++i) {
    switch(buf[i]) {
      case 0:
        if( !queue_push(buf[++i]) ) return false;
        break;
      case 1:
        queue_pop();
        break;
      default:
        break;
    }
  }
  return true;
}
bool make_circle(int *buf) {
  int command = 0, operand = 0;
  int i = 0, count = 0;

  for(i = 1; i <= buf[0]; ++i) {
    switch(buf[i]) {
      case 0:
        if(count > C_QUEUE_SIZE) return false;
        if( !c_queue_push(buf[++i]) ) return false;
        count++;
        break;
      case 1:
        c_queue_pop();
        count--;
        break;
      default:
        break;
    }
  }
  return true;
}
bool stack_push(int data) {
  stack *new_node = calloc(1, sizeof(*new_node));

  if(new_node == NULL) return false;

  new_node->data = data;
  new_node->link = NULL;

  if( top != NULL )
    new_node->link = top;
  top = new_node;

  return true;
}
int stack_pop(void) {
  stack *tmp_node = top;
  int result;

  if( top == NULL ) {
    fprintf(stderr, "ERROR: empty stack\n");
    return -1;
  }
  top = top->link;
  result = tmp_node->data;

  free(tmp_node);
  return result;
}
bool queue_push(int data) {
  queue *new_node = calloc(1, sizeof(*new_node));

  if( new_node == NULL ) return false;

  new_node->data = data;
  new_node->link = NULL;

  if( front != NULL ) {
    rear->link = new_node;
    rear = new_node;
  } else {
    front = new_node;
    rear = new_node;
  }

  return true;
}
int queue_pop(void) {
  queue *tmp_node = front;
  int result;

  if( front == NULL ) {
    fprintf(stderr, "ERROR: empty queue\n");
    return -1;
  }
  front = front->link;
  result = tmp_node->data;

  free(tmp_node);
  return result;
}
bool c_queue_push(int data) {
  c_queue *new_node = calloc(1, sizeof(*new_node));

  if( new_node == NULL ) return false;

  new_node->data = data;
  new_node->link1 = NULL;
  new_node->link2 = NULL;

  if( c_front != NULL ) {
    new_node->link1 = c_rear->link1; // link front
    new_node->link2 = c_rear;
    c_rear->link1 = new_node;
    c_front->link2 = new_node;
    c_rear = new_node;
  } else {
    c_front = new_node;
    c_rear = new_node;
    new_node->link1 = new_node;
    new_node->link2 = new_node;
  }

  return true;
}
int c_queue_pop(void) {
  c_queue *tmp_node = c_front;
  int result;

  if( c_front == NULL ) {
    fprintf(stderr, "ERROR: empty c_queue\n");
    return -1;
  }

  c_front = c_front->link1;
  c_front->link2 = c_rear;
  c_rear->link1 = c_front;
  result = tmp_node->data;

  free(tmp_node);
  return result;
}
void delete_all_memory(void) {
  while( top != NULL )
    stack_pop();
  while( front != NULL )
    queue_pop();
  while( c_front != NULL )
    c_queue_pop();
}
