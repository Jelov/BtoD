ifeq ($(strip $(HiJetAlgosPlugins)),)
HiJetAlgosPlugins := self/src/RecoHI/HiJetAlgos/plugins
PLUGINS:=yes
HiJetAlgosPlugins_files := $(patsubst src/RecoHI/HiJetAlgos/plugins/%,%,$(foreach file,*.cc *.f,$(eval xfile:=$(wildcard src/RecoHI/HiJetAlgos/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/RecoHI/HiJetAlgos/plugins/$(file). Please fix src/RecoHI/HiJetAlgos/plugins/BuildFile.))))
HiJetAlgosPlugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoHI/HiJetAlgos/plugins/BuildFile
HiJetAlgosPlugins_LOC_FLAGS_CXXFLAGS   := -frounding-math -Wno-unknown-pragmas
HiJetAlgosPlugins_LOC_USE := self cmssw FWCore/Framework FWCore/PluginManager RecoJets/JetProducers FWCore/ParameterSet RecoHI/HiJetAlgos DataFormats/JetReco CondFormats/DataRecord CondCore/DBCommon CondCore/DBOutputService CondCore/PopCon JetMETCorrections/Objects Geometry/CaloGeometry cgal f77compiler
HiJetAlgosPlugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,HiJetAlgosPlugins,HiJetAlgosPlugins,$(SCRAMSTORENAME_LIB),src/RecoHI/HiJetAlgos/plugins))
HiJetAlgosPlugins_PACKAGE := self/src/RecoHI/HiJetAlgos/plugins
ALL_PRODS += HiJetAlgosPlugins
RecoHI/HiJetAlgos_forbigobj+=HiJetAlgosPlugins
HiJetAlgosPlugins_INIT_FUNC        += $$(eval $$(call Library,HiJetAlgosPlugins,src/RecoHI/HiJetAlgos/plugins,src_RecoHI_HiJetAlgos_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
HiJetAlgosPlugins_CLASS := LIBRARY
else
$(eval $(call MultipleWarningMsg,HiJetAlgosPlugins,src/RecoHI/HiJetAlgos/plugins))
endif
ALL_COMMONRULES += src_RecoHI_HiJetAlgos_plugins
src_RecoHI_HiJetAlgos_plugins_parent := RecoHI/HiJetAlgos
src_RecoHI_HiJetAlgos_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoHI_HiJetAlgos_plugins,src/RecoHI/HiJetAlgos/plugins,PLUGINS))
