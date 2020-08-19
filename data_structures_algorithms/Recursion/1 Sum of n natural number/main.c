#include <stdio.h>

int sumOfFirstNNaturals(int n) {

    if (n == 0) {
        return 0;
    }

    return sumOfFirstNNaturals(n - 1) + n;

}

int main() {

    int n = 100;

    printf("Sum of %d natural numbers is %d", n, sumOfFirstNNaturals(n));

    return 0;
}