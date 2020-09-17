#include <iostream>

void foo()
{
	int *p = new int(10); // leaked memory 4

	int *pArray = new int[10]; // leaked memory 4*10
	pArray[10] = 10; // invalid write
}

int main(int argc, char **agrv)
{
	foo();
	
	return 0;
}
