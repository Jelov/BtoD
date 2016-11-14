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



void function_fit(){

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

//	const int nPtBins = 14;
//	float ptBins[nPtBins+1] = {2.,3.,4.,5.,6.,8.,10.,12.5,15.0,20.,25.,30.,40.,60.,100};

  const int nPtBins = 9;
  float ptBins[nPtBins+1] = {2.,4.,6.,8.,10.,12.5,20.,40.,60.,100};

  const int nBinY = 20;
  const Double_t binsY[nBinY+1] = {-0.0734,-0.0562,-0.0428,-0.0320,-0.0236,-0.0170,-0.0118,-0.0078,-0.0046,-0.002,0.0,0.002,0.0046,0.0078,0.0118,0.0170,0.0236,0.0320,0.0428,0.0562,0.0734};

  TFile *fDcaData = new TFile("bFeedDownResult.root");
  TH1D *h_DcaData[nPtBins];
//  TH1D *h_DcaData = (TH1D*)fDcaData->Get("D0DcaDatafitOut_pt5");


	RooBinning bin_dcaxy(nBinY,binsY);

	//	TH1D* h_MCP_DCAxy = new TH1D("h_MCP_DCAxy", "h_MCP_DCAxy", nBinY, binsY);
	//  TH1D* h_MCNP_DCAxy = new TH1D("h_MCNP_DCAxy", "h_MCNP_DCAxy", nBinY, binsY);

	TFile *fout= new TFile("function_fit_result.root","RECREATE");
	TH1D *h_PromptYield_fix = new TH1D("h_PromptYield_fix","h_PromptYield_fix",nPtBins,ptBins);
  TH1D *h_NonPromptYield_fix = new TH1D("h_NonPromptYield_fix","h_NonPromptYield_fix",nPtBins,ptBins);
	TH1D *h_NonPromptFraction_fix= new TH1D("h_NonPromptFraction_fix","h_NonPromptFraction_fix",nPtBins,ptBins);

  TH1D *h_PromptYield_float = new TH1D("h_PromptYield_float","h_PromptYield_float",nPtBins,ptBins);
  TH1D *h_NonPromptYield_float = new TH1D("h_NonPromptYield_float","h_NonPromptYield_float",nPtBins,ptBins);
  TH1D *h_NonPromptFraction_float= new TH1D("h_NonPromptFraction_float","h_NonPromptFraction_float",nPtBins,ptBins);

	


	hMCPSignal->GetXaxis()->SetRangeUser(8,10);
	hMCNPSignal->GetXaxis()->SetRangeUser(8,10);

	TH1D* h_MCP_DCAxy= (TH1D*)hMCPSignal->Project3D("y")->Clone("h_MCP_DCAxy");
	TH1D* h_MCNP_DCAxy= (TH1D*)hMCNPSignal->Project3D("y")->Clone("h_MCNP_DCAxy");


	TH1D* h_MCP_DCAxy_ptArr[nPtBins];
	TH1D* h_MCNP_DCAxy_ptArr[nPtBins];

	TCanvas *c_MCP_ptArr[nPtBins];
	TCanvas *c_MCNP_ptArr[nPtBins];

	double max,min;
	double MCPsigmaVal;

	TCanvas *c_MCP_gauss = new TCanvas("c_MCP_gauss","c_MCP_gauss",1000,600);
	c_MCP_gauss->Divide(5,3);

	TCanvas *c_MCP_gauss2 = new TCanvas("c_MCP_gauss2","c_MCP_gauss2",1000,600);
	c_MCP_gauss2->Divide(5,3);

	TCanvas *c_MCNP_gauss = new TCanvas("c_MCNP_gauss","c_MCNP_gauss",1000,600);
	c_MCNP_gauss->Divide(5,3);

	TCanvas *c_data[nPtBins];// = new TCanvas("c_data","c_data",600,600);


		for(int iPtBins=0; iPtBins<nPtBins; iPtBins++)
//	for(int iPtBins=1; iPtBins<2; iPtBins++)
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
		RooGaussian MCP_pdf("gauss","gaussian PDF",x,mean,sigma);
		RooPlot* MCP_frame = x.frame();

		RooDataHist h_MCP("h_MCP","h_MCP",RooArgList(x),h_MCP_DCAxy_ptArr[iPtBins]);

		MCP_pdf.fitTo(h_MCP);
		MCPsigmaVal=sigma.getVal();

		h_MCP.plotOn(MCP_frame,Binning(bin_dcaxy));


		MCP_pdf.plotOn(MCP_frame,LineColor(2));
		MCP_pdf.paramOn(MCP_frame);
		//	MCP_frame->SetTitle("test Title");
		max = MCP_frame->GetMaximum();
		min = MCP_frame->GetMinimum();
		MCP_frame->SetMaximum(max+0.2*(max-min));
		MCP_frame->Draw();

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
		MCP_frame->Draw();
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



/*
		c_MCP_ptArr[iPtBins]->cd(2);

		RooRealVar ARatio("ARatio","ARatio",0.5,0,1);
		RooRealVar sigmaRatio("sigmaRatio","sigmaRatio",1.24,1.000001,100000);
		RooGenericPdf dgauss("dgauss","Double Gaussian","ARatio*exp(-pow((x-mean)/sigma,2)/2)+(1-ARatio)*exp(-pow((x-mean)/(sigma*sigmaRatio),2)/2)",RooArgSet(x,mean,sigma,ARatio,sigmaRatio));

		dgauss.fitTo(h_MCP);
		RooPlot* MCP_frame2 = x.frame();
		h_MCP.plotOn(MCP_frame2);
		dgauss.plotOn(MCP_frame2);
		dgauss.paramOn(MCP_frame2);
		max = MCP_frame2->GetMaximum();
		min = MCP_frame2->GetMinimum();
		MCP_frame2->SetMaximum(max+0.2*(max-min));

		MCP_frame2->Draw();

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

		c_MCP_ptArr[iPtBins]->SaveAs(Form("plots_functionfit/MCP_FunCom_pt%dto%d.pdf",(int)ptLow,(int)ptHigh));

		c_MCP_gauss2->cd(iPtBins+1);
		MCP_frame2->Draw();
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
*/


		/////////////////////
		// MCNP fit and plot 
		/////////////////////

		c_MCNP_ptArr[iPtBins] = new TCanvas(Form("c_MCNP_%i",iPtBins),Form("c_MCNP_%i",iPtBins), 800,800 ); 
		c_MCNP_ptArr[iPtBins]->Divide(2,2);
		c_MCNP_ptArr[iPtBins]->cd(1);


    gPad->SetLogy();

		//  RooRealVar dca("dca","dca_xy",-0.05,0.05);
		RooRealVar alpha("alpha","alpha",-100,-20000,-0.00001);
		RooGenericPdf gp("gp","Generic PDF","exp(abs(x)*alpha)",RooArgSet(x,alpha));

		RooRealVar mg("mg","mg",0);
		RooRealVar sg("sg","sg",MCPsigmaVal,0.0000001,0.1);
		RooGaussian gauss2("gauss2","gauss2",x,mg,sg);
		x.setBins(10000,"cache");
		//  RooFFTConvPdf gpxg("gpxg","exp (x) gauss",x,gp,gauss2);
		RooFFTConvPdf *MCNP_pdf = new RooFFTConvPdf("MCNP_pdf","exp (x) gauss",x,gp,gauss2);

//		sg.setConstant(kTRUE);

		RooPlot * MCNP_frame = x.frame();
		//  RooDataHist h_MCNP("h_MCNP","h_MCNP",RooArgSet(dca),h_MCNP_DCAxy);
		RooDataHist h_MCNP("h_MCNP","h_MCNP",RooArgSet(x),h_MCNP_DCAxy_ptArr[iPtBins]);
		RooFitResult * fitres = MCNP_pdf->fitTo(h_MCNP);
		h_MCNP.plotOn(MCNP_frame,Binning(bin_dcaxy));
		MCNP_pdf->plotOn(MCNP_frame);
		MCNP_pdf->paramOn(MCNP_frame);
		//  MCNP_frame2->GetXaxis()->SetTitle("set x title");
		max = MCNP_frame->GetMaximum();
		min = MCNP_frame->GetMinimum();
//		MCNP_frame->SetMaximum(max+0.2*(max-min));
		MCNP_frame->SetMaximum(max*10);
		MCNP_frame->SetMinimum(0.5);
		MCNP_frame->Draw();
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

    TLatex *tex_MCNP_Gausspt = new TLatex(0.18,0.68,Form("%.1f<pt<%.1f",ptLow,ptHigh));
    tex_MCNP_Gausspt->SetNDC();
    tex_MCNP_Gausspt->SetTextFont(42);
    tex_MCNP_Gausspt->SetTextSize(0.035);
    tex_MCNP_Gausspt->SetLineWidth(2);
    tex_MCNP_Gausspt->Draw();



		// test other function
		c_MCNP_ptArr[iPtBins]->cd(2);
    gPad->SetLogy();
	
		RooRealVar power_a("power_a","power_a",10,0.000001,100000);
		RooRealVar power_n("power_n","power_n",3,0.001,100000);	
		RooGenericPdf power_pdf("power_pdf","power_odf","1/pow((1+power_a*abs(x)),power_n)",RooArgSet(x,power_a,power_n)); 
	
		RooPlot * MCNP_frame2 = x.frame();
		power_pdf.fitTo(h_MCNP);
		h_MCNP.plotOn(MCNP_frame2,Binning(bin_dcaxy));
		power_pdf.plotOn(MCNP_frame2);
		power_pdf.paramOn(MCNP_frame2);
		MCNP_frame2->SetMaximum(max*10);	
		MCNP_frame2->SetMinimum(0.5);
		MCNP_frame2->Draw();

    TLatex *tex_MCNPpower= new TLatex(0.18,0.75,"1/(1+a*x)^{n}");
    tex_MCNPpower->SetNDC();
    tex_MCNPpower->SetTextFont(42);
    tex_MCNPpower->SetTextSize(0.035);
    tex_MCNPpower->SetLineWidth(2);
    tex_MCNPpower->Draw();

	

		c_MCNP_ptArr[iPtBins]->cd(3);
		    gPad->SetLogy();
		RooRealVar twoExpA("twoExpA","twoExpA",-100,-100000,-10);
		RooRealVar twoExpB("twoExpB","twoExpB",-10,-300,-0.01);
		RooRealVar twoExpAfrac("twoExpAfrac","twoExpAfrac",0.5,0.0,1.0);
		RooGenericPdf twoExp_pdf("twoExp_pdf","twoExp_pdf","twoExpAfrac*exp(twoExpA*abs(x))+(1-twoExpAfrac)*exp(twoExpB*abs(x))",RooArgSet(x,twoExpA,twoExpB,twoExpAfrac));

		RooPlot *MCNP_frame3 = x.frame();
		twoExp_pdf.fitTo(h_MCNP);
		h_MCNP.plotOn(MCNP_frame3,Binning(bin_dcaxy));
		twoExp_pdf.plotOn(MCNP_frame3);
		twoExp_pdf.paramOn(MCNP_frame3);
		MCNP_frame3->SetMaximum(max*10);
		MCNP_frame3->SetMinimum(0.5);
		MCNP_frame3->Draw();

    TLatex *tex_MCNPtwoExp= new TLatex(0.18,0.75,"A*exp1+(1-A)exp2 ");
    tex_MCNPtwoExp->SetNDC();
    tex_MCNPtwoExp->SetTextFont(42);
    tex_MCNPtwoExp->SetTextSize(0.035);
    tex_MCNPtwoExp->SetLineWidth(2);
    tex_MCNPtwoExp->Draw();


/*
		c_MCNP_ptArr[iPtBins]->cd(4);
		gPad->SetLogy();

		RooRealVar doubleExpA("doubleExpA","doubleExpA",-100,-10000,-0.00001);
		RooRealVar doubleExpB("doubleExpB","doubleExpB",-1,-5000,-0.000001);
		RooGenericPdf doubleExp_pdf("doubleExp_pdf","doubleExp_pdf","exp(doubleExpA*exp(doubleExpB*abs(x)))",RooArgSet(x,doubleExpA,doubleExpB));

    RooPlot *MCNP_frame4 = x.frame();
    doubleExp_pdf.fitTo(h_MCNP);
    h_MCNP.plotOn(MCNP_frame4,Binning(bin_dcaxy));
    doubleExp_pdf.plotOn(MCNP_frame4);
    doubleExp_pdf.paramOn(MCNP_frame4);
    MCNP_frame4->SetMaximum(max*10);
    MCNP_frame4->SetMinimum(0.5);
    MCNP_frame4->Draw();

*/
    c_MCNP_ptArr[iPtBins]->SaveAs(Form("plots_functionfit/MCNP_FunCom_pt%dto%d.pdf",(int)ptLow,(int)ptHigh));
		

		//	fitres->Print(); not work for unknown reason.

/*
		c_MCNP_ptArr[iPtBins]->cd(3);
		RooPlot *MCNP_frame3= x.frame();
		sg.setConstant(kFALSE);
		gpxg->fitTo(h_MCNP);
		h_MCNP.plotOn(MCNP_frame3);
		gpxg->plotOn(MCNP_frame3);
		gpxg->paramOn(MCNP_frame3);
		MCNP_frame3->SetMaximum(max+0.2*(max-min));
		MCNP_frame3->Draw();

		TLatex *tex_MCNPGaussF= new TLatex(0.18,0.75,"Exp.(x)Gaus.");
		tex_MCNPGaussF->SetNDC();
		tex_MCNPGaussF->SetTextFont(42);
		tex_MCNPGaussF->SetTextSize(0.035);
		tex_MCNPGaussF->SetLineWidth(2);
		tex_MCNPGaussF->Draw();


		c_MCNP_gauss->cd(iPtBins+1);
		MCNP_frame3->Draw();
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


		RooPlot *MCNP_frame2= x.frame();
		//	sg.setRange(0.0000001,0.1);
		gpxg2.fitTo(h_MCNP);
		h_MCNP.plotOn(MCNP_frame2);
		gpxg2.plotOn(MCNP_frame2);
		gpxg2.paramOn(MCNP_frame2);

		MCNP_frame2->SetMaximum(max+0.2*(max-min));
		MCNP_frame2->Draw();

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

*/
/*
		c_MCNP_ptArr[iPtBins]->cd(4);
		sigma.setConstant(kFALSE);
		ARatio.setConstant(kFALSE);
		sigmaRatio.setConstant(kFALSE);

		RooPlot *MCNP_frame4= x.frame();
		//  sg.setRange(0.0000001,0.1);
		gpxg2.fitTo(h_MCNP);
		gpxg2.fitTo(h_MCNP);
		h_MCNP.plotOn(MCNP_frame4);
		gpxg2.plotOn(MCNP_frame4);
		gpxg2.paramOn(MCNP_frame4);

		MCNP_frame4->SetMaximum(max+0.2*(max-min));
		MCNP_frame4->Draw();

		TLatex *tex_MCNP2GaussF= new TLatex(0.18,0.75,"(x)Double Gauss;float");
		tex_MCNP2GaussF->SetNDC();
		tex_MCNP2GaussF->SetTextFont(42);
		tex_MCNP2GaussF->SetTextSize(0.035);
		tex_MCNP2GaussF->SetLineWidth(2);
		tex_MCNP2GaussF->Draw();

*/

//		c_MCNP_ptArr[iPtBins]->SaveAs(Form("plots_functionfit/MCNP_FunCom_pt%dto%d.pdf",(int)ptLow,(int)ptHigh));


		////////////////////
		///// fit to data //
		////////////////////

		c_data[iPtBins] = new TCanvas(Form("c_data_pt%i",iPtBins),Form("c_data_pt%i",iPtBins),1200,800);
		c_data[iPtBins]->Divide(3,2);

		c_data[iPtBins]->cd(1); //plot MC prompt fit
		gPad->SetLogy();
		MCP_frame->SetMaximum(MCP_frame->GetMaximum()*10);
		MCP_frame->SetMinimum(1);
//    gauss.plotOn(MCP_frame,LineColor(2));
    MCP_frame->Draw();
    tex_MCP->Draw();
    tex_MCPGauss->Draw();

    TLatex *tex_Datapt= new TLatex(0.18,0.68,Form("%.1f<D P_{T}<%.1f",ptLow,ptHigh));
    tex_Datapt->SetNDC();
    tex_Datapt->SetTextFont(42);
    tex_Datapt->SetTextSize(0.035);
    tex_Datapt->SetLineWidth(2);
    tex_Datapt->Draw();



		c_data[iPtBins]->cd(4);	//plot MC Non prompt fit
		gPad->SetLogy();

		MCNP_frame2->Draw();
		tex_MCNPpower->Draw();
		tex_MCNP->Draw();
/*
		MCNP_frame->SetMaximum(MCNP_frame->GetMaximum()*10);
		MCNP_frame->SetMinimum(1);
    MCNP_frame->Draw();
    tex_MCNP->Draw();
    TLatex *tex_MCNPGaussF= new TLatex(0.18,0.75,"Exp.(x)Gaus.");
    tex_MCNPGaussF->SetNDC();
    tex_MCNPGaussF->SetTextFont(42);
    tex_MCNPGaussF->SetTextSize(0.035);
    tex_MCNPGaussF->SetLineWidth(2);
    tex_MCNPGaussF->Draw();
*/
		c_data[iPtBins]->cd(2); //plot data fit , parameter fixed

		h_DcaData[iPtBins]=(TH1D*)fDcaData->Get(Form("D0DcaDataOut_pt%i",iPtBins));
/*
		TCanvas *c_dcadata = new TCanvas("c_dcadta");
		c_dcadata->cd();
		h_DcaData->

		c_data[iPtBins]->cd(3);
*/
//		gPad->SetLogy();	// not work .... <THistPainter::PaintInit>: log scale requested with a negative argument
//		fixZeroBin(h_DcaData[iPtBins]);
//		double maxdatah = h_DcaData[iPtBins]->GetMaximum();
//		h_DcaData[iPtBins]->GetYaxis()->SetRangeUser(0.00001,maxdatah);
//		h_DcaData[iPtBins]->SetMinimum(0.001);

		RooDataHist h_Data("h_Data","h_Data",RooArgSet(x),h_DcaData[iPtBins]);

/* fraction fit
		RooRealVar pfrac("pfrac","pfrac",0.5,0,1);
//		RooRealVar npfrac("npfrac","npfrac",0.1);
		RooAddPdf MCDCAmix_pdf("MCDCAmix_pdf","P+NP",RooArgList(gauss,gp),RooArgList(pfrac));
*/

//		RooArgSet * comps=gpxp.getComponents();

		RooRealVar pNum("Prompt","Prompt",20000,0,100000);
		RooRealVar npNum("NonPrompt","NonPrompt",9000,0,100000);

//		RooAddPdf MCDCAmix_pdf("MCDCAmix_pdf","P+NP exML",RooArgList(MCP_pdf,*MCNP_pdf),RooArgList(pNum,npNum));
		RooAddPdf MCDCAmix_pdf("MCDCAmix_pdf","P+NP exML",RooArgList(MCP_pdf,power_pdf),RooArgList(pNum,npNum));

		sigma.setConstant(kTRUE);
		power_a.setConstant(kTRUE);
		power_n.setConstant(kTRUE);

//		alpha.setConstant(kTRUE);
//		sg.setConstant(kTRUE);

//		MCDCAmix_pdf.fitTo(h_Data);
		MCDCAmix_pdf.fitTo(h_Data,Extended(kTRUE));	

		RooPlot* data_frame = x.frame();
		h_Data.plotOn(data_frame,Binning(bin_dcaxy));

		MCDCAmix_pdf.plotOn(data_frame,Components(RooArgSet(MCP_pdf,power_pdf)),LineColor(3));
		MCDCAmix_pdf.plotOn(data_frame,Components(power_pdf),LineStyle(kDashed),LineColor(4));
    MCDCAmix_pdf.plotOn(data_frame,Components(MCP_pdf),LineStyle(kDashed),LineColor(2));
		MCDCAmix_pdf.paramOn(data_frame);

    max = data_frame->GetMaximum();
    min = data_frame->GetMinimum();
    data_frame->SetMaximum(max+0.2*(max-min));
		// data_frame->SetMinimum(0.1); // must after the plotOn
		data_frame->Draw();	

    TLatex *tex_datafix= new TLatex(0.18,0.82,"Data, param. fix");
    tex_datafix->SetNDC();
    tex_datafix->SetTextFont(42);
    tex_datafix->SetTextSize(0.035);
    tex_datafix->SetLineWidth(2);
    tex_datafix->Draw();

		// fill in output
		h_PromptYield_fix->SetBinContent(iPtBins+1,pNum.getVal());
		h_PromptYield_fix->SetBinError(iPtBins+1,pNum.getError());
    h_NonPromptYield_fix->SetBinContent(iPtBins+1,npNum.getVal());
    h_NonPromptYield_fix->SetBinError(iPtBins+1,npNum.getError());

    h_NonPromptFraction_fix->SetBinContent(iPtBins+1,npNum.getVal()/(pNum.getVal()+npNum.getVal()));
    h_NonPromptFraction_fix->SetBinError(iPtBins+1,npNum.getError()/(pNum.getVal()+npNum.getVal()));

	
		c_data[iPtBins]->cd(5);
		gPad->SetLogy();
		RooPlot* data_framelog = x.frame();
    h_Data.plotOn(data_framelog,Binning(bin_dcaxy));
    MCDCAmix_pdf.plotOn(data_framelog,Components(RooArgSet(MCP_pdf,power_pdf)),LineColor(3));
    MCDCAmix_pdf.plotOn(data_framelog,Components(power_pdf),LineStyle(kDashed),LineColor(4));
    MCDCAmix_pdf.plotOn(data_framelog,Components(MCP_pdf),LineStyle(kDashed),LineColor(2));
//    MCDCAmix_pdf.paramOn(data_framelog);
    max = data_framelog->GetMaximum();
    min = data_frame->GetMinimum();
    data_framelog->SetMaximum(10*max);
    data_framelog->SetMinimum(0.5); // must after the plotOn
    data_framelog->Draw();
    tex_datafix->Draw();
			
	  			

		c_data[iPtBins]->cd(3);

		sigma.setConstant(kFALSE);
		power_a.setConstant(kFALSE);
		power_n.setConstant(kFALSE);

		MCDCAmix_pdf.fitTo(h_Data,Extended(kTRUE));		
    RooPlot* data_frame2 = x.frame();
    h_Data.plotOn(data_frame2,Binning(bin_dcaxy));
    MCDCAmix_pdf.plotOn(data_frame2,Components(RooArgSet(MCP_pdf,power_pdf)),LineColor(3));
    MCDCAmix_pdf.plotOn(data_frame2,Components(power_pdf),LineStyle(kDashed),LineColor(4));
    MCDCAmix_pdf.plotOn(data_frame2,Components(MCP_pdf),LineStyle(kDashed),LineColor(2));
    MCDCAmix_pdf.paramOn(data_frame2);

	  max = data_frame2->GetMaximum();
    min = data_frame2->GetMinimum();
    data_frame2->SetMaximum(max+0.2*(max-min));
    data_frame2->Draw();

    TLatex *tex_datafloat= new TLatex(0.18,0.82,"Data, param. float");
    tex_datafloat->SetNDC();
    tex_datafloat->SetTextFont(42);
    tex_datafloat->SetTextSize(0.035);
    tex_datafloat->SetLineWidth(2);
    tex_datafloat->Draw();


    // fill in output
    h_PromptYield_float->SetBinContent(iPtBins+1,pNum.getVal());
    h_PromptYield_float->SetBinError(iPtBins+1,pNum.getError());
    h_NonPromptYield_float->SetBinContent(iPtBins+1,npNum.getVal());
    h_NonPromptYield_float->SetBinError(iPtBins+1,npNum.getError());

    h_NonPromptFraction_float->SetBinContent(iPtBins+1,npNum.getVal()/(pNum.getVal()+npNum.getVal()));
    h_NonPromptFraction_float->SetBinError(iPtBins+1,npNum.getError()/(pNum.getVal()+npNum.getVal()));

		c_data[iPtBins]->cd(6);
		gPad->SetLogy();
		RooPlot *data_frame2log = x.frame();
    h_Data.plotOn(data_frame2log,Binning(bin_dcaxy));
    MCDCAmix_pdf.plotOn(data_frame2log,Components(RooArgSet(MCP_pdf,power_pdf)),LineColor(3));
    MCDCAmix_pdf.plotOn(data_frame2log,Components(power_pdf),LineStyle(kDashed),LineColor(4));
    MCDCAmix_pdf.plotOn(data_frame2log,Components(MCP_pdf),LineStyle(kDashed),LineColor(2));
//    MCDCAmix_pdf.paramOn(data_frame2);
    max = data_frame2log->GetMaximum();
//    min = data_frame2->GetMinimum();
    data_frame2log->SetMaximum(10*max);
		data_frame2log->SetMinimum(0.5);
    data_frame2log->Draw();
    tex_datafloat->Draw();
	



		c_data[iPtBins]->SaveAs(Form("plots_functionfit/fitdata_pt%dto%d.pdf",(int)ptLow,(int)ptHigh));


	} // end for iPtBins
