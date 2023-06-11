FROM ubuntu:20.04

WORKDIR /serialization

RUN apt-get update && \
    DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends \
        build-essential \
        libssl-dev \
        software-properties-common \
        autoconf \
        automake \
        libtool \
        pkg-config \
        ca-certificates \
        language-pack-en \
        locales \
        locales-all \
        cmake \
        libboost-all-dev \
        libprotobuf-dev \
        protobuf-compiler \
        wget \
        git \
        curl &&\
    apt-get clean

COPY . .

RUN rm -rf build && mkdir build && cd build && cmake .. && make -j 8 worker-bin proxy-server-bin