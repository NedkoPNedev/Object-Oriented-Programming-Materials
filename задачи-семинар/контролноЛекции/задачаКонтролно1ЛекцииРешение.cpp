/*#include <iostream>
using namespace std;

struct Book {
    char name[31];
    char* author;
};

struct Student {
    int fn;
    Book* studentBook;
};

int main() {
    Book book = {"Some name", "Gosho Petrov"};
    Student student = {81650, &book};

    Student* studentsArray[30];
    studentsArray[0] = &student;

    Book bk;
    cin.getline(bk.name, 30);
    bk.author = "Author Name";

    Student student2 = {12345, &bk};

    cout << studentsArray[0]->studentBook->author << endl;

    return 0;
}
*/
#include <iostream>
using namespace std;
struct book {
	char name[30];
	char* author;
};

struct student {
	int fn;
	const book* studentBook;
};

int main() {
	student* studentList[30];
	student st;
	st.fn = 12345;
	char bookName[30];
	char* author="Author name";
	studentList[0] = &st;
	book bk;
	cin >> bk.name;
	st.studentBook = &bk;

	return 0;
}
