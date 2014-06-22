// Gurjot Singh Sidhu
// BSc (H) Physics
// 30
// AIM: To find the smallest root of an algebraic equation using Newton-Rahpson Method

#include <iostream>
#include <conio.h>

#define f(x) p[0]*x*x*x*x*x*x*x*x*x*x + p[1]*x*x*x*x*x*x*x*x*x + p[2]*x*x*x*x*x*x*x*x + p[3]*x*x*x*x*x*x*x + p[4]*x*x*x*x*x*x + p[5]*x*x*x*x*x + p[6]*x*x*x*x + p[7]*x*x*x + p[8]*x*x + p[9]*x + p[10]
#define g(x) 10*p[0]*x*x*x*x*x*x*x*x*x + 9*p[1]*x*x*x*x*x*x*x*x + 8*p[2]*x*x*x*x*x*x*x + 7*p[3]*x*x*x*x*x*x + 6*p[4]*x*x*x*x*x + 5*p[5]*x*x*x*x + 4*p[6]*x*x*x + 3*p[7]*x*x + 2*p[8]*x + p[9]

void main()
{
	printf("\t\t\tNewton Raphson Method");
	printf("\nError limit = 0.0001");

	int N;
	float p[50] = {0}, fa, fx;
	float a, x1(0), x2(0), derivative, x(0);

	cout << "\nEnter the degree of polynomial [< 10]: ";
	cin >> N;

	cout << "\nEnter the constant term and then the coefficients of the x terms in increasing order: " << endl;
	for (int i = 10; i > 9-N; i--)
	{
		cin >> p[i];
	}
	
	input:
	printf("\nInput a guess value for the root of the equation: ");
	cin >> x1;

	x2 = x1 + 1;
	if (f(x1)*f(x2) > 0)
	{
		x1 = x2;
		goto input;
	}

	printf("\n\tx_0\t\tx_1\t\tderivative(x1)\t\tf(x1)");
	printf("\n_____________________________________________________");
		
	for (int var(0); var < 15 ;var++)
	{
		fx = f(x1);
		derivative = g(x1);
		x = x1 - (fx/derivative);
		
		printf("\n\t%f\t%f\t%f\t%f", x1, x, derivative, fx);
		
		if (fabs(x - x1) < 0.0001)
		{
			break;
		}
		x1 = x;
	}

	printf("\nSmallest Positive root is %f", x);
	getch();
}