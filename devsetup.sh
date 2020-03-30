#!/bin/bash

# This script performs the steps doc/devsetup.md

DOXYREST_PATH=~/bin/doxyrest_b
export PATH="${DOXYREST_PATH}/build/doxyrest/bin/Release:$PATH"
echo $PATH

if [[ ! -d ${DOXYREST_PATH} ]]; then
    mkdir -p ~/bin
    echo "Installing doxyrest"
    git clone https://github.com/vovkos/doxyrest_b ${DOXYREST_PATH}

    (
        cd ${DOXYREST_PATH};
        git submodule update --init;
        mkdir build;
        cd build;
        cmake ..;
        cmake --build .;
    )

fi

if [[ ! -d venv ]]; then
    echo "Creating virtualenv"
    virtualenv --python=python3.7 venv
    source venv/bin/activate
    pip install -r requirements.txt
    pip install -r doc/requirements.txt
else
    source venv/bin/activate
fi

cmake -H. -Bbuild
