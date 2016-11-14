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


void compareBtoDYield_2D3D(){

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


  const int nPtBins = 14;
  float ptBins[nPtBins+1] = {2.,3.,4.,5.,6.,8.,10.,12.5,15.0,20.,25.,30.,40.,60.,100};


	TFile* f_2D = new TFile("bFeedDownResult.root","READ");
	TFile* f_3D = new TFile("bFeedDownResult3D.root","READ");

	TH1D* hBtoDRawYield_2D = (TH1D*)f_2D->Get("hBtoDRawYield");
	TH1D* hBtoDRawYield_3D = (TH1D*)f_3D->Get("hBtoDRawYield");

	TH1D* hBtoDRawYield_2DRelErr = new TH1D("hBtoDRawYield_2DRelErr","hBtoDRawYield_2DRelErr",nPtBins,ptBins); hBtoDRawYield_2DRelErr->Sumw2();
  TH1D* hBtoDRawYield_3DRelErr = new TH1D("hBtoDRawYield_3DRelErr","hBtoDRawYield_3DRelErr",nPtBins,ptBins); hBtoDRawYield_3DRelErr->Sumw2();

	TH1D* hBtoDRawYield_ratio = (TH1D*)hBtoDRawYield_2D->Clone("hBtoDRawYield_ratio");
	hBtoDRawYield_ratio->Divide(hBtoDRawYield_2D,hBtoDRawYield_3D,1,1);

	TCanvas *c_ratio= new TCanvas("c_ratio","c_ratio",600,600);
	c_ratio->cd();
	hBtoDRawYield_ratio->GetYaxis()->SetTitle("BtoD Yield 2D/3D Ratio");
	hBtoDRawYield_ratio->Draw();

	double Yield2D,Yield2DErr,Yield2DRelErr;
  double Yield3D,Yield3DErr,Yield3DRelErr; 
	
	for(int i =1; i<=nPtBins; i++){
	Yield2D=hBtoDRawYield_2D->GetBinContent(i);
	Yield2DErr=hBtoDRawYield_2D->GetBinError(i);
	Yield2DRelErr=Yield2DErr/Yield2D;
	hBtoDRawYield_2DRelErr->SetBinContent(i,Yield2DRelErr);

  Yield3D=hBtoDRawYield_3D->GetBinContent(i);
  Yield3DErr=hBtoDRawYield_3D->GetBinError(i);
  Yield3DRelErr=Yield3DErr/Yield3D;
  hBtoDRawYield_3DRelErr->SetBinContent(i,Yield3DRelErr);
	
}

	TCanvas *c_RelErr = new TCanvas("c_RelErr","c_RelErr",400,800);
//	c_RelErr->Divide(1,2);
	c_RelErr->cd(1);
  hBtoDRawYield_2DRelErr->GetYaxis()->SetTitle("BtoD Yield Relative Err");
	hBtoDRawYield_2DRelErr->GetXaxis()->SetTitle("P_{T} (GeV/c)");
//	hBtoDRawYield_2DRelErr->SetMarkerStyle(20);
	hBtoDRawYield_2DRelErr->Draw("E");
//	c_RelErr->cd(2);
	hBtoDRawYield_3DRelErr->SetLineColor(2);
  hBtoDRawYield_3DRelErr->Draw("ESAME");

	TLegend *l_1 = new TLegend(0.65,0.65,0.88,0.88);
//	l_1->AddEntry((TObject*)0,"BtoD Yield Relative Err","");
	l_1->AddEntry(hBtoDRawYield_2DRelErr,"2D","l");
  l_1->AddEntry(hBtoDRawYield_3DRelErr,"3D","l");
	l_1->SetBorderSize(0);
	l_1->Draw();	
		


}
