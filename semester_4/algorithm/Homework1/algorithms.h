#ifndef __ALGORITHMS_H__
#define __ALGORITHMS_H__

#include "IO.h"
#include <stdlib.h>
#include <limits.h>

_1d_result_t* algorithm1(_1d_info_t* info) {
    _1d_result_t* result = calloc(1,sizeof(*result));

    int left = 0, right = 0;
    int sum = 0, max = INT_MIN;
    int i, j;

    if(!result) {
        fprintf(stderr, "Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    for(i = 0; i < info->number; ++i) {
        sum = 0;
        for(j = i; j < info->number; ++j) {
            sum += info->data[j];
            if(sum > max) {
                max = sum;
                left = i;
                right = j;
            }
        }
    }

    result->max = max;
    result->left = left;
    result->right = right;
    return result;
}

_1d_result_t* algorithm2(_1d_info_t* info, int left, int right) {
    _1d_result_t* result = calloc(1,sizeof(*result));
    _1d_result_t *max_left = NULL, *max_right = NULL;
    int max_left_border = INT_MIN, max_right_border = INT_MIN;
    int left_border = 0, right_border = 0;
    int left_idx = 0, right_idx = 0;
    int center = 0, i;

    if(!result) {
        fprintf(stderr, "Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    if(left == right) {
        result->max = info->data[left];
        result->left = left;
        result->right = right;
        return result;
    }
    center = (left + right) / 2;

    max_left = algorithm2(info, left, center);
    max_right = algorithm2(info, center + 1, right);

    max_left_border = INT_MIN, left_border = 0;

    for(i = center; i >= left; --i) {
        left_border += info->data[i];
        if(left_border > max_left_border) {
            max_left_border = left_border;
            left_idx = i;
        }
    }

    max_right_border = INT_MIN, right_border = 0;

    for(i = center + 1; i <= right; ++i) {
        right_border += info->data[i];
        if(right_border > max_right_border) {
            max_right_border = right_border;
            right_idx = i;
        }
    }

    if(max_left->max > max_right->max) {
        if(max_left->max > max_left_border + max_right_border) {
            result->max = max_left->max;
            result->left = max_left->left;
            result->right = max_left->right;
        } else {
            result->max = max_left_border + max_right_border;
            result->left = left_idx;
            result->right = right_idx;
        }
    } else {
        if(max_right->max > max_left_border + max_right_border) {
            result->max = max_right->max;
            result->left = max_right->left;
            result->right = max_right->right;
        } else {
            result->max = max_left_border + max_right_border;
            result->left = left_idx;
            result->right = right_idx;
        }
    }

    free(max_left);
    free(max_right);
    
    return result;
}
_1d_result_t* algorithm3(_1d_info_t* info) {
    _1d_result_t* result = calloc(1,sizeof(*result));
    int *dp = calloc(info->number, sizeof(*dp));
    int *left_idx_array = calloc(info->number, sizeof(*left_idx_array));
    int i;

    if(!(result&&dp&&left_idx_array)) {
        fprintf(stderr, "Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    result->max = INT_MIN;

    for(i = 0; i < info->number; ++i) dp[i] = info->data[i];
    
    for(i = 1; i < info->number; ++i) {
        if(dp[i] < dp[i] + dp[i-1]) {
            dp[i] = dp[i] + dp[i-1];
            left_idx_array[i] = left_idx_array[i-1];
        }
        else left_idx_array[i] = i;
    }
    for(i = 0; i < info->number; ++i)
        if(result->max < dp[i]) {
            result->max = dp[i];
            result->left = left_idx_array[i];
            result->right = i;
        }
    free(dp);
    free(left_idx_array);
    return result;
}

_2d_result_t* algorithm4(_2d_info_t* info) {
    _2d_result_t* result = calloc(1,sizeof(*result));

    int i,j,k,l;

    int left = 0, right = 0;
    int up = 0, down = 0;
    int sum = 0, max = INT_MIN;

    if(!result) {
        fprintf(stderr, "Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    for(i = 1; i < info->number; ++i)
        info->data[0][i] += info->data[0][i-1];

    for(i = 1; i < info->number; ++i) {
        info->data[i][0] += info->data[i-1][0];
        for(j = 1; j < info->number; ++j)
            info->data[i][j] += info->data[i][j-1] + info->data[i-1][j] - info->data[i-1][j-1];
    }

    for(i = 0; i < info->number; ++i) {
        for(j = 0; j < info->number; ++j) {
            for(k = i; k < info->number; ++k) {
                for(l = j; l < info->number; ++l) {
                    sum = info->data[k][l];
                    if(i&&j) sum = sum - info->data[i-1][l] - info->data[k][j-1] + info->data[i-1][j-1];
                    else if(!i&&j) sum = sum - info->data[k][j-1];
                    else if(i&&!j) sum = sum - info->data[i-1][l];
                    else sum = sum;
                        
                    if(sum > max) {
                        max = sum;
                        left = j, right = l;
                        up = i, down = k;
                    }
                }
            }
        }
    }

    result->max = max;
    result->left = left;
    result->right = right;
    result->up = up;
    result->down = down;

    return result;
}

_2d_result_t* algorithm5(_2d_info_t* info) {
    _2d_result_t* result = calloc(1,sizeof(*result));
    int i, j, k;

    _1d_info_t *dp = calloc(1, sizeof(*dp));
    _1d_result_t* sub_result = NULL;

    if(!(result&&dp)) {
        fprintf(stderr, "Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    result->max = INT_MIN;
    dp->number = info->number;
    dp->data = calloc(info->number, sizeof(*(dp->data)));

    for(i = 0; i < info->number; ++i) {
        for(j = 0; j < info->number; ++j)
            dp->data[j] = 0;
        for(j = i; j < info->number; ++j) {
            for(k = 0; k < info->number; ++k)
                dp->data[k] += info->data[j][k];
            sub_result = algorithm3(dp);

            if(sub_result->max > result->max) {
                result->max = sub_result->max;
                result->left = sub_result->left;
                result->right = sub_result->right;
                result->up = i;
                result->down = j;
            }
        }
    }

    free(dp->data);
    free(dp);
    free(sub_result);

    return result;
}

#endif
