import os

from conan import ConanFile
from conan.tools.cmake import CMake, cmake_layout
from conan.tools.files import copy, collect_libs, update_conandata
from conan.tools.scm import Git
from conans.errors import ConanException


class AtlasConan(ConanFile):
    name = "atlas"
    version = "0.7.0"
    license = "GPL-2.0+"
    author = "Erik Ogenvik <erik@ogenvik.org>"
    homepage = "https://www.worldforge.org"
    url = "https://github.com/worldforge/atlas-cpp"
    description = "Networking protocol for the Worldforge system."
    topics = ("mmorpg", "worldforge")
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [False, True], "fPIC": [True, False]}
    default_options = {"shared": False, "fPIC": True}
    requires = ["bzip2/1.0.8",
                "zlib/1.2.13"]
    generators = "CMakeToolchain", "CMakeDeps"

    def export(self):
        git = Git(self, self.recipe_folder)
        try:
            scm_url, scm_commit = git.get_url_and_commit()
            update_conandata(self, {"sources": {"commit": scm_commit, "url": scm_url}})
        except ConanException:
            pass

    def export_sources(self):
        folder = os.path.join(self.recipe_folder, "../..")
        copy(self, "*", folder, self.export_sources_folder)

    def config_options(self):
        if self.settings.os == "Windows":
            del self.options.fPIC

    def layout(self):
        self.folders.root = "../.."
        cmake_layout(self)

    def build(self):
        cmake = CMake(self)
        cmake.definitions['ATLAS_GENERATE_OBJECTS'] = False
        cmake.configure()
        cmake.build()

    def package(self):
        cmake = CMake(self)
        cmake.definitions['ATLAS_GENERATE_OBJECTS'] = False
        cmake.install()

    def package_info(self):
        # Since the libraries are interdependent we must provide them in correct order.
        self.cpp_info.libs = ["AtlasNet", "AtlasObjects", "AtlasFilters", "AtlasCodecs", "AtlasMessage", "Atlas"]


