#ifndef FOLDERS_H
#define FOLDERS_H
#include <string>
using namespace std;
class Folders {
	private:
		string name;
		string date;
		string user;
	public:
		Folders();
		Folders(string name, string date, string user);
		~Folders();
		void display() const;
};
#endif
