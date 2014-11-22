#include<iostream>
#include<stdlib.h>

#include "nodo.h"
using namespace std;

class Lista{
	private:
		Nodo *inicio;
		Nodo *fin;
		int tamano;
	public:
		void setInicio(Nodo *i);
		void setFin(Nodo *f);
		void setTamano(int t);
		Nodo *getInicio();
		Nodo *getFin();
		int getTamano();
		Lista();
		int insertarNodo(Nodo *nodo);
		void mostrarLista();
		Nodo *buscarNodo(bool c,bool z,bool o,bool g,bool b);
		int eliminarNodo(bool c,bool z,bool o,bool g,bool b);

};

Lista::Lista(){
	inicio=NULL;
	fin=NULL;
	tamano=0;
}

void Lista::setInicio(Nodo *i){
	inicio=i;
}

void Lista::setFin(Nodo *f){
	fin=f;
}

void Lista::setTamano(int a){
	tamano=a;
}

Nodo *Lista::getInicio(){
	return inicio;
}

Nodo *Lista::getFin(){
	return fin;
}

int Lista::getTamano(){
	return tamano;
}

int Lista::insertarNodo(Nodo *nodo){

	if(inicio == NULL){
		nodo->setSiguiente(NULL);
		nodo->setAnterior(NULL);
		inicio=nodo;
		fin=nodo;
		tamano++;
		return 1;
	}else{
		fin->setSiguiente(nodo);
		nodo->setSiguiente(NULL);
		nodo->setAnterior(fin);
		if(tamano==1){
			inicio->setSiguiente(nodo);
		}
		fin=nodo;
		tamano++;
		return 1;
	}
	return 0;

}

Nodo *Lista::buscarNodo(bool c,bool z,bool o,bool g,bool b ){
	Nodo *nodoAux = new Nodo();
	if(inicio == NULL){
		cout<<"Lista vacia"<<endl;;
		nodoAux=NULL;
	}else{
		int resBuscar=0;
		nodoAux=inicio;
		do {
			int ca,zo,oc,gr,bo;
			ca=nodoAux->getInfo()->getCampesino();
			zo=nodoAux->getInfo()->getZorro();
			oc=nodoAux->getInfo()->getOca();
			gr=nodoAux->getInfo()->getGrano();
			bo=nodoAux->getInfo()->getBote();
			if (ca==c && zo==z && oc==o && gr==g && bo==b){
				resBuscar=1;
			} else {
				nodoAux=nodoAux->getSiguiente();
			}
		} while ((nodoAux != NULL) && (resBuscar != 1));
	}
	return nodoAux;

}

int Lista::eliminarNodo(bool c,bool z,bool o,bool g,bool b){
	Nodo *nodoAux = new Nodo();
	nodoAux=buscarNodo(c,z,o,g,b);
	if(nodoAux == NULL){
				cout<<"No se ha encontrado el nodo a Eliminar"<<endl;;
			}else {
				if(tamano == 1){
					inicio=NULL;
					fin=NULL;
					tamano=0;
				}else{
					if(nodoAux == fin){
						fin->getAnterior()->setSiguiente(NULL);
						fin->setAnterior(NULL);
						fin=nodoAux->getAnterior();
						free(nodoAux);
						tamano--;
					}else{
						if (nodoAux == inicio) {
							inicio->getSiguiente()->setAnterior(NULL);
							inicio->setSiguiente(NULL);
							inicio=nodoAux->getSiguiente();
							free(nodoAux);
						} else {
							nodoAux->getAnterior()->setSiguiente(nodoAux->getSiguiente());
							nodoAux->getSiguiente()->setAnterior(nodoAux->getAnterior());
							free(nodoAux);
						}
					}

				}

			}
	return 1;

}

void Lista::mostrarLista(){
	if(inicio == NULL){
		cout<<"Lista Vacia"<<endl;;
	}else{
		Nodo *nodoAux = new Nodo();
		nodoAux=inicio;
		for (int i = 1; i <= tamano; i++) {
			cout<<"************N: "<<i<<" ***************"<<endl;
			cout<<nodoAux->getInfo()->getCampesino()<<" - ";
			cout<<nodoAux->getInfo()->getZorro()<<" - ";
			cout<<nodoAux->getInfo()->getOca()<<" - ";
			cout<<nodoAux->getInfo()->getGrano()<<" - ";
			cout<<nodoAux->getInfo()->getBote()<<endl;
			nodoAux=nodoAux->getSiguiente();
		}
	}
}

int main(){
	Lista *objL=new Lista();
	Nodo *nodo=new Nodo();
	nodo->setInfo(0,0,0,0,0);
	objL->insertarNodo(nodo);

	Nodo *nodo1=new Nodo();
	nodo1->setInfo(1,1,1,1,1);
	objL->insertarNodo(nodo1);

	Nodo *nodo3=new Nodo();
	nodo3->setInfo(1,0,1,1,0);
	objL->insertarNodo(nodo3);

	/*
	cout<<objL->getInicio()->getInfo()->getBote()<<endl;
	cout<<objL->getInicio()->getSiguiente()<<endl;

	cout<<objL->getFin()->getInfo()->getBote()<<endl;
	cout<<objL->getFin()->getSiguiente()<<endl;
	*/

	/*
	 * A=B=C
	 * B.ANTERIOR.SIGUIENTE=B.SIGUIENTE;
	 * B.SIGUIENTE.ANTERIOR=B.ANTERIOR
	 * */

	objL->mostrarLista();
	cout<<"eliminar-------------------"<<endl;
	objL->eliminarNodo(1,1,0,1,1);
	objL->mostrarLista();


	return 0;
}
