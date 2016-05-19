#define INSERT      1
#define DELETE      2
#define UNION       3
#define DIVISION    4
#define PRINT       5
#define QUIT        0
#define WRONG       -1

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef struct node {
    int data;
    struct node *rlink;
    struct node *llink;
} node;
typedef struct node* node_p;

int  read_command(const char* command);
bool add_node(node_p *head, int data);              // INSERT
bool delete_node(node_p *head, int value);          // DELETE
bool list_concat(node_p *dest, node_p *src);        // UNION
bool list_div(node_p *dest, node_p *src, int num);  // DIVISION
bool print_list(node_p target);                     // PRINT
bool delete_list(node_p *head);

int main(void) {
    // node variables
    node_p A = NULL;
    node_p B = NULL;
    // command and while control
    char command[20] = {0, };
    bool end_flag = false;
    // operands
    short int target = 0;
    int value = 0;

    while(!end_flag) {
        scanf("%[^' '\n]", command);
        switch(read_command(command)) {
            case INSERT: 
                scanf("%hd %d", &target, &value);
                switch(target) {
                    case 1:
                        if(!add_node(&A, value))
                            fprintf(stderr, "Error: memory allocation failed\n");
                        break;
                    case 2:
                        if(!add_node(&B, value))
                            fprintf(stderr, "Error: memory allocation failed\n");
                        break;
                    default:
                        fprintf(stderr, "Error: wrong target\n");
                }
                break;
            case DELETE:
                scanf("%hd %d", &target, &value);
                switch(target) {
                    case 1:
                        if(!delete_node(&A, value))
                            fprintf(stderr, "Error: nothing to delete\n");
                        break;
                    case 2:
                        if(!delete_node(&B, value))
                            fprintf(stderr, "Error: nothing to delete\n");
                        break;
                    default:
                        fprintf(stderr, "Error: wrong target\n");
                }
                break;
            case UNION:
                if(!list_concat(&A, &B))
                    fprintf(stderr, "Error: dest or src is NULL\n");
                break;
            case DIVISION:
                scanf("%d", &value);
                if(!list_div(&B, &A, value))
                    fprintf(stderr, "Error: src is empty\n");
                break;
            case PRINT: 
                scanf("%hd", &target);
                switch(target) {
                    case 1:
                        if(!print_list(A))
                            fprintf(stderr, "Error: list is empty\n");
                        break;
                    case 2:
                        if(!print_list(B))
                            fprintf(stderr, "Error: list is empty\n");
                        break;
                    default:
                        fprintf(stderr, "Error: wrong target\n");
                }
                break;
            case QUIT:
                end_flag = true;
                break;
            default:
                fprintf(stderr, "Error: wrong input\n");
        }
        while(getchar() != '\n'); // empty stdin buffer
    }

    delete_list(A);
    delete_list(B);

    exit(EXIT_SUCCESS);
}
int  read_command(const char* command) {
    if(!strcmp(command, "insert"))      return INSERT;
    if(!strcmp(command, "delete"))      return DELETE;
    if(!strcmp(command, "union"))       return UNION;
    if(!strcmp(command, "division"))    return DIVISION;
    if(!strcmp(command, "print"))       return PRINT;
    if(!strcmp(command, "quit"))        return QUIT;
    return WRONG;
}
bool add_node(node_p *head, int data) {
    node_p new_node = calloc(1, sizeof(*new_node));

    if(new_node == NULL) return false;

    new_node->data = data;
    new_node->rlink = NULL;
    new_node->llink = NULL;

    if(*head == NULL) {
        new_node->llink = new_node;
        new_node->rlink = new_node;
        *head = new_node;
        return true;
    } else {
        new_node->rlink = *head;
        new_node->llink = (*head)->llink;
        (*head)->llink->rlink = new_node;
        (*head)->llink = new_node;
    }
    return true;
}
bool delete_node(node_p *head, int value) {
    node_p cur_node = NULL;
    node_p tmp_node = NULL;
    if(!*head) return false;
    cur_node = (*head)->rlink;

    while(cur_node != *head) {
        if(cur_node->data == value) {
            tmp_node = cur_node;
            cur_node = cur_node->rlink;
            tmp_node->llink->rlink = tmp_node->rlink;
            tmp_node->rlink->llink = tmp_node->llink;
            free(tmp_node);
            continue;
        }
        cur_node = cur_node->rlink;
    }
    if(cur_node->data == value) {
        *head = cur_node->rlink;
        cur_node->llink->rlink = cur_node->rlink;
        cur_node->rlink->llink = cur_node->llink;
        free(cur_node);
        if(cur_node == *head) *head = NULL;
    }

    return true;
}
bool list_concat(node_p *dest, node_p *src) {
    if(*dest == NULL) return false;
    if(*src  == NULL) return false;

    node_p tmp = (*dest)->llink;
    (*dest)->llink->rlink = *src;
    (*src)->llink->rlink = *dest;
    (*dest)->llink = (*src)->llink;
    (*src)->llink = tmp;

    *src = NULL;

    return true;
}
bool list_div(node_p *dest, node_p *src, int num) {
    node_p tmp_node = *src;

    if(*src == NULL) return false;

    while(--num)
        tmp_node = tmp_node->rlink;
    // if num equals number of nodes
    if(tmp_node == (*src)->llink) {
        *dest = NULL;
        return true;
    }

    tmp_node->rlink->llink = (*src)->llink;
    (*src)->llink->rlink = tmp_node->rlink;

    (*src)->llink = tmp_node;
    *dest = tmp_node->rlink;
    tmp_node->rlink = *src;

    return true;
}   
bool print_list(node_p target) {
    node_p tmp_node = target;
    if(!tmp_node) return false;

    printf("\"");
    while(tmp_node != target->llink) {
        printf("%d->", tmp_node->data);
        tmp_node = tmp_node->rlink;
    }
    printf("%d\"\n", tmp_node->data);
    return true;
}
bool delete_list(node_p *head) {
    node_p cur_node = (*head)->rlink;
    node_p tmp_node = NULL;
    if(!*head) return false;
    cur_node = (*head)->rlink;

    while(cur_node != *head) {
        tmp_node = cur_node;
        cur_node = cur_node->rlink;
        tmp_node->rlink->llink = tmp_node->llink;
        tmp_node->llink->rlink = tmp_node->rlink;
        free(tmp_node);
    }
    free(cur_node);
    *head = NULL;
    return true;
}
