#!/bin/bash
source  /afs/cern.ch/cms/cmsset_default.sh
export SCRAM_ARCH=slc6_amd64_gcc491
if [ -r CMSSW_7_5_8_patch3/src ] ; then 
 echo release CMSSW_7_5_8_patch3 already exists
else
scram p CMSSW CMSSW_7_5_8_patch3
fi
cd CMSSW_7_5_8_patch3/src
eval `scram runtime -sh`

export X509_USER_PROXY=$HOME/private/personal/voms_proxy.cert
curl -s --insecure https://cms-pdmv.cern.ch/mcm/public/restapi/requests/get_fragment/HIN-HiFall15-00170 --retry 2 --create-dirs -o Configuration/GenProduction/python/HIN-HiFall15-00170-fragment.py 
[ -s Configuration/GenProduction/python/HIN-HiFall15-00170-fragment.py ] || exit $?;

scram b
cd ../../
cmsDriver.py Configuration/GenProduction/python/HIN-HiFall15-00170-fragment.py --fileout file:HIN-HiFall15-00170.root --pileup_input "dbs:/Hydjet_Quenched_MinBias_5020GeV_750/HiFall15-75X_mcRun2_HeavyIon_v1_75X_mcRun2_HeavyIon_v1-v1/GEN-SIM" --mc --eventcontent RAWSIM --pileup HiMixGEN --customise SLHCUpgradeSimulations/Configuration/postLS1Customs.customisePostLS1_HI,Configuration/DataProcessing/Utils.addMonitoring --datatier GEN-SIM --conditions 75X_mcRun2_HeavyIon_v1 --beamspot MatchHI --step GEN,SIM --scenario HeavyIons --python_filename HIN-HiFall15-00170_1_cfg.py --no_exec -n 4914 || exit $? ; 
