#pragma once
#ifndef SET_H
#define SET_H

#include "Seq.h"

class Set{
private:
	Seq V, E;

public:
	Set();

	void setSeq_V(Seq);
	void setSeq_E(Seq);
	Seq getSeq_V();
	Seq getSeq_E();

};



#endif // !SET_H

