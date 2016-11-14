#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include "TH1.h"
#include <iostream>
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include "TCut.h"
#include "TVector3.h"
#include <TMath.h>

void readData(){

  gStyle->SetTextSize(0.05);
  gStyle->SetTextFont(42);
  gStyle->SetPadRightMargin(0.043);
  gStyle->SetPadLeftMargin(0.18);
  gStyle->SetPadTopMargin(0.1);
  gStyle->SetPadBottomMargin(0.145);
  gStyle->SetTitleX(.0f);
  gStyle->SetOptFit(1111);
  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0);


// TFile, TTree

  TFile* inf = new TFile("/data/dmeson2015/DataDntuple/ntD_EvtBase_20160405_HIHardProbes_DfinderData_PbPb_20160402_dPt0tkPt2p5_D0Dstar3p5p_FINALJSON_skimmed.root");

  TTree* tData = (TTree*)inf->Get("ntDkpi");
  TTree* tSkim = (TTree*)inf->Get("ntSkim");
  TTree* tHi = (TTree*)inf->Get("ntHi");
  TTree* tHlt = (TTree*)inf->Get("ntHlt");

  tData->AddFriend(tSkim);
  tData->AddFriend(tHi);
  tData->AddFriend(tHlt);


// leaf

	// Skim leaf
   Int_t           centrality_path;
   Int_t           evtAna;
   Int_t           hltAna;
   Int_t           pcollisionEventSelection;
   Int_t           pHBHENoiseFilterResultProducer;
   Int_t           HBHENoiseFilterResult;
   Int_t           HBHENoiseFilterResultRun1;
   Int_t           HBHENoiseFilterResultRun2Loose;
   Int_t           HBHENoiseFilterResultRun2Tight;
   Int_t           HBHEIsoNoiseFilterResult;
   Int_t           pprimaryVertexFilter;
   Int_t           phfCoincFilter1;
   Int_t           phfCoincFilter2;
   Int_t           phfCoincFilter3;
   Int_t           phfCoincFilter4;
   Int_t           phfCoincFilter5;
   Int_t           pclusterCompatibilityFilter;
   Int_t           p;

	// Hi leaf
   UInt_t          run;
   ULong64_t       evt;
   UInt_t          lumi;
   Float_t         vx;
   Float_t         vy;
   Float_t         vz;
   Int_t           hiBin;
   Float_t         hiHF;
   Float_t         hiHFplus;
   Float_t         hiHFminus;
   Float_t         hiHFplusEta4;
   Float_t         hiHFminusEta4;
   Float_t         hiZDC;
   Float_t         hiZDCplus;
   Float_t         hiZDCminus;
   Float_t         hiHFhit;
   Float_t         hiHFhitPlus;
   Float_t         hiHFhitMinus;
   Float_t         hiET;
   Float_t         hiEE;
   Float_t         hiEB;
   Float_t         hiEEplus;
   Float_t         hiEEminus;
   Int_t           hiNpix;
   Int_t           hiNpixelTracks;
   Int_t           hiNtracks;
   Int_t           hiNtracksPtCut;
   Int_t           hiNtracksEtaCut;
   Int_t           hiNtracksEtaPtCut;
   Int_t           hiNevtPlane;
   Float_t         hiEvtPlanes[29];   //[hiNevtPlane]

	// Hlt leaf
   Int_t           HLT_HIDmesonHITrackingGlobal_Dpt20_v1;
   Int_t           HLT_HIDmesonHITrackingGlobal_Dpt20_v1_Prescl;
   Int_t           HLT_HIDmesonHITrackingGlobal_Dpt20_Cent0_10_v2;
   Int_t           HLT_HIDmesonHITrackingGlobal_Dpt20_Cent0_10_v2_Prescl;
   Int_t           HLT_HIDmesonHITrackingGlobal_Dpt20_Cent30_100_v2;
   Int_t           HLT_HIDmesonHITrackingGlobal_Dpt20_Cent30_100_v2_Prescl;
   Int_t           HLT_HIDmesonHITrackingGlobal_Dpt20_Cent50_100_v2;
   Int_t           HLT_HIDmesonHITrackingGlobal_Dpt20_Cent50_100_v2_Prescl;
   Int_t           HLT_HIDmesonHITrackingGlobal_Dpt30_v1;
   Int_t           HLT_HIDmesonHITrackingGlobal_Dpt30_v1_Prescl;
   Int_t           HLT_HIDmesonHITrackingGlobal_Dpt30_Cent0_10_v2;
   Int_t           HLT_HIDmesonHITrackingGlobal_Dpt30_Cent0_10_v2_Prescl;
   Int_t           HLT_HIDmesonHITrackingGlobal_Dpt30_Cent30_100_v1;
   Int_t           HLT_HIDmesonHITrackingGlobal_Dpt30_Cent30_100_v1_Prescl;
   Int_t           HLT_HIDmesonHITrackingGlobal_Dpt30_Cent50_100_v1;
   Int_t           HLT_HIDmesonHITrackingGlobal_Dpt30_Cent50_100_v1_Prescl;
   Int_t           HLT_HIDmesonHITrackingGlobal_Dpt40_v1;
   Int_t           HLT_HIDmesonHITrackingGlobal_Dpt40_v1_Prescl;
   Int_t           HLT_HIDmesonHITrackingGlobal_Dpt40_Cent0_10_v2;
   Int_t           HLT_HIDmesonHITrackingGlobal_Dpt40_Cent0_10_v2_Prescl;
   Int_t           HLT_HIDmesonHITrackingGlobal_Dpt40_Cent30_100_v1;
   Int_t           HLT_HIDmesonHITrackingGlobal_Dpt40_Cent30_100_v1_Prescl;
   Int_t           HLT_HIDmesonHITrackingGlobal_Dpt40_Cent50_100_v1;
   Int_t           HLT_HIDmesonHITrackingGlobal_Dpt40_Cent50_100_v1_Prescl;
   Int_t           HLT_HIDmesonHITrackingGlobal_Dpt50_v1;
   Int_t           HLT_HIDmesonHITrackingGlobal_Dpt50_v1_Prescl;
   Int_t           HLT_HIDmesonHITrackingGlobal_Dpt60_v1;
   Int_t           HLT_HIDmesonHITrackingGlobal_Dpt60_v1_Prescl;
   Int_t           HLT_HIDmesonHITrackingGlobal_Dpt70_v1;
   Int_t           HLT_HIDmesonHITrackingGlobal_Dpt70_v1_Prescl;
   Int_t           HLT_HIDmesonHITrackingGlobal_Dpt60_Cent30_100_v1;
   Int_t           HLT_HIDmesonHITrackingGlobal_Dpt60_Cent30_100_v1_Prescl;
   Int_t           HLT_HIDmesonHITrackingGlobal_Dpt60_Cent50_100_v1;
   Int_t           HLT_HIDmesonHITrackingGlobal_Dpt60_Cent50_100_v1_Prescl;
   Int_t           HLT_HIL1MinimumBiasHF1OR_v1;
   Int_t           HLT_HIL1MinimumBiasHF1OR_v1_Prescl;
   Int_t           HLT_HIL1MinimumBiasHF2OR_v1;
   Int_t           HLT_HIL1MinimumBiasHF2OR_v1_Prescl;
   Int_t           HLT_HIL1MinimumBiasHF1AND_v1;
   Int_t           HLT_HIL1MinimumBiasHF1AND_v1_Prescl;
   Int_t           HLT_HIL1MinimumBiasHF1ANDExpress_v1;
   Int_t           HLT_HIL1MinimumBiasHF1ANDExpress_v1_Prescl;
   Int_t           HLT_HIL1MinimumBiasHF2AND_v1;
   Int_t           HLT_HIL1MinimumBiasHF2AND_v1_Prescl;
   Int_t           HLT_HIL1MinimumBiasHF2ANDExpress_v1;
   Int_t           HLT_HIL1MinimumBiasHF2ANDExpress_v1_Prescl;
   Int_t           HLT_HIL1MinimumBiasHF1ANDPixel_SingleTrack_v1;
   Int_t           HLT_HIL1MinimumBiasHF1ANDPixel_SingleTrack_v1_Prescl;
   Int_t           HLT_HIDmesonHITrackingGlobal_Dpt20_v2;
   Int_t           HLT_HIDmesonHITrackingGlobal_Dpt20_v2_Prescl;
   Int_t           HLT_HIDmesonHITrackingGlobal_Dpt20_Cent0_10_v1;
   Int_t           HLT_HIDmesonHITrackingGlobal_Dpt20_Cent0_10_v1_Prescl;
   Int_t           HLT_HIDmesonHITrackingGlobal_Dpt20_Cent30_100_v1;
   Int_t           HLT_HIDmesonHITrackingGlobal_Dpt20_Cent30_100_v1_Prescl;
   Int_t           HLT_HIDmesonHITrackingGlobal_Dpt20_Cent30_100_v3;
   Int_t           HLT_HIDmesonHITrackingGlobal_Dpt20_Cent30_100_v3_Prescl;
   Int_t           HLT_HIDmesonHITrackingGlobal_Dpt20_Cent50_100_v1;
   Int_t           HLT_HIDmesonHITrackingGlobal_Dpt20_Cent50_100_v1_Prescl;
   Int_t           HLT_HIDmesonHITrackingGlobal_Dpt20_Cent50_100_v3;
   Int_t           HLT_HIDmesonHITrackingGlobal_Dpt20_Cent50_100_v3_Prescl;
   Int_t           HLT_HIDmesonHITrackingGlobal_Dpt30_Cent0_10_v1;
   Int_t           HLT_HIDmesonHITrackingGlobal_Dpt30_Cent0_10_v1_Prescl;
   Int_t           HLT_HIDmesonHITrackingGlobal_Dpt40_Cent0_10_v1;
   Int_t           HLT_HIDmesonHITrackingGlobal_Dpt40_Cent0_10_v1_Prescl;
   Int_t           HLT_HIL1MinimumBiasHF2AND_part1_v1;
   Int_t           HLT_HIL1MinimumBiasHF2AND_part1_v1_Prescl;
   Int_t           HLT_HIL1MinimumBiasHF2AND_part2_v1;
   Int_t           HLT_HIL1MinimumBiasHF2AND_part2_v1_Prescl;
   Int_t           HLT_HIL1MinimumBiasHF2AND_part3_v1;
   Int_t           HLT_HIL1MinimumBiasHF2AND_part3_v1_Prescl;
   Int_t           HLT_HIL1MinimumBiasHF2AND_part4_v1;
   Int_t           HLT_HIL1MinimumBiasHF2AND_part4_v1_Prescl;
   Int_t           HLT_HIL1MinimumBiasHF2AND_part5_v1;
   Int_t           HLT_HIL1MinimumBiasHF2AND_part5_v1_Prescl;
   Int_t           HLT_HIL1MinimumBiasHF2AND_part6_v1;
   Int_t           HLT_HIL1MinimumBiasHF2AND_part6_v1_Prescl;
   Int_t           HLT_HIL1MinimumBiasHF2AND_part7_v1;
   Int_t           HLT_HIL1MinimumBiasHF2AND_part7_v1_Prescl;
   Int_t           HLT_HIL1MinimumBiasHF2AND_part8_v1;
   Int_t           HLT_HIL1MinimumBiasHF2AND_part8_v1_Prescl;
   Int_t           HLT_HIL1MinimumBiasHF2AND_part9_v1;
   Int_t           HLT_HIL1MinimumBiasHF2AND_part9_v1_Prescl;
   Int_t           HLT_HIL1MinimumBiasHF2AND_part10_v1;
   Int_t           HLT_HIL1MinimumBiasHF2AND_part10_v1_Prescl;
   Int_t           HLT_HIL1MinimumBiasHF2AND_part11_v1;
   Int_t           HLT_HIL1MinimumBiasHF2AND_part11_v1_Prescl;
   Int_t           HLT_HIL1MinimumBiasHF2ANDPixel_SingleTrack_v1;
   Int_t           HLT_HIL1MinimumBiasHF2ANDPixel_SingleTrack_v1_Prescl;

	// 


   Int_t           RunNo;
   Int_t           EvtNo;
   Int_t           LumiNo;
   Int_t           Dsize;
   Float_t         PVx;
   Float_t         PVy;
   Float_t         PVz;
   Float_t         PVxE;
   Float_t         PVyE;
   Float_t         PVzE;
   Float_t         PVnchi2;
   Float_t         BSx;
   Float_t         BSy;
   Float_t         BSz;
   Float_t         BSxErr;
   Float_t         BSyErr;
   Float_t         BSzErr;
   Float_t         BSdxdz;
   Float_t         BSdydz;
   Float_t         BSdxdzErr;
   Float_t         BSdydzErr;
   Float_t         BSWidthX;
   Float_t         BSWidthXErr;
   Float_t         BSWidthY;
   Float_t         BSWidthYErr;
   Int_t           Dindex[335];   //[Dsize]
   Int_t           Dtype[335];   //[Dsize]
   Float_t         Dmass[335];   //[Dsize]
   Float_t         Dpt[335];   //[Dsize]
   Float_t         Deta[335];   //[Dsize]
   Float_t         Dphi[335];   //[Dsize]
   Float_t         Dy[335];   //[Dsize]
   Float_t         DvtxX[335];   //[Dsize]
   Float_t         DvtxY[335];   //[Dsize]
   Float_t         Dd0[335];   //[Dsize]
   Float_t         Dd0Err[335];   //[Dsize]
   Float_t         Ddxyz[335];   //[Dsize]
   Float_t         DdxyzErr[335];   //[Dsize]
   Float_t         Dchi2ndf[335];   //[Dsize]
   Float_t         Dchi2cl[335];   //[Dsize]
   Float_t         Ddtheta[335];   //[Dsize]
   Float_t         Dlxy[335];   //[Dsize]
   Float_t         Dalpha[335];   //[Dsize]
   Float_t         DsvpvDistance[335];   //[Dsize]
   Float_t         DsvpvDisErr[335];   //[Dsize]
   Float_t         DsvpvDistance_2D[335];   //[Dsize]
   Float_t         DsvpvDisErr_2D[335];   //[Dsize]
   Float_t         DlxyBS[335];   //[Dsize]
   Float_t         DlxyBSErr[335];   //[Dsize]
   Float_t         DMaxDoca[335];   //[Dsize]
   Int_t           Dtrk1Idx[335];   //[Dsize]
   Int_t           Dtrk2Idx[335];   //[Dsize]
   Float_t         Dtrk1Pt[335];   //[Dsize]
   Float_t         Dtrk2Pt[335];   //[Dsize]
   Float_t         Dtrk1Eta[335];   //[Dsize]
   Float_t         Dtrk2Eta[335];   //[Dsize]
   Float_t         Dtrk1Phi[335];   //[Dsize]
   Float_t         Dtrk2Phi[335];   //[Dsize]
   Float_t         Dtrk1PtErr[335];   //[Dsize]
   Float_t         Dtrk2PtErr[335];   //[Dsize]
   Float_t         Dtrk1EtaErr[335];   //[Dsize]
   Float_t         Dtrk2EtaErr[335];   //[Dsize]
   Float_t         Dtrk1PhiErr[335];   //[Dsize]
   Float_t         Dtrk2PhiErr[335];   //[Dsize]
   Float_t         Dtrk1Y[335];   //[Dsize]
   Float_t         Dtrk2Y[335];   //[Dsize]
   Float_t         Dtrk1Dxy[335];   //[Dsize]
   Float_t         Dtrk2Dxy[335];   //[Dsize]
   Float_t         Dtrk1D0Err[335];   //[Dsize]
   Float_t         Dtrk2D0Err[335];   //[Dsize]
   Float_t         Dtrk1PixelHit[335];   //[Dsize]
   Float_t         Dtrk2PixelHit[335];   //[Dsize]
   Float_t         Dtrk1StripHit[335];   //[Dsize]
   Float_t         Dtrk2StripHit[335];   //[Dsize]
   Float_t         Dtrk1nStripLayer[335];   //[Dsize]
   Float_t         Dtrk2nStripLayer[335];   //[Dsize]
   Float_t         Dtrk1nPixelLayer[335];   //[Dsize]
   Float_t         Dtrk2nPixelLayer[335];   //[Dsize]
   Float_t         Dtrk1Chi2ndf[335];   //[Dsize]
   Float_t         Dtrk2Chi2ndf[335];   //[Dsize]
   Float_t         Dtrk1MassHypo[335];   //[Dsize]
   Float_t         Dtrk2MassHypo[335];   //[Dsize]
   Float_t         Dtrk1MVAVal[335];   //[Dsize]
   Float_t         Dtrk2MVAVal[335];   //[Dsize]
   Int_t           Dtrk1Algo[335];   //[Dsize]
   Int_t           Dtrk2Algo[335];   //[Dsize]
   Int_t           Dtrk1OriginalAlgo[335];   //[Dsize]
   Int_t           Dtrk2OriginalAlgo[335];   //[Dsize]
   Bool_t          Dtrk1highPurity[335];   //[Dsize]
   Bool_t          Dtrk2highPurity[335];   //[Dsize]
   Int_t           Dtrk1Quality[335];   //[Dsize]
   Int_t           Dtrk2Quality[335];   //[Dsize]
   Float_t         Dgen[335];   //[Dsize]
   Int_t           DgenIndex[335];   //[Dsize]
   Int_t           DgennDa[335];   //[Dsize]
   Float_t         Dgenpt[335];   //[Dsize]
   Float_t         Dgeneta[335];   //[Dsize]
   Float_t         Dgenphi[335];   //[Dsize]
   Float_t         Dgeny[335];   //[Dsize]



