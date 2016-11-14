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


void D0Dca_xy_plot(){

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

  TFile* fPbPbMC = new TFile("bFeedDownPbPbMC.hist.root");
  TFile* fPbPbMBMC = new TFile("bFeedDownPbPbMBMC.hist.root");
  TFile* fPbPb = new TFile("bFeedDownPbPb.hist.root");
  TFile* fPbPbMB = new TFile("bFeedDownPbPbMB.hist.root");

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

  const int nPtBins = 14;
  float ptBins[nPtBins+1] = {2.,3.,4.,5.,6.,8.,10.,12.5,15.0,20.,25.,30.,40.,60.,100};


  TH1D* hD0DcaData0 = (TH1D*)hData->Project3D("y")->Clone("hD0DcaData0");
  TH1D* hD0DcaMCPSignal0 = (TH1D*)hMCPSignal->Project3D("y")->Clone("hD0DcaMCPSignal0");
  TH1D* hD0DcaMCNPSignal0 = (TH1D*)hMCNPSignal->Project3D("y")->Clone("hD0DcaMCNPSignal0");


  TH1D* hD0DcaxyData0 = (TH1D*)hData->Project3D("z")->Clone("hD0DcaxyData0");
  TH1D* hD0DcaxyMCPSignal0 = (TH1D*)hMCPSignal->Project3D("z")->Clone("hD0DcaxyMCPSignal0");
  TH1D* hD0DcaxyMCNPSignal0 = (TH1D*)hMCNPSignal->Project3D("z")->Clone("hD0DcaxyMCNPSignal0");

	TCanvas *c_Dca2D = new TCanvas("c_Dca2D","c_Dca2D",800,800);
	TLegend *l_Dca2D = new TLegend(0.2,0.2,0.45,0.45);
	 
	c_Dca2D->cd();
	gPad->SetLogy();

  hD0DcaxyMCPSignal0->GetXaxis()->SetRangeUser(0,0.08);
  hD0DcaxyMCPSignal0->SetLineColor(2);
  hD0DcaxyMCPSignal0->DrawNormalized("SAME");
	hD0DcaxyData0->SetLineColor(1);
//	hD0DcaxyData0->GetXaxis()->SetRangeUser(0,0.08);
	hD0DcaxyData0->DrawNormalized("SAME");
  hD0DcaxyMCPSignal0->GetXaxis()->SetRangeUser(0,0.08);
	hD0DcaxyMCPSignal0->SetLineColor(2);
	hD0DcaxyMCPSignal0->DrawNormalized("SAME");
	hD0DcaxyMCNPSignal0->SetLineColor(4);
	hD0DcaxyMCNPSignal0->DrawNormalized("SAME");


	l_Dca2D->AddEntry(hD0DcaxyData0,"Data","l");
  l_Dca2D->AddEntry(hD0DcaxyMCPSignal0,"MC Prompt D","l");
  l_Dca2D->AddEntry(hD0DcaxyMCNPSignal0,"MC Non Prompt","l");
	l_Dca2D->SetBorderSize(0);
	l_Dca2D->Draw();

// divided by Dpt bins.	
//	TH1D* hD0DcaxyData0[nPtBins];
//  TH1D* hD0DcaxyMCPSignal0[nPtBins];
//  TH1D* hD0DcaxyMCNPSignal0[nPtBins];

  TCanvas *c_Dca = new TCanvas("c_Dca","c_Dca",800,800);
  TLegend *l_Dca = new TLegend(0.2,0.2,0.45,0.45);

  c_Dca->cd();
  gPad->SetLogy();

  hD0DcaMCPSignal0->GetXaxis()->SetRangeUser(0,0.08);
  hD0DcaMCPSignal0->SetLineColor(2);
  hD0DcaMCPSignal0->DrawNormalized("SAME");
  hD0DcaData0->SetLineColor(1);
//  hD0DcaxyData0->GetXaxis()->SetRangeUser(0,0.08);
  hD0DcaData0->DrawNormalized("SAME");
  hD0DcaMCPSignal0->GetXaxis()->SetRangeUser(0,0.08);
  hD0DcaMCPSignal0->SetLineColor(2);
  hD0DcaMCPSignal0->DrawNormalized("SAME");
  hD0DcaMCNPSignal0->SetLineColor(4);
  hD0DcaMCNPSignal0->DrawNormalized("SAME");


  l_Dca->AddEntry(hD0DcaData0,"Data","l");
  l_Dca->AddEntry(hD0DcaMCPSignal0,"MC Prompt D","l");
  l_Dca->AddEntry(hD0DcaMCNPSignal0,"MC Non Prompt","l");
  l_Dca->SetBorderSize(0);
  l_Dca->Draw();







}

