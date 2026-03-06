#include <iostream>
#include <iomanip>
#include "Calculator.h"

int main() {
    Calculator calc;
    int choice;

    do {
        std::cout << "\n===== Scientific Calculator =====\n";
        std::cout << "1. Square Root\n";
        std::cout << "2. Factorial\n";
        std::cout << "3. Natural Logarithm\n";
        std::cout << "4. Power\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        try {
            switch (choice) {
                case 1: {
                    double x;
                    std::cout << "Enter number: ";
                    std::cin >> x;
                    std::cout << "Result: " << std::fixed << std::setprecision(6)
                              << calc.squareRoot(x) << "\n";
                    break;
                }
                case 2: {
                    int x;
                    std::cout << "Enter integer: ";
                    std::cin >> x;
                    std::cout << "Result: " << calc.factorial(x) << "\n";
                    break;
                }
                case 3: {
                    double x;
                    std::cout << "Enter number: ";
                    std::cin >> x;
                    std::cout << "Result: " << std::fixed << std::setprecision(6)
                              << calc.naturalLog(x) << "\n";
                    break;
                }
                case 4: {
                    double base, exponent;
                    std::cout << "Enter base: ";
                    std::cin >> base;
                    std::cout << "Enter exponent: ";
                    std::cin >> exponent;
                    std::cout << "Result: " << std::fixed << std::setprecision(6)
                              << calc.power(base, exponent) << "\n";
                    break;
                }
                case 5:
                    std::cout << "Exiting calculator.\n";
                    break;
                default:
                    std::cout << "Invalid choice. Please try again.\n";
            }
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << "\n";
        }

    } while (choice != 5);

    return 0;
}