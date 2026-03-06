#include <gtest/gtest.h>
#include <cmath>
#include "../src/Calculator.h"

TEST(CalculatorTest, SquareRootValid) {
    Calculator calc;
    EXPECT_DOUBLE_EQ(calc.squareRoot(25.0), 5.0);
}

TEST(CalculatorTest, SquareRootInvalid) {
    Calculator calc;
    EXPECT_THROW(calc.squareRoot(-4.0), std::invalid_argument);
}

TEST(CalculatorTest, FactorialValid) {
    Calculator calc;
    EXPECT_EQ(calc.factorial(5), 120);
    EXPECT_EQ(calc.factorial(0), 1);
}

TEST(CalculatorTest, FactorialInvalid) {
    Calculator calc;
    EXPECT_THROW(calc.factorial(-3), std::invalid_argument);
}

TEST(CalculatorTest, NaturalLogValid) {
    Calculator calc;
    EXPECT_NEAR(calc.naturalLog(1.0), 0.0, 1e-9);
}

TEST(CalculatorTest, NaturalLogInvalid) {
    Calculator calc;
    EXPECT_THROW(calc.naturalLog(0.0), std::invalid_argument);
    EXPECT_THROW(calc.naturalLog(-2.0), std::invalid_argument);
}

TEST(CalculatorTest, PowerValid) {
    Calculator calc;
    EXPECT_DOUBLE_EQ(calc.power(2.0, 3.0), 8.0);
    EXPECT_DOUBLE_EQ(calc.power(5.0, 0.0), 1.0);
}