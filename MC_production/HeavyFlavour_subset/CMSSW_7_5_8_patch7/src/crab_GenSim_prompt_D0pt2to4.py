from CRABClient.UserUtilities import config, getUsernameFromSiteDB
config = config()

config.General.requestName = 'Prompt_D0pt2to4'
config.General.workArea = 'crab_projects'
config.General.transferOutputs = True
config.General.transferLogs = False

config.JobType.pluginName = 'PrivateMC'
config.JobType.psetName = 'PbPb_prompt_D0pt2to4_GenSim_cfg.py'
#config.JobType.maxMemoryMB = 4000

config.Data.outputPrimaryDataset = 'Prompt_D0pt2to4'
config.Data.splitting = 'EventBased'
config.Data.unitsPerJob = 30000
NJOBS = 300  # This is not a configuration parameter, but an auxiliary variable that we use in the next line.
config.Data.totalUnits = config.Data.unitsPerJob * NJOBS
config.Data.outLFNDirBase = '/store/user/%s/' % (getUsernameFromSiteDB())
config.Data.publication = True
config.Data.outputDatasetTag = 'Pythia8_prompt_D0pt2to4_Pthat0_TuneCUETP8M1_5020GeV_cfi_evtgen130_py_GEN_SIM_PU_v1'
config.Site.storageSite = 'T2_US_Purdue' #'T2_CH_CERN'
config.Site.whitelist = ['T2_US_MIT','T2_US_Vanderbilt','T2_FR_GRIF_LLR']
config.section_("Debug")
config.Debug.extraJDL = ['+CMS_ALLOW_OVERFLOW=False']
