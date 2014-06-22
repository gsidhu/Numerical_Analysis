//Gurjot Singh Sidhu
//BSc. (H) Physics
//30
//AIM: Straight Line Fitting by method of group averages

#include <iostream>
#include <conio.h>
#include <math.h>

void main()
{
	start:
	double x[20]={0}, y[20]={0}, X1(0), X2(0), Y1(0), Y2(0), a(0), b(0);
	int n;
	char c;
	cout << "\n\t\tStraight Line Fitting by method of group averages\n";
	cout << "Equations are of the form y = ax + b\n";
	cout << "\nTotal number of data points: ";
	cin >> n;

	cout << "\nEnter all x,y data points - \n";
	for (int i(0); i < n; i++)
	{
		cin >> x[i] >> y[i];
	}
	
	for (int i(0); i < n/2; i++)
	{
		X1 = X1 + x[i];
		Y1 = Y1 + y[i];
		X2 = X2 + x[n-i-1];
		Y2 = Y2 + y[n-i-1];
	}
	
	if (n%2 == 0)
	{
		X1 = X1/(n/2);
		X2 = X2/(n/2);
		Y1 = Y1/(n/2);
		Y2 = Y2/(n/2);
	}
	else
	{
		X1 = (X1+x[n/2])/(n/2 + 1);
		X2 = X2/(n/2);
		Y1 = (Y1+y[n/2])/(n/2 + 1);
		Y2 = Y2/(n/2);
	}

	a = (Y2 - Y1)/(X2 - X1);
	b = Y1 - (X1*a);
	
	cout << "\n\nThe required equation is y = " << a << "x + " << b << endl;
	cout << "\n\nTry again? (Y/N)\n";
	cin >> c;
	if (c == 'Y' || c == 'y')
	goto start;

	_getch();
}