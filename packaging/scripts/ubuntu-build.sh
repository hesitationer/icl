#!/bin/bash

rm -r build
mkdir build && cd build

cmake -DCMAKE_SKIP_RPATH=ON \
      -DBUILD_WITH_OPENCV=ON  -DBUILD_WITH_QT=ON \
      -DBUILD_WITH_OPENGL=ON \
      -DBUILD_WITH_EIGEN3=ON \
      -DBUILD_WITH_IMAGEMAGICK=ON \
      -DBUILD_WITH_LIBAV=ON  -DBUILD_WITH_LIBDC=ON \
      -DBUILD_WITH_LIBFREENECT=ON \
      -DBUILD_WITH_V4L=ON \
      -DBUILD_WITH_LIBUSB=ON -DBUILD_WITH_ZMQ=ON \
      -DBUILD_WITH_OPENCL=ON \
      -DBUILD_WITH_OPENNI=ON -DBUILD_WITH_PCL=ON \
      -DBUILD_EXAMPLES=ON -DBUILD_DEMOS=ON \
      -DBUILD_APPS=ON -DBUILD_DEBS=ON ..


# -DBUILD_WITH_IPP=ON -DBUILD_WITH_MKL=ON (Custom Repos)
# -DBUILD_WITH_XIAPI=ON (Binary installer)
# -DBUILD_WITH_RSC=ON -DBUILD_WITH_RST=ON -DBUILD_WITH_RSB=ON -DBUILD_WITH_PROTOBUF=ON (Custom Repos)
# -DBUILD_WITH_LIBFREENECT2=ON (Complex build process)
# -DBUILD_WITH_XINE=ON (Dropped in xenial)
# -DBUILD_WITH_MESASR=ON (No drivers found
# -DBUILD_WITH_LIBIRIMAGER=ON -DBUILD_WITH_LIBUDEV=ON (Custom Repo)
# -DBUILD_WITH_BULLET=ON -DBULLET_ROOT=/usr/local (no package)
# -DBUILD_WITH_PYLON=ON (Custom repos)
