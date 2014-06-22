/* Gurjot Singh Sidhu
BSc (H) Physics
30	
Aim: To find one root of a cubic polynomial using bisection method */

#include <iostream>
#include <conio.h>

#define f(x) p*x*x*x+ q*x*x + r*x + s

void main()
{
	cout << "\tFinding one root of a cubic polynomial using bisection method" << endl;
	int count(0);
	double a(0),b(0),c(0),p,q,r,s;
	double e = 0.000001, fa, fc;

	cout << "\nError limit = 0.00001" << endl;

	cout << "\nEnter the coefficients of x and the constant term: " << endl;
	cin >> p >> q >> r >> s;
	cout << "The polynomial is f(x) = " << p << "x^3 + " << q << "x^2 + " << r << "x + " << s << endl;

	input:
	cout << "\nEnter the guess values a and b: " << endl;
	cin >> a >> b;

	if (f(a)*f(b) > 0)							// The root lies only in intervals where f(a) and f(b) are of opposite signs
	{
		cout << "\nThe root does not exist in this interval. \n" << endl;
		goto input;
	}
	
	while (count < 20)
	{
		c = (a+b)/2.0;							// c is the midpoint of a and b
		fa = f(a);
		fc = f(c);

		if (fa*fc < 0)							// if f(a) and f(c) are of opposite signs, assign value of c to b
		{
			b = c;
		}
		else									// if f(a) and f(c) are of same sign, assign value of c to a
		{
			a = c;
		}	
		
		if (abs(b-a) < e)						// if the difference of b and a is within the error limit, c is the root
			{
				break;
			}
		count++;
	}
	
	cout << "\nThe required root is " << c << endl;
	_getch();
}