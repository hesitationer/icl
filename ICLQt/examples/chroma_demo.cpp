#include <iclChromaGUI.h>
#include <iclImgChannel.h>
#include <iclThread.h>
#include <iclDCGrabber.h>
#include <iclPWCGrabber.h>
#include <iclFileGrabber.h>
#include <iclProgArg.h>

using namespace icl;
using namespace std;

GUI *gui;
ChromaGUI  *cg;

struct MyThread : public Thread{
  virtual void run(){
    Size size = Size(320,240);
    Grabber *grabber = 0;
    vector<DCDevice> devs = DCGrabber::getDeviceList();
    if(!devs.size()){
      vector<int> pwcdevs = PWCGrabber::getDeviceList();
      if(!pwcdevs.size()){
        if (pa_defined("-file")) {
          grabber = new FileGrabber(pa_subarg("-file",0,string("./images/*")));
          ((FileGrabber*)grabber)->setIgnoreDesiredParams(false);
        } else {
          cout << "Define at least a file or plugin the PWC cam" << endl;
          exit(1);
        }
      }else{
        grabber = new PWCGrabber(size);
      }
    }else{
      grabber = new DCGrabber(devs[0]);
    }
    grabber->setDesiredSize(size);
    Img8u segImage(size,1);
    Img8u *image = new Img8u(size,formatRGB);
    ImgBase *imageBase = image;
    while(1){
      grabber->grab(&imageBase);
      gui->getValue<ImageHandle>("image") = image;
      gui->getValue<ImageHandle>("image").update();
      
      ImgChannel8u c[3] = { 
        pickChannel(image->asImg<icl8u>(),0),
        pickChannel(image->asImg<icl8u>(),1),
        pickChannel(image->asImg<icl8u>(),2)
      };
      ImgChannel8u s = pickChannel(&segImage,0);
      
      ChromaAndRGBClassifier classi = cg->getChromaAndRGBClassifier();

      for(int x=0;x<size.width;x++){
        for(int y=0;y<size.height;y++){
          s(x,y) = 255 * classi(c[0](x,y),c[1](x,y),c[2](x,y));
        }
      }
      
      gui->getValue<ImageHandle>("segimage") = &segImage;     
      gui->getValue<ImageHandle>("segimage").update();
      msleep(40);
    }
  }
};

int main(int nArgs, char **ppcArgs){
  QApplication app(nArgs,ppcArgs);
  pa_init(nArgs, ppcArgs,"-file(1)");
  
  gui = new GUI("hbox");
  (*gui) << ( GUI("vbox")  
              << "image[@minsize=16x12@handle=image@label=Camera Image]" 
              << "image[@minsize=16x12@handle=segimage@label=Semented Image]" );
  (*gui) << "hbox[@handle=box]";
  
  gui->show();
  cg = new ChromaGUI(*(gui->getValue<BoxHandle>("box")));

  MyThread t;
  t.start();
  
  return app.exec();
}
