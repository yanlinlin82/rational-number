#include "rational.h"
using namespace std;
using namespace math;

int main()
{
	cout << "0      = " << rational(0) << endl;
	cout << "1      = " << rational(1) << endl;
	cout << "2 / 1  = " << rational(2, 1) << endl;
	cout << "1 / 2  = " << rational(1, 2) << endl;
	cout << "5 / 2  = " << rational(5, 2) << endl;
	cout << "2 / 5  = " << rational(2, 5) << endl;
	cout << "1 / 3  = " << rational(1, 3) << endl;
	cout << "3 / 7  = " << rational(3, 7) << endl;
	cout << "22 / 7 = " << rational(22, 7) << endl;
	cout << "1 / 10 = " << rational(1, 10) << endl;
	cout << "1 / 10 = (binary) " << rational(1, 10).to_string<2>() << endl;
	return 0;
}
