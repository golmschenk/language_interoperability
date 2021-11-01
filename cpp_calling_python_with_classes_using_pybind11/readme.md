* For CMake to be able to find the pybind11 package, you need to do one of the following:
    * (Recommended) Ask pip to install the appropriate pybind11 files to a standard location (`pip install pybind11[global]`). Even though "global" is stated, if in a Conda environment, this is installed only within the Conda environment.
    * Install pybind11 through Conda (`conda install pybind11 -c conda-forge`).
    * Explicitly tell CMake where to find the pybind11 files.
