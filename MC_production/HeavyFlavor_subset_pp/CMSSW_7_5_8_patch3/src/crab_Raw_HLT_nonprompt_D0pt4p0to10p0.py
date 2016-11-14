from CRABClient.UserUtilities import config, getUsernameFromSiteDB
config = config()

config.General.requestName = 'Pythia8_nonprompt_D0pt4p0to10p0_Pthat0_TuneCUETP8M1_5020GeV_cfi_evtgen130_py_RAW_HLT'
config.General.workArea = 'crab_projects'
config.General.transferOutputs = True
config.General.transferLogs = False

config.JobType.pluginName = 'Analysis'
config.JobType.psetName = 'step1_DIGI_L1_DIGI2RAW_HLT_PU.py'

#config.Data.outputPrimaryDataset = 'bJet200'
#config.Data.inputDataset = '/Pythia8_bjet30_5020GeV_GEN-SIM/mnguyen-Pythia8_bjet30_5020GeV_RECO_75X_mcRun2_asymptotic_ppAt5TeV_v3-eca985b12211699dc9125db438586ff6/USER'
#config.Data.inputDataset = '/mnt/hadoop/store/user/chengchi/bJet30/MC_generation_bJet30/160214_071858/0000'

config.Data.inputDataset ='/NonPrompt_D0_pp/chengchi-Pythia8_nonprompt_D0pt4p0to10p0_Pthat0_TuneCUETP8M1_5020GeV_cfi_evtgen130_py_GEN_SIM-4d95e9872841ede5895cbb4280f8835f/USER'
config.Data.inputDBS ='phys03'
config.Data.splitting = 'FileBased'
config.Data.unitsPerJob = 3
#NJOBS = 10  # This is not a configuration parameter, but an auxiliary variable that we use in the next line.
#config.Data.totalUnits = config.Data.unitsPerJob * NJOBS
#config.Data.outLFNDirBase = '/store/user/%s/' % (getUsernameFromSiteDB())
config.Data.publication = True
config.Data.outputDatasetTag = 'Pythia8_nonprompt_D0pt4p0to10p0_Pthat0_TuneCUETP8M1_5020GeV_cfi_evtgen130_py_RAW_HLT'

config.Site.storageSite = 'T2_US_Purdue'  # or T2_CH_CERN
#config.Site.whitelist = ['T2_US_Purdue']
#config.Site.whitelist = ['T2_US_MIT','T2_US_Vanderbilt','T2_FR_GRIF_LLR']
config.section_("Debug")
config.Debug.extraJDL = ['+CMS_ALLOW_OVERFLOW=False']


