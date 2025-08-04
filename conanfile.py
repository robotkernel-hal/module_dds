from conan import ConanFile, conan_version
from conan.tools.scm import Version
import os


class MainProject(ConanFile):
    python_requires = "conan_template/[~5]@robotkernel/stable"
    python_requires_extend = "conan_template.RobotkernelConanFile"

    name = "module_dds"
    description = "module_dds is export process data device via DDS."
    exports_sources = ["*", "!.gitignore"]
    requires = ["robotkernel/[~6]@robotkernel/unstable", "service_provider_process_data_inspection/[~6]@robotkernel/unstable"]
    
    def source(self):
        self.run(f"sed 's/AC_INIT(.*/AC_INIT([robotkernel], [{self.version}], [{self.author}])/' configure.ac.in > configure.ac")

