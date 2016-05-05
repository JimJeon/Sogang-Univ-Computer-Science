#define MAX_SIZE 101

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

void input(const char*, char*, char*);
void output(const char*, bool, int);
bool bruteForce(const char*, const char*, int*);
bool kmp(const char*, const char*, int*);
void failure(const char*, int*);

int main(void)
{
    int repetition = 0;

    char string[MAX_SIZE];
    char pattern[MAX_SIZE];

    bool success = false;

    input("a.txt", string, pattern);

    success = bruteForce(string, pattern, &repetition);

    output("b.txt", success, repetition);

    repetition = 0;

    success = kmp(string, pattern, &repetition);

    output("b.txt", success, repetition);

    return 0;
}

void input(const char* filename, char* string, char* pattern)
{
    FILE* fp = fopen(filename, "r");
    fscanf(fp, "%s", string);
    fscanf(fp, "%s", pattern);
    fclose(fp);
}
void output(const char* filename, bool success, int repetition)
{
    FILE* fp = fopen(filename, "a");
    if(success)
        fprintf(fp, "YES %d\n", repetition);
    else
        fprintf(fp, "NO %d\n", repetition);
    fclose(fp);
}
void failure(const char* pattern, int* fail)
{
    int i, idx = 0;
    int length = strlen(pattern);

    fail[0] = -1;
    for(i = 1;i < length; ++i)
    {
        if(pattern[idx] == pattern[i])
            fail[i] = fail[i-1] + 1;
        else
            fail[i] = -1;
    }
}
bool kmp(const char* string, const char* pattern, int* repetition)
{
    int i, idx = 0;
    int string_length = strlen(string);
    int pattern_length = strlen(pattern);

    int *fail = calloc(pattern_length, sizeof(int));

    failure(pattern, fail);
    for(i = 0;i < string_length;)
    {
        (*repetition)++;
        if(string[i] != pattern[idx])
        {
            if(idx)
                idx = fail[idx-1] + 1;
            else i++;
        }
        else
        {
            if(idx == pattern_length - 1)
                return true;
            idx++;
            i++;
        }
    }
    free(fail);
    return false;
}
bool bruteForce(const char* string, const char* pattern, int* repetition)
{
    int i, j;
    int string_length = strlen(string);
    int pattern_length = strlen(pattern);
    int match_cnt = 0;

    for(i = 0;i < string_length; ++i)
    {
        for(j = 0;j < pattern_length; ++j)
        {
            (*repetition)++;
            if(string[i+j] == pattern[j])
                match_cnt++;
            else match_cnt = 0;
            if(match_cnt == pattern_length) return true;
        }
    }
    return false;
}
