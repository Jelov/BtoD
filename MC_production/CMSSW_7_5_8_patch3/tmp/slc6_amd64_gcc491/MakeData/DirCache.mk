ALL_SUBSYSTEMS+=HFAnaGenFrags
subdirs_src_HFAnaGenFrags = src_HFAnaGenFrags_Run1Ana src_HFAnaGenFrags_Run2Ana
ALL_PACKAGES += HFAnaGenFrags/Run1Ana
subdirs_src_HFAnaGenFrags_Run1Ana := src_HFAnaGenFrags_Run1Ana_BAna_pPb src_HFAnaGenFrags_Run1Ana_DAna_PbPb
ALL_PACKAGES += HFAnaGenFrags/Run2Ana
subdirs_src_HFAnaGenFrags_Run2Ana := 
ALL_SUBSYSTEMS+=Configuration
subdirs_src_Configuration = src_Configuration_GenProduction
ALL_PACKAGES += Configuration/GenProduction
subdirs_src_Configuration_GenProduction := src_Configuration_GenProduction_python
ifeq ($(strip $(PyConfigurationGenProduction)),)
PyConfigurationGenProduction := self/src/Configuration/GenProduction/python
src_Configuration_GenProduction_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/Configuration/GenProduction/python)
PyConfigurationGenProduction_files := $(patsubst src/Configuration/GenProduction/python/%,%,$(wildcard $(foreach dir,src/Configuration/GenProduction/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyConfigurationGenProduction_LOC_USE := self cmssw 
PyConfigurationGenProduction_PACKAGE := self/src/Configuration/GenProduction/python
ALL_PRODS += PyConfigurationGenProduction
PyConfigurationGenProduction_INIT_FUNC        += $$(eval $$(call PythonProduct,PyConfigurationGenProduction,src/Configuration/GenProduction/python,src_Configuration_GenProduction_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyConfigurationGenProduction,src/Configuration/GenProduction/python))
endif
ALL_COMMONRULES += src_Configuration_GenProduction_python
src_Configuration_GenProduction_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_Configuration_GenProduction_python,src/Configuration/GenProduction/python,PYTHON))
ALL_SUBSYSTEMS+=crab_projects
subdirs_src_crab_projects = src_crab_projects_crab_Pythia8_prompt_D0pt40p0to60p0_Pthat0_TuneCUETP8M1_5020GeV_cfi_evtgen130_py_GEN_SIM_PU
ALL_PACKAGES += crab_projects/crab_Pythia8_prompt_D0pt40p0to60p0_Pthat0_TuneCUETP8M1_5020GeV_cfi_evtgen130_py_GEN_SIM_PU
subdirs_src_crab_projects_crab_Pythia8_prompt_D0pt40p0to60p0_Pthat0_TuneCUETP8M1_5020GeV_cfi_evtgen130_py_GEN_SIM_PU := 
ALL_SUBSYSTEMS+=record
subdirs_src_record = 
