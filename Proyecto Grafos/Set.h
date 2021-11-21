#pragma once
#ifndef SET_H
#define SET_H

#include "Seq.h"

class Set{
private:
	SeqV V; 
	SeqE E;

public:
	Set();

	void setSeq_V(SeqV);
	void setSeq_E(SeqE);
	SeqV getSeq_V();
	SeqE getSeq_E();

};



#endif // !SET_H

