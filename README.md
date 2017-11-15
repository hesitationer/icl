<h1 align="center">
  <img src="doc/icl-api/images/icl-logo-50.png" height="50px"/>
  <br>
  Image Component Library
</h1>

[![Version](https://img.shields.io/badge/version-10.0.0-brightgreen.svg)](https://github.com/iclcv/icl)
[![Build Travis](https://travis-ci.org/iclcv/icl.svg?branch=master)](https://travis-ci.org/iclcv/icl)
[![Build AppVeyor](https://ci.appveyor.com/api/projects/status/github/iclcv/icl?branch=master&svg=true)](https://ci.appveyor.com/project/aleneum/icl)
[![Commits](https://img.shields.io/github/commits-since/iclcv/icl/latest.svg)](https://github.com/iclcv/icl/compare/9.13.0...master)
[![License](https://img.shields.io/github/license/iclcv/icl.svg)](LICENSE.LGPL)

## Table of Contents
- [About ICL](#about-icl)
- [Installation](#installation)
  - [Ubuntu packages](#ubuntu packages)
  - [Homebrew Recipes (OSX)](#homebew-recipes)
  - [Windows Installers](#windows-installers)
  - [Packaging Status](#packaging-status)
  - [Building from source (Ubuntu)](#building-from-source-ubuntu)


## <a name="about-icl"></a>About ICL

ICL is a novel C++ computer-vision library developed in the neuroinformatics group of the University of Bielefeld. It unifies both performance and user friendliness. ICL provides a large set of simple-to-use classes and functions to facilitate development of complex computer vision applications.
A simple application for image acquisition and visualization can be written in less than 15 lines of C++ code.

During the design and development process, the following main goals took center stage:

### Optimal Performance

ICL can optionally be linked against the Intel IPP-Library in order to enhance it's processing speed significantly. Most functions are implemented as Intel IPP wrappers internally but we also provide fallback implementations for data-types that are not supported by Intel IPP or for the case where Intel IPP is not available. ICL images can be used as shallow wrappers around existing data structures and their raw-data can be accessed directly. By this means, image processing applications can be implemented without any overhead for data-conversion or copying.

### Simple and Easy-to-Use C++ Interface

Object-orientated programming (OOP) in C++ provides both high performance due to processor-close programming, as well as a high abstraction level, due to the inherent features of object orientation. In particular, inheritance, data/function encapsulation, as well as function- and class-templating are used for ICL's implementation.

### No Compulsory Software Dependencies

All external software dependencies are purely optional. Therefore, ICL's image structures and a large set of its functions and classes can be used without installing any 3rd-party libraries. By this means, you can develop your image processing algorithms with a slim version of ICL and link your code against a full featured ICL afterwards, i.e., when you need to use a certain camera type.

### Platform Independence

ICL is written in C++ without using compiler dependent statements like #pragma. Furthermore, we use the GNU-Autotools for it's building, which allows us to compile ICL on linux/unix based systems directly. ICL has already been compiled successfully under Linux and MacOS-X and we plan to provide a Windows build as well.

### Wide Range of Functions and GUI Integration

In contrast to the OpenCV library, we did not only concentrate on providing image-processing-related functions and tools. ICL also provides a large set of ready-to-use and well suited utility-classes and functions, e.g., for program-argument evaluation, or for object-oriented vector and matrix algebra. In particular, the ICLQt-package provides a powerful GUI-creation and image visualization and annotation framework.

## Installation

### Ubuntu Packages

Ubuntu packages can be obtained from the [Releases](https://github.com/iclcv/icl/releases) page or by using the [ICL PPA](https://launchpad.net/~iclcv/+archive/ubuntu/icl):

```bash
sudo add-apt-repository ppa:iclcv/icl
sudo apt-get update
sudo apt-get install icl-tools
```

The ICL build is divided into four packages:

* `icl-core` - Image Component Library
* `icl-dev` - ICL headers and project creation tools
* `icl-doc` - ICL sphinx manual and api documentation
* `icl-tools` - ICL Applications

Currently, we provide packages for the Ubuntu releases `trusty` and `xenial`.
The packages are built with [PCL](http://pointclouds.org/).
Users of `trusty` need to install this library before ICL packages can be installed. As described [here](http://pointclouds.org/downloads/linux.html), it is possible to get this dependency from another PPA:

```bash
sudo add-apt-repository ppa:v-launchpad-jochen-sprickerhof-de/pcl
sudo apt-get update
sudo apt-get install libpcl-all
```
### Homebrew Recipes

We provide [Homebrew](https://brew.sh/index_de.html) recipes which can be used
to install ICL in three different flavours:

```
# has to be done just once
$ brew tap iclcv/homebrew-formulas
# enables features of OpenCV, Qt, OpenGL, ImageMagick, LibAV, LibDC and LibEigen
$ brew install icl  
# base features plus additional functionality based on rsb, protobuf, freenect, pcl and bullet
$ brew install icl --with-extra
# extra features plus libusb, zmq and openni support  
brew install icl --with-full
```

### Windows Installers

Windows MSI installers for Win32 or Win64 can be downloaded from the AppVeyor CI-Servers (see below).
Users to have to install 3rd-party dependencies (pthreads-win32, Qt5, Visual Studio Redistributables) to work with the contained binaries.

### Packaging Status

Prebuilt packages can be obtained/installed from the following channels:

|   OS    | Channel | Target |
|:--------|:--------|:-------|
| Ubuntu  | [Launchpad][url-launchpad] | `trusty`, `xenial` |
| OSX     | [Homebrew][url-homebrew] | |
| Windows | MSI ([Win64][url-msi-x86]/[Win32][url-msi-x86]) | Visual Studio 2017 |

These distributions have been built with the following features enabled:

| Feature     | Ubuntu | OSX | Windows |
|:------------|:------:|:---:|:--------|
| APPS        | ✓  | ✓   | ✓ |
| DEMOS       | ✓  | ✓   | ✓ |
| EXAMPLES    | ✓  | ✓   | ✓ |
| IPP/MKL     | ✓! | ✗   | ✗ |
| QT          | ✓  | ✓   | ✓ |
| OpenCV      | ✓  | ✓   | ✓ (64bit) |
| OpenGL      | ✓  | ✓   | ✗ |
| ImageMagick | ✓  | ✓   | ✗ |
| LibAV       | ✓  | ✓   | ✗ |
| LibDC       | ✓  | ✓   | ✗ |
| Eigen3      | ✓  | ✓   | ✗ |
| PCL         | ✓  | ✓*  | ✗ |
| Bullet3     | ✓  | ✓*  | ✗ |
| Freenect    | ✓  | ✓*  | ✗ |
| OpenNI      | ✓  | ✓** | ✗ |
| ZMQ         | ✓  | ✓** | ✗ |
| LibUSB      | ✓  | ✓** | ✗ |
| Video4Linux | ✓  | ✗   | ✗ |
| OpenCL      | ✓  | ✗   | ✗ |
| RSB         | ✗  | ✓** | ✗ |
| RSC         | ✗  | ✓** | ✗ |
| PROTOBUF    | ✗  | ✓** | ✗ |

* Remark for Homebrew installations: `*` require the install flag `--with-extra` and `**` requires the install flag `--with-full`.

[url-launchpad]: https://launchpad.net/~iclcv/+archive/ubuntu/icl/
[url-homebrew]: https://github.com/iclcv/homebrew-formulas
[url-msi-x86]: https://ci.appveyor.com/api/projects/aleneum/icl/artifacts/build/_CPack_Packages/win64/WIX/icl-10.0.0-x64-1911.msi?job=Environment%3A%20platform%3Dx64%2C%20OPENCV%3D-DBUILD_WITH_OPENCV%3DON%20-DOPENCV_ROOT%3DC%3A%5Ctools%5Copencv%5Cbuild%20-DOpenCV_RUNTIME%3Dvc14%2C%20CMAKE_GENERATOR%3DVisual%20Studio%2015%20Win64%2C%20QT_ROOT%3DC%3A%5CQt%5C5.9.1%5Cmsvc2017_64
[url-msi-x64]: https://ci.appveyor.com/api/projects/aleneum/icl/artifacts/build/_CPack_Packages/win32/WIX/icl-10.0.0-x86-1911.msi?job=Environment%3A%20platform%3Dx86%2C%20OPENCV%3D%2C%20CMAKE_GENERATOR%3DVisual%20Studio%2015%2C%20QT_ROOT%3DC%3A%5CQt%5C5.9.1%5Cmsvc2015

### <a name="building-from-source-ubuntu"></a> Building from source (Ubuntu)
To build the minimal version of ICL, the following packages are **mandatory**:

* `cmake`
* `libjpeg-dev`
* `libpng-dev`

With a Debian-based operating system, these requirements can be installed using
`apt`:

```
$ sudo apt-get install cmake libjpeg-dev libpng-dev
```

Clone this repository to your workspace, cd into the project folder and build the
libraries with `cmake`

```
$ cd /path/to/workspace
$ git clone https://github.com/iclcv/icl.git
$ mkdir icl/build # create build folder
$ cd icl/build
$ cmake ..
$ make  # optionally with -j for parallel jobs
$ make install  # install ICL
```

However, the strength of ICL lies in its rich set of features which can be
tailored according to your need.
The instruction below will install dependencies
and configure the build tool in a way to makes use of 3rd party libraries such as
Qt, OpenCV, Point Cloud Library (PCL) and many more.
It will also build ICL applications for fast computer vision prototyping as well as demo code
and documentation examples.

```
$ sudo apt-get install cmake libpng-dev libjpeg-dev qtmultimedia5-dev \
  libqt5opengl5-dev libglew-dev libopencv-dev ocl-icd-opencl-dev \
  opencl-headers libeigen3-dev libmagick++-dev libfreenect-dev libxine2-dev \
  libpcl-dev

# clone and create build folder

$ cmake .. -DBUILD_WITH_EIGEN3=TRUE -DBUILD_WITH_V4L=TRUE \
           -DBUILD_WITH_LIBFREENECT=TRUE -DBUILD_WITH_MESASR=TRUE \
           -DBUILD_WITH_QT=TRUE -DBUILD_WITH_OPENCL=TRUE \
           -DBUILD_WITH_LIBDC=TRUE -DBUILD_WITH_IMAGEMAGICK=TRUE \
           -DBUILD_EXAMPLES=ON -DBUILD_DEMOS=ON \
           -DBUILD_WITH_OPENCV=TRUE -DBUILD_APPS=ON \
           -DBUILD_WITH_PCL=TRUE
$ make  # build icl
```

Let's dig bit deeper to get to know the meanings behind those flags, shall we?
Below you will find a list of features and the `cmake` flags required to build these features as well as the required Ubuntu packages.

#### Qt5 (**recommended**)

The well known Qt Library is used for ICL’s rapid GUI creation toolkit. Actually Qt is also a prerequisite for most ICL applications and for the whole ICLQt module. We strongly recommend to have at least Qt support when building ICL.

* flag: `-DBUILD_WITH_QT=TRUE`
* dependencies: `qtmultimedia5-dev libqt5opengl5-dev libglew-dev`

#### OpenCV (**recommended**)

We use OpenCV mainly in order to provide a compatibility interface that converts OpenCV’s common image data types IplImage and CvMat into ICL’s images types and vice versa.

* flag: `-DBUILD_WITH_OPENCV=TRUE`
* dependencies: `libopencv-dev`

#### OpenCL (**recommended**)

OpenCL is used to significantly speed up a set of processing units using the computing units of graphics cards or other OpenCL platforms. We mainly use it for point cloud processing units located in the ICLGeom module.

* flag: `-DBUILD_WITH_OPENCL=TRUE`
* dependencies: `ocl-icd-opencl-dev opencl-headers`

#### Eigen3 (**recommended**)

Improves calculation speed.

* flag: `-DBUILD_WITH_EIGEN3=TRUE`
* dependencies: `libeigen3-dev`

#### ImageMagick (**recommended**)

ImageMagick is used to provide a large set of support image types. Most types are supported in both reading and writing.

* flag: `-DBUILD_WITH_IMAGEMAGICK=TRUE`
* dependencies: `libmagick++-dev`

#### V4L2 (**recommended**)

For most usb-based cameras/Webcams on linux, V4L2 can be used. While v4l2 used to be a part of the kernel-Headers in older linux version, nowerdays, it is shipped as an additional library that can usually be installed conveniently using a package manager.

* flag: `-DBUILD_WITH_V4L=TRUE`

#### libfreenect (*optional*)

The libfreenect provides a lightweight interface for grabbing images from Microsoft Kinect cameras. The library allows to grab color, depth and IR-images and to set some internal camera properties.

* flag: `-DBUILD_WITH_LIBFREENECT=TRUE`
* dependencies: `libfreenect-dev`

#### libdc1394 (*optional*)

* flag: `-DBUILD_WITH_LIBDC=TRUE`

#### ICL Applications

Build with ICL tools
* flag: `-DBUILD_APPS=ON`

Build demos
* flag: `-DBUILD_DEMOS=ON`

Build doc examples
* flag: `-DBUILD_EXAMPLES=ON`

We **strongly** recommend to have at least Qt support when building ICL.
But there is more! Please refer to the documentation of [optional features](http://www.iclcv.org/install/install-linux.html#optional-dependencies)
for a complete list which includes Xine, Kinect 2, SwissRanger and more.

## Questions, feedback, issues or feature requests?

For bug reports and other issues, please [open an issue](https://github.com/iclcv/icl/issues) on GitHub.
