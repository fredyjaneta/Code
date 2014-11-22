#include <stdlib.h>
#include <iostream>
#include "info.h"
using namespace std;

class Nodo{
      private:

              Nodo *siguiente;
              Nodo *anterior;
              Info *info;
      public:

             Nodo *getSiguiente();
             Nodo *getAnterior();
             Info *getInfo();
             void setInfo(bool c,bool z,bool o,bool g,bool b);
             void setSiguiente(Nodo *s);
             void setAnterior(Nodo *a);
             Nodo();

      };

      Nodo::Nodo(){
        siguiente=NULL;
        anterior=NULL;
        info=new Info();
      }


      void Nodo::setSiguiente(Nodo *s){
           siguiente=s;
      }

      void Nodo::setAnterior(Nodo *a){
           anterior=a;
      }

      void Nodo::setInfo(bool c,bool z,bool o,bool g,bool b){
    	  info->setCampesino(c);
    	  info->setZorro(z);
    	  info->setOca(o);
    	  info->setGrano(g);
    	  info->setBote(b);
      }

      Info *Nodo::getInfo(){
    	  return info;
      }

      Nodo *Nodo::getSiguiente(){
           return siguiente;
      }

      Nodo *Nodo::getAnterior(){
           return anterior;
      }

/*
      int main(){

      	Nodo *nodo=new Nodo();
      	nodo->setInfo(1,1,0,1,1);
      	cout<<nodo->getInfo()->getBote()<<" "<<nodo->getInfo()->getOca();


      	return 0;
      }

*/


