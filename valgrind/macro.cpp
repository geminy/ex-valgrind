#include <iostream>

// macro is good
// destroy memory
// no wild pointer
#define DESTROY(ptr) \
	if (ptr) { \
		delete ptr; \
		ptr = NULL; \
	}

#define DESTROY2(ptr) \
	if (ptr) { \
		delete[] ptr; \
		ptr = NULL; \
	}

void foo()
{
	int *p = new int(10);
	DESTROY(p)
	if (p) {
		DESTROY(p)
	}

	int *pArray = new int[10];
	DESTROY2(pArray)
	if (pArray) {
		DESTROY2(pArray)
	}
}

int main(int argc, char **agrv)
{
	foo();
	
	return 0;
}
