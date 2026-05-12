FROM espressif/idf:v5.4.4

RUN apt-get update && apt-get install -y \
    vim \
    nano \
    git \
    python3-pip \
    minicom \
    picocom \
    usbutils \
    make \
    cmake\
    ccache\
    gedit\
    gdb \
    && rm -rf /var/lib/apt/lists/*
    
# Herramientas de análisis estático
RUN apt-get update && apt-get install -y \
    cppcheck clang-format \
    screen\
    gtkterm\
    gcc\
    && rm -rf /var/lib/apt/lists/*    

WORKDIR /workspace
