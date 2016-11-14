# Auto generated configuration file
# using: 
# Revision: 1.19 
# Source: /local/reps/CMSSW/CMSSW/Configuration/Applications/python/ConfigBuilder.py,v 
# with command line options: step1 --mc --pileup_input dbs:/MinBias_TuneCUETP8M1_5p02TeV-pythia8/pp502Fall15-MCRUN2_71_V1-v1/GEN-SIM --eventcontent RAWSIM --pileup pp5TeV_Poisson_1p5 --customise SLHCUpgradeSimulations/Configuration/postLS1Customs.customisePostLS1 --datatier GEN-SIM-RAW --conditions 75X_mcRun2_asymptotic_ppAt5TeV_v3 --step DIGI,L1,DIGI2RAW,HLT:PRef
import FWCore.ParameterSet.Config as cms

process = cms.Process('HLT')

# import of standard configurations
process.load('Configuration.StandardSequences.Services_cff')
process.load('SimGeneral.HepPDTESSource.pythiapdt_cfi')
process.load('FWCore.MessageService.MessageLogger_cfi')
process.load('Configuration.EventContent.EventContent_cff')
process.load('SimGeneral.MixingModule.mix_POISSON_average_cfi')
process.load('Configuration.StandardSequences.GeometryRecoDB_cff')
process.load('Configuration.StandardSequences.MagneticField_cff')
process.load('Configuration.StandardSequences.Digi_cff')
process.load('Configuration.StandardSequences.SimL1Emulator_cff')
process.load('Configuration.StandardSequences.DigiToRaw_cff')
process.load('HLTrigger.Configuration.HLT_PRef_cff')
process.load('Configuration.StandardSequences.EndOfProcess_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(1)
)

# Input source
process.source = cms.Source("PoolSource",
    dropDescendantsOfDroppedBranches = cms.untracked.bool(False),
    fileNames = cms.untracked.vstring('file:step1_SIM.root'),
    inputCommands = cms.untracked.vstring('keep *', 
        'drop *_genParticles_*_*', 
        'drop *_genParticlesForJets_*_*', 
        'drop *_kt4GenJets_*_*', 
        'drop *_kt6GenJets_*_*', 
        'drop *_iterativeCone5GenJets_*_*', 
        'drop *_ak4GenJets_*_*', 
        'drop *_ak7GenJets_*_*', 
        'drop *_ak8GenJets_*_*', 
        'drop *_ak4GenJetsNoNu_*_*', 
        'drop *_ak8GenJetsNoNu_*_*', 
        'drop *_genCandidatesForMET_*_*', 
        'drop *_genParticlesForMETAllVisible_*_*', 
        'drop *_genMetCalo_*_*', 
        'drop *_genMetCaloAndNonPrompt_*_*', 
        'drop *_genMetTrue_*_*', 
        'drop *_genMetIC5GenJs_*_*'),
    secondaryFileNames = cms.untracked.vstring()
)

process.options = cms.untracked.PSet(

)

# Production Info
process.configurationMetadata = cms.untracked.PSet(
    annotation = cms.untracked.string('step1 nevts:1'),
    name = cms.untracked.string('Applications'),
    version = cms.untracked.string('$Revision: 1.19 $')
)

# Output definition

process.RAWSIMoutput = cms.OutputModule("PoolOutputModule",
    dataset = cms.untracked.PSet(
        dataTier = cms.untracked.string('GEN-SIM-RAW'),
        filterName = cms.untracked.string('')
    ),
    eventAutoFlushCompressedSize = cms.untracked.int32(5242880),
    fileName = cms.untracked.string('step1_DIGI_L1_DIGI2RAW_HLT_PU.root'),
    outputCommands = process.RAWSIMEventContent.outputCommands,
    splitLevel = cms.untracked.int32(0)
)

# Additional output definition

