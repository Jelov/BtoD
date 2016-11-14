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

void readMCNP(){

  TFile* infMCNP = new TFile("/data/HeavyFlavourRun2/MC2015/Dntuple/PbPb/ntD_EvtBase_20160513_DfinderMC_PbPb_20160502_dPt1tkPt0p5_D0_nonprompt_Dpt2Dy1p1tkPt0p7tkEta2Decay2p9Dalpha0p14Skim_pthatweight.root");


	TTree* tMCNP = (TTree*)infMCNP->Get("ntDkpi");
  TTree* tMCNPHI = (TTree*)infMCNP->Get("ntHi");
  TTree* tMCNPSkim = (TTree*)infMCNP->Get("ntSkim");

  cout<<"check 1"<<endl;


  tMCNP->AddFriend(tMCNPHI);
  tMCNP->AddFriend(tMCNPSkim);

  cout<<"check 2"<<endl;

	int maxDsize=99;

	// ntSkim leaf
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



	// ntHi leaf

   UInt_t          run;
   ULong64_t       evt;
   UInt_t          lumi;
   Float_t         vx;
   Float_t         vy;
   Float_t         vz;
   Float_t         Npart;
   Float_t         Ncoll;
   Float_t         Nhard;
   Float_t         phi0;
   Float_t         b;
   Int_t           Ncharged;
   Int_t           NchargedMR;
   Float_t         MeanPt;
   Float_t         MeanPtMR;
   Float_t         EtMR;
   Int_t           NchargedPtCut;
   Int_t           NchargedPtCutMR;
   Int_t           ProcessID;
   Float_t         pthat;
   Float_t         weight;
   Float_t         alphaQCD;
   Float_t         alphaQED;
   Float_t         qScale;
   Int_t           nMEPartons;
   Int_t           nMEPartonsFiltered;
 //pair<int,int>   *pdfID;
//   Int_t           first;
//   Int_t           second;
 //pair<float,float> *pdfX;
//   Float_t         first;
//   Float_t         second;
 //pair<float,float> *pdfXpdf;
//   Float_t         first;
//   Float_t         second;
   vector<float>   *ttbar_w;
   vector<int>     *npus;
   vector<float>   *tnpus;
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
   Float_t         pthatweight;
   Float_t         maxDgenpt;

 //ntDkpi leaf

   Int_t           RunNo;
   Int_t           EvtNo;
   Int_t           LumiNo;
   Int_t           Dsize;
   Float_t         PVx;
   Float_t         PVy;
   Float_t         PVz;
   Float_t         PVnchi2;
   Float_t         BSx;
   Float_t         BSy;
   Float_t         BSz;
   Float_t         PVxE;
   Float_t         PVyE;
   Float_t         PVzE;
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
   Int_t           Dindex[75];   //[Dsize]
   Int_t           Dtype[75];   //[Dsize]
   Float_t         Dmass[75];   //[Dsize]
   Float_t         Dpt[75];   //[Dsize]
   Float_t         Deta[75];   //[Dsize]
   Float_t         Dphi[75];   //[Dsize]
   Float_t         Dy[75];   //[Dsize]
   Float_t         DvtxX[75];   //[Dsize]
   Float_t         DvtxY[75];   //[Dsize]
   Float_t         Dd0[75];   //[Dsize]
   Float_t         Dd0Err[75];   //[Dsize]
   Float_t         Ddxyz[75];   //[Dsize]
   Float_t         DdxyzErr[75];   //[Dsize]
   Float_t         Dchi2ndf[75];   //[Dsize]
   Float_t         Dchi2cl[75];   //[Dsize]
   Float_t         Ddtheta[75];   //[Dsize]
   Float_t         Dlxy[75];   //[Dsize]
   Float_t         Dalpha[75];   //[Dsize]
   Float_t         DsvpvDistance[75];   //[Dsize]
   Float_t         DsvpvDisErr[75];   //[Dsize]
   Float_t         DsvpvDistance_2D[75];   //[Dsize]
   Float_t         DsvpvDisErr_2D[75];   //[Dsize]
   Float_t         DtktkRes_chi2ndf[75];   //[Dsize]
   Float_t         DtktkRes_chi2cl[75];   //[Dsize]
   Float_t         DtktkRes_alpha[75];   //[Dsize]
   Float_t         DtktkRes_svpvDistance[75];   //[Dsize]

   Float_t         DtktkRes_svpvDisErr[75];   //[Dsize]
   Float_t         DlxyBS[75];   //[Dsize]
   Float_t         DlxyBSErr[75];   //[Dsize]
   Float_t         DMaxDoca[75];   //[Dsize]
   Float_t         Dtrk1Pt[75];   //[Dsize]
   Float_t         Dtrk2Pt[75];   //[Dsize]
   Float_t         Dtrk1Eta[75];   //[Dsize]
   Float_t         Dtrk2Eta[75];   //[Dsize]
   Float_t         Dtrk1Phi[75];   //[Dsize]
   Float_t         Dtrk2Phi[75];   //[Dsize]
   Float_t         Dtrk1PtErr[75];   //[Dsize]
   Float_t         Dtrk2PtErr[75];   //[Dsize]
   Float_t         Dtrk1Dxy[75];   //[Dsize]
   Float_t         Dtrk2Dxy[75];   //[Dsize]
   Float_t         Dtrk1PixelHit[75];   //[Dsize]
   Float_t         Dtrk2PixelHit[75];   //[Dsize]
   Float_t         Dtrk1StripHit[75];   //[Dsize]
   Float_t         Dtrk2StripHit[75];   //[Dsize]
   Float_t         Dtrk1nStripLayer[75];   //[Dsize]
   Float_t         Dtrk2nStripLayer[75];   //[Dsize]
   Float_t         Dtrk1nPixelLayer[75];   //[Dsize]
   Float_t         Dtrk2nPixelLayer[75];   //[Dsize]
   Float_t         Dtrk1Chi2ndf[75];   //[Dsize]
   Float_t         Dtrk2Chi2ndf[75];   //[Dsize]
   Float_t         Dtrk1MassHypo[75];   //[Dsize]
   Float_t         Dtrk2MassHypo[75];   //[Dsize]
   Int_t           Dtrk1Algo[75];   //[Dsize]
   Int_t           Dtrk2Algo[75];   //[Dsize]
   Int_t           Dtrk1originalAlgo[75];   //[Dsize]
   Int_t           Dtrk2originalAlgo[75];   //[Dsize]
   Bool_t          Dtrk1highPurity[75];   //[Dsize]
   Bool_t          Dtrk2highPurity[75];   //[Dsize]
   Int_t           Dtrk1Idx[75];   //[Dsize]
   Int_t           Dtrk2Idx[75];   //[Dsize]
   Float_t         Dtrk1EtaErr[75];   //[Dsize]
   Float_t         Dtrk2EtaErr[75];   //[Dsize]
   Float_t         Dtrk1PhiErr[75];   //[Dsize]
   Float_t         Dtrk2PhiErr[75];   //[Dsize]
   Float_t         Dtrk1Y[75];   //[Dsize]
   Float_t         Dtrk2Y[75];   //[Dsize]
   Float_t         Dtrk1D0Err[75];   //[Dsize]
   Float_t         Dtrk2D0Err[75];   //[Dsize]
   Float_t         Dtrk1MVAVal[75];   //[Dsize]
   Float_t         Dtrk2MVAVal[75];   //[Dsize]
   Int_t           Dtrk1Quality[75];   //[Dsize]
   Int_t           Dtrk2Quality[75];   //[Dsize]
   Float_t         Dgen[75];   //[Dsize]
   Int_t           DgenIndex[75];   //[Dsize]
   Int_t           DgennDa[75];   //[Dsize]
   Float_t         Dgenpt[75];   //[Dsize]
   Float_t         Dgeneta[75];   //[Dsize]
   Float_t         Dgenphi[75];   //[Dsize]
   Float_t         Dgeny[75];   //[Dsize]
   Int_t           DgencollisionId[75];   //[Dsize]
   Float_t         DgenBAncestorpt[75];   //[Dsize]
   Int_t           DgenBAncestorpdgId[75];   //[Dsize]
		
  cout<<"check 3"<<endl;

// Declaration of Branch

// ntSkim Branch

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

// ntHi Branch
   TBranch        *b_run;   //!
   TBranch        *b_evt;   //!
   TBranch        *b_lumi;   //!
   TBranch        *b_vx;   //!
   TBranch        *b_vy;   //!
   TBranch        *b_vz;   //!
   TBranch        *b_Npart;   //!
   TBranch        *b_Ncoll;   //!
   TBranch        *b_Nhard;   //!
   TBranch        *b_NPhi0;   //!
   TBranch        *b_b;   //!
   TBranch        *b_Ncharged;   //!
   TBranch        *b_NchargedMR;   //!
   TBranch        *b_MeanPt;   //!
   TBranch        *b_MeanPtMR;   //!
   TBranch        *b_EtMR;   //!
   TBranch        *b_NchargedPtCut;   //!
   TBranch        *b_NchargedPtCutMR;   //!
   TBranch        *b_ProcessID;   //!
   TBranch        *b_pthat;   //!
   TBranch        *b_weight;   //!
   TBranch        *b_alphaQCD;   //!
   TBranch        *b_alphaQED;   //!
   TBranch        *b_qScale;   //!
   TBranch        *b_nMEPartons;   //!
   TBranch        *b_nMEPartonsFiltered;   //!
//   TBranch        *b_pdfID_first;   //!
//   TBranch        *b_pdfID_second;   //!
//   TBranch        *b_pdfX_first;   //!
//   TBranch        *b_pdfX_second;   //!
//   TBranch        *b_pdfXpdf_first;   //!
//   TBranch        *b_pdfXpdf_second;   //!
   TBranch        *b_ttbar_w;   //!
   TBranch        *b_npus;   //!
   TBranch        *b_tnpus;   //!
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
   TBranch        *b_pthatweight;   //!
   TBranch        *b_maxDgenpt;   //!

  cout<<"check 4"<<endl;


// ntDkpi branch
   TBranch        *b_RunNo;   //!
   TBranch        *b_EvtNo;   //!
   TBranch        *b_LumiNo;   //!
   TBranch        *b_Dsize;   //!
   TBranch        *b_PVx;   //!
   TBranch        *b_PVy;   //!
   TBranch        *b_PVz;   //!
   TBranch        *b_PVnchi2;   //!
   TBranch        *b_BSx;   //!
   TBranch        *b_BSy;   //!
   TBranch        *b_BSz;   //!
   TBranch        *b_PVxE;   //!
   TBranch        *b_PVyE;   //!
   TBranch        *b_PVzE;   //!
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
   TBranch        *b_DtktkRes_chi2ndf;   //!
   TBranch        *b_DtktkRes_chi2cl;   //!
   TBranch        *b_DtktkRes_alpha;   //!
   TBranch        *b_DtktkRes_svpvDistance;   //!
   TBranch        *b_DtktkRes_svpvDisErr;   //!
   TBranch        *b_DlxyBS;   //!
   TBranch        *b_DlxyBSErr;   //!
   TBranch        *b_DMaxDoca;   //!
   TBranch        *b_Dtrk1Pt;   //!
   TBranch        *b_Dtrk2Pt;   //!
   TBranch        *b_Dtrk1Eta;   //!
   TBranch        *b_Dtrk2Eta;   //!
   TBranch        *b_Dtrk1Phi;   //!
   TBranch        *b_Dtrk2Phi;   //!
   TBranch        *b_Dtrk1PtErr;   //!
   TBranch        *b_Dtrk2PtErr;   //!
   TBranch        *b_Dtrk1Dxy;   //!
   TBranch        *b_Dtrk2Dxy;   //!
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
   TBranch        *b_Dtrk1Algo;   //!
   TBranch        *b_Dtrk2Algo;   //!
   TBranch        *b_Dtrk1originalAlgo;   //!
   TBranch        *b_Dtrk2originalAlgo;   //!
   TBranch        *b_Dtrk1highPurity;   //!
   TBranch        *b_Dtrk2highPurity;   //!
   TBranch        *b_Dtrk1Idx;   //!
   TBranch        *b_Dtrk2Idx;   //!
   TBranch        *b_Dtrk1EtaErr;   //!
   TBranch        *b_Dtrk2EtaErr;   //!
   TBranch        *b_Dtrk1PhiErr;   //!
   TBranch        *b_Dtrk2PhiErr;   //!
   TBranch        *b_Dtrk1Y;   //!
   TBranch        *b_Dtrk2Y;   //!
   TBranch        *b_Dtrk1D0Err;   //!
   TBranch        *b_Dtrk2D0Err;   //!
   TBranch        *b_Dtrk1MVAVal;   //!
   TBranch        *b_Dtrk2MVAVal;   //!
   TBranch        *b_Dtrk1Quality;   //!
   TBranch        *b_Dtrk2Quality;   //!
   TBranch        *b_Dgen;   //!
   TBranch        *b_DgenIndex;   //!
   TBranch        *b_DgennDa;   //!
   TBranch        *b_Dgenpt;   //!
   TBranch        *b_Dgeneta;   //!
   TBranch        *b_Dgenphi;   //!
   TBranch        *b_Dgeny;   //!
   TBranch        *b_DgencollisionId;   //!
   TBranch        *b_DgenBAncestorpt;   //!
   TBranch        *b_DgenBAncestorpdgId;   //!

// SetBranchAddress

  cout<<"check 5"<<endl;


// from ntSkim
   tMCNP->SetBranchAddress("centrality_path", &centrality_path, &b_centrality_path);
   tMCNP->SetBranchAddress("evtAna", &evtAna, &b_evtAna);
   tMCNP->SetBranchAddress("hltAna", &hltAna, &b_hltAna);
   tMCNP->SetBranchAddress("pcollisionEventSelection", &pcollisionEventSelection, &b_pcollisionEventSelection);
   tMCNP->SetBranchAddress("pHBHENoiseFilterResultProducer", &pHBHENoiseFilterResultProducer, &b_pHBHENoiseFilterResultProducer);
   tMCNP->SetBranchAddress("HBHENoiseFilterResult", &HBHENoiseFilterResult, &b_HBHENoiseFilterResult);
   tMCNP->SetBranchAddress("HBHENoiseFilterResultRun1", &HBHENoiseFilterResultRun1, &b_HBHENoiseFilterResultRun1);
   tMCNP->SetBranchAddress("HBHENoiseFilterResultRun2Loose", &HBHENoiseFilterResultRun2Loose, &b_HBHENoiseFilterResultRun2Loose);
   tMCNP->SetBranchAddress("HBHENoiseFilterResultRun2Tight", &HBHENoiseFilterResultRun2Tight, &b_HBHENoiseFilterResultRun2Tight);
   tMCNP->SetBranchAddress("HBHEIsoNoiseFilterResult", &HBHEIsoNoiseFilterResult, &b_HBHEIsoNoiseFilterResult);
   tMCNP->SetBranchAddress("pprimaryVertexFilter", &pprimaryVertexFilter, &b_pprimaryVertexFilter);
   tMCNP->SetBranchAddress("phfCoincFilter1", &phfCoincFilter1, &b_phfCoincFilter1);
   tMCNP->SetBranchAddress("phfCoincFilter2", &phfCoincFilter2, &b_phfCoincFilter2);
   tMCNP->SetBranchAddress("phfCoincFilter3", &phfCoincFilter3, &b_phfCoincFilter3);
   tMCNP->SetBranchAddress("phfCoincFilter4", &phfCoincFilter4, &b_phfCoincFilter4);
   tMCNP->SetBranchAddress("phfCoincFilter5", &phfCoincFilter5, &b_phfCoincFilter5);
   tMCNP->SetBranchAddress("pclusterCompatibilityFilter", &pclusterCompatibilityFilter, &b_pclusterCompatibilityFilter);
   tMCNP->SetBranchAddress("p", &p, &b_p);

  cout<<"check 6"<<endl;

// from ntHi
   tMCNP->SetBranchAddress("run", &run, &b_run);
   tMCNP->SetBranchAddress("evt", &evt, &b_evt);
   tMCNP->SetBranchAddress("lumi", &lumi, &b_lumi);
   tMCNP->SetBranchAddress("vx", &vx, &b_vx);
   tMCNP->SetBranchAddress("vy", &vy, &b_vy);
   tMCNP->SetBranchAddress("vz", &vz, &b_vz);
   tMCNP->SetBranchAddress("Npart", &Npart, &b_Npart);
   tMCNP->SetBranchAddress("Ncoll", &Ncoll, &b_Ncoll);
   tMCNP->SetBranchAddress("Nhard", &Nhard, &b_Nhard);
   tMCNP->SetBranchAddress("phi0", &phi0, &b_NPhi0);
   tMCNP->SetBranchAddress("b", &b, &b_b);
   tMCNP->SetBranchAddress("Ncharged", &Ncharged, &b_Ncharged);
   tMCNP->SetBranchAddress("NchargedMR", &NchargedMR, &b_NchargedMR);
   tMCNP->SetBranchAddress("MeanPt", &MeanPt, &b_MeanPt);
   tMCNP->SetBranchAddress("MeanPtMR", &MeanPtMR, &b_MeanPtMR);
   tMCNP->SetBranchAddress("EtMR", &EtMR, &b_EtMR);
   tMCNP->SetBranchAddress("NchargedPtCut", &NchargedPtCut, &b_NchargedPtCut);
   tMCNP->SetBranchAddress("NchargedPtCutMR", &NchargedPtCutMR, &b_NchargedPtCutMR);
   tMCNP->SetBranchAddress("ProcessID", &ProcessID, &b_ProcessID);
   tMCNP->SetBranchAddress("pthat", &pthat, &b_pthat);
   tMCNP->SetBranchAddress("weight", &weight, &b_weight);
   tMCNP->SetBranchAddress("alphaQCD", &alphaQCD, &b_alphaQCD);
   tMCNP->SetBranchAddress("alphaQED", &alphaQED, &b_alphaQED);
   tMCNP->SetBranchAddress("qScale", &qScale, &b_qScale);
   tMCNP->SetBranchAddress("nMEPartons", &nMEPartons, &b_nMEPartons);
   tMCNP->SetBranchAddress("nMEPartonsFiltered", &nMEPartonsFiltered, &b_nMEPartonsFiltered);
//   tMCNP->SetBranchAddress("first", &first, &b_pdfID_first);
//   tMCNP->SetBranchAddress("second", &second, &b_pdfID_second);
//   tMCNP->SetBranchAddress("ttbar_w", &ttbar_w, &b_ttbar_w);
//   tMCNP->SetBranchAddress("npus", &npus, &b_npus);
//   tMCNP->SetBranchAddress("tnpus", &tnpus, &b_tnpus);
   tMCNP->SetBranchAddress("hiBin", &hiBin, &b_hiBin);
   tMCNP->SetBranchAddress("hiHF", &hiHF, &b_hiHF);
   tMCNP->SetBranchAddress("hiHFplus", &hiHFplus, &b_hiHFplus);
   tMCNP->SetBranchAddress("hiHFminus", &hiHFminus, &b_hiHFminus);
   tMCNP->SetBranchAddress("hiHFplusEta4", &hiHFplusEta4, &b_hiHFplusEta4);
   tMCNP->SetBranchAddress("hiHFminusEta4", &hiHFminusEta4, &b_hiHFminusEta4);
   tMCNP->SetBranchAddress("hiZDC", &hiZDC, &b_hiZDC);
   tMCNP->SetBranchAddress("hiZDCplus", &hiZDCplus, &b_hiZDCplus);
   tMCNP->SetBranchAddress("hiZDCminus", &hiZDCminus, &b_hiZDCminus);
   tMCNP->SetBranchAddress("hiHFhit", &hiHFhit, &b_hiHFhit);
   tMCNP->SetBranchAddress("hiHFhitPlus", &hiHFhitPlus, &b_hiHFhitPlus);
   tMCNP->SetBranchAddress("hiHFhitMinus", &hiHFhitMinus, &b_hiHFhitMinus);
   tMCNP->SetBranchAddress("hiET", &hiET, &b_hiET);
   tMCNP->SetBranchAddress("hiEE", &hiEE, &b_hiEE);
   tMCNP->SetBranchAddress("hiEB", &hiEB, &b_hiEB);
   tMCNP->SetBranchAddress("hiEEplus", &hiEEplus, &b_hiEEplus);
   tMCNP->SetBranchAddress("hiEEminus", &hiEEminus, &b_hiEEminus);
   tMCNP->SetBranchAddress("hiNpix", &hiNpix, &b_hiNpix);
   tMCNP->SetBranchAddress("hiNpixelTracks", &hiNpixelTracks, &b_hiNpixelTracks);
   tMCNP->SetBranchAddress("hiNtracks", &hiNtracks, &b_hiNtracks);
   tMCNP->SetBranchAddress("hiNtracksPtCut", &hiNtracksPtCut, &b_hiNtracksPtCut);
   tMCNP->SetBranchAddress("hiNtracksEtaCut", &hiNtracksEtaCut, &b_hiNtracksEtaCut);
   tMCNP->SetBranchAddress("hiNtracksEtaPtCut", &hiNtracksEtaPtCut, &b_hiNtracksEtaPtCut);
   tMCNP->SetBranchAddress("hiNevtPlane", &hiNevtPlane, &b_hiNevtPlane);
   tMCNP->SetBranchAddress("hiEvtPlanes", hiEvtPlanes, &b_hiEvtPlanes);
   tMCNP->SetBranchAddress("pthatweight", &pthatweight, &b_pthatweight);
   tMCNP->SetBranchAddress("maxDgenpt", &maxDgenpt, &b_maxDgenpt);

  cout<<"check 7"<<endl;



// from ntDkpi
   tMCNP->SetBranchAddress("RunNo", &RunNo, &b_RunNo);
   tMCNP->SetBranchAddress("EvtNo", &EvtNo, &b_EvtNo);
   tMCNP->SetBranchAddress("LumiNo", &LumiNo, &b_LumiNo);
   tMCNP->SetBranchAddress("Dsize", &Dsize, &b_Dsize);
   tMCNP->SetBranchAddress("PVx", &PVx, &b_PVx);
   tMCNP->SetBranchAddress("PVy", &PVy, &b_PVy);
   tMCNP->SetBranchAddress("PVz", &PVz, &b_PVz);
   tMCNP->SetBranchAddress("PVnchi2", &PVnchi2, &b_PVnchi2);
   tMCNP->SetBranchAddress("BSx", &BSx, &b_BSx);
   tMCNP->SetBranchAddress("BSy", &BSy, &b_BSy);
   tMCNP->SetBranchAddress("BSz", &BSz, &b_BSz);
   tMCNP->SetBranchAddress("PVxE", &PVxE, &b_PVxE);
   tMCNP->SetBranchAddress("PVyE", &PVyE, &b_PVyE);
   tMCNP->SetBranchAddress("PVzE", &PVzE, &b_PVzE);
   tMCNP->SetBranchAddress("BSxErr", &BSxErr, &b_BSxErr);
   tMCNP->SetBranchAddress("BSyErr", &BSyErr, &b_BSyErr);
   tMCNP->SetBranchAddress("BSzErr", &BSzErr, &b_BSzErr);
   tMCNP->SetBranchAddress("BSdxdz", &BSdxdz, &b_BSdxdz);
   tMCNP->SetBranchAddress("BSdydz", &BSdydz, &b_BSdydz);
   tMCNP->SetBranchAddress("BSdxdzErr", &BSdxdzErr, &b_BSdxdzErr);
   tMCNP->SetBranchAddress("BSdydzErr", &BSdydzErr, &b_BSdydzErr);
   tMCNP->SetBranchAddress("BSWidthX", &BSWidthX, &b_BSWidthX);
   tMCNP->SetBranchAddress("BSWidthXErr", &BSWidthXErr, &b_BSWidthXErr);
   tMCNP->SetBranchAddress("BSWidthY", &BSWidthY, &b_BSWidthY);
   tMCNP->SetBranchAddress("BSWidthYErr", &BSWidthYErr, &b_BSWidthYErr);
   tMCNP->SetBranchAddress("Dindex", Dindex, &b_Dindex);
   tMCNP->SetBranchAddress("Dtype", Dtype, &b_Dtype);
   tMCNP->SetBranchAddress("Dmass", Dmass, &b_Dmass);
   tMCNP->SetBranchAddress("Dpt", Dpt, &b_Dpt);
   tMCNP->SetBranchAddress("Deta", Deta, &b_Deta);
   tMCNP->SetBranchAddress("Dphi", Dphi, &b_Dphi);
   tMCNP->SetBranchAddress("Dy", Dy, &b_Dy);
   tMCNP->SetBranchAddress("DvtxX", DvtxX, &b_DvtxX);
   tMCNP->SetBranchAddress("DvtxY", DvtxY, &b_DvtxY);
   tMCNP->SetBranchAddress("Dd0", Dd0, &b_Dd0);
   tMCNP->SetBranchAddress("Dd0Err", Dd0Err, &b_Dd0Err);
   tMCNP->SetBranchAddress("Ddxyz", Ddxyz, &b_Ddxyz);
   tMCNP->SetBranchAddress("DdxyzErr", DdxyzErr, &b_DdxyzErr);
   tMCNP->SetBranchAddress("Dchi2ndf", Dchi2ndf, &b_Dchi2ndf);
   tMCNP->SetBranchAddress("Dchi2cl", Dchi2cl, &b_Dchi2cl);
   tMCNP->SetBranchAddress("Ddtheta", Ddtheta, &b_Ddtheta);
   tMCNP->SetBranchAddress("Dlxy", Dlxy, &b_Dlxy);
   tMCNP->SetBranchAddress("Dalpha", Dalpha, &b_Dalpha);
   tMCNP->SetBranchAddress("DsvpvDistance", DsvpvDistance, &b_DsvpvDistance);
   tMCNP->SetBranchAddress("DsvpvDisErr", DsvpvDisErr, &b_DsvpvDisErr);
   tMCNP->SetBranchAddress("DsvpvDistance_2D", DsvpvDistance_2D, &b_DsvpvDistance_2D);
   tMCNP->SetBranchAddress("DsvpvDisErr_2D", DsvpvDisErr_2D, &b_DsvpvDisErr_2D);
   tMCNP->SetBranchAddress("DtktkRes_chi2ndf", DtktkRes_chi2ndf, &b_DtktkRes_chi2ndf);
   tMCNP->SetBranchAddress("DtktkRes_chi2cl", DtktkRes_chi2cl, &b_DtktkRes_chi2cl);
   tMCNP->SetBranchAddress("DtktkRes_alpha", DtktkRes_alpha, &b_DtktkRes_alpha);
   tMCNP->SetBranchAddress("DtktkRes_svpvDistance", DtktkRes_svpvDistance, &b_DtktkRes_svpvDistance);

   tMCNP->SetBranchAddress("DtktkRes_svpvDisErr", DtktkRes_svpvDisErr, &b_DtktkRes_svpvDisErr);
   tMCNP->SetBranchAddress("DlxyBS", DlxyBS, &b_DlxyBS);
   tMCNP->SetBranchAddress("DlxyBSErr", DlxyBSErr, &b_DlxyBSErr);
   tMCNP->SetBranchAddress("DMaxDoca", DMaxDoca, &b_DMaxDoca);
   tMCNP->SetBranchAddress("Dtrk1Pt", Dtrk1Pt, &b_Dtrk1Pt);
   tMCNP->SetBranchAddress("Dtrk2Pt", Dtrk2Pt, &b_Dtrk2Pt);
   tMCNP->SetBranchAddress("Dtrk1Eta", Dtrk1Eta, &b_Dtrk1Eta);
   tMCNP->SetBranchAddress("Dtrk2Eta", Dtrk2Eta, &b_Dtrk2Eta);
   tMCNP->SetBranchAddress("Dtrk1Phi", Dtrk1Phi, &b_Dtrk1Phi);
   tMCNP->SetBranchAddress("Dtrk2Phi", Dtrk2Phi, &b_Dtrk2Phi);
   tMCNP->SetBranchAddress("Dtrk1PtErr", Dtrk1PtErr, &b_Dtrk1PtErr);
   tMCNP->SetBranchAddress("Dtrk2PtErr", Dtrk2PtErr, &b_Dtrk2PtErr);
   tMCNP->SetBranchAddress("Dtrk1Dxy", Dtrk1Dxy, &b_Dtrk1Dxy);
   tMCNP->SetBranchAddress("Dtrk2Dxy", Dtrk2Dxy, &b_Dtrk2Dxy);
   tMCNP->SetBranchAddress("Dtrk1PixelHit", Dtrk1PixelHit, &b_Dtrk1PixelHit);
   tMCNP->SetBranchAddress("Dtrk2PixelHit", Dtrk2PixelHit, &b_Dtrk2PixelHit);
   tMCNP->SetBranchAddress("Dtrk1StripHit", Dtrk1StripHit, &b_Dtrk1StripHit);
   tMCNP->SetBranchAddress("Dtrk2StripHit", Dtrk2StripHit, &b_Dtrk2StripHit);
   tMCNP->SetBranchAddress("Dtrk1nStripLayer", Dtrk1nStripLayer, &b_Dtrk1nStripLayer);
   tMCNP->SetBranchAddress("Dtrk2nStripLayer", Dtrk2nStripLayer, &b_Dtrk2nStripLayer);
   tMCNP->SetBranchAddress("Dtrk1nPixelLayer", Dtrk1nPixelLayer, &b_Dtrk1nPixelLayer);
   tMCNP->SetBranchAddress("Dtrk2nPixelLayer", Dtrk2nPixelLayer, &b_Dtrk2nPixelLayer);
   tMCNP->SetBranchAddress("Dtrk1Chi2ndf", Dtrk1Chi2ndf, &b_Dtrk1Chi2ndf);
   tMCNP->SetBranchAddress("Dtrk2Chi2ndf", Dtrk2Chi2ndf, &b_Dtrk2Chi2ndf);
   tMCNP->SetBranchAddress("Dtrk1MassHypo", Dtrk1MassHypo, &b_Dtrk1MassHypo);
   tMCNP->SetBranchAddress("Dtrk2MassHypo", Dtrk2MassHypo, &b_Dtrk2MassHypo);
   tMCNP->SetBranchAddress("Dtrk1Algo", Dtrk1Algo, &b_Dtrk1Algo);
   tMCNP->SetBranchAddress("Dtrk2Algo", Dtrk2Algo, &b_Dtrk2Algo);
   tMCNP->SetBranchAddress("Dtrk1originalAlgo", Dtrk1originalAlgo, &b_Dtrk1originalAlgo);
   tMCNP->SetBranchAddress("Dtrk2originalAlgo", Dtrk2originalAlgo, &b_Dtrk2originalAlgo);
   tMCNP->SetBranchAddress("Dtrk1highPurity", Dtrk1highPurity, &b_Dtrk1highPurity);
   tMCNP->SetBranchAddress("Dtrk2highPurity", Dtrk2highPurity, &b_Dtrk2highPurity);
   tMCNP->SetBranchAddress("Dtrk1Idx", Dtrk1Idx, &b_Dtrk1Idx);
   tMCNP->SetBranchAddress("Dtrk2Idx", Dtrk2Idx, &b_Dtrk2Idx);
   tMCNP->SetBranchAddress("Dtrk1EtaErr", Dtrk1EtaErr, &b_Dtrk1EtaErr);
   tMCNP->SetBranchAddress("Dtrk2EtaErr", Dtrk2EtaErr, &b_Dtrk2EtaErr);
   tMCNP->SetBranchAddress("Dtrk1PhiErr", Dtrk1PhiErr, &b_Dtrk1PhiErr);
   tMCNP->SetBranchAddress("Dtrk2PhiErr", Dtrk2PhiErr, &b_Dtrk2PhiErr);
   tMCNP->SetBranchAddress("Dtrk1Y", Dtrk1Y, &b_Dtrk1Y);
   tMCNP->SetBranchAddress("Dtrk2Y", Dtrk2Y, &b_Dtrk2Y);
   tMCNP->SetBranchAddress("Dtrk1D0Err", Dtrk1D0Err, &b_Dtrk1D0Err);
   tMCNP->SetBranchAddress("Dtrk2D0Err", Dtrk2D0Err, &b_Dtrk2D0Err);
   tMCNP->SetBranchAddress("Dtrk1MVAVal", Dtrk1MVAVal, &b_Dtrk1MVAVal);
   tMCNP->SetBranchAddress("Dtrk2MVAVal", Dtrk2MVAVal, &b_Dtrk2MVAVal);
   tMCNP->SetBranchAddress("Dtrk1Quality", Dtrk1Quality, &b_Dtrk1Quality);
   tMCNP->SetBranchAddress("Dtrk2Quality", Dtrk2Quality, &b_Dtrk2Quality);
   tMCNP->SetBranchAddress("Dgen", Dgen, &b_Dgen);
   tMCNP->SetBranchAddress("DgenIndex", DgenIndex, &b_DgenIndex);
   tMCNP->SetBranchAddress("DgennDa", DgennDa, &b_DgennDa);
   tMCNP->SetBranchAddress("Dgenpt", Dgenpt, &b_Dgenpt);
   tMCNP->SetBranchAddress("Dgeneta", Dgeneta, &b_Dgeneta);
   tMCNP->SetBranchAddress("Dgenphi", Dgenphi, &b_Dgenphi);
   tMCNP->SetBranchAddress("Dgeny", Dgeny, &b_Dgeny);
   tMCNP->SetBranchAddress("DgencollisionId", DgencollisionId, &b_DgencollisionId);
   tMCNP->SetBranchAddress("DgenBAncestorpt", DgenBAncestorpt, &b_DgenBAncestorpt);
   tMCNP->SetBranchAddress("DgenBAncestorpdgId", DgenBAncestorpdgId, &b_DgenBAncestorpdgId);

  cout<<"check 8"<<endl;


// output file


  TFile* fout = new TFile("bFeedDownPbPbMCNP.tree.root","recreate");
  TTree *Dtree = new TTree("Dtree","Dtree");

	TH1F *h_D0Dca_2d = new TH1F("h_D0Dca_2d","h_D0Dca_2d",200,-0.1,0.1);

  Float_t  PVx_out;
  Float_t  PVy_out;
  Float_t  PVz_out;
	Float_t  pthat_out;
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
  Dtree->Branch("pthat",&pthat_out,"pthat/F");



// v0 using DsvpvDistance_2D
// v1 using DsvpvDistance_2D which caculate by Dvtx and PV , with long calculation.
// V2 short calculation (Hao)


//	Dtree->Branch("");
//	Dtree->Branch("");
	cout<<"check9"<<endl;

	Long64_t nentries;

	nentries=tMCNP->GetEntries();

	cout<<"nentries ="<<nentries;

	

	 for(int ientries=0; ientries<nentries; ientries++){
//		 for(int ientries=0; ientries<50000; ientries++){
			tMCNP->GetEntry(ientries);

			pthatweight_out=pthatweight;			
			pthat_out=pthat;	
			int cutPbPb=0;
			int cutPbPbMB=0;
			int cutpt=0;
			int cutptMB=0;
			int cutmc=0;
			int cutSignal=0;
			int cutPrompt=0;
			int cutNonPrompt=0;

	   for(int iDsize=0; iDsize<Dsize; iDsize++){
			cutPbPb=0;
			cutPbPbMB=0;
			cutpt=0;
			cutptMB=0;
			cutmc=0;
			cutSignal=0;
			cutPrompt=0;
			cutNonPrompt=0;

      if(pclusterCompatibilityFilter&&pprimaryVertexFilter&&phfCoincFilter3&&abs(PVz)<15&&Dy[iDsize]>-1.&&Dy[iDsize]<1.&&Dtrk1highPurity[iDsize]&&Dtrk2highPurity[iDsize]&&Dtrk1Pt[iDsize]>8.5&&Dtrk2Pt[iDsize]>8.5&&abs(Dtrk1Eta[iDsize])<1.5&&abs(Dtrk2Eta[iDsize])<1.5&&Dtrk1PtErr[iDsize]/Dtrk1Pt[iDsize]<0.3&&Dtrk2PtErr[iDsize]/Dtrk2Pt[iDsize]<0.3&&((DlxyBS[iDsize]/DlxyBSErr[iDsize])>2.5&&Dalpha[iDsize]<0.12&&((Dpt[iDsize]>2&&Dpt[iDsize]<4&&(DsvpvDistance[iDsize]/DsvpvDisErr[iDsize])>5.86&&Dchi2cl[iDsize]>0.224)||(Dpt[iDsize]>4&&Dpt[iDsize]<5&&(DsvpvDistance[iDsize]/DsvpvDisErr[iDsize])>5.46&&Dchi2cl[iDsize]>0.196)||(Dpt[iDsize]>5&&Dpt[iDsize]<6&&(DsvpvDistance[iDsize]/DsvpvDisErr[iDsize])>4.86&&Dchi2cl[iDsize]>0.170)||(Dpt[iDsize]>6&&Dpt[iDsize]<8&&(DsvpvDistance[iDsize]/DsvpvDisErr[iDsize])>4.54&&Dchi2cl[iDsize]>0.125)||(Dpt[iDsize]>8&&Dpt[iDsize]<10&&(DsvpvDistance[iDsize]/DsvpvDisErr[iDsize])>4.42&&Dchi2cl[iDsize]>0.091)||(Dpt[iDsize]>10&&Dpt[iDsize]<15&&(DsvpvDistance[iDsize]/DsvpvDisErr[iDsize])>4.06&&Dchi2cl[iDsize]>0.069)||(Dpt[iDsize]>15&&Dpt[iDsize]<20&&(DsvpvDistance[iDsize]/DsvpvDisErr[iDsize])>3.71&&Dchi2cl[iDsize]>0.056)||(Dpt[iDsize]>20&&Dpt[iDsize]<25&&(DsvpvDistance[iDsize]/DsvpvDisErr[iDsize])>3.25&&Dchi2cl[iDsize]>0.054)||(Dpt[iDsize]>25&&(DsvpvDistance[iDsize]/DsvpvDisErr[iDsize])>2.97&&Dchi2cl[iDsize]>0.050)))) {  cutPbPb=1;  }

			if(pclusterCompatibilityFilter&&pprimaryVertexFilter&&phfCoincFilter3&&abs(PVz)<15&&Dy[iDsize]>-1.&&Dy[iDsize]<1.&&Dtrk1highPurity[iDsize]&&Dtrk2highPurity[iDsize]&&Dtrk1Pt[iDsize]>1.0&&Dtrk2Pt[iDsize]>1.0&&Dtrk1PtErr[iDsize]/Dtrk1Pt[iDsize]<0.3&&Dtrk2PtErr[iDsize]/Dtrk2Pt[iDsize]<0.3&&abs(Dtrk1Eta[iDsize])<1.5&&abs(Dtrk2Eta[iDsize])<1.5&&((DlxyBS[iDsize]/DlxyBSErr[iDsize])>1.5&&Dalpha[iDsize]<0.12&&((Dpt[iDsize]>1&&Dpt[iDsize]<2&&(DsvpvDistance[iDsize]/DsvpvDisErr[iDsize])>6.0&&Dchi2cl[iDsize]>0.25)||(Dpt[iDsize]>2&&Dpt[iDsize]<4&&(DsvpvDistance[iDsize]/DsvpvDisErr[iDsize])>5.86&&Dchi2cl[iDsize]>0.224)||(Dpt[iDsize]>4&&Dpt[iDsize]<5&&(DsvpvDistance[iDsize]/DsvpvDisErr[iDsize])>5.46&&Dchi2cl[iDsize]>0.196)||(Dpt[iDsize]>5&&Dpt[iDsize]<6&&(DsvpvDistance[iDsize]/DsvpvDisErr[iDsize])>4.86&&Dchi2cl[iDsize]>0.170)||(Dpt[iDsize]>6&&Dpt[iDsize]<8&&(DsvpvDistance[iDsize]/DsvpvDisErr[iDsize])>4.54&&Dchi2cl[iDsize]>0.125)||(Dpt[iDsize]>8&&Dpt[iDsize]<10&&(DsvpvDistance[iDsize]/DsvpvDisErr[iDsize])>4.42&&Dchi2cl[iDsize]>0.091)||(Dpt[iDsize]>10&&Dpt[iDsize]<15&&(DsvpvDistance[iDsize]/DsvpvDisErr[iDsize])>4.06&&Dchi2cl[iDsize]>0.069)||(Dpt[iDsize]>15&&Dpt[iDsize]<20&&(DsvpvDistance[iDsize]/DsvpvDisErr[iDsize])>3.71&&Dchi2cl[iDsize]>0.056)||(Dpt[iDsize]>20&&Dpt[iDsize]<25&&(DsvpvDistance[iDsize]/DsvpvDisErr[iDsize])>3.25&&Dchi2cl[iDsize]>0.054)||(Dpt[iDsize]>25&&(DsvpvDistance[iDsize]/DsvpvDisErr[iDsize])>2.97&&Dchi2cl[iDsize]>0.050)))){ cutPbPbMB=1;}

      if( Dpt[iDsize]>20 && pthat>1.2*(Dpt[iDsize]-20) ){cutpt=1;}
      if( Dpt[iDsize]<20 ) {cutptMB=1;}
			if( Dgen[iDsize]==23333||Dgen[iDsize]==23344) {cutmc=1;}
			if( abs(Dmass[iDsize]-1.8649)<0.025) {cutSignal=1;}
			if( DgenBAncestorpt[iDsize]<=0){cutPrompt=1;}
			if( DgenBAncestorpt[iDsize]>0 ){cutNonPrompt=1;}

				if( ((cutPbPb == 1 && cutpt ==1) || (cutPbPbMB==1 && cutptMB==1)) && cutmc==1 && cutSignal ==1 && cutNonPrompt ==1){
//        if(  (cutPbPbMB==1 && cutptMB==1) && cutmc==1 && cutSignal ==1 && cutPrompt ==1){

        Dpt_out=Dpt[iDsize];
				Dphi_out=Dphi[iDsize];
        Dmass_out=Dmass[iDsize];
				Dalpha_out=Dalpha[iDsize];
				DsvpvDistance_out=DsvpvDistance[iDsize];
				DsvpvDistance_2D_out=DsvpvDistance_2D[iDsize];
				D0DCA_out=DsvpvDistance[iDsize]*TMath::Sin(Dalpha[iDsize]);

				TVector3 v_Dpt(Dpt_out*TMath::Cos(Dphi_out),Dpt_out*TMath::Sin(Dphi_out),0);
//				TVector3 v_Ddecay(DvtxX[iDsize]-PVx,DvtxY[iDsize]-PVy,0);		
				TVector3 v_Ddecay(DvtxX[iDsize],DvtxY[iDsize],0);
				// Float_t alpha_2d=v_Dpt.Angle(v_Ddecay);
				Float_t alpha_2d=v_Dpt.Phi()-v_Ddecay.Phi();
//				if(alpha_2d > TMath::Pi() ) alpha_2d=TMath::Pi()-alpha_2d;
//        if(alpha_2d < TMath::Pi() ) alpha_2d=alpha_2d+TMath::Pi();
			
				Dalpha_2D_out= alpha_2d;

				DsvpvDistance_2Dv1_out=v_Ddecay.Mag();
				D0DCA_2D_out=DsvpvDistance_2D_out*TMath::Sin(alpha_2d);
				D0DCA_2Dabs_out=fabs(D0DCA_2D_out);
				D0DCA_2Dv1_out=DsvpvDistance_2Dv1_out*TMath::Sin(alpha_2d);
//				D0DCA_2Dv2_out=(DvtxX[iDsize]-PVx)*TMath::Sin(Dphi_out)-(DvtxY[iDsize]-PVy)*TMath::Cos(Dphi_out);
        D0DCA_2Dv2_out=(DvtxX[iDsize])*TMath::Sin(Dphi_out)-(DvtxY[iDsize])*TMath::Cos(Dphi_out);


        Dtree->Fill();

				h_D0Dca_2d->Fill(D0DCA_2Dv1_out,pthatweight);
			

      } // end if signal selection
    }// end for Dsize     


	
	}	// end for nentries

	fout->cd();
	Dtree->Write();
	h_D0Dca_2d->Write();

	TCanvas *c1= new TCanvas("c1","c1",600,600);
	c1->cd();
	h_D0Dca_2d->Draw();

	fout->Close();

}


