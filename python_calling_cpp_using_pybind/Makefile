CXX = g++
PYTHON = /usr/local/Caskroom/miniconda/base/envs/general/bin/python3
PYTHON_CONFIG = /usr/local/Caskroom/miniconda/base/envs/general/bin/python3-config

all: cpp_library

clean:
	rm -f *.o *.exe *.so

cpp_library: cppMultiply.cpp
	# `-undefined dynamic_lookup` should only be needed for macOS.
	${CXX} -fPIC -shared -std=c++11 -undefined dynamic_lookup cppMultiply.cpp $$(${PYTHON} -m pybind11 --includes) -o cpp_library$$(${PYTHON_CONFIG} --extension-suffix)
