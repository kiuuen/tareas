/*
 * EJERCICIO 10C: Clase CuentaBancaria (Completa)
 * 
 * TAREA:
 * Crea una clase CuentaBancaria con:
 * - Atributos: titular, número de cuenta, saldo, historial de transacciones (vector)
 * - Constructor que inicialice titular y número (saldo en 0)
 * - Métodos para:
 *   * Depositar dinero (validar monto positivo)
 *   * Retirar dinero (validar fondos suficientes)
 *   * Transferir a otra cuenta (pasar por referencia con &)
 *   * Consultar saldo
 *   * Mostrar historial de transacciones
 *   * Aplicar interés (por ejemplo, 3% anual)
 * 
 * PISTA: Puedes crear una struct Transaccion para el historial con:
 *   - tipo (string): "Depósito", "Retiro", "Transferencia"
 *   - monto (double)
 *   - saldoResultante (double)
 * 
 * EJEMPLO:
 * CuentaBancaria cuenta("Ana López", "001-12345");
 * cuenta.depositar(1000);
 * cuenta.retirar(300);
 * cuenta.mostrarHistorial();
 */

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>  // para fixed y setprecision

struct Transaccion {
    double monto;
    double saldo;
    std::string tipo;
    std::string cuentaTransferida;
    Transaccion(double montoW = 0, double saldoW = 0, std::string tipoW = "null") : monto(montoW), saldo(saldoW), tipo(tipoW){};
};
std::ostream& operator<<(std::ostream& os, const Transaccion& transaccion) {
    if (transaccion.tipo == "TRANSFERENCIA") {
        os << "Tipo: " << transaccion.tipo 
        << ",Monto: " << transaccion.monto
        << ",Saldo: " << transaccion.saldo
        << ",Transferencia a: " << transaccion.cuentaTransferida;
        return os;
        } else {
        os << "Tipo: " << transaccion.tipo 
        << ",Monto: " << transaccion.monto
        << ",Saldo: " << transaccion.saldo;
        return os;
    }
}

class CuentaBancaria {
    private:
        std::string titular;  
        int numeroCuenta;
        double saldo;
        std::vector<Transaccion> historialTransacciones;
    public:
        void depositar(double cantidadDepositar) {
            if (cantidadDepositar > 0) {
                Transaccion newTransaccion(cantidadDepositar, this->saldo+=cantidadDepositar, "DEPOSITO");
                setSaldo(this->saldo += cantidadDepositar);
                historialTransacciones.push_back(newTransaccion);
                std::cout << "Deposito exitoso de: " << cantidadDepositar << std::endl;
            }
        }
        void retirar(double cantidadRetirar) {
            if (cantidadRetirar > 0 && cantidadRetirar <= this->saldo) {
                Transaccion newTransaccion(cantidadRetirar, this->saldo-=cantidadRetirar, "RETIRO");
                setSaldo(this->saldo - cantidadRetirar);
                historialTransacciones.push_back(newTransaccion);
                std::cout << "Retiro exitoso de: " << cantidadRetirar << std::endl;
            }
        }
        void transferencia(CuentaBancaria& cuentaTransferir, double montoTransferir) {
            if (montoTransferir > 0 && cuentaTransferir.titular != "null") {
                Transaccion newTransaccion(montoTransferir, this->saldo-=montoTransferir, "TRANSFERENCIA");
                cuentaTransferir.setSaldo(this->saldo+=montoTransferir);
                setSaldo(this->saldo - montoTransferir);
                newTransaccion.cuentaTransferida = cuentaTransferir.getTitular();
                historialTransacciones.push_back(newTransaccion);
                std::cout << "Transferencia exitosa de: " << montoTransferir << " a la cuenta de: " << cuentaTransferir.getTitular() << std::endl;
            }
        }
        void consultarSaldo() {
            std::cout << "El saldo es de: " << this->saldo << std::endl;
        }
        void mostrarHistorialTransacciones() {
            std::cout << "----------Historial de transacciones-------" << std::endl;
            int n = 1;
            for (const auto& c : historialTransacciones) {
                std::cout << n << ") " << c << std::endl;
                n++;
            }
        }
        void setSaldo(double saldoSet) {
            this->saldo = saldoSet;
        }
        std::string getTitular() {
            return this->titular;
        }
        CuentaBancaria(std::string titularW = "Blank", double numeroCuentaW = 0) : titular(titularW), numeroCuenta(numeroCuentaW){};
};

int main() {
  CuentaBancaria cuenta1("Daniel Alcantar", 12938);
  cuenta1.depositar(100);
  cuenta1.retirar(59);
  CuentaBancaria cuenta2("Michi", 192323);
  cuenta1.transferencia(cuenta2, 10);
  cuenta1.depositar(100);
  cuenta1.mostrarHistorialTransacciones();
  cuenta1.consultarSaldo();
  cuenta1.depositar(-100);
  cuenta1.retirar(1000);
  cuenta1.transferencia(cuenta2, 100000);
  return 0;
}