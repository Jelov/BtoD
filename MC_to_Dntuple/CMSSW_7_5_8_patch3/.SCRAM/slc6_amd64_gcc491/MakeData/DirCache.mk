ifeq ($(strip $(Bfinder/Bfinder)),)
ALL_COMMONRULES += src_Bfinder_Bfinder_src
src_Bfinder_Bfinder_src_parent := Bfinder/Bfinder
src_Bfinder_Bfinder_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_Bfinder_Bfinder_src,src/Bfinder/Bfinder/src,LIBRARY))
BfinderBfinder := self/Bfinder/Bfinder
Bfinder/Bfinder := BfinderBfinder
BfinderBfinder_files := $(patsubst src/Bfinder/Bfinder/src/%,%,$(wildcard $(foreach dir,src/Bfinder/Bfinder/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
BfinderBfinder_BuildFile    := $(WORKINGDIR)/cache/bf/src/Bfinder/Bfinder/BuildFile
BfinderBfinder_LOC_USE := self cmssw CommonTools/UtilAlgos CommonTools/CandUtils DataFormats/TrackReco DataFormats/MuonReco DataFormats/VertexReco DataFormats/Common DataFormats/PatCandidates DataFormats/HepMCCandidate DataFormats/Candidate DataFormats/BeamSpot DataFormats/RecoCandidate FWCore/Framework FWCore/PluginManager FWCore/ParameterSet FWCore/MessageLogger FWCore/ServiceRegistry FWCore/Utilities Geometry/CommonDetUnit Geometry/TrackerGeometryBuilder Geometry/Records MagneticField/Engine MagneticField/Records MagneticField/VolumeBasedEngine RecoVertex/VertexPrimitives RecoVertex/KalmanVertexFit RecoVertex/AdaptiveVertexFit RecoVertex/KinematicFitPrimitives RecoVertex/KinematicFit SimTracker/Records SimDataFormats/Vertex SimDataFormats/TrackingAnalysis SimDataFormats/PileupSummaryInfo SimTracker/TrackAssociation TrackingTools/TransientTrack TrackingTools/Records TrackingTools/PatternTools TrackingTools/TrajectoryState root
BfinderBfinder_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,BfinderBfinder,BfinderBfinder,$(SCRAMSTORENAME_LIB),src/Bfinder/Bfinder/src))
BfinderBfinder_PACKAGE := self/src/Bfinder/Bfinder/src
ALL_PRODS += BfinderBfinder
BfinderBfinder_CLASS := LIBRARY
Bfinder/Bfinder_forbigobj+=BfinderBfinder
BfinderBfinder_INIT_FUNC        += $$(eval $$(call Library,BfinderBfinder,src/Bfinder/Bfinder/src,src_Bfinder_Bfinder_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(HeavyIonsAnalysis/EventAnalysis)),)
ALL_COMMONRULES += src_HeavyIonsAnalysis_EventAnalysis_src
src_HeavyIonsAnalysis_EventAnalysis_src_parent := HeavyIonsAnalysis/EventAnalysis
src_HeavyIonsAnalysis_EventAnalysis_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_HeavyIonsAnalysis_EventAnalysis_src,src/HeavyIonsAnalysis/EventAnalysis/src,LIBRARY))
HeavyIonsAnalysisEventAnalysis := self/HeavyIonsAnalysis/EventAnalysis
HeavyIonsAnalysis/EventAnalysis := HeavyIonsAnalysisEventAnalysis
HeavyIonsAnalysisEventAnalysis_files := $(patsubst src/HeavyIonsAnalysis/EventAnalysis/src/%,%,$(wildcard $(foreach dir,src/HeavyIonsAnalysis/EventAnalysis/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
HeavyIonsAnalysisEventAnalysis_BuildFile    := $(WORKINGDIR)/cache/bf/src/HeavyIonsAnalysis/EventAnalysis/BuildFile
HeavyIonsAnalysisEventAnalysis_LOC_USE := self cmssw FWCore/Framework FWCore/PluginManager FWCore/ParameterSet CommonTools/UtilAlgos FWCore/ServiceRegistry DataFormats/HeavyIonEvent DataFormats/VertexReco RecoHI/HiCentralityAlgos DataFormats/HepMCCandidate DataFormats/JetReco DataFormats/Common SimDataFormats/HiGenData SimDataFormats/GeneratorProducts FWCore/Common DataFormats/HLTReco HLTrigger/HLTcore CondFormats/HLTObjects CondFormats/DataRecord
HeavyIonsAnalysisEventAnalysis_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,HeavyIonsAnalysisEventAnalysis,HeavyIonsAnalysisEventAnalysis,$(SCRAMSTORENAME_LIB),src/HeavyIonsAnalysis/EventAnalysis/src))
HeavyIonsAnalysisEventAnalysis_PACKAGE := self/src/HeavyIonsAnalysis/EventAnalysis/src
ALL_PRODS += HeavyIonsAnalysisEventAnalysis
HeavyIonsAnalysisEventAnalysis_CLASS := LIBRARY
HeavyIonsAnalysis/EventAnalysis_forbigobj+=HeavyIonsAnalysisEventAnalysis
HeavyIonsAnalysisEventAnalysis_INIT_FUNC        += $$(eval $$(call Library,HeavyIonsAnalysisEventAnalysis,src/HeavyIonsAnalysis/EventAnalysis/src,src_HeavyIonsAnalysis_EventAnalysis_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(HeavyIonsAnalysis/JetAnalysis)),)
ALL_COMMONRULES += src_HeavyIonsAnalysis_JetAnalysis_src
src_HeavyIonsAnalysis_JetAnalysis_src_parent := HeavyIonsAnalysis/JetAnalysis
src_HeavyIonsAnalysis_JetAnalysis_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_HeavyIonsAnalysis_JetAnalysis_src,src/HeavyIonsAnalysis/JetAnalysis/src,LIBRARY))
HeavyIonsAnalysisJetAnalysis := self/HeavyIonsAnalysis/JetAnalysis
HeavyIonsAnalysis/JetAnalysis := HeavyIonsAnalysisJetAnalysis
HeavyIonsAnalysisJetAnalysis_files := $(patsubst src/HeavyIonsAnalysis/JetAnalysis/src/%,%,$(wildcard $(foreach dir,src/HeavyIonsAnalysis/JetAnalysis/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
HeavyIonsAnalysisJetAnalysis_BuildFile    := $(WORKINGDIR)/cache/bf/src/HeavyIonsAnalysis/JetAnalysis/BuildFile
HeavyIonsAnalysisJetAnalysis_LOC_USE := self cmssw root hepmc boost fastjet fastjet-contrib FWCore/PluginManager FWCore/ParameterSet FWCore/ServiceRegistry FWCore/Framework PhysicsTools/UtilAlgos CommonTools/UtilAlgos Geometry/CaloGeometry Geometry/Records SimGeneral/HepPDTRecord SimDataFormats/GeneratorProducts SimDataFormats/HiGenData SimTracker/TrackAssociation SimTracker/Records DataFormats/HepMCCandidate DataFormats/EcalRecHit DataFormats/HcalRecHit DataFormats/HcalDigi DataFormats/HcalDetId DataFormats/DetId DataFormats/GeometryVector DataFormats/JetReco DataFormats/METReco DataFormats/PatCandidates RecoJets/JetProducers RecoHI/HiJetAlgos DataFormats/HeavyIonEvent CondFormats/JetMETObjects CalibFormats/HcalObjects RecoLocalCalo/HcalRecAlgos RecoBTag/SecondaryVertex
HeavyIonsAnalysisJetAnalysis_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,HeavyIonsAnalysisJetAnalysis,HeavyIonsAnalysisJetAnalysis,$(SCRAMSTORENAME_LIB),src/HeavyIonsAnalysis/JetAnalysis/src))
HeavyIonsAnalysisJetAnalysis_PACKAGE := self/src/HeavyIonsAnalysis/JetAnalysis/src
ALL_PRODS += HeavyIonsAnalysisJetAnalysis
HeavyIonsAnalysisJetAnalysis_CLASS := LIBRARY
HeavyIonsAnalysis/JetAnalysis_forbigobj+=HeavyIonsAnalysisJetAnalysis
HeavyIonsAnalysisJetAnalysis_INIT_FUNC        += $$(eval $$(call Library,HeavyIonsAnalysisJetAnalysis,src/HeavyIonsAnalysis/JetAnalysis/src,src_HeavyIonsAnalysis_JetAnalysis_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(HeavyIonsAnalysis/MuonAnalysis)),)
ALL_COMMONRULES += src_HeavyIonsAnalysis_MuonAnalysis_src
src_HeavyIonsAnalysis_MuonAnalysis_src_parent := HeavyIonsAnalysis/MuonAnalysis
src_HeavyIonsAnalysis_MuonAnalysis_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_HeavyIonsAnalysis_MuonAnalysis_src,src/HeavyIonsAnalysis/MuonAnalysis/src,LIBRARY))
HeavyIonsAnalysisMuonAnalysis := self/HeavyIonsAnalysis/MuonAnalysis
HeavyIonsAnalysis/MuonAnalysis := HeavyIonsAnalysisMuonAnalysis
HeavyIonsAnalysisMuonAnalysis_files := $(patsubst src/HeavyIonsAnalysis/MuonAnalysis/src/%,%,$(wildcard $(foreach dir,src/HeavyIonsAnalysis/MuonAnalysis/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
HeavyIonsAnalysisMuonAnalysis_BuildFile    := $(WORKINGDIR)/cache/bf/src/HeavyIonsAnalysis/MuonAnalysis/BuildFile
HeavyIonsAnalysisMuonAnalysis_LOC_USE := self cmssw clhep root FWCore/Framework FWCore/PluginManager FWCore/ParameterSet FWCore/ServiceRegistry DataFormats/HepMCCandidate DataFormats/MuonReco DataFormats/HeavyIonEvent SimDataFormats/TrackingAnalysis CommonTools/UtilAlgos CondFormats/HIObjects CondFormats/DataRecord TrackingTools/TransientTrack RecoVertex/KalmanVertexFit DataFormats/TrackReco DataFormats/TrackerRecHit2D DataFormats/TrackingRecHit RecoTracker/TkTrackingRegions
HeavyIonsAnalysisMuonAnalysis_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,HeavyIonsAnalysisMuonAnalysis,HeavyIonsAnalysisMuonAnalysis,$(SCRAMSTORENAME_LIB),src/HeavyIonsAnalysis/MuonAnalysis/src))
HeavyIonsAnalysisMuonAnalysis_PACKAGE := self/src/HeavyIonsAnalysis/MuonAnalysis/src
ALL_PRODS += HeavyIonsAnalysisMuonAnalysis
HeavyIonsAnalysisMuonAnalysis_CLASS := LIBRARY
HeavyIonsAnalysis/MuonAnalysis_forbigobj+=HeavyIonsAnalysisMuonAnalysis
HeavyIonsAnalysisMuonAnalysis_INIT_FUNC        += $$(eval $$(call Library,HeavyIonsAnalysisMuonAnalysis,src/HeavyIonsAnalysis/MuonAnalysis/src,src_HeavyIonsAnalysis_MuonAnalysis_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(UserCodeDataAnalyzers_plugins)),)
UserCodeDataAnalyzers_plugins := self/src/HeavyIonsAnalysis/PhotonAnalysis/plugins
PLUGINS:=yes
UserCodeDataAnalyzers_plugins_files := $(patsubst src/HeavyIonsAnalysis/PhotonAnalysis/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/HeavyIonsAnalysis/PhotonAnalysis/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/HeavyIonsAnalysis/PhotonAnalysis/plugins/$(file). Please fix src/HeavyIonsAnalysis/PhotonAnalysis/plugins/BuildFile.))))
UserCodeDataAnalyzers_plugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/HeavyIonsAnalysis/PhotonAnalysis/plugins/BuildFile
UserCodeDataAnalyzers_plugins_LOC_USE := self cmssw CondFormats/DataRecord CondFormats/EcalObjects DataFormats/Candidate DataFormats/Common DataFormats/PatCandidates DataFormats/EcalRecHit DataFormats/Math PhysicsTools/UtilAlgos PhysicsTools/CandUtils FWCore/ServiceRegistry FWCore/Framework FWCore/ParameterSet DataFormats/Provenance DataFormats/BeamSpot DataFormats/L1GlobalTrigger RecoEcal/EgammaCoreTools RecoEgamma/EgammaTools RecoEgamma/EgammaMCTools RecoJets/JetAlgorithms CommonTools/Statistics Geometry/Records Geometry/CaloGeometry Geometry/EcalAlgo RecoHI/HiEgammaAlgos DataFormats/HeavyIonEvent HeavyIonsAnalysis/PhotonAnalysis clhep root
UserCodeDataAnalyzers_plugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,UserCodeDataAnalyzers_plugins,UserCodeDataAnalyzers_plugins,$(SCRAMSTORENAME_LIB),src/HeavyIonsAnalysis/PhotonAnalysis/plugins))
UserCodeDataAnalyzers_plugins_PACKAGE := self/src/HeavyIonsAnalysis/PhotonAnalysis/plugins
ALL_PRODS += UserCodeDataAnalyzers_plugins
HeavyIonsAnalysis/PhotonAnalysis_forbigobj+=UserCodeDataAnalyzers_plugins
UserCodeDataAnalyzers_plugins_INIT_FUNC        += $$(eval $$(call Library,UserCodeDataAnalyzers_plugins,src/HeavyIonsAnalysis/PhotonAnalysis/plugins,src_HeavyIonsAnalysis_PhotonAnalysis_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
UserCodeDataAnalyzers_plugins_CLASS := LIBRARY
else
$(eval $(call MultipleWarningMsg,UserCodeDataAnalyzers_plugins,src/HeavyIonsAnalysis/PhotonAnalysis/plugins))
endif
ALL_COMMONRULES += src_HeavyIonsAnalysis_PhotonAnalysis_plugins
src_HeavyIonsAnalysis_PhotonAnalysis_plugins_parent := HeavyIonsAnalysis/PhotonAnalysis
src_HeavyIonsAnalysis_PhotonAnalysis_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_HeavyIonsAnalysis_PhotonAnalysis_plugins,src/HeavyIonsAnalysis/PhotonAnalysis/plugins,PLUGINS))
ifeq ($(strip $(HeavyIonsAnalysis/PhotonAnalysis)),)
ALL_COMMONRULES += src_HeavyIonsAnalysis_PhotonAnalysis_src
src_HeavyIonsAnalysis_PhotonAnalysis_src_parent := HeavyIonsAnalysis/PhotonAnalysis
src_HeavyIonsAnalysis_PhotonAnalysis_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_HeavyIonsAnalysis_PhotonAnalysis_src,src/HeavyIonsAnalysis/PhotonAnalysis/src,LIBRARY))
HeavyIonsAnalysisPhotonAnalysis := self/HeavyIonsAnalysis/PhotonAnalysis
HeavyIonsAnalysis/PhotonAnalysis := HeavyIonsAnalysisPhotonAnalysis
HeavyIonsAnalysisPhotonAnalysis_files := $(patsubst src/HeavyIonsAnalysis/PhotonAnalysis/src/%,%,$(wildcard $(foreach dir,src/HeavyIonsAnalysis/PhotonAnalysis/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
HeavyIonsAnalysisPhotonAnalysis_BuildFile    := $(WORKINGDIR)/cache/bf/src/HeavyIonsAnalysis/PhotonAnalysis/BuildFile
HeavyIonsAnalysisPhotonAnalysis_LOC_USE := self cmssw CondFormats/DataRecord CondFormats/EcalObjects FWCore/Framework FWCore/ParameterSet DataFormats/HcalRecHit DataFormats/EgammaReco DataFormats/Candidate DataFormats/PatCandidates Geometry/CaloGeometry DataFormats/HepMCCandidate clhep root
HeavyIonsAnalysisPhotonAnalysis_EX_LIB   := HeavyIonsAnalysisPhotonAnalysis
HeavyIonsAnalysisPhotonAnalysis_EX_USE   := $(foreach d,$(HeavyIonsAnalysisPhotonAnalysis_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
HeavyIonsAnalysisPhotonAnalysis_PACKAGE := self/src/HeavyIonsAnalysis/PhotonAnalysis/src
ALL_PRODS += HeavyIonsAnalysisPhotonAnalysis
HeavyIonsAnalysisPhotonAnalysis_CLASS := LIBRARY
HeavyIonsAnalysis/PhotonAnalysis_forbigobj+=HeavyIonsAnalysisPhotonAnalysis
HeavyIonsAnalysisPhotonAnalysis_INIT_FUNC        += $$(eval $$(call Library,HeavyIonsAnalysisPhotonAnalysis,src/HeavyIonsAnalysis/PhotonAnalysis/src,src_HeavyIonsAnalysis_PhotonAnalysis_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(HeavyIonsAnalysis/TrackAnalysis)),)
ALL_COMMONRULES += src_HeavyIonsAnalysis_TrackAnalysis_src
src_HeavyIonsAnalysis_TrackAnalysis_src_parent := HeavyIonsAnalysis/TrackAnalysis
src_HeavyIonsAnalysis_TrackAnalysis_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_HeavyIonsAnalysis_TrackAnalysis_src,src/HeavyIonsAnalysis/TrackAnalysis/src,LIBRARY))
HeavyIonsAnalysisTrackAnalysis := self/HeavyIonsAnalysis/TrackAnalysis
HeavyIonsAnalysis/TrackAnalysis := HeavyIonsAnalysisTrackAnalysis
HeavyIonsAnalysisTrackAnalysis_files := $(patsubst src/HeavyIonsAnalysis/TrackAnalysis/src/%,%,$(wildcard $(foreach dir,src/HeavyIonsAnalysis/TrackAnalysis/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
HeavyIonsAnalysisTrackAnalysis_BuildFile    := $(WORKINGDIR)/cache/bf/src/HeavyIonsAnalysis/TrackAnalysis/BuildFile
HeavyIonsAnalysisTrackAnalysis_LOC_USE := self cmssw hepmc root heppdt DataFormats/Common DataFormats/DetId DataFormats/EcalRecHit DataFormats/GeometryVector DataFormats/HeavyIonEvent DataFormats/SiPixelDigi DataFormats/TrackingRecHit DataFormats/VertexReco DataFormats/HepMCCandidate RecoBTag/SecondaryVertex FWCore/Framework FWCore/ServiceRegistry FWCore/PluginManager FWCore/ParameterSet PhysicsTools/UtilAlgos SimDataFormats/Vertex SimDataFormats/GeneratorProducts SimDataFormats/TrackingAnalysis SimGeneral/HepPDTRecord SimTracker/TrackerHitAssociation SimTracker/TrackAssociation SimTracker/Records Geometry/CaloGeometry Geometry/CommonDetUnit Geometry/TrackerGeometryBuilder Geometry/Records RecoTracker/Record HLTrigger/HLTcore
HeavyIonsAnalysisTrackAnalysis_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,HeavyIonsAnalysisTrackAnalysis,HeavyIonsAnalysisTrackAnalysis,$(SCRAMSTORENAME_LIB),src/HeavyIonsAnalysis/TrackAnalysis/src))
HeavyIonsAnalysisTrackAnalysis_PACKAGE := self/src/HeavyIonsAnalysis/TrackAnalysis/src
ALL_PRODS += HeavyIonsAnalysisTrackAnalysis
HeavyIonsAnalysisTrackAnalysis_CLASS := LIBRARY
HeavyIonsAnalysis/TrackAnalysis_forbigobj+=HeavyIonsAnalysisTrackAnalysis
HeavyIonsAnalysisTrackAnalysis_INIT_FUNC        += $$(eval $$(call Library,HeavyIonsAnalysisTrackAnalysis,src/HeavyIonsAnalysis/TrackAnalysis/src,src_HeavyIonsAnalysis_TrackAnalysis_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
ifeq ($(strip $(HeavyIonsAnalysis/VectorBosonAnalysis)),)
src_HeavyIonsAnalysis_VectorBosonAnalysis := self/HeavyIonsAnalysis/VectorBosonAnalysis
HeavyIonsAnalysis/VectorBosonAnalysis  := src_HeavyIonsAnalysis_VectorBosonAnalysis
src_HeavyIonsAnalysis_VectorBosonAnalysis_BuildFile    := $(WORKINGDIR)/cache/bf/src/HeavyIonsAnalysis/VectorBosonAnalysis/BuildFile
src_HeavyIonsAnalysis_VectorBosonAnalysis_LOC_USE := clhep PhysicsTools/PatAlgos PhysicsTools/PatUtils RecoEcal/EgammaCoreTools FWCore/Framework self DataFormats/VertexReco CondFormats/JetMETObjects DataFormats/EcalRecHit PhysicsTools/CandUtils DataFormats/L1GlobalMuonTrigger Geometry/CaloTopology FWCore/PluginManager FWCore/MessageLogger RecoJets/JetProducers RecoVertex/VertexPrimitives Geometry/Records CommonTools/UtilAlgos DataFormats/L1GlobalTrigger CalibCalorimetry/EcalLaserCorrection RecoJets/JetAlgorithms PhysicsTools/UtilAlgos PhysicsTools/PatExamples CondFormats/PhysicsToolsObjects Geometry/EcalAlgo cmssw DataFormats/EgammaReco RecoEgamma/EgammaTools Geometry/CaloGeometry DataFormats/METReco CondCore/DBOutputService root DataFormats/PatCandidates DataFormats/EgammaCandidates roottmva JetMETCorrections/Objects DataFormats/Common EgammaAnalysis/ElectronTools CondFormats/EgammaObjects TrackingTools/IPTools DataFormats/Candidate JetMETCorrections/Modules FWCore/ServiceRegistry DataFormats/TrackReco RecoLocalCalo/EcalRecAlgos FWCore/Common DataFormats/MuonReco JetMETCorrections/Algorithms FWCore/ParameterSet
src_HeavyIonsAnalysis_VectorBosonAnalysis_EX_USE   := $(foreach d,$(src_HeavyIonsAnalysis_VectorBosonAnalysis_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
ALL_EXTERNAL_PRODS += src_HeavyIonsAnalysis_VectorBosonAnalysis
src_HeavyIonsAnalysis_VectorBosonAnalysis_INIT_FUNC += $$(eval $$(call EmptyPackage,src_HeavyIonsAnalysis_VectorBosonAnalysis,src/HeavyIonsAnalysis/VectorBosonAnalysis))
endif

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
ifeq ($(strip $(HeavyIonsAnalysis/VertexAnalysis)),)
ALL_COMMONRULES += src_HeavyIonsAnalysis_VertexAnalysis_src
src_HeavyIonsAnalysis_VertexAnalysis_src_parent := HeavyIonsAnalysis/VertexAnalysis
src_HeavyIonsAnalysis_VertexAnalysis_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_HeavyIonsAnalysis_VertexAnalysis_src,src/HeavyIonsAnalysis/VertexAnalysis/src,LIBRARY))
HeavyIonsAnalysisVertexAnalysis := self/HeavyIonsAnalysis/VertexAnalysis
HeavyIonsAnalysis/VertexAnalysis := HeavyIonsAnalysisVertexAnalysis
HeavyIonsAnalysisVertexAnalysis_files := $(patsubst src/HeavyIonsAnalysis/VertexAnalysis/src/%,%,$(wildcard $(foreach dir,src/HeavyIonsAnalysis/VertexAnalysis/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
HeavyIonsAnalysisVertexAnalysis_BuildFile    := $(WORKINGDIR)/cache/bf/src/HeavyIonsAnalysis/VertexAnalysis/BuildFile
HeavyIonsAnalysisVertexAnalysis_LOC_USE := self cmssw hepmc FWCore/Framework FWCore/PluginManager FWCore/ParameterSet FWCore/MessageLogger FWCore/Utilities DataFormats/Common DataFormats/FEDRawData DataFormats/SiStripDetId DataFormats/TrackerRecHit2D DataFormats/SiPixelDetId DataFormats/DetId CondFormats/DataRecord CondFormats/SiStripObjects CalibFormats/SiStripObjects CalibTracker/Records FWCore/ServiceRegistry CommonTools/UtilAlgos DataFormats/SiStripCluster DataFormats/SiPixelCluster DataFormats/HeavyIonEvent DataFormats/TrackReco DataFormats/VertexReco DataFormats/HepMCCandidate DataFormats/Math DataFormats/Scalers Geometry/TrackerGeometryBuilder SimTracker/Records SimTracker/TrackAssociation SimTracker/TrackHistory SimDataFormats/GeneratorProducts SimDataFormats/PileupSummaryInfo SimGeneral/HepPDTRecord
HeavyIonsAnalysisVertexAnalysis_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,HeavyIonsAnalysisVertexAnalysis,HeavyIonsAnalysisVertexAnalysis,$(SCRAMSTORENAME_LIB),src/HeavyIonsAnalysis/VertexAnalysis/src))
HeavyIonsAnalysisVertexAnalysis_PACKAGE := self/src/HeavyIonsAnalysis/VertexAnalysis/src
ALL_PRODS += HeavyIonsAnalysisVertexAnalysis
HeavyIonsAnalysisVertexAnalysis_CLASS := LIBRARY
HeavyIonsAnalysis/VertexAnalysis_forbigobj+=HeavyIonsAnalysisVertexAnalysis
HeavyIonsAnalysisVertexAnalysis_INIT_FUNC        += $$(eval $$(call Library,HeavyIonsAnalysisVertexAnalysis,src/HeavyIonsAnalysis/VertexAnalysis/src,src_HeavyIonsAnalysis_VertexAnalysis_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
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
ifeq ($(strip $(RecoJetsJetProducers_plugins)),)
RecoJetsJetProducers_plugins := self/src/RecoJets/JetProducers/plugins
PLUGINS:=yes
RecoJetsJetProducers_plugins_files := $(patsubst src/RecoJets/JetProducers/plugins/%,%,$(foreach file,*.cc,$(eval xfile:=$(wildcard src/RecoJets/JetProducers/plugins/$(file)))$(if $(xfile),$(xfile),$(warning No such file exists: src/RecoJets/JetProducers/plugins/$(file). Please fix src/RecoJets/JetProducers/plugins/BuildFile.))))
RecoJetsJetProducers_plugins_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoJets/JetProducers/plugins/BuildFile
RecoJetsJetProducers_plugins_LOC_USE := self cmssw RecoJets/JetProducers RecoJets/JetAlgorithms FWCore/Framework DataFormats/BTauReco DataFormats/JetReco DataFormats/VertexReco Geometry/CaloGeometry Geometry/Records CommonTools/UtilAlgos CondFormats/JetMETObjects PhysicsTools/UtilAlgos JetMETCorrections/Objects fastjet fastjet-contrib
RecoJetsJetProducers_plugins_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,RecoJetsJetProducers_plugins,RecoJetsJetProducers_plugins,$(SCRAMSTORENAME_LIB),src/RecoJets/JetProducers/plugins))
RecoJetsJetProducers_plugins_PACKAGE := self/src/RecoJets/JetProducers/plugins
ALL_PRODS += RecoJetsJetProducers_plugins
RecoJets/JetProducers_forbigobj+=RecoJetsJetProducers_plugins
RecoJetsJetProducers_plugins_INIT_FUNC        += $$(eval $$(call Library,RecoJetsJetProducers_plugins,src/RecoJets/JetProducers/plugins,src_RecoJets_JetProducers_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
RecoJetsJetProducers_plugins_CLASS := LIBRARY
else
$(eval $(call MultipleWarningMsg,RecoJetsJetProducers_plugins,src/RecoJets/JetProducers/plugins))
endif
ALL_COMMONRULES += src_RecoJets_JetProducers_plugins
src_RecoJets_JetProducers_plugins_parent := RecoJets/JetProducers
src_RecoJets_JetProducers_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_RecoJets_JetProducers_plugins,src/RecoJets/JetProducers/plugins,PLUGINS))
ifeq ($(strip $(RecoJets/JetProducers)),)
ALL_COMMONRULES += src_RecoJets_JetProducers_src
src_RecoJets_JetProducers_src_parent := RecoJets/JetProducers
src_RecoJets_JetProducers_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_RecoJets_JetProducers_src,src/RecoJets/JetProducers/src,LIBRARY))
RecoJetsJetProducers := self/RecoJets/JetProducers
RecoJets/JetProducers := RecoJetsJetProducers
RecoJetsJetProducers_files := $(patsubst src/RecoJets/JetProducers/src/%,%,$(wildcard $(foreach dir,src/RecoJets/JetProducers/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
RecoJetsJetProducers_BuildFile    := $(WORKINGDIR)/cache/bf/src/RecoJets/JetProducers/BuildFile
RecoJetsJetProducers_LOC_USE := self cmssw boost FWCore/Framework DataFormats/JetReco DataFormats/PatCandidates Geometry/CaloGeometry Geometry/CaloTopology Geometry/Records Geometry/CommonDetUnit SimDataFormats/CaloHit RecoJets/JetAlgorithms DataFormats/CastorReco CommonTools/Utils fastjet roottmva vdt_headers boost_serialization CondFormats/DataRecord
RecoJetsJetProducers_EX_LIB   := RecoJetsJetProducers
RecoJetsJetProducers_EX_USE   := $(foreach d,$(RecoJetsJetProducers_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
RecoJetsJetProducers_PACKAGE := self/src/RecoJets/JetProducers/src
ALL_PRODS += RecoJetsJetProducers
RecoJetsJetProducers_CLASS := LIBRARY
RecoJets/JetProducers_forbigobj+=RecoJetsJetProducers
RecoJetsJetProducers_INIT_FUNC        += $$(eval $$(call Library,RecoJetsJetProducers,src/RecoJets/JetProducers/src,src_RecoJets_JetProducers_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
