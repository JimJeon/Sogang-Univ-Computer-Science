#include "IO.h"
#include "algorithms.h"

int main(int argc, char** argv) {
    int algo_num = 0;
    int data_cnt = 0;
    char filename[20];

    FILE* commands_fp = NULL;

    commands_fp = fopen("HW2_commands.txt", "rt");
    fscanf(commands_fp, "%d", &algo_num);
    fscanf(commands_fp, "%d", &data_cnt);
    fscanf(commands_fp, "%s", filename);
    elements = read_data(filename, data_cnt);
    fscanf(commands_fp, "%s", filename);


    switch(algo_num) {
        case 1:
            break;
        case 21:
            break;
        case 22:
            break;
        case 23:
            break;
        case 24:
            break;
    }

    exit(EXIT_SUCCESS);
}