/*
	c_MCP_gauss->SaveAs("plots_functionfit/MCP_Gauss_Ptall.pdf");
	c_MCP_gauss2->SaveAs("plots_functionfit/MCP_Gauss2_Ptall.pdf");
	c_MCNP_gauss->SaveAs("plots_functionfit/MCNP_Gauss_Ptall.pdf");
*/

	divideBinWidth(h_PromptYield_fix);
	divideBinWidth(h_NonPromptYield_fix);
	divideBinWidth(h_PromptYield_float);
	divideBinWidth(h_NonPromptYield_float);

	TCanvas *c_dataPtall = new TCanvas("c_dataPtall","c_dataPtall",1000,600);
	c_dataPtall->Divide(3,2);
	c_dataPtall->cd(1);
	gPad->SetLogy();
	h_PromptYield_fix->GetXaxis()->SetTitle("D P_{T} (GeV/c)");
  h_PromptYield_fix->GetYaxis()->SetTitle("Prompt Yield (fix)");
	h_PromptYield_fix->Draw();
	c_dataPtall->cd(2);
  gPad->SetLogy();
  h_NonPromptYield_fix->GetXaxis()->SetTitle("D P_{T} (GeV/c)");
  h_NonPromptYield_fix->GetYaxis()->SetTitle("NonPrompt Yield (fix)");
	h_NonPromptYield_fix->Draw();
	c_dataPtall->cd(3);
  h_NonPromptFraction_fix->GetXaxis()->SetTitle("D P_{T} (GeV/c)");
  h_NonPromptFraction_fix->GetYaxis()->SetTitle("NonPrompt Fraction (fix)");
	h_NonPromptFraction_fix->Draw();
  c_dataPtall->cd(4);
  gPad->SetLogy();
  h_PromptYield_float->GetXaxis()->SetTitle("D P_{T} (GeV/c)");
  h_PromptYield_float->GetYaxis()->SetTitle("Prompt Yield (float)");
  h_PromptYield_float->Draw();
  c_dataPtall->cd(5);
  gPad->SetLogy();
  h_NonPromptYield_float->GetXaxis()->SetTitle("D P_{T} (GeV/c)");
  h_NonPromptYield_float->GetYaxis()->SetTitle("NonPrompt Yield (float)");
  h_NonPromptYield_float->Draw();
  c_dataPtall->cd(6);
  h_NonPromptFraction_float->GetXaxis()->SetTitle("D P_{T} (GeV/c)");
  h_NonPromptFraction_float->GetYaxis()->SetTitle("NonPrompt Fraction (float)");
