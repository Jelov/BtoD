from CRABClient.UserUtilities import config, getUsernameFromSiteDB
config = config()

config.General.requestName = 'Pythia8_nonprompt_D0pt4p0to10p0_Pthat0_TuneCUETP8M1_5020GeV_cfi_evtgen130_py_GEN_SIM_PU_v1'
config.General.workArea = 'crab_projects'
config.General.transferOutputs = True
config.General.transferLogs = False

config.JobType.pluginName = 'PrivateMC'
config.JobType.psetName = 'Pythia8_nonprompt_D0pt4p0to10p0_Pthat0_TuneCUETP8M1_5020GeV_cfi_evtgen130_py_GEN_SIM_PU.py'
config.JobType.maxMemoryMB = 4000

config.Data.outputPrimaryDataset = 'NonPrompt_D0'
config.Data.splitting = 'EventBased'
config.Data.unitsPerJob = 20000
NJOBS = 20  # This is not a configuration parameter, but an auxiliary variable that we use in the next line.
config.Data.totalUnits = config.Data.unitsPerJob * NJOBS
config.Data.outLFNDirBase = '/store/user/%s/' % (getUsernameFromSiteDB())
config.Data.publication = True
config.Data.outputDatasetTag = 'Pythia8_nonprompt_D0pt4p0to10p0_Pthat0_TuneCUETP8M1_5020GeV_cfi_evtgen130_py_GEN_SIM_PU_v1'
config.Site.storageSite = 'T2_US_Purdue' #'T2_CH_CERN'
config.Site.whitelist = ['T2_US_MIT','T2_US_Vanderbilt','T2_FR_GRIF_LLR']
config.section_("Debug")
config.Debug.extraJDL = ['+CMS_ALLOW_OVERFLOW=False']
