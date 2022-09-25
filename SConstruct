#! /usr/bin/python3
import os
import sys

env = SConscript("godot-cpp/SConstruct")

# Set up target
target_project = "project/extension/"
extension_path = "qrnative/" + env["platform"]
extension_name = "libqrnative"


# Set up sources
def add_sources(sources, dir, extension):
    for f in os.listdir(dir):
        if f.endswith("." + extension):
            sources.append(dir + "/" + f)
        elif os.path.isdir(dir + "/" + f):
            add_sources(sources, dir + "/" + f, extension)

qrnative_path = "src/"
zxing_path = qrnative_path + "zxing-cpp/"

env.Append(CPPDEFINES=["ZXING_BUILD_READERS", "ZXING_BUILD_WRITERS"]) # Required to compile Readers and Writers
env.Append(CPPPATH=[zxing_path])
sources = []
add_sources(sources, qrnative_path, "cpp")


# Create the library target (e.g. qrnative/w/libexample.linux.debug.x86_64.so).
if env["platform"] == "macos":
    library = env.SharedLibrary(
        "{0}{1}/{2}.{3}.framework/{2}.{3}.{4}".format(
            target_project,
            extension_path,
            extension_name,
            env["platform"],
            env["target"],
        ),
        source=sources,
    )
else:
    library = env.SharedLibrary(
        "{0}{1}/{2}.{3}.{4}.{5}{6}".format(
            target_project,
            extension_path,
            extension_name,
            env["platform"],
            env["target"],
            env["arch_suffix"],
            env["SHLIBSUFFIX"],
        ),
        source=sources,
    )

Default(library)