FROM ubuntu:xenial

LABEL description="Ubuntu Xenial ICL Build Environment"

RUN apt-get update
RUN apt-get upgrade -y

RUN apt-get install -y build-essential git cmake python-pip dirmngr \
                       devscripts equivs apt-file debhelper sudo
RUN apt-get clean

RUN useradd --create-home -s /bin/bash user
RUN echo user:user | chpasswd
RUN adduser user sudo
RUN echo "user ALL=(ALL:ALL) NOPASSWD: /usr/bin/mk-build-deps" >> /etc/sudoers

WORKDIR /home/user
USER user
CMD ["workspace/icl/packaging/scripts/build-ubuntu-packages.sh"]
