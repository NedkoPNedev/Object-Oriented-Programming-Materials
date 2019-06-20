#include <iostream>
#include "human.h"
#include "student.h"
using namespace std;

int main() {
	{
		Human h("pesho");
		Student st("gosho", "cambridge");
	}
	cout << endl;
	Human* h = new Student("sasho", "oxford");
	delete h;
	system("pause");
}


