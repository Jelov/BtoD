ifeq ($(strip $(PyHeavyIonsAnalysisVectorBosonAnalysis)),)
PyHeavyIonsAnalysisVectorBosonAnalysis := self/src/HeavyIonsAnalysis/VectorBosonAnalysis/python
src_HeavyIonsAnalysis_VectorBosonAnalysis_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/HeavyIonsAnalysis/VectorBosonAnalysis/python)
PyHeavyIonsAnalysisVectorBosonAnalysis_files := $(patsubst src/HeavyIonsAnalysis/VectorBosonAnalysis/python/%,%,$(wildcard $(foreach dir,src/HeavyIonsAnalysis/VectorBosonAnalysis/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyHeavyIonsAnalysisVectorBosonAnalysis_LOC_USE := self cmssw 
PyHeavyIonsAnalysisVectorBosonAnalysis_PACKAGE := self/src/HeavyIonsAnalysis/VectorBosonAnalysis/python
ALL_PRODS += PyHeavyIonsAnalysisVectorBosonAnalysis
PyHeavyIonsAnalysisVectorBosonAnalysis_INIT_FUNC        += $$(eval $$(call PythonProduct,PyHeavyIonsAnalysisVectorBosonAnalysis,src/HeavyIonsAnalysis/VectorBosonAnalysis/python,src_HeavyIonsAnalysis_VectorBosonAnalysis_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyHeavyIonsAnalysisVectorBosonAnalysis,src/HeavyIonsAnalysis/VectorBosonAnalysis/python))
endif
ALL_COMMONRULES += src_HeavyIonsAnalysis_VectorBosonAnalysis_python
src_HeavyIonsAnalysis_VectorBosonAnalysis_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_HeavyIonsAnalysis_VectorBosonAnalysis_python,src/HeavyIonsAnalysis/VectorBosonAnalysis/python,PYTHON))
