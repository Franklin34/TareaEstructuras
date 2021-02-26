#ifndef STACK_H
#define STACK_H

#define MAX 20

class Stack {
public:
	Stack();
	~Stack();
	void push(const int);
	int pop();
	int peek();
	bool estaVacia();
private:
	unsigned int pila[MAX];
	int top;

	
	bool estaLlena();
};

#endif

