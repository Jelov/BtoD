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

TH1F *background;

void histgen(){

   //generate the histogram background and save it to a file
   //background taken as linearly decreasing
   TF1 f1("f1","pol1",0,10);
   f1.SetParameters(5,-0.5);
   TH1F h("background","linear background",100,0,10);
	 h.Sumw2();
   h.FillRandom("f1",10000);
   TFile f("background.root","recreate");
   //save the background histogram
   h.Write();
   //superimpose a gaussian signal to the background histogram
   TF1 f2("f2","gaus",0,10);
   f2.SetParameters(1,6,0.5);
   h.FillRandom("f2",2000);
   h.SetName("result");
   h.Write();


}

Double_t ftotal(Double_t *x, Double_t *par) {
   Double_t xx = x[0];
   Int_t bin = background->GetXaxis()->FindBin(xx);
   Double_t br = par[3]*background->GetBinContent(bin);
   Double_t arg = (xx-par[1])/par[2];
   Double_t sr = par[0]*TMath::Exp(-0.5*arg*arg);

	 Double_t br2 = par[3]+par[4]*xx;

   return sr + br2;
}



void test_TF1_FitErr2(){

  gStyle->SetOptFit(1111);
  gStyle->SetOptStat(0);

   histgen();
   TFile *f = new TFile("background.root");
   background = (TH1F*)f->Get("background"); //pointer used in ftotal
   TH1F *result = (TH1F*)f->Get("result");
   TF1 *ftot = new TF1("ftot",ftotal,0,10,5);
   Double_t norm = result->GetMaximum();
//   ftot->SetParameters(0.5*norm,5,.2,norm);
   ftot->SetParameters(0.5*norm,6,.5,5,-0.5);
   ftot->SetParLimits(0,.3*norm,norm);
//	 ftot->FixParameter(1,6);
//	 ftot->FixParameter(2,0.5);
	 ftot->SetParLimits(1,5.5,6.5);
	 ftot->SetParLimits(2,0.25,1);
//	 ftot->SetParLimits(4,-0.01,-50);
   result->Fit("ftot","b");
   result->Fit("ftot","b");
   result->Fit("ftot","b");
   result->Fit("ftot");
   result->Fit("ftot");
   result->Fit("ftot");

	 TFitResult fitResult=result->Fit("ftot");

	 double 


	 TF1 *bgf = TF1("bgf","pol1",0,10);
	 



}
