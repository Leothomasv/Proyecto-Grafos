#include "Set.h"


Set::Set(){

}

void Set::setSeq_V(Seq _V){
	V = _V;
}

void Set::setSeq_E(Seq _E){
	E = _E;
}

Seq Set::getSeq_V(){

	return V;
}

Seq Set::getSeq_E(){

	return E;
}
