#include "Set.h"


Set::Set(){

}

void Set::setSeq_V(SeqV _V){
	V = _V;
}

void Set::setSeq_E(SeqE _E){
	E = _E;
}

SeqV Set::getSeq_V(){

	return V;
}

SeqE Set::getSeq_E(){

	return E;
}
