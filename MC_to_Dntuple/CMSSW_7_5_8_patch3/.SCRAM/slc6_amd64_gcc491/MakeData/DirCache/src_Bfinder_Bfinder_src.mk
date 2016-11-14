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
