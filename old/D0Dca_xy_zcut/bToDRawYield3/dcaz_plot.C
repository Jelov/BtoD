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


#include <RooFit.h>
#include <RooRealVar.h>
#include <RooDataHist.h>
#include <RooDataSet.h>
#include <RooHistPdf.h>
#include <RooPlot.h>
#include <RooAddPdf.h>
#include <RooGlobalFunc.h>
using namespace RooFit;


void fixZeroBin(TH1* h1){
	for(int ibin=1; ibin<=h1->GetNbinsX();ibin++){
		if(h1->GetBinContent(ibin)<=1e-20){
			 h1->SetBinContent(ibin,1e-20);
			 h1->SetBinError(ibin,0);
		}
	}
}

Double_t fun_MCP(Double_t *x, Double_t *par){

	double amp=par[0];
	double frac=par[1];
	double mean=par[2];
	double width1=par[3];
	double widthratio=par[4];

	//	Double_t fitval=amp1*TMath::Gaus(x[0],mean1,width1,kTRUE); 
	//  Double_t fitval=amp*TMath::Gaus(x[0],mean1,width1);
	Double_t fitval=amp*(frac*TMath::Gaus(x[0],mean,width1)+(1-frac)*TMath::Gaus(x[0],mean,width1*widthratio));	
	return fitval;

}

Double_t fun_MCNP(Double_t *x, Double_t *par){

	Double_t fitval= par[0]*exp(par[1]*fabs(x[0]));

	return fitval;

}
/*
	 Double_t fun_MCNP_smear(Double_t *X, Double_t *par){

	 double amp=par[0];
	 double 



	 }
	 */


void normalize(TH1D* h)
{
	h->Sumw2();
	for (int i=1;i<=h->GetNbinsX();i++)
	{
		Float_t val=h->GetBinContent(i);
		Float_t valErr=h->GetBinError(i);
		h->SetBinContent(i,val/h->GetBinWidth(i));
		h->SetBinError(i,valErr/h->GetBinWidth(i));
	}
	h->Scale(1./h->Integral(0,100,"width"));
}

void divideBinWidth(TH1* h)
{
  h->Sumw2();
  for(int i=1;i<=h->GetNbinsX();i++)
    {
      Float_t val = h->GetBinContent(i);
      Float_t valErr = h->GetBinError(i);
      val/=h->GetBinWidth(i);
      valErr/=h->GetBinWidth(i);
      h->SetBinContent(i,val);
      h->SetBinError(i,valErr);
    }
  h->GetXaxis()->CenterTitle();
  h->GetYaxis()->CenterTitle();
}

void SetHistStyle(TH1* h,int color = 1, int markerstyle =24){
	h->SetLineColor(color);
	h->SetMarkerColor(color);
	h->SetMarkerStyle(markerstyle);
}



