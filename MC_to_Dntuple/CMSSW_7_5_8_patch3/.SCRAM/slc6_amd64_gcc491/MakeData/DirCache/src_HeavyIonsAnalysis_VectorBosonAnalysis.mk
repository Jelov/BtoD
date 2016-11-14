ifeq ($(strip $(HeavyIonsAnalysis/VectorBosonAnalysis)),)
src_HeavyIonsAnalysis_VectorBosonAnalysis := self/HeavyIonsAnalysis/VectorBosonAnalysis
HeavyIonsAnalysis/VectorBosonAnalysis  := src_HeavyIonsAnalysis_VectorBosonAnalysis
src_HeavyIonsAnalysis_VectorBosonAnalysis_BuildFile    := $(WORKINGDIR)/cache/bf/src/HeavyIonsAnalysis/VectorBosonAnalysis/BuildFile
src_HeavyIonsAnalysis_VectorBosonAnalysis_LOC_USE := clhep PhysicsTools/PatAlgos PhysicsTools/PatUtils RecoEcal/EgammaCoreTools FWCore/Framework self DataFormats/VertexReco CondFormats/JetMETObjects DataFormats/EcalRecHit PhysicsTools/CandUtils DataFormats/L1GlobalMuonTrigger Geometry/CaloTopology FWCore/PluginManager FWCore/MessageLogger RecoJets/JetProducers RecoVertex/VertexPrimitives Geometry/Records CommonTools/UtilAlgos DataFormats/L1GlobalTrigger CalibCalorimetry/EcalLaserCorrection RecoJets/JetAlgorithms PhysicsTools/UtilAlgos PhysicsTools/PatExamples CondFormats/PhysicsToolsObjects Geometry/EcalAlgo cmssw DataFormats/EgammaReco RecoEgamma/EgammaTools Geometry/CaloGeometry DataFormats/METReco CondCore/DBOutputService root DataFormats/PatCandidates DataFormats/EgammaCandidates roottmva JetMETCorrections/Objects DataFormats/Common EgammaAnalysis/ElectronTools CondFormats/EgammaObjects TrackingTools/IPTools DataFormats/Candidate JetMETCorrections/Modules FWCore/ServiceRegistry DataFormats/TrackReco RecoLocalCalo/EcalRecAlgos FWCore/Common DataFormats/MuonReco JetMETCorrections/Algorithms FWCore/ParameterSet
src_HeavyIonsAnalysis_VectorBosonAnalysis_EX_USE   := $(foreach d,$(src_HeavyIonsAnalysis_VectorBosonAnalysis_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
ALL_EXTERNAL_PRODS += src_HeavyIonsAnalysis_VectorBosonAnalysis
src_HeavyIonsAnalysis_VectorBosonAnalysis_INIT_FUNC += $$(eval $$(call EmptyPackage,src_HeavyIonsAnalysis_VectorBosonAnalysis,src/HeavyIonsAnalysis/VectorBosonAnalysis))
endif

