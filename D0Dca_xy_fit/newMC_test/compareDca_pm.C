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
#include "TMath.h"


Double_t fitf(Double_t *x, Double_t *par){

	double mean =par[0];
	double sigma=par[1];
	double powA=par[2];
	double powN=par[3];
	double ampP=par[4];
	double ampNP=par[5];
//	Double_t fitval= par[0]*TMath::Exp(-0.5*arg*arg);
	Double_t fitval= ampP*TMath::Exp(-0.5*(pow((x[0]-mean)/sigma,2))) + ampNP/(pow(1+powA*abs(x[0]-mean),powN));
	return fitval;

}


void setColorTitleLabel(TH1* h, int color)
{
  h->SetLineColor(color);
  h->SetMarkerColor(color);
  h->SetMarkerStyle(20);
  h->SetStats(0);
  h->GetXaxis()->CenterTitle();
  h->GetYaxis()->CenterTitle();
  h->GetXaxis()->SetTitleOffset(1.);
  h->GetYaxis()->SetTitleOffset(1.2);
  h->GetXaxis()->SetLabelOffset(0.007);
  h->GetYaxis()->SetLabelOffset(0.007);
  h->GetXaxis()->SetTitleSize(0.06);
  h->GetYaxis()->SetTitleSize(0.06);
  h->GetXaxis()->SetLabelSize(0.06);
  h->GetYaxis()->SetLabelSize(0.06);
}


void RatioCal(double *ratioV,double *ratioE, double valueP, double valueN, double errorP, double errorN){

      if(valueN==0){
        if(valueP>=0){
        ratioV[0]=4;
        ratioE[0]=5;
        }
        else{
        ratioV[0]=-1;
        ratioE[0]=5;
        }
      }
      else {
				ratioV[0]=valueP/valueN;
				ratioE[0]=valueP/valueN*pow(pow(errorP/valueP,2)+pow(errorN/valueN,2),0.5);
      }
      if (ratioV[0]>4){
        ratioV[0]=4;
      }
      if (ratioV[0]<-1){
        ratioV[0]=-1;
			}


}

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

	double ratioV[1]={0};
	double ratioE[1]={0};

	TH1D *h_DcaData[nPtBins];

	TH1D *h_Dca_DataPos[nPtBins];
	TH1D *h_Dca_DataNeg[nPtBins];
	TH1D *h_Dca_DataPNratio[nPtBins];

  TH1D *h_DcaData_Si[nPtBins];

  TH1D *h_Dca_DataPos_Si[nPtBins];
  TH1D *h_Dca_DataNeg_Si[nPtBins];
  TH1D *h_Dca_DataPNratio_Si[nPtBins];

  TH1D *h_Dca_DataPos_SB[nPtBins];
  TH1D *h_Dca_DataNeg_SB[nPtBins];
  TH1D *h_Dca_DataPNratio_SB[nPtBins];

  TH1D *h_Dca_DataPos_Cand[nPtBins];
  TH1D *h_Dca_DataNeg_Cand[nPtBins];
  TH1D *h_Dca_DataPNratio_Cand[nPtBins];



	TH1D *h_Dca_MCPPos[nPtBins];
	TH1D *h_Dca_MCPNeg[nPtBins];
	TH1D *h_Dca_MCPPNratio[nPtBins];

	TH1D *h_Dca_MCNPPos[nPtBins];
	TH1D *h_Dca_MCNPNeg[nPtBins];
	TH1D *h_Dca_MCNPPNratio[nPtBins];


	TH1D *h_Dca_MCPPos_noW[nPtBins];
	TH1D *h_Dca_MCPNeg_noW[nPtBins];
	TH1D *h_Dca_MCPPNratio_noW[nPtBins];

	TH1D *h_Dca_MCNPPos_noW[nPtBins];
	TH1D *h_Dca_MCNPNeg_noW[nPtBins];
	TH1D *h_Dca_MCNPPNratio_noW[nPtBins];


	// read MC
	TFile* fPbPbMC = new TFile("bFeedDownPbPbMC_new.hist.root");
	TFile* fPbPbMBMC = new TFile("bFeedDownPbPbMBMC_new.hist.root");
	TH3D* hMCPSignalPbPb = (TH3D*)fPbPbMC->Get("hMCPSignal");
	TH3D* hMCNPSignalPbPb = (TH3D*)fPbPbMC->Get("hMCNPSignal");
	TH3D* hMCPSignalPbPbMB = (TH3D*)fPbPbMBMC->Get("hMCPSignal");
	TH3D* hMCNPSignalPbPbMB = (TH3D*)fPbPbMBMC->Get("hMCNPSignal");
	TH3D* hPtMD0DcaMCPSignalPbPb = (TH3D*)fPbPbMC->Get("hPtMD0DcaMCPSignal");
	TH3D* hPtMD0DcaMCPSwappedPbPb = (TH3D*)fPbPbMC->Get("hPtMD0DcaMCPSwapped");
	TH3D* hPtMD0DcaMCPSignalPbPbMB =(TH3D*)fPbPbMBMC->Get("hPtMD0DcaMCPSignal");
	TH3D* hPtMD0DcaMCPSwappedPbPbMB = (TH3D*)fPbPbMBMC->Get("hPtMD0DcaMCPSwapped");


	TH3D* hMCPSignalPbPb_noW = (TH3D*)fPbPbMC->Get("hMCPSignal_noW");
	TH3D* hMCNPSignalPbPb_noW = (TH3D*)fPbPbMC->Get("hMCNPSignal_noW");
	TH3D* hMCPSignalPbPbMB_noW = (TH3D*)fPbPbMBMC->Get("hMCPSignal_noW");
	TH3D* hMCNPSignalPbPbMB_noW = (TH3D*)fPbPbMBMC->Get("hMCNPSignal_noW");

	double valuePt=0;
	double valueNt=0;
	double errorPt=0;
	double errorNt=0;



	TH3D* hMCPSignal = (TH3D*)hMCPSignalPbPb->Clone("hMCPSignal");
	hMCPSignal->Sumw2();
	hMCPSignal->Add(hMCPSignalPbPbMB);

	TH3D* hMCNPSignal = (TH3D*)hMCNPSignalPbPb->Clone("hMCNPSignal");
	hMCNPSignal->Sumw2();
	hMCNPSignal->Add(hMCNPSignalPbPbMB);


	TH3D* hMCPSignal_noW = (TH3D*)hMCPSignalPbPb_noW->Clone("hMCPSignal_noW");
	hMCPSignal_noW->Sumw2();
	hMCPSignal_noW->Add(hMCPSignalPbPbMB_noW);

	TH3D* hMCNPSignal_noW = (TH3D*)hMCNPSignalPbPb_noW->Clone("hMCNPSignal_noW");
	hMCNPSignal_noW->Sumw2();
	hMCNPSignal_noW->Add(hMCNPSignalPbPbMB_noW);



	TH3D* hPtMD0DcaMCPSignal = (TH3D*)hPtMD0DcaMCPSignalPbPb->Clone("hPtMD0DcaMCPSignal");
	hPtMD0DcaMCPSignal->Sumw2();
	hPtMD0DcaMCPSignal->Add(hPtMD0DcaMCPSignalPbPbMB);

	TH3D* hPtMD0DcaMCPSwapped =(TH3D*)hPtMD0DcaMCPSwappedPbPb->Clone("hPtMD0DcaMCPSwapped");
	hPtMD0DcaMCPSwapped->Sumw2();
	hPtMD0DcaMCPSwapped->Add(hPtMD0DcaMCPSwappedPbPbMB);

  TFile* fPbPb = new TFile("bFeedDownPbPb.hist.root");
  TFile* fPbPbMB = new TFile("bFeedDownPbPbMB.hist.root");
  TH3D* hSidebandPbPb = (TH3D*)fPbPb->Get("hSideband");
  TH3D* hSidebandPbPbMB = (TH3D*)fPbPbMB->Get("hSideband");
  TH3D* hSideband = (TH3D*)hSidebandPbPb->Clone("hSideband");
  hSideband->Sumw2();
  hSideband->Add(hSidebandPbPbMB);

  TH3D* hDataPbPb = (TH3D*)fPbPb->Get("hData");
  TH3D* hDataPbPbMB = (TH3D*)fPbPbMB->Get("hData");
  TH3D* hData = (TH3D*)hDataPbPb->Clone("hData");
  hData->Sumw2();
  hData->Add(hDataPbPbMB);

	TH1D* h_DataCand_DcaMean = new TH1D("h_DataCand_DcaMean","h_DataCand_DcaMean",nPtBins,ptBins);
	h_DataCand_DcaMean->Sumw2();

	TH1D* h_MCP_Mean = new TH1D("h_MCP_Mean","h_MCP_Mean",nPtBins,ptBins);
	h_MCP_Mean->Sumw2();
  TH1D* h_MCP_Mean_noW = new TH1D("h_MCP_Mean_noW","h_MCP_Mean_noW",nPtBins,ptBins);
  h_MCP_Mean_noW->Sumw2();

  TH1D* h_MCNP_Mean = new TH1D("h_MCNP_Mean","h_MCNP_Mean",nPtBins,ptBins);
  h_MCNP_Mean->Sumw2();
  TH1D* h_MCNP_Mean_noW = new TH1D("h_MCNP_Mean_noW","h_MCNP_Mean_noW",nPtBins,ptBins);
  h_MCNP_Mean_noW->Sumw2();


  TH1D* h_DcaData_Cand[nPtBins];
  TH1D* h_DcaData_SB[nPtBins];	

	TH1D* h_MCP_DCAxy_ptArr[nPtBins];
	TH1D* h_MCNP_DCAxy_ptArr[nPtBins];

	TH1D* h_MCP_DCAxy_ptArr_noW[nPtBins];
	TH1D* h_MCNP_DCAxy_ptArr_noW[nPtBins];

	TCanvas *c_DcaPM[nPtBins];
	TCanvas *c_DcaPM_Si[nPtBins];
  TCanvas *c_DcaPM_SB[nPtBins];
	TCanvas *c_DcaPM_Cand[nPtBins];
	TCanvas *c_DcaPM_MCP[nPtBins];
	TCanvas *c_DcaPM_MCNP[nPtBins];
	TCanvas *c_DcaPM_MCP_noW[nPtBins];
	TCanvas *c_DcaPM_MCNP_noW[nPtBins];

	double valueP=0;
	double valueN=0;
	double errorP=0;
	double errorN=0;	

	double fitLow=-0.0734;
	double fitHi=0.0734;

	TF1 *fitfunc = new TF1("fitfunc",fitf,fitLow,fitHi,6);
	fitfunc->SetParNames("mean","sigma","powA","powN","ampP","ampNP");

	TH1D *h_DCA_DataOverFit[nPtBins];

	TCanvas *c_fitplot[nPtBins];

  TLine *line1 = new TLine(0,1,0.07,1);
  line1->SetLineStyle(7);

	TLine *line2 = new TLine(-0.07,1,0.07,1);
	line2->SetLineStyle(7);

	TH1D *h_DCA_DataMean= new TH1D("h_DCA_DataMean","h_DCA_DataMean",nPtBins,ptBins);
	h_DCA_DataMean->Sumw2();

