/********************************************************************
**                Image Component Library (ICL)                    **
**                                                                 **
** Copyright (C) 2006-2012 CITEC, University of Bielefeld          **
**                         Neuroinformatics Group                  **
** Website: www.iclcv.org and                                      **
**          http://opensource.cit-ec.de/projects/icl               **
**                                                                 **
** File   : ICLMarkers/src/MarkerCodeICL1.cpp                      **
** Module : ICLMarkers                                             **
** Authors: Christof Elbrechter                                    **
**                                                                 **
**                                                                 **
** Commercial License                                              **
** ICL can be used commercially, please refer to our website       **
** www.iclcv.org for more details.                                 **
**                                                                 **
** GNU General Public License Usage                                **
** Alternatively, this file may be used under the terms of the     **
** GNU General Public License version 3.0 as published by the      **
** Free Software Foundation and appearing in the file LICENSE.GPL  **
** included in the packaging of this file.  Please review the      **
** following information to ensure the GNU General Public License  **
** version 3.0 requirements will be met:                           **
** http://www.gnu.org/copyleft/gpl.html.                           **
**                                                                 **
** The development of this software was supported by the           **
** Excellence Cluster EXC 277 Cognitive Interaction Technology.    **
** The Excellence Cluster EXC 277 is a grant of the Deutsche       **
** Forschungsgemeinschaft (DFG) in the context of the German       **
** Excellence Initiative.                                          **
**                                                                 **
*********************************************************************/

#include <ICLMarkers/MarkerCodeICL1.h>
#include <ICLUtils/Macros.h>

#include <algorithm>

namespace icl{
  
  const int MarkerCodeICL1::P;
  const int MarkerCodeICL1::P1;

  MarkerCodeICL1::MarkerCodeICL1():id(99999999){
    n[0] = n[1] = n[2] = n[3] = 0;
  }

  MarkerCodeICL1::MarkerCodeICL1(const int ns[4], bool rootColorIsBlack){
    for(int i=0;i<4;++i) n[i] = ns[i];
    id = n[0] + P1*n[1] + (P1*P1)*n[2] + (P1*P1*P1)*n[3];
    if(!rootColorIsBlack) id = -id;
  }

  MarkerCodeICL1::MarkerCodeICL1(int id):id(id){
    const int sign = id<0 ? -1: 1;
    id = abs(id);
    
    n[3] = iclMin(P,id/(P1*P1*P1));
    id -= n[3]*(P1*P1*P1);
    n[2] = iclMin(P,id/(P1*P1));
    id -= n[2]*(P1*P1);
    n[1] = iclMin(P,id/(P1));
    id -= n[1]*(P1);
    n[0] = id;
    id *= sign;
  }

  int MarkerCodeICL1::operator-(const MarkerCodeICL1 &p) const {
    int e = 0;
    for(int i=0;i<4;++i) e += ::abs(n[i]-p.n[i]);
    return e;
  }


  std::ostream &operator<<(std::ostream &str, const MarkerCodeICL1 &c){
    return str << "("<<c[0]<<","<<c[1]<<","<<c[2]<<","<<c[3]<<")["<<c.id<<"]";
  }

  static bool hamming_ok(const MarkerCodeICL1 &a, const std::vector<MarkerCodeICL1> &ps){
    for(unsigned int x=0;x<ps.size();++x){
      if( (a - ps[x]) < 2){
        return false;
      }
    }
    return true;
  }
  
  const std::vector<MarkerCodeICL1> &MarkerCodeICL1::generate(){
    static std::vector<MarkerCodeICL1> ps;
    if(ps.size()) return ps;
    
    for(int i=1;i<=P;++i){
      for(int j=1;j<=P;++j){
        for(int k=1;k<=P;++k){
          for(int l=1;l<=P;++l){
            if(i<=j && j<=k && k<=l && i<l){
              int ns[]={i,j,k,l};
              MarkerCodeICL1 t(ns);
              if(hamming_ok(t, ps)){
                ps.push_back(t);
              }
            }
          }
        }
      }
    }
    std::reverse(ps.begin(),ps.end());
    return ps;
  }
  


}
