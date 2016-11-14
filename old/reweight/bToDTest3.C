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

TH1D* hD0DcaMCPSignal;
TH1D* hD0DcaMCNPSignal;

void bToDTest3()
{
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

	TFile* fPbPbMC = new TFile("bFeedDownPbPbMC.hist.root");
	TFile* fPbPbMBMC = new TFile("bFeedDownPbPbMBMC.hist.root");

	const int nPtBins = 14;
	float ptBins[nPtBins+1] = {2.,3.,4.,5.,6.,8.,10.,12.5,15.0,20.,25.,30.,40.,60.,100};


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


	TH1D* hD0DcaMCPSignal0[nCent][nPtWeight];
	TH1D* hD0DcaMCNPSignal0[nCent][nPtWeight];

	TH1D* hD0DcaMCPSignal0_Pt[nCent][nPtWeight][nPtBins];
	TH1D* hD0DcaMCNPSignal0_Pt[nCent][nPtWeight][nPtBins];

	const char* CentArr[] ={"cent0to100","cent0to10", "cent10to30", "cent30to50", "cent50to100"};
	const char* PtWeightArr[] ={"PtWeight","NoWeight"};

	std::string iCentStr = "eta0to15";
	std::string iPtWeightStr = "PtWeight";
	std::string PtRangeStr = "all_pt";
	int ptrangecut = 0;
	if(ptrangecut ==1){
	PtRangeStr = "pt8to10";
	}
	double ptlow = 8;
	double pthigh = 10;
	int saveplot= 1;

	double hD0DcaMCPSignal0Integral[nCent][nPtWeight];
	double hD0DcaMCNPSignal0Integral[nCent][nPtWeight];

	double hD0DcaMCPSignal0Entries[nCent][nPtWeight];
	double hD0DcaMCNPSignal0Entries[nCent][nPtWeight];


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
			cout<<"check 3"<<endl;

			hMCNPSignal[iCent][iPtWeight] = (TH3D*)hMCNPSignalPbPb[iCent][iPtWeight]->Clone(Form("hMCNPSignal_%s%s",iCentStr.c_str(), iPtWeightStr.c_str()));
			hMCNPSignal[iCent][iPtWeight]->Sumw2();
			hMCNPSignal[iCent][iPtWeight]->Add(hMCNPSignalPbPbMB[iCent][iPtWeight]);
			cout<<"check 4"<<endl;

			const int nPtBins = 14;
			float ptBins[nPtBins+1] = {2.,3.,4.,5.,6.,8.,10.,12.5,15.0,20.,25.,30.,40.,60.,100};
			const int nBinY = 14;
			Float_t binsY[nBinY+1];
			float firstBinYWidth = 0.001;
			float binYWidthRatio = 1.27;
			binsY[0]=0;
			for(int i=1; i<=nBinY; i++)
				binsY[i] = binsY[i-1]+firstBinYWidth*pow(binYWidthRatio,i-1);

			cout<<"check 5"<<endl;
			//	hD0DcaMCPSignal0[iCent][iPtWeight]->SetName(Form("hD0DcaMCPSignal0_%s%s", iCentStr.c_str(), iPtWeightStr.c_str()));
			//  hD0DcaMCNPSignal0[iCent][iPtWeight]->SetName(Form("hD0DcaMCNPSignal0_%s%s", iCentStr.c_str(), iPtWeightStr.c_str()));

			if ( ptrangecut ==1){
				hMCPSignal[iCent][iPtWeight]->GetXaxis()->SetRangeUser(ptlow,pthigh);
				hMCNPSignal[iCent][iPtWeight]->GetXaxis()->SetRangeUser(ptlow,pthigh);
			}

			cout<<"check 6"<<endl;
			hD0DcaMCPSignal0[iCent][iPtWeight] = (TH1D*)hMCPSignal[iCent][iPtWeight]->Project3D("y")->Clone(Form("hD0DcaMCPSignal0_%s%s",iCentStr.c_str(), iPtWeightStr.c_str()));
			hD0DcaMCPSignal0[iCent][iPtWeight]->Sumw2();


			cout<<"check 7"<<endl;
			hD0DcaMCNPSignal0[iCent][iPtWeight] = (TH1D*)hMCNPSignal[iCent][iPtWeight]->Project3D("y")->Clone(Form("hD0DcaMCNPSignal0_%s%s",iCentStr.c_str(), iPtWeightStr.c_str()));
			hD0DcaMCNPSignal0[iCent][iPtWeight]->Sumw2();

			hD0DcaMCPSignal0Integral[iCent][iPtWeight]= hD0DcaMCPSignal0[iCent][iPtWeight]->Integral();
			hD0DcaMCNPSignal0Integral[iCent][iPtWeight]=hD0DcaMCNPSignal0[iCent][iPtWeight]->Integral();

			hD0DcaMCPSignal0Entries[iCent][iPtWeight]=hD0DcaMCPSignal0[iCent][iPtWeight]->GetEntries();
			hD0DcaMCNPSignal0Entries[iCent][iPtWeight]=hD0DcaMCNPSignal0[iCent][iPtWeight]->GetEntries();


		} // end  for(int iPthatWeight)
	} // end   for(int iCent=0; iCent<nCent; iCent++)

	cout<<"MCP Integral all (withPthatWeight)= "<<hD0DcaMCPSignal0Integral[0][0];
	cout<<" , MCP Integral all (w/o PthatWeight)= "<<hD0DcaMCPSignal0Integral[0][1]<<endl;
	cout<<"MCP Entries all (withPthatWeight) = "<<hD0DcaMCPSignal0Entries[0][0];
	cout<<" , MCP Entries all (w/oPthatWeight)  = "<<hD0DcaMCPSignal0Entries[0][1]<<endl;

	cout<<"\nMCNP Integral all (withPthatWeight)= "<<hD0DcaMCNPSignal0Integral[0][0];
	cout<<" , MCNP Integral all (w/o PthatWeight)= "<<hD0DcaMCNPSignal0Integral[0][1]<<endl;
	cout<<"MCNP Entries all (withPthatWeight) = "<<hD0DcaMCNPSignal0Entries[0][0];
	cout<<" , MCNP Entries all (w/oPthatWeight)  = "<<hD0DcaMCNPSignal0Entries[0][1]<<endl;



	cout<<"check 8"<<endl;

	hD0DcaMCPSignal0[0][0]->Draw();
	hD0DcaMCNPSignal0[0][0]->SetLineColor(2);
	hD0DcaMCNPSignal0[0][0]->Draw("SAME");

	TH1D* hD0DcaMCPSignal0_normall[nCent][nPtWeight];
	TH1D* hD0DcaMCNPSignal0_normall[nCent][nPtWeight];

	TH1D* hD0DcaMCPSignal0_norm[nCent][nPtWeight];
	TH1D* hD0DcaMCNPSignal0_norm[nCent][nPtWeight];


	TCanvas *C1 = new TCanvas("C1","C1",800,800);
	C1->Divide(2,2);
	TLegend *le1[nCent][nPtWeight];


	TCanvas *C2 = new TCanvas("C2","C2",800,800);
	C2->Divide(2,2);

	TCanvas *C3_P_weight_nonweight = new TCanvas("C3_P_weight_nonweight","C3_P_weight_nonweight",800,800);
	C3_P_weight_nonweight->Divide(2,2);
	TLegend *le3[nCent];

  TCanvas *C4_NP_weight_nonweight = new TCanvas("C4_NP_weight_nonweight","C4_NP_weight_nonweight",800,800);
  C4_NP_weight_nonweight->Divide(2,2);
  TLegend *le4[nCent];


	iPtWeightStr= PtWeightArr[1];
	iCentStr= CentArr[0];

	hD0DcaMCPSignal0_norm[0][1] = (TH1D*)hD0DcaMCPSignal0[0][1]->Clone(Form("hD0DcaMCPSignal0Norm_%s%s",iCentStr.c_str(), iPtWeightStr.c_str()));
	hD0DcaMCPSignal0_norm[0][1]->Sumw2();
	hD0DcaMCPSignal0_norm[0][1]->SetLineColor(1);
	hD0DcaMCPSignal0_norm[0][1]->Scale(1/hD0DcaMCPSignal0Integral[0][1]);

  hD0DcaMCNPSignal0_norm[0][1] = (TH1D*)hD0DcaMCNPSignal0[0][1]->Clone(Form("hD0DcaMCNPSignal0Norm_%s%s",iCentStr.c_str(), iPtWeightStr.c_str()));
  hD0DcaMCNPSignal0_norm[0][1]->Sumw2();