void dcaz_plot(){

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
//	TFile* fPbPbMC = new TFile("bFeedDownPbPbMC_funfit.hist.root");
//	TFile* fPbPbMBMC = new TFile("bFeedDownPbPbMBMC_funfit.hist.root");

	  TFile* fPbPbMC = new TFile("bFeedDownPbPbMC.hist.root");
	  TFile* fPbPbMBMC = new TFile("bFeedDownPbPbMBMC.hist.root");

/*
	TH3D* hDataPbPb = (TH3D*)fPbPb->Get("hData");
	TH3D* hSidebandPbPb = (TH3D*)fPbPb->Get("hSideband");
	TH3D* hDataPbPbMB = (TH3D*)fPbPbMB->Get("hData");
	TH3D* hSidebandPbPbMB = (TH3D*)fPbPbMB->Get("hSideband");
	TH3D* hPtMD0DcaPbPb = (TH3D*)fPbPb->Get("hPtMD0Dca");
	TH3D* hPtMD0DcaPbPbMB = (TH3D*)fPbPbMB->Get("hPtMD0Dca");
*/

	TH3D* hMCPSignalPbPb = (TH3D*)fPbPbMC->Get("hMCPSignal");
	TH3D* hMCNPSignalPbPb = (TH3D*)fPbPbMC->Get("hMCNPSignal");
	TH3D* hMCPSignalPbPbMB = (TH3D*)fPbPbMBMC->Get("hMCPSignal");
	TH3D* hMCNPSignalPbPbMB = (TH3D*)fPbPbMBMC->Get("hMCNPSignal");
	TH3D* hPtMD0DcaMCPSignalPbPb = (TH3D*)fPbPbMC->Get("hPtMD0DcaMCPSignal");
	TH3D* hPtMD0DcaMCPSwappedPbPb = (TH3D*)fPbPbMC->Get("hPtMD0DcaMCPSwapped");
	TH3D* hPtMD0DcaMCPSignalPbPbMB =(TH3D*)fPbPbMBMC->Get("hPtMD0DcaMCPSignal");
	TH3D* hPtMD0DcaMCPSwappedPbPbMB = (TH3D*)fPbPbMBMC->Get("hPtMD0DcaMCPSwapped");

/*
	TH3D* hData = (TH3D*)hDataPbPb->Clone("hData");
	hData->Sumw2();
	hData->Add(hDataPbPbMB);

	TH3D* hSideband = (TH3D*)hSidebandPbPb->Clone("hSideband");
	hSideband->Sumw2();
	hSideband->Add(hSidebandPbPbMB);

	TH3D* hPtMD0Dca = (TH3D*)hPtMD0DcaPbPb->Clone("hPtMD0Dca");
	hPtMD0Dca->Sumw2();
	hPtMD0Dca->Add(hPtMD0DcaPbPbMB);

*/
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


//	TH1D *h_DcaData = (TH1D*)fDcaData->Get("D0DcaDatafitOut_pt5");

//	const int nPtBins = 14;
//	float ptBins[nPtBins+1] = {2.,3.,4.,5.,6.,8.,10.,12.5,15.0,20.,25.,30.,40.,60.,100};

  const int nPtBins = 9;
  float ptBins[nPtBins+1] = {2.,4.,6.,8.,10.,12.5,20.,40.,60.,100};

  const int nBinY = 20;
  const Double_t binsY[nBinY+1] = {-0.0734,-0.0562,-0.0428,-0.0320,-0.0236,-0.0170,-0.0118,-0.0078,-0.0046,-0.002,0.0,0.002,0.0046,0.0078,0.0118,0.0170,0.0236,0.0320,0.0428,0.0562,0.0734};

  const int nBinZ = 40;
  Float_t binsZ[nBinZ+1];
  for(int i=0; i<=nBinZ; i++){
    binsZ[i]=i*0.001;
  }

	RooBinning bin_dcaxy(nBinY,binsY);

	TH1D* h_MCP_DCAxy= (TH1D*)hMCPSignal->Project3D("y")->Clone("h_MCP_DCAxy");
	TH1D* h_MCNP_DCAxy= (TH1D*)hMCNPSignal->Project3D("y")->Clone("h_MCNP_DCAxy");
/*
	hMCPSignal->GetZaxis()->SetRangeUser(0,0.08);
	hMCNPSignal->GetZaxis()->SetRangeUser(0,0.08);
*/
	cout<<"check 1"<<endl;


// start to fill and plot

	for (int iPtBins =0; iPtBins<nPtBins; iPtBins++)
//	for(int iPtBins =2; iPtBins<4; iPtBins++)
{

	double ptLow = ptBins[iPtBins];
	double ptHigh = ptBins[iPtBins+1];

	hMCPSignal->GetXaxis()->SetRangeUser(ptLow,ptHigh);
  hMCNPSignal->GetXaxis()->SetRangeUser(ptLow,ptHigh);	

	TH1D* h_MCP_DCAz = (TH1D*)hMCPSignal->Project3D("z")->Clone("h_MCP_DCAz");
  TH1D* h_MCNP_DCAz = (TH1D*)hMCNPSignal->Project3D("z")->Clone("h_MCNP_DCAz");

	cout<<"create TH1D"<<endl;
	TH1D* h_MCP_DCAzEff= new TH1D("h_MCP_DCAzEff","h_MCP_DCAzEff",nBinZ,binsZ);
	cout<<"check 2"<<endl;
  TH1D* h_MCNP_DCAzEff= new TH1D("h_MCNP_DCAzEff","h_MCNP_DCAzEff",nBinZ,binsZ);

	TCanvas * c_DCAz = new TCanvas("c_DCAz","c_DCAz",800,800);
	c_DCAz->Divide(2,2);
	c_DCAz->cd(1);

	h_MCP_DCAz->Scale(1/h_MCP_DCAz->Integral());
	h_MCP_DCAz->SetLineColor(2);
	h_MCP_DCAz->GetXaxis()->SetRangeUser(0,0.04);
	h_MCP_DCAz->Draw();

	h_MCNP_DCAz->Scale(1/h_MCNP_DCAz->Integral());
	h_MCNP_DCAz->SetLineColor(4);
  h_MCNP_DCAz->GetXaxis()->SetRangeUser(0,0.04);
	h_MCNP_DCAz->Draw("same");

	TLegend *l_DCAz = new TLegend(0.65,0.75,0.88,0.88);
	l_DCAz->AddEntry(h_MCP_DCAz,"Prompt D","l");
  l_DCAz->AddEntry(h_MCNP_DCAz,"NonPrompt D","l");
	l_DCAz->SetBorderSize(0);
	l_DCAz->Draw();

	TLatex *tex_pt = new TLatex(0.18,0.82,Form("%.1f < Dpt < %.1f",ptLow,ptHigh));
	tex_pt->SetNDC();
	tex_pt->SetTextSize(0.04);
	tex_pt->Draw();

	c_DCAz->cd(3);
	gPad->SetLogy();	 
	h_MCP_DCAz->Draw();
  h_MCNP_DCAz->Draw("same");
  l_DCAz->Draw();

	cout<<"check 3"<<endl;

	c_DCAz->cd(2);

	h_MCP_DCAzEff->SetBinContent(1,1);
	h_MCNP_DCAzEff->SetBinContent(1,1);

	for (int iBinZ = 2; iBinZ<=40; iBinZ++){
//	h_MCP_DCAzEff->SetBinContent(iBinZ,1-h_MCP_DCAz->Integral(1,iBinZ));
  h_MCP_DCAzEff->SetBinContent(iBinZ,h_MCP_DCAzEff->GetBinContent(iBinZ-1)-h_MCP_DCAz->GetBinContent(iBinZ-1));

	// cout<<"check 4"<<endl;
//  h_MCNP_DCAzEff->SetBinContent(iBinZ,1-h_MCNP_DCAz->Integral(1,iBinZ));
  h_MCNP_DCAzEff->SetBinContent(iBinZ,h_MCNP_DCAzEff->GetBinContent(iBinZ-1)-h_MCNP_DCAz->GetBinContent(iBinZ-1));
	// cout<<"check 5"<<endl;
}
	// TCanvas *c_DcaZeff = new TCanvas("c_DcaZeff","c_DcaZeff",800,800);
	// c_DcaZeff->cd();
	
	cout<<"check 6"<<endl;
	h_MCP_DCAzEff->SetLineColor(2);
//	h_MCP_DCAzEff->Draw();

	h_MCNP_DCAzEff->SetLineColor(4);
	h_MCNP_DCAzEff->Draw("SAME");
	h_MCP_DCAzEff->Draw("SAME");

	TLegend *l_DCAzEff = new TLegend(0.62,0.65,0.88,0.88);
	l_DCAzEff->AddEntry((TObject*)0,"eff for DcaZ cut","");
	l_DCAzEff->AddEntry(h_MCP_DCAzEff,"Prompt D","l");
  l_DCAzEff->AddEntry(h_MCNP_DCAzEff,"NonPrompt D","l");
	l_DCAzEff->SetBorderSize(0);
	l_DCAzEff->Draw();	


	c_DCAz->cd(4);
	gPad->SetLogy();

	TH1D *dcaZEff_ratio = (TH1D*)h_MCNP_DCAzEff->Clone("dcaZEff_ratio");
	dcaZEff_ratio->Divide(h_MCP_DCAzEff);
	dcaZEff_ratio->Draw();

/*
	TLegend *l_effRatio = new TLegend(0.55,0.20,0.88,0.45);
	l_effRatio->AddEntry((TObject*)0,"eff NonP/Prompt","");
	l_effRatio->SetBorderSize(0);
	l_effRatio->Draw();	
*/

	TLatex *tex_effRatio = new TLatex(0.60,0.22,"eff NonP/Prompt");
  tex_effRatio->SetNDC();
  tex_effRatio->SetTextSize(0.04);
  tex_effRatio->Draw();



	
	c_DCAz->SaveAs(Form("plot_DcaZ/dcaZ_pt%ito%i.pdf",(int)ptLow,(int)ptHigh));

	}


} // end of main
