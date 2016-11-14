ALL_SUBSYSTEMS+=Bfinder
subdirs_src_Bfinder = src_Bfinder_Bfinder src_Bfinder_JSON src_Bfinder_batchSub src_Bfinder_crab src_Bfinder_finderMaker src_Bfinder_outDated src_Bfinder_test
ALL_PACKAGES += Bfinder/Bfinder
subdirs_src_Bfinder_Bfinder := src_Bfinder_Bfinder_Dntuple src_Bfinder_Bfinder_interface src_Bfinder_Bfinder_src src_Bfinder_Bfinder_weighPthat
ALL_PACKAGES += Bfinder/JSON
subdirs_src_Bfinder_JSON := 
ALL_PACKAGES += Bfinder/batchSub
subdirs_src_Bfinder_batchSub := 
ALL_PACKAGES += Bfinder/crab
subdirs_src_Bfinder_crab := 
ALL_PACKAGES += Bfinder/finderMaker
subdirs_src_Bfinder_finderMaker := src_Bfinder_finderMaker_python
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
ALL_PACKAGES += Bfinder/outDated
subdirs_src_Bfinder_outDated := 
ALL_PACKAGES += Bfinder/test
subdirs_src_Bfinder_test := 
ALL_SUBSYSTEMS+=HeavyIonsAnalysis
subdirs_src_HeavyIonsAnalysis = src_HeavyIonsAnalysis_Configuration src_HeavyIonsAnalysis_CentralityAnalysis src_HeavyIonsAnalysis_EventAnalysis src_HeavyIonsAnalysis_JetAnalysis src_HeavyIonsAnalysis_MuonAnalysis src_HeavyIonsAnalysis_PhotonAnalysis src_HeavyIonsAnalysis_TrackAnalysis src_HeavyIonsAnalysis_VectorBosonAnalysis src_HeavyIonsAnalysis_VertexAnalysis
ALL_PACKAGES += HeavyIonsAnalysis/CentralityAnalysis
subdirs_src_HeavyIonsAnalysis_CentralityAnalysis := src_HeavyIonsAnalysis_CentralityAnalysis_tools
ALL_PACKAGES += HeavyIonsAnalysis/Configuration
subdirs_src_HeavyIonsAnalysis_Configuration := src_HeavyIonsAnalysis_Configuration_data src_HeavyIonsAnalysis_Configuration_python src_HeavyIonsAnalysis_Configuration_test
ifeq ($(strip $(PyHeavyIonsAnalysisConfiguration)),)
PyHeavyIonsAnalysisConfiguration := self/src/HeavyIonsAnalysis/Configuration/python
src_HeavyIonsAnalysis_Configuration_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/HeavyIonsAnalysis/Configuration/python)
PyHeavyIonsAnalysisConfiguration_files := $(patsubst src/HeavyIonsAnalysis/Configuration/python/%,%,$(wildcard $(foreach dir,src/HeavyIonsAnalysis/Configuration/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyHeavyIonsAnalysisConfiguration_LOC_USE := self cmssw 
PyHeavyIonsAnalysisConfiguration_PACKAGE := self/src/HeavyIonsAnalysis/Configuration/python
ALL_PRODS += PyHeavyIonsAnalysisConfiguration
PyHeavyIonsAnalysisConfiguration_INIT_FUNC        += $$(eval $$(call PythonProduct,PyHeavyIonsAnalysisConfiguration,src/HeavyIonsAnalysis/Configuration/python,src_HeavyIonsAnalysis_Configuration_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyHeavyIonsAnalysisConfiguration,src/HeavyIonsAnalysis/Configuration/python))
endif
ALL_COMMONRULES += src_HeavyIonsAnalysis_Configuration_python
src_HeavyIonsAnalysis_Configuration_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_HeavyIonsAnalysis_Configuration_python,src/HeavyIonsAnalysis/Configuration/python,PYTHON))
ALL_COMMONRULES += src_HeavyIonsAnalysis_Configuration_test
src_HeavyIonsAnalysis_Configuration_test_parent := HeavyIonsAnalysis/Configuration
src_HeavyIonsAnalysis_Configuration_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_HeavyIonsAnalysis_Configuration_test,src/HeavyIonsAnalysis/Configuration/test,TEST))
ALL_PACKAGES += HeavyIonsAnalysis/EventAnalysis
subdirs_src_HeavyIonsAnalysis_EventAnalysis := src_HeavyIonsAnalysis_EventAnalysis_interface src_HeavyIonsAnalysis_EventAnalysis_python src_HeavyIonsAnalysis_EventAnalysis_src src_HeavyIonsAnalysis_EventAnalysis_test
ifeq ($(strip $(PyHeavyIonsAnalysisEventAnalysis)),)
PyHeavyIonsAnalysisEventAnalysis := self/src/HeavyIonsAnalysis/EventAnalysis/python
src_HeavyIonsAnalysis_EventAnalysis_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/HeavyIonsAnalysis/EventAnalysis/python)
PyHeavyIonsAnalysisEventAnalysis_files := $(patsubst src/HeavyIonsAnalysis/EventAnalysis/python/%,%,$(wildcard $(foreach dir,src/HeavyIonsAnalysis/EventAnalysis/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyHeavyIonsAnalysisEventAnalysis_LOC_USE := self cmssw 
PyHeavyIonsAnalysisEventAnalysis_PACKAGE := self/src/HeavyIonsAnalysis/EventAnalysis/python
ALL_PRODS += PyHeavyIonsAnalysisEventAnalysis
PyHeavyIonsAnalysisEventAnalysis_INIT_FUNC        += $$(eval $$(call PythonProduct,PyHeavyIonsAnalysisEventAnalysis,src/HeavyIonsAnalysis/EventAnalysis/python,src_HeavyIonsAnalysis_EventAnalysis_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyHeavyIonsAnalysisEventAnalysis,src/HeavyIonsAnalysis/EventAnalysis/python))
endif
ALL_COMMONRULES += src_HeavyIonsAnalysis_EventAnalysis_python
src_HeavyIonsAnalysis_EventAnalysis_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_HeavyIonsAnalysis_EventAnalysis_python,src/HeavyIonsAnalysis/EventAnalysis/python,PYTHON))
ALL_COMMONRULES += src_HeavyIonsAnalysis_EventAnalysis_test
src_HeavyIonsAnalysis_EventAnalysis_test_parent := HeavyIonsAnalysis/EventAnalysis
src_HeavyIonsAnalysis_EventAnalysis_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_HeavyIonsAnalysis_EventAnalysis_test,src/HeavyIonsAnalysis/EventAnalysis/test,TEST))
ALL_PACKAGES += HeavyIonsAnalysis/JetAnalysis
subdirs_src_HeavyIonsAnalysis_JetAnalysis := src_HeavyIonsAnalysis_JetAnalysis_interface src_HeavyIonsAnalysis_JetAnalysis_python src_HeavyIonsAnalysis_JetAnalysis_src src_HeavyIonsAnalysis_JetAnalysis_test
ifeq ($(strip $(PyHeavyIonsAnalysisJetAnalysis)),)
PyHeavyIonsAnalysisJetAnalysis := self/src/HeavyIonsAnalysis/JetAnalysis/python
src_HeavyIonsAnalysis_JetAnalysis_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/HeavyIonsAnalysis/JetAnalysis/python)
PyHeavyIonsAnalysisJetAnalysis_files := $(patsubst src/HeavyIonsAnalysis/JetAnalysis/python/%,%,$(wildcard $(foreach dir,src/HeavyIonsAnalysis/JetAnalysis/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyHeavyIonsAnalysisJetAnalysis_LOC_USE := self cmssw 
PyHeavyIonsAnalysisJetAnalysis_PACKAGE := self/src/HeavyIonsAnalysis/JetAnalysis/python
ALL_PRODS += PyHeavyIonsAnalysisJetAnalysis
PyHeavyIonsAnalysisJetAnalysis_INIT_FUNC        += $$(eval $$(call PythonProduct,PyHeavyIonsAnalysisJetAnalysis,src/HeavyIonsAnalysis/JetAnalysis/python,src_HeavyIonsAnalysis_JetAnalysis_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyHeavyIonsAnalysisJetAnalysis,src/HeavyIonsAnalysis/JetAnalysis/python))
endif
ALL_COMMONRULES += src_HeavyIonsAnalysis_JetAnalysis_python
src_HeavyIonsAnalysis_JetAnalysis_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_HeavyIonsAnalysis_JetAnalysis_python,src/HeavyIonsAnalysis/JetAnalysis/python,PYTHON))
ALL_COMMONRULES += src_HeavyIonsAnalysis_JetAnalysis_test
src_HeavyIonsAnalysis_JetAnalysis_test_parent := HeavyIonsAnalysis/JetAnalysis
src_HeavyIonsAnalysis_JetAnalysis_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_HeavyIonsAnalysis_JetAnalysis_test,src/HeavyIonsAnalysis/JetAnalysis/test,TEST))
ALL_PACKAGES += HeavyIonsAnalysis/MuonAnalysis
subdirs_src_HeavyIonsAnalysis_MuonAnalysis := src_HeavyIonsAnalysis_MuonAnalysis_python src_HeavyIonsAnalysis_MuonAnalysis_src
ifeq ($(strip $(PyHeavyIonsAnalysisMuonAnalysis)),)
PyHeavyIonsAnalysisMuonAnalysis := self/src/HeavyIonsAnalysis/MuonAnalysis/python
src_HeavyIonsAnalysis_MuonAnalysis_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/HeavyIonsAnalysis/MuonAnalysis/python)
PyHeavyIonsAnalysisMuonAnalysis_files := $(patsubst src/HeavyIonsAnalysis/MuonAnalysis/python/%,%,$(wildcard $(foreach dir,src/HeavyIonsAnalysis/MuonAnalysis/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyHeavyIonsAnalysisMuonAnalysis_LOC_USE := self cmssw 
PyHeavyIonsAnalysisMuonAnalysis_PACKAGE := self/src/HeavyIonsAnalysis/MuonAnalysis/python
ALL_PRODS += PyHeavyIonsAnalysisMuonAnalysis
PyHeavyIonsAnalysisMuonAnalysis_INIT_FUNC        += $$(eval $$(call PythonProduct,PyHeavyIonsAnalysisMuonAnalysis,src/HeavyIonsAnalysis/MuonAnalysis/python,src_HeavyIonsAnalysis_MuonAnalysis_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyHeavyIonsAnalysisMuonAnalysis,src/HeavyIonsAnalysis/MuonAnalysis/python))
endif
ALL_COMMONRULES += src_HeavyIonsAnalysis_MuonAnalysis_python
src_HeavyIonsAnalysis_MuonAnalysis_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_HeavyIonsAnalysis_MuonAnalysis_python,src/HeavyIonsAnalysis/MuonAnalysis/python,PYTHON))
ALL_PACKAGES += HeavyIonsAnalysis/PhotonAnalysis
subdirs_src_HeavyIonsAnalysis_PhotonAnalysis := src_HeavyIonsAnalysis_PhotonAnalysis_plugins src_HeavyIonsAnalysis_PhotonAnalysis_python src_HeavyIonsAnalysis_PhotonAnalysis_src
ifeq ($(strip $(PyHeavyIonsAnalysisPhotonAnalysis)),)
PyHeavyIonsAnalysisPhotonAnalysis := self/src/HeavyIonsAnalysis/PhotonAnalysis/python
src_HeavyIonsAnalysis_PhotonAnalysis_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/HeavyIonsAnalysis/PhotonAnalysis/python)
PyHeavyIonsAnalysisPhotonAnalysis_files := $(patsubst src/HeavyIonsAnalysis/PhotonAnalysis/python/%,%,$(wildcard $(foreach dir,src/HeavyIonsAnalysis/PhotonAnalysis/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyHeavyIonsAnalysisPhotonAnalysis_LOC_USE := self cmssw 
PyHeavyIonsAnalysisPhotonAnalysis_PACKAGE := self/src/HeavyIonsAnalysis/PhotonAnalysis/python
ALL_PRODS += PyHeavyIonsAnalysisPhotonAnalysis
PyHeavyIonsAnalysisPhotonAnalysis_INIT_FUNC        += $$(eval $$(call PythonProduct,PyHeavyIonsAnalysisPhotonAnalysis,src/HeavyIonsAnalysis/PhotonAnalysis/python,src_HeavyIonsAnalysis_PhotonAnalysis_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyHeavyIonsAnalysisPhotonAnalysis,src/HeavyIonsAnalysis/PhotonAnalysis/python))
endif
ALL_COMMONRULES += src_HeavyIonsAnalysis_PhotonAnalysis_python
src_HeavyIonsAnalysis_PhotonAnalysis_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_HeavyIonsAnalysis_PhotonAnalysis_python,src/HeavyIonsAnalysis/PhotonAnalysis/python,PYTHON))
ALL_PACKAGES += HeavyIonsAnalysis/TrackAnalysis
subdirs_src_HeavyIonsAnalysis_TrackAnalysis := src_HeavyIonsAnalysis_TrackAnalysis_python src_HeavyIonsAnalysis_TrackAnalysis_src
ifeq ($(strip $(PyHeavyIonsAnalysisTrackAnalysis)),)
PyHeavyIonsAnalysisTrackAnalysis := self/src/HeavyIonsAnalysis/TrackAnalysis/python
src_HeavyIonsAnalysis_TrackAnalysis_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/HeavyIonsAnalysis/TrackAnalysis/python)
PyHeavyIonsAnalysisTrackAnalysis_files := $(patsubst src/HeavyIonsAnalysis/TrackAnalysis/python/%,%,$(wildcard $(foreach dir,src/HeavyIonsAnalysis/TrackAnalysis/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyHeavyIonsAnalysisTrackAnalysis_LOC_USE := self cmssw 
PyHeavyIonsAnalysisTrackAnalysis_PACKAGE := self/src/HeavyIonsAnalysis/TrackAnalysis/python
ALL_PRODS += PyHeavyIonsAnalysisTrackAnalysis
PyHeavyIonsAnalysisTrackAnalysis_INIT_FUNC        += $$(eval $$(call PythonProduct,PyHeavyIonsAnalysisTrackAnalysis,src/HeavyIonsAnalysis/TrackAnalysis/python,src_HeavyIonsAnalysis_TrackAnalysis_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyHeavyIonsAnalysisTrackAnalysis,src/HeavyIonsAnalysis/TrackAnalysis/python))
endif
ALL_COMMONRULES += src_HeavyIonsAnalysis_TrackAnalysis_python
src_HeavyIonsAnalysis_TrackAnalysis_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_HeavyIonsAnalysis_TrackAnalysis_python,src/HeavyIonsAnalysis/TrackAnalysis/python,PYTHON))
ALL_PACKAGES += HeavyIonsAnalysis/VectorBosonAnalysis
subdirs_src_HeavyIonsAnalysis_VectorBosonAnalysis := src_HeavyIonsAnalysis_VectorBosonAnalysis_plugins src_HeavyIonsAnalysis_VectorBosonAnalysis_python
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
ALL_PACKAGES += HeavyIonsAnalysis/VertexAnalysis
subdirs_src_HeavyIonsAnalysis_VertexAnalysis := src_HeavyIonsAnalysis_VertexAnalysis_interface src_HeavyIonsAnalysis_VertexAnalysis_python src_HeavyIonsAnalysis_VertexAnalysis_src
ifeq ($(strip $(PyHeavyIonsAnalysisVertexAnalysis)),)
PyHeavyIonsAnalysisVertexAnalysis := self/src/HeavyIonsAnalysis/VertexAnalysis/python
src_HeavyIonsAnalysis_VertexAnalysis_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/HeavyIonsAnalysis/VertexAnalysis/python)
PyHeavyIonsAnalysisVertexAnalysis_files := $(patsubst src/HeavyIonsAnalysis/VertexAnalysis/python/%,%,$(wildcard $(foreach dir,src/HeavyIonsAnalysis/VertexAnalysis/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyHeavyIonsAnalysisVertexAnalysis_LOC_USE := self cmssw 
PyHeavyIonsAnalysisVertexAnalysis_PACKAGE := self/src/HeavyIonsAnalysis/VertexAnalysis/python
ALL_PRODS += PyHeavyIonsAnalysisVertexAnalysis
PyHeavyIonsAnalysisVertexAnalysis_INIT_FUNC        += $$(eval $$(call PythonProduct,PyHeavyIonsAnalysisVertexAnalysis,src/HeavyIonsAnalysis/VertexAnalysis/python,src_HeavyIonsAnalysis_VertexAnalysis_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyHeavyIonsAnalysisVertexAnalysis,src/HeavyIonsAnalysis/VertexAnalysis/python))
endif
ALL_COMMONRULES += src_HeavyIonsAnalysis_VertexAnalysis_python
src_HeavyIonsAnalysis_VertexAnalysis_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_HeavyIonsAnalysis_VertexAnalysis_python,src/HeavyIonsAnalysis/VertexAnalysis/python,PYTHON))
ALL_SUBSYSTEMS+=RecoHI
subdirs_src_RecoHI = src_RecoHI_HiJetAlgos
ALL_PACKAGES += RecoHI/HiJetAlgos
subdirs_src_RecoHI_HiJetAlgos := src_RecoHI_HiJetAlgos_plugins src_RecoHI_HiJetAlgos_python src_RecoHI_HiJetAlgos_src src_RecoHI_HiJetAlgos_test
ifeq ($(strip $(PyRecoHIHiJetAlgos)),)
PyRecoHIHiJetAlgos := self/src/RecoHI/HiJetAlgos/python
src_RecoHI_HiJetAlgos_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/RecoHI/HiJetAlgos/python)
PyRecoHIHiJetAlgos_files := $(patsubst src/RecoHI/HiJetAlgos/python/%,%,$(wildcard $(foreach dir,src/RecoHI/HiJetAlgos/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyRecoHIHiJetAlgos_LOC_USE := self cmssw 
PyRecoHIHiJetAlgos_PACKAGE := self/src/RecoHI/HiJetAlgos/python
ALL_PRODS += PyRecoHIHiJetAlgos
PyRecoHIHiJetAlgos_INIT_FUNC        += $$(eval $$(call PythonProduct,PyRecoHIHiJetAlgos,src/RecoHI/HiJetAlgos/python,src_RecoHI_HiJetAlgos_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyRecoHIHiJetAlgos,src/RecoHI/HiJetAlgos/python))
endif
ALL_COMMONRULES += src_RecoHI_HiJetAlgos_python
src_RecoHI_HiJetAlgos_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoHI_HiJetAlgos_python,src/RecoHI/HiJetAlgos/python,PYTHON))
ALL_COMMONRULES += src_RecoHI_HiJetAlgos_test
src_RecoHI_HiJetAlgos_test_parent := RecoHI/HiJetAlgos
src_RecoHI_HiJetAlgos_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoHI_HiJetAlgos_test,src/RecoHI/HiJetAlgos/test,TEST))
ALL_SUBSYSTEMS+=RecoJets
subdirs_src_RecoJets = src_RecoJets_JetProducers
ALL_PACKAGES += RecoJets/JetProducers
subdirs_src_RecoJets_JetProducers := src_RecoJets_JetProducers_data src_RecoJets_JetProducers_doc src_RecoJets_JetProducers_interface src_RecoJets_JetProducers_plugins src_RecoJets_JetProducers_python src_RecoJets_JetProducers_src src_RecoJets_JetProducers_test src_RecoJets_JetProducers_validation
ifeq ($(strip $(PyRecoJetsJetProducers)),)
PyRecoJetsJetProducers := self/src/RecoJets/JetProducers/python
src_RecoJets_JetProducers_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/RecoJets/JetProducers/python)
PyRecoJetsJetProducers_files := $(patsubst src/RecoJets/JetProducers/python/%,%,$(wildcard $(foreach dir,src/RecoJets/JetProducers/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyRecoJetsJetProducers_LOC_USE := self cmssw 
PyRecoJetsJetProducers_PACKAGE := self/src/RecoJets/JetProducers/python
ALL_PRODS += PyRecoJetsJetProducers
PyRecoJetsJetProducers_INIT_FUNC        += $$(eval $$(call PythonProduct,PyRecoJetsJetProducers,src/RecoJets/JetProducers/python,src_RecoJets_JetProducers_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyRecoJetsJetProducers,src/RecoJets/JetProducers/python))
endif
ALL_COMMONRULES += src_RecoJets_JetProducers_python
src_RecoJets_JetProducers_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoJets_JetProducers_python,src/RecoJets/JetProducers/python,PYTHON))
ifeq ($(strip $(test-large-voronoi-area)),)
test-large-voronoi-area_files := $(patsubst src/RecoJets/JetProducers/test/%,%,$(foreach file,test-large-voronoi-area.cc,$(eval xfile:=$(wildcard src/RecoJets/JetProducers/test/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/RecoJets/JetProducers/test/$(file). Please fix src/RecoJets/JetProducers/test/BuildFile.))))
test-large-voronoi-area := self/src/RecoJets/JetProducers/test
test-large-voronoi-area_TEST_RUNNER_CMD :=  test-large-voronoi-area 
test-large-voronoi-area_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoJets/JetProducers/test/BuildFile
test-large-voronoi-area_LOC_USE := self cmssw RecoJets/JetProducers RecoJets/JetAlgorithms FWCore/Framework DataFormats/JetReco DataFormats/VertexReco Geometry/CaloGeometry Geometry/Records CommonTools/UtilAlgos fastjet
test-large-voronoi-area_PACKAGE := self/src/RecoJets/JetProducers/test
ALL_PRODS += test-large-voronoi-area
test-large-voronoi-area_INIT_FUNC        += $$(eval $$(call Binary,test-large-voronoi-area,src/RecoJets/JetProducers/test,src_RecoJets_JetProducers_test,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_TEST),test,$(SCRAMSTORENAME_LOGS)))
test-large-voronoi-area_CLASS := TEST
else
$(eval $(call MultipleWarningMsg,test-large-voronoi-area,src/RecoJets/JetProducers/test))
endif
ALL_COMMONRULES += src_RecoJets_JetProducers_test
src_RecoJets_JetProducers_test_parent := RecoJets/JetProducers
src_RecoJets_JetProducers_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoJets_JetProducers_test,src/RecoJets/JetProducers/test,TEST))
