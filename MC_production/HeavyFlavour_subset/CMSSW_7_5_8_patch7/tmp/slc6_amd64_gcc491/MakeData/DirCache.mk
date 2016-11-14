ALL_SUBSYSTEMS+=HFAnaGenFrags
subdirs_src_HFAnaGenFrags = src_HFAnaGenFrags_DAnaPbPb_HFSubset
ALL_PACKAGES += HFAnaGenFrags/DAnaPbPb_HFSubset
subdirs_src_HFAnaGenFrags_DAnaPbPb_HFSubset := src_HFAnaGenFrags_DAnaPbPb_HFSubset_python
ifeq ($(strip $(PyHFAnaGenFragsDAnaPbPb_HFSubset)),)
PyHFAnaGenFragsDAnaPbPb_HFSubset := self/src/HFAnaGenFrags/DAnaPbPb_HFSubset/python
src_HFAnaGenFrags_DAnaPbPb_HFSubset_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/HFAnaGenFrags/DAnaPbPb_HFSubset/python)
PyHFAnaGenFragsDAnaPbPb_HFSubset_files := $(patsubst src/HFAnaGenFrags/DAnaPbPb_HFSubset/python/%,%,$(wildcard $(foreach dir,src/HFAnaGenFrags/DAnaPbPb_HFSubset/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyHFAnaGenFragsDAnaPbPb_HFSubset_LOC_USE := self cmssw 
PyHFAnaGenFragsDAnaPbPb_HFSubset_PACKAGE := self/src/HFAnaGenFrags/DAnaPbPb_HFSubset/python
ALL_PRODS += PyHFAnaGenFragsDAnaPbPb_HFSubset
PyHFAnaGenFragsDAnaPbPb_HFSubset_INIT_FUNC        += $$(eval $$(call PythonProduct,PyHFAnaGenFragsDAnaPbPb_HFSubset,src/HFAnaGenFrags/DAnaPbPb_HFSubset/python,src_HFAnaGenFrags_DAnaPbPb_HFSubset_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyHFAnaGenFragsDAnaPbPb_HFSubset,src/HFAnaGenFrags/DAnaPbPb_HFSubset/python))
endif
ALL_COMMONRULES += src_HFAnaGenFrags_DAnaPbPb_HFSubset_python
src_HFAnaGenFrags_DAnaPbPb_HFSubset_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_HFAnaGenFrags_DAnaPbPb_HFSubset_python,src/HFAnaGenFrags/DAnaPbPb_HFSubset/python,PYTHON))
