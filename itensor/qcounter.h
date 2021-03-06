//
// Distributed under the ITensor Library License, Version 1.1.
//    (See accompanying LICENSE file.)
//
#ifndef __ITENSOR_QCOUNTER_H
#define __ITENSOR_QCOUNTER_H

#include "counter.h"
#include "iqindex.h"

#define Cout std::cout
#define Endl std::endl

namespace itensor {

//
// QCounter
//

class QCounter : public Counter
    {
    public:

    QCounter(const std::vector<IQIndex>& v)
        {
        rn = v.size();
        r = rn;
        n[0] = 0;
        for(int j = 0; j < rn; ++j) 
            n[j+1] = v[j].nindex();
        for(int j = rn+1; j <= NMAX; ++j) 
            n[j] = 1;
        reset();
        }

    QCounter(const IndexSet<IQIndex>& is)
        {
        rn = is.rn();
        r = is.r();
        n[0] = 0;
        for(int j = 1; j <= rn; ++j) 
            n[j] = is.index(j).nindex();
        for(int j = rn+1; j <= NMAX; ++j) 
            n[j] = 1;
        reset();
        }

    void 
    getVecInd(const std::vector<IQIndex>& origv, 
              std::vector<Index>& vind, QN& q) const
        {
        const int size = origv.size();
        vind.resize(size);
        q = QN(); 
        for(int k = 0; k < size; ++k)
            {
            const IQIndex& I = origv[k];
            const int j = i[k+1]+1;
            vind[k] = I.index(j);
            q += I.qn(j)*I.dir();
            }
        }
    };

}; //namespace itensor

#undef Cout
#undef Endl

#endif