//  hD0DcaMCNPSignal0_norm[0][1]->SetLineColor(1);
  hD0DcaMCNPSignal0_norm[0][1]->Scale(1/hD0DcaMCNPSignal0Integral[0][1]);

	for(int iCent=1; iCent<nCent; iCent++){
		iCentStr= CentArr[iCent];
    iPtWeightStr= PtWeightArr[1];


		cout<<"iCent = "<<iCent<<endl;

		C1->cd(iCent);

		hD0DcaMCPSignal0_normall[iCent][1] = (TH1D*)hD0DcaMCPSignal0[iCent][1]->Clone(Form("hD0DcaMCPSignal0Normall_%s%s",iCentStr.c_str(), iPtWeightStr.c_str()));
		hD0DcaMCPSignal0_normall[iCent][1]->Sumw2();
    hD0DcaMCPSignal0_normall[iCent][1]->Scale(1/hD0DcaMCPSignal0Integral[iCent][1]);
		hD0DcaMCPSignal0_normall[iCent][1]->Divide( hD0DcaMCPSignal0_normall[iCent][1],hD0DcaMCPSignal0_norm[0][1],1,1,"B");
//		hD0DcaMCPSignal0_normall[iCent][1]->Divide( hD0DcaMCPSignal0[iCent][1], hD0DcaMCPSignal0[0][1],  hD0DcaMCPSignal0Integral[0][1], hD0DcaMCPSignal0Integral[iCent][1],"B");

		cout<<"check a-2"<<endl;

		hD0DcaMCNPSignal0_normall[iCent][1] = (TH1D*)hD0DcaMCNPSignal0[iCent][1]->Clone(Form("hD0DcaMCNPSignal0Normall_%s%s",iCentStr.c_str(), iPtWeightStr.c_str()));
		hD0DcaMCNPSignal0_normall[iCent][1]->Sumw2();
    hD0DcaMCNPSignal0_normall[iCent][1]->Scale(1/hD0DcaMCNPSignal0Integral[iCent][1]);
    hD0DcaMCNPSignal0_normall[iCent][1]->Divide( hD0DcaMCNPSignal0_normall[iCent][1],hD0DcaMCNPSignal0_norm[0][1],1,1,"B");
//		hD0DcaMCNPSignal0_normall[iCent][1]->Divide( hD0DcaMCNPSignal0[iCent][1],hD0DcaMCNPSignal0[0][1] , hD0DcaMCNPSignal0Integral[0][1], hD0DcaMCNPSignal0Integral[iCent][1],"B");

		cout<<"check a-"<<endl;

		hD0DcaMCPSignal0_normall[iCent][1]->SetLineColor(2);
		hD0DcaMCPSignal0_normall[iCent][1]->GetYaxis()->SetTitle("Divided by Centrality 0-100");
		hD0DcaMCPSignal0_normall[iCent][1]->SetMinimum(0.0);
		hD0DcaMCPSignal0_normall[iCent][1]->SetMaximum(4);
		hD0DcaMCPSignal0_normall[iCent][1]->GetXaxis()->SetRangeUser(0,0.08);
		hD0DcaMCPSignal0_normall[iCent][1]->Draw();
		hD0DcaMCNPSignal0_normall[iCent][1]->SetLineColor(4);
		hD0DcaMCNPSignal0_normall[iCent][1]->Draw("SAME");

		le1[iCent][1] = new TLegend(0.65,0.65,0.9,0.88);
		le1[iCent][1]->AddEntry((TObject*)0,Form("%s",iCentStr.c_str()),"");
		le1[iCent][1]->AddEntry((TObject*)0,Form("%s",PtRangeStr.c_str()),"");
		le1[iCent][1]->AddEntry(hD0DcaMCPSignal0_normall[iCent][1],"Prompt","l");
		le1[iCent][1]->AddEntry(hD0DcaMCNPSignal0_normall[iCent][1],"Non Prompt","l");
		le1[iCent][1]->SetBorderSize(0);
		le1[iCent][1]->Draw();

		TLine *line1 = new TLine(0,1,0.1,1);
		line1->SetLineStyle(7);
		line1->Draw("SAME");
		
		// if(saveplot ==1){
		// C1->SaveAs(Form("./Plots1/CentNorm_%s.pdf",PtRangeStr.c_str()));
		// }

		////
		C2->cd(iCent);
		gPad->SetLogy();

		hD0DcaMCPSignal0_norm[iCent][1] = (TH1D*)hD0DcaMCPSignal0[iCent][1]->Clone(Form("hD0DcaMCPSignal0Norm_%s%s",iCentStr.c_str(), iPtWeightStr.c_str()));
		hD0DcaMCPSignal0_norm[iCent][1]->Sumw2();
		hD0DcaMCPSignal0_norm[0][1]->GetXaxis()->SetRangeUser(0,0.08);

		hD0DcaMCPSignal0_norm[0][1]->DrawNormalized();
		hD0DcaMCPSignal0_norm[iCent][1]->SetLineColor(2);
		hD0DcaMCPSignal0_norm[iCent][1]->DrawNormalized("SAME");
		le1[iCent][0] = new TLegend(0.65,0.65,0.9,0.88);
		le1[iCent][0]->AddEntry((TObject*)0,Form("%s",PtRangeStr.c_str()),"");
		le1[iCent][0]->AddEntry(hD0DcaMCPSignal0_norm[iCent][1],Form("Prompt, %s", iCentStr.c_str()),"l");
		le1[iCent][0]->AddEntry(hD0DcaMCPSignal0_norm[0][1],"Prompt, cent0to100","l");
		le1[iCent][0]->SetBorderSize(0);
		le1[iCent][0]->Draw();

    // if(saveplot ==1){
		// C2->SaveAs(Form("./Plots1/Prompt_%s.pdf",PtRangeStr.c_str()));
		// }

	
		C3_P_weight_nonweight->cd(iCent);
		gPad->SetLogy();
    iPtWeightStr= PtWeightArr[1];
		hD0DcaMCPSignal0_norm[iCent][0] = (TH1D*)hD0DcaMCPSignal0[iCent][0]->Clone(Form("hD0DcaMCPSignal0Norm_%s%s",iCentStr.c_str(), iPtWeightStr.c_str()));
		hD0DcaMCPSignal0_norm[iCent][0]->Sumw2();
		hD0DcaMCPSignal0_norm[iCent][0]->SetLineColor(1);
		hD0DcaMCPSignal0_norm[iCent][0]->GetXaxis()->SetRangeUser(0,0.08);
		hD0DcaMCPSignal0_norm[iCent][0]->DrawNormalized();
		hD0DcaMCPSignal0_norm[iCent][1]->SetLineColor(2);
    hD0DcaMCPSignal0_norm[iCent][1]->DrawNormalized("SAME");

    le3[iCent] = new TLegend(0.65,0.65,0.9,0.88);
		le3[iCent]->AddEntry((TObject*)0,Form("%s",iCentStr.c_str()),"");
    le3[iCent]->AddEntry((TObject*)0,Form("%s",PtRangeStr.c_str()),"");
    le3[iCent]->AddEntry(hD0DcaMCPSignal0_norm[iCent][0],"Prompt D Weighted","l");
    le3[iCent]->AddEntry(hD0DcaMCPSignal0_norm[iCent][1],"Prompt D NonWeighted" ,"l");
    le3[iCent]->SetBorderSize(0);
    le3[iCent]->Draw();

    // if(saveplot ==1){
    // C3_P_weight_nonweight->SaveAs(Form("./Plots1/weight_%s.pdf",PtRangeStr.c_str()));
    // }

    C4_NP_weight_nonweight->cd(iCent);
    gPad->SetLogy();
    iPtWeightStr= PtWeightArr[1];
    hD0DcaMCNPSignal0_norm[iCent][0] = (TH1D*)hD0DcaMCNPSignal0[iCent][0]->Clone(Form("hD0DcaMCNPSignal0Norm_%s%s",iCentStr.c_str(), iPtWeightStr.c_str()));
    hD0DcaMCNPSignal0_norm[iCent][0]->Sumw2();
    hD0DcaMCNPSignal0_norm[iCent][0]->SetLineColor(1);
    hD0DcaMCNPSignal0_norm[iCent][0]->GetXaxis()->SetRangeUser(0,0.08);
    hD0DcaMCNPSignal0_norm[iCent][0]->DrawNormalized();

    hD0DcaMCNPSignal0_norm[iCent][1] = (TH1D*)hD0DcaMCNPSignal0[iCent][1]->Clone(Form("hD0DcaMCNPSignal0Norm_%s%s",iCentStr.c_str(), iPtWeightStr.c_str()));
    hD0DcaMCNPSignal0_norm[iCent][1]->Sumw2();

    hD0DcaMCNPSignal0_norm[iCent][1]->SetLineColor(2);
    hD0DcaMCNPSignal0_norm[iCent][1]->DrawNormalized("SAME");

    le4[iCent] = new TLegend(0.65,0.65,0.9,0.88);
    le4[iCent]->AddEntry((TObject*)0,Form("%s",iCentStr.c_str()),"");
    le4[iCent]->AddEntry((TObject*)0,Form("%s",PtRangeStr.c_str()),"");
    le4[iCent]->AddEntry(hD0DcaMCNPSignal0_norm[iCent][0],"Non Prompt D Weighted","l");
    le4[iCent]->AddEntry(hD0DcaMCNPSignal0_norm[iCent][1],"Non Prompt D NonWeighted" ,"l");
    le4[iCent]->SetBorderSize(0);
    le4[iCent]->Draw();





	}// end for(int iCent=0; iCent<nCent; iCent++)

    if(saveplot ==1){
    C1->SaveAs(Form("./Plots1/CentNorm_%s.pdf",PtRangeStr.c_str()));
    C2->SaveAs(Form("./Plots1/Prompt_%s.pdf",PtRangeStr.c_str()));
    C3_P_weight_nonweight->SaveAs(Form("./Plots1/Pweight_%s.pdf",PtRangeStr.c_str()));
    C4_NP_weight_nonweight->SaveAs(Form("./Plots1/NPweight_%s.pdf",PtRangeStr.c_str()));
}



	TCanvas *C_PtWeight = new TCanvas("C_PtWeight","C_PtWeight",400,400);
	C_PtWeight->cd();
	iCentStr=CentArr[0];
	iPtWeightStr=CentArr[0];

	hD0DcaMCPSignal0_normall[0][0] = (TH1D*)hD0DcaMCPSignal0[0][0]->Clone(Form("hD0DcaMCPSignal0Normall_%s%s",iCentStr.c_str(), iPtWeightStr.c_str()));
	hD0DcaMCPSignal0_normall[0][0]->Sumw2();
	hD0DcaMCPSignal0_normall[0][0]->Scale(1/hD0DcaMCPSignal0Integral[0][0]);
  hD0DcaMCPSignal0_normall[0][0]->Divide( hD0DcaMCPSignal0_normall[0][0],hD0DcaMCPSignal0_norm[0][1],1,1,"B");
