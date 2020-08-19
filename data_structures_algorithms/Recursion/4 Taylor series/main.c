/*

e^x = 1 + x/1 + (x^2)/2! + ... n terms
*/

#include <stdio.h>

int taylorSeries(int x, int n) {

    static int p = 1, f = 1;
    int r;

    if (n == 0) {
        return 1;
    } else {
        r = taylorSeries(x, n - 1) ;
        p = p * x;
        f = f * n;
        return r + (p / f);
    }

}

int main() {

    int n = 3;
    int m = 2;
    printf("Power of %d raised to %d is %d", m, n, power(m, n));

    return 0;
}