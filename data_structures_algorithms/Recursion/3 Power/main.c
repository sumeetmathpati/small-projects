#include <stdio.h>

int power(int m, int n) {

    if (n == 0) {
        return 1;
    }

    if (n % 2 == 0){
        return power(m * m, n / 2);
    } else {
        return (m * power(m * m, n / 2));
    }

    return power(m, n - 1) * m;

}

int main() {

    int n = 3;
    int m = 2;
    printf("Power of %d raised to %d is %d", m, n, power(m, n));

    return 0;
}