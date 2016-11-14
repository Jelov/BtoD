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
#include <TTree.h>

void Plot(){


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


	TFile *fPbPb = new TFile("bFeedDownPbPbMC.tree.root","READ");

	TTree *tMCP =(TTree*)fPbPb->Get("Dtree");

	TH1F * h_D0Dca_2D = new TH1F("h_D0Dca_2D","h_D0Dca_2D",200,-0.1,0.1);

	

//	TH1F * h_decay = new TH1F("h_decay","h_decay",);

	TH1F * h_alpha = new TH1F("h_alpha","h_alpha",100,0,3.15);
  TH1F * h_alpha_2D = new TH1F("h_alpha_2D","h_alpha_2D",100,0,3.15);

	TCanvas *c1= new TCanvas("c1","c1",600,600);
	tMCP->Draw("D0DCA_2Dv1>>h_D0Dca_2D","pthatweight");
	h_D0Dca_2D->GetXaxis()->SetTitle("D0Dca 2D (cm)");	

	TCanvas *c2 = new TCanvas("c2","c2",600,600);
	tMCP->Draw("abs(Dalpha)>>h_alpha","pthatweight");
	tMCP->Draw("abs(Dalpha_2D)>>h_alpha_2D","pthatweight");

	h_alpha->GetXaxis()->SetTitle("angle (radian)");
	h_alpha->Draw();
	h_alpha_2D->SetLineColor(2);
	h_alpha_2D->Draw("SAME");

	TLegend *l2 = new TLegend(0.6,0.7,0.88,0.88);
	l2->AddEntry(h_alpha,"D alpha","l");	 
  l2->AddEntry(h_alpha_2D,"D alpha 2D","l");
	l2->SetBorderSize(0);
	l2->Draw();








}

