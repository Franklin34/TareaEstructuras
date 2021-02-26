#include "ControlUsuario.h"

void ControlUsuario::menu()
{
	Cola_Prioridad<Estudiante> cola;

	std::cout << "============================ COLA MAXIMOS ==================================" << std::endl << std::endl;

	Estudiante est1("Franklin", "208150490", 19);
	Estudiante est2("Sofia", "207856932", 20);
	Estudiante est3("Gabriela", "207850865", 21);
	Estudiante est4("Jose Calvo", "205890658", 36);

	std::cout << "============================ SE INSERTAN LOS ESTUDIANTES A LA COLA ==================================" << std::endl << '\n';

	std::cout << "Estudiante 1: " << '\n';
	std::cout << est1.toString() << '\n' << '\n';

	std::cout << "Estudiante 2: " << '\n';
	std::cout << est2.toString() << '\n' << '\n';

	std::cout << "Estudiante 3: " << '\n';
	std::cout << est3.toString() << '\n' << '\n';

	std::cout << "Estudiante 4: " << '\n';
	std::cout << est4.toString() << '\n' << '\n';

	cola.Agregar(est1);
	cola.Agregar(est2);
	cola.Agregar(est3);
	cola.Agregar(est4);

	std::cout << "============================ ESTUDIANTE EN EL TOPE DE LA COLA ==================================" << std::endl << '\n';

	std::cout << cola.ExtraerMax().toString() << '\n' << '\n';

	std::cout << "============================ SE ELIMINAN LOS ESTUDIANTES ==================================" << std::endl << '\n';

	std::cout << "Se elimina el estudiante: ";
	std::cout << cola.pop().toString() << '\n';

	std::cout << "Se elimina el estudiante: ";
	std::cout << cola.pop().toString() << '\n';

	std::cout << "Se elimina el estudiante: ";
	std::cout << cola.pop().toString() << '\n';

	std::cout << "Se elimina el estudiante: ";
	std::cout << cola.pop().toString() << '\n';



	std::cout << "=================================== FIN DE COLA DE MAXIMOS ==================================" << "\n";

	system("pause");
	system("cls");

	Cola_Prioridad<Estudiante> cola2(true);

	std::cout << "============================ COLA DE MINIMOS ==================================" << std::endl << std::endl;

	Estudiante est12("Sofia", "208160780", 19);
	Estudiante est32("Keylor", "205890411", 10);
	Estudiante est22("Franklin", "205690231", 20);
	
	Estudiante est42("Jose Calvo", "205680123", 35);

	std::cout << "============================ SE INSERTAN LOS ESTUDIANTES A LA COLA ==================================" << std::endl << '\n';

	std::cout << "Estudiante 1: " << '\n';
	std::cout << est12.toString() << '\n' << '\n';

	std::cout << "Estudiante 2: " << '\n';
	std::cout << est22.toString() << '\n' << '\n';

	std::cout << "Estudiante 3: " << '\n';
	std::cout << est32.toString() << '\n' << '\n';

	std::cout << "Estudiante 4: " << '\n';
	std::cout << est42.toString() << '\n' << '\n';

	cola2.Agregar(est12);
	cola2.Agregar(est32);
	cola2.Agregar(est22);
	cola2.Agregar(est42);

	std::cout << "============================ ESTUDIANTE EN EL TOPE DE LA COLA ==================================" << std::endl << '\n';

	std::cout << cola2.ExtraerMax().toString() << '\n' << '\n';

	std::cout << "============================ SE ELIMINAN LOS ESTUDIANTES ==================================" << std::endl << '\n';

	Cola_Prioridad<Estudiante> cola3(cola2);

	std::cout << "Se elimina el estudiante: ";
	std::cout << cola2.pop().toString() << '\n';

	std::cout << "Se elimina el estudiante: ";
	std::cout << cola2.pop().toString() << '\n';

	std::cout << "Se elimina el estudiante: ";
	std::cout << cola2.pop().toString() << '\n';

	std::cout << "Se elimina el estudiante: ";
	std::cout << cola2.pop().toString() << '\n';



	std::cout << "=================================== FIN DE COLA DE MINIMOS ==================================" << "\n";

	system("pause");
	system("cls");


	std::cout << "============================ PRUEBA CONSTRUCTOR DE COPIA ==================================" << std::endl << std::endl;


	std::cout << "============================ ESTUDIANTE EN EL TOPE DE LA COLA ==================================" << std::endl << '\n';

	std::cout << cola3.ExtraerMax().toString() << '\n' << '\n';

	std::cout << "============================ SE ELIMINAN LOS ESTUDIANTES ==================================" << std::endl << '\n';

	std::cout << "Se elimina el estudiante: ";
	std::cout << cola3.pop().toString() << '\n';

	std::cout << "Se elimina el estudiante: ";
	std::cout << cola3.pop().toString() << '\n';

	std::cout << "Se elimina el estudiante: ";
	std::cout << cola3.pop().toString() << '\n';

	std::cout << "Se elimina el estudiante: ";
	std::cout << cola3.pop().toString() << '\n';



	std::cout << "=================================== FIN DE PRUEBA ==================================" << "\n" << "\n";

	system("pause");
	system("cls");

	std::cout << "=================================== COLA HEAP A PARTIR DE UNA LISTA DOBLE ==================================" << "\n";

	ListaDoble<Estudiante> lista;

	lista.Insertar(est1);
	lista.Insertar(est2);
	lista.Insertar(est3);
	lista.Insertar(est4);

	Cola_Prioridad<Estudiante>cola4(lista);

	std::cout << "Se elimina el estudiante: ";
	std::cout << cola4.pop().toString() << '\n';

	std::cout << "Se elimina el estudiante: ";
	std::cout << cola4.pop().toString() << '\n';

	std::cout << "Se elimina el estudiante: ";
	std::cout << cola4.pop().toString() << '\n';

	std::cout << "Se elimina el estudiante: ";
	std::cout << cola4.pop().toString() << '\n';

	std::cout << "=================================== FIN DE PRUEBA HEAP A PARTIR DE LISTA DOBLE ==================================" << "\n" << "\n";

}

