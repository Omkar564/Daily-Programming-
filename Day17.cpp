#include <iostream>
#include <vector>

std::vector<int> primeFactorization(int N) {
    std::vector<int> factors;

    // Check for the number of 2s that divide N
    while (N % 2 == 0) {
        factors.push_back(2);
        N /= 2;
    }

    // N must be odd at this point, so we can skip even numbers
    for (int i = 3; i * i <= N; i += 2) {
        while (N % i == 0) {
            factors.push_back(i);
            N /= i;
        }
    }

    // This condition is to check if N is a prime number greater than 2
    if (N > 2) {
        factors.push_back(N);
    }

    return factors;
}

int main() {
    int N;
    std::cout << "Enter a positive integer: ";
    std::cin >> N;

    if (N <= 0) {
        std::cout << "Please enter a positive integer." << std::endl;
        return 1;
    }

    std::vector<int> factors = primeFactorization(N);
    std::cout << "Prime Factorization of " << N << ": [";
    for (size_t i = 0; i < factors.size(); ++i) {
        std::cout << factors[i];
        if (i < factors.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;

    return 0;
}
