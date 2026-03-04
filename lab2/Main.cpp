#include "Folders.h"
#include "Files.h"
#include "User.h"

int main() {
	Folders f1;
	Folders f2("Homework2", "03.03.2026", "Student");

	Files fi1;
	Files fi2("Homework_OOP2", "Homework2", "Student");

	User u1;
	User u2("Igor Aheienko", "Program Ingeneering", "143a");

	f1.display();
	f2.display();

	fi1.display();
	fi2.display();

	u1.display();
	u2.display();

	return 0;
}