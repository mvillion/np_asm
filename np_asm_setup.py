"""
    setup.py file for logit.c
    Note that since this is a numpy extension
    we use numpy.distutils instead of
    distutils from the python standard library.

    Calling
    $python setup.py build_ext --inplace
    will build the extension library in the current file.

    Calling
    $python setup.py build
    will build a file that looks like ./build/lib*, where
    lib* is a file that begins with lib. The library will
    be in this file and end with a C library extension,
    such as .so

    Calling
    $python setup.py install
    will install the module in your site-packages file.

    See the distutils section of
    "Extending and Embedding the Python Interpreter"
    at docs.python.org  and the documentation
    on numpy.distutils for more information.
"""

def configuration(parent_package="", top_path=None):
    from numpy.distutils.misc_util import Configuration
    from numpy.distutils.misc_util import get_info
    from numpy.distutils.log import set_verbosity

    # necessary for the half-float d-type.
    info = get_info("npymath")

    config = Configuration("np_asm_directory", parent_package, top_path)
    config.add_extension("np_asm", ["np_asm.c"], extra_info=info)
    set_verbosity(5, force=True)
    return config


if __name__ == "__main__":
    from numpy.distutils.core import setup
    setup(configuration=configuration)
