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



void DptReWeight(){
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

	TFile* fPbPbMC = new TFile("bFeedDownPbPbMC_FineDPt.hist.root");
	TFile* fPbPbMBMC = new TFile("bFeedDownPbPbMBMC_FineDPt.hist.root");



	const int nPtBins = 14;
	float ptBins[nPtBins+1] = {2.,3.,4.,5.,6.,8.,10.,12.5,15.0,20.,25.,30.,40.,60.,100};

	const int nBinX = 220;
	Float_t binsX[nBinX+1];
	Float_t binPt=0.1;
	Float_t iPt=2;
	for(int i =0; i<=nBinX; i++){
		binsX[i]=iPt;
		if(iPt<10) binPt=0.1;
		if(iPt>=10 && iPt< 20) binPt=0.25;
		if(iPt>=20 && iPt< 40) binPt=0.5;
		if(iPt>=40) binPt =1;
		iPt = iPt+binPt;
		cout<<"i = "<<i<<" , binsX = "<<binsX[i]<<endl;
	}

	double BinScaleFactor=1;
	TH1D* h_BinRescale= new TH1D("h_BinRescale=","h_BinRescale=",nBinX,binsX);
	h_BinRescale->Sumw2();
	for(int i =0; i<=nBinX; i++){
		if(i<80) BinScaleFactor=10;
		if(i>=80 && i<120) BinScaleFactor=4;
		if(i>=120 && i<160) BinScaleFactor=2;
		if(i>=160) BinScaleFactor=1;

		h_BinRescale->SetBinContent(i+1,BinScaleFactor);
	}

	const int nBinY = 20;
	Float_t binsY[nBinY+1];
	float firstBinYWidth = 0.001;
	float binYWidthRatio = 1.27;
	binsY[0]=0;
	for(int i=1; i<=nBinY; i++)
	{binsY[i] = binsY[i-1]+firstBinYWidth*pow(binYWidthRatio,i-1);}
	cout<<"last y bin: "<<binsY[nBinY]<<endl;

	const int nBinZ = 20;
	Float_t binsZ[nBinZ+1];
	float firstBinZ = 3.5;
	float binWidthZ = 5;
	for(int i=0; i<=nBinZ; i++)
	{binsZ[i] = firstBinZ+binWidthZ*i;}



	TCanvas *C_BinScale = new TCanvas("C_BinScale","C_BinScale",800,800);
	C_BinScale->cd();
	h_BinRescale->Draw();



	const int nCent = 5;
	const int nPtWeight = 2;
	TH3D* hMCPSignal[nCent][nPtWeight];
	TH3D* hMCNPSignal[nCent][nPtWeight];
	//  TH3D* hPtMD0DcaMCPSignal[nCent][nPtWeight];
	//  TH3D* hPtMD0DcaMCPSwapped[nCent][nPtWeight];
	TH3D* hMCPSignalPbPb[nCent][nPtWeight];
	TH3D* hMCNPSignalPbPb[nCent][nPtWeight];
	TH3D* hMCPSignalPbPbMB[nCent][nPtWeight];
	TH3D* hMCNPSignalPbPbMB[nCent][nPtWeight];


	TH1D* hD0DcaMCPSignal_Dpt[nCent][nPtWeight];
	TH1D* hD0DcaMCNPSignal_Dpt[nCent][nPtWeight];

	TH1D* hD0DcaMCPSignal_Dpt_Norm[nCent][nPtWeight];
	TH1D* hD0DcaMCNPSignal_Dpt_Norm[nCent][nPtWeight];


	//  TH1D* hD0DcaMCPSignal0_Dpt[nCent][nPtWeight][nPtBins];
	//  TH1D* hD0DcaMCNPSignal0_Dpt[nCent][nPtWeight][nPtBins];



	const char* CentArr[] ={"cent0to100","cent0to10", "cent10to30", "cent30to50", "cent50to100"};
	const char* PtWeightArr[] ={"PtWeight","NoWeight"};

	std::string iCentStr = "cent0to10";
	std::string iPtWeightStr = "PtWeight";
	std::string PtRangeStr = "all pt";
	int ptrangecut = 1;
	if(ptrangecut ==0){
		PtRangeStr = "pt30to40";
	}
//	double ptlow = 30;
//	double pthigh = 40;

	double hD0DcaMCPSignal_Dpt_Integral[nCent][nPtWeight];
	double hD0DcaMCNPSignal_Dpt_Integral[nCent][nPtWeight];

	double hD0DcaMCPSignal_Dpt_Entries[nCent][nPtWeight];
	double hD0DcaMCNPSignal_Dpt_Entries[nCent][nPtWeight];

	// get the TH3D and project to TH1D
	for(int iCent=0; iCent<nCent; iCent++){
		iCentStr= CentArr[iCent];
		//    cutCentralityBin=cutCentralityBinArr[iCent];
		for(int iPtWeight=0 ; iPtWeight<nPtWeight ; iPtWeight++){
			iPtWeightStr= PtWeightArr[iPtWeight];
			cout<<"iCent = "<<iCent<<" , iPtWeight = "<<iPtWeight<<endl;

			cout<<"check 1"<<endl;
			hMCPSignalPbPb[iCent][iPtWeight] = (TH3D*)fPbPbMC->Get(Form("hMCPSignal_%s%s",iCentStr.c_str(), iPtWeightStr.c_str() ));
			hMCNPSignalPbPb[iCent][iPtWeight] = (TH3D*)fPbPbMC->Get(Form("hMCNPSignal_%s%s",iCentStr.c_str(), iPtWeightStr.c_str()));
			hMCPSignalPbPbMB[iCent][iPtWeight] = (TH3D*)fPbPbMBMC->Get(Form("hMCPSignal_%s%s",iCentStr.c_str(), iPtWeightStr.c_str()));
			hMCNPSignalPbPbMB[iCent][iPtWeight] = (TH3D*)fPbPbMBMC->Get(Form("hMCNPSignal_%s%s",iCentStr.c_str(), iPtWeightStr.c_str()));

			hMCPSignalPbPb[iCent][iPtWeight]->Sumw2();
			hMCNPSignalPbPb[iCent][iPtWeight]->Sumw2();
			hMCPSignalPbPbMB[iCent][iPtWeight]->Sumw2();
			hMCNPSignalPbPbMB[iCent][iPtWeight]->Sumw2();

			cout<<"check 2"<<endl;

			hMCPSignal[iCent][iPtWeight] = (TH3D*)hMCPSignalPbPb[iCent][iPtWeight]->Clone(Form("hMCPSignal_%s%s",iCentStr.c_str(), iPtWeightStr.c_str()));
			hMCPSignal[iCent][iPtWeight]->Sumw2();
			hMCPSignal[iCent][iPtWeight]->Add(hMCPSignalPbPbMB[iCent][iPtWeight]);

			hMCNPSignal[iCent][iPtWeight] = (TH3D*)hMCNPSignalPbPb[iCent][iPtWeight]->Clone(Form("hMCNPSignal_%s%s",iCentStr.c_str(), iPtWeightStr.c_str()));
			hMCNPSignal[iCent][iPtWeight]->Sumw2();
			hMCNPSignal[iCent][iPtWeight]->Add(hMCNPSignalPbPbMB[iCent][iPtWeight]);


			cout<<"check 4"<<endl;


			cout<<"check 6"<<endl;
			hD0DcaMCPSignal_Dpt[iCent][iPtWeight] = (TH1D*)hMCPSignal[iCent][iPtWeight]->Project3D("x")->Clone(Form("hD0DcaMCPSignal_Dpt_%s%s",iCentStr.c_str(), iPtWeightStr.c_str()));
			hD0DcaMCPSignal_Dpt[iCent][iPtWeight]->Sumw2();


			cout<<"check 7"<<endl;
			hD0DcaMCNPSignal_Dpt[iCent][iPtWeight] = (TH1D*)hMCNPSignal[iCent][iPtWeight]->Project3D("x")->Clone(Form("hD0DcaMCNPSignal_Dpt_%s%s",iCentStr.c_str(), iPtWeightStr.c_str()));
			hD0DcaMCNPSignal_Dpt[iCent][iPtWeight]->Sumw2();

			cout<<"check 7.1"<<endl;

			hD0DcaMCPSignal_Dpt_Integral[iCent][iPtWeight]= hD0DcaMCPSignal_Dpt[iCent][iPtWeight]->Integral();
			hD0DcaMCNPSignal_Dpt_Integral[iCent][iPtWeight]=hD0DcaMCNPSignal_Dpt[iCent][iPtWeight]->Integral();

			cout<<"check 7.2"<<endl;
			hD0DcaMCPSignal_Dpt_Entries[iCent][iPtWeight]=hD0DcaMCPSignal_Dpt[iCent][iPtWeight]->GetEntries();
			hD0DcaMCNPSignal_Dpt_Entries[iCent][iPtWeight]=hD0DcaMCNPSignal_Dpt[iCent][iPtWeight]->GetEntries();

			cout<<"check 7.3"<<endl;
			hD0DcaMCPSignal_Dpt[iCent][iPtWeight]->Scale(1/ hD0DcaMCPSignal_Dpt_Integral[iCent][iPtWeight]);
			hD0DcaMCNPSignal_Dpt[iCent][iPtWeight]->Scale(1/ hD0DcaMCNPSignal_Dpt_Integral[iCent][iPtWeight]);


			// rebin to lower fluctuations.
			//			hD0DcaMCPSignal_Dpt[iCent][iPtWeight]->Rebin(2);
			//			hD0DcaMCNPSignal_Dpt[iCent][iPtWeight]->Rebin(2);

			// rescal bin content (cancel the bin width effect)
			hD0DcaMCPSignal_Dpt[iCent][iPtWeight]->Multiply(h_BinRescale); 
			hD0DcaMCNPSignal_Dpt[iCent][iPtWeight]->Multiply(h_BinRescale);


		} // end  for(int iPthatWeight)
	} // end   for(int iCent=0; iCent<nCent; iCent++)

	cout<<"bin 0 = "<< hD0DcaMCPSignal_Dpt[0][0]->GetBinContent(0)<<endl;
	cout<<"bin 1 = "<< hD0DcaMCPSignal_Dpt[0][0]->GetBinContent(1)<<endl;
	cout<<"bin 120 = "<< hD0DcaMCPSignal_Dpt[0][0]->GetBinContent(120)<<endl;
	cout<<"bin 121 = "<< hD0DcaMCPSignal_Dpt[0][0]->GetBinContent(121)<<endl;
	cout<<"bin 122 = "<< hD0DcaMCPSignal_Dpt[0][0]->GetBinContent(122)<<endl;
	cout<<"bin 123 = "<< hD0DcaMCPSignal_Dpt[0][0]->GetBinContent(123)<<endl;

	cout<<"bin 0 = "<< h_BinRescale->GetBinContent(0)<<endl;
	cout<<"bin 1 = "<< h_BinRescale->GetBinContent(1)<<endl;
	cout<<"bin 120 = "<< h_BinRescale->GetBinContent(120)<<endl;
	cout<<"bin 121 = "<< h_BinRescale->GetBinContent(121)<<endl;
	cout<<"bin 122 = "<< h_BinRescale->GetBinContent(122)<<endl;
	cout<<"bin 123 = "<< h_BinRescale->GetBinContent(123)<<endl;



	cout<<"check 8"<<endl;

	TCanvas *c_P[nCent];
	TCanvas *c_NP[nCent];

	TLegend *l_P[nCent];
	TLegend *l_NP[nCent];

	TH1D *hD0DcaMCPSignal_Dpt_ratio[nCent];
	TH1D *hD0DcaMCNPSignal_Dpt_ratio[nCent];

	TF1 *f_MCPRatio[nCent];
	TF1 *f_MCNPRatio[nCent];


	for(int iCent=0; iCent<nCent; iCent++){
		iCentStr= CentArr[iCent];

		// plot Prompot Dpt
		c_P[iCent] = new TCanvas(Form("c_P%s",iCentStr.c_str()),Form("c_P%s",iCentStr.c_str()),400,800);
		c_P[iCent]->Divide(1,2);
		c_P[iCent]->cd(1);

		hD0DcaMCPSignal_Dpt[iCent][0]->SetLineColor(1);
		hD0DcaMCPSignal_Dpt[iCent][0]->Draw();
		hD0DcaMCPSignal_Dpt[iCent][1]->SetLineColor(2);
		hD0DcaMCPSignal_Dpt[iCent][1]->Draw("SAME");

		cout<<"check 9"<<endl;

		l_P[iCent] = new TLegend(0.5,0.65,0.88,0.88);
		l_P[iCent]->AddEntry((TObject*)0,Form("%s",iCentStr.c_str()),"");    
		l_P[iCent]->AddEntry(hD0DcaMCPSignal_Dpt[iCent][0],"Prompt Dpt Weight","l");
		l_P[iCent]->AddEntry(hD0DcaMCPSignal_Dpt[iCent][1],"Prompt Dpt NonWeight","l");
		l_P[iCent]->SetBorderSize(0);
		l_P[iCent]->Draw();

		c_P[iCent]->cd(2);

		hD0DcaMCPSignal_Dpt_ratio[iCent]=(TH1D*)hD0DcaMCPSignal_Dpt[iCent][0]->Clone(Form("hD0DcaMCPSignal_Dpt_ratio_%s",iCentStr.c_str()));
		// hD0DcaMCPSignal_Dpt_ratio[iCent]->Sumw2();
		hD0DcaMCPSignal_Dpt_ratio[iCent]->Divide(hD0DcaMCPSignal_Dpt[iCent][1]);
		hD0DcaMCPSignal_Dpt_ratio[iCent]->Draw();

		//		f_MCPRatio[iCent] = new TF1(Form("f_MCPRatio_%d",iCent),"expo",4,100);
		/*
			 f_MCPRatio[iCent] = new TF1(Form("f_MCPRatio_%d",iCent),"[0]+[1]/TMath::Log(x)",4,50);
		// not expo, maybe log, or 1/x^2
		hD0DcaMCPSignal_Dpt_ratio[iCent]->Fit(Form("f_MCPRatio_%d",iCent),"MR");
		hD0DcaMCPSignal_Dpt_ratio[iCent]->Fit(Form("f_MCPRatio_%d",iCent),"MR");
		hD0DcaMCPSignal_Dpt_ratio[iCent]->Fit(Form("f_MCPRatio_%d",iCent),"MR");
		hD0DcaMCPSignal_Dpt_ratio[iCent]->Fit(Form("f_MCPRatio_%d",iCent),"MR");
		*/

		// plot Non-Prompt Dpt

		c_NP[iCent] = new TCanvas(Form("c_NP%s",iCentStr.c_str()),Form("c_NP%s",iCentStr.c_str()),400,800);
		c_NP[iCent]->Divide(1,2);
		c_NP[iCent]->cd(1);

		hD0DcaMCNPSignal_Dpt[iCent][0]->SetLineColor(1);
		hD0DcaMCNPSignal_Dpt[iCent][0]->Draw();
		hD0DcaMCNPSignal_Dpt[iCent][1]->SetLineColor(2);
		hD0DcaMCNPSignal_Dpt[iCent][1]->Draw("SAME");

		cout<<"check 9"<<endl;

		l_NP[iCent] = new TLegend(0.5,0.65,0.88,0.88);
		l_NP[iCent]->AddEntry((TObject*)0,Form("%s",iCentStr.c_str()),"");
		l_NP[iCent]->AddEntry(hD0DcaMCNPSignal_Dpt[iCent][0],"Prompt Dpt Weight","l");
		l_NP[iCent]->AddEntry(hD0DcaMCNPSignal_Dpt[iCent][1],"Prompt Dpt NonWeight","l");
		l_NP[iCent]->SetBorderSize(0);
		l_NP[iCent]->Draw();

		c_NP[iCent]->cd(2);

		hD0DcaMCNPSignal_Dpt_ratio[iCent]=(TH1D*)hD0DcaMCNPSignal_Dpt[iCent][0]->Clone(Form("hD0DcaMCNPSignal_Dpt_ratio_%s",iCentStr.c_str()));
		hD0DcaMCNPSignal_Dpt_ratio[iCent]->Sumw2();
		hD0DcaMCNPSignal_Dpt_ratio[iCent]->Divide(hD0DcaMCNPSignal_Dpt[iCent][1]);
		hD0DcaMCNPSignal_Dpt_ratio[iCent]->Draw();


	} // end for int iCent
	// end of Dpt distribution plot and histo-ratio

	// begin reweight

	TH3D* hMCPSignal_DptReWeight[nCent];
	TH3D* hMCNPSignal_DptReWeight[nCent];

	TH1D* hD0DcaMCPSignal_DptReWeight[nCent];
	TH1D* hD0DcaMCNPSignal_DptReWeight[nCent];

	TH1D* hDptMCPSignal_DptReWeight[nCent];
	TH1D* hDptMCNPSignal_DptReWeight[nCent];


	for(int iCent=0; iCent<nCent; iCent++){
		iCentStr= CentArr[iCent];
		hMCPSignal_DptReWeight[iCent]=(TH3D*)hMCPSignal[iCent][1]->Clone(Form("hMCPSignal_DptReWeight_%s", iCentStr.c_str()));
		hMCNPSignal_DptReWeight[iCent]=(TH3D*)hMCNPSignal[iCent][1]->Clone(Form("hMCNPSignal_DptReWeight_%s", iCentStr.c_str()));
		/*
			 hMCPSignal_DptReWeight[iCent]= new TH3D(Form("hMCPSignal_DptReWeight_%s", iCentStr.c_str() ),";p_{T} (GeV/c);D^{0} DCA (cm);flight distance significance",nBinX,binsX,nBinY,binsY,nBinZ,binsZ);
			 hMCPSignal_DptReWeight[iCent]->Sumw2();
			 hMCNPSignal_DptReWeight[iCent]= new TH3D(Form("hMCNPSignal_DptReWeight_%s", iCentStr.c_str() ),";p_{T} (GeV/c);D^{0} DCA (cm);flight distance significance",nBinX,binsX,nBinY,binsY,nBinZ,binsZ);
			 hMCNPSignal_DptReWeight[iCent]->Sumw2();
			 */
		for(int iBinX=1; iBinX<=nBinX; iBinX++){ // BinX for Dpt, BinY for D0DcA, BinZ for flight distance significance
			for(int iBinY=1; iBinY<=nBinY; iBinY++){
				for(int iBinZ=1; iBinZ<=nBinZ; iBinZ++){

					double content3d_MCP = hMCPSignal[iCent][1]->GetBinContent(iBinX,iBinY,iBinZ);
					double error3d_MCP = hMCPSignal[iCent][1]->GetBinError(iBinX,iBinY,iBinZ);
					double DptBinRatio_MCP = hD0DcaMCPSignal_Dpt_ratio[0]->GetBinContent(iBinX); // use all centrality bins to reweight dpt
					double DptBinRatioErr_MCP = hD0DcaMCPSignal_Dpt_ratio[0]->GetBinError(iBinX);
					hMCPSignal_DptReWeight[iCent]->SetBinContent(iBinX,iBinY,iBinZ,content3d_MCP*DptBinRatio_MCP );
					hMCPSignal_DptReWeight[iCent]->SetBinError(iBinX,iBinY,iBinZ,TMath::Sqrt(TMath::Power(content3d_MCP*DptBinRatioErr_MCP,2)+TMath::Power(error3d_MCP*DptBinRatio_MCP,2)));	

					double content3d_MCNP = hMCNPSignal[iCent][1]->GetBinContent(iBinX,iBinY,iBinZ);
					double error3d_MCNP = hMCNPSignal[iCent][1]->GetBinError(iBinX,iBinY,iBinZ);
					double DptBinRatio_MCNP = hD0DcaMCNPSignal_Dpt_ratio[0]->GetBinContent(iBinX); // use all centrality bins to reweight dpt
					double DptBinRatioErr_MCNP = hD0DcaMCNPSignal_Dpt_ratio[0]->GetBinError(iBinX);
					hMCNPSignal_DptReWeight[iCent]->SetBinContent(iBinX,iBinY,iBinZ,content3d_MCNP*DptBinRatio_MCNP );
					hMCNPSignal_DptReWeight[iCent]->SetBinError(iBinX,iBinY,iBinZ,TMath::Sqrt(TMath::Power(content3d_MCNP*DptBinRatioErr_MCNP,2)+TMath::Power(error3d_MCNP*DptBinRatio_MCNP,2)));



				}// end for(int iBinX=1; iBinX<nBinX; iBinX++)
			}// end for(int iBinX=1; iBinX<nBinX; iBinX++)
		}// end for(int iBinX=1; iBinX<nBinX; iBinX++)

		//      hD0DcaMCPSignal_DptReWeight[iCent] = (TH1D*)hMCPSignal_DptReWeight[iCent]->Project3D("y")->Clone(Form("hD0DcaMCPSignal_DptReWeight_%s",iCentStr.c_str()));
		//      hD0DcaMCPSignal_DptReWeight[iCent]->Sumw2();
		hDptMCPSignal_DptReWeight[iCent] = (TH1D*)hMCPSignal_DptReWeight[iCent]->Project3D("x")->Clone(Form("hDptMCPSignal_DptReWeight_%s",iCentStr.c_str()));
		cout<<"before"<<endl;
		hDptMCPSignal_DptReWeight[iCent]->Sumw2();
		cout<<"after"<<endl;

		//      hD0DcaMCNPSignal_DptReWeight[iCent] = (TH1D*)hMCNPSignal_DptReWeight[iCent]->Project3D("y")->Clone(Form("hD0DcaMCNPSignal_DptReWeight_%s",iCentStr.c_str()));
		//      hD0DcaMCNPSignal_DptReWeight[iCent]->Sumw2();
		hDptMCNPSignal_DptReWeight[iCent] = (TH1D*)hMCNPSignal_DptReWeight[iCent]->Project3D("x")->Clone(Form("hDptMCNPSignal_DptReWeight_%s",iCentStr.c_str()));
		hDptMCNPSignal_DptReWeight[iCent]->Sumw2();


	} // end for(int iCent=0; iCent<nCent; iCent++)


	// project to 1D based on Dpt range- pthatweighted, non-weighted, Dptweight

	//  const int nPtBins = 14;
	//  float ptBins[nPtBins+1] = {2.,3.,4.,5.,6.,8.,10.,12.5,15.0,20.,25.,30.,40.,60.,100};

	TH1D* hD0DcaMCPSignal_PtHatWeight_DptBin[nCent][nPtBins];
	TH1D* hD0DcaMCNPSignal_PtHatWeight_DptBin[nCent][nPtBins];
	TH1D* hDptMCPSignal_PtHatWeight_DptBin[nCent][nPtBins];
	TH1D* hDptMCNPSignal_PtHatWeight_DptBin[nCent][nPtBins];

	TH1D* hD0DcaMCPSignal_NoWeight_DptBin[nCent][nPtBins];
	TH1D* hD0DcaMCNPSignal_NoWeight_DptBin[nCent][nPtBins];
	TH1D* hDptMCPSignal_NoWeight_DptBin[nCent][nPtBins];
	TH1D* hDptMCNPSignal_NoWeight_DptBin[nCent][nPtBins];

	TH1D* hD0DcaMCPSignal_NoWeightRatio_DptBin[nCent][nPtBins];
	TH1D* hD0DcaMCNPSignal_NoWeightRatio_DptBin[nCent][nPtBins];
	TH1D* hDptMCPSignal_NoWeightRatio_DptBin[nCent][nPtBins];
	TH1D* hDptMCNPSignal_NoWeightRatio_DptBin[nCent][nPtBins];

	TH1D* hD0DcaMCPSignal_DptReWeight_DptBin[nCent][nPtBins];
	TH1D* hD0DcaMCNPSignal_DptReWeight_DptBin[nCent][nPtBins];
	TH1D* hDptMCPSignal_DptReWeight_DptBin[nCent][nPtBins];
	TH1D* hDptMCNPSignal_DptReWeight_DptBin[nCent][nPtBins];

	TH1D* hD0DcaMCPSignal_DptReWeightRatio_DptBin[nCent][nPtBins];
	TH1D* hD0DcaMCNPSignal_DptReWeightRatio_DptBin[nCent][nPtBins];
	TH1D* hDptMCPSignal_DptReWeightRatio_DptBin[nCent][nPtBins];
	TH1D* hDptMCNPSignal_DptReWeightRatio_DptBin[nCent][nPtBins];

/*
	TCanvas *c_testPt[nCent];
	c_testPt[0]= new TCanvas("testpt_0to100");
	c_testPt[0]->Divide(4,4);
  c_testPt[1]= new TCanvas("testpt_1");
  c_testPt[1]->Divide(4,4);
  c_testPt[2]= new TCanvas("testpt_2");
  c_testPt[2]->Divide(4,4);
  c_testPt[3]= new TCanvas("testpt_3");
  c_testPt[3]->Divide(4,4);
  c_testPt[4]= new TCanvas("testpt_4");
  c_testPt[4]->Divide(4,4);
*/


	for(int iPtBins=0; iPtBins<nPtBins; iPtBins++){
		Float_t ptLow=ptBins[iPtBins];
		Float_t ptHigh=ptBins[iPtBins+1];
		Float_t deltaPt=0.001;
		cout<<"iPtBins = "<<iPtBins<<" ,ptLow = "<<ptLow<<" ,ptHih = "<<ptHigh<<endl;

		for(int iCent=0; iCent<nCent; iCent++){
			iCentStr= CentArr[iCent];
		
//			c_testPt[iCent]->cd(iPtBins+1);
			//set TH3D Dpt range
			hMCPSignal[iCent][0]->GetXaxis()->SetRangeUser(ptLow+deltaPt,ptHigh-deltaPt);
			hMCNPSignal[iCent][0]->GetXaxis()->SetRangeUser(ptLow+deltaPt,ptHigh-deltaPt);

			hMCPSignal[iCent][1]->GetXaxis()->SetRangeUser(ptLow+deltaPt,ptHigh-deltaPt);
			hMCNPSignal[iCent][1]->GetXaxis()->SetRangeUser(ptLow+deltaPt,ptHigh-deltaPt);

			hMCPSignal_DptReWeight[iCent]->GetXaxis()->SetRangeUser(ptLow+deltaPt,ptHigh-deltaPt);
			hMCNPSignal_DptReWeight[iCent]->GetXaxis()->SetRangeUser(ptLow+deltaPt,ptHigh-deltaPt);


			//project	D0DCA
			hD0DcaMCPSignal_PtHatWeight_DptBin[iCent][iPtBins]= (TH1D*)hMCPSignal[iCent][0]->Project3D("y")->Clone(Form("hD0DcaMCPSignal_PtHatWeight_%sPtbin%d",iCentStr.c_str(),iPtBins));
			hD0DcaMCPSignal_PtHatWeight_DptBin[iCent][iPtBins]->Scale(1/hD0DcaMCPSignal_PtHatWeight_DptBin[iCent][iPtBins]->Integral());

			hD0DcaMCNPSignal_PtHatWeight_DptBin[iCent][iPtBins]= (TH1D*)hMCNPSignal[iCent][0]->Project3D("y")->Clone(Form("hD0DcaMCNPSignal_PtHatWeight_%sPtbin%d",iCentStr.c_str(),iPtBins));
			hD0DcaMCNPSignal_PtHatWeight_DptBin[iCent][iPtBins]->Scale(1/hD0DcaMCNPSignal_PtHatWeight_DptBin[iCent][iPtBins]->Integral());
			//
			hD0DcaMCPSignal_NoWeight_DptBin[iCent][iPtBins]= (TH1D*)hMCPSignal[iCent][1]->Project3D("y")->Clone(Form("hD0DcaMCPSignal_NoWeight_%sPtbin%d",iCentStr.c_str(),iPtBins));
			hD0DcaMCPSignal_NoWeight_DptBin[iCent][iPtBins]->Scale(1/hD0DcaMCPSignal_NoWeight_DptBin[iCent][iPtBins]->Integral());

			hD0DcaMCNPSignal_NoWeight_DptBin[iCent][iPtBins]= (TH1D*)hMCNPSignal[iCent][1]->Project3D("y")->Clone(Form("hD0DcaMCNPSignal_NoWeight_%sPtbin%d",iCentStr.c_str(),iPtBins));
			hD0DcaMCNPSignal_NoWeight_DptBin[iCent][iPtBins]->Scale(1/hD0DcaMCNPSignal_NoWeight_DptBin[iCent][iPtBins]->Integral());

			//
			hD0DcaMCPSignal_DptReWeight_DptBin[iCent][iPtBins]= (TH1D*)hMCPSignal_DptReWeight[iCent]->Project3D("y")->Clone(Form("hD0DcaMCPSignal_DptReWeight_%sPtbin%d",iCentStr.c_str(),iPtBins));
			hD0DcaMCPSignal_DptReWeight_DptBin[iCent][iPtBins]->Scale(1/hD0DcaMCPSignal_DptReWeight_DptBin[iCent][iPtBins]->Integral());

			hD0DcaMCNPSignal_DptReWeight_DptBin[iCent][iPtBins]= (TH1D*)hMCNPSignal_DptReWeight[iCent]->Project3D("y")->Clone(Form("hD0DcaMCNPSignal_DptReWeight_%sPtbin%d",iCentStr.c_str(),iPtBins));
			hD0DcaMCNPSignal_DptReWeight_DptBin[iCent][iPtBins]->Scale(1/hD0DcaMCNPSignal_DptReWeight_DptBin[iCent][iPtBins]->Integral());
			// calculate the ratio histograms
			hD0DcaMCPSignal_NoWeightRatio_DptBin[iCent][iPtBins]=(TH1D*)hD0DcaMCPSignal_NoWeight_DptBin[iCent][iPtBins]->Clone(Form("hD0DcaMCPSignal_NoWeightRatio_%sPtbin%d",iCentStr.c_str(),iPtBins));
			hD0DcaMCPSignal_NoWeightRatio_DptBin[iCent][iPtBins]->Divide(hD0DcaMCPSignal_NoWeightRatio_DptBin[iCent][iPtBins],hD0DcaMCPSignal_PtHatWeight_DptBin[iCent][iPtBins],1,1);

			hD0DcaMCNPSignal_NoWeightRatio_DptBin[iCent][iPtBins]=(TH1D*)hD0DcaMCNPSignal_NoWeight_DptBin[iCent][iPtBins]->Clone(Form("hD0DcaMCNPSignal_NoWeightRatio_%sPtbin%d",iCentStr.c_str(),iPtBins));
			hD0DcaMCNPSignal_NoWeightRatio_DptBin[iCent][iPtBins]->Divide(hD0DcaMCNPSignal_NoWeightRatio_DptBin[iCent][iPtBins],hD0DcaMCNPSignal_PtHatWeight_DptBin[iCent][iPtBins],1,1);
			//
			hD0DcaMCPSignal_DptReWeightRatio_DptBin[iCent][iPtBins]=(TH1D*)hD0DcaMCPSignal_DptReWeight_DptBin[iCent][iPtBins]->Clone(Form("hD0DcaMCPSignal_DptReWeightRatio_%sPtbin%d",iCentStr.c_str(),iPtBins));
			hD0DcaMCPSignal_DptReWeightRatio_DptBin[iCent][iPtBins]->Divide(hD0DcaMCPSignal_DptReWeightRatio_DptBin[iCent][iPtBins],hD0DcaMCPSignal_PtHatWeight_DptBin[iCent][iPtBins],1,1);

			hD0DcaMCNPSignal_DptReWeightRatio_DptBin[iCent][iPtBins]=(TH1D*)hD0DcaMCNPSignal_DptReWeight_DptBin[iCent][iPtBins]->Clone(Form("hD0DcaMCNPSignal_DptReWeightRatio_%sPtbin%d",iCentStr.c_str(),iPtBins));
			hD0DcaMCNPSignal_DptReWeightRatio_DptBin[iCent][iPtBins]->Divide(hD0DcaMCNPSignal_DptReWeightRatio_DptBin[iCent][iPtBins],hD0DcaMCNPSignal_PtHatWeight_DptBin[iCent][iPtBins],1,1);




			//project	Dpt
			hDptMCPSignal_PtHatWeight_DptBin[iCent][iPtBins]= (TH1D*)hMCPSignal[iCent][0]->Project3D("x")->Clone(Form("hDptMCPSignal_PtHatWeight_%sPtbin%d",iCentStr.c_str(),iPtBins));
			hDptMCPSignal_PtHatWeight_DptBin[iCent][iPtBins]->Scale(1/hDptMCPSignal_PtHatWeight_DptBin[iCent][iPtBins]->Integral());

//			hDptMCPSignal_PtHatWeight_DptBin[iCent][iPtBins]->Draw();

			hDptMCNPSignal_PtHatWeight_DptBin[iCent][iPtBins]= (TH1D*)hMCNPSignal[iCent][0]->Project3D("x")->Clone(Form("hDptMCNPSignal_PtHatWeight_%sPtbin%d",iCentStr.c_str(),iPtBins));
			hDptMCNPSignal_PtHatWeight_DptBin[iCent][iPtBins]->Scale(1/hDptMCNPSignal_PtHatWeight_DptBin[iCent][iPtBins]->Integral());
			//
			hDptMCPSignal_NoWeight_DptBin[iCent][iPtBins]= (TH1D*)hMCPSignal[iCent][1]->Project3D("x")->Clone(Form("hDptMCPSignal_NoWeight_%sPtbin%d",iCentStr.c_str(),iPtBins));
			hDptMCPSignal_NoWeight_DptBin[iCent][iPtBins]->Scale(1/hDptMCPSignal_NoWeight_DptBin[iCent][iPtBins]->Integral());

			hDptMCNPSignal_NoWeight_DptBin[iCent][iPtBins]= (TH1D*)hMCNPSignal[iCent][1]->Project3D("x")->Clone(Form("hDptMCNPSignal_NoWeight_%sPtbin%d",iCentStr.c_str(),iPtBins));
			hDptMCNPSignal_NoWeight_DptBin[iCent][iPtBins]->Scale(1/hDptMCNPSignal_NoWeight_DptBin[iCent][iPtBins]->Integral());

			//
			hDptMCPSignal_DptReWeight_DptBin[iCent][iPtBins]= (TH1D*)hMCPSignal_DptReWeight[iCent]->Project3D("x")->Clone(Form("hDptMCPSignal_DptReWeight_%sPtbin%d",iCentStr.c_str(),iPtBins));
			hDptMCPSignal_DptReWeight_DptBin[iCent][iPtBins]->Scale(1/hDptMCPSignal_DptReWeight_DptBin[iCent][iPtBins]->Integral());

//      hDptMCPSignal_DptReWeight_DptBin[iCent][iPtBins]->Draw();

			hDptMCNPSignal_DptReWeight_DptBin[iCent][iPtBins]= (TH1D*)hMCNPSignal_DptReWeight[iCent]->Project3D("x")->Clone(Form("hDptMCNPSignal_DptReWeight_%sPtbin%d",iCentStr.c_str(),iPtBins));
			hDptMCNPSignal_DptReWeight_DptBin[iCent][iPtBins]->Scale(1/hDptMCNPSignal_DptReWeight_DptBin[iCent][iPtBins]->Integral());
			// calculate the ratio histograms
			hDptMCPSignal_NoWeightRatio_DptBin[iCent][iPtBins]=(TH1D*)hDptMCPSignal_NoWeight_DptBin[iCent][iPtBins]->Clone(Form("hDptMCPSignal_NoWeightRatio_%sPtbin%d",iCentStr.c_str(),iPtBins));
			hDptMCPSignal_NoWeightRatio_DptBin[iCent][iPtBins]->Divide(hDptMCPSignal_NoWeightRatio_DptBin[iCent][iPtBins],hDptMCPSignal_PtHatWeight_DptBin[iCent][iPtBins],1,1);

			hDptMCNPSignal_NoWeightRatio_DptBin[iCent][iPtBins]=(TH1D*)hDptMCNPSignal_NoWeight_DptBin[iCent][iPtBins]->Clone(Form("hDptMCNPSignal_NoWeightRatio_%sPtbin%d",iCentStr.c_str(),iPtBins));
			hDptMCNPSignal_NoWeightRatio_DptBin[iCent][iPtBins]->Divide(hDptMCNPSignal_NoWeightRatio_DptBin[iCent][iPtBins],hDptMCNPSignal_PtHatWeight_DptBin[iCent][iPtBins],1,1);
			//
			hDptMCPSignal_DptReWeightRatio_DptBin[iCent][iPtBins]=(TH1D*)hDptMCPSignal_DptReWeight_DptBin[iCent][iPtBins]->Clone(Form("hDptMCPSignal_DptReWeightRatio_%sPtbin%d",iCentStr.c_str(),iPtBins));
			hDptMCPSignal_DptReWeightRatio_DptBin[iCent][iPtBins]->Divide(hDptMCPSignal_DptReWeightRatio_DptBin[iCent][iPtBins],hDptMCPSignal_PtHatWeight_DptBin[iCent][iPtBins],1,1);

			hDptMCNPSignal_DptReWeightRatio_DptBin[iCent][iPtBins]=(TH1D*)hDptMCNPSignal_DptReWeight_DptBin[iCent][iPtBins]->Clone(Form("hDptMCNPSignal_DptReWeightRatio_%sPtbin%d",iCentStr.c_str(),iPtBins));
			hDptMCNPSignal_DptReWeightRatio_DptBin[iCent][iPtBins]->Divide(hDptMCNPSignal_DptReWeightRatio_DptBin[iCent][iPtBins],hDptMCNPSignal_PtHatWeight_DptBin[iCent][iPtBins],1,1);






		} // end for(int iCent=0; iCent<nCent; iCent++)
	}// end for(int iPtBins=0; iPtBins<nPtBins; iPtBins++)




	// plot the Dpt reweight

	TCanvas *c_MCP[nCent][nPtBins];
	TLegend *l_MCP[nCent][nPtBins][4];

	TCanvas *c_MCNP[nCent][nPtBins];
  TLegend *l_MCNP[nCent][nPtBins][4];


//	for(int iPtBins=0; iPtBins<nPtBins; iPtBins++){
		int iPtBins =12;
		Float_t ptLow=ptBins[iPtBins];
		Float_t ptHigh=ptBins[iPtBins+1];
    cout<<"iPtBins = "<<iPtBins<<" ,ptLow = "<<ptLow<<" ,ptHih = "<<ptHigh<<endl;


		for(int iCent=0; iCent<nCent; iCent++){
			iCentStr= CentArr[iCent];

			c_MCP[iCent][iPtBins]= new TCanvas(Form("MCP_pt%dcent%d",iPtBins,iCent), Form("MCP_pt%dcent%d",iPtBins,iCent) , 800,800);
		  c_MCP[iCent][iPtBins]->Divide(2,2);	
			c_MCP[iCent][iPtBins]->cd(1); // DCA distribution

	    gPad->SetLogy();
			hD0DcaMCPSignal_PtHatWeight_DptBin[iCent][iPtBins]->Draw();
			hD0DcaMCPSignal_PtHatWeight_DptBin[iCent][iPtBins]->SetLineColor(3);
      hD0DcaMCPSignal_PtHatWeight_DptBin[iCent][iPtBins]->SetMarkerStyle(24);
      hD0DcaMCPSignal_PtHatWeight_DptBin[iCent][iPtBins]->SetMarkerColor(3);
			hD0DcaMCPSignal_PtHatWeight_DptBin[iCent][iPtBins]->GetXaxis()->SetRangeUser(0,0.07);
			hD0DcaMCPSignal_NoWeight_DptBin[iCent][iPtBins]->SetLineColor(2);
      hD0DcaMCPSignal_NoWeight_DptBin[iCent][iPtBins]->SetMarkerColor(2);
      hD0DcaMCPSignal_NoWeight_DptBin[iCent][iPtBins]->SetMarkerStyle(24);
      hD0DcaMCPSignal_NoWeight_DptBin[iCent][iPtBins]->Draw("SAME");
			hD0DcaMCPSignal_DptReWeight_DptBin[iCent][iPtBins]->SetLineColor(4);
      hD0DcaMCPSignal_DptReWeight_DptBin[iCent][iPtBins]->SetMarkerColor(4);
      hD0DcaMCPSignal_DptReWeight_DptBin[iCent][iPtBins]->SetMarkerStyle(24);
      hD0DcaMCPSignal_DptReWeight_DptBin[iCent][iPtBins]->Draw("SAME");


			l_MCP[iCent][iPtBins][0] = new TLegend(0.60,0.65,0.9,0.88);
      l_MCP[iCent][iPtBins][0]->AddEntry((TObject*)0,"Non-Prompt D","");
			l_MCP[iCent][iPtBins][0]->AddEntry((TObject*)0,Form("%s",iCentStr.c_str()),"");
			l_MCP[iCent][iPtBins][0]->AddEntry((TObject*)0,Form("%d<P_{T}<%d",(int)ptLow,(int)ptHigh),"");
			l_MCP[iCent][iPtBins][0]->AddEntry(hD0DcaMCPSignal_PtHatWeight_DptBin[iCent][iPtBins],"PtHatWeighted","lp");
      l_MCP[iCent][iPtBins][0]->AddEntry(hD0DcaMCPSignal_NoWeight_DptBin[iCent][iPtBins],"NonWeighted","lp");
      l_MCP[iCent][iPtBins][0]->AddEntry(hD0DcaMCPSignal_DptReWeight_DptBin[iCent][iPtBins],"DptWeighted","lp");
			l_MCP[iCent][iPtBins][0]->SetBorderSize(0);
			l_MCP[iCent][iPtBins][0]->Draw();

			c_MCP[iCent][iPtBins]->cd(2);

      hDptMCPSignal_PtHatWeight_DptBin[iCent][iPtBins]->Draw();
      hDptMCPSignal_PtHatWeight_DptBin[iCent][iPtBins]->SetLineColor(3);
      hDptMCPSignal_PtHatWeight_DptBin[iCent][iPtBins]->SetMarkerColor(3);
      hDptMCPSignal_PtHatWeight_DptBin[iCent][iPtBins]->SetMarkerStyle(24);
			hDptMCPSignal_NoWeight_DptBin[iCent][iPtBins]->SetLineColor(2);
      hDptMCPSignal_NoWeight_DptBin[iCent][iPtBins]->SetMarkerStyle(24);
      hDptMCPSignal_NoWeight_DptBin[iCent][iPtBins]->SetMarkerColor(2);
      hDptMCPSignal_NoWeight_DptBin[iCent][iPtBins]->Draw("SAME");
			hDptMCPSignal_DptReWeight_DptBin[iCent][iPtBins]->SetLineColor(4);
      hDptMCPSignal_DptReWeight_DptBin[iCent][iPtBins]->SetMarkerColor(4);
      hDptMCPSignal_DptReWeight_DptBin[iCent][iPtBins]->SetMarkerStyle(24);
      hDptMCPSignal_DptReWeight_DptBin[iCent][iPtBins]->Draw("SAME");


			l_MCP[iCent][iPtBins][1] = new TLegend(0.65,0.65,0.9,0.88);
      // l_MCP[iCent][1]->AddEntry((TObject*)0,Form("%d<P_T<%d",ptLow,ptHigh),"");
      l_MCP[iCent][iPtBins][1]->AddEntry(hDptMCPSignal_PtHatWeight_DptBin[iCent][iPtBins],"PtHatWeighted","lp");
      l_MCP[iCent][iPtBins][1]->AddEntry(hDptMCPSignal_NoWeight_DptBin[iCent][iPtBins],"NonWeighted","lp");
      l_MCP[iCent][iPtBins][1]->AddEntry(hDptMCPSignal_DptReWeight_DptBin[iCent][iPtBins],"DptWeighted","lp");
      l_MCP[iCent][iPtBins][1]->SetBorderSize(0);
      l_MCP[iCent][iPtBins][1]->Draw();



			c_MCP[iCent][iPtBins]->cd(3);
      hD0DcaMCPSignal_NoWeightRatio_DptBin[iCent][iPtBins]->SetLineColor(2);
      hD0DcaMCPSignal_NoWeightRatio_DptBin[iCent][iPtBins]->SetMarkerColor(2);
      hD0DcaMCPSignal_NoWeightRatio_DptBin[iCent][iPtBins]->SetMarkerStyle(24);
			hD0DcaMCPSignal_NoWeightRatio_DptBin[iCent][iPtBins]->SetMinimum(0.0);
			hD0DcaMCPSignal_NoWeightRatio_DptBin[iCent][iPtBins]->SetMaximum(4);
      hD0DcaMCPSignal_NoWeightRatio_DptBin[iCent][iPtBins]->GetXaxis()->SetRangeUser(0,0.07);			
      hD0DcaMCPSignal_NoWeightRatio_DptBin[iCent][iPtBins]->Draw("SAME");
      hD0DcaMCPSignal_DptReWeightRatio_DptBin[iCent][iPtBins]->SetLineColor(4);
      hD0DcaMCPSignal_DptReWeightRatio_DptBin[iCent][iPtBins]->SetMarkerColor(4);
      hD0DcaMCPSignal_DptReWeightRatio_DptBin[iCent][iPtBins]->SetMarkerStyle(24);
      hD0DcaMCPSignal_DptReWeightRatio_DptBin[iCent][iPtBins]->Draw("SAME");

      l_MCP[iCent][iPtBins][2] = new TLegend(0.58,0.65,0.9,0.88);
      l_MCP[iCent][iPtBins][2]->AddEntry((TObject*)0,"Divided by PtHatWeighted","");
      // l_MCP[iCent][2]->AddEntry(hD0DcaMCPSignal_PtHatWeight_DptBin[iCent][iPtBins],"PtHatWeighted","l");
      l_MCP[iCent][iPtBins][2]->AddEntry(hD0DcaMCPSignal_NoWeightRatio_DptBin[iCent][iPtBins],"NonWeighted","lp");
      l_MCP[iCent][iPtBins][2]->AddEntry(hD0DcaMCPSignal_DptReWeightRatio_DptBin[iCent][iPtBins],"DptWeighted","lp");
      l_MCP[iCent][iPtBins][2]->SetBorderSize(0);
      l_MCP[iCent][iPtBins][2]->Draw();
	
		
      c_MCP[iCent][iPtBins]->cd(4);
      hDptMCPSignal_NoWeightRatio_DptBin[iCent][iPtBins]->SetLineColor(2);
      hDptMCPSignal_NoWeightRatio_DptBin[iCent][iPtBins]->SetMarkerColor(2);
      hDptMCPSignal_NoWeightRatio_DptBin[iCent][iPtBins]->SetMarkerStyle(24);
      hDptMCPSignal_NoWeightRatio_DptBin[iCent][iPtBins]->Draw("SAME");
      hDptMCPSignal_DptReWeightRatio_DptBin[iCent][iPtBins]->SetLineColor(4);
      hDptMCPSignal_DptReWeightRatio_DptBin[iCent][iPtBins]->SetMarkerColor(4);
      hDptMCPSignal_DptReWeightRatio_DptBin[iCent][iPtBins]->SetMarkerStyle(24);
      hDptMCPSignal_DptReWeightRatio_DptBin[iCent][iPtBins]->Draw("SAME");

      l_MCP[iCent][iPtBins][3] = new TLegend(0.58,0.65,0.9,0.88);
      l_MCP[iCent][iPtBins][3]->AddEntry((TObject*)0,"Divided by PtHatWeighted","");
      // l_MCP[iCent][4]->AddEntry(hDptMCPSignal_PtHatWeightRatio_DptBin[iCent][iPtBins],"PtHatWeighted","l");
      l_MCP[iCent][iPtBins][3]->AddEntry(hDptMCPSignal_NoWeightRatio_DptBin[iCent][iPtBins],"NonWeighted","lp");
      l_MCP[iCent][iPtBins][3]->AddEntry(hDptMCPSignal_DptReWeightRatio_DptBin[iCent][iPtBins],"DptWeighted","lp");
      l_MCP[iCent][iPtBins][3]->SetBorderSize(0);
      l_MCP[iCent][iPtBins][3]->Draw();


			c_MCP[iCent][iPtBins]->SaveAs(Form("Plot_DptReWeight/Prompt/DCA_Prompt_%s_pt%dto%d.pdf",iCentStr.c_str(),(int)ptLow,(int)ptHigh));



			//non-prompt

			c_MCNP[iCent][iPtBins]= new TCanvas(Form("MCNP_pt%dcent%d",iPtBins,iCent), Form("MCNP_pt%dcent%d",iPtBins,iCent) , 800,800);
		  c_MCNP[iCent][iPtBins]->Divide(2,2);	
			c_MCNP[iCent][iPtBins]->cd(1); // DCA distribution

	    gPad->SetLogy();
			hD0DcaMCNPSignal_PtHatWeight_DptBin[iCent][iPtBins]->Draw();
			hD0DcaMCNPSignal_PtHatWeight_DptBin[iCent][iPtBins]->SetLineColor(3);
      hD0DcaMCNPSignal_PtHatWeight_DptBin[iCent][iPtBins]->SetMarkerStyle(24);
      hD0DcaMCNPSignal_PtHatWeight_DptBin[iCent][iPtBins]->SetMarkerColor(3);
			hD0DcaMCNPSignal_PtHatWeight_DptBin[iCent][iPtBins]->GetXaxis()->SetRangeUser(0,0.07);
			hD0DcaMCNPSignal_NoWeight_DptBin[iCent][iPtBins]->SetLineColor(2);
      hD0DcaMCNPSignal_NoWeight_DptBin[iCent][iPtBins]->SetMarkerColor(2);
      hD0DcaMCNPSignal_NoWeight_DptBin[iCent][iPtBins]->SetMarkerStyle(24);
      hD0DcaMCNPSignal_NoWeight_DptBin[iCent][iPtBins]->Draw("SAME");
			hD0DcaMCNPSignal_DptReWeight_DptBin[iCent][iPtBins]->SetLineColor(4);
      hD0DcaMCNPSignal_DptReWeight_DptBin[iCent][iPtBins]->SetMarkerColor(4);
      hD0DcaMCNPSignal_DptReWeight_DptBin[iCent][iPtBins]->SetMarkerStyle(24);
      hD0DcaMCNPSignal_DptReWeight_DptBin[iCent][iPtBins]->Draw("SAME");


			l_MCNP[iCent][iPtBins][0] = new TLegend(0.60,0.65,0.9,0.88);
      l_MCNP[iCent][iPtBins][0]->AddEntry((TObject*)0,"Prompt D","");
			l_MCNP[iCent][iPtBins][0]->AddEntry((TObject*)0,Form("%s",iCentStr.c_str()),"");
			l_MCNP[iCent][iPtBins][0]->AddEntry((TObject*)0,Form("%d<P_{T}<%d",(int)ptLow,(int)ptHigh),"");
			l_MCNP[iCent][iPtBins][0]->AddEntry(hD0DcaMCNPSignal_PtHatWeight_DptBin[iCent][iPtBins],"PtHatWeighted","lp");
      l_MCNP[iCent][iPtBins][0]->AddEntry(hD0DcaMCNPSignal_NoWeight_DptBin[iCent][iPtBins],"NonWeighted","lp");
      l_MCNP[iCent][iPtBins][0]->AddEntry(hD0DcaMCNPSignal_DptReWeight_DptBin[iCent][iPtBins],"DptWeighted","lp");
			l_MCNP[iCent][iPtBins][0]->SetBorderSize(0);
			l_MCNP[iCent][iPtBins][0]->Draw();

			c_MCNP[iCent][iPtBins]->cd(2);

      hDptMCNPSignal_PtHatWeight_DptBin[iCent][iPtBins]->Draw();
      hDptMCNPSignal_PtHatWeight_DptBin[iCent][iPtBins]->SetLineColor(3);
      hDptMCNPSignal_PtHatWeight_DptBin[iCent][iPtBins]->SetMarkerColor(3);
      hDptMCNPSignal_PtHatWeight_DptBin[iCent][iPtBins]->SetMarkerStyle(24);
			hDptMCNPSignal_NoWeight_DptBin[iCent][iPtBins]->SetLineColor(2);
      hDptMCNPSignal_NoWeight_DptBin[iCent][iPtBins]->SetMarkerStyle(24);
      hDptMCNPSignal_NoWeight_DptBin[iCent][iPtBins]->SetMarkerColor(2);
      hDptMCNPSignal_NoWeight_DptBin[iCent][iPtBins]->Draw("SAME");
			hDptMCNPSignal_DptReWeight_DptBin[iCent][iPtBins]->SetLineColor(4);
      hDptMCNPSignal_DptReWeight_DptBin[iCent][iPtBins]->SetMarkerColor(4);
      hDptMCNPSignal_DptReWeight_DptBin[iCent][iPtBins]->SetMarkerStyle(24);
      hDptMCNPSignal_DptReWeight_DptBin[iCent][iPtBins]->Draw("SAME");


			l_MCNP[iCent][iPtBins][1] = new TLegend(0.65,0.65,0.9,0.88);
      // l_MCNP[iCent][1]->AddEntry((TObject*)0,Form("%d<P_T<%d",ptLow,ptHigh),"");
      l_MCNP[iCent][iPtBins][1]->AddEntry(hDptMCNPSignal_PtHatWeight_DptBin[iCent][iPtBins],"PtHatWeighted","lp");
      l_MCNP[iCent][iPtBins][1]->AddEntry(hDptMCNPSignal_NoWeight_DptBin[iCent][iPtBins],"NonWeighted","lp");
      l_MCNP[iCent][iPtBins][1]->AddEntry(hDptMCNPSignal_DptReWeight_DptBin[iCent][iPtBins],"DptWeighted","lp");
      l_MCNP[iCent][iPtBins][1]->SetBorderSize(0);
      l_MCNP[iCent][iPtBins][1]->Draw();



			c_MCNP[iCent][iPtBins]->cd(3);
      hD0DcaMCNPSignal_NoWeightRatio_DptBin[iCent][iPtBins]->SetLineColor(2);
      hD0DcaMCNPSignal_NoWeightRatio_DptBin[iCent][iPtBins]->SetMarkerColor(2);
      hD0DcaMCNPSignal_NoWeightRatio_DptBin[iCent][iPtBins]->SetMarkerStyle(24);
			hD0DcaMCNPSignal_NoWeightRatio_DptBin[iCent][iPtBins]->SetMinimum(0.0);
			hD0DcaMCNPSignal_NoWeightRatio_DptBin[iCent][iPtBins]->SetMaximum(4);
      hD0DcaMCNPSignal_NoWeightRatio_DptBin[iCent][iPtBins]->GetXaxis()->SetRangeUser(0,0.07);			
      hD0DcaMCNPSignal_NoWeightRatio_DptBin[iCent][iPtBins]->Draw("SAME");
      hD0DcaMCNPSignal_DptReWeightRatio_DptBin[iCent][iPtBins]->SetLineColor(4);
      hD0DcaMCNPSignal_DptReWeightRatio_DptBin[iCent][iPtBins]->SetMarkerColor(4);
      hD0DcaMCNPSignal_DptReWeightRatio_DptBin[iCent][iPtBins]->SetMarkerStyle(24);
      hD0DcaMCNPSignal_DptReWeightRatio_DptBin[iCent][iPtBins]->Draw("SAME");

      l_MCNP[iCent][iPtBins][2] = new TLegend(0.58,0.65,0.9,0.88);
      l_MCNP[iCent][iPtBins][2]->AddEntry((TObject*)0,"Divided by PtHatWeighted","");
      // l_MCNP[iCent][2]->AddEntry(hD0DcaMCNPSignal_PtHatWeight_DptBin[iCent][iPtBins],"PtHatWeighted","l");
      l_MCNP[iCent][iPtBins][2]->AddEntry(hD0DcaMCNPSignal_NoWeightRatio_DptBin[iCent][iPtBins],"NonWeighted","lp");
      l_MCNP[iCent][iPtBins][2]->AddEntry(hD0DcaMCNPSignal_DptReWeightRatio_DptBin[iCent][iPtBins],"DptWeighted","lp");
      l_MCNP[iCent][iPtBins][2]->SetBorderSize(0);
      l_MCNP[iCent][iPtBins][2]->Draw();
	
		
      c_MCNP[iCent][iPtBins]->cd(4);
      hDptMCNPSignal_NoWeightRatio_DptBin[iCent][iPtBins]->SetLineColor(2);
      hDptMCNPSignal_NoWeightRatio_DptBin[iCent][iPtBins]->SetMarkerColor(2);
      hDptMCNPSignal_NoWeightRatio_DptBin[iCent][iPtBins]->SetMarkerStyle(24);
      hDptMCNPSignal_NoWeightRatio_DptBin[iCent][iPtBins]->Draw("SAME");
      hDptMCNPSignal_DptReWeightRatio_DptBin[iCent][iPtBins]->SetLineColor(4);
      hDptMCNPSignal_DptReWeightRatio_DptBin[iCent][iPtBins]->SetMarkerColor(4);
      hDptMCNPSignal_DptReWeightRatio_DptBin[iCent][iPtBins]->SetMarkerStyle(24);
      hDptMCNPSignal_DptReWeightRatio_DptBin[iCent][iPtBins]->Draw("SAME");

      l_MCNP[iCent][iPtBins][3] = new TLegend(0.58,0.65,0.9,0.88);
      l_MCNP[iCent][iPtBins][3]->AddEntry((TObject*)0,"Divided by PtHatWeighted","");
      // l_MCNP[iCent][4]->AddEntry(hDptMCNPSignal_PtHatWeightRatio_DptBin[iCent][iPtBins],"PtHatWeighted","l");
      l_MCNP[iCent][iPtBins][3]->AddEntry(hDptMCNPSignal_NoWeightRatio_DptBin[iCent][iPtBins],"NonWeighted","lp");
      l_MCNP[iCent][iPtBins][3]->AddEntry(hDptMCNPSignal_DptReWeightRatio_DptBin[iCent][iPtBins],"DptWeighted","lp");
      l_MCNP[iCent][iPtBins][3]->SetBorderSize(0);
      l_MCNP[iCent][iPtBins][3]->Draw();


			c_MCNP[iCent][iPtBins]->SaveAs(Form("Plot_DptReWeight/NonPrompt/DCA_NonPrompt_%s_pt%dto%d.pdf",iCentStr.c_str(),(int)ptLow,(int)ptHigh));


		} // end for(int iCent=0; iCent<nCent; iCent++)
//	} // end for(int iPtBins=0; iPtBins<nPtBins; iPtBins++)





}// end void DptReWeight
