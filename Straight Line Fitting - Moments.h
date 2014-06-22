//Gurjot Singh Sidhu
//BSc. (H) Physics
//30
//AIM: Straight Line Fitting by method of moments

#include <iostream>
#include <conio.h>
#include <math.h>

void main()
{
	start:
	double x[20]={0}, y[20]={0}, Y(0), XY(0);
	double B(0), A(0), h(0), m(0), c(0), sq(0), qb(0);
	int n;
	char ch;
	cout << "\n\t\tStraight Line Fitting by method of moments\n";
	cout << "Equations are of the form y = ax + b\n";
	cout << "\nTotal number of data points: ";
	cin >> n;

	cout << "\nEnter all x,y data points - \n";
	for (int i(0); i < n; i++)
	{
		cin >> x[i] >> y[i];
		Y = Y + y[i];
		XY = XY + y[i]*x[i];
	}

	h = x[1] - x[0];
	A = x[0] - h/2;
	B = x[n-1] + h/2;
	sq = (pow(B,2) - pow(A,2))/2;
	qb = (pow(B,3) - pow(A,3))/3;

	m = (Y*sq - XY*(B-A))/(pow(sq,2)-(qb*(B-A)));
	c = (Y - sq*m)/(B-A);

	cout << "\n\nThe required equation is y = " << m << "x + " << c << endl;
	cout << "\n\nTry again? (Y/N)\n";
	cin >> ch;
	if (ch == 'Y' || ch == 'y')
	goto start;

	_getch();
}