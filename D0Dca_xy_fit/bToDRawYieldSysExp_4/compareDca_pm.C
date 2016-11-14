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

void compareDca_pm(){

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


	
	TFile *fDcaData = new TFile("bFeedDownResult.root");


  const int nPtBins = 9;
  float ptBins[nPtBins+1] = {2.,4.,6.,8.,10.,12.,20.,40.,60.,100};

  const int nBinY = 20;
  const Double_t binsY[nBinY+1] = {-0.0734,-0.0562,-0.0428,-0.0320,-0.0236,-0.0170,-0.0118,-0.0078,-0.0046,-0.002,0.0,0.002,0.0046,0.0078,0.0118,0.0170,0.0236,0.0320,0.0428,0.0562,0.0734};

  const int nBinYh= nBinY/2;
  Double_t binsYh[nBinYh+1] = {0.0,0.002,0.0046,0.0078,0.0118,0.0170,0.0236,0.0320,0.0428,0.0562,0.0734};

	TH1D *h_DcaData[nPtBins];

  TH1D *h_Dca_DataPos[nPtBins];
  TH1D *h_Dca_DataNeg[nPtBins];
	TH1D *h_Dca_DataPNratio[nPtBins];


  TH1D *h_Dca_MCPPos[nPtBins];
  TH1D *h_Dca_MCPNeg[nPtBins];
  TH1D *h_Dca_MCNPPos[nPtBins];
  TH1D *h_Dca_MCNPNeg[nPtBins];

	TCanvas *c_DcaPM[nPtBins];


    for(int iPtBins=0; iPtBins<nPtBins; iPtBins++)
//  for(int iPtBins=1; iPtBins<2; iPtBins++)
  {

  Float_t ptLow=ptBins[iPtBins];
  Float_t ptHigh=ptBins[iPtBins+1];


  h_DcaData[iPtBins]=(TH1D*)fDcaData->Get(Form("D0DcaDataOut_pt%i",iPtBins));

  h_Dca_DataPos[iPtBins] = new TH1D(Form("h_Dca_DataPos_Dpt%i",iPtBins),Form("h_Dca_DataPos_Dpt%i",iPtBins),nBinYh,binsYh);
  h_Dca_DataNeg[iPtBins] = new TH1D(Form("h_Dca_DataNeg_Dpt%i",iPtBins),Form("h_Dca_DataNeg_Dpt%i",iPtBins),nBinYh,binsYh);

  h_Dca_MCPPos[iPtBins] = new TH1D(Form("h_Dca_MCPPos_Dpt%i",iPtBins),Form("h_Dca_MCPPos_Dpt%i",iPtBins),nBinYh,binsYh);
  h_Dca_MCPNeg[iPtBins] = new TH1D(Form("h_Dca_MCPNeg_Dpt%i",iPtBins),Form("h_Dca_MCPNeg_Dpt%i",iPtBins),nBinYh,binsYh);
  h_Dca_MCNPPos[iPtBins] = new TH1D(Form("h_Dca_MCNPPos_Dpt%i",iPtBins),Form("h_Dca_MCNPPos_Dpt%i",iPtBins),nBinYh,binsYh);
  h_Dca_MCNPNeg[iPtBins] = new TH1D(Form("h_Dca_MCNPNeg_Dpt%i",iPtBins),Form("h_Dca_MCNPNeg_Dpt%i",iPtBins),nBinYh,binsYh);

		for(int iBinYh=0; iBinYh<nBinYh;iBinYh++){

			 h_Dca_DataPos[iPtBins]->SetBinContent(iBinYh+1,h_DcaData[iPtBins]->GetBinContent(iBinYh+11));
       h_Dca_DataPos[iPtBins]->SetBinError(iBinYh+1,h_DcaData[iPtBins]->GetBinError(iBinYh+11));
			 
			 h_Dca_DataNeg[iPtBins]->SetBinContent(iBinYh+1,h_DcaData[iPtBins]->GetBinContent(10-iBinYh));
       h_Dca_DataNeg[iPtBins]->SetBinError(iBinYh+1,h_DcaData[iPtBins]->GetBinError(10-iBinYh));
		
		} // end for int iBinYh
//	h_Dca_DataPNratio[iPtBins]->Divide(h_Dca_DataPos[iPtBins],h_Dca_DataNeg[iPtBins],1,1);

	c_DcaPM[iPtBins] = new TCanvas("c_DcaPm","c_DcaPM",600,600);
	c_DcaPM[iPtBins]->Divide(1,1);
	c_DcaPM[iPtBins]->cd(1);

	gPad->SetLogy();
	h_Dca_DataPos[iPtBins]->Draw();
	h_Dca_DataPos[iPtBins]->GetXaxis()->SetTitle("Dca_xy (cm)");
	h_Dca_DataPos[iPtBins]->SetMarkerStyle(24);
  h_Dca_DataPos[iPtBins]->SetMarkerColor(4);	
	h_Dca_DataNeg[iPtBins]->SetLineColor(2);
	h_Dca_DataNeg[iPtBins]->SetMarkerStyle(24);
  h_Dca_DataNeg[iPtBins]->SetMarkerColor(2);
	h_Dca_DataNeg[iPtBins]->Draw("SAME");

	TLegend *le_DcaPM = new TLegend(0.63,0.63,0.88,0.88) ;
	le_DcaPM->SetBorderSize(0);
	le_DcaPM->AddEntry((TObject*)0,Form("DPt %0.0f to %0.0f",ptLow,ptHigh),"");
	le_DcaPM->AddEntry(h_Dca_DataPos[iPtBins],"Data Dca +","l");
  le_DcaPM->AddEntry(h_Dca_DataNeg[iPtBins],"Data Dca -","l");

	le_DcaPM->Draw();

	c_DcaPM[iPtBins]->SaveAs(Form("plots_dcaPN/Dca_DataPN_pt%dto%d.png",(int)ptLow,(int)ptHigh));

//	c_DcaPM[iPtBins]->cd(2);
//	h_Dca_DataPNratio[iPtBins]->Draw();		


	}// end for int iPtBins

}// end void compareDca_pm
