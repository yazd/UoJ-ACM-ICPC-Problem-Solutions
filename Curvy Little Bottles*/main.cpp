#include <iostream>
#include <vector>

#include <cmath>
#include <iomanip>

using namespace std;

struct Polynomial {
	double* coefficients;
	unsigned int length;	
};

void printPoly(Polynomial poly) {

	for (int i = 0; i < poly.length; i++) {
		if (poly.coefficients[i] == 0) continue;
		cout << poly.coefficients[i];
		cout << " x^" << i << " + ";
	}
	
	cout << endl;
	
}

Polynomial* integrate(Polynomial poly) {
	
	Polynomial* integral = new Polynomial;
	integral->coefficients = new double[poly.length + 1];
	
	for (int i = poly.length; i > 0; i--) {
		integral->coefficients[i] = poly.coefficients[i-1] / (double) i;
	}
	
	integral->coefficients[0] = 0;
	integral->length = poly.length + 1;
	
	return integral;
	
}

Polynomial* revVolume(Polynomial shape) {
	
	Polynomial* y_2 = new Polynomial;
	y_2->coefficients = new double[shape.length * 2 - 1];
	
	y_2->length = shape.length * 2 - 1;
	
	for (int i = 0; i < y_2->length; i++)
		y_2->coefficients[i] = 0;
		
	//printPoly(shape);

	for (int i = 0; i < shape.length; i++) {
		for (int j = 0; j < shape.length; j++) {
			//cout << "Adding to X^" << (i + j) << ": " << shape.coefficients[i] * shape.coefficients[j] << endl;
			y_2->coefficients[i + j] += shape.coefficients[i] * shape.coefficients[j] * M_PI;
		}
	}
	
	//cout << "y^2 = ";
	//printPoly(*y_2);
	
	Polynomial* result = integrate(*y_2);
	//cout << "integral = ";
	//printPoly(*result);
			
	return result;
	
}

double eval(Polynomial* poly, double x) {

	double val = poly->coefficients[0];
	
	for (int i = 1; i < poly->length; i++)
		val += poly->coefficients[i] * pow(x, i);
	
	return val;
	
}

int main() {
	
	Polynomial shape;
		
	int casenumber = 0;
	
	while ( !cin.eof() ) {
	
		cin >> shape.length;
		if (cin.eof()) break;
		
		shape.coefficients = new double[11];
		
		for (int i = 10; i > shape.length; i--) {
			shape.coefficients[i] = 0;
		}
			
		for (int i = shape.length; i >= 0; i--)
			cin >> shape.coefficients[shape.length - i];
		
		shape.length = 11;
		
		//printPoly(shape);
		
		double xlow, xhigh;			
		cin >> xlow >> xhigh;
				
		int inc;
		cin >> inc;
		
		Polynomial* volume = revVolume(shape);		
		volume->coefficients[0] = -eval(volume, xlow);
				
		double totalVolume = eval(volume, xhigh);
		//cout << totalVolume << endl;
		
		int numberOfPoints = floor(totalVolume / inc);
		
		if (numberOfPoints == 0) {
			cout << "Case " << ++casenumber << ": " << totalVolume << endl;
			cout << "insufficient volume" << endl;
			continue;
		}
		
		if (numberOfPoints > 8) numberOfPoints = 8;
		
		double target = inc;
				
		double lowBound = xlow;
		double uppBound = xhigh - 0.10;
		
		vector <double> pos;
		
		double nextTestPoint = (lowBound + uppBound) / 2.0;
		
		while (true) {
				
			double vol = eval(volume, nextTestPoint);

			double thisError = abs(target - eval(volume, nextTestPoint));

			if (thisError < 1.0e-12) {
			
				double nextError = abs(target - eval(volume, nextTestPoint + 0.01));
				double prevError = abs(target - eval(volume, nextTestPoint - 0.01));

				if (prevError < nextError) {
					if (prevError < thisError)
						nextTestPoint = nextTestPoint - 0.01;
					
				} else {
					if (nextError < thisError)
						nextTestPoint = nextTestPoint + 0.01;
				
				}

				if ((pos.size() > 0) && (abs(nextTestPoint - pos[pos.size() - 1]) < 0.05)) {;
					while (true) {}
				}

				pos.push_back(nextTestPoint);
				target += inc;
			
				if (pos.size() == numberOfPoints) break;
				
				lowBound = nextTestPoint;
				uppBound = xhigh;
				nextTestPoint = (lowBound + uppBound) / 2.0;
				
			} else {
				
				if (vol > target)
					uppBound = nextTestPoint;
				else
					lowBound = nextTestPoint;
				
				nextTestPoint = (lowBound + uppBound) / 2.0;
			
			}
			
		}		
		
		cout << setiosflags(ios::fixed) << setprecision(2);

		cout << "Case " << ++casenumber << ": " << totalVolume << endl;
		
		for (int i = 0; i < pos.size() - 1; i++)
			cout << (pos[i] - xlow) << " ";
		
		cout << (pos[pos.size()-1] - xlow);
		cout << endl;

	}
	
	return 0;
}