//  line1->Draw("SAME");



	for(int iPtBins=0; iPtBins<nPtBins; iPtBins++)
//		  for(int iPtBins=1; iPtBins<3; iPtBins++)
	{

		Float_t ptLow=ptBins[iPtBins];
		Float_t ptHigh=ptBins[iPtBins+1];

		hSideband->GetXaxis()->SetRangeUser(ptLow,ptHigh);
    hData->GetXaxis()->SetRangeUser(ptLow,ptHigh);


		hMCPSignal->GetXaxis()->SetRangeUser(ptLow,ptHigh);
		hMCNPSignal->GetXaxis()->SetRangeUser(ptLow,ptHigh);

		hMCPSignal_noW->GetXaxis()->SetRangeUser(ptLow,ptHigh);
		hMCNPSignal_noW->GetXaxis()->SetRangeUser(ptLow,ptHigh);


		h_DcaData[iPtBins]=(TH1D*)fDcaData->Get(Form("D0DcaDataOut_pt%i",iPtBins));

		h_DcaData_Si[iPtBins]=(TH1D*)fDcaData->Get(Form("D0DcaDataOut_sideband_pt%i",iPtBins));

		h_Dca_DataPos[iPtBins] = new TH1D(Form("h_Dca_DataPos_Dpt%i",iPtBins),Form("h_Dca_DataPos_Dpt%i",iPtBins),nBinYh,binsYh);
		h_Dca_DataNeg[iPtBins] = new TH1D(Form("h_Dca_DataNeg_Dpt%i",iPtBins),Form("h_Dca_DataNeg_Dpt%i",iPtBins),nBinYh,binsYh);
		h_Dca_DataPNratio[iPtBins] = new TH1D(Form("h_Dca_DataPNratio_Dpt%i",iPtBins),Form("h_Dca_DataPNratio_Dpt%i",iPtBins),nBinYh,binsYh);

    h_Dca_DataPos_Si[iPtBins] = new TH1D(Form("h_Dca_DataPos_Si_Dpt%i",iPtBins),Form("h_Dca_DataPos_Si_Dpt%i",iPtBins),nBinYh,binsYh);
    h_Dca_DataNeg_Si[iPtBins] = new TH1D(Form("h_Dca_DataNeg_Si_Dpt%i",iPtBins),Form("h_Dca_DataNeg_Si_Dpt%i",iPtBins),nBinYh,binsYh);
    h_Dca_DataPNratio_Si[iPtBins] = new TH1D(Form("h_Dca_DataPNratio_Si_Dpt%i",iPtBins),Form("h_Dca_DataPNratio_Si_Dpt%i",iPtBins),nBinYh,binsYh);


    h_Dca_DataPos_SB[iPtBins] = new TH1D(Form("h_Dca_DataPos_SB_Dpt%i",iPtBins),Form("h_Dca_DataPos_SB_Dpt%i",iPtBins),nBinYh,binsYh);
    h_Dca_DataNeg_SB[iPtBins] = new TH1D(Form("h_Dca_DataNeg_SB_Dpt%i",iPtBins),Form("h_Dca_DataNeg_SB_Dpt%i",iPtBins),nBinYh,binsYh);
    h_Dca_DataPNratio_SB[iPtBins] = new TH1D(Form("h_Dca_DataPNratio_SB_Dpt%i",iPtBins),Form("h_Dca_DataPNratio_SB_Dpt%i",iPtBins),nBinYh,binsYh);

    h_Dca_DataPos_Cand[iPtBins] = new TH1D(Form("h_Dca_DataPos_Cand_Dpt%i",iPtBins),Form("h_Dca_DataPos_Cand_Dpt%i",iPtBins),nBinYh,binsYh);
    h_Dca_DataNeg_Cand[iPtBins] = new TH1D(Form("h_Dca_DataNeg_Cand_Dpt%i",iPtBins),Form("h_Dca_DataNeg_Cand_Dpt%i",iPtBins),nBinYh,binsYh);
    h_Dca_DataPNratio_Cand[iPtBins] = new TH1D(Form("h_Dca_DataPNratio_Cand_Dpt%i",iPtBins),Form("h_Dca_DataPNratio_Cand_Dpt%i",iPtBins),nBinYh,binsYh);



		h_Dca_MCPPos[iPtBins] = new TH1D(Form("h_Dca_MCPPos_Dpt%i",iPtBins),Form("h_Dca_MCPPos_Dpt%i",iPtBins),nBinYh,binsYh);
		h_Dca_MCPNeg[iPtBins] = new TH1D(Form("h_Dca_MCPNeg_Dpt%i",iPtBins),Form("h_Dca_MCPNeg_Dpt%i",iPtBins),nBinYh,binsYh);
		h_Dca_MCPPNratio[iPtBins] = new TH1D(Form("h_Dca_MCPPNratio_Dpt%i",iPtBins),Form("h_Dca_MCPPNratio_Dpt%i",iPtBins),nBinYh,binsYh);

		h_Dca_MCNPPos[iPtBins] = new TH1D(Form("h_Dca_MCNPPos_Dpt%i",iPtBins),Form("h_Dca_MCNPPos_Dpt%i",iPtBins),nBinYh,binsYh);
		h_Dca_MCNPNeg[iPtBins] = new TH1D(Form("h_Dca_MCNPNeg_Dpt%i",iPtBins),Form("h_Dca_MCNPNeg_Dpt%i",iPtBins),nBinYh,binsYh);
    h_Dca_MCNPPNratio[iPtBins] = new TH1D(Form("h_Dca_MCNPPNratio_Dpt%i",iPtBins),Form("h_Dca_MCNPPNratio_Dpt%i",iPtBins),nBinYh,binsYh);

    h_Dca_MCPPos_noW[iPtBins] = new TH1D(Form("h_Dca_MCPPos_noW_Dpt%i",iPtBins),Form("h_Dca_MCPPos_noW_Dpt%i",iPtBins),nBinYh,binsYh);
    h_Dca_MCPNeg_noW[iPtBins] = new TH1D(Form("h_Dca_MCPNeg_noW_Dpt%i",iPtBins),Form("h_Dca_MCPNeg_noW_Dpt%i",iPtBins),nBinYh,binsYh);
    h_Dca_MCPPNratio_noW[iPtBins] = new TH1D(Form("h_Dca_MCPPNratio_noW_Dpt%i",iPtBins),Form("h_Dca_MCPPNratio_noW_Dpt%i",iPtBins),nBinYh,binsYh);

    h_Dca_MCNPPos_noW[iPtBins] = new TH1D(Form("h_Dca_MCNPPos_noW_Dpt%i",iPtBins),Form("h_Dca_MCNPPos_noW_Dpt%i",iPtBins),nBinYh,binsYh);
    h_Dca_MCNPNeg_noW[iPtBins] = new TH1D(Form("h_Dca_MCNPNeg_noW_Dpt%i",iPtBins),Form("h_Dca_MCNPNeg_noW_Dpt%i",iPtBins),nBinYh,binsYh);
    h_Dca_MCNPPNratio_noW[iPtBins] = new TH1D(Form("h_Dca_MCNPPNratio_noW_Dpt%i",iPtBins),Form("h_Dca_MCNPPNratio_noW_Dpt%i",iPtBins),nBinYh,binsYh);

		h_DcaData_SB[iPtBins]=(TH1D*)hSideband->Project3D("y")->Clone(Form("h_DataSB_DCAxy_Dpt%.1fto%.1f",ptLow,ptHigh));

    h_DcaData_Cand[iPtBins]=(TH1D*)hData->Project3D("y")->Clone(Form("h_DataCand_DCAxy_Dpt%.1fto%.1f",ptLow,ptHigh));
		h_DataCand_DcaMean->SetBinContent(iPtBins+1,h_DcaData_Cand[iPtBins]->GetMean());
    h_DataCand_DcaMean->SetBinError(iPtBins+1,h_DcaData_Cand[iPtBins]->GetMeanError());


		h_MCP_DCAxy_ptArr[iPtBins]= (TH1D*)hMCPSignal->Project3D("y")->Clone(Form("h_MCP_DCAxy_Dpt%.1fto%.1f",ptLow,ptHigh));
		h_MCNP_DCAxy_ptArr[iPtBins]= (TH1D*)hMCNPSignal->Project3D("y")->Clone(Form("h_MCNP_DCAxy_Dpt%.1fto%.1f",ptLow,ptHigh));

		h_MCP_DCAxy_ptArr_noW[iPtBins]= (TH1D*)hMCPSignal_noW->Project3D("y")->Clone(Form("h_MCP_DCAxy_Dpt%.1fto%.1f_noW",ptLow,ptHigh));
		h_MCNP_DCAxy_ptArr_noW[iPtBins]= (TH1D*)hMCNPSignal_noW->Project3D("y")->Clone(Form("h_MCNP_DCAxy_Dpt%.1fto%.1f_noW",ptLow,ptHigh));
    h_MCP_Mean->SetBinContent(iPtBins+1,h_MCP_DCAxy_ptArr[iPtBins]->GetMean());
    h_MCP_Mean->SetBinError(iPtBins+1,h_MCP_DCAxy_ptArr[iPtBins]->GetMeanError());
		h_MCP_Mean_noW->SetBinContent(iPtBins+1,h_MCP_DCAxy_ptArr_noW[iPtBins]->GetMean());
    h_MCP_Mean_noW->SetBinError(iPtBins+1,h_MCP_DCAxy_ptArr_noW[iPtBins]->GetMeanError());
    h_MCNP_Mean->SetBinContent(iPtBins+1,h_MCNP_DCAxy_ptArr[iPtBins]->GetMean());
    h_MCNP_Mean->SetBinError(iPtBins+1,h_MCNP_DCAxy_ptArr[iPtBins]->GetMeanError());
    h_MCNP_Mean_noW->SetBinContent(iPtBins+1,h_MCNP_DCAxy_ptArr_noW[iPtBins]->GetMean());
    h_MCNP_Mean_noW->SetBinError(iPtBins+1,h_MCNP_DCAxy_ptArr_noW[iPtBins]->GetMeanError());

		
		// fitting Data
    h_DCA_DataOverFit[iPtBins] = (TH1D*)h_DcaData[iPtBins]->Clone(Form("h_Dca_DataOverFit_Dpt%i",iPtBins));

		c_fitplot[iPtBins] = new TCanvas(Form("c_fitplot_Dpt%i",iPtBins),Form("c_fitplot_Dpt%i",iPtBins),500,1000);
		c_fitplot[iPtBins]->Divide(1,2);
		c_fitplot[iPtBins]->cd(1);

		gPad->SetLogy();		
	  gStyle->SetOptFit(1111);


		fitfunc->SetParameters(0,0.0045,5,10,0.8*h_DcaData[iPtBins]->Integral(),0.2*h_DcaData[iPtBins]->Integral());
		fitfunc->SetParLimits(5,0,1000000);
		fitfunc->SetParLimits(4,0,10000000); 
		fitfunc->SetParLimits(1,0.002,0.007); // sigma
		fitfunc->SetParLimits(2,0.01,100); //powA
		fitfunc->SetParLimits(3,1,10000); //powN
		fitfunc->FixParameter(0,0);
	
		h_DcaData[iPtBins]->Fit("fitfunc");
    h_DcaData[iPtBins]->Fit("fitfunc");
    h_DcaData[iPtBins]->Fit("fitfunc");
    h_DcaData[iPtBins]->Fit("fitfunc");
    h_DcaData[iPtBins]->Fit("fitfunc");

		fitfunc->ReleaseParameter(0);

    h_DcaData[iPtBins]->Fit("fitfunc");
    h_DcaData[iPtBins]->Fit("fitfunc");
    h_DcaData[iPtBins]->Fit("fitfunc");


    gStyle->SetOptFit(1111);

		h_DcaData[iPtBins]->SetMaximum(h_DcaData[iPtBins]->GetMaximum()*10);
		h_DcaData[iPtBins]->GetYaxis()->SetTitle("");
		h_DcaData[iPtBins]->Draw();
    gStyle->SetOptFit(1111);


		TLegend *le_DataOverFit = new TLegend (0.15,0.63,0.38,0.88);
    le_DataOverFit->SetBorderSize(0);
    le_DataOverFit->AddEntry((TObject*)0,Form("DPt %0.0f to %0.0f",ptLow,ptHigh),"");
		le_DataOverFit->SetFillStyle(0);

		le_DataOverFit->Draw();

		c_fitplot[iPtBins]->cd(2);

		h_DCA_DataOverFit[iPtBins]->GetYaxis()->SetTitle("Data/fit");
		h_DCA_DataOverFit[iPtBins]->Divide(fitfunc);
		h_DCA_DataOverFit[iPtBins]->SetMaximum(3);
		h_DCA_DataOverFit[iPtBins]->SetMinimum(-1);
		h_DCA_DataOverFit[iPtBins]->Draw("e");

    line2->Draw("SAME");
		
		h_DCA_DataMean->SetBinContent(iPtBins+1,fitfunc->GetParameter(0));
		h_DCA_DataMean->SetBinError(iPtBins+1,fitfunc->GetParError(0));


//		for(int iBinY=0; iBinY<nBinY; iBinY++){

//}

		c_fitplot[iPtBins]->SaveAs((Form("plots_dcaPN/fitplot/DcaFit_DataPN_pt%dto%d.png",(int)ptLow,(int)ptHigh)));

		// end of fitting Data

		for(int iBinYh=0; iBinYh<nBinYh;iBinYh++){

			h_Dca_DataPos[iPtBins]->SetBinContent(iBinYh+1,h_DcaData[iPtBins]->GetBinContent(iBinYh+11));
			h_Dca_DataPos[iPtBins]->SetBinError(iBinYh+1,h_DcaData[iPtBins]->GetBinError(iBinYh+11));

			h_Dca_DataNeg[iPtBins]->SetBinContent(iBinYh+1,h_DcaData[iPtBins]->GetBinContent(10-iBinYh));
			h_Dca_DataNeg[iPtBins]->SetBinError(iBinYh+1,h_DcaData[iPtBins]->GetBinError(10-iBinYh));
			if(iBinYh==6){
			valuePt= h_Dca_DataPos[iPtBins]->GetBinContent(iBinYh+1);
      valueNt= h_Dca_DataNeg[iPtBins]->GetBinError(iBinYh+1);
      errorPt= h_Dca_DataPos[iPtBins]->GetBinContent(iBinYh+1);
      errorNt= h_Dca_DataNeg[iPtBins]->GetBinError(iBinYh+1);
			}

			RatioCal(ratioV,ratioE, h_Dca_DataPos[iPtBins]->GetBinContent(iBinYh+1) ,h_Dca_DataNeg[iPtBins]->GetBinContent(iBinYh+1), h_Dca_DataPos[iPtBins]->GetBinError(iBinYh+1), h_Dca_DataNeg[iPtBins]->GetBinError(iBinYh+1));

			h_Dca_DataPNratio[iPtBins]->SetBinContent(iBinYh+1,ratioV[0]);
      h_Dca_DataPNratio[iPtBins]->SetBinError(iBinYh+1,ratioE[0]);

// Data_si
      h_Dca_DataPos_Si[iPtBins]->SetBinContent(iBinYh+1,h_DcaData_Si[iPtBins]->GetBinContent(iBinYh+11));
      h_Dca_DataPos_Si[iPtBins]->SetBinError(iBinYh+1,h_DcaData_Si[iPtBins]->GetBinError(iBinYh+11));

      h_Dca_DataNeg_Si[iPtBins]->SetBinContent(iBinYh+1,h_DcaData_Si[iPtBins]->GetBinContent(10-iBinYh));
      h_Dca_DataNeg_Si[iPtBins]->SetBinError(iBinYh+1,h_DcaData_Si[iPtBins]->GetBinError(10-iBinYh));

      RatioCal(ratioV,ratioE, h_Dca_DataPos_Si[iPtBins]->GetBinContent(iBinYh+1) ,h_Dca_DataNeg_Si[iPtBins]->GetBinContent(iBinYh+1), h_Dca_DataPos_Si[iPtBins]->GetBinError(iBinYh+1), h_Dca_DataNeg_Si[iPtBins]->GetBinError(iBinYh+1));

      h_Dca_DataPNratio_Si[iPtBins]->SetBinContent(iBinYh+1,ratioV[0]);
      h_Dca_DataPNratio_Si[iPtBins]->SetBinError(iBinYh+1,ratioE[0]);


// Data_SideBand
      h_Dca_DataPos_SB[iPtBins]->SetBinContent(iBinYh+1,h_DcaData_SB[iPtBins]->GetBinContent(iBinYh+11));
      h_Dca_DataPos_SB[iPtBins]->SetBinError(iBinYh+1,h_DcaData_SB[iPtBins]->GetBinError(iBinYh+11));

      h_Dca_DataNeg_SB[iPtBins]->SetBinContent(iBinYh+1,h_DcaData_SB[iPtBins]->GetBinContent(10-iBinYh));
      h_Dca_DataNeg_SB[iPtBins]->SetBinError(iBinYh+1,h_DcaData_SB[iPtBins]->GetBinError(10-iBinYh));

      RatioCal(ratioV,ratioE, h_Dca_DataPos_SB[iPtBins]->GetBinContent(iBinYh+1) ,h_Dca_DataNeg_SB[iPtBins]->GetBinContent(iBinYh+1), h_Dca_DataPos_SB[iPtBins]->GetBinError(iBinYh+1), h_Dca_DataNeg_SB[iPtBins]->GetBinError(iBinYh+1));

      h_Dca_DataPNratio_SB[iPtBins]->SetBinContent(iBinYh+1,ratioV[0]);
      h_Dca_DataPNratio_SB[iPtBins]->SetBinError(iBinYh+1,ratioE[0]);


// Data_Candidate

      h_Dca_DataPos_Cand[iPtBins]->SetBinContent(iBinYh+1,h_DcaData_Cand[iPtBins]->GetBinContent(iBinYh+11));
      h_Dca_DataPos_Cand[iPtBins]->SetBinError(iBinYh+1,h_DcaData_Cand[iPtBins]->GetBinError(iBinYh+11));

      h_Dca_DataNeg_Cand[iPtBins]->SetBinContent(iBinYh+1,h_DcaData_Cand[iPtBins]->GetBinContent(10-iBinYh));
      h_Dca_DataNeg_Cand[iPtBins]->SetBinError(iBinYh+1,h_DcaData_Cand[iPtBins]->GetBinError(10-iBinYh));

      RatioCal(ratioV,ratioE, h_Dca_DataPos_Cand[iPtBins]->GetBinContent(iBinYh+1) ,h_Dca_DataNeg_Cand[iPtBins]->GetBinContent(iBinYh+1), h_Dca_DataPos_Cand[iPtBins]->GetBinError(iBinYh+1), h_Dca_DataNeg_Cand[iPtBins]->GetBinError(iBinYh+1));

      h_Dca_DataPNratio_Cand[iPtBins]->SetBinContent(iBinYh+1,ratioV[0]);
      h_Dca_DataPNratio_Cand[iPtBins]->SetBinError(iBinYh+1,ratioE[0]);



			// MCP
			h_Dca_MCPPos[iPtBins]->SetBinContent(iBinYh+1,h_MCP_DCAxy_ptArr[iPtBins]->GetBinContent(iBinYh+11));
			h_Dca_MCPPos[iPtBins]->SetBinError(iBinYh+1,h_MCP_DCAxy_ptArr[iPtBins]->GetBinError(iBinYh+11));

			h_Dca_MCPNeg[iPtBins]->SetBinContent(iBinYh+1,h_MCP_DCAxy_ptArr[iPtBins]->GetBinContent(10-iBinYh));
			h_Dca_MCPNeg[iPtBins]->SetBinError(iBinYh+1,h_MCP_DCAxy_ptArr[iPtBins]->GetBinError(10-iBinYh));

      RatioCal(ratioV,ratioE, h_Dca_MCPPos[iPtBins]->GetBinContent(iBinYh+1) ,h_Dca_MCPNeg[iPtBins]->GetBinContent(iBinYh+1), h_Dca_MCPPos[iPtBins]->GetBinError(iBinYh+1), h_Dca_MCPNeg[iPtBins]->GetBinError(iBinYh+1));

      h_Dca_MCPPNratio[iPtBins]->SetBinContent(iBinYh+1,ratioV[0]);
      h_Dca_MCPPNratio[iPtBins]->SetBinError(iBinYh+1,ratioE[0]);

			// MCNP	
			h_Dca_MCNPPos[iPtBins]->SetBinContent(iBinYh+1,h_MCNP_DCAxy_ptArr[iPtBins]->GetBinContent(iBinYh+11));
			h_Dca_MCNPPos[iPtBins]->SetBinError(iBinYh+1,h_MCNP_DCAxy_ptArr[iPtBins]->GetBinError(iBinYh+11));

			h_Dca_MCNPNeg[iPtBins]->SetBinContent(iBinYh+1,h_MCNP_DCAxy_ptArr[iPtBins]->GetBinContent(10-iBinYh));
			h_Dca_MCNPNeg[iPtBins]->SetBinError(iBinYh+1,h_MCNP_DCAxy_ptArr[iPtBins]->GetBinError(10-iBinYh));

      RatioCal(ratioV,ratioE, h_Dca_MCNPPos[iPtBins]->GetBinContent(iBinYh+1) ,h_Dca_MCNPNeg[iPtBins]->GetBinContent(iBinYh+1), h_Dca_MCNPPos[iPtBins]->GetBinError(iBinYh+1), h_Dca_MCNPNeg[iPtBins]->GetBinError(iBinYh+1));

      h_Dca_MCNPPNratio[iPtBins]->SetBinContent(iBinYh+1,ratioV[0]);
      h_Dca_MCNPPNratio[iPtBins]->SetBinError(iBinYh+1,ratioE[0]);


			// noW
			// MCP
			h_Dca_MCPPos_noW[iPtBins]->SetBinContent(iBinYh+1,h_MCP_DCAxy_ptArr_noW[iPtBins]->GetBinContent(iBinYh+11));
			h_Dca_MCPPos_noW[iPtBins]->SetBinError(iBinYh+1,h_MCP_DCAxy_ptArr_noW[iPtBins]->GetBinError(iBinYh+11));

			h_Dca_MCPNeg_noW[iPtBins]->SetBinContent(iBinYh+1,h_MCP_DCAxy_ptArr_noW[iPtBins]->GetBinContent(10-iBinYh));
			h_Dca_MCPNeg_noW[iPtBins]->SetBinError(iBinYh+1,h_MCP_DCAxy_ptArr_noW[iPtBins]->GetBinError(10-iBinYh));

      RatioCal(ratioV,ratioE, h_Dca_MCPPos_noW[iPtBins]->GetBinContent(iBinYh+1) ,h_Dca_MCPNeg_noW[iPtBins]->GetBinContent(iBinYh+1), h_Dca_MCPPos_noW[iPtBins]->GetBinError(iBinYh+1), h_Dca_MCPNeg_noW[iPtBins]->GetBinError(iBinYh+1));

      h_Dca_MCPPNratio_noW[iPtBins]->SetBinContent(iBinYh+1,ratioV[0]);
      h_Dca_MCPPNratio_noW[iPtBins]->SetBinError(iBinYh+1,ratioE[0]);


			// MCNP
			h_Dca_MCNPPos_noW[iPtBins]->SetBinContent(iBinYh+1,h_MCNP_DCAxy_ptArr_noW[iPtBins]->GetBinContent(iBinYh+11));
			h_Dca_MCNPPos_noW[iPtBins]->SetBinError(iBinYh+1,h_MCNP_DCAxy_ptArr_noW[iPtBins]->GetBinError(iBinYh+11));

			h_Dca_MCNPNeg_noW[iPtBins]->SetBinContent(iBinYh+1,h_MCNP_DCAxy_ptArr_noW[iPtBins]->GetBinContent(10-iBinYh));
			h_Dca_MCNPNeg_noW[iPtBins]->SetBinError(iBinYh+1,h_MCNP_DCAxy_ptArr_noW[iPtBins]->GetBinError(10-iBinYh));

      RatioCal(ratioV,ratioE, h_Dca_MCNPPos_noW[iPtBins]->GetBinContent(iBinYh+1) ,h_Dca_MCNPNeg_noW[iPtBins]->GetBinContent(iBinYh+1), h_Dca_MCNPPos_noW[iPtBins]->GetBinError(iBinYh+1), h_Dca_MCNPNeg_noW[iPtBins]->GetBinError(iBinYh+1));

      h_Dca_MCNPPNratio_noW[iPtBins]->SetBinContent(iBinYh+1,ratioV[0]);
      h_Dca_MCNPPNratio_noW[iPtBins]->SetBinError(iBinYh+1,ratioE[0]);




		} // end for int iBinYh
		//	h_Dca_DataPNratio[iPtBins]->Divide(h_Dca_DataPos[iPtBins],h_Dca_DataNeg[iPtBins],1,1);

		c_DcaPM[iPtBins] = new TCanvas("c_DcaPM","c_DcaPM",500,1000);
		c_DcaPM[iPtBins]->Divide(1,2);
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

    c_DcaPM[iPtBins]->cd(2);
		h_Dca_DataPNratio[iPtBins]->Draw();
		h_Dca_DataPNratio[iPtBins]->SetMaximum(4.1);
		h_Dca_DataPNratio[iPtBins]->SetMinimum(-1.1);
		h_Dca_DataPNratio[iPtBins]->GetYaxis()->SetTitle("Data DCA P/N");

//	  TLine *line1 = new TLine(0,1,0.07,1);
//    line1->SetLineStyle(7);
    line1->Draw("SAME");
	


		c_DcaPM[iPtBins]->SaveAs(Form("plots_dcaPN/Dca_DataPN_pt%dto%d.png",(int)ptLow,(int)ptHigh));

		//	c_DcaPM[iPtBins]->SaveAs(Form("plots_dcaPN/sideband/Dca_DataSidebandPN_pt%dto%d.png",(int)ptLow,(int)ptHigh));

		//Data_sidebandsub
    c_DcaPM_Si[iPtBins] = new TCanvas("c_DcaPM_Si","c_DcaPM_Si",500,1000);
    c_DcaPM_Si[iPtBins]->Divide(1,2);
    c_DcaPM_Si[iPtBins]->cd(1);

    gPad->SetLogy();
    h_Dca_DataPos_Si[iPtBins]->Draw();
    h_Dca_DataPos_Si[iPtBins]->GetXaxis()->SetTitle("Dca_xy (cm)");
    h_Dca_DataPos_Si[iPtBins]->SetMarkerStyle(24);
    h_Dca_DataPos_Si[iPtBins]->SetMarkerColor(4);
    h_Dca_DataNeg_Si[iPtBins]->SetLineColor(2);
    h_Dca_DataNeg_Si[iPtBins]->SetMarkerStyle(24);
    h_Dca_DataNeg_Si[iPtBins]->SetMarkerColor(2);
    h_Dca_DataNeg_Si[iPtBins]->Draw("SAME");

    TLegend *le_DcaPM_Si = new TLegend(0.63,0.63,0.88,0.88) ;
    le_DcaPM_Si->SetBorderSize(0);
    le_DcaPM_Si->AddEntry((TObject*)0,Form("DPt %0.0f to %0.0f",ptLow,ptHigh),"");
    le_DcaPM_Si->AddEntry(h_Dca_DataPos[iPtBins],"Data Dca +","l");
    le_DcaPM_Si->AddEntry(h_Dca_DataNeg[iPtBins],"Data Dca -","l");

    le_DcaPM_Si->Draw();

    c_DcaPM_Si[iPtBins]->cd(2);
    h_Dca_DataPNratio_Si[iPtBins]->Draw();
    h_Dca_DataPNratio_Si[iPtBins]->SetMaximum(4.1);
    h_Dca_DataPNratio_Si[iPtBins]->SetMinimum(-1.1);
    h_Dca_DataPNratio_Si[iPtBins]->GetYaxis()->SetTitle("Data SBscale DCA P/N");

    // TLine *line1 = new TLine(0,1,0.07,1);
    // line1->SetLineStyle(7);
    line1->Draw("SAME");

    c_DcaPM_Si[iPtBins]->SaveAs(Form("plots_dcaPN/sidebandScale/Dca_DataSbScalePN_pt%dto%d.png",(int)ptLow,(int)ptHigh));

//Data SideBand
    c_DcaPM_SB[iPtBins] = new TCanvas("c_DcaPM_SB","c_DcaPM_SB",500,1000);
    c_DcaPM_SB[iPtBins]->Divide(1,2);
    c_DcaPM_SB[iPtBins]->cd(1);

    gPad->SetLogy();
    h_Dca_DataPos_SB[iPtBins]->Draw();
    h_Dca_DataPos_SB[iPtBins]->GetXaxis()->SetTitle("Dca_xy (cm)");
    h_Dca_DataPos_SB[iPtBins]->SetMarkerStyle(24);
    h_Dca_DataPos_SB[iPtBins]->SetMarkerColor(4);
    h_Dca_DataNeg_SB[iPtBins]->SetLineColor(2);
    h_Dca_DataNeg_SB[iPtBins]->SetMarkerStyle(24);
    h_Dca_DataNeg_SB[iPtBins]->SetMarkerColor(2);
    h_Dca_DataNeg_SB[iPtBins]->Draw("SAME");

    TLegend *le_DcaPM_SB = new TLegend(0.63,0.63,0.88,0.88) ;
    le_DcaPM_SB->SetBorderSize(0);
    le_DcaPM_SB->AddEntry((TObject*)0,Form("DPt %0.0f to %0.0f",ptLow,ptHigh),"");
    le_DcaPM_SB->AddEntry(h_Dca_DataPos[iPtBins],"Data Dca +","l");
    le_DcaPM_SB->AddEntry(h_Dca_DataNeg[iPtBins],"Data Dca -","l");

    le_DcaPM_SB->Draw();

    c_DcaPM_SB[iPtBins]->cd(2);
    h_Dca_DataPNratio_SB[iPtBins]->Draw();
		if(h_Dca_DataPNratio_SB[iPtBins]->GetMaximum()>4.2) 
    h_Dca_DataPNratio_SB[iPtBins]->SetMaximum(4.1);
    if(h_Dca_DataPNratio_SB[iPtBins]->GetMinimum()<-1.2)
    h_Dca_DataPNratio_SB[iPtBins]->SetMinimum(-1.1);

    h_Dca_DataPNratio_SB[iPtBins]->GetYaxis()->SetTitle("Data SideBand DCA P/N");

    // TLine *line1 = new TLine(0,1,0.07,1);
    // line1->SetLineStyle(7);
    line1->Draw("SAME");

    c_DcaPM_SB[iPtBins]->SaveAs(Form("plots_dcaPN/sideband/Dca_DataSidebandPN_pt%dto%d.png",(int)ptLow,(int)ptHigh));


//Data Candidate
    c_DcaPM_Cand[iPtBins] = new TCanvas("c_DcaPM_Cand","c_DcaPM_Cand",500,1000);
    c_DcaPM_Cand[iPtBins]->Divide(1,2);
    c_DcaPM_Cand[iPtBins]->cd(1);

    gPad->SetLogy();
    h_Dca_DataPos_Cand[iPtBins]->Draw();
    h_Dca_DataPos_Cand[iPtBins]->GetXaxis()->SetTitle("Dca_xy (cm)");
    h_Dca_DataPos_Cand[iPtBins]->SetMarkerStyle(24);
    h_Dca_DataPos_Cand[iPtBins]->SetMarkerColor(4);
    h_Dca_DataNeg_Cand[iPtBins]->SetLineColor(2);
    h_Dca_DataNeg_Cand[iPtBins]->SetMarkerStyle(24);
    h_Dca_DataNeg_Cand[iPtBins]->SetMarkerColor(2);
    h_Dca_DataNeg_Cand[iPtBins]->Draw("SAME");

    TLegend *le_DcaPM_Cand = new TLegend(0.63,0.63,0.88,0.88) ;
    le_DcaPM_Cand->SetBorderSize(0);
    le_DcaPM_Cand->AddEntry((TObject*)0,Form("DPt %0.0f to %0.0f",ptLow,ptHigh),"");
    le_DcaPM_Cand->AddEntry(h_Dca_DataPos[iPtBins],"Data Dca +","l");
    le_DcaPM_Cand->AddEntry(h_Dca_DataNeg[iPtBins],"Data Dca -","l");

    le_DcaPM_Cand->Draw();

    c_DcaPM_Cand[iPtBins]->cd(2);
    h_Dca_DataPNratio_Cand[iPtBins]->Draw();
//    h_Dca_DataPNratio_Cand[iPtBins]->SetMaximum(4.1);
//    h_Dca_DataPNratio_Cand[iPtBins]->SetMinimum(-1.1);
    h_Dca_DataPNratio_Cand[iPtBins]->GetYaxis()->SetTitle("Data SideBand DCA P/N");

    // TLine *line1 = new TLine(0,1,0.07,1);
    // line1->SetLineStyle(7);
    line1->Draw("SAME");

    c_DcaPM_Cand[iPtBins]->SaveAs(Form("plots_dcaPN/Data_Cand/Dca_DataCandidatePN_pt%dto%d.png",(int)ptLow,(int)ptHigh));




		//MCP
		c_DcaPM_MCP[iPtBins] = new TCanvas("c_DcaPM_MCP","c_DcaPM_MCP",500,1000);
		c_DcaPM_MCP[iPtBins]->Divide(1,2);
		c_DcaPM_MCP[iPtBins]->cd(1);

		gPad->SetLogy();
		h_Dca_MCPPos[iPtBins]->Draw();
		h_Dca_MCPPos[iPtBins]->GetXaxis()->SetTitle("Dca_xy (cm)");
		h_Dca_MCPPos[iPtBins]->SetMarkerStyle(24);
		h_Dca_MCPPos[iPtBins]->SetMarkerColor(4);
		h_Dca_MCPNeg[iPtBins]->SetLineColor(2);
		h_Dca_MCPNeg[iPtBins]->SetMarkerStyle(24);
		h_Dca_MCPNeg[iPtBins]->SetMarkerColor(2);
		h_Dca_MCPNeg[iPtBins]->Draw("SAME");

		TLegend *le_DcaPM_MCP = new TLegend(0.63,0.63,0.88,0.88) ;
		le_DcaPM_MCP->SetBorderSize(0);
		le_DcaPM_MCP->AddEntry((TObject*)0,Form("DPt %0.0f to %0.0f",ptLow,ptHigh),"");
		le_DcaPM_MCP->AddEntry(h_Dca_MCPPos[iPtBins],"MCP Dca +","l");
		le_DcaPM_MCP->AddEntry(h_Dca_MCPNeg[iPtBins],"MCP Dca -","l");

		le_DcaPM_MCP->Draw();

    c_DcaPM_MCP[iPtBins]->cd(2);

    h_Dca_MCPPNratio[iPtBins]->Draw();
    h_Dca_MCPPNratio[iPtBins]->SetMaximum(4.1);
    h_Dca_MCPPNratio[iPtBins]->SetMinimum(-1.1);
    h_Dca_MCPPNratio[iPtBins]->GetYaxis()->SetTitle("MCP DCA P/N");

    // TLine *line1 = new TLine(0,1,0.07,1);
    // line1->SetLineStyle(7);
    line1->Draw("SAME");

		c_DcaPM_MCP[iPtBins]->SaveAs(Form("plots_dcaPN/Dca_MCPPN_pt%dto%d.png",(int)ptLow,(int)ptHigh));

		//MCNP
		c_DcaPM_MCNP[iPtBins] = new TCanvas("c_DcaPM_MCNP","c_DcaPM_MCNP",500,1000);
		c_DcaPM_MCNP[iPtBins]->Divide(1,2);
		c_DcaPM_MCNP[iPtBins]->cd(1);

		gPad->SetLogy();
		h_Dca_MCNPPos[iPtBins]->Draw();
		h_Dca_MCNPPos[iPtBins]->GetXaxis()->SetTitle("Dca_xy (cm)");
		h_Dca_MCNPPos[iPtBins]->SetMarkerStyle(24);
		h_Dca_MCNPPos[iPtBins]->SetMarkerColor(4);
		h_Dca_MCNPNeg[iPtBins]->SetLineColor(2);
		h_Dca_MCNPNeg[iPtBins]->SetMarkerStyle(24);
		h_Dca_MCNPNeg[iPtBins]->SetMarkerColor(2);
		h_Dca_MCNPNeg[iPtBins]->Draw("SAME");

		TLegend *le_DcaPM_MCNP = new TLegend(0.63,0.63,0.88,0.88) ;
		le_DcaPM_MCNP->SetBorderSize(0);
		le_DcaPM_MCNP->AddEntry((TObject*)0,Form("DPt %0.0f to %0.0f",ptLow,ptHigh),"");
		le_DcaPM_MCNP->AddEntry(h_Dca_MCNPPos[iPtBins],"MCNP Dca +","l");
		le_DcaPM_MCNP->AddEntry(h_Dca_MCNPNeg[iPtBins],"MCNP Dca -","l");

		le_DcaPM_MCNP->Draw();

    c_DcaPM_MCNP[iPtBins]->cd(2);

    h_Dca_MCNPPNratio[iPtBins]->Draw();
    h_Dca_MCNPPNratio[iPtBins]->SetMaximum(4.1);
    h_Dca_MCNPPNratio[iPtBins]->SetMinimum(-1.1);
    h_Dca_MCNPPNratio[iPtBins]->GetYaxis()->SetTitle("MCNP DCA P/N");

    // TLine *line1 = new TLine(0,1,0.07,1);
    // line1->SetLineStyle(7);
    line1->Draw("SAME");


		c_DcaPM_MCNP[iPtBins]->SaveAs(Form("plots_dcaPN/Dca_MCNPPN_pt%dto%d.png",(int)ptLow,(int)ptHigh));

		//noW
		//MCP
		c_DcaPM_MCP_noW[iPtBins] = new TCanvas("c_DcaPM_MCP_noW","c_DcaPM_MCP_noW",500,1000);
		c_DcaPM_MCP_noW[iPtBins]->Divide(1,2);
		c_DcaPM_MCP_noW[iPtBins]->cd(1);

		gPad->SetLogy();
		h_Dca_MCPPos_noW[iPtBins]->Draw();
		h_Dca_MCPPos_noW[iPtBins]->GetXaxis()->SetTitle("Dca_xy (cm)");
		h_Dca_MCPPos_noW[iPtBins]->SetMarkerStyle(24);
		h_Dca_MCPPos_noW[iPtBins]->SetMarkerColor(4);
		h_Dca_MCPNeg_noW[iPtBins]->SetLineColor(2);
		h_Dca_MCPNeg_noW[iPtBins]->SetMarkerStyle(24);
		h_Dca_MCPNeg_noW[iPtBins]->SetMarkerColor(2);
		h_Dca_MCPNeg_noW[iPtBins]->Draw("SAME");

		TLegend *le_DcaPM_MCP_noW = new TLegend(0.63,0.63,0.88,0.88) ;
		le_DcaPM_MCP_noW->SetBorderSize(0);
		le_DcaPM_MCP_noW->AddEntry((TObject*)0,Form("DPt %0.0f to %0.0f",ptLow,ptHigh),"");
		le_DcaPM_MCP_noW->AddEntry(h_Dca_MCPPos[iPtBins],"MCP Dca +","l");
		le_DcaPM_MCP_noW->AddEntry(h_Dca_MCPNeg[iPtBins],"MCP Dca -","l");

		le_DcaPM_MCP_noW->Draw();

    c_DcaPM_MCP_noW[iPtBins]->cd(2);

    h_Dca_MCPPNratio_noW[iPtBins]->Draw();
    h_Dca_MCPPNratio_noW[iPtBins]->SetMaximum(4.1);
    h_Dca_MCPPNratio_noW[iPtBins]->SetMinimum(-1.1);
    h_Dca_MCPPNratio_noW[iPtBins]->GetYaxis()->SetTitle("MCP DCA noW P/N");

    // TLine *line1 = new TLine(0,1,0.07,1);
    // line1->SetLineStyle(7);
    line1->Draw("SAME");


		c_DcaPM_MCP_noW[iPtBins]->SaveAs(Form("plots_dcaPN/MC_noW/Dca_MCPPN_noW_pt%dto%d.png",(int)ptLow,(int)ptHigh));

		//MCNP
		c_DcaPM_MCNP_noW[iPtBins] = new TCanvas("c_DcaPM_MCNP_noW","c_DcaPM_MCNP_noW",500,1000);
		c_DcaPM_MCNP_noW[iPtBins]->Divide(1,2);
		c_DcaPM_MCNP_noW[iPtBins]->cd(1);

		gPad->SetLogy();
		h_Dca_MCNPPos_noW[iPtBins]->Draw();
		h_Dca_MCNPPos_noW[iPtBins]->GetXaxis()->SetTitle("Dca_xy (cm)");
		h_Dca_MCNPPos_noW[iPtBins]->SetMarkerStyle(24);
		h_Dca_MCNPPos_noW[iPtBins]->SetMarkerColor(4);
		h_Dca_MCNPNeg_noW[iPtBins]->SetLineColor(2);
		h_Dca_MCNPNeg_noW[iPtBins]->SetMarkerStyle(24);
		h_Dca_MCNPNeg_noW[iPtBins]->SetMarkerColor(2);
		h_Dca_MCNPNeg_noW[iPtBins]->Draw("SAME");

		TLegend *le_DcaPM_MCNP_noW = new TLegend(0.63,0.63,0.88,0.88) ;
		le_DcaPM_MCNP_noW->SetBorderSize(0);
		le_DcaPM_MCNP_noW->AddEntry((TObject*)0,Form("DPt %0.0f to %0.0f",ptLow,ptHigh),"");
		le_DcaPM_MCNP_noW->AddEntry(h_Dca_MCNPPos[iPtBins],"MCNP Dca +","l");
		le_DcaPM_MCNP_noW->AddEntry(h_Dca_MCNPNeg[iPtBins],"MCNP Dca -","l");

		le_DcaPM_MCNP_noW->Draw();

    c_DcaPM_MCNP_noW[iPtBins]->cd(2);

    h_Dca_MCNPPNratio_noW[iPtBins]->Draw();
    h_Dca_MCNPPNratio_noW[iPtBins]->SetMaximum(4.1);
    h_Dca_MCNPPNratio_noW[iPtBins]->SetMinimum(-1.1);
    h_Dca_MCNPPNratio_noW[iPtBins]->GetYaxis()->SetTitle("MCNP DCA noW P/N");

    // TLine *line1 = new TLine(0,1,0.07,1);
    // line1->SetLineStyle(7);
    line1->Draw("SAME");


		c_DcaPM_MCNP_noW[iPtBins]->SaveAs(Form("plots_dcaPN/MC_noW/Dca_MCNPPN_noW_pt%dto%d.png",(int)ptLow,(int)ptHigh));



		//	c_DcaPM[iPtBins]->cd(2);
		//	h_Dca_DataPNratio[iPtBins]->Draw();		

//	if (iPtBins ==7) return;
	}// end for int iPtBins

	cout<<"valuePt = "<<valuePt<<", valueNt= "<<valueNt<<endl;
  cout<<"errorPt = "<<errorPt<<", errorNt= "<<errorNt<<endl;
	cout<<"p/n= "<<valuePt/valueNt<<endl;
