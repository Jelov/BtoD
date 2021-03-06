############## All Tools Variables ################
CUDASRC_FILES_SUFFIXES := 
CXXSRC_FILES_SUFFIXES     := cxx cc C cpp
CSRC_FILES_SUFFIXES       := c
FORTRANSRC_FILES_SUFFIXES := F f77 f F77
SRC_FILES_SUFFIXES        := $(CXXSRC_FILES_SUFFIXES) $(CSRC_FILES_SUFFIXES) $(FORTRANSRC_FILES_SUFFIXES) $(CUDASRC_FILES_SUFFIXES)
SCRAM_ADMIN_DIR           := .SCRAM/$(SCRAM_ARCH)
SCRAM_TOOLS_DIR           := $(SCRAM_ADMIN_DIR)/timestamps
CFLAGS:=
LIBRARY_CFLAGS:=
TEST_CFLAGS:=
BINARY_CFLAGS:=
EDM_CFLAGS:=
CAPABILITIES_CFLAGS:=
LCGDICT_CFLAGS:=
ROOTDICT_CFLAGS:=
PRECOMPILE_CFLAGS:=
DEV_CFLAGS:=
RELEASE_CFLAGS:=
REM_CFLAGS:=
REM_LIBRARY_CFLAGS:=
REM_TEST_CFLAGS:=
REM_BINARY_CFLAGS:=
REM_EDM_CFLAGS:=
REM_CAPABILITIES_CFLAGS:=
REM_LCGDICT_CFLAGS:=
REM_ROOTDICT_CFLAGS:=
REM_PRECOMPILE_CFLAGS:=
REM_DEV_CFLAGS:=
REM_RELEASE_CFLAGS:=
CPPDEFINES:=
LIBRARY_CPPDEFINES:=
TEST_CPPDEFINES:=
BINARY_CPPDEFINES:=
EDM_CPPDEFINES:=
CAPABILITIES_CPPDEFINES:=
LCGDICT_CPPDEFINES:=
ROOTDICT_CPPDEFINES:=
PRECOMPILE_CPPDEFINES:=
DEV_CPPDEFINES:=
RELEASE_CPPDEFINES:=
REM_CPPDEFINES:=
REM_LIBRARY_CPPDEFINES:=
REM_TEST_CPPDEFINES:=
REM_BINARY_CPPDEFINES:=
REM_EDM_CPPDEFINES:=
REM_CAPABILITIES_CPPDEFINES:=
REM_LCGDICT_CPPDEFINES:=
REM_ROOTDICT_CPPDEFINES:=
REM_PRECOMPILE_CPPDEFINES:=
REM_DEV_CPPDEFINES:=
REM_RELEASE_CPPDEFINES:=
CPPFLAGS:=
LIBRARY_CPPFLAGS:=
TEST_CPPFLAGS:=
BINARY_CPPFLAGS:=
EDM_CPPFLAGS:=
CAPABILITIES_CPPFLAGS:=
LCGDICT_CPPFLAGS:=
ROOTDICT_CPPFLAGS:=
PRECOMPILE_CPPFLAGS:=
DEV_CPPFLAGS:=
RELEASE_CPPFLAGS:=
REM_CPPFLAGS:=
REM_LIBRARY_CPPFLAGS:=
REM_TEST_CPPFLAGS:=
REM_BINARY_CPPFLAGS:=
REM_EDM_CPPFLAGS:=
REM_CAPABILITIES_CPPFLAGS:=
REM_LCGDICT_CPPFLAGS:=
REM_ROOTDICT_CPPFLAGS:=
REM_PRECOMPILE_CPPFLAGS:=
REM_DEV_CPPFLAGS:=
REM_RELEASE_CPPFLAGS:=
CSHAREDOBJECTFLAGS:=
LIBRARY_CSHAREDOBJECTFLAGS:=
TEST_CSHAREDOBJECTFLAGS:=
BINARY_CSHAREDOBJECTFLAGS:=
EDM_CSHAREDOBJECTFLAGS:=
CAPABILITIES_CSHAREDOBJECTFLAGS:=
LCGDICT_CSHAREDOBJECTFLAGS:=
ROOTDICT_CSHAREDOBJECTFLAGS:=
PRECOMPILE_CSHAREDOBJECTFLAGS:=
DEV_CSHAREDOBJECTFLAGS:=
RELEASE_CSHAREDOBJECTFLAGS:=
REM_CSHAREDOBJECTFLAGS:=
REM_LIBRARY_CSHAREDOBJECTFLAGS:=
REM_TEST_CSHAREDOBJECTFLAGS:=
REM_BINARY_CSHAREDOBJECTFLAGS:=
REM_EDM_CSHAREDOBJECTFLAGS:=
REM_CAPABILITIES_CSHAREDOBJECTFLAGS:=
REM_LCGDICT_CSHAREDOBJECTFLAGS:=
REM_ROOTDICT_CSHAREDOBJECTFLAGS:=
REM_PRECOMPILE_CSHAREDOBJECTFLAGS:=
REM_DEV_CSHAREDOBJECTFLAGS:=
REM_RELEASE_CSHAREDOBJECTFLAGS:=
CXXFLAGS:=
LIBRARY_CXXFLAGS:=
TEST_CXXFLAGS:=
BINARY_CXXFLAGS:=
EDM_CXXFLAGS:=
CAPABILITIES_CXXFLAGS:=
LCGDICT_CXXFLAGS:=
ROOTDICT_CXXFLAGS:=
PRECOMPILE_CXXFLAGS:=
DEV_CXXFLAGS:=
RELEASE_CXXFLAGS:=
REM_CXXFLAGS:=
REM_LIBRARY_CXXFLAGS:=
REM_TEST_CXXFLAGS:=
REM_BINARY_CXXFLAGS:=
REM_EDM_CXXFLAGS:=
REM_CAPABILITIES_CXXFLAGS:=
REM_LCGDICT_CXXFLAGS:=
REM_ROOTDICT_CXXFLAGS:=
REM_PRECOMPILE_CXXFLAGS:=
REM_DEV_CXXFLAGS:=
REM_RELEASE_CXXFLAGS:=
CXXSHAREDFLAGS:=
LIBRARY_CXXSHAREDFLAGS:=
TEST_CXXSHAREDFLAGS:=
BINARY_CXXSHAREDFLAGS:=
EDM_CXXSHAREDFLAGS:=
CAPABILITIES_CXXSHAREDFLAGS:=
LCGDICT_CXXSHAREDFLAGS:=
ROOTDICT_CXXSHAREDFLAGS:=
PRECOMPILE_CXXSHAREDFLAGS:=
DEV_CXXSHAREDFLAGS:=
RELEASE_CXXSHAREDFLAGS:=
REM_CXXSHAREDFLAGS:=
REM_LIBRARY_CXXSHAREDFLAGS:=
REM_TEST_CXXSHAREDFLAGS:=
REM_BINARY_CXXSHAREDFLAGS:=
REM_EDM_CXXSHAREDFLAGS:=
REM_CAPABILITIES_CXXSHAREDFLAGS:=
REM_LCGDICT_CXXSHAREDFLAGS:=
REM_ROOTDICT_CXXSHAREDFLAGS:=
REM_PRECOMPILE_CXXSHAREDFLAGS:=
REM_DEV_CXXSHAREDFLAGS:=
REM_RELEASE_CXXSHAREDFLAGS:=
CXXSHAREDOBJECTFLAGS:=
LIBRARY_CXXSHAREDOBJECTFLAGS:=
TEST_CXXSHAREDOBJECTFLAGS:=
BINARY_CXXSHAREDOBJECTFLAGS:=
EDM_CXXSHAREDOBJECTFLAGS:=
CAPABILITIES_CXXSHAREDOBJECTFLAGS:=
LCGDICT_CXXSHAREDOBJECTFLAGS:=
ROOTDICT_CXXSHAREDOBJECTFLAGS:=
PRECOMPILE_CXXSHAREDOBJECTFLAGS:=
DEV_CXXSHAREDOBJECTFLAGS:=
RELEASE_CXXSHAREDOBJECTFLAGS:=
REM_CXXSHAREDOBJECTFLAGS:=
REM_LIBRARY_CXXSHAREDOBJECTFLAGS:=
REM_TEST_CXXSHAREDOBJECTFLAGS:=
REM_BINARY_CXXSHAREDOBJECTFLAGS:=
REM_EDM_CXXSHAREDOBJECTFLAGS:=
REM_CAPABILITIES_CXXSHAREDOBJECTFLAGS:=
REM_LCGDICT_CXXSHAREDOBJECTFLAGS:=
REM_ROOTDICT_CXXSHAREDOBJECTFLAGS:=
REM_PRECOMPILE_CXXSHAREDOBJECTFLAGS:=
REM_DEV_CXXSHAREDOBJECTFLAGS:=
REM_RELEASE_CXXSHAREDOBJECTFLAGS:=
FFLAGS:=
LIBRARY_FFLAGS:=
TEST_FFLAGS:=
BINARY_FFLAGS:=
EDM_FFLAGS:=
CAPABILITIES_FFLAGS:=
LCGDICT_FFLAGS:=
ROOTDICT_FFLAGS:=
PRECOMPILE_FFLAGS:=
DEV_FFLAGS:=
RELEASE_FFLAGS:=
REM_FFLAGS:=
REM_LIBRARY_FFLAGS:=
REM_TEST_FFLAGS:=
REM_BINARY_FFLAGS:=
REM_EDM_FFLAGS:=
REM_CAPABILITIES_FFLAGS:=
REM_LCGDICT_FFLAGS:=
REM_ROOTDICT_FFLAGS:=
REM_PRECOMPILE_FFLAGS:=
REM_DEV_FFLAGS:=
REM_RELEASE_FFLAGS:=
FOPTIMISEDFLAGS:=
LIBRARY_FOPTIMISEDFLAGS:=
TEST_FOPTIMISEDFLAGS:=
BINARY_FOPTIMISEDFLAGS:=
EDM_FOPTIMISEDFLAGS:=
CAPABILITIES_FOPTIMISEDFLAGS:=
LCGDICT_FOPTIMISEDFLAGS:=
ROOTDICT_FOPTIMISEDFLAGS:=
PRECOMPILE_FOPTIMISEDFLAGS:=
DEV_FOPTIMISEDFLAGS:=
RELEASE_FOPTIMISEDFLAGS:=
REM_FOPTIMISEDFLAGS:=
REM_LIBRARY_FOPTIMISEDFLAGS:=
REM_TEST_FOPTIMISEDFLAGS:=
REM_BINARY_FOPTIMISEDFLAGS:=
REM_EDM_FOPTIMISEDFLAGS:=
REM_CAPABILITIES_FOPTIMISEDFLAGS:=
REM_LCGDICT_FOPTIMISEDFLAGS:=
REM_ROOTDICT_FOPTIMISEDFLAGS:=
REM_PRECOMPILE_FOPTIMISEDFLAGS:=
REM_DEV_FOPTIMISEDFLAGS:=
REM_RELEASE_FOPTIMISEDFLAGS:=
FSHAREDOBJECTFLAGS:=
LIBRARY_FSHAREDOBJECTFLAGS:=
TEST_FSHAREDOBJECTFLAGS:=
BINARY_FSHAREDOBJECTFLAGS:=
EDM_FSHAREDOBJECTFLAGS:=
CAPABILITIES_FSHAREDOBJECTFLAGS:=
LCGDICT_FSHAREDOBJECTFLAGS:=
ROOTDICT_FSHAREDOBJECTFLAGS:=
PRECOMPILE_FSHAREDOBJECTFLAGS:=
DEV_FSHAREDOBJECTFLAGS:=
RELEASE_FSHAREDOBJECTFLAGS:=
REM_FSHAREDOBJECTFLAGS:=
REM_LIBRARY_FSHAREDOBJECTFLAGS:=
REM_TEST_FSHAREDOBJECTFLAGS:=
REM_BINARY_FSHAREDOBJECTFLAGS:=
REM_EDM_FSHAREDOBJECTFLAGS:=
REM_CAPABILITIES_FSHAREDOBJECTFLAGS:=
REM_LCGDICT_FSHAREDOBJECTFLAGS:=
REM_ROOTDICT_FSHAREDOBJECTFLAGS:=
REM_PRECOMPILE_FSHAREDOBJECTFLAGS:=
REM_DEV_FSHAREDOBJECTFLAGS:=
REM_RELEASE_FSHAREDOBJECTFLAGS:=
LDFLAGS:=
LIBRARY_LDFLAGS:=
TEST_LDFLAGS:=
BINARY_LDFLAGS:=
EDM_LDFLAGS:=
CAPABILITIES_LDFLAGS:=
LCGDICT_LDFLAGS:=
ROOTDICT_LDFLAGS:=
PRECOMPILE_LDFLAGS:=
DEV_LDFLAGS:=
RELEASE_LDFLAGS:=
REM_LDFLAGS:=
REM_LIBRARY_LDFLAGS:=
REM_TEST_LDFLAGS:=
REM_BINARY_LDFLAGS:=
REM_EDM_LDFLAGS:=
REM_CAPABILITIES_LDFLAGS:=
REM_LCGDICT_LDFLAGS:=
REM_ROOTDICT_LDFLAGS:=
REM_PRECOMPILE_LDFLAGS:=
REM_DEV_LDFLAGS:=
REM_RELEASE_LDFLAGS:=
LD_UNIT:=
LIBRARY_LD_UNIT:=
TEST_LD_UNIT:=
BINARY_LD_UNIT:=
EDM_LD_UNIT:=
CAPABILITIES_LD_UNIT:=
LCGDICT_LD_UNIT:=
ROOTDICT_LD_UNIT:=
PRECOMPILE_LD_UNIT:=
DEV_LD_UNIT:=
RELEASE_LD_UNIT:=
REM_LD_UNIT:=
REM_LIBRARY_LD_UNIT:=
REM_TEST_LD_UNIT:=
REM_BINARY_LD_UNIT:=
REM_EDM_LD_UNIT:=
REM_CAPABILITIES_LD_UNIT:=
REM_LCGDICT_LD_UNIT:=
REM_ROOTDICT_LD_UNIT:=
REM_PRECOMPILE_LD_UNIT:=
REM_DEV_LD_UNIT:=
REM_RELEASE_LD_UNIT:=
ALL_COMPILER_FLAGS := CFLAGS CPPDEFINES CPPFLAGS CSHAREDOBJECTFLAGS CXXFLAGS CXXSHAREDFLAGS CXXSHAREDOBJECTFLAGS FFLAGS FOPTIMISEDFLAGS FSHAREDOBJECTFLAGS LDFLAGS LD_UNIT 
SCRAM_MULTIPLE_COMPILERS := yes
SCRAM_DEFAULT_COMPILER    := gcc
SCRAM_COMPILER            := $(SCRAM_DEFAULT_COMPILER)
ifdef COMPILER
SCRAM_COMPILER            := $(COMPILER)
endif
CXX_TYPE_COMPILER := cxxcompiler
C_TYPE_COMPILER := ccompiler
F77_TYPE_COMPILER := f77compiler
ifndef SCRAM_IGNORE_MISSING_COMPILERS
$(if $(wildcard $(SCRAM_TOOLS_DIR)/$(SCRAM_COMPILER)-$(CXX_TYPE_COMPILER)),,$(info ****WARNING: You have selected $(SCRAM_COMPILER) as compiler but there is no $(SCRAM_COMPILER)-$(CXX_TYPE_COMPILER) tool setup. Default compiler $(SCRAM_DEFAULT_COMPILER)-$(CXX_TYPE_COMPILER) will be used to comple CXX files))
$(if $(wildcard $(SCRAM_TOOLS_DIR)/$(SCRAM_COMPILER)-$(C_TYPE_COMPILER)),,$(info ****WARNING: You have selected $(SCRAM_COMPILER) as compiler but there is no $(SCRAM_COMPILER)-$(C_TYPE_COMPILER) tool setup. Default compiler $(SCRAM_DEFAULT_COMPILER)-$(C_TYPE_COMPILER) will be used to comple C files))
$(if $(wildcard $(SCRAM_TOOLS_DIR)/$(SCRAM_COMPILER)-$(F77_TYPE_COMPILER)),,$(info ****WARNING: You have selected $(SCRAM_COMPILER) as compiler but there is no $(SCRAM_COMPILER)-$(F77_TYPE_COMPILER) tool setup. Default compiler $(SCRAM_DEFAULT_COMPILER)-$(F77_TYPE_COMPILER) will be used to comple F77 files))
endif
GCC_CXXCOMPILER_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/gcc/4.9.1-cms
CXX:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/gcc/4.9.1-cms/bin/c++
GCC_CCOMPILER_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/gcc/4.9.1-cms
CC:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/gcc/4.9.1-cms/bin/gcc
GCC_F77COMPILER_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/gcc/4.9.1-cms
FC:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/gcc/4.9.1-cms/bin/gfortran
ALL_TOOLS  += cxxcompiler
cxxcompiler_EX_USE    := $(if $(strip $(wildcard $(LOCALTOP)/$(SCRAM_TOOLS_DIR)/$(SCRAM_COMPILER)-cxxcompiler)),$(SCRAM_COMPILER)-cxxcompiler,$(SCRAM_DEFAULT_COMPILER)-cxxcompiler)
ALL_TOOLS  += ccompiler
ccompiler_EX_USE    := $(if $(strip $(wildcard $(LOCALTOP)/$(SCRAM_TOOLS_DIR)/$(SCRAM_COMPILER)-ccompiler)),$(SCRAM_COMPILER)-ccompiler,$(SCRAM_DEFAULT_COMPILER)-ccompiler)
ALL_TOOLS  += f77compiler
f77compiler_EX_USE    := $(if $(strip $(wildcard $(LOCALTOP)/$(SCRAM_TOOLS_DIR)/$(SCRAM_COMPILER)-f77compiler)),$(SCRAM_COMPILER)-f77compiler,$(SCRAM_DEFAULT_COMPILER)-f77compiler)
CMSSW_BASE:=/afs/cern.ch/user/c/chengchi/scratch/Project/BtoD/MC_production/HeavyFlavour_subset/CMSSW_7_5_8_patch3/src/CMSSW_7_5_8_patch3
PROTOBUF_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/protobuf/2.4.1-cms
BINDIR:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/protobuf/2.4.1-cms/bin
GLIBC_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/glibc/2.17-78.el7_2.12-1.166.el6_7.3
LIBTIFF_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/libtiff/3.9.4-cms
PY2_JINJA_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/py2-jinja/2.7.2-eccfad
CLHEP_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/clhep/2.1.4.1-eccfad
FILE_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/file/5.13-cms
HERWIG_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/herwig/6.521-eccfad2
LAPACK_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/lapack/3.3.1-eccfad
PY2_PANDAS_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/py2-pandas/0.16.0-eccfad
LIBHEPML_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/libhepml/0.2.1-cms
BOOST_PYTHON_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/boost/1.57.0-eccfad
GSL_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/gsl/1.10-cms
DOXYGEN_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/doxygen/1.8.5-eccfad
QT3SUPPORT_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/qt/4.8.1-cms
QTEXTRA_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/qt/4.8.1-cms
PY2_CJSON_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/py2-cjson/1.0.5-eccfad
ROOTRFLX_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/lcg/root/6.02.12
RIVET_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/rivet/2.2.1-eccfad2
PY2PYTZ_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/py2-pytz/2014.7-eccfad
QTDESIGNER_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/qt/4.8.1-cms
DPM_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/dpm/1.8.0.1-cms
XROOTD_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/xrootd/4.0.4-eccfad3
GEANT4DATA_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external
ifeq ($(strip $(SCRAM_COMPILER)),distcc)
CXX:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/distcc/3.2rc1-eccfad/bin/c++
endif
MAKE_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/gmake/3.81-cms
OPENLOOPS_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/openloops/1.1.1
DCAP_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/dcap/2.47.8-eccfad
HEPMC_HEADERS_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/hepmc/2.06.07-eccfad
PY2_ORDEREDDICT_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/py2-ordereddict/1.1-eccfad
PY2_DABLOOMS:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/py2-dablooms/0.9.1-eccfad
JIMMY_HEADERS_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/jimmy/4.2-eccfad2
FRONTIER_CLIENT_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/frontier_client/2.8.11-eccfad
LIBUUID_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/libuuid/2.22.2-cms
CMSSW_BASE_FULL_RELEASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/cms/cmssw/CMSSW_7_5_8
CMSSW_BINDIR:=/afs/cern.ch/cms/slc6_amd64_gcc491/cms/cmssw/CMSSW_7_5_8/bin/slc6_amd64_gcc491
EVTGENLHC_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/evtgenlhc/9.1-eccfad
LLVM_CCOMPILER_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/llvm/3.6-eccfad
ifeq ($(strip $(SCRAM_COMPILER)),llvm)
CC:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/llvm/3.6-eccfad/bin/clang
endif
BLACKHAT_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/blackhat/0.9.9-eccfad
PY2_PRETTYTABLE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/py2-prettytable/0.7.2-eccfad
PACPARSER_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/pacparser/1.3.1-cms
CASCADE_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/cascade/2.2.04-eccfad2
LIBXSLT_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/libxslt/1.1.26
MCTESTER_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/mctester/1.25.0a-eccfad7
BOOSTHEADER_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/boost/1.57.0-eccfad
PYTHIA6_HEADERS_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/pythia6/426-cms
PY2_IPYTHON_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/py2-ipython/3.1.0
CASTOR_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/castor/2.1.13.9-cms
TOPREX_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/toprex/4.23-cms
PY2_MATPLOTLIB_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/py2-matplotlib/1.2.1-eccfad2
BOOST_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/boost/1.57.0-eccfad
SIP_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/sip/4.11.2-eccfad2
ORACLE_ADMINDIR:=/afs/cern.ch/cms/slc6_amd64_gcc491/cms/oracle-env/29/etc
TCMALLOC_MINIMAL_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/google-perftools/1.6-cms
FASTJET_CONTRIB_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/fastjet-contrib/1.014-odfocd
LCOV_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/lcov/1.9
PYTHON_LDAP_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/python-ldap/2.4.10-eccfad
PYTHON_LDAP_PYPATH:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/python-ldap/2.4.10-eccfad/lib/python2.7/site-packages
ZLIB_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/zlib/1.2.8-cms
PYMINUIT2_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/pyminuit2/0.0.1-eccfad7
YAML_CPP_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/yaml-cpp/0.5.1-eccfad
XZ_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/xz/5.2.1
LLVM_ANALYZER_CXXCOMPILER_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/llvm/3.6-eccfad
ifeq ($(strip $(SCRAM_COMPILER)),llvm-analyzer)
CXX:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/llvm/3.6-eccfad/bin/c++-analyzer
endif
LIBXML2_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/libxml2/2.7.7-cms
XERCES_C_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/xerces-c/2.8.0-cms
GMP_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/gmp-static/5.1.3-eccfad
LLVM_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/llvm/3.6-eccfad
PHOTOSPP_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/photospp/3.56-eccfad
MCDB_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/mcdb/1.0.2-cms
DB4_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/db4/4.4.20-cms
SHERPA_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/sherpa/2.1.1-eccfad2
PYTHIA6_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/pythia6/426-cms
ifeq ($(strip $(SCRAM_COMPILER)),distcc)
CC:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/distcc/3.2rc1-eccfad/bin/gcc
endif
GEANT4CORE_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/geant4/10.00.p03-eccfad2
G4LIB:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/geant4/10.00.p03-eccfad2/lib
FASTJET_CONTRIB_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/fastjet-contrib/1.014-odfocd
FFTW3_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/fftw3/3.3.2-cms
THEPEG_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/thepeg/1.9.2p1-eccfad2
PY2_DOCOPT:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/py2-docopt/0.6.2-eccfad
LLVM_ANALYZER_CCOMPILER_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/llvm/3.6-eccfad
ifeq ($(strip $(SCRAM_COMPILER)),llvm-analyzer)
CC:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/llvm/3.6-eccfad/bin/ccc-analyzer
endif
QT_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/qt/4.8.1-cms
SIGCPP_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/sigcpp/2.2.10-eccfad
PYQT_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/pyqt/4.8.1-eccfad2
HEPMC_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/hepmc/2.06.07-eccfad
PCRE_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/pcre/7.9__8.33-cms
TAUOLA_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/tauola/27.121.5-cms
LHAPDF_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/lhapdf/6.1.5-eccfad2
ifeq ($(strip $(SCRAM_COMPILER)),ccache)
CC:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/ccache/3.1.8-cms/bin/gcc
endif
ifeq ($(strip $(SCRAM_COMPILER)),ccache)
CXX:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/ccache/3.1.8-cms/bin/c++
export CCACHE_BASEDIR:=/afs/cern.ch/cms/slc6_amd64_gcc491/cms/cmssw-patch/CMSSW_7_5_8_patch3
endif
PY2_PARSIMONIOUS_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/py2-parsimonious/0.6.1-eccfad
ifeq ($(strip $(SCRAM_COMPILER)),llvm)
FC:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/gcc/4.9.1-cms/bin/gfortran
endif
PY2_PYGMENTS_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/py2-pygments/1.6-eccfad
MILLEPEDE_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/millepede/V04-02-02
OPENSSL_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/openssl/0.9.8e__1.0.1-cms
PY2_PYYAML:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/py2-PyYAML/3.11-eccfad
CURL_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/curl/7.28.0-eccfad
GNUPLOT_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/gnuplot/4.6.1-cms
TBB_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/tbb/43_20150316oss
GEANT4STATIC_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/geant4/10.00.p03-eccfad2
DMTCP_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/dmtcp/2.0-2212-cms
ifeq ($(strip $(SCRAM_COMPILER)),ccache)
FC:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/ccache/3.1.8-cms/bin/gfortran
endif
PYDATA_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/pythia6/426-cms
PYCLANG_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/llvm/3.6-eccfad
ALPGEN_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/alpgen/214-cms
LIBUNGIF_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/libungif/4.1.4-cms
PY2_DXR_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/py2-dxr/1.0-eccfad
PY2_CX_ORACLE_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/py2-cx-oracle/5.1-eccfad
GRAPHVIZ_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/graphviz/2.16.1-eccfad
CMSSWDATA_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/cms
CMSSW_DATA_PATH:=/afs/cern.ch/cms/slc6_amd64_gcc491/cms
PY2_NUMPY_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/py2-numpy/1.9.2-eccfad
HECTOR_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/hector/1.3.4-eccfad7
CVS2GIT_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/cvs2git/5419-eccfad
JEMALLOC_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/jemalloc/3.5.0-cms
QTBASE_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/qt/4.8.1-cms
GEANT4_PARFULLCMS:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/geant4-parfullcms/2014.01.27-eccfad3
TAUOLA_HEADERS_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/tauola/27.121.5-cms
ROOTCLING_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/lcg/root/6.02.12
TKONLINESW_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/tkonlinesw/2.7.0-cms
PYTHON_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/python/2.7.6-eccfad
PYTHON_COMPILE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/python/2.7.6-eccfad/lib/python2.7/compileall.py
PY2_NETWORKX:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/py2-networkx/1.8.1-eccfad2
KTJET_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/ktjet/1.06-eccfad
VDT_HEADERS_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/cms/vdt/v0.3.2-eccfad
VDT_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/cms/vdt/v0.3.2-eccfad
PYTHIA8_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/pythia8/212
BZ2LIB_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/bz2lib/1.0.5-cms
GDB_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/gdb/7.8.1-eccfad
LIBJPEG_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/libjpg/8b-cms
CASCADE_HEADERS_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/cascade/2.2.04-eccfad2
ifeq ($(strip $(SCRAM_COMPILER)),distcc)
FC:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/distcc/3.2rc1-eccfad/bin/gfortran
endif
QD_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/qd/2.3.13-cms
SLOCCOUNT_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/sloccount/2.26-eccfad
GDBM_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/gdbm/1.10-cms
PY2_PYGITHUB:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/py2-pygithub/1.23.0-eccfad
DBS_CLIENT_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/cms/dbs-client/DBS_2_1_9-eccfad
EIGEN_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/eigen/3.2.2
CPPUNIT_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/cppunit/1.12.1-cms
EXPAT_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/expat/2.0.1-cms
FFTJET_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/fftjet/1.5.0-cms
PY2_PYCURL_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/py2-pycurl/7.19.0-eccfad
PROFESSOR_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/professor/1.0.0-eccfad8
HERWIGPP_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/herwigpp/2.7.1-eccfad2
ROOT_INTERFACE_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/lcg/root/6.02.12
CASTOR_HEADER_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/castor/2.1.13.9-cms
TAUOLAPP_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/tauolapp/1.1.5-eccfad4
PY2_FUTURES_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/py2-futures/2.2.0-eccfad
HEPPDT_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/heppdt/3.03.00-cms
PY2_SQLALCHEMY_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/py2-sqlalchemy/0.8.2-eccfad2
CORAL_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/cms/coral/CORAL_2_3_21-eccfad9
PY2_LINT_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/py2-lint/0.25.1-eccfad
PY2_MARKUPSAFE_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/py2-markupsafe/0.23-eccfad
MPFR_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/mpfr-static/3.1.2-eccfad
OPENLDAP_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/openldap/2.4.34-cms
DAS_CLIENT_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/cms/das_client/v02.05.00-eccfad
LIBPNG_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/libpng/1.6.16-eccfad
PHOTOS_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/photos/215.5-cms
SQLITE_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/sqlite/3.7.17-cms
CYTHON_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/cython/0.22-eccfad
CLHEPHEADER_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/clhep/2.1.4.1-eccfad
CGAL_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/cgal/4.2-eccfad
JIMMY_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/jimmy/4.2-eccfad2
EVTGEN_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/evtgen/1.3.0-eccfad4
PY2SHIPY_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/py2-scipy/0.8.0-eccfad2
GIT_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/git/1.8.3.1-eccfad
CLASSLIB_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/classlib/3.1.3-eccfad
PY2_SCHEMA:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/py2-schema/0.3.1-eccfad
VALGRIND_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/valgrind/3.10.1-eccfad
IGPROF_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/igprof/5.9.14-eccfad
TCMALLOC_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/google-perftools/1.6-cms
LLVM_CXXCOMPILER_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/llvm/3.6-eccfad
ifeq ($(strip $(SCRAM_COMPILER)),llvm)
CXX:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/llvm/3.6-eccfad/bin/clang++
endif
ORACLE_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/oracle/11.2.0.3.0__10.2.0.4.0-cms
MESCHACH_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/meschach/1.2.pCMS1-cms
ROOFIT_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/lcg/root/6.02.12
TOPREX_HEADERS_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/toprex/4.23-cms
GLIMPSE_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/glimpse/4.18.5-cms
FASTJET_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/fastjet/3.1.0-odfocd
CHARYBDIS_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/charybdis/1.003-eccfad2
PHOTOS_HEADERS_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/photos/215.5-cms
YODA_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/yoda/1.3.1-eccfad
PY2_PYTHON_DATEUTIL_BASE:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/py2-python-dateutil/1.5-eccfad
############## All SCRAM ENV variables ################
LOCALTOP:=/afs/cern.ch/user/c/chengchi/scratch/Project/BtoD/MC_production/HeavyFlavour_subset/CMSSW_7_5_8_patch3/src/CMSSW_7_5_8_patch3
SCRAM_TMP:=tmp
SCRAM_INIT_LOCALTOP:=/afs/cern.ch/user/c/chengchi/scratch/Project/BtoD/MC_production/HeavyFlavour_subset/CMSSW_7_5_8_patch3/src/CMSSW_7_5_8_patch3
SCRAM_BUILDFILE:=BuildFile
RELEASETOP:=/afs/cern.ch/cms/slc6_amd64_gcc491/cms/cmssw-patch/CMSSW_7_5_8_patch3
SCRAM_INTlog:=logs
SCRAM_GMAKE_PATH:=/afs/cern.ch/cms/slc6_amd64_gcc491/external/gmake/3.81-cms/bin/
SCRAM_INTwork:=tmp/slc6_amd64_gcc491
SCRAM_PROJECTNAME:=CMSSW
SCRAM_ARCH:=slc6_amd64_gcc491
SCRAM_SOURCEDIR:=src
SCRAM_RTBOURNE_SET:=CMSSW:CMSSW_7_5_8_patch3:slc6_amd64_gcc491:V2_2_6_pre8:SRT_
SCRAM_CONFIGCHKSUM:=V05-04-10
SCRAM_LOOKUPDB_WRITE:=/afs/.cern.ch/cms
SCRAM_PROJECTVERSION:=CMSSW_7_5_8_patch3
SCRAM_CONFIGDIR:=config
################ ALL SCRAM Stores #######################
ALL_PRODUCT_STORES:=
SCRAMSTORENAME_LOGS:=logs/slc6_amd64_gcc491
ALL_PRODUCT_STORES+=$(SCRAMSTORENAME_LOGS)
SCRAMSTORENAME_LIB:=lib/slc6_amd64_gcc491
ALL_PRODUCT_STORES+=$(SCRAMSTORENAME_LIB)
SCRAMSTORENAME_INCLUDE:=include
ALL_PRODUCT_STORES+=$(SCRAMSTORENAME_INCLUDE)
SCRAMSTORENAME_CFIPYTHON:=cfipython/slc6_amd64_gcc491
ALL_PRODUCT_STORES+=$(SCRAMSTORENAME_CFIPYTHON)
SCRAMSTORENAME_BIGLIB:=biglib/slc6_amd64_gcc491
ALL_PRODUCT_STORES+=$(SCRAMSTORENAME_BIGLIB)
SCRAMSTORENAME_OBJS:=objs/slc6_amd64_gcc491
ALL_PRODUCT_STORES+=$(SCRAMSTORENAME_OBJS)
SCRAMSTORENAME_DOC:=doc
ALL_PRODUCT_STORES+=$(SCRAMSTORENAME_DOC)
SCRAMSTORENAME_TEST:=test/slc6_amd64_gcc491
ALL_PRODUCT_STORES+=$(SCRAMSTORENAME_TEST)
SCRAMSTORENAME_PYTHON:=python
ALL_PRODUCT_STORES+=$(SCRAMSTORENAME_PYTHON)
SCRAMSTORENAME_BIN:=bin/slc6_amd64_gcc491
ALL_PRODUCT_STORES+=$(SCRAMSTORENAME_BIN)
