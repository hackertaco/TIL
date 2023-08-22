#include <stdio.h>

void HanoiTower(int n, char from, char by, char to)
{
    if (n == 1)
    {
        printf("원반1을 %c에서 %c로이동\n", from, to);
    }
    else
    {
        HanoiTower(n - 1, from, to, by);
        printf("원반%d을 %c에서 %c로이동\n", n, from, to);
        HanoiTower(n - 1, by, from, to);
    }
}

int main(void)
{
    HanoiTower(3, 'A', 'B', 'C');
    return 0;
}
