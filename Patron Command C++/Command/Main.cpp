#include<iostream>
#include<queue>
using namespace std;

// Command
class Operacion {
public:
	virtual void execute() = 0;
};

// Receiver
class Cuenta {
private:
	int id;
	double saldo;

public:
	Cuenta() {
		id = 0;
		saldo = 0;
	}

	Cuenta(int id, double saldo) {
		this->id = id;
		this->saldo = saldo;
	}

	void retirar(double monto) {
		saldo -= monto;
		cout << "[COMANDO RETIRAR] Cuenta: " << id << " Saldo: " << saldo;
	}

	void depositar(double monto) {
		saldo += monto;
		cout << "[COMANDO DEPOSITAR] Cuenta: " << id << " Saldo: " << saldo;
	}
};

class Invoker {
private:
	queue<Operacion*> operaciones;

public:
	void recibirOperacion(Operacion* operacion) {
		operaciones.push(operacion);
	}

	void realizarOperaciones() {
		while (!operaciones.empty()) {
			operaciones.front()->execute();
			cout << endl;
			operaciones.pop();
		}
	}
};

// Command 2
class Depositar : public Operacion {
private:
	Cuenta cuenta;
	double monto;

public:
	Depositar(Cuenta cuenta, double monto) {
		this->cuenta = cuenta;
		this->monto = monto;
	}

	void execute() {
		cuenta.depositar(monto);
	}
};

// Command 1
class Retirar : public Operacion {
private:
	Cuenta cuenta;
	double monto;

public:
	Retirar(Cuenta cuenta, double monto) {
		this->cuenta = cuenta;
		this->monto = monto;
	}

	void execute() {
		cuenta.retirar(monto);
	}
};

int main() {
	Cuenta cuenta(1, 500);

	Depositar* depositarOperacion = new Depositar(cuenta, 100);
	Retirar* retirarOperacion = new Retirar(cuenta, 300);

	Invoker invoker;

	invoker.recibirOperacion(depositarOperacion);
	invoker.recibirOperacion(retirarOperacion);

	invoker.realizarOperaciones();
	cin.get();
	return 0;
}



