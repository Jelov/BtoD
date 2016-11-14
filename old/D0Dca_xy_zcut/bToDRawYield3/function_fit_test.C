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




void function_fit_test(){

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
	TFile* fPbPbMC = new TFile("bFeedDownPbPbMC_funfit.hist.root");
	TFile* fPbPbMBMC = new TFile("bFeedDownPbPbMBMC_funfit.hist.root");

	//  TFile* fPbPbMC = new TFile("bFeedDownPbPbMC.hist.root");
	//  TFile* fPbPbMBMC = new TFile("bFeedDownPbPbMBMC.hist.root");

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


//	TH1D *h_DcaData = (TH1D*)fDcaData->Get("D0DcaDatafitOut_pt5");

	const int nPtBins = 14;
	float ptBins[nPtBins+1] = {2.,3.,4.,5.,6.,8.,10.,12.5,15.0,20.,25.,30.,40.,60.,100};

  const int nBinY = 20;
  const Double_t binsY[nBinY+1] = {-0.0734,-0.0562,-0.0428,-0.0320,-0.0236,-0.0170,-0.0118,-0.0078,-0.0046,-0.002,0.0,0.002,0.0046,0.0078,0.0118,0.0170,0.0236,0.0320,0.0428,0.0562,0.0734};

  TFile *fDcaData = new TFile("bFeedDownResult.root");
  TH1D *h_DcaData[nPtBins];
//  TH1D *h_DcaData = (TH1D*)fDcaData->Get("D0DcaDatafitOut_pt5");


	RooBinning bin_dcaxy(nBinY,binsY);

	//	TH1D* h_MCP_DCAxy = new TH1D("h_MCP_DCAxy", "h_MCP_DCAxy", nBinY, binsY);
	//  TH1D* h_MCNP_DCAxy = new TH1D("h_MCNP_DCAxy", "h_MCNP_DCAxy", nBinY, binsY);


	hMCPSignal->GetXaxis()->SetRangeUser(8,10);
	hMCNPSignal->GetXaxis()->SetRangeUser(8,10);

	TH1D* h_MCP_DCAxy= (TH1D*)hMCPSignal->Project3D("y")->Clone("h_MCP_DCAxy");
	TH1D* h_MCNP_DCAxy= (TH1D*)hMCNPSignal->Project3D("y")->Clone("h_MCNP_DCAxy");


	TH1D* h_MCP_DCAxy_ptArr[nPtBins];
	TH1D* h_MCNP_DCAxy_ptArr[nPtBins];

	TCanvas *c_MCP_ptArr[nPtBins];
	TCanvas *c_MCNP_ptArr[nPtBins];

	double max,min;
	double sigmafit;

	TCanvas *c_MCP_gauss = new TCanvas("c_MCP_gauss","c_MCP_gauss",1000,600);
	c_MCP_gauss->Divide(5,3);

	TCanvas *c_MCP_gauss2 = new TCanvas("c_MCP_gauss2","c_MCP_gauss2",1000,600);
	c_MCP_gauss2->Divide(5,3);

	TCanvas *c_MCNP_gauss = new TCanvas("c_MCNP_gauss","c_MCNP_gauss",1000,600);
	c_MCNP_gauss->Divide(5,3);

	TCanvas *c_data[nPtBins];// = new TCanvas("c_data","c_data",600,600);


//		for(int iPtBins=0; iPtBins<nPtBins; iPtBins++)
	for(int iPtBins=1; iPtBins<2; iPtBins++)
	{
		// Fill the TH1D

		Float_t ptLow=ptBins[iPtBins];
		Float_t ptHigh=ptBins[iPtBins+1];

		hMCPSignal->GetXaxis()->SetRangeUser(ptLow,ptHigh);
		hMCNPSignal->GetXaxis()->SetRangeUser(ptLow,ptHigh);

		h_MCP_DCAxy_ptArr[iPtBins]= (TH1D*)hMCPSignal->Project3D("y")->Clone(Form("h_MCP_DCAxy_Dpt%.1fto%.1f",ptLow,ptHigh));
		h_MCNP_DCAxy_ptArr[iPtBins]= (TH1D*)hMCNPSignal->Project3D("y")->Clone(Form("h_MCNP_DCAxy_Dpt%.1fto%.1f",ptLow,ptHigh));


		// MCP fit and plot

		c_MCP_ptArr[iPtBins] = new TCanvas(Form("c_MCP_%i",iPtBins),Form("c_MCP_%i",iPtBins), 800,400 ); 	
		c_MCP_ptArr[iPtBins]->Divide(2,1);
		c_MCP_ptArr[iPtBins]->cd(1);		


		RooRealVar x("x","Dca_xy",-0.07,0.07);
		//  RooRealVar mean("mean","mean",0,-0.02,0.02);
		RooRealVar mean("mean","mean",0);

		RooRealVar sigma("sigma","sigma",0.003,0.0000001,0.02);
		RooGaussian gauss("gauss","gaussian PDF",x,mean,sigma);
		RooPlot* xframe = x.frame();

		RooDataHist h_MCP("h_MCP","h_MCP",RooArgList(x),h_MCP_DCAxy_ptArr[iPtBins]);

		gauss.fitTo(h_MCP);
		sigmafit=sigma.getVal();

		h_MCP.plotOn(xframe);

		gauss.plotOn(xframe,LineColor(2));
		gauss.paramOn(xframe);
		//	xframe->SetTitle("test Title");
		max = xframe->GetMaximum();
		min = xframe->GetMinimum();
		xframe->SetMaximum(max+0.2*(max-min));
		xframe->Draw();

		TLatex *tex_MCP= new TLatex(0.18,0.82,Form("Prompt D"));
		tex_MCP->SetNDC();
		tex_MCP->SetTextFont(42);
		tex_MCP->SetTextSize(0.035);
		tex_MCP->SetLineWidth(2);
		tex_MCP->Draw();
		TLatex *tex_MCPGauss= new TLatex(0.18,0.75,"Gaussian Fit");
		tex_MCPGauss->SetNDC();
		tex_MCPGauss->SetTextFont(42);
		tex_MCPGauss->SetTextSize(0.035);
		tex_MCPGauss->SetLineWidth(2);
		tex_MCPGauss->Draw();


		c_MCP_gauss->cd(iPtBins+1);
		xframe->Draw();
		if(iPtBins==0){
			TLatex *tex_MCP_Gauss = new TLatex(0.18,0.75,Form("Prompt D, Gauss"));
			tex_MCP_Gauss->SetNDC();
			tex_MCP_Gauss->SetTextFont(42);
			tex_MCP_Gauss->SetTextSize(0.035);
			tex_MCP_Gauss->SetLineWidth(2);
			tex_MCP_Gauss->Draw();
		}
		TLatex *tex_MCP_Gausspt = new TLatex(0.18,0.82,Form("%.1f<pt<%.1f",ptLow,ptHigh));
		tex_MCP_Gausspt->SetNDC();
		tex_MCP_Gausspt->SetTextFont(42);
		tex_MCP_Gausspt->SetTextSize(0.035);
		tex_MCP_Gausspt->SetLineWidth(2);
		tex_MCP_Gausspt->Draw();




		c_MCP_ptArr[iPtBins]->cd(2);

		RooRealVar ARatio("ARatio","ARatio",0.5,0,1);
		RooRealVar sigmaRatio("sigmaRatio","sigmaRatio",1.24,1.000001,100000);
		RooGenericPdf dgauss("dgauss","Double Gaussian","ARatio*exp(-pow((x-mean)/sigma,2)/2)+(1-ARatio)*exp(-pow((x-mean)/(sigma*sigmaRatio),2)/2)",RooArgSet(x,mean,sigma,ARatio,sigmaRatio));

		dgauss.fitTo(h_MCP);
		RooPlot* xframe2 = x.frame();
		h_MCP.plotOn(xframe2);
		dgauss.plotOn(xframe2);
		dgauss.paramOn(xframe2);
		max = xframe2->GetMaximum();
		min = xframe2->GetMinimum();
		xframe2->SetMaximum(max+0.2*(max-min));

		xframe2->Draw();

		TLatex *tex_MCPpt= new TLatex(0.18,0.82,Form("%.1f<D P_{T}<%.1f",ptLow,ptHigh));
		tex_MCPpt->SetNDC();
		tex_MCPpt->SetTextFont(42);
		tex_MCPpt->SetTextSize(0.035);
		tex_MCPpt->SetLineWidth(2);
		tex_MCPpt->Draw();
		TLatex *tex_MCPGauss2= new TLatex(0.18,0.75,"Double Gaussian Fit");
		tex_MCPGauss2->SetNDC();
		tex_MCPGauss2->SetTextFont(42);
		tex_MCPGauss2->SetTextSize(0.035);
		tex_MCPGauss2->SetLineWidth(2);
		tex_MCPGauss2->Draw();

		c_MCP_ptArr[iPtBins]->SaveAs(Form("function_plot/MCP_FunCom_pt%dto%d.pdf",(int)ptLow,(int)ptHigh));

		c_MCP_gauss2->cd(iPtBins+1);
		xframe2->Draw();
		if(iPtBins==0){
			TLatex *tex_MCP_Gauss2 = new TLatex(0.18,0.75,Form("Prompt D,Double Gauss"));
			tex_MCP_Gauss2->SetNDC();
			tex_MCP_Gauss2->SetTextFont(42);
			tex_MCP_Gauss2->SetTextSize(0.035);
			tex_MCP_Gauss2->SetLineWidth(2);
			tex_MCP_Gauss2->Draw();
		}
		TLatex *tex_MCP_Gauss2pt = new TLatex(0.18,0.82,Form("%.1f<pt<%.1f",ptLow,ptHigh));
		tex_MCP_Gauss2pt->SetNDC();
		tex_MCP_Gauss2pt->SetTextFont(42);
		tex_MCP_Gauss2pt->SetTextSize(0.035);
		tex_MCP_Gauss2pt->SetLineWidth(2);
		tex_MCP_Gauss2pt->Draw();



		/////////////////////
		// MCNP fit and plot 
		/////////////////////

		c_MCNP_ptArr[iPtBins] = new TCanvas(Form("c_MCNP_%i",iPtBins),Form("c_MCNP_%i",iPtBins), 800,800 ); 
		c_MCNP_ptArr[iPtBins]->Divide(2,2);
		c_MCNP_ptArr[iPtBins]->cd(1);


		//  RooRealVar dca("dca","dca_xy",-0.05,0.05);
		RooRealVar alpha("alpha","alpha",-100,-20000,-0.00001);
		RooGenericPdf gp("gp","Generic PDF","exp(abs(x)*alpha)",RooArgSet(x,alpha));

		RooRealVar mg("mg","mg",0);
		RooRealVar sg("sg","sg",sigmafit,0.0000001,0.1);
		RooGaussian gauss2("gauss2","gauss2",x,mg,sg);
		x.setBins(10000,"cache");
		//  RooFFTConvPdf gpxg("gpxg","exp (x) gauss",x,gp,gauss2);
		RooFFTConvPdf *gpxg = new RooFFTConvPdf("gpxg","exp (x) gauss",x,gp,gauss2);

		sg.setConstant(kTRUE);

		RooPlot * dcaframe = x.frame();
		//  RooDataHist h_MCNP("h_MCNP","h_MCNP",RooArgSet(dca),h_MCNP_DCAxy);
		RooDataHist h_MCNP("h_MCNP","h_MCNP",RooArgSet(x),h_MCNP_DCAxy);
		RooFitResult * fitres = gpxg->fitTo(h_MCNP);
		h_MCNP.plotOn(dcaframe);
		gpxg->plotOn(dcaframe);
		gpxg->paramOn(dcaframe);
		//  dcaframe2->GetXaxis()->SetTitle("set x title");
		max = dcaframe->GetMaximum();
		min = dcaframe->GetMinimum();
		dcaframe->SetMaximum(max+0.2*(max-min));

		dcaframe->Draw();
		cout<<"sg = "<<sg.getVal();

		TLatex *tex_MCNP= new TLatex(0.18,0.82,Form("Non Prompt D"));
		tex_MCNP->SetNDC();
		tex_MCNP->SetTextFont(42);
		tex_MCNP->SetTextSize(0.035);
		tex_MCNP->SetLineWidth(2);
		tex_MCNP->Draw();
		TLatex *tex_MCNPGauss= new TLatex(0.18,0.75,"Exp (x) Gaussian");
		tex_MCNPGauss->SetNDC();
		tex_MCNPGauss->SetTextFont(42);
		tex_MCNPGauss->SetTextSize(0.035);
		tex_MCNPGauss->SetLineWidth(2);
		tex_MCNPGauss->Draw();


		//	fitres->Print(); not work for unknown reason.


		c_MCNP_ptArr[iPtBins]->cd(3);
		RooPlot *dcaframe3= x.frame();
		sg.setConstant(kFALSE);
		gpxg->fitTo(h_MCNP);
		h_MCNP.plotOn(dcaframe3);
		gpxg->plotOn(dcaframe3);
		gpxg->paramOn(dcaframe3);
		dcaframe3->SetMaximum(max+0.2*(max-min));
		dcaframe3->Draw();

		TLatex *tex_MCNPGaussF= new TLatex(0.18,0.75,"Exp.(x)Gaus.");
		tex_MCNPGaussF->SetNDC();
		tex_MCNPGaussF->SetTextFont(42);
		tex_MCNPGaussF->SetTextSize(0.035);
		tex_MCNPGaussF->SetLineWidth(2);
		tex_MCNPGaussF->Draw();


		c_MCNP_gauss->cd(iPtBins+1);
		dcaframe3->Draw();
		if(iPtBins==0){
			TLatex *tex_MCNP_Gauss = new TLatex(0.18,0.75,Form("Non Prompt D, Gauss"));
			tex_MCNP_Gauss->SetNDC();
			tex_MCNP_Gauss->SetTextFont(42);
			tex_MCNP_Gauss->SetTextSize(0.035);
			tex_MCNP_Gauss->SetLineWidth(2);
			tex_MCNP_Gauss->Draw();
		}
		TLatex *tex_MCNP_Gausspt = new TLatex(0.18,0.82,Form("%.1f<pt<%.1f",ptLow,ptHigh));
		tex_MCNP_Gausspt->SetNDC();
		tex_MCNP_Gausspt->SetTextFont(42);
		tex_MCNP_Gausspt->SetTextSize(0.035);
		tex_MCNP_Gausspt->SetLineWidth(2);
		tex_MCNP_Gausspt->Draw();



		c_MCNP_ptArr[iPtBins]->cd(2);

		//  RooFFTConvPdf gpxg2("gpxg2","exp (x) gauss2",x,gp,dgauss); dgauss can not perform FFT
		RooNumConvPdf gpxg2("gpxg2","exp (x) gauss2",x,gp,dgauss);

		sigma.setConstant(kTRUE);
		ARatio.setConstant(kTRUE);
		sigmaRatio.setConstant(kTRUE);


		RooPlot *dcaframe2= x.frame();
		//	sg.setRange(0.0000001,0.1);
		gpxg2.fitTo(h_MCNP);
		h_MCNP.plotOn(dcaframe2);
		gpxg2.plotOn(dcaframe2);
		gpxg2.paramOn(dcaframe2);

		dcaframe2->SetMaximum(max+0.2*(max-min));
		dcaframe2->Draw();

		TLatex *tex_MCNPpt= new TLatex(0.18,0.82,Form("%.1f<D P_{T}<%.1f",ptLow,ptHigh));
		tex_MCNPpt->SetNDC();
		tex_MCNPpt->SetTextFont(42);
		tex_MCNPpt->SetTextSize(0.035);
		tex_MCNPpt->SetLineWidth(2);
		tex_MCNPpt->Draw();
		TLatex *tex_MCNPGauss2= new TLatex(0.18,0.75,"Exp (x) Double Gass.");
		tex_MCNPGauss2->SetNDC();
		tex_MCNPGauss2->SetTextFont(42);
		tex_MCNPGauss2->SetTextSize(0.035);
		tex_MCNPGauss2->SetLineWidth(2);
		tex_MCNPGauss2->Draw();



		// double exponential fit
		c_MCNP_ptArr[iPtBins]->cd(4);


/*
		c_MCNP_ptArr[iPtBins]->cd(4);
		sigma.setConstant(kFALSE);
		ARatio.setConstant(kFALSE);
		sigmaRatio.setConstant(kFALSE);

		RooPlot *dcaframe4= x.frame();
		//  sg.setRange(0.0000001,0.1);
		gpxg2.fitTo(h_MCNP);
		gpxg2.fitTo(h_MCNP);
		h_MCNP.plotOn(dcaframe4);
		gpxg2.plotOn(dcaframe4);
		gpxg2.paramOn(dcaframe4);

		dcaframe4->SetMaximum(max+0.2*(max-min));
		dcaframe4->Draw();

		TLatex *tex_MCNP2GaussF= new TLatex(0.18,0.75,"(x)Double Gauss;float");
		tex_MCNP2GaussF->SetNDC();
		tex_MCNP2GaussF->SetTextFont(42);
		tex_MCNP2GaussF->SetTextSize(0.035);
		tex_MCNP2GaussF->SetLineWidth(2);
		tex_MCNP2GaussF->Draw();

*/
		c_MCNP_ptArr[iPtBins]->SaveAs(Form("function_plot/MCNP_FunCom_pt%dto%d.pdf",(int)ptLow,(int)ptHigh));


		////////////////////
		///// fit to data //
		////////////////////

		c_data[iPtBins] = new TCanvas(Form("c_data_pt%i",iPtBins),Form("c_data_pt%i",iPtBins),800,800);
		c_data[iPtBins]->Divide(2,2);

		c_data[iPtBins]->cd(1); //plot MC prompt fit
//    gauss.plotOn(xframe,LineColor(2));
    xframe->Draw();
    tex_MCP->Draw();
    tex_MCPGauss->Draw();

    TLatex *tex_Datapt= new TLatex(0.18,0.68,Form("%.1f<D P_{T}<%.1f",ptLow,ptHigh));
    tex_Datapt->SetNDC();
    tex_Datapt->SetTextFont(42);
    tex_Datapt->SetTextSize(0.035);
    tex_Datapt->SetLineWidth(2);
    tex_Datapt->Draw();



		c_data[iPtBins]->cd(2);	//plot MC Non prompt fit
    dcaframe3->Draw();
    tex_MCNP->Draw();
    tex_MCNPGaussF->Draw();

		c_data[iPtBins]->cd(3); //plot data fit , parameter fixed

		h_DcaData[iPtBins]=(TH1D*)fDcaData->Get(Form("D0DcaDataOut_pt%i",iPtBins));
//		gPad->SetLogy();	// not work .... <THistPainter::PaintInit>: log scale requested with a negative argument
//		fixZeroBin(h_DcaData[iPtBins]);
//		double maxdatah = h_DcaData[iPtBins]->GetMaximum();
//		h_DcaData[iPtBins]->GetYaxis()->SetRangeUser(0.00001,maxdatah);

		RooDataHist h_Data("h_Data","h_Data",RooArgSet(x),h_DcaData[iPtBins]);

/* fraction fit
		RooRealVar pfrac("pfrac","pfrac",0.5,0,1);
//		RooRealVar npfrac("npfrac","npfrac",0.1);
		RooAddPdf sum("sum","P+NP",RooArgList(gauss,gp),RooArgList(pfrac));
*/

//		RooArgSet * comps=gpxp.getComponents();

		RooRealVar pNum("Prompt","Prompt",20000,0,100000);
		RooRealVar npNum("NonPrompt","NonPrompt",9000,0,100000);
		RooAddPdf sum("sum","P+NP exML",RooArgList(gauss,*gpxg),RooArgList(pNum,npNum));

		sigma.setConstant(kTRUE);
		alpha.setConstant(kTRUE);
		sg.setConstant(kTRUE);

//		sum.fitTo(h_Data);
		sum.fitTo(h_Data,Extended(kTRUE));	

		RooPlot* dataframe = x.frame();
		dataframe->SetMinimum(0.0001);
		h_Data.plotOn(dataframe,Binning(bin_dcaxy));

		sum.plotOn(dataframe,Components(RooArgSet(gauss,*gpxg)),LineColor(3));
		sum.plotOn(dataframe,Components(*gpxg),LineStyle(kDashed),LineColor(4));
    sum.plotOn(dataframe,Components(gauss),LineStyle(kDashed),LineColor(2));
		sum.paramOn(dataframe);

    max = dataframe->GetMaximum();
    min = dataframe->GetMinimum();
    dataframe->SetMaximum(max+0.2*(max-min));
		dataframe->Draw();	

    TLatex *tex_datafix= new TLatex(0.18,0.82,"Data, param. fix");
    tex_datafix->SetNDC();
    tex_datafix->SetTextFont(42);
    tex_datafix->SetTextSize(0.035);
    tex_datafix->SetLineWidth(2);
    tex_datafix->Draw();



		c_data[iPtBins]->cd(4);
		sigma.setConstant(kFALSE);
		alpha.setConstant(kFALSE);
		sg.setConstant(kFALSE);

		sum.fitTo(h_Data,Extended(kTRUE));		
    RooPlot* dataframe2 = x.frame();
    h_Data.plotOn(dataframe2,Binning(bin_dcaxy));
    sum.plotOn(dataframe2,Components(RooArgSet(gauss,*gpxg)),LineColor(3));
    sum.plotOn(dataframe2,Components(*gpxg),LineStyle(kDashed),LineColor(4));
    sum.plotOn(dataframe2,Components(gauss),LineStyle(kDashed),LineColor(2));
    sum.paramOn(dataframe2);

	  max = dataframe2->GetMaximum();
    min = dataframe2->GetMinimum();
    dataframe2->SetMaximum(max+0.2*(max-min));
    dataframe2->Draw();

    TLatex *tex_datafloat= new TLatex(0.18,0.82,"Data, param. float");
    tex_datafloat->SetNDC();
    tex_datafloat->SetTextFont(42);
    tex_datafloat->SetTextSize(0.035);
    tex_datafloat->SetLineWidth(2);
    tex_datafloat->Draw();


		c_data[iPtBins]->SaveAs(Form("function_plot/fitdata_pt%dto%d.pdf",(int)ptLow,(int)ptHigh));


	} // end for iPtBins

	c_MCP_gauss->SaveAs("function_plot/MCP_Gauss_Ptall.pdf");
	c_MCP_gauss2->SaveAs("function_plot/MCP_Gauss2_Ptall.pdf");
	c_MCNP_gauss->SaveAs("function_plot/MCNP_Gauss_Ptall.pdf");



	/*


		 TCanvas *c_DCA_xy = new TCanvas("c_DCA_xy","c_DCA_xy",600,600);
		 c_DCA_xy->cd();
		 h_MCP_DCAxy->SetLineColor(1);
		 h_MCP_DCAxy->Draw();
		 h_MCNP_DCAxy->SetLineColor(4);
		 h_MCNP_DCAxy->Draw("SAME");



		 TCanvas *c_MCP = new TCanvas("c_MCP","c_MCP",600,600);
		 c_MCP->cd();

		 TF1 *f_MCP = new TF1("f_MCP",&fun_MCP,-0.05,0.0,5);
	//	f_MCP->SetParameters(h_MCP_DCAxy->Integral(), 0, h_MCP_DCAxy->GetRMS());


	f_MCP->SetParameters(77770, 0.7, 0,0.002726,2);
	f_MCP->FixParameter(2,0);
	f_MCP->SetParLimits(1,0,1);
	f_MCP->SetParLimits(4,1,1000);
	cout<<"integral = "<<h_MCP_DCAxy->Integral()<<" , RMS = "<<h_MCP_DCAxy->GetRMS()<<endl;

	TFitResultPtr fitResult;
	fitResult = h_MCP_DCAxy->Fit("f_MCP","MR","",-0.05,0.05);
	int fitStatus=1;
	fitStatus= fitResult->Status();
	cout<<"fit precision: "<<TFitter::GetPrecision()<<"   status: "<<fitStatus<<endl;

	h_MCP_DCAxy->Draw();
	f_MCP->Draw("flsame");



	TCanvas *c_RoofitMCP = new TCanvas("c_RoofitMCP","c_RoofitMCP",800,800);
	c_RoofitMCP->Divide(2,2);
	c_RoofitMCP->cd(1);

	RooRealVar x("x","dca_xy",-0.05,0.05);
	//	RooRealVar mean("mean","mean",0,-0.02,0.02);
	RooRealVar mean("mean","mean",0);
	RooRealVar sigma("sigma","sigma",0.003,0.00001,0.02);
	RooGaussian gauss("gauss","gaussian PDF",x,mean,sigma);
	RooPlot* xframe = x.frame();

	RooDataHist h_MCP("h_MCP","h_MCP",RooArgList(x),h_MCP_DCAxy);

	gauss.fitTo(h_MCP);
	h_MCP.plotOn(xframe);
	gauss.plotOn(xframe);
	gauss.paramOn(xframe);
	xframe->Draw();

	c_RoofitMCP->cd(2);
	gPad->SetLogy();
	xframe->Draw();


	c_RoofitMCP->cd(3);
	RooRealVar ARatio("ARatio","ARatio",0.5,0,1);
	RooRealVar sigmaRatio("sigmaRatio","sigmaRatio",1.24,1.000001,100000);
	RooGenericPdf dgauss("dgauss","Double Gaussian","ARatio*exp(-pow((x-mean)/sigma,2)/2)+(1-ARatio)*exp(-pow((x-mean)/(sigma*sigmaRatio),2)/2)",RooArgSet(x,mean,sigma,ARatio,sigmaRatio));
	//	RooGenericPdf dgauss("dgauss","Double Gaussian", "exp(-pow((x-mean)/sigma,2)/2)" ,RooArgSet(x,mean,sigma));

	dgauss.fitTo(h_MCP);
	RooPlot* xframe2 = x.frame();
	h_MCP.plotOn(xframe2);
	dgauss.plotOn(xframe2);
	dgauss.paramOn(xframe2);
	xframe2->Draw();

	c_RoofitMCP->cd(4);
	gPad->SetLogy();
	xframe2->Draw();




	TCanvas *c_RoofitMCNP = new TCanvas("c_RoofitMCNP","c_RoofitMCNP",800,800);
	c_RoofitMCNP->Divide(2,2);
	c_RoofitMCNP->cd(1);

	RooRealVar dca("dca","dca_xy",-0.05,0.05);
	RooRealVar alpha("alpha","alpha",-100,-20000,-0.00001);
	RooGenericPdf gp("gp","Generic PDF","exp(abs(dca)*alpha)",RooArgSet(dca,alpha));
	RooPlot * dcaframe = dca.frame();

	RooDataHist h_MCNP("h_MCNP","h_MCNP",RooArgSet(dca),h_MCNP_DCAxy);
	gp.fitTo(h_MCNP);
	h_MCNP.plotOn(dcaframe);
	gp.plotOn(dcaframe);
	dcaframe->Draw();

	c_RoofitMCNP->cd(2);
	gPad->SetLogy();
	dcaframe->Draw();


	//	TCanvas *c_RoofitMCNP_Conv = new TCanvas("c_RoofitMCNP_Conv","c_RoofitMCNP_Conv",600,600);
	//  RooRealVar dca("dca","dca",-0.05,0.05);
	//  RooRealVar alpha("alpha","alpha",-100,-20000,-0.00001);
	//  RooGenericPdf gp("gp","Generic PDF","exp(abs(dca)*alpha)",RooArgSet(dca,alpha));

	c_RoofitMCNP->cd(3);	
	RooRealVar mg("mg","mg",0);
	RooRealVar sg("sg","sg",0.0001,0.0000001,0.1);
	RooGaussian gauss2("gauss2","gauss2",dca,mg,sg);
	dca.setBins(10000,"cache");
	RooFFTConvPdf gpxg("gpxg","exp (x) gauss",dca,gp,gauss2);


	RooPlot * dcaframe2 = dca.frame();
	//  RooDataHist h_MCNP("h_MCNP","h_MCNP",RooArgSet(dca),h_MCNP_DCAxy);
	gpxg.fitTo(h_MCNP);
	h_MCNP.plotOn(dcaframe2);
	gpxg.plotOn(dcaframe2);
	gpxg.paramOn(dcaframe2);
	//	dcaframe2->GetXaxis()->SetTitle("set x title");
	dcaframe2->Draw();

	c_RoofitMCNP->cd(4);
	gPad->SetLogy();
	dcaframe2->Draw();





	TCanvas *c_MCNP = new TCanvas("c_MCNP","c_MCNP",600,600);
	c_MCNP->cd();
	TF1 *f_MCNP = new TF1("f_MCNP",&fun_MCNP,-0.05,0.05,2);
	f_MCNP->SetParameters(1000,-3);

	TFitResultPtr fitResult_MCNP;
	fitResult_MCNP = h_MCNP_DCAxy->Fit("f_MCNP","MR","",-0.05,0.05);
	int fitStatus_MCNP=1;
	fitStatus_MCNP = fitResult_MCNP->Status();
	h_MCNP_DCAxy->Draw();
	f_MCNP->Draw("flsame");

	*/
		////
		cout<<"sigmafit ="<<sigmafit<<endl;

}
