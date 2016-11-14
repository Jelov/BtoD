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


void test_TF1_FitErr(){


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

  TFile* fPbPb = new TFile("bFeedDownPbPb.hist.root");
  TFile* fPbPbMB = new TFile("bFeedDownPbPbMB.hist.root");
  TFile* fPbPbMC = new TFile("bFeedDownPbPbMC.hist.root");
  TFile* fPbPbMBMC = new TFile("bFeedDownPbPbMBMC.hist.root");

  TH3D* hDataPbPb = (TH3D*)fPbPb->Get("hData");
  TH3D* hSidebandPbPb = (TH3D*)fPbPb->Get("hSideband");
  TH3D* hDataPbPbMB = (TH3D*)fPbPbMB->Get("hData");
  TH3D* hSidebandPbPbMB = (TH3D*)fPbPbMB->Get("hSideband");
  TH3D* hPtMD0DcaPbPb = (TH3D*)fPbPb->Get("hPtMD0Dca");
  TH3D* hPtMD0DcaPbPbMB = (TH3D*)fPbPbMB->Get("hPtMD0Dca");

  TH3D* hMCPSignalPbPb = (TH3D*)fPbPbMC->Get("hMCPSignal");
  TH3D* hMCNPSignalPbPb = (TH3D*)fPbPbMC->Get("hMCNPSignal");
  TH3D* hMCPSignalPbPbMB = (TH3D*)fPbPbMBMC->Get("hMCPSignal");
  TH3D* hMCNPSignalPbPbMB = (TH3D*)fPbPbMBMC->Get("hMCNPSignal");
  TH3D* hPtMD0DcaMCPSignalPbPb = (TH3D*)fPbPbMC->Get("hPtMD0DcaMCPSignal");
  TH3D* hPtMD0DcaMCPSwappedPbPb = (TH3D*)fPbPbMC->Get("hPtMD0DcaMCPSwapped");
  TH3D* hPtMD0DcaMCPSignalPbPbMB =(TH3D*)fPbPbMBMC->Get("hPtMD0DcaMCPSignal");
  TH3D* hPtMD0DcaMCPSwappedPbPbMB = (TH3D*)fPbPbMBMC->Get("hPtMD0DcaMCPSwapped");

  TH3D* hData = (TH3D*)hDataPbPb->Clone("hData");
  hData->Sumw2();
  hData->Add(hDataPbPbMB);

  TH3D* hSideband = (TH3D*)hSidebandPbPb->Clone("hSideband");
  hSideband->Sumw2();
  hSideband->Add(hSidebandPbPbMB);

  TH3D* hPtMD0Dca = (TH3D*)hPtMD0DcaPbPb->Clone("hPtMD0Dca");
  hPtMD0Dca->Sumw2();
  hPtMD0Dca->Add(hPtMD0DcaPbPbMB);

  TH3D* hMCPSignal = (TH3D*)hMCPSignalPbPb->Clone("hMCPSignal");
  hMCPSignal->Sumw2();
  hMCPSignal->Add(hMCPSignalPbPbMB);
  TH3D* hMCNPSignal = (TH3D*)hMCNPSignalPbPb->Clone("hMCNPSignal");
  hMCNPSignal->Sumw2();
  hMCNPSignal->Add(hMCNPSignalPbPbMB);

  TH3D* hPtMD0DcaMCPSignal = (TH3D*)hPtMD0DcaMCPSignalPbPb->Clone("hPtMD0DcaMCPSignal");
  hPtMD0DcaMCPSignal->Sumw2();
  hPtMD0DcaMCPSignal->Add(hPtMD0DcaMCPSignalPbPbMB);

  TH3D* hPtMD0DcaMCPSwapped =(TH3D*)hPtMD0DcaMCPSwappedPbPb->Clone("hPtMD0DcaMCPSwapped");
  hPtMD0DcaMCPSwapped->Sumw2();
  hPtMD0DcaMCPSwapped->Add(hPtMD0DcaMCPSwappedPbPbMB);

  const int nPtBins = 9;
  float ptBins[nPtBins+1] = {2.,4.,6.,8.,10.,12,20.,40.,60.,100};

  const int nBinY = 20;
  Float_t binsY[nBinY+1] = {-0.0734,-0.0562,-0.0428,-0.0320,-0.0236,-0.0170,-0.0118,-0.0078,-0.0046,-0.002,0.0,0.002,0.0046,0.0078,0.0118,0.0170,0.0236,0.0320,0.0428,0.0562,0.0734};

  float pts[nPtBins];
  float ptErrors[nPtBins];

	double ptLow = ptBins[1]; // 4-6 pt bin
	double ptHi = ptBins[2];

    hPtMD0Dca->GetZaxis()->SetRange(1,100);
    hPtMD0Dca->GetXaxis()->SetRangeUser(ptLow+0.001,ptHigh-0.001);
    hPtMD0DcaMCPSignal->GetXaxis()->SetRangeUser(ptLow+0.001,ptHigh-0.001);
    hPtMD0DcaMCPSwapped->GetXaxis()->SetRangeUser(ptLow+0.001,ptHigh-0.001);
    TH1D* hMData = (TH1D*)hPtMD0Dca->Project3D("y")->Clone(Form("hM_%1.1f_%1.1f", ptLow, ptHigh));
    TH1D* hMMCSignal = (TH1D*)hPtMD0DcaMCPSignal->Project3D("y");
    TH1D* hMMCSwapped = (TH1D*)hPtMD0DcaMCPSwapped->Project3D("y");


//






	}
