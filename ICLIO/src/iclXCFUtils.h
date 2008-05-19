#ifdef HAVE_XCF
#ifndef ICL_XCF_UTILS_H
#define ICL_XCF_UTILS_H

#include <string>
#include <xmltio/xmltio.hpp>
#include <iclImgBase.h>
#include <xcf/RemoteServer.hpp>
#include <xmltio/Location.hpp>

namespace icl{
  class XCFUtils{
    public:
    static const std::string &createEmptyXMLDoc();
    static xmltio::Location createXMLDoc(const ImgBase* image, const std::string& uri, const std::string& bayerPattern);
    static void CTUtoImage(const XCF::CTUPtr ctu, const xmltio::Location& l, ImgBase** ppoImage);

    static  XCF::Binary::TransportUnitPtr ImageToCTU(const ImgBase* image, XCF::Binary::TransportUnitPtr btu);
  };  
}


#endif // ICL_XCF_UTILS_H

#endif // HAVE_XCF
