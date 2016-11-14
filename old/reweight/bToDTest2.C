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

TH1D* hD0DcaMCPSignal;
TH1D* hD0DcaMCNPSignal;

void bToDTest()
{
  gStyle->SetTextSize(0.05);
  gStyle->SetTextFont(42);
  gStyle->SetPadRightMargin(0.04);
  gStyle->SetPadLeftMargin(0.14);
  gStyle->SetPadTopMargin(0.1);
  gStyle->SetPadBottomMargin(0.14);
  gStyle->SetTitleX(.0f);
  gStyle->SetOptFit(1111);
  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0);

  TCanvas* c4 = new TCanvas("c4","",800,600);
  c4->Divide(2,2);

  TCanvas* c2 = new TCanvas("c2","",400,600);
  c2->Divide(1,2);

  TCanvas* c1 = new TCanvas();

  TCanvas* c15 = new TCanvas("c15","",810,1000);
  c15->Divide(3,5);

  TFile* fPbPbMC = new TFile("bFeedDownPbPbMC.hist.root");
  TFile* fPbPbMBMC = new TFile("bFeedDownPbPbMBMC.hist.root");

  const int nCent = 5;
  const int nPtWeight = 2;
  TH3D* hMCPSignal[nCent][nPtWeight];
  TH3D* hMCNPSignal[nCent][nPtWeight];
  TH3D* hPtMD0DcaMCPSignal[nCent][nPtWeight];
  TH3D* hPtMD0DcaMCPSwapped[nCent][nPtWeight];

  const char* CentArr[] ={"cent0to100","cent0to10", "cent10to30", "cent30to50", "cent50to100"};
  const char* PtWeightArr[] ={"PtWeight","NoWeight"};

  std::string iCentStr = "eta0to15";
  std::string iPtWeightStr = "PtWeight";

// get the TH3D and project to TH1D
  for(int iCent=0; iCent<nCent; iCent++){
    iCentStr= CentArr[iCent];
    cutCentralityBin=cutCentralityBinArr[iCent];
    for(int iPtWeight=0 ; iPtWeight<nPtWeight ; iPtWeight++){
      iPtWeightStr= PtWeightArr[iPtWeight];


  hMCPSignalPbPb[iCent][] = (TH3D*)fPbPbMC->Get("hMCPSignal");
  hMCNPSignalPbPb = (TH3D*)fPbPbMC->Get("hMCNPSignal");
  hMCPSignalPbPbMB = (TH3D*)fPbPbMBMC->Get("hMCPSignal");
  hMCNPSignalPbPbMB = (TH3D*)fPbPbMBMC->Get("hMCNPSignal");

  TH3D* hMCPSignal = (TH3D*)hMCPSignalPbPb->Clone("hMCPSignal");
  hMCPSignal->Sumw2();
  hMCPSignal->Add(hMCPSignalPbPbMB);

  TH3D* hMCNPSignal = (TH3D*)hMCNPSignalPbPb->Clone("hMCNPSignal");
  hMCNPSignal->Sumw2();
  hMCNPSignal->Add(hMCNPSignalPbPbMB);


  const int nPtBins = 14;
  float ptBins[nPtBins+1] = {2.,3.,4.,5.,6.,8.,10.,12.5,15.0,20.,25.,30.,40.,60.,100};
  const int nBinY = 14;
  Float_t binsY[nBinY+1];
  float firstBinYWidth = 0.001;
  float binYWidthRatio = 1.27;
  binsY[0]=0;
  for(int i=1; i<=nBinY; i++)
    binsY[i] = binsY[i-1]+firstBinYWidth*pow(binYWidthRatio,i-1);

  TH1D* hD0DcaMCPSignal0 = (TH1D*)hMCPSignal->Project3D("y")->Clone("hD0DcaMCPSignal0");
  TH1D* hD0DcaMCNPSignal0 = (TH1D*)hMCNPSignal->Project3D("y")->Clone("hD0DcaMCNPSignal0");


    } // end     for(int iPtWeight=0 ; iPtWeight<nPtWeight ; iPtWeight++)
  } // end   for(int iCent=0; iCent<nCent; iCent++)

} // end void bToDTest2() 