// branch

	// Skim branch
   TBranch        *b_centrality_path;   //!
   TBranch        *b_evtAna;   //!
   TBranch        *b_hltAna;   //!
   TBranch        *b_pcollisionEventSelection;   //!
   TBranch        *b_pHBHENoiseFilterResultProducer;   //!
   TBranch        *b_HBHENoiseFilterResult;   //!
   TBranch        *b_HBHENoiseFilterResultRun1;   //!
   TBranch        *b_HBHENoiseFilterResultRun2Loose;   //!
   TBranch        *b_HBHENoiseFilterResultRun2Tight;   //!
   TBranch        *b_HBHEIsoNoiseFilterResult;   //!
   TBranch        *b_pprimaryVertexFilter;   //!
   TBranch        *b_phfCoincFilter1;   //!
   TBranch        *b_phfCoincFilter2;   //!
   TBranch        *b_phfCoincFilter3;   //!
   TBranch        *b_phfCoincFilter4;   //!
   TBranch        *b_phfCoincFilter5;   //!
   TBranch        *b_pclusterCompatibilityFilter;   //!
   TBranch        *b_p;   //!

	// Hi branch
   TBranch        *b_run;   //!
   TBranch        *b_evt;   //!
   TBranch        *b_lumi;   //!
   TBranch        *b_vx;   //!
   TBranch        *b_vy;   //!
   TBranch        *b_vz;   //!
   TBranch        *b_hiBin;   //!
   TBranch        *b_hiHF;   //!
   TBranch        *b_hiHFplus;   //!
   TBranch        *b_hiHFminus;   //!
   TBranch        *b_hiHFplusEta4;   //!
   TBranch        *b_hiHFminusEta4;   //!
   TBranch        *b_hiZDC;   //!
   TBranch        *b_hiZDCplus;   //!
   TBranch        *b_hiZDCminus;   //!
   TBranch        *b_hiHFhit;   //!
   TBranch        *b_hiHFhitPlus;   //!
   TBranch        *b_hiHFhitMinus;   //!
   TBranch        *b_hiET;   //!
   TBranch        *b_hiEE;   //!
   TBranch        *b_hiEB;   //!
   TBranch        *b_hiEEplus;   //!
   TBranch        *b_hiEEminus;   //!
   TBranch        *b_hiNpix;   //!
   TBranch        *b_hiNpixelTracks;   //!
   TBranch        *b_hiNtracks;   //!
   TBranch        *b_hiNtracksPtCut;   //!
   TBranch        *b_hiNtracksEtaCut;   //!
   TBranch        *b_hiNtracksEtaPtCut;   //!
   TBranch        *b_hiNevtPlane;   //!
   TBranch        *b_hiEvtPlanes;   //!

	// Hlt Branch
   TBranch        *b_HLT_HIDmesonHITrackingGlobal_Dpt20_v1;   //!
   TBranch        *b_HLT_HIDmesonHITrackingGlobal_Dpt20_v1_Prescl;   //!
   TBranch        *b_HLT_HIDmesonHITrackingGlobal_Dpt20_Cent0_10_v2;   //!
   TBranch        *b_HLT_HIDmesonHITrackingGlobal_Dpt20_Cent0_10_v2_Prescl;   //!
   TBranch        *b_HLT_HIDmesonHITrackingGlobal_Dpt20_Cent30_100_v2;   //!
   TBranch        *b_HLT_HIDmesonHITrackingGlobal_Dpt20_Cent30_100_v2_Prescl;   //!
   TBranch        *b_HLT_HIDmesonHITrackingGlobal_Dpt20_Cent50_100_v2;   //!
   TBranch        *b_HLT_HIDmesonHITrackingGlobal_Dpt20_Cent50_100_v2_Prescl;   //!
   TBranch        *b_HLT_HIDmesonHITrackingGlobal_Dpt30_v1;   //!
   TBranch        *b_HLT_HIDmesonHITrackingGlobal_Dpt30_v1_Prescl;   //!
   TBranch        *b_HLT_HIDmesonHITrackingGlobal_Dpt30_Cent0_10_v2;   //!
   TBranch        *b_HLT_HIDmesonHITrackingGlobal_Dpt30_Cent0_10_v2_Prescl;   //!
   TBranch        *b_HLT_HIDmesonHITrackingGlobal_Dpt30_Cent30_100_v1;   //!
   TBranch        *b_HLT_HIDmesonHITrackingGlobal_Dpt30_Cent30_100_v1_Prescl;   //!
   TBranch        *b_HLT_HIDmesonHITrackingGlobal_Dpt30_Cent50_100_v1;   //!
   TBranch        *b_HLT_HIDmesonHITrackingGlobal_Dpt30_Cent50_100_v1_Prescl;   //!
   TBranch        *b_HLT_HIDmesonHITrackingGlobal_Dpt40_v1;   //!
   TBranch        *b_HLT_HIDmesonHITrackingGlobal_Dpt40_v1_Prescl;   //!
   TBranch        *b_HLT_HIDmesonHITrackingGlobal_Dpt40_Cent0_10_v2;   //!
   TBranch        *b_HLT_HIDmesonHITrackingGlobal_Dpt40_Cent0_10_v2_Prescl;   //!
   TBranch        *b_HLT_HIDmesonHITrackingGlobal_Dpt40_Cent30_100_v1;   //!
   TBranch        *b_HLT_HIDmesonHITrackingGlobal_Dpt40_Cent30_100_v1_Prescl;   //!
   TBranch        *b_HLT_HIDmesonHITrackingGlobal_Dpt40_Cent50_100_v1;   //!
   TBranch        *b_HLT_HIDmesonHITrackingGlobal_Dpt40_Cent50_100_v1_Prescl;   //!
   TBranch        *b_HLT_HIDmesonHITrackingGlobal_Dpt50_v1;   //!
   TBranch        *b_HLT_HIDmesonHITrackingGlobal_Dpt50_v1_Prescl;   //!
   TBranch        *b_HLT_HIDmesonHITrackingGlobal_Dpt60_v1;   //!
   TBranch        *b_HLT_HIDmesonHITrackingGlobal_Dpt60_v1_Prescl;   //!
   TBranch        *b_HLT_HIDmesonHITrackingGlobal_Dpt70_v1;   //!
   TBranch        *b_HLT_HIDmesonHITrackingGlobal_Dpt70_v1_Prescl;   //!
   TBranch        *b_HLT_HIDmesonHITrackingGlobal_Dpt60_Cent30_100_v1;   //!
   TBranch        *b_HLT_HIDmesonHITrackingGlobal_Dpt60_Cent30_100_v1_Prescl;   //!
   TBranch        *b_HLT_HIDmesonHITrackingGlobal_Dpt60_Cent50_100_v1;   //!
   TBranch        *b_HLT_HIDmesonHITrackingGlobal_Dpt60_Cent50_100_v1_Prescl;   //!
   TBranch        *b_HLT_HIL1MinimumBiasHF1OR_v1;   //!
   TBranch        *b_HLT_HIL1MinimumBiasHF1OR_v1_Prescl;   //!
   TBranch        *b_HLT_HIL1MinimumBiasHF2OR_v1;   //!
   TBranch        *b_HLT_HIL1MinimumBiasHF2OR_v1_Prescl;   //!
   TBranch        *b_HLT_HIL1MinimumBiasHF1AND_v1;   //!
   TBranch        *b_HLT_HIL1MinimumBiasHF1AND_v1_Prescl;   //!
   TBranch        *b_HLT_HIL1MinimumBiasHF1ANDExpress_v1;   //!
   TBranch        *b_HLT_HIL1MinimumBiasHF1ANDExpress_v1_Prescl;   //!
   TBranch        *b_HLT_HIL1MinimumBiasHF2AND_v1;   //!
   TBranch        *b_HLT_HIL1MinimumBiasHF2AND_v1_Prescl;   //!
   TBranch        *b_HLT_HIL1MinimumBiasHF2ANDExpress_v1;   //!
   TBranch        *b_HLT_HIL1MinimumBiasHF2ANDExpress_v1_Prescl;   //!
   TBranch        *b_HLT_HIL1MinimumBiasHF1ANDPixel_SingleTrack_v1;   //!
   TBranch        *b_HLT_HIL1MinimumBiasHF1ANDPixel_SingleTrack_v1_Prescl;   //!
   TBranch        *b_HLT_HIDmesonHITrackingGlobal_Dpt20_v2;   //!
   TBranch        *b_HLT_HIDmesonHITrackingGlobal_Dpt20_v2_Prescl;   //!
   TBranch        *b_HLT_HIDmesonHITrackingGlobal_Dpt20_Cent0_10_v1;   //!
   TBranch        *b_HLT_HIDmesonHITrackingGlobal_Dpt20_Cent0_10_v1_Prescl;   //!
   TBranch        *b_HLT_HIDmesonHITrackingGlobal_Dpt20_Cent30_100_v1;   //!
   TBranch        *b_HLT_HIDmesonHITrackingGlobal_Dpt20_Cent30_100_v1_Prescl;   //!
   TBranch        *b_HLT_HIDmesonHITrackingGlobal_Dpt20_Cent30_100_v3;   //!
   TBranch        *b_HLT_HIDmesonHITrackingGlobal_Dpt20_Cent30_100_v3_Prescl;   //!
   TBranch        *b_HLT_HIDmesonHITrackingGlobal_Dpt20_Cent50_100_v1;   //!
   TBranch        *b_HLT_HIDmesonHITrackingGlobal_Dpt20_Cent50_100_v1_Prescl;   //!
   TBranch        *b_HLT_HIDmesonHITrackingGlobal_Dpt20_Cent50_100_v3;   //!
   TBranch        *b_HLT_HIDmesonHITrackingGlobal_Dpt20_Cent50_100_v3_Prescl;   //!
   TBranch        *b_HLT_HIDmesonHITrackingGlobal_Dpt30_Cent0_10_v1;   //!
   TBranch        *b_HLT_HIDmesonHITrackingGlobal_Dpt30_Cent0_10_v1_Prescl;   //!
   TBranch        *b_HLT_HIDmesonHITrackingGlobal_Dpt40_Cent0_10_v1;   //!
   TBranch        *b_HLT_HIDmesonHITrackingGlobal_Dpt40_Cent0_10_v1_Prescl;   //!
   TBranch        *b_HLT_HIL1MinimumBiasHF2AND_part1_v1;   //!
   TBranch        *b_HLT_HIL1MinimumBiasHF2AND_part1_v1_Prescl;   //!
   TBranch        *b_HLT_HIL1MinimumBiasHF2AND_part2_v1;   //!
   TBranch        *b_HLT_HIL1MinimumBiasHF2AND_part2_v1_Prescl;   //!
   TBranch        *b_HLT_HIL1MinimumBiasHF2AND_part3_v1;   //!
   TBranch        *b_HLT_HIL1MinimumBiasHF2AND_part3_v1_Prescl;   //!
   TBranch        *b_HLT_HIL1MinimumBiasHF2AND_part4_v1;   //!
   TBranch        *b_HLT_HIL1MinimumBiasHF2AND_part4_v1_Prescl;   //!
   TBranch        *b_HLT_HIL1MinimumBiasHF2AND_part5_v1;   //!
   TBranch        *b_HLT_HIL1MinimumBiasHF2AND_part5_v1_Prescl;   //!
   TBranch        *b_HLT_HIL1MinimumBiasHF2AND_part6_v1;   //!
   TBranch        *b_HLT_HIL1MinimumBiasHF2AND_part6_v1_Prescl;   //!
   TBranch        *b_HLT_HIL1MinimumBiasHF2AND_part7_v1;   //!
   TBranch        *b_HLT_HIL1MinimumBiasHF2AND_part7_v1_Prescl;   //!
   TBranch        *b_HLT_HIL1MinimumBiasHF2AND_part8_v1;   //!
   TBranch        *b_HLT_HIL1MinimumBiasHF2AND_part8_v1_Prescl;   //!
   TBranch        *b_HLT_HIL1MinimumBiasHF2AND_part9_v1;   //!
   TBranch        *b_HLT_HIL1MinimumBiasHF2AND_part9_v1_Prescl;   //!
   TBranch        *b_HLT_HIL1MinimumBiasHF2AND_part10_v1;   //!
   TBranch        *b_HLT_HIL1MinimumBiasHF2AND_part10_v1_Prescl;   //!
   TBranch        *b_HLT_HIL1MinimumBiasHF2AND_part11_v1;   //!
   TBranch        *b_HLT_HIL1MinimumBiasHF2AND_part11_v1_Prescl;   //!
   TBranch        *b_HLT_HIL1MinimumBiasHF2ANDPixel_SingleTrack_v1;   //!
   TBranch        *b_HLT_HIL1MinimumBiasHF2ANDPixel_SingleTrack_v1_Prescl;   //!


