FROM ubuntu:18.04

ENV DEBIAN_FRONTEND noninteractive

ENV LANGUAGE=en_US.UTF-8
ENV LC_CTYPE en_US.UTF-8
ENV LANG en_US.UTF-8
ENV LC_ALL en_US.UTF-8

RUN apt-get update
RUN apt-get upgrade -y

RUN apt-get install apt-utils locales -y
RUN locale-gen en_US en_US.UTF-8
RUN update-locale LANG=en_US.UTF-8

RUN apt-get install -y --no-install-recommends \
        bc \
        build-essential \
        bzr \
        ca-certificates \
        cmake \
        cpio \
        cvs \
        file \
        git \
        libncurses5-dev \
        python3 \
        rsync \
        unzip \
        wget \
	time \
        && \
    apt-get -y autoremove && \
    apt-get -y clean

RUN useradd -ms /bin/bash user && \
    chown -R user:user /home/user

ENV DEBIAN_FRONTEND newt

RUN id
RUN pwd

USER user
WORKDIR /home/user

RUN id
RUN pwd

COPY --chown=user . firmware
RUN ls -la firmware/vendors
RUN make -C firmware mrproper
RUN make -C firmware configs
RUN time make -C firmware hisilicon_hi3516cv100_toolchain-uclibc_defconfig  
RUN mkdir -p ~/sdk
RUN cp firmware/toolchain/*.tar.gz ~/sdk
RUN rm -rf firmware
