//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Sat Aug  6 03:36:35 2016 by ROOT version 6.02/13
// from TTree ntDkpi/
// found on file: /data/dmeson2015/DataDntuple/ntD_EvtBase_20160405_HIHardProbes_DfinderData_PbPb_20160402_dPt0tkPt2p5_D0Dstar3p5p_FINALJSON_skimmed.root
//////////////////////////////////////////////////////////

#ifndef Data_Class_h
#define Data_Class_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class Data_Class {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
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

   Data_Class(TTree *tree=0);
   virtual ~Data_Class();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef Data_Class_cxx
Data_Class::Data_Class(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/data/dmeson2015/DataDntuple/ntD_EvtBase_20160405_HIHardProbes_DfinderData_PbPb_20160402_dPt0tkPt2p5_D0Dstar3p5p_FINALJSON_skimmed.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/data/dmeson2015/DataDntuple/ntD_EvtBase_20160405_HIHardProbes_DfinderData_PbPb_20160402_dPt0tkPt2p5_D0Dstar3p5p_FINALJSON_skimmed.root");
      }
      f->GetObject("ntDkpi",tree);

   }
   Init(tree);
}

Data_Class::~Data_Class()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t Data_Class::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t Data_Class::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void Data_Class::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

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
   Notify();
}

Bool_t Data_Class::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void Data_Class::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t Data_Class::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef Data_Class_cxx
