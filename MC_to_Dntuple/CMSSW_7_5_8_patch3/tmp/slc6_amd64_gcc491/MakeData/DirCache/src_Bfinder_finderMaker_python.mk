ifeq ($(strip $(PyBfinderfinderMaker)),)
PyBfinderfinderMaker := self/src/Bfinder/finderMaker/python
src_Bfinder_finderMaker_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/Bfinder/finderMaker/python)
PyBfinderfinderMaker_files := $(patsubst src/Bfinder/finderMaker/python/%,%,$(wildcard $(foreach dir,src/Bfinder/finderMaker/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyBfinderfinderMaker_LOC_USE := self cmssw 
PyBfinderfinderMaker_PACKAGE := self/src/Bfinder/finderMaker/python
ALL_PRODS += PyBfinderfinderMaker
PyBfinderfinderMaker_INIT_FUNC        += $$(eval $$(call PythonProduct,PyBfinderfinderMaker,src/Bfinder/finderMaker/python,src_Bfinder_finderMaker_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyBfinderfinderMaker,src/Bfinder/finderMaker/python))
endif
ALL_COMMONRULES += src_Bfinder_finderMaker_python
src_Bfinder_finderMaker_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_Bfinder_finderMaker_python,src/Bfinder/finderMaker/python,PYTHON))
