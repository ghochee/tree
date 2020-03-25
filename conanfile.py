import os

from conans import ConanFile, tools

class TreeConan(ConanFile):
    name = "tree"
    # TODO(ghochee): DRY with VERSION.txt / CMakeFiles.txt. This can't be read
    # because the object is created and referenced during conan command runs
    # before derived fields are operated on.
    version = "0.1.0"

    license = "MIT"
    author = "Aditya Dalmia dalmia.aditya@gmail.com"

    url = "https://github.com/ghochee/tree"
    description = "A tree container library."
    topics = ("tree", "container")

    build_requires = 'Catch2/2.7.0@catchorg/stable'
    generators = 'cmake'

    no_copy_source = True
    exports_sources = "include*"

    # Header only so we can omit.
    settings = None
    build_policy = "missing"

    def package(self):
        # NOTE: 'detangled' which is the namespace under which the assets are.
        self.copy("*.h*", dst="include/detangled", src="include/")
