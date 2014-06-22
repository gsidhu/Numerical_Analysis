//Gurjot Singh Sidhu
//BSc. (H) Physics
//30
//AIM: Exponential Curve Fitting by method of least squares

#include <iostream>
#include <conio.h>
#include <math.h>

void main()
{
	start:
	double x[20]={0}, y[20]={0}, X(0), X2(0), Y(0), XY(0);
	double h(0), m(0), c(0);
	int n, choice;
	char ch;
	cout << "\n\t\tExponential Curve Fitting by method of least squares\n";
	cout << "Press 1 for equations of the form y = ae^bx\n";
	cout << "Press 2 for equations of the form y = bx^a\n";
	cout << "Press 3 for equations of the form y = ka^bx\n";
	cin >> choice;

	cout << "\nTotal number of data points: ";
	cin >> n;

	cout << "\nEnter all x,y data points - \n";
	for (int i(0); i < n; i++)
	{
		cin >> x[i] >> y[i];
	}

	switch(choice)
	{
	case(1) :	{	
					for (int i(0); i < n; i++)
						{
							X = X + x[i];
							X2 = X2 + pow(x[i],2);
							Y = Y + log(y[i]);
							XY = XY + x[i]*log(y[i]);
						}
					m = (n*XY - X*Y)/(n*X2 - X*X);
					c = (XY - X2*m)/X;
					cout << "The equation is y = " << exp(c) << "e^(" << m << "x)\n" << endl;
					break;
				}
	case(2) :	{
					for (int i(0); i < n; i++)
						{
							X = X + log(x[i]);
							X2 = X2 + pow(log(x[i]),2);
							Y = Y + log(y[i]);
							XY = XY + log(x[i])*log(y[i]);
						}
					m = (n*XY - X*Y)/(n*X2 - X*X);
					c = (XY - X2*m)/X;
					cout << "The equation is y = " << exp(c) << "x^(" << m << ")\n" << endl;
					break;
				}
	case(3) :	{	for (int i(0); i < n; i++)
						{
							X = X + x[i];
							X2 = X2 + pow(x[i],2);
							Y = Y + log(y[i]);
							XY = XY + x[i]*log(y[i]);
						}
					m = (n*XY - X*Y)/(n*X2 - X*X);
					c = (XY - X2*m)/X;
					cout << "The equation is y = (" << exp(c) << ")" << exp(m) << "^x\n" << endl;
					break;
				}
	}

	cout << "Try again? (Y/N)\n";
	cin >> ch;
	if (ch == 'Y' || ch == 'y')
		goto start;

	_getch();
}