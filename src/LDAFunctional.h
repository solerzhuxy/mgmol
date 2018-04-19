// Copyright (c) 2017, Lawrence Livermore National Security, LLC. Produced at
// the Lawrence Livermore National Laboratory. 
// Written by J.-L. Fattebert, D. Osei-Kuffuor and I.S. Dunn.
// LLNL-CODE-743438
// All rights reserved. 
// This file is part of MGmol. For details, see https://github.com/llnl/mgmol.
// Please also read this link https://github.com/llnl/mgmol/LICENSE

////////////////////////////////////////////////////////////////////////////////
//
// LDAFunctional.h
//
////////////////////////////////////////////////////////////////////////////////
// $Id$

#ifndef LDAFUNCTIONAL_H
#define LDAFUNCTIONAL_H

#include "XCFunctional.h"
#include "Rho.h"

#include <vector>
#include <string>
#include <cassert>

class LDAFunctional : public XCFunctional
{
    void xc_unpolarized(RHODTYPE rh, POTDTYPE &ee, POTDTYPE &vv);
    void xc_polarized(RHODTYPE rh, POTDTYPE &ee, POTDTYPE &vv);    
    std::vector<POTDTYPE> exc_;
    std::vector<std::vector<POTDTYPE> > vxc_;
    
    LDAFunctional();
    
public:
  
    LDAFunctional(std::vector<std::vector<RHODTYPE> > &rhoe):
      XCFunctional(rhoe)
    {
        assert( nspin_==1 );
        assert( np_>0 );
        
        exc_.resize(np_);
        vxc_.resize(nspin_);
        for ( int i = 0; i < nspin_; i++ )
        {
          vxc_[i].resize(np_);
        }
        
        pexc_ = &exc_[0];
        if ( nspin_ == 1 )
        {
          pvxc1_ = &vxc_[0][0];
        }
        else
        {
          pvxc1_up_ = &vxc_[0][0];
          pvxc1_dn_ = &vxc_[1][0];
        }
    };
    
    bool isGGA()const { return false; };
    std::string name()const { return "LDA"; };
    void computeXC(void);

    double computeRhoDotExc()const;
};
#endif
