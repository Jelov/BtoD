#include "TH1F.h"
#include "TH2F.h"
#include "TH3F.h"
#include "TFile.h"
#include "TH1D.h"
#include "TCanvas.h"
#include "TF1.h"
#include "TStyle.h"
#include "TRandom.h"
#include "TLatex.h"
#include "TLine.h"
#include "TLegend.h"
#include "TGraph.h"
#include "TFitter.h"
#include "TFitResult.h"
#include <TLine.h>
#include <TMath.h>



void readMCP(){


  TFile* infMCP = new TFile("/data/HeavyFlavourRun2/MC2015/Dntuple/PbPb/ntD_EvtBase_20160513_DfinderMC_PbPb_20160502_dPt1tkPt0p5_D0_prompt_Dpt2Dy1p1tkPt0p7tkEta2Decay2p9Dalpha0p14Skim_pthatweight.root");

	TTree* tMCP = (TTree*)infMCP->Get("ntDkpi"); 
  TTree* tMCPHI = (TTree*)infMCP->Get("ntHi");
  TTree* tMCPSkim = (TTree*)infMCP->Get("ntSkim");

  tMCP->AddFriend(tMCPHI);
  tMCP->AddFriend(tMCPSkim);

	tMCP 	


  TFile* outf = new TFile("bFeedDownPbPbMBMC.ntuple.root","recreate");

// 
  TCut cutPbPbMB = "pclusterCompatibilityFilter&&pprimaryVertexFilter&&phfCoincFilter3&&abs(PVz)<15&&Dy>-1.&&Dy<1.&&Dtrk1highPurity&&Dtrk2highPurity&&Dtrk1Pt>1.0&&Dtrk2Pt>1.0&&Dtrk1PtErr/Dtrk1Pt<0.3&&Dtrk2PtErr/Dtrk2Pt<0.3&&abs(Dtrk1Eta)<1.5&&abs(Dtrk2Eta)<1.5&&((DlxyBS/DlxyBSErr)>1.5&&Dalpha<0.12&&((Dpt>1&&Dpt<2&&(DsvpvDistance/DsvpvDisErr)>6.0&&Dchi2cl>0.25)||(Dpt>2&&Dpt<4&&(DsvpvDistance/DsvpvDisErr)>5.86&&Dchi2cl>0.224)||(Dpt>4&&Dpt<5&&(DsvpvDistance/DsvpvDisErr)>5.46&&Dchi2cl>0.196)||(Dpt>5&&Dpt<6&&(DsvpvDistance/DsvpvDisErr)>4.86&&Dchi2cl>0.170)||(Dpt>6&&Dpt<8&&(DsvpvDistance/DsvpvDisErr)>4.54&&Dchi2cl>0.125)||(Dpt>8&&Dpt<10&&(DsvpvDistance/DsvpvDisErr)>4.42&&Dchi2cl>0.091)||(Dpt>10&&Dpt<15&&(DsvpvDistance/DsvpvDisErr)>4.06&&Dchi2cl>0.069)||(Dpt>15&&Dpt<20&&(DsvpvDistance/DsvpvDisErr)>3.71&&Dchi2cl>0.056)||(Dpt>20&&Dpt<25&&(DsvpvDistance/DsvpvDisErr)>3.25&&Dchi2cl>0.054)||(Dpt>25&&(DsvpvDistance/DsvpvDisErr)>2.97&&Dchi2cl>0.050)))";

  TCut cutmc = "(Dgen==23333||Dgen==23344)";
  TCut cutmcSignal = "Dgen==23333";
  TCut cutmcSwapped = "Dgen==23344";
  TCut cutpt = "Dpt<20";
  TCut cutSignal = "abs(Dmass-1.8649)<0.025";
  TCut cutSideband = "abs(Dmass-1.8649)>0.075&&abs(Dmass-1.8649)<0.1";
  TCut cutPrompt = "DgenBAncestorpt<=0";
  TCut cutNonPrompt ="DgenBAncestorpt>0";
  TCut weightfunctionreco = "pthatweight";

  TCut cutCentralityBin = "hiBin>=0&&hiBin<200";
  TCut cutCentralityBinArr[] = {"hiBin>=0&&hiBin<200","hiBin>=0&&hiBin<20","hiBin>=20&&hiBin<60","hiBin>=60&&hiBin<100","hiBin>=100&&hiBin<200"};
  TCut weightfunctionrecoArr[]={ "pthatweight" , "1"};

  tMCP->Draw(Form("DsvpvDistance/DsvpvDisErr:DsvpvDistance*sin(Dalpha):Dpt>>hMCPSignal_%s%s", iCentStr.c_str(), iPtWeightStr.c_str() ),weightfunctionreco*(cutpt&&cutPbPbMB&&cutSignal&&cutmc&&cutPrompt&&cutCentralityBin));





// save minimal ntuple test size 



}
