ifeq ($(strip $(RecoHI/HiJetAlgos)),)
ALL_COMMONRULES += src_RecoHI_HiJetAlgos_src
src_RecoHI_HiJetAlgos_src_parent := RecoHI/HiJetAlgos
src_RecoHI_HiJetAlgos_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_RecoHI_HiJetAlgos_src,src/RecoHI/HiJetAlgos/src,LIBRARY))
RecoHIHiJetAlgos := self/RecoHI/HiJetAlgos
RecoHI/HiJetAlgos := RecoHIHiJetAlgos
RecoHIHiJetAlgos_files := $(patsubst src/RecoHI/HiJetAlgos/src/%,%,$(wildcard $(foreach dir,src/RecoHI/HiJetAlgos/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
RecoHIHiJetAlgos_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoHI/HiJetAlgos/BuildFile
RecoHIHiJetAlgos_LOC_USE := self cmssw boost FWCore/Framework RecoJets/JetProducers DataFormats/HeavyIonEvent
RecoHIHiJetAlgos_EX_LIB   := RecoHIHiJetAlgos
RecoHIHiJetAlgos_EX_USE   := $(foreach d,$(RecoHIHiJetAlgos_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
RecoHIHiJetAlgos_PACKAGE := self/src/RecoHI/HiJetAlgos/src
ALL_PRODS += RecoHIHiJetAlgos
RecoHIHiJetAlgos_CLASS := LIBRARY
RecoHI/HiJetAlgos_forbigobj+=RecoHIHiJetAlgos
RecoHIHiJetAlgos_INIT_FUNC        += $$(eval $$(call Library,RecoHIHiJetAlgos,src/RecoHI/HiJetAlgos/src,src_RecoHI_HiJetAlgos_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
