* For CMake to be able to find the pybind11 package, you need to do one of the following:
    * Install pybind11 through Conda (`conda install pybind11 -c conda-forge`)
    * Ask pip to install the appropriate pybind11 files to a standard location globally rather than in your virtual environment (`pip install pybind11[global]`)
    * Explicitly tell CMake where to find the pybind11 files
