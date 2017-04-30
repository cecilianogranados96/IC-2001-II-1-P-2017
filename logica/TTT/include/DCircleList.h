#ifndef DCIRCLELIST_H
#define DCIRCLELIST_H
#include "DLinkedListJ.h"
#include <cstddef>

using namespace std;

class DCircleList : public DLinkedListJ
{
    public:
        DCircleList();
        void append(Jugador* value);
        bool empty();
        void clear();
        virtual ~DCircleList();
    protected:
    private:
};

#endif // DCIRCLELIST_H