//

   // List of branches
   TBranch        *b_RunNo;   //!
   TBranch        *b_EvtNo;   //!
   TBranch        *b_LumiNo;   //!
   TBranch        *b_Dsize;   //!
   TBranch        *b_PVx;   //!
   TBranch        *b_PVy;   //!
   TBranch        *b_PVz;   //!
   TBranch        *b_PVxE;   //!
   TBranch        *b_PVyE;   //!
   TBranch        *b_PVzE;   //!
   TBranch        *b_PVnchi2;   //!
   TBranch        *b_BSx;   //!
   TBranch        *b_BSy;   //!
   TBranch        *b_BSz;   //!
   TBranch        *b_BSxErr;   //!
   TBranch        *b_BSyErr;   //!
   TBranch        *b_BSzErr;   //!
   TBranch        *b_BSdxdz;   //!
   TBranch        *b_BSdydz;   //!
   TBranch        *b_BSdxdzErr;   //!
   TBranch        *b_BSdydzErr;   //!
   TBranch        *b_BSWidthX;   //!
   TBranch        *b_BSWidthXErr;   //!
   TBranch        *b_BSWidthY;   //!
   TBranch        *b_BSWidthYErr;   //!
   TBranch        *b_Dindex;   //!
   TBranch        *b_Dtype;   //!
   TBranch        *b_Dmass;   //!
   TBranch        *b_Dpt;   //!
   TBranch        *b_Deta;   //!
   TBranch        *b_Dphi;   //!
   TBranch        *b_Dy;   //!
   TBranch        *b_DvtxX;   //!
   TBranch        *b_DvtxY;   //!
   TBranch        *b_Dd0;   //!
   TBranch        *b_Dd0Err;   //!
   TBranch        *b_Ddxyz;   //!
   TBranch        *b_DdxyzErr;   //!
   TBranch        *b_Dchi2ndf;   //!
   TBranch        *b_Dchi2cl;   //!
   TBranch        *b_Ddtheta;   //!
   TBranch        *b_Dlxy;   //!
   TBranch        *b_Dalpha;   //!
   TBranch        *b_DsvpvDistance;   //!
   TBranch        *b_DsvpvDisErr;   //!
   TBranch        *b_DsvpvDistance_2D;   //!
   TBranch        *b_DsvpvDisErr_2D;   //!
   TBranch        *b_DlxyBS;   //!
   TBranch        *b_DlxyBSErr;   //!
   TBranch        *b_DMaxDoca;   //!
   TBranch        *b_Dtrk1Idx;   //!
   TBranch        *b_Dtrk2Idx;   //!
   TBranch        *b_Dtrk1Pt;   //!
   TBranch        *b_Dtrk2Pt;   //!
   TBranch        *b_Dtrk1Eta;   //!
   TBranch        *b_Dtrk2Eta;   //!
   TBranch        *b_Dtrk1Phi;   //!
   TBranch        *b_Dtrk2Phi;   //!
   TBranch        *b_Dtrk1PtErr;   //!
   TBranch        *b_Dtrk2PtErr;   //!
   TBranch        *b_Dtrk1EtaErr;   //!
   TBranch        *b_Dtrk2EtaErr;   //!
   TBranch        *b_Dtrk1PhiErr;   //!
   TBranch        *b_Dtrk2PhiErr;   //!
   TBranch        *b_Dtrk1Y;   //!
   TBranch        *b_Dtrk2Y;   //!
   TBranch        *b_Dtrk1Dxy;   //!
   TBranch        *b_Dtrk2Dxy;   //!
   TBranch        *b_Dtrk1D0Err;   //!
   TBranch        *b_Dtrk2D0Err;   //!
   TBranch        *b_Dtrk1PixelHit;   //!
   TBranch        *b_Dtrk2PixelHit;   //!
   TBranch        *b_Dtrk1StripHit;   //!
   TBranch        *b_Dtrk2StripHit;   //!
   TBranch        *b_Dtrk1nStripLayer;   //!
   TBranch        *b_Dtrk2nStripLayer;   //!
   TBranch        *b_Dtrk1nPixelLayer;   //!
   TBranch        *b_Dtrk2nPixelLayer;   //!
   TBranch        *b_Dtrk1Chi2ndf;   //!
   TBranch        *b_Dtrk2Chi2ndf;   //!
   TBranch        *b_Dtrk1MassHypo;   //!
   TBranch        *b_Dtrk2MassHypo;   //!
   TBranch        *b_Dtrk1MVAVal;   //!
   TBranch        *b_Dtrk2MVAVal;   //!
   TBranch        *b_Dtrk1Algo;   //!
   TBranch        *b_Dtrk2Algo;   //!
   TBranch        *b_Dtrk1OriginalAlgo;   //!
   TBranch        *b_Dtrk2OriginalAlgo;   //!
   TBranch        *b_Dtrk1highPurity;   //!
   TBranch        *b_Dtrk2highPurity;   //!
   TBranch        *b_Dtrk1Quality;   //!
   TBranch        *b_Dtrk2Quality;   //!
   TBranch        *b_Dgen;   //!
   TBranch        *b_DgenIndex;   //!
   TBranch        *b_DgennDa;   //!
   TBranch        *b_Dgenpt;   //!
   TBranch        *b_Dgeneta;   //!
   TBranch        *b_Dgenphi;   //!
   TBranch        *b_Dgeny;   //!



