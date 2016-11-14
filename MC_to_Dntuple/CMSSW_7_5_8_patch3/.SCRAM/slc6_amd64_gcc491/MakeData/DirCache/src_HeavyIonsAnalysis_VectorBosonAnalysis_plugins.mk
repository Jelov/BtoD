ifeq ($(strip $(VectorBosonAnalysis)),)
VectorBosonAnalysis := self/src/HeavyIonsAnalysis/VectorBosonAnalysis/plugins
PLUGINS:=yes
VectorBosonAnalysis_files := $(patsubst src/HeavyIonsAnalysis/VectorBosonAnalysis/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/HeavyIonsAnalysis/VectorBosonAnalysis/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/HeavyIonsAnalysis/VectorBosonAnalysis/plugins/$(file). Please fix src/HeavyIonsAnalysis/VectorBosonAnalysis/plugins/BuildFile.))))
VectorBosonAnalysis_BuildFile    := $(WORKINGDIR)/cache/bf/src/HeavyIonsAnalysis/VectorBosonAnalysis/plugins/BuildFile
VectorBosonAnalysis_LOC_USE := self cmssw CondFormats/DataRecord CondFormats/EcalObjects DataFormats/Candidate DataFormats/Common DataFormats/PatCandidates DataFormats/EcalRecHit DataFormats/Math PhysicsTools/UtilAlgos PhysicsTools/CandUtils FWCore/ServiceRegistry FWCore/Framework FWCore/ParameterSet DataFormats/Provenance DataFormats/BeamSpot DataFormats/L1GlobalTrigger RecoEcal/EgammaCoreTools RecoEgamma/EgammaTools RecoEgamma/EgammaMCTools RecoJets/JetAlgorithms CommonTools/Statistics Geometry/Records Geometry/CaloGeometry Geometry/EcalAlgo RecoHI/HiEgammaAlgos DataFormats/HeavyIonEvent HeavyIonsAnalysis/PhotonAnalysis clhep root
VectorBosonAnalysis_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,VectorBosonAnalysis,VectorBosonAnalysis,$(SCRAMSTORENAME_LIB),src/HeavyIonsAnalysis/VectorBosonAnalysis/plugins))
VectorBosonAnalysis_PACKAGE := self/src/HeavyIonsAnalysis/VectorBosonAnalysis/plugins
ALL_PRODS += VectorBosonAnalysis
HeavyIonsAnalysis/VectorBosonAnalysis_forbigobj+=VectorBosonAnalysis
VectorBosonAnalysis_INIT_FUNC        += $$(eval $$(call Library,VectorBosonAnalysis,src/HeavyIonsAnalysis/VectorBosonAnalysis/plugins,src_HeavyIonsAnalysis_VectorBosonAnalysis_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
VectorBosonAnalysis_CLASS := LIBRARY
else
$(eval $(call MultipleWarningMsg,VectorBosonAnalysis,src/HeavyIonsAnalysis/VectorBosonAnalysis/plugins))
endif
ALL_COMMONRULES += src_HeavyIonsAnalysis_VectorBosonAnalysis_plugins
src_HeavyIonsAnalysis_VectorBosonAnalysis_plugins_parent := HeavyIonsAnalysis/VectorBosonAnalysis
src_HeavyIonsAnalysis_VectorBosonAnalysis_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_HeavyIonsAnalysis_VectorBosonAnalysis_plugins,src/HeavyIonsAnalysis/VectorBosonAnalysis/plugins,PLUGINS))
