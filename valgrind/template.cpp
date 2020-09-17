#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

template<typename T>
void destroy(T obj)
{
	cout << "destroy(T) " << typeid(obj).name() << endl;
	if (obj) {
		delete obj; // destroy
		// obj = NULL; // invalid
	}
}

// matches prior
template<typename T>
void destroy(T* obj)
{
	cout << "destroy(T*) " << typeid(obj).name() << endl;
	if (obj) {
		delete obj; // destroy
		// obj = NULL; // invalid
	}
};

class Foo
{
};

int main(int argc, char **agrv)
{
	char *pc = new char;
	destroy(pc);
	if (pc) {
		cout << "!!wild!!" << endl;
		// destroy(pc);
	}
	cout << typeid(pc).name() << " " << sizeof(char) << endl;
	
	int *pi = new int;
	destroy(pi);
	cout << typeid(pi).name() << " " << sizeof(int) << endl;
	
	string *ps = new string;
	destroy(ps);
	cout << typeid(ps).name() << " " << sizeof(string) << endl;
	
	Foo *pFoo = new Foo;
	destroy(pFoo);
	cout << typeid(pFoo).name() << " " << sizeof(Foo) << endl;

	return 0;
}