//	h_NonPromptFraction_float->SetMaximum(1);;
  h_NonPromptFraction_float->Draw();

	c_dataPtall->SaveAs("plots_functionfit/fitPt_spectrum.pdf");

	
	TH1D *h_PromptYield_tmp = (TH1D*)fDcaData->Get("hPromptDRawYield");
	TH1D *h_NonPromptYield_tmp = (TH1D*)fDcaData->Get("hBtoDRawYield");

	TH1D *h_PromptYield_diff = new TH1D("h_PromptYield_diff","h_PromptYield_diff",nPtBins,ptBins);
  TH1D *h_NonPromptYield_diff = new TH1D("h_PromptYield_diff","h_PromptYield_diff",nPtBins,ptBins);

	TH1D *h_PromptYield_RelErr = new TH1D("h_PromptYield_RelErr","h_PromptYield_RelErr",nPtBins,ptBins);
  TH1D *h_NonPromptYield_RelErr = new TH1D("h_NonPromptYield_RelErr","h_NonPromptYield_RelErr",nPtBins,ptBins);

	for(int iPtBins =0;iPtBins<nPtBins; iPtBins++){
	
		h_PromptYield_diff->SetBinContent(iPtBins+1,h_PromptYield_float->GetBinContent(iPtBins+1)-h_PromptYield_tmp->GetBinContent(iPtBins+1));
    h_NonPromptYield_diff->SetBinContent(iPtBins+1,h_NonPromptYield_float->GetBinContent(iPtBins+1)-h_NonPromptYield_tmp->GetBinContent(iPtBins+1));
	
    h_PromptYield_RelErr->SetBinContent(iPtBins+1,abs((h_PromptYield_float->GetBinContent(iPtBins+1)-h_PromptYield_tmp->GetBinContent(iPtBins+1))/h_PromptYield_tmp->GetBinContent(iPtBins+1)));
    h_NonPromptYield_RelErr->SetBinContent(iPtBins+1,abs((h_NonPromptYield_float->GetBinContent(iPtBins+1)-h_NonPromptYield_tmp->GetBinContent(iPtBins+1))/h_NonPromptYield_tmp->GetBinContent(iPtBins+1)));

	}

	TCanvas *c_yield_sys = new TCanvas("c_yield_sys","c_yield_sys",800,800);
	c_yield_sys->Divide(2,2);

	c_yield_sys->cd(1);
	gPad->SetLogy();