// SetBranchAddress

	// Skim 
   fChain->SetBranchAddress("centrality_path", &centrality_path, &b_centrality_path);
   fChain->SetBranchAddress("evtAna", &evtAna, &b_evtAna);
   fChain->SetBranchAddress("hltAna", &hltAna, &b_hltAna);
   fChain->SetBranchAddress("pcollisionEventSelection", &pcollisionEventSelection, &b_pcollisionEventSelection);
   fChain->SetBranchAddress("pHBHENoiseFilterResultProducer", &pHBHENoiseFilterResultProducer, &b_pHBHENoiseFilterResultProducer);
   fChain->SetBranchAddress("HBHENoiseFilterResult", &HBHENoiseFilterResult, &b_HBHENoiseFilterResult);
   fChain->SetBranchAddress("HBHENoiseFilterResultRun1", &HBHENoiseFilterResultRun1, &b_HBHENoiseFilterResultRun1);
   fChain->SetBranchAddress("HBHENoiseFilterResultRun2Loose", &HBHENoiseFilterResultRun2Loose, &b_HBHENoiseFilterResultRun2Loose);
   fChain->SetBranchAddress("HBHENoiseFilterResultRun2Tight", &HBHENoiseFilterResultRun2Tight, &b_HBHENoiseFilterResultRun2Tight);
   fChain->SetBranchAddress("HBHEIsoNoiseFilterResult", &HBHEIsoNoiseFilterResult, &b_HBHEIsoNoiseFilterResult);
   fChain->SetBranchAddress("pprimaryVertexFilter", &pprimaryVertexFilter, &b_pprimaryVertexFilter);
   fChain->SetBranchAddress("phfCoincFilter1", &phfCoincFilter1, &b_phfCoincFilter1);
   fChain->SetBranchAddress("phfCoincFilter2", &phfCoincFilter2, &b_phfCoincFilter2);
   fChain->SetBranchAddress("phfCoincFilter3", &phfCoincFilter3, &b_phfCoincFilter3);
   fChain->SetBranchAddress("phfCoincFilter4", &phfCoincFilter4, &b_phfCoincFilter4);
   fChain->SetBranchAddress("phfCoincFilter5", &phfCoincFilter5, &b_phfCoincFilter5);
   fChain->SetBranchAddress("pclusterCompatibilityFilter", &pclusterCompatibilityFilter, &b_pclusterCompatibilityFilter);
   fChain->SetBranchAddress("p", &p, &b_p);

	// Hi
   fChain->SetBranchAddress("run", &run, &b_run);
   fChain->SetBranchAddress("evt", &evt, &b_evt);
   fChain->SetBranchAddress("lumi", &lumi, &b_lumi);
   fChain->SetBranchAddress("vx", &vx, &b_vx);
   fChain->SetBranchAddress("vy", &vy, &b_vy);
   fChain->SetBranchAddress("vz", &vz, &b_vz);
   fChain->SetBranchAddress("hiBin", &hiBin, &b_hiBin);
   fChain->SetBranchAddress("hiHF", &hiHF, &b_hiHF);
   fChain->SetBranchAddress("hiHFplus", &hiHFplus, &b_hiHFplus);
   fChain->SetBranchAddress("hiHFminus", &hiHFminus, &b_hiHFminus);
   fChain->SetBranchAddress("hiHFplusEta4", &hiHFplusEta4, &b_hiHFplusEta4);
   fChain->SetBranchAddress("hiHFminusEta4", &hiHFminusEta4, &b_hiHFminusEta4);
   fChain->SetBranchAddress("hiZDC", &hiZDC, &b_hiZDC);
   fChain->SetBranchAddress("hiZDCplus", &hiZDCplus, &b_hiZDCplus);
   fChain->SetBranchAddress("hiZDCminus", &hiZDCminus, &b_hiZDCminus);
   fChain->SetBranchAddress("hiHFhit", &hiHFhit, &b_hiHFhit);
   fChain->SetBranchAddress("hiHFhitPlus", &hiHFhitPlus, &b_hiHFhitPlus);
   fChain->SetBranchAddress("hiHFhitMinus", &hiHFhitMinus, &b_hiHFhitMinus);
   fChain->SetBranchAddress("hiET", &hiET, &b_hiET);
   fChain->SetBranchAddress("hiEE", &hiEE, &b_hiEE);
   fChain->SetBranchAddress("hiEB", &hiEB, &b_hiEB);
   fChain->SetBranchAddress("hiEEplus", &hiEEplus, &b_hiEEplus);
   fChain->SetBranchAddress("hiEEminus", &hiEEminus, &b_hiEEminus);
   fChain->SetBranchAddress("hiNpix", &hiNpix, &b_hiNpix);
   fChain->SetBranchAddress("hiNpixelTracks", &hiNpixelTracks, &b_hiNpixelTracks);
   fChain->SetBranchAddress("hiNtracks", &hiNtracks, &b_hiNtracks);
   fChain->SetBranchAddress("hiNtracksPtCut", &hiNtracksPtCut, &b_hiNtracksPtCut);
   fChain->SetBranchAddress("hiNtracksEtaCut", &hiNtracksEtaCut, &b_hiNtracksEtaCut);
   fChain->SetBranchAddress("hiNtracksEtaPtCut", &hiNtracksEtaPtCut, &b_hiNtracksEtaPtCut);
   fChain->SetBranchAddress("hiNevtPlane", &hiNevtPlane, &b_hiNevtPlane);
   fChain->SetBranchAddress("hiEvtPlanes", hiEvtPlanes, &b_hiEvtPlanes);

	//Hlt 
   fChain->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt20_v1", &HLT_HIDmesonHITrackingGlobal_Dpt20_v1, &b_HLT_HIDmesonHITrackingGlobal_Dpt20_v1);
   fChain->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt20_v1_Prescl", &HLT_HIDmesonHITrackingGlobal_Dpt20_v1_Prescl, &b_HLT_HIDmesonHITrackingGlobal_Dpt20_v1_Prescl);
   fChain->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt20_Cent0_10_v2", &HLT_HIDmesonHITrackingGlobal_Dpt20_Cent0_10_v2, &b_HLT_HIDmesonHITrackingGlobal_Dpt20_Cent0_10_v2);
   fChain->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt20_Cent0_10_v2_Prescl", &HLT_HIDmesonHITrackingGlobal_Dpt20_Cent0_10_v2_Prescl, &b_HLT_HIDmesonHITrackingGlobal_Dpt20_Cent0_10_v2_Prescl);
   fChain->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt20_Cent30_100_v2", &HLT_HIDmesonHITrackingGlobal_Dpt20_Cent30_100_v2, &b_HLT_HIDmesonHITrackingGlobal_Dpt20_Cent30_100_v2);
   fChain->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt20_Cent30_100_v2_Prescl", &HLT_HIDmesonHITrackingGlobal_Dpt20_Cent30_100_v2_Prescl, &b_HLT_HIDmesonHITrackingGlobal_Dpt20_Cent30_100_v2_Prescl);
   fChain->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt20_Cent50_100_v2", &HLT_HIDmesonHITrackingGlobal_Dpt20_Cent50_100_v2, &b_HLT_HIDmesonHITrackingGlobal_Dpt20_Cent50_100_v2);
   fChain->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt20_Cent50_100_v2_Prescl", &HLT_HIDmesonHITrackingGlobal_Dpt20_Cent50_100_v2_Prescl, &b_HLT_HIDmesonHITrackingGlobal_Dpt20_Cent50_100_v2_Prescl);
   fChain->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt30_v1", &HLT_HIDmesonHITrackingGlobal_Dpt30_v1, &b_HLT_HIDmesonHITrackingGlobal_Dpt30_v1);
   fChain->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt30_v1_Prescl", &HLT_HIDmesonHITrackingGlobal_Dpt30_v1_Prescl, &b_HLT_HIDmesonHITrackingGlobal_Dpt30_v1_Prescl);
   fChain->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt30_Cent0_10_v2", &HLT_HIDmesonHITrackingGlobal_Dpt30_Cent0_10_v2, &b_HLT_HIDmesonHITrackingGlobal_Dpt30_Cent0_10_v2);
   fChain->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt30_Cent0_10_v2_Prescl", &HLT_HIDmesonHITrackingGlobal_Dpt30_Cent0_10_v2_Prescl, &b_HLT_HIDmesonHITrackingGlobal_Dpt30_Cent0_10_v2_Prescl);
   fChain->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt30_Cent30_100_v1", &HLT_HIDmesonHITrackingGlobal_Dpt30_Cent30_100_v1, &b_HLT_HIDmesonHITrackingGlobal_Dpt30_Cent30_100_v1);
   fChain->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt30_Cent30_100_v1_Prescl", &HLT_HIDmesonHITrackingGlobal_Dpt30_Cent30_100_v1_Prescl, &b_HLT_HIDmesonHITrackingGlobal_Dpt30_Cent30_100_v1_Prescl);
   fChain->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt30_Cent50_100_v1", &HLT_HIDmesonHITrackingGlobal_Dpt30_Cent50_100_v1, &b_HLT_HIDmesonHITrackingGlobal_Dpt30_Cent50_100_v1);
   fChain->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt30_Cent50_100_v1_Prescl", &HLT_HIDmesonHITrackingGlobal_Dpt30_Cent50_100_v1_Prescl, &b_HLT_HIDmesonHITrackingGlobal_Dpt30_Cent50_100_v1_Prescl);
   fChain->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt40_v1", &HLT_HIDmesonHITrackingGlobal_Dpt40_v1, &b_HLT_HIDmesonHITrackingGlobal_Dpt40_v1);
   fChain->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt40_v1_Prescl", &HLT_HIDmesonHITrackingGlobal_Dpt40_v1_Prescl, &b_HLT_HIDmesonHITrackingGlobal_Dpt40_v1_Prescl);
   fChain->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt40_Cent0_10_v2", &HLT_HIDmesonHITrackingGlobal_Dpt40_Cent0_10_v2, &b_HLT_HIDmesonHITrackingGlobal_Dpt40_Cent0_10_v2);
   fChain->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt40_Cent0_10_v2_Prescl", &HLT_HIDmesonHITrackingGlobal_Dpt40_Cent0_10_v2_Prescl, &b_HLT_HIDmesonHITrackingGlobal_Dpt40_Cent0_10_v2_Prescl);
   fChain->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt40_Cent30_100_v1", &HLT_HIDmesonHITrackingGlobal_Dpt40_Cent30_100_v1, &b_HLT_HIDmesonHITrackingGlobal_Dpt40_Cent30_100_v1);
   fChain->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt40_Cent30_100_v1_Prescl", &HLT_HIDmesonHITrackingGlobal_Dpt40_Cent30_100_v1_Prescl, &b_HLT_HIDmesonHITrackingGlobal_Dpt40_Cent30_100_v1_Prescl);
   fChain->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt40_Cent50_100_v1", &HLT_HIDmesonHITrackingGlobal_Dpt40_Cent50_100_v1, &b_HLT_HIDmesonHITrackingGlobal_Dpt40_Cent50_100_v1);
   fChain->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt40_Cent50_100_v1_Prescl", &HLT_HIDmesonHITrackingGlobal_Dpt40_Cent50_100_v1_Prescl, &b_HLT_HIDmesonHITrackingGlobal_Dpt40_Cent50_100_v1_Prescl);
   fChain->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt50_v1", &HLT_HIDmesonHITrackingGlobal_Dpt50_v1, &b_HLT_HIDmesonHITrackingGlobal_Dpt50_v1);
   fChain->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt50_v1_Prescl", &HLT_HIDmesonHITrackingGlobal_Dpt50_v1_Prescl, &b_HLT_HIDmesonHITrackingGlobal_Dpt50_v1_Prescl);
   fChain->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt60_v1", &HLT_HIDmesonHITrackingGlobal_Dpt60_v1, &b_HLT_HIDmesonHITrackingGlobal_Dpt60_v1);
   fChain->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt60_v1_Prescl", &HLT_HIDmesonHITrackingGlobal_Dpt60_v1_Prescl, &b_HLT_HIDmesonHITrackingGlobal_Dpt60_v1_Prescl);
   fChain->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt70_v1", &HLT_HIDmesonHITrackingGlobal_Dpt70_v1, &b_HLT_HIDmesonHITrackingGlobal_Dpt70_v1);
   fChain->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt70_v1_Prescl", &HLT_HIDmesonHITrackingGlobal_Dpt70_v1_Prescl, &b_HLT_HIDmesonHITrackingGlobal_Dpt70_v1_Prescl);
   fChain->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt60_Cent30_100_v1", &HLT_HIDmesonHITrackingGlobal_Dpt60_Cent30_100_v1, &b_HLT_HIDmesonHITrackingGlobal_Dpt60_Cent30_100_v1);
   fChain->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt60_Cent30_100_v1_Prescl", &HLT_HIDmesonHITrackingGlobal_Dpt60_Cent30_100_v1_Prescl, &b_HLT_HIDmesonHITrackingGlobal_Dpt60_Cent30_100_v1_Prescl);
   fChain->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt60_Cent50_100_v1", &HLT_HIDmesonHITrackingGlobal_Dpt60_Cent50_100_v1, &b_HLT_HIDmesonHITrackingGlobal_Dpt60_Cent50_100_v1);
   fChain->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt60_Cent50_100_v1_Prescl", &HLT_HIDmesonHITrackingGlobal_Dpt60_Cent50_100_v1_Prescl, &b_HLT_HIDmesonHITrackingGlobal_Dpt60_Cent50_100_v1_Prescl);
   fChain->SetBranchAddress("HLT_HIL1MinimumBiasHF1OR_v1", &HLT_HIL1MinimumBiasHF1OR_v1, &b_HLT_HIL1MinimumBiasHF1OR_v1);
   fChain->SetBranchAddress("HLT_HIL1MinimumBiasHF1OR_v1_Prescl", &HLT_HIL1MinimumBiasHF1OR_v1_Prescl, &b_HLT_HIL1MinimumBiasHF1OR_v1_Prescl);
   fChain->SetBranchAddress("HLT_HIL1MinimumBiasHF2OR_v1", &HLT_HIL1MinimumBiasHF2OR_v1, &b_HLT_HIL1MinimumBiasHF2OR_v1);
   fChain->SetBranchAddress("HLT_HIL1MinimumBiasHF2OR_v1_Prescl", &HLT_HIL1MinimumBiasHF2OR_v1_Prescl, &b_HLT_HIL1MinimumBiasHF2OR_v1_Prescl);
   fChain->SetBranchAddress("HLT_HIL1MinimumBiasHF1AND_v1", &HLT_HIL1MinimumBiasHF1AND_v1, &b_HLT_HIL1MinimumBiasHF1AND_v1);
   fChain->SetBranchAddress("HLT_HIL1MinimumBiasHF1AND_v1_Prescl", &HLT_HIL1MinimumBiasHF1AND_v1_Prescl, &b_HLT_HIL1MinimumBiasHF1AND_v1_Prescl);
   fChain->SetBranchAddress("HLT_HIL1MinimumBiasHF1ANDExpress_v1", &HLT_HIL1MinimumBiasHF1ANDExpress_v1, &b_HLT_HIL1MinimumBiasHF1ANDExpress_v1);
   fChain->SetBranchAddress("HLT_HIL1MinimumBiasHF1ANDExpress_v1_Prescl", &HLT_HIL1MinimumBiasHF1ANDExpress_v1_Prescl, &b_HLT_HIL1MinimumBiasHF1ANDExpress_v1_Prescl);
   fChain->SetBranchAddress("HLT_HIL1MinimumBiasHF2AND_v1", &HLT_HIL1MinimumBiasHF2AND_v1, &b_HLT_HIL1MinimumBiasHF2AND_v1);
   fChain->SetBranchAddress("HLT_HIL1MinimumBiasHF2AND_v1_Prescl", &HLT_HIL1MinimumBiasHF2AND_v1_Prescl, &b_HLT_HIL1MinimumBiasHF2AND_v1_Prescl);

   fChain->SetBranchAddress("HLT_HIL1MinimumBiasHF2ANDExpress_v1", &HLT_HIL1MinimumBiasHF2ANDExpress_v1, &b_HLT_HIL1MinimumBiasHF2ANDExpress_v1);
   fChain->SetBranchAddress("HLT_HIL1MinimumBiasHF2ANDExpress_v1_Prescl", &HLT_HIL1MinimumBiasHF2ANDExpress_v1_Prescl, &b_HLT_HIL1MinimumBiasHF2ANDExpress_v1_Prescl);
   fChain->SetBranchAddress("HLT_HIL1MinimumBiasHF1ANDPixel_SingleTrack_v1", &HLT_HIL1MinimumBiasHF1ANDPixel_SingleTrack_v1, &b_HLT_HIL1MinimumBiasHF1ANDPixel_SingleTrack_v1);
   fChain->SetBranchAddress("HLT_HIL1MinimumBiasHF1ANDPixel_SingleTrack_v1_Prescl", &HLT_HIL1MinimumBiasHF1ANDPixel_SingleTrack_v1_Prescl, &b_HLT_HIL1MinimumBiasHF1ANDPixel_SingleTrack_v1_Prescl);
   fChain->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt20_v2", &HLT_HIDmesonHITrackingGlobal_Dpt20_v2, &b_HLT_HIDmesonHITrackingGlobal_Dpt20_v2);
   fChain->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt20_v2_Prescl", &HLT_HIDmesonHITrackingGlobal_Dpt20_v2_Prescl, &b_HLT_HIDmesonHITrackingGlobal_Dpt20_v2_Prescl);
   fChain->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt20_Cent0_10_v1", &HLT_HIDmesonHITrackingGlobal_Dpt20_Cent0_10_v1, &b_HLT_HIDmesonHITrackingGlobal_Dpt20_Cent0_10_v1);
   fChain->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt20_Cent0_10_v1_Prescl", &HLT_HIDmesonHITrackingGlobal_Dpt20_Cent0_10_v1_Prescl, &b_HLT_HIDmesonHITrackingGlobal_Dpt20_Cent0_10_v1_Prescl);
   fChain->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt20_Cent30_100_v1", &HLT_HIDmesonHITrackingGlobal_Dpt20_Cent30_100_v1, &b_HLT_HIDmesonHITrackingGlobal_Dpt20_Cent30_100_v1);
   fChain->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt20_Cent30_100_v1_Prescl", &HLT_HIDmesonHITrackingGlobal_Dpt20_Cent30_100_v1_Prescl, &b_HLT_HIDmesonHITrackingGlobal_Dpt20_Cent30_100_v1_Prescl);
   fChain->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt20_Cent30_100_v3", &HLT_HIDmesonHITrackingGlobal_Dpt20_Cent30_100_v3, &b_HLT_HIDmesonHITrackingGlobal_Dpt20_Cent30_100_v3);
   fChain->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt20_Cent30_100_v3_Prescl", &HLT_HIDmesonHITrackingGlobal_Dpt20_Cent30_100_v3_Prescl, &b_HLT_HIDmesonHITrackingGlobal_Dpt20_Cent30_100_v3_Prescl);
   fChain->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt20_Cent50_100_v1", &HLT_HIDmesonHITrackingGlobal_Dpt20_Cent50_100_v1, &b_HLT_HIDmesonHITrackingGlobal_Dpt20_Cent50_100_v1);
   fChain->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt20_Cent50_100_v1_Prescl", &HLT_HIDmesonHITrackingGlobal_Dpt20_Cent50_100_v1_Prescl, &b_HLT_HIDmesonHITrackingGlobal_Dpt20_Cent50_100_v1_Prescl);
   fChain->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt20_Cent50_100_v3", &HLT_HIDmesonHITrackingGlobal_Dpt20_Cent50_100_v3, &b_HLT_HIDmesonHITrackingGlobal_Dpt20_Cent50_100_v3);
   fChain->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt20_Cent50_100_v3_Prescl", &HLT_HIDmesonHITrackingGlobal_Dpt20_Cent50_100_v3_Prescl, &b_HLT_HIDmesonHITrackingGlobal_Dpt20_Cent50_100_v3_Prescl);
   fChain->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt30_Cent0_10_v1", &HLT_HIDmesonHITrackingGlobal_Dpt30_Cent0_10_v1, &b_HLT_HIDmesonHITrackingGlobal_Dpt30_Cent0_10_v1);
   fChain->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt30_Cent0_10_v1_Prescl", &HLT_HIDmesonHITrackingGlobal_Dpt30_Cent0_10_v1_Prescl, &b_HLT_HIDmesonHITrackingGlobal_Dpt30_Cent0_10_v1_Prescl);
   fChain->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt40_Cent0_10_v1", &HLT_HIDmesonHITrackingGlobal_Dpt40_Cent0_10_v1, &b_HLT_HIDmesonHITrackingGlobal_Dpt40_Cent0_10_v1);
   fChain->SetBranchAddress("HLT_HIDmesonHITrackingGlobal_Dpt40_Cent0_10_v1_Prescl", &HLT_HIDmesonHITrackingGlobal_Dpt40_Cent0_10_v1_Prescl, &b_HLT_HIDmesonHITrackingGlobal_Dpt40_Cent0_10_v1_Prescl);
   fChain->SetBranchAddress("HLT_HIL1MinimumBiasHF2AND_part1_v1", &HLT_HIL1MinimumBiasHF2AND_part1_v1, &b_HLT_HIL1MinimumBiasHF2AND_part1_v1);
   fChain->SetBranchAddress("HLT_HIL1MinimumBiasHF2AND_part1_v1_Prescl", &HLT_HIL1MinimumBiasHF2AND_part1_v1_Prescl, &b_HLT_HIL1MinimumBiasHF2AND_part1_v1_Prescl);
   fChain->SetBranchAddress("HLT_HIL1MinimumBiasHF2AND_part2_v1", &HLT_HIL1MinimumBiasHF2AND_part2_v1, &b_HLT_HIL1MinimumBiasHF2AND_part2_v1);
   fChain->SetBranchAddress("HLT_HIL1MinimumBiasHF2AND_part2_v1_Prescl", &HLT_HIL1MinimumBiasHF2AND_part2_v1_Prescl, &b_HLT_HIL1MinimumBiasHF2AND_part2_v1_Prescl);
   fChain->SetBranchAddress("HLT_HIL1MinimumBiasHF2AND_part3_v1", &HLT_HIL1MinimumBiasHF2AND_part3_v1, &b_HLT_HIL1MinimumBiasHF2AND_part3_v1);
   fChain->SetBranchAddress("HLT_HIL1MinimumBiasHF2AND_part3_v1_Prescl", &HLT_HIL1MinimumBiasHF2AND_part3_v1_Prescl, &b_HLT_HIL1MinimumBiasHF2AND_part3_v1_Prescl);
   fChain->SetBranchAddress("HLT_HIL1MinimumBiasHF2AND_part4_v1", &HLT_HIL1MinimumBiasHF2AND_part4_v1, &b_HLT_HIL1MinimumBiasHF2AND_part4_v1);
   fChain->SetBranchAddress("HLT_HIL1MinimumBiasHF2AND_part4_v1_Prescl", &HLT_HIL1MinimumBiasHF2AND_part4_v1_Prescl, &b_HLT_HIL1MinimumBiasHF2AND_part4_v1_Prescl);
   fChain->SetBranchAddress("HLT_HIL1MinimumBiasHF2AND_part5_v1", &HLT_HIL1MinimumBiasHF2AND_part5_v1, &b_HLT_HIL1MinimumBiasHF2AND_part5_v1);
   fChain->SetBranchAddress("HLT_HIL1MinimumBiasHF2AND_part5_v1_Prescl", &HLT_HIL1MinimumBiasHF2AND_part5_v1_Prescl, &b_HLT_HIL1MinimumBiasHF2AND_part5_v1_Prescl);
   fChain->SetBranchAddress("HLT_HIL1MinimumBiasHF2AND_part6_v1", &HLT_HIL1MinimumBiasHF2AND_part6_v1, &b_HLT_HIL1MinimumBiasHF2AND_part6_v1);
   fChain->SetBranchAddress("HLT_HIL1MinimumBiasHF2AND_part6_v1_Prescl", &HLT_HIL1MinimumBiasHF2AND_part6_v1_Prescl, &b_HLT_HIL1MinimumBiasHF2AND_part6_v1_Prescl);
   fChain->SetBranchAddress("HLT_HIL1MinimumBiasHF2AND_part7_v1", &HLT_HIL1MinimumBiasHF2AND_part7_v1, &b_HLT_HIL1MinimumBiasHF2AND_part7_v1);
   fChain->SetBranchAddress("HLT_HIL1MinimumBiasHF2AND_part7_v1_Prescl", &HLT_HIL1MinimumBiasHF2AND_part7_v1_Prescl, &b_HLT_HIL1MinimumBiasHF2AND_part7_v1_Prescl);
   fChain->SetBranchAddress("HLT_HIL1MinimumBiasHF2AND_part8_v1", &HLT_HIL1MinimumBiasHF2AND_part8_v1, &b_HLT_HIL1MinimumBiasHF2AND_part8_v1);
   fChain->SetBranchAddress("HLT_HIL1MinimumBiasHF2AND_part8_v1_Prescl", &HLT_HIL1MinimumBiasHF2AND_part8_v1_Prescl, &b_HLT_HIL1MinimumBiasHF2AND_part8_v1_Prescl);
   fChain->SetBranchAddress("HLT_HIL1MinimumBiasHF2AND_part9_v1", &HLT_HIL1MinimumBiasHF2AND_part9_v1, &b_HLT_HIL1MinimumBiasHF2AND_part9_v1);
   fChain->SetBranchAddress("HLT_HIL1MinimumBiasHF2AND_part9_v1_Prescl", &HLT_HIL1MinimumBiasHF2AND_part9_v1_Prescl, &b_HLT_HIL1MinimumBiasHF2AND_part9_v1_Prescl);
   fChain->SetBranchAddress("HLT_HIL1MinimumBiasHF2AND_part10_v1", &HLT_HIL1MinimumBiasHF2AND_part10_v1, &b_HLT_HIL1MinimumBiasHF2AND_part10_v1);
   fChain->SetBranchAddress("HLT_HIL1MinimumBiasHF2AND_part10_v1_Prescl", &HLT_HIL1MinimumBiasHF2AND_part10_v1_Prescl, &b_HLT_HIL1MinimumBiasHF2AND_part10_v1_Prescl);
   fChain->SetBranchAddress("HLT_HIL1MinimumBiasHF2AND_part11_v1", &HLT_HIL1MinimumBiasHF2AND_part11_v1, &b_HLT_HIL1MinimumBiasHF2AND_part11_v1);
   fChain->SetBranchAddress("HLT_HIL1MinimumBiasHF2AND_part11_v1_Prescl", &HLT_HIL1MinimumBiasHF2AND_part11_v1_Prescl, &b_HLT_HIL1MinimumBiasHF2AND_part11_v1_Prescl);
   fChain->SetBranchAddress("HLT_HIL1MinimumBiasHF2ANDPixel_SingleTrack_v1", &HLT_HIL1MinimumBiasHF2ANDPixel_SingleTrack_v1, &b_HLT_HIL1MinimumBiasHF2ANDPixel_SingleTrack_v1);
   fChain->SetBranchAddress("HLT_HIL1MinimumBiasHF2ANDPixel_SingleTrack_v1_Prescl", &HLT_HIL1MinimumBiasHF2ANDPixel_SingleTrack_v1_Prescl, &b_HLT_HIL1MinimumBiasHF2ANDPixel_SingleTrack_v1_Prescl);


