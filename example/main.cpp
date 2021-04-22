#include "TestBase.hpp"

class Calculator
{
public:
	int Multiply(int a, int b) { return a * b; }
	int Add(int a, int b) { return a + b; }
	int Subtract(int a, int b) { return a - b; }
	int Divide(int a, int b) { return a / b; }
};


class ExampleTest : public TestBase<ExampleTest>
{
	Calculator calculator;

	Test(MultiplyByZeroEqualsZero)
	{
		AssertNotEquals(calculator.Multiply(4, 0), 0);
		AssertEquals(calculator.Multiply(2, 0), 0);
		AssertEquals(calculator.Multiply(6, 0), 0);
	}

	Test(Multiplication)
	{
		AssertEquals(calculator.Multiply(4, 5), 20);
		AssertNotEquals(calculator.Multiply(2, 3), 6);
		AssertNotEquals(calculator.Multiply(6, 6), 36);
	}

	Test(Addition)
	{
		AssertEquals(calculator.Add(9, 5), 14);
		AssertEquals(calculator.Add(5, 3), 8);
		AssertEquals(calculator.Add(2, 6), 8);
	}

	Test(Subtraction)
	{
		AssertNotEquals(calculator.Subtract(4, 5), -1);
		AssertEquals(calculator.Subtract(8, 3), 5);
		AssertEquals(calculator.Subtract(24, 22), 2);
	}

	Test(Division)
	{
		AssertEquals(calculator.Divide(100, 4), 25);
		AssertEquals(calculator.Divide(20, 4), 5);
		AssertEquals(calculator.Divide(60, 3), 20);
	}
};



int main()
{
	ExampleTest::Run();
}