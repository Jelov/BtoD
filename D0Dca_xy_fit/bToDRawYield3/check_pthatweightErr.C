#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include "TH1.h"
#include <iostream>
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include "TCut.h"
//#include "TVector3.h"
#include <TMath.h>

using namespace std;

void check_pthatweightErr(){

	TFile* infMCP= new TFile("bFeedDownPbPbMCP.tree.root","READ");
	TFile* infMCNP=new TFile("bFeedDownPbPbMCNP.tree.root","READ");

	TTree* tMCP= (TTree*)infMCP->Get("Dtree");
  TTree* tMCNP=(TTree*)infMCNP->Get("Dtree");

	Float_t         pthatweight;
	Float_t         pthat;
	Float_t         DCA_xy;

	tMCP->SetBranchAddress("pthatweight", &pthatweight);
	tMCP->SetBranchAddress("pthat", &pthat);
	tMCP->SetBranchAddress("D0DCA_2Dv2", &DCA_xy);


	cout<<"check1"<<endl;

	const int nPthatWeightBin=9;
	double PthatWeightBin[nPthatWeightBin+1]={0,5,10,15,30,50,80,120,170,99999};
	double dcaHi=0.0170;
	double dcaLow=0.0118;

//	TH1D *pthatEntry = new TH1D("pthatEntry","pthatEntry",nPthatWeightBin,PthatWeightBin);
//	TH1D *pthatWeight[nPthatWeightBin];

	const int nBinY = 20;
	Float_t binsY[nBinY+1] = {-0.0734,-0.0562,-0.0428,-0.0320,-0.0236,-0.0170,-0.0118,-0.0078,-0.0046,-0.002,0.0,0.002,0.0046,0.0078,0.0118,0.0170,0.0236,0.0320,0.0428,0.0562,0.0734};
	TH1D *h_dca_MCP_pt20= new TH1D("h_dca_MCP_pt20","h_dca_MCP_pt20",nBinY,binsY);
	h_dca_MCP_pt20->Sumw2();
	tMCP->Draw("D0DCA_2Dv2>>h_dca_MCP_pt20","pthatweight*(Dpt>20 && Dpt<40)");	

  TH1D *h_dca_MCP_pt10= new TH1D("h_dca_MCP_pt10","h_dca_MCP_pt10",nBinY,binsY);
  h_dca_MCP_pt10->Sumw2();
  TH1D *h_dca_MCNP_pt10= new TH1D("h_dca_MCP_pt10","h_dca_MCP_pt10",nBinY,binsY);
  h_dca_MCNP_pt10->Sumw2();


//	tMCP->Draw("D0DCA_2Dv2>>h_dca_MCP_pt20","(Dpt>20 && Dpt<40)");
  cout<<"check2"<<endl;

	TH1D *h_DCA_MCP_pthatbin[nPthatWeightBin];

  TH1D *h_DCA_MCNP_pthatbin[nPthatWeightBin];

	TCanvas *c_DCA_MCP[nPthatWeightBin];
//= new TCanvas("c_DCA_MCP","c_DCA_MCP",500,1000);
//	c_DCA_MCP->Divide(1,2);
	TCanvas *c_DCA_MCNP[nPthatWeightBin];
//= new TCanvas("c_DCA_MCNP","c_DCA_MCNP",500,1000);
//	c_DCA_MCP->Divide(1,2);

	TCanvas *c_DCA_MCPall= new TCanvas("c_DCA_MCPall","c_DCA_MCPall",1200,900);
	c_DCA_MCPall->Divide(4,3);
  TCanvas *c_DCA_MCNPall= new TCanvas("c_DCA_MCNPall","c_DCA_MCNPall",1200,900);
  c_DCA_MCNPall->Divide(4,3);

	c_DCA_MCPall->cd(1);
	gPad->SetLogy();
  tMCP->Draw("D0DCA_2Dv2>>h_dca_MCP_pt10",Form("pthatweight*(Dpt>10 && Dpt<12)"));

	c_DCA_MCNPall->cd(1);
  gPad->SetLogy();
  tMCNP->Draw("D0DCA_2Dv2>>h_dca_MCNP_pt10",Form("pthatweight*(Dpt>10 && Dpt<12)"));

	TCanvas *c_Dca_MCP_pt20 = new TCanvas("c_Dca_MCP_pt20","c_Dca_MCP_pt20",600,600);
	c_Dca_MCP_pt20->cd();
	h_dca_MCP_pt20->Draw();

	c_Dca_MCP_pt20->SaveAs("plots_dcaPN/checkPthatError/MCP_pt20.png");

	double value_bin15=	h_dca_MCP_pt20->GetBinContent(15);
	double error_bin15= h_dca_MCP_pt20->GetBinError(15);
	cout<<"value = "<<value_bin15<<" , error_bin15= "<<error_bin15<<endl;

	TCanvas *c_pthatweight = new TCanvas("c_pthatweight","c_pthatweight",1000,1000);
	c_pthatweight->Divide(3,3);
	
  cout<<"check3"<<endl;


	for(int iPthatWeightBin=0; iPthatWeightBin<nPthatWeightBin; iPthatWeightBin++){

		c_pthatweight->cd(iPthatWeightBin+1);
		double ptlow= PthatWeightBin[iPthatWeightBin];
		double pthi= PthatWeightBin[iPthatWeightBin+1];
		tMCP->Draw("pthatweight",Form("D0DCA_2Dv2>0.0118 && D0DCA_2Dv2<0.0170 && Dpt>20 && Dpt<40 && pthat>%f && pthat<%f",ptlow,pthi));

	  cout<<"check4"<<endl;
/*
		c_DCA_MCP[iPthatWeightBin]= new TCanvas("c_DCA_MCP","c_DCA_MCP",500,1000);
    c_DCA_MCP[iPthatWeightBin]->Divide(1,2);
	

		c_DCA_MCP[iPthatWeightBin]->cd(1);
		gPad->SetLogy();
//  tMCP->Draw("D0DCA_2Dv2>>h_dca_MCP_pt20","pthatweight*(Dpt>20 && Dpt<40)");

    tMCP->Draw("D0DCA_2Dv2>>h_dca_MCP_pt20",Form("pthatweight*(Dpt>10 && Dpt<12 && pthat>%f && pthat<%f)",ptlow,pthi));
    c_DCA_MCP[iPthatWeightBin]->cd(2);
		gPad->SetLogy();
    tMCP->Draw("D0DCA_2Dv2>>h_dca_MCP_pt20",Form("(Dpt>10 && Dpt<12 && pthat>%f && pthat<%f)",ptlow,pthi));
		c_DCA_MCP[iPthatWeightBin]->SaveAs(Form("plots_dcaPN/check_pthat/MCP_Dpt10to12_pthat%0.0fto%0.0f.png",ptlow,pthi));

    c_DCA_MCNP[iPthatWeightBin]= new TCanvas("c_DCA_MCNP","c_DCA_MCNP",500,1000);
    c_DCA_MCNP[iPthatWeightBin]->Divide(1,2);

    c_DCA_MCNP[iPthatWeightBin]->cd(1);
    gPad->SetLogy();
    tMCNP->Draw("D0DCA_2Dv2>>h_dca_MCP_pt20",Form("pthatweight*(Dpt>10 && Dpt<12 && pthat>%f && pthat<%f)",ptlow,pthi));
    c_DCA_MCNP[iPthatWeightBin]->cd(2);
    gPad->SetLogy();
    tMCNP->Draw("D0DCA_2Dv2>>h_dca_MCP_pt20",Form("(Dpt>10 && Dpt<12 && pthat>%f && pthat<%f)",ptlow,pthi));
    c_DCA_MCNP[iPthatWeightBin]->SaveAs(Form("plots_dcaPN/check_pthat/MCNP_Dpt10to12_pthat%0.0fto%0.0f.png",ptlow,pthi));
*/

    h_DCA_MCP_pthatbin[iPthatWeightBin]= new TH1D(Form("h_dca_MCP_pthat%0.0fto%0.0f",ptlow,pthi),Form("h_dca_MCP_pthat%0.0fto%0.0f",ptlow,pthi),nBinY,binsY);
    h_DCA_MCP_pthatbin[iPthatWeightBin]->Sumw2();

    h_DCA_MCNP_pthatbin[iPthatWeightBin]= new TH1D(Form("h_dca_MCNP_pthat%0.0fto%0.0f",ptlow,pthi),Form("h_dca_MCNP_pthat%0.0fto%0.0f",ptlow,pthi),nBinY,binsY);
    h_DCA_MCNP_pthatbin[iPthatWeightBin]->Sumw2();

    c_DCA_MCPall->cd(iPthatWeightBin+2);
    gPad->SetLogy();
    tMCP->Draw(Form("D0DCA_2Dv2>>h_dca_MCP_pthat%0.0fto%0.0f",ptlow,pthi),Form("pthatweight*(Dpt>10 && Dpt<12 && pthat>%f && pthat<%f)",ptlow,pthi));

    c_DCA_MCNPall->cd(iPthatWeightBin+2);
    gPad->SetLogy();
    tMCNP->Draw(Form("D0DCA_2Dv2>>h_dca_MCNP_pthat%0.0fto%0.0f",ptlow,pthi),Form("pthatweight*(Dpt>10 && Dpt<12 && pthat>%f && pthat<%f)",ptlow,pthi));



	}// end for iPthatWeightBin

  c_pthatweight->SaveAs("plots_dcaPN/checkPthatError/pthatweight.png");

	c_DCA_MCPall->SaveAs(Form("plots_dcaPN/check_pthat/MCP_Dpt10to12.png"));
  c_DCA_MCNPall->SaveAs(Form("plots_dcaPN/check_pthat/MCNP_Dpt10to12.png"));


	/*
		 Long64_t nentries;
		 nentries=tMCP->GetEntries();
		 cout<<"nentries ="<<nentries;
		 for(int ientries=0; ientries<nentries; ientries++){
		 tMCP->GetEntry[ientries];


		 if(DCA_xy>0.0118 && DCA_xy<0.0170){
		 for(int iPthatWeightBin=0; iPtHatWeightBin<nPthatWeightBin; iPthatWeightBin++){

		 double ptlow= PthatWeightBin[iPthatWeightBin];
		 double pthi= PthatWeightBin[iPthatWeightBin+1];




		 }// end for iPthatWeightBin
		 }// end if DCA_xy

		 }// end for ientries
		 */
}// end main


