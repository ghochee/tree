@page devsetup Developer Setup

# Easy Opaque Setup

Execute
```console
$ ./devsetup.sh
$ source venv/bin/activate
```

and you sould be able to run `cmake --build .` inside the `build/` directory.

# Longer Detailed Setup

This is for those who don't trust the script and would like to understand the
bits or if the script failed for any reason.

The development environment contains the following elements

* `virtualenv` environment for python libraries and binaries.
* `conan` for installing dependencies
* `CMake` for generating the build files / building.

## Virtualenv

For almost all operations you would have to be in the `virtualenv` environment.
The onetime setup of this environment is done by running:

```console
$ virtualenv --python=python3.7 venv
```

After this every time you need to build or generate documentation files you
would need to activate this environment by runniing.
```console
$ source venv/bin/activate
```

You can see [VirtualEnv](https://virtualenv.pypa.io/en/stable/) for a primer on
what it is and how it works.

## Build and Testing

Uses cmake but cmake depends on conan executable to be available. After
activating the `virtualenv` from the top level directory run the following:

```console
$ pip install -r requirements.txt
```

After this building with cmake is as with any other project

```console
$ cmake -H. -Bbuild
$ cd build/
$ cmake --build .
```

## Generating Documentation

Documentation is generated using
[doxyrest](https://github.com/vovkos/doxyrest). This in turn depends on some
python libraries which are listed in doc/requirements.txt. The doxyrest binary
needs to be available on `PATH` for documentation generation to work. The
easiest way to install doxyrest is to clone the [binary
repo](https://github.com/vovkos/doxyrest_b).

```console
$ git clone https://github.com/vovkos/doxyrest_b ~/bin/
$ export PATH=~/bin/doxyrest_b/build/doxyrest/bin/Release:$PATH
```
After that you have to follow the `README.rst` in the repository to build all
the binaries required.

You may install the other dependencies by running the following commands after
activating the `virtualenv`:
```console
$ pip install doc/requirements.txt
```

Once these setup steps are done, building documentation is possible by runninng
```console
$ cmake --build doc
```
inside the `build/` directory.
