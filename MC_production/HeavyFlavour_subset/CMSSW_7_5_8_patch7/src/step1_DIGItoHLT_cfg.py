# Auto generated configuration file
# using: 
# Revision: 1.19 
# Source: /local/reps/CMSSW/CMSSW/Configuration/Applications/python/ConfigBuilder.py,v 
# with command line options: step1 --filein dbs:/Pythia8_prompt_D0pt2to4_Pthat0_Hydjet_MB/HiFall15-75X_mcRun2_HeavyIon_v14-v1/GEN-SIM --fileout file:PbPb_prompt_D0pt2to4_step1_DIGItoHLT.root --mc --eventcontent RAWSIM --pileup HiMixNoPU --customise SLHCUpgradeSimulations/Configuration/postLS1Customs.customisePostLS1_HI,Configuration/DataProcessing/Utils.addMonitoring --datatier GEN-SIM-RAW --conditions 75X_mcRun2_HeavyIon_v14 --step DIGI:pdigi_hi,L1,DIGI2RAW,HLT:HIon --scenario HeavyIons --python_filename step1_DIGItoHLT_cfg.py --no_exec -n 64
import FWCore.ParameterSet.Config as cms

process = cms.Process('HLT')

# import of standard configurations
process.load('Configuration.StandardSequences.Services_cff')
process.load('SimGeneral.HepPDTESSource.pythiapdt_cfi')
process.load('FWCore.MessageService.MessageLogger_cfi')
process.load('Configuration.EventContent.EventContentHeavyIons_cff')
process.load('SimGeneral.MixingModule.HiMixNoPU_cff')
process.load('Configuration.StandardSequences.GeometryRecoDB_cff')
process.load('Configuration.StandardSequences.MagneticField_cff')
process.load('Configuration.StandardSequences.Digi_cff')
process.load('Configuration.StandardSequences.SimL1Emulator_cff')
process.load('Configuration.StandardSequences.DigiToRaw_cff')
process.load('HLTrigger.Configuration.HLT_HIon_cff')
process.load('Configuration.StandardSequences.EndOfProcess_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)

# Input source
process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
#		'/store/himc/HiFall15/Pythia8_prompt_D0pt2to4_Pthat0_Hydjet_MB/GEN-SIM/75X_mcRun2_HeavyIon_v14-v1/50000/00615C28-0C94-E611-B1A4-848F69FDFC5C.root', 
#        '/store/himc/HiFall15/Pythia8_prompt_D0pt2to4_Pthat0_Hydjet_MB/GEN-SIM/75X_mcRun2_HeavyIon_v14-v1/50000/02040C29-0C94-E611-9146-002590DB923E.root', 
#        '/store/himc/HiFall15/Pythia8_prompt_D0pt2to4_Pthat0_Hydjet_MB/GEN-SIM/75X_mcRun2_HeavyIon_v14-v1/50000/024D9ABF-1194-E611-B1E6-001E67DBDF5D.root', 
#        '/store/himc/HiFall15/Pythia8_prompt_D0pt2to4_Pthat0_Hydjet_MB/GEN-SIM/75X_mcRun2_HeavyIon_v14-v1/50000/025F6FBE-0D94-E611-A69C-0CC47A4DECE2.root', 
#        '/store/himc/HiFall15/Pythia8_prompt_D0pt2to4_Pthat0_Hydjet_MB/GEN-SIM/75X_mcRun2_HeavyIon_v14-v1/50000/02B010F9-0D94-E611-B5D3-0CC47A7E6A66.root', 
#        '/store/himc/HiFall15/Pythia8_prompt_D0pt2to4_Pthat0_Hydjet_MB/GEN-SIM/75X_mcRun2_HeavyIon_v14-v1/50000/02CB4A6B-0F94-E611-8E50-6CC2173BC350.root', 
#        '/store/himc/HiFall15/Pythia8_prompt_D0pt2to4_Pthat0_Hydjet_MB/GEN-SIM/75X_mcRun2_HeavyIon_v14-v1/50000/047F9F27-0C94-E611-A93B-F452149391B0.root', 
#        '/store/himc/HiFall15/Pythia8_prompt_D0pt2to4_Pthat0_Hydjet_MB/GEN-SIM/75X_mcRun2_HeavyIon_v14-v1/50000/048DBCFF-0D94-E611-B8B7-180373FFCED8.root', 
#        '/store/himc/HiFall15/Pythia8_prompt_D0pt2to4_Pthat0_Hydjet_MB/GEN-SIM/75X_mcRun2_HeavyIon_v14-v1/50000/060F6CEF-0D94-E611-8FE1-0CC47A7FC844.root', 
#        '/store/himc/HiFall15/Pythia8_prompt_D0pt2to4_Pthat0_Hydjet_MB/GEN-SIM/75X_mcRun2_HeavyIon_v14-v1/50000/061F0B20-1094-E611-A598-C4346BBC9BB0.root'),
		'file:/afs/cern.ch/work/c/chengchi/work/Project/BtoD/MC_production/HeavyFlavour_subset/CMSSW_7_5_8_patch7/src/PbPb_prompt_D0pt2to4_GenSim.root'),
	secondaryFileNames = cms.untracked.vstring()
)

process.options = cms.untracked.PSet(

)

# Production Info
process.configurationMetadata = cms.untracked.PSet(
    annotation = cms.untracked.string('step1 nevts:64'),
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
    fileName = cms.untracked.string('file:PbPb_prompt_D0pt2to4_step1_DIGItoHLT.root'),
    outputCommands = process.RAWSIMEventContent.outputCommands,
    splitLevel = cms.untracked.int32(0)
)

# Additional output definition

# Other statements
process.mix.digitizers = cms.PSet(process.theDigitizersValid)
from Configuration.AlCa.GlobalTag import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, '75X_mcRun2_HeavyIon_v14', '')

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

# Automatic addition of the customisation function from Configuration.DataProcessing.Utils
from Configuration.DataProcessing.Utils import addMonitoring 

#call to customisation function addMonitoring imported from Configuration.DataProcessing.Utils
process = addMonitoring(process)

# Automatic addition of the customisation function from HLTrigger.Configuration.customizeHLTforMC
from HLTrigger.Configuration.customizeHLTforMC import customizeHLTforFullSim 

#call to customisation function customizeHLTforFullSim imported from HLTrigger.Configuration.customizeHLTforMC
process = customizeHLTforFullSim(process)

# End of customisation functions

