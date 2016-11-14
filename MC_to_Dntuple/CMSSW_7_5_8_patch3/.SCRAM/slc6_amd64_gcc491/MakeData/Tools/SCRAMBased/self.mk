ifeq ($(strip $(HLTrigger/HLTanalyzers)),)
HLTriggerHLTanalyzers := self/HLTrigger/HLTanalyzers
HLTrigger/HLTanalyzers := HLTriggerHLTanalyzers
HLTriggerHLTanalyzers_BuildFile    := $(RELEASETOP)/.SCRAM/$(SCRAM_ARCH)/MakeData/DirCache.mk
HLTriggerHLTanalyzers_EX_USE := $(foreach d, self cmssw CondFormats/DataRecord CondFormats/L1TObjects DataFormats/BTauReco DataFormats/CSCDigi DataFormats/CaloTowers DataFormats/Candidate DataFormats/Common DataFormats/DTDigi DataFormats/EcalDigi DataFormats/EgammaCandidates DataFormats/EgammaReco DataFormats/FEDRawData DataFormats/GeometryVector DataFormats/HcalDigi DataFormats/JetReco DataFormats/L1CaloTrigger DataFormats/L1GlobalCaloTrigger DataFormats/L1GlobalMuonTrigger DataFormats/L1GlobalTrigger DataFormats/L1Trigger DataFormats/METReco DataFormats/MuonData DataFormats/MuonReco DataFormats/RPCDigi DataFormats/RecoCandidate DataFormats/SiPixelDigi DataFormats/SiStripDigi DataFormats/TauReco DataFormats/TrackReco DataFormats/TrajectorySeed DataFormats/HeavyIonEvent DataFormats/Luminosity SimDataFormats/HiGenData FWCore/Framework FWCore/MessageLogger FWCore/ParameterSet FWCore/PluginManager Geometry/CaloGeometry Geometry/CommonDetUnit Geometry/Records Geometry/EcalMapping HLTrigger/HLTcore L1Trigger/RegionalCaloTrigger MagneticField/Engine MagneticField/Records SimDataFormats/GeneratorProducts SimDataFormats/Track SimDataFormats/Vertex TrackingTools/TrajectoryState RecoEcal/EgammaCoreTools RecoEgamma/EgammaTools RecoHI/HiEgammaAlgos RecoJets/JetProducers TrackingTools/TransientTrack DQMServices/Core rootcore,$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
ALL_EXTERNAL_PRODS += HLTriggerHLTanalyzers
HLTriggerHLTanalyzers_CLASS := LIBRARY
HLTrigger/HLTanalyzers_relbigobj+=HLTriggerHLTanalyzers
endif
ifeq ($(strip $(RecoEcalEcalClusterFunctions)),)
RecoEcalEcalClusterFunctions := self/src/RecoEcal/EgammaCoreTools/plugins
RecoEcalEcalClusterFunctions_LOC_USE := self cmssw RecoEcal/EgammaCoreTools CondFormats/DataRecord CondFormats/EcalObjects
RecoEcal/EgammaCoreTools_relbigobj+=RecoEcalEcalClusterFunctions
endif
ifeq ($(strip $(DQMOffline/EGamma)),)
DQMOfflineEGamma := self/DQMOffline/EGamma
DQMOffline/EGamma := DQMOfflineEGamma
DQMOfflineEGamma_BuildFile    := $(RELEASETOP)/.SCRAM/$(SCRAM_ARCH)/MakeData/DirCache.mk
DQMOfflineEGamma_EX_USE := $(foreach d, self cmssw FWCore/Framework FWCore/ParameterSet DQMServices/Components DQMServices/Core,$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
DQMOfflineEGamma_EX_LIB   := DQMOfflineEGamma
ALL_EXTERNAL_PRODS += DQMOfflineEGamma
DQMOfflineEGamma_CLASS := LIBRARY
DQMOffline/EGamma_relbigobj+=DQMOfflineEGamma
endif
ifeq ($(strip $(PhysicsTools/Heppy)),)
PhysicsToolsHeppy := self/PhysicsTools/Heppy
PhysicsTools/Heppy := PhysicsToolsHeppy
PhysicsToolsHeppy_BuildFile    := $(RELEASETOP)/.SCRAM/$(SCRAM_ARCH)/MakeData/DirCache.mk
PhysicsToolsHeppy_EX_USE := $(foreach d, self cmssw root rootcore rootinteractive rootpy clhepheader DataFormats/Candidate DataFormats/PatCandidates DataFormats/HepMCCandidate fastjet ktjet EgammaAnalysis/ElectronTools boost lhapdf,$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
PhysicsToolsHeppy_LCGDICTS  := x 
PhysicsToolsHeppy_EX_LIB   := PhysicsToolsHeppy
ALL_EXTERNAL_PRODS += PhysicsToolsHeppy
PhysicsToolsHeppy_CLASS := LIBRARY
PhysicsTools/Heppy_relbigobj+=PhysicsToolsHeppy
endif
ifeq ($(strip $(Alignment/OfflineValidation)),)
AlignmentOfflineValidation := self/Alignment/OfflineValidation
Alignment/OfflineValidation := AlignmentOfflineValidation
AlignmentOfflineValidation_BuildFile    := $(RELEASETOP)/.SCRAM/$(SCRAM_ARCH)/MakeData/DirCache.mk
AlignmentOfflineValidation_EX_USE := $(foreach d, self cmssw DataFormats/TrackReco FWCore/PluginManager FWCore/Framework FWCore/Utilities FWCore/ParameterSet FWCore/ServiceRegistry Geometry/TrackerGeometryBuilder TrackingTools/PatternTools TrackingTools/TrackFitters MagneticField/Engine clhep rootmath,$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
AlignmentOfflineValidation_LCGDICTS  := x 
AlignmentOfflineValidation_EX_LIB   := AlignmentOfflineValidation
ALL_EXTERNAL_PRODS += AlignmentOfflineValidation
AlignmentOfflineValidation_CLASS := LIBRARY
Alignment/OfflineValidation_relbigobj+=AlignmentOfflineValidation
endif
ifeq ($(strip $(RecoParticleFlowPFClusterProducerPlugins)),)
RecoParticleFlowPFClusterProducerPlugins := self/src/RecoParticleFlow/PFClusterProducer/plugins
RecoParticleFlowPFClusterProducerPlugins_LOC_USE := self cmssw CondFormats/HcalObjects CondFormats/EcalObjects CondFormats/DataRecord DataFormats/CaloTowers DataFormats/DetId DataFormats/EcalDetId DataFormats/EcalRecHit DataFormats/HcalDetId DataFormats/HcalRecHit DataFormats/Math DataFormats/ParticleFlowReco FWCore/Framework FWCore/MessageLogger FWCore/ParameterSet FWCore/PluginManager Geometry/CaloGeometry Geometry/CaloTopology Geometry/EcalAlgo Geometry/Records RecoLocalCalo/HcalRecAlgos RecoParticleFlow/PFClusterProducer
RecoParticleFlow/PFClusterProducer_relbigobj+=RecoParticleFlowPFClusterProducerPlugins
endif
ifeq ($(strip $(EgammaAnalysisElectronToolsPlugins)),)
EgammaAnalysisElectronToolsPlugins := self/src/EgammaAnalysis/ElectronTools/plugins
EgammaAnalysisElectronToolsPlugins_LOC_USE := self cmssw FWCore/Framework FWCore/PluginManager FWCore/ParameterSet DataFormats/PatCandidates DataFormats/Common DataFormats/VertexReco PhysicsTools/UtilAlgos FWCore/ServiceRegistry Geometry/CaloTopology Geometry/Records EgammaAnalysis/ElectronTools RecoEcal/EgammaCoreTools PhysicsTools/SelectorUtils
EgammaAnalysis/ElectronTools_relbigobj+=EgammaAnalysisElectronToolsPlugins
endif
ifeq ($(strip $(FireworksGeometryMFProducerPlugin)),)
FireworksGeometryMFProducerPlugin := self/src/Fireworks/Geometry/plugins
FireworksGeometryMFProducerPlugin_LOC_USE := self cmssw FWCore/Framework FWCore/PluginManager FWCore/ParameterSet clhep MagneticField/Engine MagneticField/Records rootgpad
Fireworks/Geometry_relbigobj+=FireworksGeometryMFProducerPlugin
endif
ifeq ($(strip $(FireworksGeometryFWRecoGeometryESProducerPlugin)),)
FireworksGeometryFWRecoGeometryESProducerPlugin := self/src/Fireworks/Geometry/plugins
FireworksGeometryFWRecoGeometryESProducerPlugin_LOC_USE := self cmssw Fireworks/Geometry
Fireworks/Geometry_relbigobj+=FireworksGeometryFWRecoGeometryESProducerPlugin
endif
ifeq ($(strip $(FireworksGeometryDumpSimGeometryPlugin)),)
FireworksGeometryDumpSimGeometryPlugin := self/src/Fireworks/Geometry/plugins
FireworksGeometryDumpSimGeometryPlugin_LOC_LIB   := Geom
FireworksGeometryDumpSimGeometryPlugin_LOC_USE := self cmssw Fireworks/Geometry FWCore/Framework FWCore/PluginManager FWCore/ParameterSet
Fireworks/Geometry_relbigobj+=FireworksGeometryDumpSimGeometryPlugin
endif
ifeq ($(strip $(FireworksGeometryDumpFWRecoGeometryPlugin)),)
FireworksGeometryDumpFWRecoGeometryPlugin := self/src/Fireworks/Geometry/plugins
FireworksGeometryDumpFWRecoGeometryPlugin_LOC_LIB   := Eve Geom
FireworksGeometryDumpFWRecoGeometryPlugin_LOC_USE := self cmssw Fireworks/Geometry rootcore FWCore/Framework FWCore/PluginManager FWCore/ParameterSet Geometry/CaloGeometry Geometry/DTGeometry Geometry/CSCGeometry Geometry/RPCGeometry Geometry/TrackerGeometryBuilder Geometry/Records
Fireworks/Geometry_relbigobj+=FireworksGeometryDumpFWRecoGeometryPlugin
endif
ifeq ($(strip $(FireworksGeometryPlugins)),)
FireworksGeometryPlugins := self/src/Fireworks/Geometry/plugins
FireworksGeometryPlugins_LOC_LIB   := Eve Geom
FireworksGeometryPlugins_LOC_USE := self cmssw Geometry/Records Fireworks/Geometry rootgpad
Fireworks/Geometry_relbigobj+=FireworksGeometryPlugins
endif
ifeq ($(strip $(FireworksGeometryDumpFWTGeoRecoGeometryPlugin)),)
FireworksGeometryDumpFWTGeoRecoGeometryPlugin := self/src/Fireworks/Geometry/plugins
FireworksGeometryDumpFWTGeoRecoGeometryPlugin_LOC_LIB   := Eve Geom
FireworksGeometryDumpFWTGeoRecoGeometryPlugin_LOC_USE := self cmssw Fireworks/Geometry rootcore FWCore/Framework FWCore/PluginManager FWCore/ParameterSet Geometry/CaloGeometry Geometry/DTGeometry Geometry/CSCGeometry Geometry/RPCGeometry Geometry/TrackerGeometryBuilder Geometry/Records
Fireworks/Geometry_relbigobj+=FireworksGeometryDumpFWTGeoRecoGeometryPlugin
endif
ifeq ($(strip $(FireworksDisplayGeomPlugin)),)
FireworksDisplayGeomPlugin := self/src/Fireworks/Geometry/plugins
FireworksDisplayGeomPlugin_LOC_LIB   := Eve Geom Physics
FireworksDisplayGeomPlugin_LOC_USE := self cmssw FWCore/Framework Fireworks/Geometry Fireworks/Eve MagneticField/Engine MagneticField/Records
Fireworks/Geometry_relbigobj+=FireworksDisplayGeomPlugin
endif
ifeq ($(strip $(FireworksGeometryValidateGeometryPlugin)),)
FireworksGeometryValidateGeometryPlugin := self/src/Fireworks/Geometry/plugins
FireworksGeometryValidateGeometryPlugin_LOC_LIB   := Geom
FireworksGeometryValidateGeometryPlugin_LOC_USE := self cmssw FWCore/Framework Geometry/RPCGeometry Geometry/DTGeometry Geometry/CSCGeometry Geometry/CaloGeometry Geometry/TrackerGeometryBuilder Geometry/Records Fireworks/Core Fireworks/Tracks rootcore
Fireworks/Geometry_relbigobj+=FireworksGeometryValidateGeometryPlugin
endif
ifeq ($(strip $(FireworksGeometryTGeoMgrFromDddPlugin)),)
FireworksGeometryTGeoMgrFromDddPlugin := self/src/Fireworks/Geometry/plugins
FireworksGeometryTGeoMgrFromDddPlugin_LOC_USE := self cmssw Fireworks/Geometry
Fireworks/Geometry_relbigobj+=FireworksGeometryTGeoMgrFromDddPlugin
endif
ifeq ($(strip $(FireworksGeometryFWTGeoRecoGeometryESProducerPlugin)),)
FireworksGeometryFWTGeoRecoGeometryESProducerPlugin := self/src/Fireworks/Geometry/plugins
FireworksGeometryFWTGeoRecoGeometryESProducerPlugin_LOC_USE := self cmssw Fireworks/Geometry
Fireworks/Geometry_relbigobj+=FireworksGeometryFWTGeoRecoGeometryESProducerPlugin
endif
ifeq ($(strip $(FireworksFWInterfacePlugin)),)
FireworksFWInterfacePlugin := self/src/Fireworks/FWInterface/plugins
FireworksFWInterfacePlugin_LOC_LIB   := Geom Eve
FireworksFWInterfacePlugin_LOC_USE := self cmssw FWCore/PluginManager FWCore/Framework Fireworks/FWInterface CondFormats/DataRecord CondFormats/RunInfo SimDataFormats/Track SimDataFormats/TrackingHit SimDataFormats/CaloHit SimDataFormats/Vertex SimDataFormats/TrackingAnalysis SimGeneral/TrackingAnalysis rootcore
Fireworks/FWInterface_relbigobj+=FireworksFWInterfacePlugin
endif
ifeq ($(strip $(PhysicsTools/PatAlgos)),)
PhysicsToolsPatAlgos := self/PhysicsTools/PatAlgos
PhysicsTools/PatAlgos := PhysicsToolsPatAlgos
PhysicsToolsPatAlgos_BuildFile    := $(RELEASETOP)/.SCRAM/$(SCRAM_ARCH)/MakeData/DirCache.mk
PhysicsToolsPatAlgos_EX_USE := $(foreach d, self cmssw DataFormats/Candidate DataFormats/Common DataFormats/EgammaCandidates DataFormats/EgammaReco DataFormats/JetReco DataFormats/Math DataFormats/METReco DataFormats/MuonReco DataFormats/PatCandidates DataFormats/TauReco DataFormats/TrackReco DataFormats/VertexReco FWCore/Framework FWCore/ParameterSet FWCore/ServiceRegistry FWCore/Utilities PhysicsTools/PatUtils PhysicsTools/Utilities PhysicsTools/IsolationAlgos Geometry/CaloTopology RecoEgamma/EgammaTools clhep,$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
PhysicsToolsPatAlgos_EX_LIB   := PhysicsToolsPatAlgos
ALL_EXTERNAL_PRODS += PhysicsToolsPatAlgos
PhysicsToolsPatAlgos_CLASS := LIBRARY
PhysicsTools/PatAlgos_relbigobj+=PhysicsToolsPatAlgos
endif
ifeq ($(strip $(L1Trigger/L1TCalorimeter)),)
L1TriggerL1TCalorimeter := self/L1Trigger/L1TCalorimeter
L1Trigger/L1TCalorimeter := L1TriggerL1TCalorimeter
L1TriggerL1TCalorimeter_BuildFile    := $(RELEASETOP)/.SCRAM/$(SCRAM_ARCH)/MakeData/DirCache.mk
L1TriggerL1TCalorimeter_EX_USE := $(foreach d, self cmssw FWCore/Framework FWCore/PluginManager FWCore/ParameterSet DataFormats/L1TCalorimeter DataFormats/L1GlobalCaloTrigger CondFormats/L1TObjects CondFormats/DataRecord,$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
L1TriggerL1TCalorimeter_EX_LIB   := L1TriggerL1TCalorimeter
ALL_EXTERNAL_PRODS += L1TriggerL1TCalorimeter
L1TriggerL1TCalorimeter_CLASS := LIBRARY
L1Trigger/L1TCalorimeter_relbigobj+=L1TriggerL1TCalorimeter
endif
ifeq ($(strip $(RecoMuonMuonIsolationProducersPlugins)),)
RecoMuonMuonIsolationProducersPlugins := self/src/RecoMuon/MuonIsolationProducers/plugins
RecoMuonMuonIsolationProducersPlugins_LOC_USE := self cmssw DataFormats/BeamSpot DataFormats/Common DataFormats/MuonReco DataFormats/RecoCandidate DataFormats/TrackReco FWCore/Framework FWCore/MessageLogger FWCore/ParameterSet FWCore/PluginManager PhysicsTools/IsolationAlgos RecoMuon/MuonIsolation
RecoMuon/MuonIsolationProducers_relbigobj+=RecoMuonMuonIsolationProducersPlugins
endif
ifeq ($(strip $(RecoEgamma/PhotonIdentification)),)
RecoEgammaPhotonIdentification := self/RecoEgamma/PhotonIdentification
RecoEgamma/PhotonIdentification := RecoEgammaPhotonIdentification
RecoEgammaPhotonIdentification_BuildFile    := $(RELEASETOP)/.SCRAM/$(SCRAM_ARCH)/MakeData/DirCache.mk
RecoEgammaPhotonIdentification_EX_USE := $(foreach d, self cmssw FWCore/Framework FWCore/PluginManager DataFormats/HcalRecHit DataFormats/EgammaReco DataFormats/PatCandidates DataFormats/ParticleFlowCandidate RecoEcal/EgammaCoreTools DataFormats/BeamSpot Geometry/CaloGeometry RecoEgamma/EgammaIsolationAlgos PhysicsTools/SelectorUtils,$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
RecoEgammaPhotonIdentification_LCGDICTS  := x 
RecoEgammaPhotonIdentification_EX_LIB   := RecoEgammaPhotonIdentification
ALL_EXTERNAL_PRODS += RecoEgammaPhotonIdentification
RecoEgammaPhotonIdentification_CLASS := LIBRARY
RecoEgamma/PhotonIdentification_relbigobj+=RecoEgammaPhotonIdentification
endif
ifeq ($(strip $(RecoEgamma/EgammaTools)),)
RecoEgammaEgammaTools := self/RecoEgamma/EgammaTools
RecoEgamma/EgammaTools := RecoEgammaEgammaTools
RecoEgammaEgammaTools_BuildFile    := $(RELEASETOP)/.SCRAM/$(SCRAM_ARCH)/MakeData/DirCache.mk
RecoEgammaEgammaTools_EX_USE := $(foreach d, self cmssw FWCore/Framework DataFormats/HcalRecHit DataFormats/EgammaReco DataFormats/EgammaCandidates Geometry/CaloGeometry clhep root PhysicsTools/MVAComputer PhysicsTools/MVATrainer CondFormats/DataRecord CondFormats/EgammaObjects RecoEcal/EgammaCoreTools CondCore/DBOutputService DataFormats/ParticleFlowReco roottmva,$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
RecoEgammaEgammaTools_EX_LIB   := RecoEgammaEgammaTools
ALL_EXTERNAL_PRODS += RecoEgammaEgammaTools
RecoEgammaEgammaTools_CLASS := LIBRARY
RecoEgamma/EgammaTools_relbigobj+=RecoEgammaEgammaTools
endif
ifeq ($(strip $(DQMTrackingMonitorSourcePlugins)),)
DQMTrackingMonitorSourcePlugins := self/src/DQM/TrackingMonitorSource/plugins
DQMTrackingMonitorSourcePlugins_LOC_USE := self cmssw TrackingTools/Records FWCore/Framework FWCore/PluginManager FWCore/ParameterSet DQMServices/Core CommonTools/TriggerUtils DataFormats/TrackReco DataFormats/Luminosity DataFormats/VertexReco TrackingTools/TransientTrackingRecHit TrackingTools/TransientTrack TrackingTools/DetLayers TrackPropagation/SteppingHelixPropagator DataFormats/MuonReco Geometry/RPCGeometry RecoMuon/GlobalTrackingTools RecoLocalTracker/SiStripClusterizer
DQM/TrackingMonitorSource_relbigobj+=DQMTrackingMonitorSourcePlugins
endif
ifeq ($(strip $(DQMOffline/Muon)),)
DQMOfflineMuon := self/DQMOffline/Muon
DQMOffline/Muon := DQMOfflineMuon
DQMOfflineMuon_BuildFile    := $(RELEASETOP)/.SCRAM/$(SCRAM_ARCH)/MakeData/DirCache.mk
DQMOfflineMuon_EX_USE := $(foreach d, self cmssw Geometry/CSCGeometry FWCore/Framework DQMServices/Core DQMServices/Components FWCore/PluginManager DataFormats/MuonReco DataFormats/L1GlobalMuonTrigger DataFormats/FEDRawData RecoMuon/TrackingTools TrackingTools/TransientTrack DataFormats/CSCDigi DataFormats/CSCRecHit DataFormats/DTRecHit DataFormats/RPCDigi CondFormats/DTObjects CondFormats/CSCObjects CondFormats/DataRecord EventFilter/CSCRawToDigi CommonTools/TriggerUtils,$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
ALL_EXTERNAL_PRODS += DQMOfflineMuon
DQMOfflineMuon_CLASS := LIBRARY
DQMOffline/Muon_relbigobj+=DQMOfflineMuon
endif
ifeq ($(strip $(TauAnalysis/MCEmbeddingTools)),)
TauAnalysisMCEmbeddingTools := self/TauAnalysis/MCEmbeddingTools
TauAnalysis/MCEmbeddingTools := TauAnalysisMCEmbeddingTools
TauAnalysisMCEmbeddingTools_BuildFile    := $(RELEASETOP)/.SCRAM/$(SCRAM_ARCH)/MakeData/DirCache.mk
TauAnalysisMCEmbeddingTools_EX_USE := $(foreach d, self cmssw FWCore/Framework FWCore/PluginManager FWCore/ParameterSet rootmath boost SimDataFormats/GeneratorProducts DataFormats/HepMCCandidate RecoMuon/MuonIsolation DataFormats/DetId TrackingTools/TrackAssociator DataFormats/VertexReco CommonTools/Utils CommonTools/UtilAlgos GeneratorInterface/ExternalDecays DataFormats/MuonReco DataFormats/EcalRecHit pythia6 GeneratorInterface/Pythia6Interface GeneratorInterface/Core,$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
TauAnalysisMCEmbeddingTools_EX_LIB   := TauAnalysisMCEmbeddingTools
ALL_EXTERNAL_PRODS += TauAnalysisMCEmbeddingTools
TauAnalysisMCEmbeddingTools_CLASS := LIBRARY
TauAnalysis/MCEmbeddingTools_relbigobj+=TauAnalysisMCEmbeddingTools
endif
ifeq ($(strip $(Configuration/Skimming)),)
ConfigurationSkimming := self/Configuration/Skimming
Configuration/Skimming := ConfigurationSkimming
ConfigurationSkimming_BuildFile    := $(RELEASETOP)/.SCRAM/$(SCRAM_ARCH)/MakeData/DirCache.mk
ConfigurationSkimming_EX_USE := $(foreach d, self cmssw FWCore/Framework FWCore/PluginManager FWCore/ParameterSet FWCore/Common DataFormats/EgammaCandidates DataFormats/MuonReco DataFormats/JetReco DataFormats/Common Geometry/CaloTopology Geometry/Records RecoEcal/EgammaCoreTools RecoJets/JetAlgorithms HLTrigger/HLTcore,$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
ALL_EXTERNAL_PRODS += ConfigurationSkimming
ConfigurationSkimming_CLASS := LIBRARY
Configuration/Skimming_relbigobj+=ConfigurationSkimming
endif
ifeq ($(strip $(RecoMuonMuonIdentificationPlugins)),)
RecoMuonMuonIdentificationPlugins := self/src/RecoMuon/MuonIdentification/plugins
RecoMuonMuonIdentificationPlugins_LOC_USE := self cmssw DataFormats/Common DataFormats/MuonDetId DataFormats/MuonReco DataFormats/RecoCandidate DataFormats/TrackReco FWCore/Framework FWCore/MessageLogger FWCore/ParameterSet FWCore/PluginManager Geometry/CommonDetUnit Geometry/Records Geometry/CaloTopology PhysicsTools/IsolationAlgos PhysicsTools/SelectorUtils RecoMuon/MuonIdentification RecoMuon/TrackingTools TrackingTools/Records TrackingTools/TrackAssociator TrackingTools/TransientTrackingRecHit boost_regex CommonTools/Utils DataFormats/ParticleFlowCandidate
RecoMuon/MuonIdentification_relbigobj+=RecoMuonMuonIdentificationPlugins
endif
ifeq ($(strip $(RecoMuonMuonIdentificationPlugins_cuts)),)
RecoMuonMuonIdentificationPlugins_cuts := self/src/RecoMuon/MuonIdentification/plugins
RecoMuonMuonIdentificationPlugins_cuts_LOC_USE := self cmssw DataFormats/Common DataFormats/MuonDetId DataFormats/MuonReco DataFormats/RecoCandidate DataFormats/TrackReco FWCore/Framework FWCore/MessageLogger FWCore/ParameterSet FWCore/PluginManager Geometry/CommonDetUnit Geometry/Records Geometry/CaloTopology PhysicsTools/IsolationAlgos RecoMuon/MuonIdentification RecoMuon/TrackingTools TrackingTools/Records TrackingTools/TrackAssociator TrackingTools/TransientTrackingRecHit boost_regex CommonTools/Utils DataFormats/ParticleFlowCandidate PhysicsTools/SelectorUtils
RecoMuon/MuonIdentification_relbigobj+=RecoMuonMuonIdentificationPlugins_cuts
endif
ifeq ($(strip $(EventFilterSiPixelRawToDigiPlugins)),)
EventFilterSiPixelRawToDigiPlugins := self/src/EventFilter/SiPixelRawToDigi/plugins
EventFilterSiPixelRawToDigiPlugins_LOC_USE := self cmssw EventFilter/SiPixelRawToDigi
EventFilter/SiPixelRawToDigi_relbigobj+=EventFilterSiPixelRawToDigiPlugins
endif
ifeq ($(strip $(TauAnalysisMCEmbeddingToolsPlugins)),)
TauAnalysisMCEmbeddingToolsPlugins := self/src/TauAnalysis/MCEmbeddingTools/plugins
TauAnalysisMCEmbeddingToolsPlugins_LOC_USE := self cmssw FWCore/Framework FWCore/PluginManager FWCore/ParameterSet CommonTools/UtilAlgos CommonTools/Utils DataFormats/CSCRecHit DataFormats/DTRecHit DataFormats/EcalRecHit DataFormats/HepMCCandidate DataFormats/HcalRecHit DataFormats/METReco DataFormats/MuonDetId DataFormats/MuonReco DataFormats/ParticleFlowCandidate DataFormats/PatCandidates DataFormats/RPCRecHit PhysicsTools/JetMCUtils RecoEcal/EgammaCoreTools RecoMuon/MuonIsolation SimDataFormats/GeneratorProducts TrackingTools/TransientTrack DQMServices/Core rootmath TauAnalysis/MCEmbeddingTools
TauAnalysis/MCEmbeddingTools_relbigobj+=TauAnalysisMCEmbeddingToolsPlugins
endif
ifeq ($(strip $(RecoHI/HiEgammaAlgos)),)
RecoHIHiEgammaAlgos := self/RecoHI/HiEgammaAlgos
RecoHI/HiEgammaAlgos := RecoHIHiEgammaAlgos
RecoHIHiEgammaAlgos_BuildFile    := $(RELEASETOP)/.SCRAM/$(SCRAM_ARCH)/MakeData/DirCache.mk
RecoHIHiEgammaAlgos_EX_USE := $(foreach d, self cmssw FWCore/Framework FWCore/ParameterSet DataFormats/EgammaReco DataFormats/Candidate DataFormats/HepMCCandidate Geometry/CaloGeometry RecoEcal/EgammaClusterAlgos DataFormats/EgammaCandidates clhep root,$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
RecoHIHiEgammaAlgos_EX_LIB   := RecoHIHiEgammaAlgos
ALL_EXTERNAL_PRODS += RecoHIHiEgammaAlgos
RecoHIHiEgammaAlgos_CLASS := LIBRARY
RecoHI/HiEgammaAlgos_relbigobj+=RecoHIHiEgammaAlgos
endif
ifeq ($(strip $(DQMOfflineJetMETPlugins)),)
DQMOfflineJetMETPlugins := self/src/DQMOffline/JetMET/plugins
DQMOfflineJetMETPlugins_LOC_USE := self cmssw DQMServices/Components DQMServices/Core FWCore/Utilities FWCore/Framework DataFormats/Common CommonTools/UtilAlgos DataFormats/EgammaCandidates DataFormats/CaloTowers DataFormats/Candidate DataFormats/VertexReco RecoJets/JetAlgorithms RecoJets/JetProducers Validation/RecoJets DataFormats/JetReco
DQMOffline/JetMET_relbigobj+=DQMOfflineJetMETPlugins
endif
ifeq ($(strip $(RecoParticleFlow/PFClusterProducer)),)
RecoParticleFlowPFClusterProducer := self/RecoParticleFlow/PFClusterProducer
RecoParticleFlow/PFClusterProducer := RecoParticleFlowPFClusterProducer
RecoParticleFlowPFClusterProducer_BuildFile    := $(RELEASETOP)/.SCRAM/$(SCRAM_ARCH)/MakeData/DirCache.mk
RecoParticleFlowPFClusterProducer_EX_USE := $(foreach d, self cmssw CondFormats/HcalObjects CondFormats/EcalObjects CondFormats/EgammaObjects CondFormats/DataRecord DataFormats/Common DataFormats/ParticleFlowReco RecoLocalCalo/HcalRecAlgos DataFormats/HcalDetId RecoEcal/EgammaCoreTools RecoParticleFlow/PFClusterTools vdt_headers rootmath root,$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
RecoParticleFlowPFClusterProducer_EX_LIB   := RecoParticleFlowPFClusterProducer
ALL_EXTERNAL_PRODS += RecoParticleFlowPFClusterProducer
RecoParticleFlowPFClusterProducer_CLASS := LIBRARY
RecoParticleFlow/PFClusterProducer_relbigobj+=RecoParticleFlowPFClusterProducer
endif
ifeq ($(strip $(AlignmentCommonAlignmentAuto)),)
AlignmentCommonAlignmentAuto := self/src/Alignment/CommonAlignment/plugins
AlignmentCommonAlignmentAuto_LOC_USE := self cmssw FWCore/Framework FWCore/PluginManager FWCore/ParameterSet CondFormats/DataRecord CondFormats/RunInfo CondFormats/SiStripObjects
Alignment/CommonAlignment_relbigobj+=AlignmentCommonAlignmentAuto
endif
ifeq ($(strip $(Calibration/EcalCalibAlgos)),)
CalibrationEcalCalibAlgos := self/Calibration/EcalCalibAlgos
Calibration/EcalCalibAlgos := CalibrationEcalCalibAlgos
CalibrationEcalCalibAlgos_BuildFile    := $(RELEASETOP)/.SCRAM/$(SCRAM_ARCH)/MakeData/DirCache.mk
CalibrationEcalCalibAlgos_EX_USE := $(foreach d, self cmssw FWCore/Framework FWCore/PluginManager FWCore/ParameterSet DataFormats/EcalRecHit DataFormats/EcalDetId DataFormats/EgammaReco DataFormats/TrackReco DataFormats/EgammaCandidates CondFormats/EcalObjects CondFormats/DataRecord RecoLocalCalo/EcalRecAlgos Geometry/CaloGeometry Geometry/CaloTopology RecoEcal/EgammaClusterAlgos Geometry/EcalAlgo DataFormats/Math RecoEcal/EgammaCoreTools root xerces-c Calibration/Tools CalibCalorimetry/CaloMiscalibTools CondTools/Ecal SimDataFormats/GeneratorProducts,$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
CalibrationEcalCalibAlgos_EX_LIB   := CalibrationEcalCalibAlgos
ALL_EXTERNAL_PRODS += CalibrationEcalCalibAlgos
CalibrationEcalCalibAlgos_CLASS := LIBRARY
Calibration/EcalCalibAlgos_relbigobj+=CalibrationEcalCalibAlgos
endif
ifeq ($(strip $(DQM/Physics)),)
DQMPhysics := self/DQM/Physics
DQM/Physics := DQMPhysics
DQMPhysics_BuildFile    := $(RELEASETOP)/.SCRAM/$(SCRAM_ARCH)/MakeData/DirCache.mk
DQMPhysics_EX_USE := $(foreach d, self cmssw DQMServices/Core FWCore/Framework DataFormats/MuonReco DataFormats/EgammaCandidates DataFormats/EgammaReco DataFormats/BTauReco DataFormats/TauReco DataFormats/JetReco DataFormats/METReco DataFormats/VertexReco DataFormats/TrackerRecHit2D DataFormats/HeavyIonEvent HLTrigger/HLTcore Geometry/Records Geometry/TrackerGeometryBuilder JetMETCorrections/Objects RecoEcal/EgammaCoreTools DataFormats/EcalRecHit CondFormats/DataRecord CondFormats/EcalObjects RecoJets/JetProducers RecoJets/JetAlgorithms,$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
ALL_EXTERNAL_PRODS += DQMPhysics
DQMPhysics_CLASS := LIBRARY
DQM/Physics_relbigobj+=DQMPhysics
endif
ifeq ($(strip $(RecoParticleFlowPFProducerPlugins)),)
RecoParticleFlowPFProducerPlugins := self/src/RecoParticleFlow/PFProducer/plugins
RecoParticleFlowPFProducerPlugins_LOC_USE := self cmssw CondFormats/DataRecord CondFormats/PhysicsToolsObjects DataFormats/CaloRecHit DataFormats/Common DataFormats/EgammaReco DataFormats/EgammaTrackReco DataFormats/GsfTrackReco DataFormats/MuonReco DataFormats/ParticleFlowCandidate DataFormats/ParticleFlowReco FWCore/Framework FWCore/MessageLogger FWCore/ParameterSet FWCore/Utilities RecoParticleFlow/PFClusterTools RecoParticleFlow/PFProducer RecoEcal/EgammaCoreTools Geometry/CaloTopology RecoEgamma/EgammaIsolationAlgos RecoEgamma/PhotonIdentification
RecoParticleFlow/PFProducer_relbigobj+=RecoParticleFlowPFProducerPlugins
endif
ifeq ($(strip $(RecoParticleFlowPFProducerPlugins_importers)),)
RecoParticleFlowPFProducerPlugins_importers := self/src/RecoParticleFlow/PFProducer/plugins
RecoParticleFlowPFProducerPlugins_importers_LOC_USE := self cmssw CondFormats/DataRecord CondFormats/PhysicsToolsObjects DataFormats/CaloRecHit DataFormats/Common DataFormats/EgammaReco DataFormats/EgammaTrackReco DataFormats/GsfTrackReco DataFormats/MuonReco DataFormats/ParticleFlowCandidate DataFormats/ParticleFlowReco FWCore/Framework FWCore/MessageLogger FWCore/ParameterSet FWCore/Utilities RecoParticleFlow/PFClusterTools RecoParticleFlow/PFProducer RecoEcal/EgammaCoreTools Geometry/CaloTopology RecoEgamma/EgammaIsolationAlgos RecoEgamma/PhotonIdentification
RecoParticleFlow/PFProducer_relbigobj+=RecoParticleFlowPFProducerPlugins_importers
endif
ifeq ($(strip $(RecoParticleFlowPFProducerPlugins_linkers)),)
RecoParticleFlowPFProducerPlugins_linkers := self/src/RecoParticleFlow/PFProducer/plugins
RecoParticleFlowPFProducerPlugins_linkers_LOC_USE := self cmssw CondFormats/DataRecord CondFormats/PhysicsToolsObjects DataFormats/CaloRecHit DataFormats/Common DataFormats/EgammaReco DataFormats/EgammaTrackReco DataFormats/GsfTrackReco DataFormats/MuonReco DataFormats/ParticleFlowCandidate DataFormats/ParticleFlowReco FWCore/Framework FWCore/MessageLogger FWCore/ParameterSet FWCore/Utilities RecoParticleFlow/PFClusterTools RecoParticleFlow/PFProducer RecoEcal/EgammaCoreTools Geometry/CaloTopology RecoEgamma/EgammaIsolationAlgos RecoEgamma/PhotonIdentification
RecoParticleFlow/PFProducer_relbigobj+=RecoParticleFlowPFProducerPlugins_linkers
endif
ifeq ($(strip $(RecoParticleFlowPFProducerPlugins_kdtrees)),)
RecoParticleFlowPFProducerPlugins_kdtrees := self/src/RecoParticleFlow/PFProducer/plugins
RecoParticleFlowPFProducerPlugins_kdtrees_LOC_USE := self cmssw CondFormats/DataRecord CondFormats/PhysicsToolsObjects DataFormats/CaloRecHit DataFormats/Common DataFormats/EgammaReco DataFormats/EgammaTrackReco DataFormats/GsfTrackReco DataFormats/MuonReco DataFormats/ParticleFlowCandidate DataFormats/ParticleFlowReco FWCore/Framework FWCore/MessageLogger FWCore/ParameterSet FWCore/Utilities RecoParticleFlow/PFClusterTools RecoParticleFlow/PFProducer RecoEcal/EgammaCoreTools Geometry/CaloTopology RecoEgamma/EgammaIsolationAlgos RecoEgamma/PhotonIdentification
RecoParticleFlow/PFProducer_relbigobj+=RecoParticleFlowPFProducerPlugins_kdtrees
endif
ifeq ($(strip $(PhysicsToolsPatAlgos_plugins)),)
PhysicsToolsPatAlgos_plugins := self/src/PhysicsTools/PatAlgos/plugins
PhysicsToolsPatAlgos_plugins_LOC_USE := self cmssw PhysicsTools/PatAlgos FWCore/Framework FWCore/ParameterSet FWCore/MessageLogger FWCore/MessageService L1Trigger/GlobalTriggerAnalyzer HLTrigger/HLTcore DataFormats/PatCandidates DataFormats/BTauReco DataFormats/JetReco DataFormats/TrackReco DataFormats/Candidate DataFormats/HeavyIonEvent PhysicsTools/PatUtils CondFormats/JetMETObjects CommonTools/CandAlgos JetMETCorrections/Objects JetMETCorrections/JetCorrector TrackingTools/TransientTrack SimDataFormats/Track SimDataFormats/Vertex SimGeneral/HepPDTRecord RecoMET/METAlgorithms RecoEgamma/EgammaTools TrackingTools/IPTools root
PhysicsTools/PatAlgos_relbigobj+=PhysicsToolsPatAlgos_plugins
endif
ifeq ($(strip $(RecoEgammaEgammaToolsPlugins)),)
RecoEgammaEgammaToolsPlugins := self/src/RecoEgamma/EgammaTools/plugins
RecoEgammaEgammaToolsPlugins_LOC_USE := self cmssw FWCore/Framework PhysicsTools/MVAComputer PhysicsTools/MVATrainer CommonTools/CandAlgos CondCore/PluginSystem CondCore/DBOutputService CondFormats/DataRecord CondFormats/EgammaObjects DataFormats/EgammaCandidates RecoEgamma/EgammaTools
RecoEgamma/EgammaTools_relbigobj+=RecoEgammaEgammaToolsPlugins
endif
ifeq ($(strip $(Validation/EcalClusters)),)
ValidationEcalClusters := self/Validation/EcalClusters
Validation/EcalClusters := ValidationEcalClusters
ValidationEcalClusters_BuildFile    := $(RELEASETOP)/.SCRAM/$(SCRAM_ARCH)/MakeData/DirCache.mk
ValidationEcalClusters_EX_USE := $(foreach d, self cmssw FWCore/Framework FWCore/ParameterSet DataFormats/EcalRecHit DataFormats/EgammaReco DataFormats/EcalDetId CondFormats/EcalObjects CondFormats/DataRecord Geometry/CaloGeometry Geometry/CaloTopology Geometry/EcalAlgo DataFormats/Math RecoEcal/EgammaCoreTools DQMServices/Core SimDataFormats/GeneratorProducts SimDataFormats/TrackingHit SimDataFormats/Track SimDataFormats/Vertex CommonTools/UtilAlgos clhep,$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
ALL_EXTERNAL_PRODS += ValidationEcalClusters
ValidationEcalClusters_CLASS := LIBRARY
Validation/EcalClusters_relbigobj+=ValidationEcalClusters
endif
ifeq ($(strip $(GeneratorInterface/GenFilters)),)
GeneratorInterfaceGenFilters := self/GeneratorInterface/GenFilters
GeneratorInterface/GenFilters := GeneratorInterfaceGenFilters
GeneratorInterfaceGenFilters_BuildFile    := $(RELEASETOP)/.SCRAM/$(SCRAM_ARCH)/MakeData/DirCache.mk
GeneratorInterfaceGenFilters_EX_USE := $(foreach d, self cmssw boost FWCore/PluginManager FWCore/ParameterSet FWCore/Framework FWCore/Utilities SimDataFormats/GeneratorProducts heppdt clhep root GeneratorInterface/Pythia6Interface GeneratorInterface/Core SimGeneral/HepPDTRecord DataFormats/GeometryVector DataFormats/GeometrySurface TrackPropagation/SteppingHelixPropagator MagneticField/Records TrackingTools/TrajectoryState TrackingTools/TrajectoryParametrization TrackingTools/Records CommonTools/UtilAlgos FWCore/ServiceRegistry FastSimulation/Particle FastSimulation/BaseParticlePropagator TrackingTools/GeomPropagators DataFormats/HepMCCandidate DataFormats/JetReco DataFormats/EgammaReco,$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
ALL_EXTERNAL_PRODS += GeneratorInterfaceGenFilters
GeneratorInterfaceGenFilters_CLASS := LIBRARY
GeneratorInterface/GenFilters_relbigobj+=GeneratorInterfaceGenFilters
endif
ifeq ($(strip $(RecoEgamma/EgammaPhotonProducers)),)
RecoEgammaEgammaPhotonProducers := self/RecoEgamma/EgammaPhotonProducers
RecoEgamma/EgammaPhotonProducers := RecoEgammaEgammaPhotonProducers
RecoEgammaEgammaPhotonProducers_BuildFile    := $(RELEASETOP)/.SCRAM/$(SCRAM_ARCH)/MakeData/DirCache.mk
RecoEgammaEgammaPhotonProducers_EX_USE := $(foreach d, self cmssw FWCore/Framework FWCore/ParameterSet FWCore/PluginManager DataFormats/ParticleFlowCandidate DataFormats/EgammaCandidates DataFormats/TrajectorySeed DataFormats/Common DataFormats/TrackCandidate DataFormats/TrackReco DataFormats/EgammaTrackReco DataFormats/CaloRecHit DataFormats/Math Geometry/CaloGeometry Geometry/CaloTopology RecoEcal/EgammaCoreTools RecoEgamma/EgammaIsolationAlgos RecoEgamma/EgammaPhotonAlgos RecoEgamma/PhotonIdentification RecoEgamma/EgammaTools RecoTracker/MeasurementDet RecoTracker/CkfPattern RecoTracker/TrackProducer RecoVertex/KinematicFitPrimitives RecoVertex/KinematicFit DataFormats/HcalRecHit RecoCaloTools/Selectors clhep,$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
ALL_EXTERNAL_PRODS += RecoEgammaEgammaPhotonProducers
RecoEgammaEgammaPhotonProducers_CLASS := LIBRARY
RecoEgamma/EgammaPhotonProducers_relbigobj+=RecoEgammaEgammaPhotonProducers
endif
ifeq ($(strip $(ElectroWeakAnalysis/WENu)),)
ElectroWeakAnalysisWENu := self/ElectroWeakAnalysis/WENu
ElectroWeakAnalysis/WENu := ElectroWeakAnalysisWENu
ElectroWeakAnalysisWENu_BuildFile    := $(RELEASETOP)/.SCRAM/$(SCRAM_ARCH)/MakeData/DirCache.mk
ElectroWeakAnalysisWENu_EX_USE := $(foreach d, self cmssw FWCore/Framework FWCore/PluginManager FWCore/ParameterSet DataFormats/PatCandidates DataFormats/Common RecoEgamma/EgammaTools RecoLocalCalo/EcalRecAlgos root rootmath rootcore,$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
ALL_EXTERNAL_PRODS += ElectroWeakAnalysisWENu
ElectroWeakAnalysisWENu_CLASS := LIBRARY
ElectroWeakAnalysis/WENu_relbigobj+=ElectroWeakAnalysisWENu
endif
ifeq ($(strip $(DQMOfflineTriggerPlugins)),)
DQMOfflineTriggerPlugins := self/src/DQMOffline/Trigger/plugins
DQMOfflineTriggerPlugins_LOC_USE := self cmssw FWCore/Framework FWCore/PluginManager FWCore/ParameterSet FWCore/ServiceRegistry DataFormats/RecoCandidate DataFormats/HLTReco DataFormats/MuonReco DataFormats/EgammaReco DataFormats/TrackReco DataFormats/TrajectorySeed DataFormats/BTauReco DataFormats/TauReco DataFormats/METReco DataFormats/JetReco RecoEcal/EgammaCoreTools RecoEgamma/EgammaHLTAlgos HLTrigger/HLTcore CondFormats/DataRecord DQM/HLTEvF root roofit boost
DQMOffline/Trigger_relbigobj+=DQMOfflineTriggerPlugins
endif
ifeq ($(strip $(CondCoreESSourcesPlugins)),)
CondCoreESSourcesPlugins := self/src/CondCore/ESSources/plugins
CondCoreESSourcesPlugins_LOC_USE := self cmssw FWCore/Framework CondCore/ESSources
CondCore/ESSources_relbigobj+=CondCoreESSourcesPlugins
endif
ifeq ($(strip $(RecoEgamma/EgammaIsolationAlgos)),)
RecoEgammaEgammaIsolationAlgos := self/RecoEgamma/EgammaIsolationAlgos
RecoEgamma/EgammaIsolationAlgos := RecoEgammaEgammaIsolationAlgos
RecoEgammaEgammaIsolationAlgos_BuildFile    := $(RELEASETOP)/.SCRAM/$(SCRAM_ARCH)/MakeData/DirCache.mk
RecoEgammaEgammaIsolationAlgos_EX_USE := $(foreach d, self cmssw FWCore/Framework FWCore/PluginManager FWCore/ParameterSet Geometry/CaloGeometry Geometry/CaloTopology RecoCaloTools/Selectors DataFormats/Candidate DataFormats/RecoCandidate DataFormats/ParticleFlowReco DataFormats/ParticleFlowCandidate CondFormats/EcalObjects CondFormats/DataRecord RecoLocalCalo/EcalRecAlgos CommonTools/Statistics,$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
RecoEgammaEgammaIsolationAlgos_EX_LIB   := RecoEgammaEgammaIsolationAlgos
ALL_EXTERNAL_PRODS += RecoEgammaEgammaIsolationAlgos
RecoEgammaEgammaIsolationAlgos_CLASS := LIBRARY
RecoEgamma/EgammaIsolationAlgos_relbigobj+=RecoEgammaEgammaIsolationAlgos
endif
ifeq ($(strip $(CondCore/ESSources)),)
CondCoreESSources := self/CondCore/ESSources
CondCore/ESSources := CondCoreESSources
CondCoreESSources_BuildFile    := $(RELEASETOP)/.SCRAM/$(SCRAM_ARCH)/MakeData/DirCache.mk
CondCoreESSources_EX_USE := $(foreach d, self cmssw FWCore/Framework FWCore/PluginManager FWCore/ParameterSet CondCore/CondDB,$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
CondCoreESSources_EX_LIB   := CondCoreESSources
ALL_EXTERNAL_PRODS += CondCoreESSources
CondCoreESSources_CLASS := LIBRARY
CondCore/ESSources_relbigobj+=CondCoreESSources
endif
ifeq ($(strip $(GeneratorInterfaceHydjet2InterfacePlugins)),)
GeneratorInterfaceHydjet2InterfacePlugins := self/src/GeneratorInterface/Hydjet2Interface/plugins
GeneratorInterfaceHydjet2InterfacePlugins_LOC_USE := self cmssw GeneratorInterface/Hydjet2Interface pydata
GeneratorInterface/Hydjet2Interface_relbigobj+=GeneratorInterfaceHydjet2InterfacePlugins
endif
ifeq ($(strip $(DQMOfflineEGammaPlugins)),)
DQMOfflineEGammaPlugins := self/src/DQMOffline/EGamma/plugins
DQMOfflineEGammaPlugins_LOC_USE := self cmssw DQMOffline/EGamma DataFormats/EgammaReco DataFormats/EgammaCandidates DataFormats/EcalRecHit DataFormats/MuonReco RecoEcal/EgammaCoreTools DataFormats/Math RecoEgamma/EgammaIsolationAlgos Geometry/CaloTopology Geometry/CaloGeometry DQMServices/Components DQMServices/Core HLTrigger/HLTcore clhep CommonTools/Statistics CommonTools/UtilAlgos root roofit boost
DQMOffline/EGamma_relbigobj+=DQMOfflineEGammaPlugins
endif
ifeq ($(strip $(RecoEgammaElectronIdentificationPlugins_cuts)),)
RecoEgammaElectronIdentificationPlugins_cuts := self/src/RecoEgamma/ElectronIdentification/plugins
RecoEgammaElectronIdentificationPlugins_cuts_LOC_USE := self cmssw FWCore/Framework FWCore/ParameterSet FWCore/MessageLogger FWCore/ServiceRegistry CondFormats/DataRecord CondFormats/EgammaObjects DataFormats/EgammaCandidates DataFormats/EcalRecHit root rootcore RecoEgamma/EgammaTools RecoEgamma/ElectronIdentification
RecoEgamma/ElectronIdentification_relbigobj+=RecoEgammaElectronIdentificationPlugins_cuts
endif
ifeq ($(strip $(RecoEgammaElectronIdentificationPlugins)),)
RecoEgammaElectronIdentificationPlugins := self/src/RecoEgamma/ElectronIdentification/plugins
RecoEgammaElectronIdentificationPlugins_LOC_USE := self cmssw FWCore/Framework FWCore/ParameterSet FWCore/MessageLogger FWCore/ServiceRegistry CondFormats/DataRecord CondFormats/EgammaObjects DataFormats/EgammaCandidates DataFormats/EcalRecHit root rootcore RecoEgamma/EgammaTools RecoEgamma/ElectronIdentification
RecoEgamma/ElectronIdentification_relbigobj+=RecoEgammaElectronIdentificationPlugins
endif
ifeq ($(strip $(Validation/Performance)),)
ValidationPerformance := self/Validation/Performance
Validation/Performance := ValidationPerformance
ValidationPerformance_BuildFile    := $(RELEASETOP)/.SCRAM/$(SCRAM_ARCH)/MakeData/DirCache.mk
ValidationPerformance_EX_USE := $(foreach d, self cmssw FWCore/Framework FWCore/ParameterSet DataFormats/Common DataFormats/HLTReco DQMServices/Core root,$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
ALL_EXTERNAL_PRODS += ValidationPerformance
ValidationPerformance_CLASS := LIBRARY
Validation/Performance_relbigobj+=ValidationPerformance
endif
ifeq ($(strip $(RecoEgamma/EgammaPhotonAlgos)),)
RecoEgammaEgammaPhotonAlgos := self/RecoEgamma/EgammaPhotonAlgos
RecoEgamma/EgammaPhotonAlgos := RecoEgammaEgammaPhotonAlgos
RecoEgammaEgammaPhotonAlgos_BuildFile    := $(RELEASETOP)/.SCRAM/$(SCRAM_ARCH)/MakeData/DirCache.mk
RecoEgammaEgammaPhotonAlgos_LOC_FLAGS_CXXFLAGS   := -Ofast
RecoEgammaEgammaPhotonAlgos_EX_USE := $(foreach d, self cmssw FWCore/Framework FWCore/ParameterSet Geometry/CaloGeometry Geometry/CaloTopology DataFormats/CaloRecHit DataFormats/DetId RecoEgamma/EgammaTools DataFormats/Math DataFormats/EgammaCandidates DataFormats/Common DataFormats/TrajectorySeed TrackingTools/MaterialEffects TrackingTools/GeomPropagators TrackingTools/KalmanUpdators TrackingTools/TrajectoryState TrackingTools/PatternTools TrackingTools/DetLayers TrackingTools/TransientTrack RecoTracker/MeasurementDet RecoTracker/TkTrackingRegions RecoTracker/CkfPattern RecoTracker/TkSeedGenerator RecoVertex/VertexPrimitives RecoVertex/KalmanVertexFit RecoVertex/KinematicFitPrimitives RecoVertex/KinematicFit MagneticField/Engine Utilities/General clhep,$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
RecoEgammaEgammaPhotonAlgos_EX_LIB   := RecoEgammaEgammaPhotonAlgos
ALL_EXTERNAL_PRODS += RecoEgammaEgammaPhotonAlgos
RecoEgammaEgammaPhotonAlgos_CLASS := LIBRARY
RecoEgamma/EgammaPhotonAlgos_relbigobj+=RecoEgammaEgammaPhotonAlgos
endif
ifeq ($(strip $(L1TriggerL1TCalorimeterPlugins)),)
L1TriggerL1TCalorimeterPlugins := self/src/L1Trigger/L1TCalorimeter/plugins
L1TriggerL1TCalorimeterPlugins_LOC_USE := self cmssw FWCore/Framework FWCore/PluginManager FWCore/ParameterSet FWCore/Utilities FWCore/ServiceRegistry CommonTools/UtilAlgos DataFormats/EcalDigi DataFormats/EcalDetId DataFormats/HcalDigi DataFormats/HcalDetId CalibFormats/CaloTPG CalibCalorimetry/EcalTPGTools DataFormats/L1Trigger DataFormats/L1CaloTrigger DataFormats/L1TCalorimeter DataFormats/JetReco DataFormats/METReco CondFormats/L1TObjects CondFormats/DataRecord L1Trigger/L1TCalorimeter CondTools/L1Trigger
L1Trigger/L1TCalorimeter_relbigobj+=L1TriggerL1TCalorimeterPlugins
endif
ifeq ($(strip $(DQMOffline/Trigger)),)
DQMOfflineTrigger := self/DQMOffline/Trigger
DQMOffline/Trigger := DQMOfflineTrigger
DQMOfflineTrigger_BuildFile    := $(RELEASETOP)/.SCRAM/$(SCRAM_ARCH)/MakeData/DirCache.mk
DQMOfflineTrigger_EX_USE := $(foreach d, self cmssw DQMServices/Core FWCore/Framework FWCore/PluginManager FWCore/ParameterSet FWCore/ServiceRegistry FWCore/Utilities DataFormats/RecoCandidate DataFormats/HLTReco DataFormats/MuonReco DataFormats/EgammaReco DataFormats/TrackReco DataFormats/TrajectorySeed DataFormats/BTauReco DataFormats/TauReco DataFormats/METReco DataFormats/JetReco DataFormats/CaloTowers DataFormats/HeavyIonEvent CommonTools/Utils RecoEcal/EgammaCoreTools RecoEgamma/EgammaHLTAlgos RecoEgamma/EgammaIsolationAlgos HLTrigger/HLTcore CondFormats/DataRecord DQM/HLTEvF RecoJets/JetAssociationAlgorithms RecoJets/JetAlgorithms RecoJets/JetProducers JetMETCorrections/Objects root boost,$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
ALL_EXTERNAL_PRODS += DQMOfflineTrigger
DQMOfflineTrigger_CLASS := LIBRARY
DQMOffline/Trigger_relbigobj+=DQMOfflineTrigger
endif
ifeq ($(strip $(EgammaAnalysis/ElectronTools)),)
EgammaAnalysisElectronTools := self/EgammaAnalysis/ElectronTools
EgammaAnalysis/ElectronTools := EgammaAnalysisElectronTools
EgammaAnalysisElectronTools_BuildFile    := $(RELEASETOP)/.SCRAM/$(SCRAM_ARCH)/MakeData/DirCache.mk
EgammaAnalysisElectronTools_EX_USE := $(foreach d, self cmssw FWCore/Framework FWCore/ServiceRegistry FWCore/Utilities FWCore/MessageLogger FWCore/ParameterSet Geometry/CaloTopology CondCore/DBOutputService CondFormats/EgammaObjects CondFormats/PhysicsToolsObjects RecoEgamma/EgammaTools RecoEcal/EgammaCoreTools DataFormats/Candidate DataFormats/Common DataFormats/EgammaCandidates DataFormats/PatCandidates DataFormats/EgammaReco DataFormats/TrackReco TrackingTools/IPTools PhysicsTools/UtilAlgos PhysicsTools/SelectorUtils clhep root rootcore roottmva,$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
EgammaAnalysisElectronTools_EX_LIB   := EgammaAnalysisElectronTools
ALL_EXTERNAL_PRODS += EgammaAnalysisElectronTools
EgammaAnalysisElectronTools_CLASS := LIBRARY
EgammaAnalysis/ElectronTools_relbigobj+=EgammaAnalysisElectronTools
endif
ifeq ($(strip $(RecoEgammaEgammaElectronProducersPlugins)),)
RecoEgammaEgammaElectronProducersPlugins := self/src/RecoEgamma/EgammaElectronProducers/plugins
RecoEgammaEgammaElectronProducersPlugins_LOC_USE := self cmssw RecoEgamma/EgammaElectronAlgos RecoEgamma/EgammaIsolationAlgos RecoTracker/CkfPattern RecoTracker/TrackProducer Geometry/CommonDetUnit Geometry/TrackerGeometryBuilder MagneticField/Engine MagneticField/Records FWCore/Framework FWCore/ParameterSet FWCore/PluginManager DataFormats/EgammaCandidates DataFormats/DetId DataFormats/SiPixelCluster DataFormats/TrackerRecHit2D DataFormats/TrackingRecHit DataFormats/ParticleFlowCandidate hepmc clhep root
RecoEgamma/EgammaElectronProducers_relbigobj+=RecoEgammaEgammaElectronProducersPlugins
endif
ifeq ($(strip $(EventFilter/SiPixelRawToDigi)),)
EventFilterSiPixelRawToDigi := self/EventFilter/SiPixelRawToDigi
EventFilter/SiPixelRawToDigi := EventFilterSiPixelRawToDigi
EventFilterSiPixelRawToDigi_BuildFile    := $(RELEASETOP)/.SCRAM/$(SCRAM_ARCH)/MakeData/DirCache.mk
EventFilterSiPixelRawToDigi_EX_USE := $(foreach d, self cmssw FWCore/Framework FWCore/PluginManager FWCore/ParameterSet DataFormats/FEDRawData DataFormats/SiPixelDigi DataFormats/SiPixelRawData CondFormats/SiPixelObjects DataFormats/Candidate CondFormats/DataRecord root,$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
EventFilterSiPixelRawToDigi_EX_LIB   := EventFilterSiPixelRawToDigi
ALL_EXTERNAL_PRODS += EventFilterSiPixelRawToDigi
EventFilterSiPixelRawToDigi_CLASS := LIBRARY
EventFilter/SiPixelRawToDigi_relbigobj+=EventFilterSiPixelRawToDigi
endif
ifeq ($(strip $(RecoMuon/MuonIsolationProducers)),)
src_RecoMuon_MuonIsolationProducers := self/RecoMuon/MuonIsolationProducers
RecoMuon/MuonIsolationProducers  := src_RecoMuon_MuonIsolationProducers
src_RecoMuon_MuonIsolationProducers_BuildFile    := $(RELEASETOP)/.SCRAM/$(SCRAM_ARCH)/MakeData/DirCache.mk
src_RecoMuon_MuonIsolationProducers_EX_USE := $(foreach d, FWCore/Framework self FWCore/PluginManager MagneticField/Records FWCore/MessageLogger Geometry/Records DataFormats/CaloTowers MagneticField/Engine cmssw Geometry/CaloGeometry RecoMuon/MuonIsolation Geometry/CaloEventSetup DataFormats/TrackReco DataFormats/MuonReco FWCore/ParameterSet,$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
ALL_EXTERNAL_PRODS += src_RecoMuon_MuonIsolationProducers
endif

ifeq ($(strip $(GeneratorInterface/Hydjet2Interface)),)
GeneratorInterfaceHydjet2Interface := self/GeneratorInterface/Hydjet2Interface
GeneratorInterface/Hydjet2Interface := GeneratorInterfaceHydjet2Interface
GeneratorInterfaceHydjet2Interface_BuildFile    := $(RELEASETOP)/.SCRAM/$(SCRAM_ARCH)/MakeData/DirCache.mk
GeneratorInterfaceHydjet2Interface_EX_USE := $(foreach d, self cmssw boost GeneratorInterface/Core FWCore/Framework SimDataFormats/GeneratorProducts GeneratorInterface/Pythia6Interface GeneratorInterface/PyquenInterface GeneratorInterface/ExternalDecays GeneratorInterface/HiGenCommon FWCore/Concurrency clhep f77compiler DataFormats/Math DataFormats/Common DataFormats/Provenance FWCore/Common FWCore/FWLite FWCore/ParameterSet FWCore/Utilities CommonTools/UtilAlgos root rootmath rootcore,$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
GeneratorInterfaceHydjet2Interface_EX_LIB   := GeneratorInterfaceHydjet2Interface
ALL_EXTERNAL_PRODS += GeneratorInterfaceHydjet2Interface
GeneratorInterfaceHydjet2Interface_CLASS := LIBRARY
GeneratorInterface/Hydjet2Interface_relbigobj+=GeneratorInterfaceHydjet2Interface
endif
ifeq ($(strip $(GeneratorInterface/ExternalDecays)),)
GeneratorInterfaceExternalDecays := self/GeneratorInterface/ExternalDecays
GeneratorInterface/ExternalDecays := GeneratorInterfaceExternalDecays
GeneratorInterfaceExternalDecays_BuildFile    := $(RELEASETOP)/.SCRAM/$(SCRAM_ARCH)/MakeData/DirCache.mk
GeneratorInterfaceExternalDecays_EX_USE := $(foreach d, self cmssw FWCore/Concurrency FWCore/ParameterSet FWCore/Utilities FWCore/Framework FWCore/PluginManager heppdt SimGeneral/HepPDTRecord clhep hepmc GeneratorInterface/Core GeneratorInterface/LHEInterface GeneratorInterface/EvtGenInterface GeneratorInterface/PhotosInterface GeneratorInterface/TauolaInterface,$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
GeneratorInterfaceExternalDecays_EX_LIB   := GeneratorInterfaceExternalDecays
ALL_EXTERNAL_PRODS += GeneratorInterfaceExternalDecays
GeneratorInterfaceExternalDecays_CLASS := LIBRARY
GeneratorInterface/ExternalDecays_relbigobj+=GeneratorInterfaceExternalDecays
endif
ifeq ($(strip $(CalibrationEcalCalibAlgosAuto)),)
CalibrationEcalCalibAlgosAuto := self/src/Calibration/EcalCalibAlgos/plugins
CalibrationEcalCalibAlgosAuto_LOC_USE := self cmssw Calibration/EcalCalibAlgos
Calibration/EcalCalibAlgos_relbigobj+=CalibrationEcalCalibAlgosAuto
endif
ifeq ($(strip $(Alignment/CommonAlignment)),)
AlignmentCommonAlignment := self/Alignment/CommonAlignment
Alignment/CommonAlignment := AlignmentCommonAlignment
AlignmentCommonAlignment_BuildFile    := $(RELEASETOP)/.SCRAM/$(SCRAM_ARCH)/MakeData/DirCache.mk
AlignmentCommonAlignment_EX_USE := $(foreach d, self cmssw DataFormats/GeometrySurface DataFormats/GeometryVector DataFormats/TrackingRecHit DataFormats/CSCRecHit DataFormats/DTRecHit FWCore/MessageLogger FWCore/ParameterSet FWCore/ServiceRegistry FWCore/Utilities Geometry/CommonDetUnit Geometry/CommonTopologies clhep boost_serialization,$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
AlignmentCommonAlignment_EX_LIB   := AlignmentCommonAlignment
ALL_EXTERNAL_PRODS += AlignmentCommonAlignment
AlignmentCommonAlignment_CLASS := LIBRARY
Alignment/CommonAlignment_relbigobj+=AlignmentCommonAlignment
endif
ifeq ($(strip $(Alignment/MillePedeAlignmentAlgorithm)),)
AlignmentMillePedeAlignmentAlgorithm := self/Alignment/MillePedeAlignmentAlgorithm
Alignment/MillePedeAlignmentAlgorithm := AlignmentMillePedeAlignmentAlgorithm
AlignmentMillePedeAlignmentAlgorithm_BuildFile    := $(RELEASETOP)/.SCRAM/$(SCRAM_ARCH)/MakeData/DirCache.mk
AlignmentMillePedeAlignmentAlgorithm_EX_USE := $(foreach d, self cmssw Alignment/CommonAlignment Alignment/CommonAlignmentAlgorithm Alignment/CommonAlignmentParametrization Alignment/MuonAlignment Alignment/SurveyAnalysis Alignment/ReferenceTrajectories DataFormats/CLHEP DataFormats/SiStripDetId DataFormats/GeometryVector DataFormats/TrackReco FWCore/MessageLogger FWCore/ParameterSet FWCore/PluginManager Geometry/CommonDetUnit rootcore,$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
ALL_EXTERNAL_PRODS += AlignmentMillePedeAlignmentAlgorithm
AlignmentMillePedeAlignmentAlgorithm_CLASS := LIBRARY
Alignment/MillePedeAlignmentAlgorithm_relbigobj+=AlignmentMillePedeAlignmentAlgorithm
endif
ifeq ($(strip $(Alignment/APEEstimation)),)
src_Alignment_APEEstimation := self/Alignment/APEEstimation
Alignment/APEEstimation  := src_Alignment_APEEstimation
src_Alignment_APEEstimation_BuildFile    := $(RELEASETOP)/.SCRAM/$(SCRAM_ARCH)/MakeData/DirCache.mk
src_Alignment_APEEstimation_EX_USE := $(foreach d, TrackingTools/TrajectoryState TrackingTools/TransientTrackingRecHit FWCore/Framework self RecoLocalTracker/SiStripClusterizer DataFormats/SiPixelCluster DataFormats/DetId RecoLocalTracker/SiStripRecHitConverter Geometry/CommonDetUnit DataFormats/GeometryVector DataFormats/BeamSpot TrackingTools/TrackFitters DataFormats/Math DataFormats/SiStripDetId CondFormats/DataRecord Geometry/CommonTopologies TrackingTools/PatternTools MagneticField/Records FWCore/MessageLogger CondFormats/Alignment DataFormats/CLHEP CommonTools/UtilAlgos DataFormats/GeometryCommonDetAlgo DataFormats/TrackerRecHit2D MagneticField/Engine cmssw CondFormats/SiStripObjects CommonTools/Utils root DataFormats/GeometrySurface DataFormats/SiPixelDetId Geometry/TrackerGeometryBuilder DataFormats/Common rootcore DataFormats/TrackReco FWCore/ServiceRegistry DataFormats/TrackingRecHit DataFormats/SiStripCluster FWCore/ParameterSet FWCore/Utilities,$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
ALL_EXTERNAL_PRODS += src_Alignment_APEEstimation
endif

ifeq ($(strip $(RecoEgamma/ElectronIdentification)),)
RecoEgammaElectronIdentification := self/RecoEgamma/ElectronIdentification
RecoEgamma/ElectronIdentification := RecoEgammaElectronIdentification
RecoEgammaElectronIdentification_BuildFile    := $(RELEASETOP)/.SCRAM/$(SCRAM_ARCH)/MakeData/DirCache.mk
RecoEgammaElectronIdentification_EX_USE := $(foreach d, self cmssw FWCore/Framework DataFormats/EgammaReco Geometry/CaloGeometry CondFormats/EgammaObjects RecoEcal/EgammaCoreTools DataFormats/TrackReco MagneticField/Records MagneticField/Engine RecoEgamma/EgammaTools PhysicsTools/SelectorUtils,$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
RecoEgammaElectronIdentification_LCGDICTS  := x 
RecoEgammaElectronIdentification_EX_LIB   := RecoEgammaElectronIdentification
ALL_EXTERNAL_PRODS += RecoEgammaElectronIdentification
RecoEgammaElectronIdentification_CLASS := LIBRARY
RecoEgamma/ElectronIdentification_relbigobj+=RecoEgammaElectronIdentification
endif
ifeq ($(strip $(GeometryForwardCommonDataPlugin)),)
GeometryForwardCommonDataPlugin := self/src/Geometry/ForwardCommonData/plugins
GeometryForwardCommonDataPlugin_LOC_USE := self cmssw DetectorDescription/Parser FWCore/PluginManager
Geometry/ForwardCommonData_relbigobj+=GeometryForwardCommonDataPlugin
endif
ifeq ($(strip $(FastSimulationMuonsPlugins)),)
FastSimulationMuonsPlugins := self/src/FastSimulation/Muons/plugins
FastSimulationMuonsPlugins_LOC_USE := self cmssw CondFormats/DataRecord CondFormats/L1TObjects DataFormats/L1GlobalMuonTrigger DataFormats/L1Trigger DataFormats/Math DataFormats/MuonSeed DataFormats/TrackReco DataFormats/TrackerRecHit2D DataFormats/TrajectorySeed FWCore/Framework FWCore/MessageLogger FWCore/ParameterSet FWCore/PluginManager FWCore/ServiceRegistry FWCore/Utilities FastSimDataFormats/L1GlobalMuonTrigger FastSimulation/Tracking FastSimulation/Utilities Geometry/RPCGeometry RecoMuon/GlobalTrackingTools RecoMuon/L3TrackFinder RecoMuon/TrackerSeedGenerator RecoMuon/TrackingTools RecoTracker/TkTrackingRegions SimDataFormats/Track TrackingTools/DetLayers TrackingTools/PatternTools Utilities/General
FastSimulation/Muons_relbigobj+=FastSimulationMuonsPlugins
endif
ifeq ($(strip $(RecoEgammaEgammaIsolationAlgosPlugins)),)
RecoEgammaEgammaIsolationAlgosPlugins := self/src/RecoEgamma/EgammaIsolationAlgos/plugins
RecoEgammaEgammaIsolationAlgosPlugins_LOC_USE := self cmssw DataFormats/BeamSpot PhysicsTools/IsolationAlgos DataFormats/CaloTowers DataFormats/RecoCandidate DataFormats/EgammaCandidates DataFormats/TrackReco FWCore/Framework FWCore/MessageLogger FWCore/ParameterSet FWCore/PluginManager Geometry/CaloGeometry Geometry/Records RecoCaloTools/Selectors CommonTools/Statistics RecoEgamma/EgammaIsolationAlgos CondFormats/EcalObjects CondFormats/DataRecord RecoLocalCalo/EcalRecAlgos DataFormats/ParticleFlowCandidate DataFormats/PatCandidates
RecoEgamma/EgammaIsolationAlgos_relbigobj+=RecoEgammaEgammaIsolationAlgosPlugins
endif
ifeq ($(strip $(RecoEgammaEgammaIsolationAlgosPlugins_isolation_cones)),)
RecoEgammaEgammaIsolationAlgosPlugins_isolation_cones := self/src/RecoEgamma/EgammaIsolationAlgos/plugins
RecoEgammaEgammaIsolationAlgosPlugins_isolation_cones_LOC_USE := self cmssw DataFormats/BeamSpot PhysicsTools/IsolationAlgos DataFormats/CaloTowers DataFormats/RecoCandidate DataFormats/EgammaCandidates DataFormats/TrackReco FWCore/Framework FWCore/MessageLogger FWCore/ParameterSet FWCore/PluginManager Geometry/CaloGeometry Geometry/Records RecoCaloTools/Selectors CommonTools/Statistics RecoEgamma/EgammaIsolationAlgos CondFormats/EcalObjects CondFormats/DataRecord RecoLocalCalo/EcalRecAlgos DataFormats/ParticleFlowCandidate DataFormats/PatCandidates
RecoEgamma/EgammaIsolationAlgos_relbigobj+=RecoEgammaEgammaIsolationAlgosPlugins_isolation_cones
endif
ifeq ($(strip $(AlignmentMillePedeAlignmentAlgorithmAuto)),)
AlignmentMillePedeAlignmentAlgorithmAuto := self/src/Alignment/MillePedeAlignmentAlgorithm/plugins
AlignmentMillePedeAlignmentAlgorithmAuto_LOC_USE := self cmssw FWCore/Framework FWCore/PluginManager FWCore/ParameterSet CondFormats/Common
Alignment/MillePedeAlignmentAlgorithm_relbigobj+=AlignmentMillePedeAlignmentAlgorithmAuto
endif
ifeq ($(strip $(RecoEcal/EgammaCoreTools)),)
RecoEcalEgammaCoreTools := self/RecoEcal/EgammaCoreTools
RecoEcal/EgammaCoreTools := RecoEcalEgammaCoreTools
RecoEcalEgammaCoreTools_BuildFile    := $(RELEASETOP)/.SCRAM/$(SCRAM_ARCH)/MakeData/DirCache.mk
RecoEcalEgammaCoreTools_EX_USE := $(foreach d, self cmssw DataFormats/EcalRecHit DataFormats/EgammaReco DataFormats/Math FWCore/Framework FWCore/Utilities FWCore/MessageLogger Geometry/CaloGeometry Geometry/CaloTopology Geometry/EcalAlgo RecoLocalCalo/EcalRecAlgos Geometry/Records CalibCalorimetry/EcalLaserCorrection clhep,$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
RecoEcalEgammaCoreTools_EX_LIB   := RecoEcalEgammaCoreTools
ALL_EXTERNAL_PRODS += RecoEcalEgammaCoreTools
RecoEcalEgammaCoreTools_CLASS := LIBRARY
RecoEcal/EgammaCoreTools_relbigobj+=RecoEcalEgammaCoreTools
endif
ifeq ($(strip $(RecoHI/HiMuonAlgos)),)
src_RecoHI_HiMuonAlgos := self/RecoHI/HiMuonAlgos
RecoHI/HiMuonAlgos  := src_RecoHI_HiMuonAlgos
src_RecoHI_HiMuonAlgos_BuildFile    := $(RELEASETOP)/.SCRAM/$(SCRAM_ARCH)/MakeData/DirCache.mk
src_RecoHI_HiMuonAlgos_EX_USE := $(foreach d, RecoTracker/TransientTrackingRecHit clhep FWCore/Framework self DataFormats/VertexReco TrackingTools/TrackFitters DataFormats/L1GlobalMuonTrigger DataFormats/Math RecoVertex/KalmanVertexFit TrackingTools/PatternTools MagneticField/Records RecoTracker/TkNavigation TrackingTools/MeasurementDet RecoVertex/VertexPrimitives RecoTracker/MeasurementDet RecoTracker/CkfPattern Geometry/Records TrackingTools/TrajectoryCleaning DataFormats/GsfTrackReco MagneticField/Engine TrackingTools/TransientTrack cmssw TrackingTools/MaterialEffects TrackingTools/KalmanUpdators Geometry/TrackerGeometryBuilder DataFormats/Common DataFormats/TrackReco FWCore/ParameterSet,$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
ALL_EXTERNAL_PRODS += src_RecoHI_HiMuonAlgos
endif

ifeq ($(strip $(AlignmentOfflinevalidationPlugins)),)
AlignmentOfflinevalidationPlugins := self/src/Alignment/OfflineValidation/plugins
AlignmentOfflinevalidationPlugins_LOC_USE := self cmssw FWCore/MessageLogger TrackPropagation/SteppingHelixPropagator Alignment/CommonAlignment Alignment/TrackerAlignment CondCore/DBOutputService CondFormats/Alignment DataFormats/TrackReco DataFormats/MuonReco FWCore/PluginManager FWCore/Framework FWCore/Utilities FWCore/ParameterSet FWCore/ServiceRegistry Geometry/TrackerGeometryBuilder CommonTools/TrackerMap CommonTools/UtilAlgos CommonTools/Utils RecoMuon/TrackingTools TrackingTools/TransientTrack SimDataFormats/Track SimDataFormats/GeneratorProducts SimTracker/Records SimTracker/TrackAssociation DataFormats/DetId DataFormats/MuonDetId Geometry/CommonDetUnit Geometry/CommonTopologies Geometry/Records Geometry/TrackerNumberingBuilder DataFormats/SiStripDetId DataFormats/SiPixelDetId DataFormats/TrackerRecHit2D DataFormats/TrackingRecHit TrackingTools/TrackFitters TrackingTools/TrajectoryState TrackingTools/IPTools DataFormats/TrajectorySeed DataFormats/VertexReco SimDataFormats/Vertex DataFormats/BeamSpot RecoVertex/PrimaryVertexProducer MagneticField/Records DQM/SiStripCommon DQMServices/Core clhep root TrackingTools/TrackAssociator Geometry/CaloGeometry Alignment/OfflineValidation CondFormats/GeometryObjects
Alignment/OfflineValidation_relbigobj+=AlignmentOfflinevalidationPlugins
endif
ifeq ($(strip $(RecoEgamma/EgammaHLTProducers)),)
RecoEgammaEgammaHLTProducers := self/RecoEgamma/EgammaHLTProducers
RecoEgamma/EgammaHLTProducers := RecoEgammaEgammaHLTProducers
RecoEgammaEgammaHLTProducers_BuildFile    := $(RELEASETOP)/.SCRAM/$(SCRAM_ARCH)/MakeData/DirCache.mk
RecoEgammaEgammaHLTProducers_EX_USE := $(foreach d, self cmssw FWCore/Framework FWCore/PluginManager FWCore/ParameterSet DataFormats/EgammaCandidates Geometry/CaloGeometry RecoEcal/EgammaClusterAlgos RecoEcal/EgammaCoreTools RecoEgamma/EgammaHLTAlgos RecoEgamma/EgammaElectronAlgos RecoEgamma/EgammaIsolationAlgos MagneticField/Engine MagneticField/Records DataFormats/DetId DataFormats/SiPixelCluster DataFormats/TrackerRecHit2D DataFormats/TrackingRecHit CondFormats/L1TObjects CondFormats/DataRecord Geometry/CommonDetUnit Geometry/TrackerGeometryBuilder DataFormats/FEDRawData Geometry/EcalMapping DataFormats/L1Trigger DataFormats/EcalRawData RecoEgamma/EgammaTools RecoTracker/TkTrackingRegions PhysicsTools/UtilAlgos FWCore/ServiceRegistry,$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
ALL_EXTERNAL_PRODS += RecoEgammaEgammaHLTProducers
RecoEgammaEgammaHLTProducers_CLASS := LIBRARY
RecoEgamma/EgammaHLTProducers_relbigobj+=RecoEgammaEgammaHLTProducers
endif
ifeq ($(strip $(RecoMuon/MuonIdentification)),)
RecoMuonMuonIdentification := self/RecoMuon/MuonIdentification
RecoMuon/MuonIdentification := RecoMuonMuonIdentification
RecoMuonMuonIdentification_BuildFile    := $(RELEASETOP)/.SCRAM/$(SCRAM_ARCH)/MakeData/DirCache.mk
RecoMuonMuonIdentification_EX_USE := $(foreach d, self cmssw DataFormats/GeometrySurface DataFormats/GeometryVector DataFormats/Math DataFormats/TrajectoryState DataFormats/VertexReco FWCore/ServiceRegistry RecoMuon/Navigation RecoMuon/TransientTrackingRecHit RecoMuon/MuonIsolation RecoTracker/TkDetLayers RecoTracker/TkMSParametrization RecoTracker/TransientTrackingRecHit TrackingTools/DetLayers TrackingTools/GeomPropagators TrackingTools/PatternTools TrackingTools/Records TrackingTools/TrackFitters TrackingTools/TrackRefitter TrackingTools/TrajectoryState TrackingTools/TransientTrackingRecHit Geometry/DTGeometry DataFormats/DetId DataFormats/MuonDetId DataFormats/MuonReco DataFormats/TrackReco FWCore/Framework FWCore/MessageLogger FWCore/ParameterSet Geometry/CommonDetUnit Geometry/CSCGeometry Geometry/Records SimDataFormats/Track SimDataFormats/TrackingHit roothistmatrix RecoMuon/TrackingTools DataFormats/CSCRecHit RecoLocalCalo/HcalRecAlgos PhysicsTools/SelectorUtils,$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
RecoMuonMuonIdentification_LCGDICTS  := x 
RecoMuonMuonIdentification_EX_LIB   := RecoMuonMuonIdentification
ALL_EXTERNAL_PRODS += RecoMuonMuonIdentification
RecoMuonMuonIdentification_CLASS := LIBRARY
RecoMuon/MuonIdentification_relbigobj+=RecoMuonMuonIdentification
endif
ifeq ($(strip $(RecoHIHiEgammaAlgosPlugins)),)
RecoHIHiEgammaAlgosPlugins := self/src/RecoHI/HiEgammaAlgos/plugins
RecoHIHiEgammaAlgosPlugins_LOC_USE := self cmssw FWCore/Framework FWCore/ParameterSet FWCore/Utilities FWCore/ServiceRegistry DataFormats/Common DataFormats/BTauReco DataFormats/EgammaCandidates RecoHI/HiEgammaAlgos RecoLocalCalo/EcalRecAlgos RecoEcal/EgammaCoreTools CondFormats/DataRecord CondFormats/EcalObjects FWCore/MessageLogger  root
RecoHI/HiEgammaAlgos_relbigobj+=RecoHIHiEgammaAlgosPlugins
endif
ifeq ($(strip $(FWCore/Version)),)
FWCoreVersion := self/FWCore/Version
FWCore/Version := FWCoreVersion
FWCoreVersion_BuildFile    := $(RELEASETOP)/.SCRAM/$(SCRAM_ARCH)/MakeData/DirCache.mk
FWCoreVersion_EX_USE := $(foreach d, self cmssw ,$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
FWCoreVersion_EX_LIB   := FWCoreVersion
ALL_EXTERNAL_PRODS += FWCoreVersion
FWCoreVersion_CLASS := LIBRARY
FWCore/Version_relbigobj+=FWCoreVersion
endif
ifeq ($(strip $(ElectroWeakAnalysis/ZEE)),)
ElectroWeakAnalysisZEE := self/ElectroWeakAnalysis/ZEE
ElectroWeakAnalysis/ZEE := ElectroWeakAnalysisZEE
ElectroWeakAnalysisZEE_BuildFile    := $(RELEASETOP)/.SCRAM/$(SCRAM_ARCH)/MakeData/DirCache.mk
ElectroWeakAnalysisZEE_EX_USE := $(foreach d, self cmssw FWCore/Framework FWCore/PluginManager FWCore/ParameterSet DataFormats/PatCandidates DataFormats/Common Geometry/CaloGeometry Geometry/CaloTopology CommonTools/UtilAlgos L1Trigger/GlobalTriggerAnalyzer MagneticField/Records MagneticField/Engine RecoEgamma/EgammaTools RecoEcal/EgammaCoreTools RecoLocalCalo/EcalRecAlgos HLTrigger/HLTcore root rootmath rootcore,$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
ALL_EXTERNAL_PRODS += ElectroWeakAnalysisZEE
ElectroWeakAnalysisZEE_CLASS := LIBRARY
ElectroWeakAnalysis/ZEE_relbigobj+=ElectroWeakAnalysisZEE
endif
ifeq ($(strip $(RecoParticleFlow/PFProducer)),)
RecoParticleFlowPFProducer := self/RecoParticleFlow/PFProducer
RecoParticleFlow/PFProducer := RecoParticleFlowPFProducer
RecoParticleFlowPFProducer_BuildFile    := $(RELEASETOP)/.SCRAM/$(SCRAM_ARCH)/MakeData/DirCache.mk
RecoParticleFlowPFProducer_EX_USE := $(foreach d, self cmssw CondFormats/DataRecord CondFormats/EgammaObjects DataFormats/CaloRecHit DataFormats/Common DataFormats/EgammaCandidates DataFormats/ParticleFlowCandidate DataFormats/ParticleFlowReco DataFormats/Provenance DataFormats/TrackReco DataFormats/VertexReco DataFormats/MuonReco DataFormats/EcalDetId RecoParticleFlow/PFClusterTools RecoEcal/EgammaCoreTools RecoEgamma/ElectronIdentification boost clhep rootmath roottmva,$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
RecoParticleFlowPFProducer_EX_LIB   := RecoParticleFlowPFProducer
ALL_EXTERNAL_PRODS += RecoParticleFlowPFProducer
RecoParticleFlowPFProducer_CLASS := LIBRARY
RecoParticleFlow/PFProducer_relbigobj+=RecoParticleFlowPFProducer
endif
ifeq ($(strip $(RecoEgammaPhotonIdentificationPlugins_cuts)),)
RecoEgammaPhotonIdentificationPlugins_cuts := self/src/RecoEgamma/PhotonIdentification/plugins
RecoEgammaPhotonIdentificationPlugins_cuts_LOC_USE := self cmssw FWCore/Framework FWCore/PluginManager DataFormats/EgammaReco DataFormats/EgammaCandidates DataFormats/PatCandidates CondFormats/PhysicsToolsObjects Geometry/CaloGeometry PhysicsTools/SelectorUtils RecoEgamma/EgammaTools
RecoEgamma/PhotonIdentification_relbigobj+=RecoEgammaPhotonIdentificationPlugins_cuts
endif
ifeq ($(strip $(RecoEgammaPhotonIdentificationPlugins)),)
RecoEgammaPhotonIdentificationPlugins := self/src/RecoEgamma/PhotonIdentification/plugins
RecoEgammaPhotonIdentificationPlugins_LOC_USE := self cmssw FWCore/Framework FWCore/PluginManager DataFormats/EgammaReco DataFormats/EgammaCandidates DataFormats/PatCandidates CondFormats/PhysicsToolsObjects Geometry/CaloGeometry PhysicsTools/SelectorUtils RecoEgamma/PhotonIdentification RecoEgamma/EgammaTools
RecoEgamma/PhotonIdentification_relbigobj+=RecoEgammaPhotonIdentificationPlugins
endif
ifeq ($(strip $(Fireworks/FWInterface)),)
FireworksFWInterface := self/Fireworks/FWInterface
Fireworks/FWInterface := FireworksFWInterface
FireworksFWInterface_BuildFile    := $(RELEASETOP)/.SCRAM/$(SCRAM_ARCH)/MakeData/DirCache.mk
FireworksFWInterface_EX_USE := $(foreach d, self cmssw FWCore/PluginManager FWCore/Framework DataFormats/Provenance DataFormats/TrackReco TrackingTools/TrajectoryState TrackingTools/PatternTools CondFormats/DataRecord CondFormats/RunInfo Fireworks/Core Fireworks/Geometry rootcore rootinteractive,$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
FireworksFWInterface_LCGDICTS  := x 
FireworksFWInterface_EX_LIB   := FireworksFWInterface
ALL_EXTERNAL_PRODS += FireworksFWInterface
FireworksFWInterface_CLASS := LIBRARY
Fireworks/FWInterface_relbigobj+=FireworksFWInterface
endif
ifeq ($(strip $(ApeEstimatorApeEstimatorPlugins)),)
ApeEstimatorApeEstimatorPlugins := self/src/Alignment/APEEstimation/plugins
ApeEstimatorApeEstimatorPlugins_LOC_USE := self cmssw Alignment/APEEstimation
Alignment/APEEstimation_relbigobj+=ApeEstimatorApeEstimatorPlugins
endif
ifeq ($(strip $(DQM/SiPixelMonitorTrack)),)
DQMSiPixelMonitorTrack := self/DQM/SiPixelMonitorTrack
DQM/SiPixelMonitorTrack := DQMSiPixelMonitorTrack
DQMSiPixelMonitorTrack_BuildFile    := $(RELEASETOP)/.SCRAM/$(SCRAM_ARCH)/MakeData/DirCache.mk
DQMSiPixelMonitorTrack_EX_USE := $(foreach d, self cmssw MagneticField/Engine FWCore/Framework FWCore/PluginManager FWCore/ParameterSet DQMServices/Core DQM/SiPixelCommon AnalysisDataFormats/TrackInfo DataFormats/TrackerRecHit2D DataFormats/DTRecHit DataFormats/CSCRecHit Geometry/CommonDetUnit Geometry/Records Geometry/TrackerGeometryBuilder TrackingTools/TrackFitters TrackPropagation/SteppingHelixPropagator RecoTracker/MeasurementDet TrackingTools/KalmanUpdators TrackingTools/MeasurementDet TrackingTools/Records RecoTracker/TransientTrackingRecHit TrackingTools/TransientTrack boost,$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
ALL_EXTERNAL_PRODS += DQMSiPixelMonitorTrack
DQMSiPixelMonitorTrack_CLASS := LIBRARY
DQM/SiPixelMonitorTrack_relbigobj+=DQMSiPixelMonitorTrack
endif
ifeq ($(strip $(Fireworks/Geometry)),)
FireworksGeometry := self/Fireworks/Geometry
Fireworks/Geometry := FireworksGeometry
FireworksGeometry_BuildFile    := $(RELEASETOP)/.SCRAM/$(SCRAM_ARCH)/MakeData/DirCache.mk
FireworksGeometry_EX_USE := $(foreach d, self cmssw FWCore/PluginManager FWCore/Framework FWCore/MessageLogger Geometry/CommonDetUnit Geometry/MuonNumbering Geometry/EcalCommonData Geometry/CSCGeometryBuilder DetectorDescription/Core Geometry/CaloGeometry Geometry/DTGeometry Geometry/CSCGeometry Geometry/RPCGeometry Geometry/GEMGeometry Geometry/TrackerGeometryBuilder Geometry/Records DataFormats/GeometrySurface DataFormats/MuonDetId DataFormats/SiStripDetId DataFormats/SiPixelDetId Fireworks/Core rootcore,$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
FireworksGeometry_EX_LIB   := FireworksGeometry
ALL_EXTERNAL_PRODS += FireworksGeometry
FireworksGeometry_CLASS := LIBRARY
Fireworks/Geometry_relbigobj+=FireworksGeometry
endif
ifeq ($(strip $(DQMOffline/JetMET)),)
DQMOfflineJetMET := self/DQMOffline/JetMET
DQMOffline/JetMET := DQMOfflineJetMET
DQMOfflineJetMET_BuildFile    := $(RELEASETOP)/.SCRAM/$(SCRAM_ARCH)/MakeData/DirCache.mk
DQMOfflineJetMET_EX_USE := $(foreach d, self cmssw FWCore/Framework FWCore/Utilities MagneticField/Engine DQMServices/Core DQMServices/Components FWCore/PluginManager DataFormats/JetReco DataFormats/METReco DataFormats/CaloTowers DataFormats/HcalRecHit DataFormats/HcalDetId DataFormats/EgammaReco DataFormats/EgammaCandidates HLTrigger/HLTcore RecoJets/JetAlgorithms RecoJets/JetProducers RecoHI/HiJetAlgos RecoHI/HiCentralityAlgos DataFormats/CSCRecHit DataFormats/EcalDetId DataFormats/DetId DataFormats/RecoCandidate Geometry/CaloTopology Geometry/CaloGeometry Geometry/CSCGeometry Geometry/CSCGeometryBuilder DataFormats/TrackReco DataFormats/Common DataFormats/Math RecoJets/JetAssociationAlgorithms MagneticField/Records TrackingTools/Records DataFormats/TrackingRecHit DataFormats/TrackerRecHit2D DataFormats/SiStripCluster DataFormats/SiStripDetId DataFormats/PatCandidates CalibFormats/SiStripObjects CondFormats/SiStripObjects CalibTracker/Records CondFormats/DataRecord CommonTools/TriggerUtils RecoMuon/TrackingTools CommonTools/RecoAlgos JetMETCorrections/Objects,$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
ALL_EXTERNAL_PRODS += DQMOfflineJetMET
DQMOfflineJetMET_CLASS := LIBRARY
DQMOffline/JetMET_relbigobj+=DQMOfflineJetMET
endif
ifeq ($(strip $(RecoHIHiMuonAlgosPlugins)),)
RecoHIHiMuonAlgosPlugins := self/src/RecoHI/HiMuonAlgos/plugins
RecoHIHiMuonAlgosPlugins_LOC_USE := self cmssw boost FWCore/Framework FWCore/PluginManager FWCore/ParameterSet Geometry/Records Geometry/TrackerGeometryBuilder RecoTracker/Record MagneticField/Records MagneticField/Engine DataFormats/VertexReco DataFormats/Common TrackingTools/TrajectoryState TrackingTools/GeomPropagators TrackingTools/DetLayers DataFormats/TrajectorySeed TrackingTools/MeasurementDet RecoTracker/MeasurementDet TrackingTools/TrajectoryFiltering TrackingTools/TrajectoryCleaning TrackingTools/MaterialEffects TrackingTools/TrackFitters RecoVertex/KalmanVertexFit RecoVertex/VertexPrimitives TrackingTools/TransientTrack HLTrigger/HLTcore RecoMuon/GlobalTrackingTools RecoMuon/TrackingTools hepmc RecoHI/HiMuonAlgos
RecoHI/HiMuonAlgos_relbigobj+=RecoHIHiMuonAlgosPlugins
endif
