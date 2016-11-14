# Auto generated configuration file
# using: 
# Revision: 1.19 
# Source: /local/reps/CMSSW/CMSSW/Configuration/Applications/python/ConfigBuilder.py,v 
# with command line options: step2 --pileup_input dbs:/Hydjet_Quenched_MinBias_5020GeV_750/HiFall15-75X_mcRun2_HeavyIon_v1_75X_mcRun2_HeavyIon_v1-v1/GEN-SIM --mc --eventcontent RAWSIM --pileup HiMix --customise SLHCUpgradeSimulations/Configuration/postLS1Customs.customisePostLS1_HI --datatier GEN-SIM-RAW --conditions 75X_mcRun2_HeavyIon_v13 --step DIGI:pdigi_hi,L1,DIGI2RAW,HLT:HIon --scenario HeavyIons
import FWCore.ParameterSet.Config as cms

process = cms.Process('HLT')

# import of standard configurations
process.load('Configuration.StandardSequences.Services_cff')
process.load('SimGeneral.HepPDTESSource.pythiapdt_cfi')
process.load('FWCore.MessageService.MessageLogger_cfi')
process.load('Configuration.EventContent.EventContentHeavyIons_cff')
process.load('SimGeneral.MixingModule.HiMix_cff')
process.load('Configuration.StandardSequences.GeometryRecoDB_cff')
process.load('Configuration.StandardSequences.MagneticField_cff')
process.load('Configuration.StandardSequences.Digi_cff')
process.load('Configuration.StandardSequences.SimL1Emulator_cff')
process.load('Configuration.StandardSequences.DigiToRaw_cff')
process.load('HLTrigger.Configuration.HLT_HIon_cff')
process.load('Configuration.StandardSequences.EndOfProcess_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(1)
)

# Input source
process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring('file:Pythia8_prompt_D0pt2p0to4p0_Pthat0_TuneCUETP8M1_5020GeV_cfi_evtgen130_py_GEN_SIM_PU.root'),
    secondaryFileNames = cms.untracked.vstring()
)

process.options = cms.untracked.PSet(

)

# Production Info
process.configurationMetadata = cms.untracked.PSet(
    annotation = cms.untracked.string('step2 nevts:1'),
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
    fileName = cms.untracked.string('step2_prompt_D0pt2to4__DIGI_L1_DIGI2RAW_HLT_PU.root'),
    outputCommands = process.RAWSIMEventContent.outputCommands,
    splitLevel = cms.untracked.int32(0)
)

# Additional output definition

# Other statements
process.mix.input.fileNames = cms.untracked.vstring(['/store/himc/HiFall15/Hydjet_Quenched_MinBias_5020GeV_750/GEN-SIM/75X_mcRun2_HeavyIon_v1_75X_mcRun2_HeavyIon_v1-v1/10000/0041B26A-EB74-E511-BA4B-0025905C4264.root', '/store/himc/HiFall15/Hydjet_Quenched_MinBias_5020GeV_750/GEN-SIM/75X_mcRun2_HeavyIon_v1_75X_mcRun2_HeavyIon_v1-v1/10000/004752C7-AD73-E511-9761-003048F2E63A.root', '/store/himc/HiFall15/Hydjet_Quenched_MinBias_5020GeV_750/GEN-SIM/75X_mcRun2_HeavyIon_v1_75X_mcRun2_HeavyIon_v1-v1/10000/0049E97E-3672-E511-8316-0025904C51DA.root', '/store/himc/HiFall15/Hydjet_Quenched_MinBias_5020GeV_750/GEN-SIM/75X_mcRun2_HeavyIon_v1_75X_mcRun2_HeavyIon_v1-v1/10000/00BDE5ED-5A73-E511-8389-002590AC5062.root', '/store/himc/HiFall15/Hydjet_Quenched_MinBias_5020GeV_750/GEN-SIM/75X_mcRun2_HeavyIon_v1_75X_mcRun2_HeavyIon_v1-v1/10000/00CA13C1-2E73-E511-BA95-00259073E3B2.root', '/store/himc/HiFall15/Hydjet_Quenched_MinBias_5020GeV_750/GEN-SIM/75X_mcRun2_HeavyIon_v1_75X_mcRun2_HeavyIon_v1-v1/10000/00F86C8B-C873-E511-BFED-549F35AD8BE3.root', '/store/himc/HiFall15/Hydjet_Quenched_MinBias_5020GeV_750/GEN-SIM/75X_mcRun2_HeavyIon_v1_75X_mcRun2_HeavyIon_v1-v1/10000/00FDAD95-F073-E511-85CD-00266CF9B9F0.root', '/store/himc/HiFall15/Hydjet_Quenched_MinBias_5020GeV_750/GEN-SIM/75X_mcRun2_HeavyIon_v1_75X_mcRun2_HeavyIon_v1-v1/10000/022159CB-8172-E511-9923-0025905C431A.root', '/store/himc/HiFall15/Hydjet_Quenched_MinBias_5020GeV_750/GEN-SIM/75X_mcRun2_HeavyIon_v1_75X_mcRun2_HeavyIon_v1-v1/10000/0230036F-3D73-E511-9278-002590DB9232.root', '/store/himc/HiFall15/Hydjet_Quenched_MinBias_5020GeV_750/GEN-SIM/75X_mcRun2_HeavyIon_v1_75X_mcRun2_HeavyIon_v1-v1/10000/02BB0106-A973-E511-96C1-00266CF250C0.root'])
process.mix.digitizers = cms.PSet(process.theDigitizersValid)
from Configuration.AlCa.GlobalTag import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, '75X_mcRun2_HeavyIon_v13', '')

# Path and EndPath definitions
process.digitisation_step = cms.Path(process.pdigi_hi)
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
from SLHCUpgradeSimulations.Configuration.postLS1Customs import customisePostLS1_HI 

#call to customisation function customisePostLS1_HI imported from SLHCUpgradeSimulations.Configuration.postLS1Customs
process = customisePostLS1_HI(process)

# Automatic addition of the customisation function from HLTrigger.Configuration.customizeHLTforMC
from HLTrigger.Configuration.customizeHLTforMC import customizeHLTforFullSim 

#call to customisation function customizeHLTforFullSim imported from HLTrigger.Configuration.customizeHLTforMC
process = customizeHLTforFullSim(process)

# End of customisation functions

