#include <iostream>
#include <cstring>
#include <fstream>
#include <exception>

using namespace std;

//&a {a++;} promenq i stoinostta na a v main!
//int& sum(int& a, int& b) {
//	
//	int sum = a + b;
//	return sum;
//}

//int sum(int a, int b) {
//	return a + b;
//}
//
//int prod(int a, int b) {
//	return a * b;
//}
//
////f-ii ot po-visok red
//int myFunc(int a, int b, int(*func)(int, int)) {
//	return func(a, b);
//}

//exceptions!
double division(double a, double b) {
	//throw, try, catch
	if (b == 0) {
		throw invalid_argument("Invalid argument! Division by zero!"); //"Invalid argument!"; //throw 5;
	}
	
	return a / b;
}

int main() {
	//int a = 5, b = 10;
	//int c = sum(a, b);
	//cout << c << endl;

	//cout << myFunc(a, b, sum) << endl;
	//cout << myFunc(a, b, prod) << endl;

	//sum(5,6) - 5 i 6 sa vremenni obekti, sled izpolzvaneto im ne mojem da gi viknem nikude

	//exceptions!
	double x = 5;
	double y = 0;
	double z = 0;

	try {
		z = division(x, y);
		cout << z << endl;
	}
	catch (invalid_argument msg) {
		cerr << msg.what() << endl;
	}
	catch (exception exc) {
		cout << "Other exception." << endl;
	}
	/*catch (const char* msg) { //first comment in the throw
		cout << msg << endl;
	}*/
	/*catch (int e) { //third comment in the throw
		cout << e << endl;
	}*/
	//ne dobra praktika, no mojem da napishe i:
	//catch (...) {
	//	cout << "bla bla" << endl;//no po dobre, ne!
	//}

	system("pause");
	return 0;
}