//	h_PromptYield_tmp->SetMarkerStyle(24);
//	h_PromptYield_tmp->SetMarkerColor(4);
//	h_PromptYield_tmp->SetLinceColor(4);
	SetHistStyle(h_PromptYield_tmp,4);
	h_PromptYield_tmp->GetXaxis()->SetTitle("D P_{T} (GeV/c)");
	h_PromptYield_tmp->Draw();
//	h_PromptYield_float->SetMarkerStyle(24);
//  h_PromptYield_float->SetMarkerColor(2);
//	h_PromptYield_float->SetLineColor(2);
	SetHistStyle(h_PromptYield_float,2);
	h_PromptYield_float->Draw("same");

	TLegend *le_PromptYield = new TLegend(0.65,0.65,0.88,0.88);
	le_PromptYield->SetBorderSize(0);
	le_PromptYield->AddEntry((TObject*)0,"Prompt Yield","");
	le_PromptYield->AddEntry(h_PromptYield_tmp,"template fit","l");
  le_PromptYield->AddEntry(h_PromptYield_float,"function fit","l");
	le_PromptYield->Draw();

  c_yield_sys->cd(2);
	gPad->SetLogy();
//  h_NonPromptYield_tmp->SetMarkerStyle(24);
//  h_NonPromptYield_tmp->SetMarkerColor(4);
//  h_NonPromptYield_tmp->SetLinceColor(4);
  SetHistStyle(h_NonPromptYield_tmp,4);
  h_NonPromptYield_tmp->GetXaxis()->SetTitle("D P_{T} (GeV/c)");
  h_NonPromptYield_tmp->Draw();