//	hD0DcaMCPSignal0_normall[0][0]->Divide(hD0DcaMCPSignal0[0][0],hD0DcaMCPSignal0[0][1],hD0DcaMCPSignal0Integral[0][1],hD0DcaMCPSignal0Integral[0][0]);

	hD0DcaMCNPSignal0_normall[0][0] = (TH1D*)hD0DcaMCNPSignal0[0][0]->Clone(Form("hD0DcaMCNPSignal0Normall_%s%s",iCentStr.c_str(), iPtWeightStr.c_str()));
	hD0DcaMCNPSignal0_normall[0][0]->Sumw2();
  hD0DcaMCNPSignal0_normall[0][0]->Scale(1/hD0DcaMCNPSignal0Integral[0][0]);
  hD0DcaMCNPSignal0_normall[0][0]->Divide( hD0DcaMCNPSignal0_normall[0][0],hD0DcaMCNPSignal0_norm[0][1],1,1,"B");
//	hD0DcaMCNPSignal0_normall[0][0]->Divide(hD0DcaMCNPSignal0[0][0],hD0DcaMCNPSignal0[0][1],hD0DcaMCNPSignal0Integral[0][1],hD0DcaMCNPSignal0Integral[0][0]);

	hD0DcaMCPSignal0_normall[0][0]->SetLineColor(2);
	hD0DcaMCPSignal0_normall[0][0]->GetYaxis()->SetTitle("PtHatWeighted/NonWeight");
	hD0DcaMCPSignal0_normall[0][0]->SetMinimum(0.0);
	hD0DcaMCPSignal0_normall[0][0]->SetMaximum(4);
	hD0DcaMCPSignal0_normall[0][0]->GetXaxis()->SetRangeUser(0,0.08);
	hD0DcaMCPSignal0_normall[0][0]->Draw();
	hD0DcaMCNPSignal0_normall[0][0]->SetLineColor(4);
	hD0DcaMCNPSignal0_normall[0][0]->Draw("SAME");


	le1[0][0] = new TLegend(0.65,0.65,0.9,0.88);
	le1[0][0]->AddEntry((TObject*)0,Form("%s",iCentStr.c_str()),"");
	le1[0][0]->AddEntry((TObject*)0,Form("%s",PtRangeStr.c_str()),"");
	le1[0][0]->AddEntry(hD0DcaMCPSignal0_normall[0][0],"Prompt","l");
	le1[0][0]->AddEntry(hD0DcaMCNPSignal0_normall[0][0],"Non Prompt","l");
	le1[0][0]->SetBorderSize(0);
	le1[0][0]->Draw();

	TLine *line2 = new TLine(0,1,0.1,1);
	line2->SetLineStyle(7);
	line2->Draw("SAME");

  if(saveplot ==1){
	C_PtWeight->SaveAs(Form("./Plots1/PthatWeightOverNonWeight_%s.pdf",PtRangeStr.c_str()));
	}

} // end void bToDTest2() 
