#ifndef COLA_H
#define COLA_H

#define MAX 20

class Cola {
public:
	Cola();
	~Cola();
	void enqueue(const int);
	int dequeue();
	int siguiente();
	bool estaVacia();
	int size();
private:
	int cola[MAX];
	short int head; //salida
	short int tail;  //entrada
	int tam;
	int cantidad;
};

#endif

