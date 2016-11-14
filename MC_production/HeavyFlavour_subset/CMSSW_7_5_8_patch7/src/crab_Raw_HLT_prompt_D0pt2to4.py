from CRABClient.UserUtilities import config, getUsernameFromSiteDB
config = config()

config.General.requestName = 'Prompt_D0pt2to4_RAW_HLT_withPU_p7v14_t2'
config.General.workArea = 'crab_projects'
config.General.transferOutputs = True
config.General.transferLogs = False

config.JobType.pluginName = 'Analysis'
config.JobType.psetName = 'step1_DIGItoHLT_withPU_cfg.py'

#config.Data.outputPrimaryDataset = 'bJet200'
#config.Data.inputDataset = '/Pythia8_bjet30_5020GeV_GEN-SIM/mnguyen-Pythia8_bjet30_5020GeV_RECO_75X_mcRun2_asymptotic_ppAt5TeV_v3-eca985b12211699dc9125db438586ff6/USER'
#config.Data.inputDataset = '/mnt/hadoop/store/user/chengchi/bJet30/MC_generation_bJet30/160214_071858/0000'

config.Data.inputDataset ='/Prompt_D0pt2to4/chengchi-Pythia8_prompt_D0pt2to4_Pthat0_TuneCUETP8M1_5020GeV_cfi_evtgen130_py_GEN_SIM_PU_v1-062d3216df52fb52307cafd986dce510/USER'
config.Data.inputDBS ='phys03'
config.Data.splitting = 'FileBased'
config.Data.unitsPerJob = 1
#NJOBS = 10  # This is not a configuration parameter, but an auxiliary variable that we use in the next line.
#config.Data.totalUnits = config.Data.unitsPerJob * NJOBS
#config.Data.outLFNDirBase = '/store/user/%s/' % (getUsernameFromSiteDB())
config.Data.publication = True
config.Data.outputDatasetTag = 'Prompt_D0pt2to4_RAW_HLT_withPU_p7v14_t2'

config.Site.storageSite = 'T2_US_Purdue'  # or T2_CH_CERN
#config.Site.whitelist = ['T2_US_Purdue']
#config.Site.whitelist = ['T2_US_MIT','T2_US_Vanderbilt','T2_FR_GRIF_LLR']
config.section_("Debug")
config.Debug.extraJDL = ['+CMS_ALLOW_OVERFLOW=False']


