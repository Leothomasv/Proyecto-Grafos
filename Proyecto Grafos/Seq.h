#pragma once
#ifndef SEQ_H
#define SEQ_H

#include "V.h"
#include "E.h"
#include <vector>
using namespace std;
class Seq {

};

class SeqV : public Seq {
public:
    SeqV();
    SeqV(vector<V>);
    vector<V> value_v;
};

class SeqE : public Seq {
public:
    SeqE();
    SeqE(vector<E>);
    vector<E> value_e;
};






#endif // !SEQ_H


