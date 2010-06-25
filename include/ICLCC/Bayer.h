/********************************************************************
**                Image Component Library (ICL)                    **
**                                                                 **
** Copyright (C) 2006-2010 CITEC, University of Bielefeld          **
**                         Neuroinformatics Group                  **
** Website: www.iclcv.org and                                      **
**          http://opensource.cit-ec.de/projects/icl               **
**                                                                 **
** File   : include/ICLCC/Bayer.h                                  **
** Module : ICLCC                                                  **
** Authors: Michael Götting, Felix Reinhard                        **
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

#ifndef iclBayer_H
#define iclBayer_H

#include <ICLCore/Img.h>
#include <ICLUtils/Uncopyable.h>

namespace icl {

  class BayerConverter : public Uncopyable
  {
    public:
    
  enum bayerConverterMethod {
    nearestNeighbor = 0,
    simple,
    bilinear,
    hqLinear,
    edgeSense,
    vng
  };
  
  enum bayerPattern {
    bayerPattern_RGGB = 512,
    bayerPattern_GBRG,
    bayerPattern_GRBG,
    bayerPattern_BGGR
  };
  
  BayerConverter(bayerConverterMethod eConvMethod, 
                 bayerPattern eBayerPattern, 
                 Size s);
  ~BayerConverter();
  
  void apply(const Img8u *src, ImgBase **dst);
  
  void setBayerPattern(bayerPattern eBayerPattern) { 
    m_eBayerPattern = eBayerPattern; }
  void setConverterMethod(bayerConverterMethod eConvMethod) { 
    m_eConvMethod = eConvMethod; }
  void setBayerImgSize(Size s) {
     m_vRGBInterImg.resize(s.width * s.height * 3);
  }

  static std::string translateBayerConverterMethod(bayerConverterMethod ebcm);
  static bayerConverterMethod translateBayerConverterMethod(std::string sbcm);

  static std::string translateBayerPattern(bayerPattern ebp);
  static bayerPattern translateBayerPattern(std::string sbp);
  
 private:
  std::vector<unsigned char> m_vRGBInterImg;
  bayerConverterMethod m_eConvMethod;
  bayerPattern m_eBayerPattern;
  
  // Interpolation methods
  void nnInterpolation(const Img8u *poBayerImg);
  void bilinearInterpolation(const Img<icl8u> *poBayerImg);
  void hqLinearInterpolation(const Img<icl8u> *poBayerImg);
  void edgeSenseInterpolation(const Img<icl8u> *poBayerImg);
  void simpleInterpolation(const Img<icl8u> *poBayerImg);
  
  // Utility functions
  void clearBorders(icl8u *rgb, int sx, int sy, int w);
  void clip(int *iIn, icl8u *iOut) {
    *iOut = *iIn = *iIn < 0 ? 0 : *iIn > 255 ? 255 : 0;
    // slower !
    // *iIn = *iIn < 0 ? 0 : *iIn; 
    // *iIn = *iIn > 255 ? 255 : *iIn; 
    //*iOut = *iIn;
  }
};
 
} // namespace icl

#endif
