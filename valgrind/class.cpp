#include <iostream>

class Foo
{
public:
	Foo()
	: m_pInt(new int(-1))
	{

	}

	int createData(int d)
	{
		if (!m_pInt) {
			m_pInt = new int(d);
		}
		return *m_pInt;
	}

	~Foo()
	{
        // leaked if no delete
		if (m_pInt) {
			delete m_pInt;
			m_pInt = NULL;
		}
	}

private:
	int *m_pInt;
};

int main(int argc, char **agrv)
{
	Foo *pFoo = new Foo;
	if (pFoo) {
		std::cout << pFoo->createData(10) << std::endl;
		delete pFoo;
		pFoo = NULL;
	}
	
	return 0;
}
