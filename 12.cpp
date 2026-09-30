#include <iostream>
using namespace std;

struct Nodo {
  char info;
  Nodo *ptrSgte;
};
void push(Nodo*&, char);
char pop(Nodo*&);
bool gruposBalanceados(char[]);

int main() {
  char palabra[50];
  cout << "Ingrese palabra: ";
  cin >> palabra;
  if(gruposBalanceados(palabra)) {
    cout << "Los grupos estan balanceados" << endl;
  }
  else {
    cout << "Los grupos estan desbalanceados" << endl;
  }
  return 0;
}

void push(Nodo *&ptrCima, char valor) {
  Nodo *ptrNuevo = new Nodo();
  ptrNuevo->info = valor;
  ptrNuevo->ptrSgte = ptrCima;
  ptrCima = ptrNuevo;
}
char pop(Nodo *&ptrCima) {
  char valorEliminado = ptrCima->info;
  Nodo *ptrTemp = ptrCima;
  ptrCima = ptrTemp->ptrSgte;
  delete ptrTemp;
  return valorEliminado;
}
bool gruposBalanceados(char palabra[]) {
  Nodo *Pila = NULL;
  for(int i = 0; palabra[i] != '\0'; i++) {
    if(palabra[i] == '{' || palabra[i] == '}' ||
       palabra[i] == '[' || palabra[i] == ']' ||
       palabra[i] == '(' || palabra[i] == ')') {
      push(Pila, palabra[i]);
    }
  }
  while(Pila != NULL) {
    char x = pop(Pila);
    char y = pop(Pila);
    if(!(y == '{' && x == '}') ||
       !(y == '[' && x == ']') ||
       !(y == '(' && x == ')')) {
      return false;
    }
  }
  return true;
}
