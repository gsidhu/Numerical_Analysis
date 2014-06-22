// Gurjot Singh Sidhu
// BSc (H) Physics
// 30
// AIM: TO find a root of an algebraic equation using Secant Method

#include <iostream>
#include <conio.h>
#include <math.h>

#define f(x) p*x*x*x + q*x*x + r*x + s

void main()
{
	cout << "\tFinding a root of an algebraic equation using Secant Method" << endl;
	
	float a,b,c,p,q,r,s;
	double e = 0.0001;
	cout << "\nError limit = " << e << endl;

	cout << "\nInput the values of coefficients and the constant term: " << endl;
	cin >> p >> q >> r >> s;
	printf("The polynomial is: %gx^3 + %gx^2 + %gx + %g", p,q,r,s);
	
	cout << "\nInput the guess values of x_0 and x_1:" << endl;
	cin >> a >> b;

	while (abs(f(c)) > e)								// if f(x_2) lies within the error, x_2 is the root
	{
		c = b - (f(b) * (b-a)/(f(b)-f(a)));				// value of next estimate
		a = b;											// assign value of x_1 to x_0
		b = c;											// and x_2 to x_1
	}
	cout << "The root is " << c;
	getch();
} 