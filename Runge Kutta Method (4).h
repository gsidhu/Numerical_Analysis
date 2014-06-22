//Gurjot Singh Sidhu
//BSc (H) Physics
//30
//AIM: To solve an ordinary differential equation using Runge Kutta Method of IVth order

#include <iostream>
#include <conio.h>

double x_coeff[10]={0}, y_coeff[10]={0}, xy_coeff[20]={0}, f[10]={0}, y[10]={0}, x[10]={0};
double k1 = 0, k2 = 0, k3 = 0, k4 = 0, h;
int m_x, m_y, m_xy, cons, var;
	

double func(double X, double Y)
{
	double ans(0);
	for (int i = 0; i < m_x; i++)
	{
		ans = ans + x_coeff[i]*pow(X,i+1);
	}
	for (int i = 0; i < m_y; i++)
	{
		ans = ans + y_coeff[i]*pow(Y,i+1);
	}
	for (int i = 0; i < var; i++)
	{
		if (i < m_xy)
		{
			ans = ans + xy_coeff[i]*pow(X,i+1)*pow(Y,i+1);
		}
		else if (m_xy <= i <= 2*m_xy - 2)
		{
			ans = ans + xy_coeff[i]*X*pow(Y,i+1);
		}
		else
		{
			ans = ans + xy_coeff[i]*pow(X,i+1)*Y;
		}
	}
	ans = ans + cons;
	return ans;
}

void main()
{	
	start:
	cout << "\tRunge Kutta Method of IInd order for ordinary differential equation";

	char c;

	cout << "\nOrder of x terms: ";
	cin >> m_x;
	cout << "\nOrder of y terms: ";
	cin >> m_y;
	cout << "\nHighest power of xy mixed terms: ";
	cin >> m_xy;
	var = m_xy + 2*m_xy - 2;

	for (int i = 0; i < m_x; i++)									//input coeffs of x terms
	{
		cout << "Coefficient of x^" << i+1 << ": ";
		cin >> x_coeff[i];
	}
	cout << endl;
	for (int i = 0; i < m_y; i++)									//input coeffs of y terms
	{
		cout << "Coefficient of y^" << i+1 << ": ";
		cin >> y_coeff[i];
	}
	for (int i = 0; i < var; i++)									//input coeffs of xy terms
	{
		if (i < m_xy)
		{
			cout << "Coefficient of x^" << i+1 << "y^" << i+1 << ": ";
			cin >> xy_coeff[i];
		}
	
		else if (m_xy <= i <= 2*m_xy - 2)							//input coeffs of xy^ terms
		{
			cout << "Coefficient of xy^" << i+1 << ": ";
			cin >> xy_coeff[i+m_xy-1];
		}
		else														//input coeffs of x^y terms
		{
			cout << "Coefficient of x^" << i+1 << "y: ";
			cin >> xy_coeff[i+m_xy+1];
		}
	}
	cout << "\nConstant term: ";
	cin >> cons;

	printf("\nInput values of x_0, y_0 and h: ");
	cin >> x[0] >> y[0] >> h;

	for (int i = 1; i <= 10; i++)									//computing x values
	{
		x[i] = x[i-1] + h;
	}

	for (int k = 0; k < 6; k++)										//computing y values
	{
		k1 = func(x[k], y[k])*h;
		k2 = func(x[k]+h/2, y[k]+k1/2)*h;
		k3 = func(x[k]+h/2,y[k]+k2/2)*h;
		k4 = func(x[k]+h, y[k]+k3)*h;
		y[k+1] = y[k] + (k1 + 2*k2 + 2*k3 + k4)/6;
	}
	
	cout << "\nx\t\ty(x)";											//printing answer table
	for (int i = 0; i < 6; i++)
	{
		cout << "\n" << x[i] << "\t\t" << y[i];
	}

	cout << "\n\nTry again? (Y/N)\n";
	cin >> c;
	if (c == 'Y' || c == 'y')
	goto start;

	_getch();
 }