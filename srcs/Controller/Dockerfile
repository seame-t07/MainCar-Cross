#Debian ARM64: buster
FROM hmacielp/crosscompile-gpio:latest

RUN apt update && apt-get install -y \
    libzmq3-dev \
    build-essential

RUN git clone https://github.com/zeromq/cppzmq.git /tmp/cppzmq && \
    cp /tmp/cppzmq/zmq.hpp /usr/include/ && \
    rm -rf /tmp/cppzmq

WORKDIR /workspace

CMD ["/bin/bash"]