# Other statements
process.mix.input.nbPileupEvents.averageNumber = cms.double(1.500000)
process.mix.bunchspace = cms.int32(25)
process.mix.minBunch = cms.int32(-5)
process.mix.maxBunch = cms.int32(3)
process.mix.input.fileNames = cms.untracked.vstring(['/store/himc/pp502Fall15/MinBias_TuneCUETP8M1_5p02TeV-pythia8/GEN-SIM/MCRUN2_71_V1-v1/80000/020D5E4D-E97E-E511-9681-001EC9ADE587.root', '/store/himc/pp502Fall15/MinBias_TuneCUETP8M1_5p02TeV-pythia8/GEN-SIM/MCRUN2_71_V1-v1/80000/02B1BA24-F37E-E511-9E73-848F69FD29B8.root', '/store/himc/pp502Fall15/MinBias_TuneCUETP8M1_5p02TeV-pythia8/GEN-SIM/MCRUN2_71_V1-v1/80000/0612E37C-D67E-E511-A870-001E67E71CE0.root', '/store/himc/pp502Fall15/MinBias_TuneCUETP8M1_5p02TeV-pythia8/GEN-SIM/MCRUN2_71_V1-v1/80000/0845C6E6-037F-E511-948D-002590A50046.root', '/store/himc/pp502Fall15/MinBias_TuneCUETP8M1_5p02TeV-pythia8/GEN-SIM/MCRUN2_71_V1-v1/80000/08AAC172-0D7F-E511-9F29-0025904E1286.root', '/store/himc/pp502Fall15/MinBias_TuneCUETP8M1_5p02TeV-pythia8/GEN-SIM/MCRUN2_71_V1-v1/80000/0A8795BF-EA7E-E511-8A9E-44A842B298FE.root', '/store/himc/pp502Fall15/MinBias_TuneCUETP8M1_5p02TeV-pythia8/GEN-SIM/MCRUN2_71_V1-v1/80000/0C8D2DEC-097F-E511-B777-002590200B38.root', '/store/himc/pp502Fall15/MinBias_TuneCUETP8M1_5p02TeV-pythia8/GEN-SIM/MCRUN2_71_V1-v1/80000/0E237EDE-D97E-E511-83B3-001E67E6F65C.root', '/store/himc/pp502Fall15/MinBias_TuneCUETP8M1_5p02TeV-pythia8/GEN-SIM/MCRUN2_71_V1-v1/80000/0E2A55E4-D77E-E511-83E8-D8D385AF891A.root', '/store/himc/pp502Fall15/MinBias_TuneCUETP8M1_5p02TeV-pythia8/GEN-SIM/MCRUN2_71_V1-v1/80000/0E5EA881-537F-E511-9607-782BCB67826E.root'])
from Configuration.AlCa.GlobalTag import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, '75X_mcRun2_asymptotic_ppAt5TeV_v3', '')

# Path and EndPath definitions
process.digitisation_step = cms.Path(process.pdigi)
process.L1simulation_step = cms.Path(process.SimL1Emulator)
process.digi2raw_step = cms.Path(process.DigiToRaw)
process.endjob_step = cms.EndPath(process.endOfProcess)
process.RAWSIMoutput_step = cms.EndPath(process.RAWSIMoutput)

# Schedule definition
process.schedule = cms.Schedule(process.digitisation_step,process.L1simulation_step,process.digi2raw_step)
process.schedule.extend(process.HLTSchedule)
process.schedule.extend([process.endjob_step,process.RAWSIMoutput_step])

# customisation of the process.

# Automatic addition of the customisation function from SLHCUpgradeSimulations.Configuration.postLS1Customs
from SLHCUpgradeSimulations.Configuration.postLS1Customs import customisePostLS1 

#call to customisation function customisePostLS1 imported from SLHCUpgradeSimulations.Configuration.postLS1Customs
process = customisePostLS1(process)

# Automatic addition of the customisation function from HLTrigger.Configuration.customizeHLTforMC
from HLTrigger.Configuration.customizeHLTforMC import customizeHLTforFullSim 

#call to customisation function customizeHLTforFullSim imported from HLTrigger.Configuration.customizeHLTforMC
process = customizeHLTforFullSim(process)

# End of customisation functions

