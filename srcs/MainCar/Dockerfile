# Usar imagem Debian ARM64
FROM arm64v8/debian:buster

# Instalar dependências básicas
RUN apt-get update && DEBIAN_FRONTEND=noninteractive && apt-get install -y \
    gcc-aarch64-linux-gnu \
    g++-aarch64-linux-gnu \
    cmake \
    rsync \
    make \
    git \
    tzdata \
    libsdl2-dev \
    libgtest-dev \
    && apt-get clean && rm -rf /var/lib/apt/lists/*

# Instalar pigpio a partir do código-fonte
RUN git clone https://github.com/joan2937/pigpio.git /tmp/pigpio \
    && cd /tmp/pigpio \
    && make \
    && make install \
    && rm -rf /tmp/pigpio

# Variável para a ferramenta de compilação
ENV TOOLCHAIN=/usr/bin/aarch64-linux-gnu

# Definir o diretório de trabalho
WORKDIR /workspace

# Copiar os arquivos do projeto
#COPY . .

# Comando padrão do container
CMD ["/bin/bash"]