//  h_NonPromptYield_float->SetMarkerStyle(24);
//  h_NonPromptYield_float->SetMarkerColor(2);
//  h_NonPromptYield_float->SetLineColor(2);
  SetHistStyle(h_NonPromptYield_float,2);
  h_NonPromptYield_float->Draw("same");

  TLegend *le_NonPromptYield = new TLegend(0.65,0.65,0.88,0.88);
  le_NonPromptYield->SetBorderSize(0);
  le_NonPromptYield->AddEntry((TObject*)0,"NonPrompt Yield","");
  le_NonPromptYield->AddEntry(h_NonPromptYield_tmp,"template fit","l");
  le_NonPromptYield->AddEntry(h_NonPromptYield_float,"function fit","l");
  le_NonPromptYield->Draw();

	c_yield_sys->cd(3);
	h_PromptYield_RelErr->Draw();
  TLatex *tex_promptY_RelErr= new TLatex(0.18,0.82,"Prompt Yield rel.Err");
  tex_promptY_RelErr->SetNDC();
  tex_promptY_RelErr->SetTextFont(42);
  tex_promptY_RelErr->SetTextSize(0.035);
  tex_promptY_RelErr->SetLineWidth(2);
  tex_promptY_RelErr->Draw();



	c_yield_sys->cd(4);
