ALL_TOOLS      += boost
boost_EX_INCLUDE := /afs/cern.ch/cms/slc6_amd64_gcc491/external/boost/1.57.0-eccfad/include
boost_EX_LIB := boost_thread boost_signals boost_date_time
boost_EX_USE := root_cxxdefaults sockets
boost_EX_FLAGS_CPPDEFINES  := -DBOOST_SPIRIT_THREADSAFE -DPHOENIX_THREADSAFE

