#include "rational.h"
#include "unit_test.h"
using namespace std;
using namespace math;

void test_fraction()
{
	unit(fraction);
	unit_assert(rational(0).to_fraction() == "0");
	unit_assert(rational(0, 10).to_fraction() == "0");
	unit_assert(rational(4, 2).to_fraction() == "2");
	unit_assert(rational(10, 4).to_fraction() == "5/2");
	unit_assert(rational(0, 0).to_fraction() == "NA");
	unit_assert(rational(1, 0).to_fraction() == "Inf");
}

void test_decimal()
{
	unit(decimal);
	unit_assert(rational( 0    ).to_decimal() == "0");
	unit_assert(rational( 1    ).to_decimal() == "1");
	unit_assert(rational( 0    ).to_decimal() == "0");
	unit_assert(rational( 1    ).to_decimal() == "1");
	unit_assert(rational( 2,  1).to_decimal() == "2");
	unit_assert(rational( 1,  2).to_decimal() == "0.5");
	unit_assert(rational( 5,  2).to_decimal() == "2.5");
	unit_assert(rational( 2,  5).to_decimal() == "0.4");
	unit_assert(rational( 1,  3).to_decimal() == "0.(3)...");
	unit_assert(rational( 3,  7).to_decimal() == "0.(428571)...");
	unit_assert(rational(22,  7).to_decimal() == "3.(142857)...");
	unit_assert(rational( 1, 10).to_decimal() == "0.1");
	unit_assert(rational( 0,  0).to_decimal() == "NA");
	unit_assert(rational( 1,  0).to_decimal() == "Inf");
}

void test_binary_decimal()
{
	unit(binary_decimal);
	unit_assert(rational(1, 10).to_decimal<2>() == "0.0(0011)...");
}

void test_add()
{
	unit(add);
	unit_assert(rational(1) + rational(2) == rational(3));
	unit_assert(rational(1, 10) + rational(1, 5) == rational(3, 10));
}

int main()
{
	test_fraction();
	test_decimal();
	test_binary_decimal();
	test_add();
	return 0;
}
