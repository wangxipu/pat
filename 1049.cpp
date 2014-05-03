#include<stdio.h>

int main()
{
    int n;
    long long sum = 0;
    scanf("%d", &n);
    int left, current, right;
    int r = 1;
    while (n/r) {
        left = n/(r*10);
        current = (n/r)%10;
        right = n - (n/r)*r;
        if (current == 1) {
            sum += right + 1 + left * r;
        }else if (current > 1 ) {
            sum += (left + 1)*r;
        }else {
            sum += left * r;
        }

        r *= 10;
    }

    printf("%ld\n", sum);
}
