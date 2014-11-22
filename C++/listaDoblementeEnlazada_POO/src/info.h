#include <stdlib.h>
#include <iostream>
using namespace std;

class Info{
	private:
		bool campesino;
	    bool zorro;
	    bool oca;
	    bool grano;
	    bool bote;
	public:
	    bool getCampesino();
	    bool getZorro();
	    bool getOca();
	    bool getGrano();
	    bool getBote();
	    void setCampesino(bool c);
	    void setZorro(bool z);
	    void setOca(bool o);
	    void setGrano(bool g);
	    void setBote(bool b);
	    Info();

};

Info::Info(){
	campesino=0;
	zorro=0;
	oca=0;
	grano=0;
	bote=0;
}

void Info::setCampesino(bool c){
           campesino=c;
      }

void Info::setZorro(bool z){
           zorro=z;
      }

void Info::setOca(bool o){
           oca=o;
      }

void Info::setGrano(bool g){
           grano=g;
      }

void Info::setBote(bool b){
           bote=b;
      }

bool Info::getCampesino(){
           return campesino;
      }

bool Info::getZorro(){
           return zorro;
      }

bool Info::getOca(){
           return oca;
      }

bool Info::getGrano(){
           return grano;
      }

bool Info::getBote(){
           return bote;
      }


