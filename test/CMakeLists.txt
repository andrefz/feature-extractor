set(FEX_TEST_SHLIBEXT "${CMAKE_SHARED_LIBRARY_SUFFIX}")
set(FEX_TEST_SITE_CFG_INPUT "${CMAKE_CURRENT_SOURCE_DIR}/lit.site.cfg.py.in")
set(FEX_TEST_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")

set(FEX_SITE_CFG_IN_HEADER
    "## Autogenerated from ${FEX_TEST_SITE_CFG_INPUT}\n## Do not edit!")

configure_file("${FEX_TEST_SITE_CFG_INPUT}"
    "${CMAKE_CURRENT_BINARY_DIR}/lit.site.cfg.py" @ONLY)
