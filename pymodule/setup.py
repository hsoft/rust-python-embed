from setuptools import setup, Extension

exts = [
    Extension(
        "_myrustlib",
        sources=['myrustlib.c'],
        include_dirs=['../rust/include'],
        extra_objects=['./libmyrustlib.a'],
    ),
]
setup(
    script_args=['build_ext', '--inplace'],
    ext_modules=exts,
)

