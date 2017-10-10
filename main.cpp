#include <iostream>
#include <cstring>
#include <string>
#include "fstream"
#include <sstream>

using namespace std;

int main() {

	//stringstream - stringove v potoci
/*string str("first second third");
stringstream ss(str);

string s;

ss >> s;
ss >> s;
ss >> s;
cout << s;
cout << '\n';*/
//za chisla
/*string str("250 800 16");
stringstream ss(str);

int num;

ss >> num;
ss >> num;
ss >> num;
cout << num;
cout << '\n';*/

	const unsigned MAX_SIZE = 1000;
	char buff[MAX_SIZE];

	//ifstream myfile("file.txt"); //za chetene ot faila, ios - flagove
	// //ios::ate - at the end, pri zapisvane zapochva ot kraq; ios::in - input, ios::out - output; ios::app - kato ate, no vs operacii se sluchvat samo v kraq
	////pri ate samo 1ta oper se sluchva v kraq, drugite mogat navsqkude drugade; ios::binary - chetene na dvoichen fail; ios::trunc - ;
	//// | neshto kato ili, no se izvurshva po bitovo.
	//myfile >> buff;
	//cout << buff;
	//myfile.close(); //zaduljitelno zatvarqme faila!
	////ofstream myfile("file.txt"); //za pisane ot faila 


	ofstream fo("myFile.txt", ios::out | ios::trunc);
	fo << "simple example." << '\n';
	fo << "second row." << '\n';
	fo << "third row." << '\n';
	fo.close();

	ifstream fi("myFile.txt", ios::in);
	//fi >> buff;
	fi.getline(buff, MAX_SIZE);
	cout << buff << endl;
	fi.close();

	system("pause");
	return 0;
}