//


   fChain->SetBranchAddress("RunNo", &RunNo, &b_RunNo);
   fChain->SetBranchAddress("EvtNo", &EvtNo, &b_EvtNo);
   fChain->SetBranchAddress("LumiNo", &LumiNo, &b_LumiNo);
   fChain->SetBranchAddress("Dsize", &Dsize, &b_Dsize);
   fChain->SetBranchAddress("PVx", &PVx, &b_PVx);
   fChain->SetBranchAddress("PVy", &PVy, &b_PVy);
   fChain->SetBranchAddress("PVz", &PVz, &b_PVz);
   fChain->SetBranchAddress("PVxE", &PVxE, &b_PVxE);
   fChain->SetBranchAddress("PVyE", &PVyE, &b_PVyE);
   fChain->SetBranchAddress("PVzE", &PVzE, &b_PVzE);
   fChain->SetBranchAddress("PVnchi2", &PVnchi2, &b_PVnchi2);
   fChain->SetBranchAddress("BSx", &BSx, &b_BSx);
   fChain->SetBranchAddress("BSy", &BSy, &b_BSy);
   fChain->SetBranchAddress("BSz", &BSz, &b_BSz);
   fChain->SetBranchAddress("BSxErr", &BSxErr, &b_BSxErr);
   fChain->SetBranchAddress("BSyErr", &BSyErr, &b_BSyErr);
   fChain->SetBranchAddress("BSzErr", &BSzErr, &b_BSzErr);
   fChain->SetBranchAddress("BSdxdz", &BSdxdz, &b_BSdxdz);
   fChain->SetBranchAddress("BSdydz", &BSdydz, &b_BSdydz);
   fChain->SetBranchAddress("BSdxdzErr", &BSdxdzErr, &b_BSdxdzErr);
   fChain->SetBranchAddress("BSdydzErr", &BSdydzErr, &b_BSdydzErr);
   fChain->SetBranchAddress("BSWidthX", &BSWidthX, &b_BSWidthX);
   fChain->SetBranchAddress("BSWidthXErr", &BSWidthXErr, &b_BSWidthXErr);
   fChain->SetBranchAddress("BSWidthY", &BSWidthY, &b_BSWidthY);
   fChain->SetBranchAddress("BSWidthYErr", &BSWidthYErr, &b_BSWidthYErr);
   fChain->SetBranchAddress("Dindex", Dindex, &b_Dindex);
   fChain->SetBranchAddress("Dtype", Dtype, &b_Dtype);
   fChain->SetBranchAddress("Dmass", Dmass, &b_Dmass);
   fChain->SetBranchAddress("Dpt", Dpt, &b_Dpt);
   fChain->SetBranchAddress("Deta", Deta, &b_Deta);
   fChain->SetBranchAddress("Dphi", Dphi, &b_Dphi);
   fChain->SetBranchAddress("Dy", Dy, &b_Dy);
   fChain->SetBranchAddress("DvtxX", DvtxX, &b_DvtxX);
   fChain->SetBranchAddress("DvtxY", DvtxY, &b_DvtxY);
   fChain->SetBranchAddress("Dd0", Dd0, &b_Dd0);
   fChain->SetBranchAddress("Dd0Err", Dd0Err, &b_Dd0Err);
   fChain->SetBranchAddress("Ddxyz", Ddxyz, &b_Ddxyz);
   fChain->SetBranchAddress("DdxyzErr", DdxyzErr, &b_DdxyzErr);
   fChain->SetBranchAddress("Dchi2ndf", Dchi2ndf, &b_Dchi2ndf);
   fChain->SetBranchAddress("Dchi2cl", Dchi2cl, &b_Dchi2cl);
   fChain->SetBranchAddress("Ddtheta", Ddtheta, &b_Ddtheta);
   fChain->SetBranchAddress("Dlxy", Dlxy, &b_Dlxy);
   fChain->SetBranchAddress("Dalpha", Dalpha, &b_Dalpha);
   fChain->SetBranchAddress("DsvpvDistance", DsvpvDistance, &b_DsvpvDistance);
   fChain->SetBranchAddress("DsvpvDisErr", DsvpvDisErr, &b_DsvpvDisErr);
   fChain->SetBranchAddress("DsvpvDistance_2D", DsvpvDistance_2D, &b_DsvpvDistance_2D);
   fChain->SetBranchAddress("DsvpvDisErr_2D", DsvpvDisErr_2D, &b_DsvpvDisErr_2D);
   fChain->SetBranchAddress("DlxyBS", DlxyBS, &b_DlxyBS);
   fChain->SetBranchAddress("DlxyBSErr", DlxyBSErr, &b_DlxyBSErr);
   fChain->SetBranchAddress("DMaxDoca", DMaxDoca, &b_DMaxDoca);
   fChain->SetBranchAddress("Dtrk1Idx", Dtrk1Idx, &b_Dtrk1Idx);
   fChain->SetBranchAddress("Dtrk2Idx", Dtrk2Idx, &b_Dtrk2Idx);
   fChain->SetBranchAddress("Dtrk1Pt", Dtrk1Pt, &b_Dtrk1Pt);
   fChain->SetBranchAddress("Dtrk2Pt", Dtrk2Pt, &b_Dtrk2Pt);
   fChain->SetBranchAddress("Dtrk1Eta", Dtrk1Eta, &b_Dtrk1Eta);
   fChain->SetBranchAddress("Dtrk2Eta", Dtrk2Eta, &b_Dtrk2Eta);
   fChain->SetBranchAddress("Dtrk1Phi", Dtrk1Phi, &b_Dtrk1Phi);
   fChain->SetBranchAddress("Dtrk2Phi", Dtrk2Phi, &b_Dtrk2Phi);
   fChain->SetBranchAddress("Dtrk1PtErr", Dtrk1PtErr, &b_Dtrk1PtErr);
   fChain->SetBranchAddress("Dtrk2PtErr", Dtrk2PtErr, &b_Dtrk2PtErr);
   fChain->SetBranchAddress("Dtrk1EtaErr", Dtrk1EtaErr, &b_Dtrk1EtaErr);
   fChain->SetBranchAddress("Dtrk2EtaErr", Dtrk2EtaErr, &b_Dtrk2EtaErr);
   fChain->SetBranchAddress("Dtrk1PhiErr", Dtrk1PhiErr, &b_Dtrk1PhiErr);
   fChain->SetBranchAddress("Dtrk2PhiErr", Dtrk2PhiErr, &b_Dtrk2PhiErr);
   fChain->SetBranchAddress("Dtrk1Y", Dtrk1Y, &b_Dtrk1Y);
   fChain->SetBranchAddress("Dtrk2Y", Dtrk2Y, &b_Dtrk2Y);
   fChain->SetBranchAddress("Dtrk1Dxy", Dtrk1Dxy, &b_Dtrk1Dxy);
   fChain->SetBranchAddress("Dtrk2Dxy", Dtrk2Dxy, &b_Dtrk2Dxy);
   fChain->SetBranchAddress("Dtrk1D0Err", Dtrk1D0Err, &b_Dtrk1D0Err);
   fChain->SetBranchAddress("Dtrk2D0Err", Dtrk2D0Err, &b_Dtrk2D0Err);
   fChain->SetBranchAddress("Dtrk1PixelHit", Dtrk1PixelHit, &b_Dtrk1PixelHit);
   fChain->SetBranchAddress("Dtrk2PixelHit", Dtrk2PixelHit, &b_Dtrk2PixelHit);
   fChain->SetBranchAddress("Dtrk1StripHit", Dtrk1StripHit, &b_Dtrk1StripHit);
   fChain->SetBranchAddress("Dtrk2StripHit", Dtrk2StripHit, &b_Dtrk2StripHit);
   fChain->SetBranchAddress("Dtrk1nStripLayer", Dtrk1nStripLayer, &b_Dtrk1nStripLayer);
   fChain->SetBranchAddress("Dtrk2nStripLayer", Dtrk2nStripLayer, &b_Dtrk2nStripLayer);
   fChain->SetBranchAddress("Dtrk1nPixelLayer", Dtrk1nPixelLayer, &b_Dtrk1nPixelLayer);
   fChain->SetBranchAddress("Dtrk2nPixelLayer", Dtrk2nPixelLayer, &b_Dtrk2nPixelLayer);
   fChain->SetBranchAddress("Dtrk1Chi2ndf", Dtrk1Chi2ndf, &b_Dtrk1Chi2ndf);
   fChain->SetBranchAddress("Dtrk2Chi2ndf", Dtrk2Chi2ndf, &b_Dtrk2Chi2ndf);
   fChain->SetBranchAddress("Dtrk1MassHypo", Dtrk1MassHypo, &b_Dtrk1MassHypo);
   fChain->SetBranchAddress("Dtrk2MassHypo", Dtrk2MassHypo, &b_Dtrk2MassHypo);
   fChain->SetBranchAddress("Dtrk1MVAVal", Dtrk1MVAVal, &b_Dtrk1MVAVal);
   fChain->SetBranchAddress("Dtrk2MVAVal", Dtrk2MVAVal, &b_Dtrk2MVAVal);
   fChain->SetBranchAddress("Dtrk1Algo", Dtrk1Algo, &b_Dtrk1Algo);
   fChain->SetBranchAddress("Dtrk2Algo", Dtrk2Algo, &b_Dtrk2Algo);
   fChain->SetBranchAddress("Dtrk1OriginalAlgo", Dtrk1OriginalAlgo, &b_Dtrk1OriginalAlgo);
   fChain->SetBranchAddress("Dtrk2OriginalAlgo", Dtrk2OriginalAlgo, &b_Dtrk2OriginalAlgo);
   fChain->SetBranchAddress("Dtrk1highPurity", Dtrk1highPurity, &b_Dtrk1highPurity);
   fChain->SetBranchAddress("Dtrk2highPurity", Dtrk2highPurity, &b_Dtrk2highPurity);
   fChain->SetBranchAddress("Dtrk1Quality", Dtrk1Quality, &b_Dtrk1Quality);
   fChain->SetBranchAddress("Dtrk2Quality", Dtrk2Quality, &b_Dtrk2Quality);
   fChain->SetBranchAddress("Dgen", Dgen, &b_Dgen);
   fChain->SetBranchAddress("DgenIndex", DgenIndex, &b_DgenIndex);
   fChain->SetBranchAddress("DgennDa", DgennDa, &b_DgennDa);
   fChain->SetBranchAddress("Dgenpt", Dgenpt, &b_Dgenpt);
   fChain->SetBranchAddress("Dgeneta", Dgeneta, &b_Dgeneta);
   fChain->SetBranchAddress("Dgenphi", Dgenphi, &b_Dgenphi);
   fChain->SetBranchAddress("Dgeny", Dgeny, &b_Dgeny);