//	h_NonPromptYield_RelErr->SetMaximum(1);
	h_NonPromptYield_RelErr->Draw();
  TLatex *tex_NonpromptY_RelErr= new TLatex(0.18,0.82,"NonPrompt Yield rel.Err");
  tex_NonpromptY_RelErr->SetNDC();
  tex_NonpromptY_RelErr->SetTextFont(42);
  tex_NonpromptY_RelErr->SetTextSize(0.035);
  tex_NonpromptY_RelErr->SetLineWidth(2);
  tex_NonpromptY_RelErr->Draw();




	c_yield_sys->SaveAs("plots_functionfit/Yield_sys.pdf");




	fout->cd();
  h_PromptYield_fix->Write();
  h_NonPromptYield_fix->Write();
  h_NonPromptFraction_fix->Write();

	h_PromptYield_float->Write();
	h_NonPromptYield_float->Write();
	h_NonPromptFraction_float->Write();


	h_PromptYield_diff->Write();
	h_NonPromptYield_diff->Write();
	h_PromptYield_RelErr->Write();
	h_NonPromptYield_RelErr->Write();	



	fout->Write();
	fout->Close(); // this will delete all object on plot


	cout<<"end of main"<<endl;
	

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
	RooPlot* MCP_frame = x.frame();

	RooDataHist h_MCP("h_MCP","h_MCP",RooArgList(x),h_MCP_DCAxy);

	gauss.fitTo(h_MCP);
	h_MCP.plotOn(MCP_frame);
	gauss.plotOn(MCP_frame);
	gauss.paramOn(MCP_frame);
	MCP_frame->Draw();

	c_RoofitMCP->cd(2);
	gPad->SetLogy();
	MCP_frame->Draw();


	c_RoofitMCP->cd(3);
	RooRealVar ARatio("ARatio","ARatio",0.5,0,1);
	RooRealVar sigmaRatio("sigmaRatio","sigmaRatio",1.24,1.000001,100000);
	RooGenericPdf dgauss("dgauss","Double Gaussian","ARatio*exp(-pow((x-mean)/sigma,2)/2)+(1-ARatio)*exp(-pow((x-mean)/(sigma*sigmaRatio),2)/2)",RooArgSet(x,mean,sigma,ARatio,sigmaRatio));
	//	RooGenericPdf dgauss("dgauss","Double Gaussian", "exp(-pow((x-mean)/sigma,2)/2)" ,RooArgSet(x,mean,sigma));

	dgauss.fitTo(h_MCP);
	RooPlot* MCP_frame2 = x.frame();
	h_MCP.plotOn(MCP_frame2);
	dgauss.plotOn(MCP_frame2);
	dgauss.paramOn(MCP_frame2);
	MCP_frame2->Draw();

	c_RoofitMCP->cd(4);
	gPad->SetLogy();
	MCP_frame2->Draw();




	TCanvas *c_RoofitMCNP = new TCanvas("c_RoofitMCNP","c_RoofitMCNP",800,800);
	c_RoofitMCNP->Divide(2,2);
	c_RoofitMCNP->cd(1);

	RooRealVar dca("dca","dca_xy",-0.05,0.05);
	RooRealVar alpha("alpha","alpha",-100,-20000,-0.00001);
	RooGenericPdf gp("gp","Generic PDF","exp(abs(dca)*alpha)",RooArgSet(dca,alpha));
	RooPlot * MCNP_frame = dca.frame();

	RooDataHist h_MCNP("h_MCNP","h_MCNP",RooArgSet(dca),h_MCNP_DCAxy);
	gp.fitTo(h_MCNP);
	h_MCNP.plotOn(MCNP_frame);
	gp.plotOn(MCNP_frame);
	MCNP_frame->Draw();

	c_RoofitMCNP->cd(2);
	gPad->SetLogy();
	MCNP_frame->Draw();


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


	RooPlot * MCNP_frame2 = dca.frame();
	//  RooDataHist h_MCNP("h_MCNP","h_MCNP",RooArgSet(dca),h_MCNP_DCAxy);
	gpxg.fitTo(h_MCNP);
	h_MCNP.plotOn(MCNP_frame2);
	gpxg.plotOn(MCNP_frame2);
	gpxg.paramOn(MCNP_frame2);
	//	MCNP_frame2->GetXaxis()->SetTitle("set x title");
	MCNP_frame2->Draw();

	c_RoofitMCNP->cd(4);
	gPad->SetLogy();
	MCNP_frame2->Draw();





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
		cout<<"MCPsigmaVal ="<<MCPsigmaVal<<endl;

}
