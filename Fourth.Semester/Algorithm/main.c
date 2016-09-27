#include "IO.h"
#include "algorithms.h"
#include<time.h>

int main(int argc, char** argv) {

    int testcase = 0;
    int algo_num = 0;
    int filesize = 0;
    char input_name[33] = {0};
    char output_name[33] = {0};

    FILE* config_fp = NULL;

    clock_t start;
    clock_t stop;

    _1d_info_t* _1d_info = NULL;
    _1d_result_t* _1d_result = NULL;
    _2d_info_t* _2d_info = NULL;
    _2d_result_t* _2d_result = NULL;

    config_fp = fopen("HW1_config.txt", "r");
    filesize = fscanf(config_fp, "%d", &testcase);

    while(testcase--) {
        filesize = fscanf(config_fp, "%d %s %s", &algo_num, input_name, output_name);
        _1d_info = NULL;
        _2d_info = NULL;
        _1d_result = NULL;
        _2d_result = NULL;

        switch(algo_num) {
            case 1: // O(n^2)
                _1d_info = one_dim_read_info(input_name);
                start = clock();
                _1d_result = algorithm1(_1d_info);
                stop = clock();
                one_dim_write_info(output_name, _1d_result);
                printf("%s/time: %lf\n", input_name, ((double)(stop-start)) / CLOCKS_PER_SEC);
                free(_1d_info);
                free(_1d_result);
                break;
            case 2: // O(nlogn)
                _1d_info = one_dim_read_info(input_name);
                start = clock();
                _1d_result = algorithm2(_1d_info, 0, _1d_info->number - 1);
                stop = clock();
                one_dim_write_info(output_name, _1d_result);
                printf("%s/time: %lf\n", input_name, ((double)(stop-start)) / CLOCKS_PER_SEC);
                free(_1d_info);
                free(_1d_result);
                break;
            case 3: // O(n)
                _1d_info = one_dim_read_info(input_name);
                start = clock();
                _1d_result = algorithm3(_1d_info);
                stop = clock();
                one_dim_write_info(output_name, _1d_result);
                printf("%s/time: %lf\n", input_name, ((double)(stop-start)) / CLOCKS_PER_SEC);
                free(_1d_info);
                free(_1d_result);
                break;
            case 4: // O(n^4)
                _2d_info = two_dim_read_info(input_name);
                start = clock();
                _2d_result = algorithm4(_2d_info);
                stop = clock();
                two_dim_write_info(output_name, _2d_result);
                printf("%s/time: %lf\n", input_name, ((double)(stop-start)) / CLOCKS_PER_SEC);
                free(_2d_info);
                free(_2d_result);
                break;
            case 5: // O(n^3)
                _2d_info = two_dim_read_info(input_name);
                start = clock();
                _2d_result = algorithm5(_2d_info);
                stop = clock();
                two_dim_write_info(output_name, _2d_result);
                printf("%s/time: %lf\n", input_name, ((double)(stop-start)) / CLOCKS_PER_SEC);
                free(_2d_info);
                free(_2d_result);
                break;
        }
    }
    exit(EXIT_SUCCESS);
}
