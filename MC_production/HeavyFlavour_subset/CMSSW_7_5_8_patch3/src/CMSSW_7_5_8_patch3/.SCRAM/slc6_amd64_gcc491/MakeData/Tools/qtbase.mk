ALL_TOOLS      += qtbase
qtbase_EX_INCLUDE := /afs/cern.ch/cms/slc6_amd64_gcc491/external/qt/4.8.1-cms/include /afs/cern.ch/cms/slc6_amd64_gcc491/external/qt/4.8.1-cms/include/Qt /afs/cern.ch/cms/slc6_amd64_gcc491/external/qt/4.8.1-cms/include/QtCore /afs/cern.ch/cms/slc6_amd64_gcc491/external/qt/4.8.1-cms/include/QtXml
qtbase_EX_LIB := QtCore QtXml
qtbase_EX_USE := root_cxxdefaults zlib
qtbase_EX_FLAGS_CPPDEFINES  := -DQT_ALTERNATE_QTSMANIP -DQT_CLEAN_NAMESPACE -DQT_THREAD_SUPPORT

