#ifndef FILES_H
#define FILES_H
#include <string>
using namespace std;
class Files {
private:
	string name;
	string folder;
	string user;
public:
	Files();
	Files(string name, string folder, string user);
	~Files();
	void display() const;
};
#endif