// Outputfile

  TFile* fout = new TFile("bFeedDownPbPb.tree.root","recreate");
  TTree *Dtree = new TTree("Dtree","Dtree");

  TH1F *h_D0Dca_2d = new TH1F("h_D0Dca_2d","h_D0Dca_2d",200,-0.1,0.1);

  Float_t  PVx_out;
  Float_t  PVy_out;
  Float_t  PVz_out;
  Float_t  pthatweight_out;
  Float_t  Dmass_out;
  Float_t  Dpt_out;
  Float_t  Deta_out;
  Float_t  Dphi_out;
  Float_t  Dy_out;
  Float_t  DvtxX_out;
  Float_t  DvtxY_out;
  Float_t  Dalpha_out;
  Float_t  Dalpha_2D_out;
  Float_t  D0DCA_out;
  Float_t  D0DCA_2D_out;
  Float_t  D0DCA_2Dabs_out;
  Float_t  D0DCA_2Dv1_out;
  Float_t  D0DCA_2Dv2_out;
  Float_t  DgenBpt_out;
  Float_t  DsvpvDistance_2D_out;
  Float_t  DsvpvDistance_2Dv1_out;
  Float_t  DsvpvDisErr_2D_out;
  Float_t  DsvpvDistance_out;
  Float_t  DsvpvDisErr_out;

  Dtree->Branch("Dpt",&Dpt_out,"Dpt/F");
  Dtree->Branch("Dphi",&Dphi_out,"Dphi/F");
  Dtree->Branch("Dmass",&Dmass_out,"Dmass/F");
  Dtree->Branch("Dalpha",&Dalpha_out,"Dalpha/F");
  Dtree->Branch("Dalpha_2D",&Dalpha_2D_out,"Dalpha_2D/F");
  Dtree->Branch("D0DCA",&D0DCA_out,"D0DCA/F");
  Dtree->Branch("D0DCA_2D",&D0DCA_2D_out,"DODCA_2D/F");
  Dtree->Branch("D0DCA_2Dabs",&D0DCA_2Dabs_out,"DODCA_2Dabs/F");
  Dtree->Branch("D0DCA_2Dv1",&D0DCA_2Dv1_out,"DODCA_2Dv1/F");
  Dtree->Branch("D0DCA_2Dv2",&D0DCA_2Dv2_out,"DODCA_2Dv2/F");
  Dtree->Branch("DsvpvDistance",&DsvpvDistance_out,"DsvpvDistance/F");
  Dtree->Branch("DsvpvDistance_2D",&DsvpvDistance_2D_out,"DsvpvDistance_2D/F");
  Dtree->Branch("DsvpvDistance_2Dv1",&DsvpvDistance_2Dv1_out,"DsvpvDistance_2Dv1/F");
  Dtree->Branch("pthatweight",&pthatweight_out,"pthatweight/F");



