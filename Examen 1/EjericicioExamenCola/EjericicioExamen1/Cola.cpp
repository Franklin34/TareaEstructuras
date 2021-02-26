#include "cola.h"

Cola::Cola() : head{ 0 }, tail{ 0 }, cola{ 0 }, cantidad{ 0 }{}

Cola::~Cola() {
}

void Cola::enqueue(const int elemento) {
	if (tail == MAX - 1)
		tail = 0;
	else
		++tail;
	if (tail == head)
		return;
	cola[tail] = elemento;
	cantidad++;
}

int Cola::dequeue() {
	if (estaVacia())
		return -1;

	if (head == MAX - 1)
		head = 0;
	else
		++head;
	cantidad--;
	return cola[head];
	
}
int Cola::siguiente() {
	if (estaVacia())
		return -1;

	int tmp;
	if (head == MAX - 1)
		tmp = 0;
	else
		tmp = head + 1;

	return cola[tmp];
}

bool Cola::estaVacia() {
	return (head == tail);
}

int Cola::size()
{
	return cantidad;
}
