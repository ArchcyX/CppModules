#ifndef	INTERN_HPP
#define	INTERN_HPP

class Intern {
public:
	MyClass();
	MyClass(MyClass &&) = default;
	MyClass(const MyClass &) = default;
	MyClass &operator=(MyClass &&) = default;
	MyClass &operator=(const MyClass &) = default;
	~MyClass();

private:
	
};

MyClass::MyClass() {
}

MyClass::~MyClass() {
}

#endif