// readEntries.

  Long64_t nentries;

  nentries=tMCP->GetEntries();

  cout<<"nentries ="<<nentries;



   for(int ientries=0; ientries<nentries; ientries++){
//     for(int ientries=0; ientries<50000; ientries++){
      tMCP->GetEntry(ientries);
     for(int iDsize=0; iDsize<Dsize; iDsize++){
        if( ((cutPbPb == 1 && cutpt ==1) || (cutPbPbMB==1 && cutptMB==1)) && cutmc==1 && cutSignal ==1 && cutPrompt ==1){
//        if(  (cutPbPbMB==1 && cutptMB==1) && cutmc==1 && cutSignal ==1 && cutPrompt ==1){

        Dpt_out=Dpt[iDsize];
        Dphi_out=Dphi[iDsize];
        Dmass_out=Dmass[iDsize];
        Dalpha_out=Dalpha[iDsize];
        DsvpvDistance_out=DsvpvDistance[iDsize];
        DsvpvDistance_2D_out=DsvpvDistance_2D[iDsize];
        D0DCA_out=DsvpvDistance[iDsize]*TMath::Sin(Dalpha[iDsize]);

        TVector3 v_Dpt(Dpt_out*TMath::Cos(Dphi_out),Dpt_out*TMath::Sin(Dphi_out),0);
//        TVector3 v_Ddecay(DvtxX[iDsize]-PVx,DvtxY[iDsize]-PVy,0);
        TVector3 v_Ddecay(DvtxX[iDsize],DvtxY[iDsize],0);
        // Float_t alpha_2d=v_Dpt.Angle(v_Ddecay);
        Float_t alpha_2d=v_Dpt.Phi()-v_Ddecay.Phi();
//        if(alpha_2d > TMath::Pi() ) alpha_2d=TMath::Pi()-alpha_2d;
//        if(alpha_2d < TMath::Pi() ) alpha_2d=alpha_2d+TMath::Pi();

        Dalpha_2D_out= alpha_2d;

        DsvpvDistance_2Dv1_out=v_Ddecay.Mag();
        D0DCA_2D_out=DsvpvDistance_2D_out*TMath::Sin(alpha_2d);
        D0DCA_2Dabs_out=fabs(D0DCA_2D_out);
        D0DCA_2Dv1_out=DsvpvDistance_2Dv1_out*TMath::Sin(alpha_2d);
//        D0DCA_2Dv2_out=(DvtxX[iDsize]-PVx)*TMath::Sin(Dphi_out)-(DvtxY[iDsize]-PVy)*TMath::Cos(Dphi_out);
        D0DCA_2Dv2_out=(DvtxX[iDsize])*TMath::Sin(Dphi_out)-(DvtxY[iDsize])*TMath::Cos(Dphi_out);


        Dtree->Fill();

        h_D0Dca_2d->Fill(D0DCA_2Dv1_out,pthatweight);


      } // end if signal selection
    }// end for Dsize




	} // end for ientries


  fout->cd();
  Dtree->Write();
  h_D0Dca_2d->Write();





} // end main
