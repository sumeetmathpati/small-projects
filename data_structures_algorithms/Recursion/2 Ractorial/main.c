#include <stdio.h>

int factorial(int n) {

    if (n == 1) {
        return 1;
    }

    return factorial(n - 1) * n;

}

int main() {

    int n = 3;

    printf("Sum of %d natural numbers is %d", n, factorial(n));

    return 0;
}