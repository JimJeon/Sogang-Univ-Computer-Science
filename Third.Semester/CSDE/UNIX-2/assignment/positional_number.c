int positional_number(int number)
{
    int cnt = 0;
    while(!number)
    {
        cnt++;
        number /= 10;
    }
    return cnt;
}