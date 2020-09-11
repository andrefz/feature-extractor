import platform
import lit.formats

from lit.llvm import llvm_config
from lit.llvm.subst import ToolSubst

config.name = 'feature-extractor'
config.suffixes = ['.ll']
config.test_format = lit.formats.ShTest(not llvm_config.use_lit_shell)
config.test_source_root = os.path.dirname(__file__)
config.excludes = ['input']

if platform.system() == 'Darwin':
    tool_substitutions = [
        ToolSubst('%clang', "clang",
            extra_args=[
                "-isysroot",
                "`xcrun --show-sdk-path`",
                "-mlinker-version=0"
            ],
        ),
    ]
else:
    tool_substitutions = [ToolSubst('%clang', "clang")]

tools = ["opt", "lli", "not", "FileCheck", "clang"]

llvm_config.add_tool_substitutions(tool_substitutions)
llvm_config.add_tool_substitutions(tools, config.llvm_tools_dir)

config.substitutions.append(('%shlibext', config.llvm_shlib_ext))
config.substitutions.append(('%shlibdir', config.llvm_shlib_dir))