//	cout<<"error ="<<valuePt/valueNt*pow(pow(errorPt/valuePt,2)+pow(errorNt,valueNt,2),0.5)<<endl;
	TCanvas *c_DCA_dataMean = new TCanvas("c_DCA_dataMean","c_DCA_dataMean",600,600);
	c_DCA_dataMean->cd();

	double max= h_DCA_DataMean->GetMaximum();
	double min= h_DCA_DataMean->GetMinimum();

	h_DCA_DataMean->SetMaximum(max+(0.15*max-min));
	h_DCA_DataMean->GetYaxis()->SetTitle("cm");
  h_DCA_DataMean->GetXaxis()->SetTitle("Dpt (GeV)");
	
	
	h_DCA_DataMean->Draw();

    TLegend *le_DcaDataMean = new TLegend(0.60,0.63,0.88,0.88) ;
    le_DcaDataMean->SetBorderSize(0);
    le_DcaDataMean->AddEntry((TObject*)0,"Data DCA fitMean","");
		
		le_DcaDataMean->Draw();

	c_DCA_dataMean->SaveAs("plots_dcaPN/fitplot/DcaFit_DataMean.png");

  TCanvas *c_DCA_dataCandMean = new TCanvas("c_DCA_dataCandMean","c_DCA_dataCandMean",600,600);
  c_DCA_dataCandMean->cd();
	max= h_DataCand_DcaMean->GetMaximum();
	min= h_DataCand_DcaMean->GetMinimum();
	h_DataCand_DcaMean->SetMaximum(max+(0.15*max-min));

	h_DataCand_DcaMean->Draw();
  h_DataCand_DcaMean->GetYaxis()->SetTitle("cm");
  h_DataCand_DcaMean->GetXaxis()->SetTitle("Dpt (GeV)");



    TLegend *le_DcaDataCandMean = new TLegend(0.60,0.63,0.88,0.88) ;
    le_DcaDataCandMean->SetBorderSize(0);
    le_DcaDataCandMean->AddEntry((TObject*)0,"DataCand DCA Mean","");

    le_DcaDataCandMean->Draw();

  c_DCA_dataCandMean->SaveAs("plots_dcaPN/Data_Cand/DcaFit_DataMean.png");



  TCanvas *c_DCA_MCPMean = new TCanvas("c_DCA_MCPMean","c_DCA_MCPMean",600,600);
  c_DCA_MCPMean->cd();
  max= h_MCP_Mean->GetMaximum();
  min= h_MCP_Mean->GetMinimum();
  h_MCP_Mean->SetMaximum(max+(0.15*max-min));

  h_MCP_Mean->Draw();
  h_MCP_Mean->GetYaxis()->SetTitle("cm");
  h_MCP_Mean->GetXaxis()->SetTitle("Dpt (GeV)");


  h_MCP_Mean->Draw();

    TLegend *le_DcaMCPMean = new TLegend(0.60,0.63,0.88,0.88) ;
    le_DcaMCPMean->SetBorderSize(0);
    le_DcaMCPMean->AddEntry((TObject*)0,"MCP DCA Mean","");

    le_DcaMCPMean->Draw();

  c_DCA_MCPMean->SaveAs("plots_dcaPN/MC_noW/Dca_MCPMean.png");

  TCanvas *c_DCA_MCPMean_noW = new TCanvas("c_DCA_MCPMean_noW","c_DCA_MCPMean_noW",600,600);
  c_DCA_MCPMean_noW->cd();
  max= h_MCP_Mean_noW->GetMaximum();
  min= h_MCP_Mean_noW->GetMinimum();
  h_MCP_Mean_noW->SetMaximum(max+(0.15*max-min));
  h_MCP_Mean_noW->Draw();
  h_MCP_Mean_noW->GetYaxis()->SetTitle("cm");
  h_MCP_Mean_noW->GetXaxis()->SetTitle("Dpt (GeV)");

  h_MCP_Mean_noW->Draw();

    TLegend *le_DcaMCPMean_noW = new TLegend(0.60,0.63,0.88,0.88) ;
    le_DcaMCPMean_noW->SetBorderSize(0);
    le_DcaMCPMean_noW->AddEntry((TObject*)0,"MCP DCA Mean noW","");

    le_DcaMCPMean_noW->Draw();

  c_DCA_MCPMean_noW->SaveAs("plots_dcaPN/MC_noW/Dca_MCPMean_noW.png");

  TCanvas *c_DCA_MCNPMean = new TCanvas("c_DCA_MCNPMean","c_DCA_MCNPMean",600,600);
  c_DCA_MCNPMean->cd();
  max= h_MCNP_Mean->GetMaximum();
  min= h_MCNP_Mean->GetMinimum();
  h_MCNP_Mean->SetMaximum(max+(0.15*max-min));
  h_MCNP_Mean->Draw();
  h_MCNP_Mean->GetYaxis()->SetTitle("cm");
  h_MCNP_Mean->GetXaxis()->SetTitle("Dpt (GeV)");


  h_MCNP_Mean->Draw();

    TLegend *le_DcaMCNPMean = new TLegend(0.60,0.63,0.88,0.88) ;
    le_DcaMCNPMean->SetBorderSize(0);
    le_DcaMCNPMean->AddEntry((TObject*)0,"MCNP DCA Mean","");

    le_DcaMCNPMean->Draw();

  c_DCA_MCNPMean->SaveAs("plots_dcaPN/MC_noW/Dca_MCNPMean.png");

  TCanvas *c_DCA_MCNPMean_noW = new TCanvas("c_DCA_MCNPMean_noW","c_DCA_MCNPMean_noW",600,600);
  c_DCA_MCNPMean_noW->cd();
  max= h_MCNP_Mean_noW->GetMaximum();
  min= h_MCNP_Mean_noW->GetMinimum();
  h_MCNP_Mean_noW->SetMaximum(max+(0.15*max-min));
  h_MCNP_Mean_noW->Draw();
  h_MCNP_Mean_noW->GetYaxis()->SetTitle("cm");
  h_MCNP_Mean_noW->GetXaxis()->SetTitle("Dpt (GeV)");

  h_MCNP_Mean_noW->Draw();

    TLegend *le_DcaMCNPMean_noW = new TLegend(0.60,0.63,0.88,0.88) ;
    le_DcaMCNPMean_noW->SetBorderSize(0);
    le_DcaMCNPMean_noW->AddEntry((TObject*)0,"MCNP DCA Mean noW","");

    le_DcaMCNPMean_noW->Draw();

  c_DCA_MCNPMean_noW->SaveAs("plots_dcaPN/MC_noW/Dca_MCNPMean_noW.png");



}// end void compareDca_pm
