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



void BptReWeight(){
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

	TFile* fPbPbMC = new TFile("bFeedDownPbPbMC_Bpt.hist.root");
	TFile* fPbPbMBMC = new TFile("bFeedDownPbPbMBMC_Bpt.hist.root");

	const int nPtBins = 14;
	float ptBins[nPtBins+1] = {2.,3.,4.,5.,6.,8.,10.,12.5,15.0,20.,25.,30.,40.,60.,100};

	const int nBinX =14;
	float binsX[nBinX+1] = {2.,3.,4.,5.,6.,8.,10.,12.5,15.0,20.,25.,30.,40.,60.,100};

	const int nBinY = 20;
	Float_t binsY[nBinY+1];
	float firstBinYWidth = 0.001;
	float binYWidthRatio = 1.27;
	binsY[0]=0;
	for(int i=1; i<=nBinY; i++)
	{binsY[i] = binsY[i-1]+firstBinYWidth*pow(binYWidthRatio,i-1);}
	cout<<"last y bin: "<<binsY[nBinY]<<endl;

	const int nBinZ = 150;
	Float_t binsZ[nBinZ+1];
	binsZ[0]=2;
	for(int i=1; i<=nBinZ; i++){
		binsZ[i]= binsZ[i-1]+ 2;
	}

	const int nCent = 5;
	const int nPtWeight = 2;
	TH3D* hMCNPSignal[nCent][nPtWeight];
	TH3D* hMCNPSignalPbPb[nCent][nPtWeight];
	TH3D* hMCNPSignalPbPbMB[nCent][nPtWeight];

	TH3D* hMCNPSignal_Dpt8to10[nCent][nPtWeight];

	TH1D* hD0DcaMCNPSignal_Bpt[nCent][nPtWeight];
	TH1D* hD0DcaMCNPSignal_Bpt_Dpt8to10[nCent][nPtWeight];


	const char* CentArr[] ={"cent0to100","cent0to10", "cent10to30", "cent30to50", "cent50to100"};
	const char* PtWeightArr[] ={"PtWeight","NoWeight"};

	std::string iCentStr = "cent0to10";
	std::string iPtWeightStr = "PtWeight";
	std::string PtRangeStr = "all pt";

	for(int iCent=0; iCent<nCent; iCent++){
		iCentStr= CentArr[iCent];
		//    cutCentralityBin=cutCentralityBinArr[iCent];
		for(int iPtWeight=0 ; iPtWeight<nPtWeight ; iPtWeight++){
			iPtWeightStr= PtWeightArr[iPtWeight];
			cout<<"iCent = "<<iCent<<" , iPtWeight = "<<iPtWeight<<endl;

			hMCNPSignalPbPb[iCent][iPtWeight] = (TH3D*)fPbPbMC->Get(Form("hMCNPSignal_%s%s",iCentStr.c_str(), iPtWeightStr.c_str()));
			hMCNPSignalPbPbMB[iCent][iPtWeight] = (TH3D*)fPbPbMBMC->Get(Form("hMCNPSignal_%s%s",iCentStr.c_str(), iPtWeightStr.c_str()));

			hMCNPSignalPbPb[iCent][iPtWeight]->Sumw2();
			hMCNPSignalPbPbMB[iCent][iPtWeight]->Sumw2();

			cout<<"check 2"<<endl;

			hMCNPSignal[iCent][iPtWeight] = (TH3D*)hMCNPSignalPbPb[iCent][iPtWeight]->Clone(Form("hMCNPSignal_%s%s",iCentStr.c_str(), iPtWeightStr.c_str()));
			hMCNPSignal[iCent][iPtWeight]->Sumw2();
			hMCNPSignal[iCent][iPtWeight]->Add(hMCNPSignalPbPbMB[iCent][iPtWeight]);



			cout<<"check 7"<<endl;
			hD0DcaMCNPSignal_Bpt[iCent][iPtWeight] = (TH1D*)hMCNPSignal[iCent][iPtWeight]->Project3D("z")->Clone(Form("hD0DcaMCNPSignal_Dpt_%s%s",iCentStr.c_str(), iPtWeightStr.c_str()));
			hD0DcaMCNPSignal_Bpt[iCent][iPtWeight]->Sumw2();


			// create Dpt subrange histo
			hMCNPSignal_Dpt8to10[iCent][iPtWeight] = (TH3D*)hMCNPSignal[iCent][iPtWeight]->Clone(Form("hMCNPSignal_Dpt8to10_%s%s",iCentStr.c_str(), iPtWeightStr.c_str()));
			hMCNPSignal_Dpt8to10[iCent][iPtWeight]->Sumw2();

			hMCNPSignal_Dpt8to10[iCent][iPtWeight]->GetXaxis()->SetRangeUser(8,10);
			hD0DcaMCNPSignal_Bpt_Dpt8to10[iCent][iPtWeight] = (TH1D*)hMCNPSignal_Dpt8to10[iCent][iPtWeight]->Project3D("z")->Clone(Form("hD0DcaMCNPSignal_Dpt8to10_%s%s",iCentStr.c_str(), iPtWeightStr.c_str()));
			hD0DcaMCNPSignal_Bpt_Dpt8to10[iCent][iPtWeight]->Sumw2();




			//      hD0DcaMCNPSignal_Bpt_Integral[iCent][iPtWeight]=hD0DcaMCNPSignal_Bpt[iCent][iPtWeight]->Integral();
			//      hD0DcaMCNPSignal_Bpt_Entries[iCent][iPtWeight]=hD0DcaMCNPSignal_Bpt[iCent][iPtWeight]->GetEntries();
			//      hD0DcaMCNPSignal_Bpt[iCent][iPtWeight]->Scale(1/ hD0DcaMCNPSignal_Bpt_Integral[iCent][iPtWeight]);


		} // end  for(int iPthatWeight)
	} // end   for(int iCent=0; iCent<nCent; iCent++)


	TH1D* hD0DcaMCNPSignal_BptRatio;
	TH1D* hD0DcaMCNPSignal_BptRatio_Dpt8to10;

	hD0DcaMCNPSignal_BptRatio= (TH1D*)hD0DcaMCNPSignal_Bpt[0][0]->Clone("hD0DcaMCNPSignal_BptRatio");
	hD0DcaMCNPSignal_BptRatio->Sumw2();
	hD0DcaMCNPSignal_BptRatio->Divide(hD0DcaMCNPSignal_Bpt[0][1]);

	hD0DcaMCNPSignal_BptRatio_Dpt8to10 =(TH1D*)hD0DcaMCNPSignal_Bpt_Dpt8to10[0][0]->Clone("hD0DcaMCNPSignal_BptRatio_Dpt8to10");
	hD0DcaMCNPSignal_BptRatio_Dpt8to10->Sumw2();
	hD0DcaMCNPSignal_BptRatio_Dpt8to10->Divide(hD0DcaMCNPSignal_Bpt_Dpt8to10[0][1]);

	TCanvas *c_Bpt = new TCanvas("c_Bpt","c_Bpt",600,600);
	c_Bpt->cd();
	gPad->SetLogy();
	TLegend *l_Bpt = new TLegend(0.6,0.7,0.88,0.88);

	hD0DcaMCNPSignal_Bpt[0][0]->SetLineColor(3);
	hD0DcaMCNPSignal_Bpt[0][0]->DrawNormalized();
	hD0DcaMCNPSignal_Bpt[0][1]->SetLineColor(2);
	hD0DcaMCNPSignal_Bpt[0][1]->DrawNormalized("SAME");

//	l_Bpt->AddEntry((TObject*)0, " ","");
	l_Bpt->AddEntry(hD0DcaMCNPSignal_Bpt[0][0],"pthatweighted","l");
	l_Bpt->AddEntry(hD0DcaMCNPSignal_Bpt[0][1],"Nonweighted","l");
	l_Bpt->Draw();


  TCanvas *c_Bpt_Dpt8to10 = new TCanvas("c_Bpt_Dpt8to10","c_Bpt_Dpt8to10",600,600);
  c_Bpt_Dpt8to10->cd();
	gPad->SetLogy();

  TLegend *l_Bpt_Dpt8to10 = new TLegend(0.6,0.7,0.88,0.88);


	hD0DcaMCNPSignal_Bpt_Dpt8to10[0][0]->SetLineColor(3);
  hD0DcaMCNPSignal_Bpt_Dpt8to10[0][0]->DrawNormalized();
  hD0DcaMCNPSignal_Bpt_Dpt8to10[0][1]->SetLineColor(2);
  hD0DcaMCNPSignal_Bpt_Dpt8to10[0][1]->DrawNormalized("SAME");

  l_Bpt_Dpt8to10->AddEntry((TObject*)0, "8<Dpt<10 (GeV) ","");
  l_Bpt_Dpt8to10->AddEntry(hD0DcaMCNPSignal_Bpt_Dpt8to10[0][0],"pthatweighted","l");
  l_Bpt_Dpt8to10->AddEntry(hD0DcaMCNPSignal_Bpt_Dpt8to10[0][1],"Nonweighted","l");
  l_Bpt_Dpt8to10->Draw();


	// reweight
	cout<<"check a"<<endl;

	TH3D* hMCNPSignal_BptReWeight;
	hMCNPSignal_BptReWeight=(TH3D*)hMCNPSignal[0][0]->Clone("hMCPSignal_BptReWeight");
	TH1D* hD0DcaMCNPSignal_BptReWeight;
	TH1D* hBptMCNPSignal_BptReWeight;

  cout<<"check b"<<endl;

	TH3D* hMCNPSignal_BptReWeight_Dpt8to10;
  hMCNPSignal_BptReWeight_Dpt8to10=(TH3D*)hMCNPSignal[0][0]->Clone("hMCPSignal_BptReWeight_Dpt8to10");
	TH1D* hD0DcaMCNPSignal_BptReWeight_Dpt8to10;
	TH1D* hBptMCNPSignal_BptReWeight_Dpt8to10;
  cout<<"check c"<<endl;

	double max_scale =0.0001;
	double min_scale =1;
	
	double max_scale_Dpt8to10 = 0.00001;
	double min_scale_Dpt8to10 =1;


	for(int iBinX=1; iBinX<=nBinX; iBinX++){ // BinX for Dpt , BinY for D0DcA, BinZ for bpt
		for(int iBinY=1; iBinY<=nBinY; iBinY++){
			for(int iBinZ=1; iBinZ<=nBinZ; iBinZ++){

					double content3d = hMCNPSignal[0][1]->GetBinContent(iBinX,iBinY,iBinZ);
					double error3d=hMCNPSignal[0][1]->GetBinError(iBinX,iBinY,iBinZ);
					double BptBinRatio= hD0DcaMCNPSignal_BptRatio->GetBinContent(iBinZ);
					double BptBinRatioErr = hD0DcaMCNPSignal_BptRatio->GetBinError(iBinZ);

					hMCNPSignal_BptReWeight->SetBinContent(iBinX,iBinY,iBinZ,content3d*BptBinRatio );
					hMCNPSignal_BptReWeight->SetBinError(iBinX,iBinY,iBinZ,TMath::Sqrt(TMath::Power(content3d*BptBinRatioErr,2)+TMath::Power(error3d*BptBinRatio,2)));

					if(BptBinRatio >max_scale) max_scale=BptBinRatio;
          if(BptBinRatio <min_scale) min_scale=BptBinRatio;

          double content3d_Dpt8to10 = hMCNPSignal_Dpt8to10[0][1]->GetBinContent(iBinX,iBinY,iBinZ);
          double error3d_Dpt8to10=hMCNPSignal_Dpt8to10[0][1]->GetBinError(iBinX,iBinY,iBinZ);
          double BptBinRatio_Dpt8to10= hD0DcaMCNPSignal_BptRatio_Dpt8to10->GetBinContent(iBinZ);
          double BptBinRatioErr_Dpt8to10 = hD0DcaMCNPSignal_BptRatio_Dpt8to10->GetBinError(iBinZ);
    
          hMCNPSignal_BptReWeight_Dpt8to10->SetBinContent(iBinX,iBinY,iBinZ,content3d_Dpt8to10*BptBinRatio_Dpt8to10 );
          hMCNPSignal_BptReWeight_Dpt8to10->SetBinError(iBinX,iBinY,iBinZ,TMath::Sqrt(TMath::Power(content3d_Dpt8to10*BptBinRatioErr_Dpt8to10,2)+TMath::Power(error3d_Dpt8to10*BptBinRatio_Dpt8to10,2)));

          if(BptBinRatio_Dpt8to10 >max_scale_Dpt8to10) max_scale_Dpt8to10=BptBinRatio_Dpt8to10;
          if(BptBinRatio_Dpt8to10 <min_scale_Dpt8to10) min_scale_Dpt8to10=BptBinRatio_Dpt8to10;


			}// end iBinZ
		}// end iBinY
	}// end iBinX

	cout<<"max scale = "<<max_scale<<" ,min = "<<min_scale<<endl;
  cout<<"max scale dpt8to10 = "<<max_scale_Dpt8to10<<" ,min = "<<min_scale_Dpt8to10<<endl;


  cout<<"check g"<<endl;

	// project to D0DCA TH1D
	
	TH1D *hD0DcaMCNPSignal_PtHatWeight;
  TH1D *hD0DcaMCNPSignal_NonHatWeight;
  TH1D *hD0DcaMCNPSignal_BptWeight;
  TH1D *hD0DcaMCNPSignal_BptWeight_Dpt8to10;

	TH1D *hD0DcaMCNPSignal_NonHatWeightRatio;
	TH1D *hD0DcaMCNPSignal_BptWeightRatio;
  TH1D *hD0DcaMCNPSignal_BptWeightRatio_Dpt8to10;

	hMCNPSignal[0][0]->GetXaxis()->SetRangeUser(8,10);
	hMCNPSignal[0][1]->GetXaxis()->SetRangeUser(8,10);
  hMCNPSignal_BptReWeight->GetXaxis()->SetRangeUser(8,10);
  hMCNPSignal_BptReWeight_Dpt8to10->GetXaxis()->SetRangeUser(8,10);



	hD0DcaMCNPSignal_PtHatWeight=(TH1D*)hMCNPSignal[0][0]->Project3D("y")->Clone("hD0DcaMCNPSignal_PtHatWeight");
  hD0DcaMCNPSignal_NonHatWeight=(TH1D*)hMCNPSignal[0][1]->Project3D("y")->Clone("hD0DcaMCNPSignal_NonHatWeight");
	hD0DcaMCNPSignal_BptWeight=(TH1D*)hMCNPSignal_BptReWeight->Project3D("y")->Clone("hD0DcaMCNPSignal_BptWeight");
  hD0DcaMCNPSignal_BptWeight_Dpt8to10=(TH1D*)hMCNPSignal_BptReWeight_Dpt8to10->Project3D("y")->Clone("hD0DcaMCNPSignal_BptWeight_Dpt8to10");

	hD0DcaMCNPSignal_NonHatWeightRatio=(TH1D*)hD0DcaMCNPSignal_NonHatWeight->Clone("hD0DcaMCNPSignal_NonHatWeightRatio");
	hD0DcaMCNPSignal_NonHatWeightRatio->Divide(hD0DcaMCNPSignal_NonHatWeightRatio,hD0DcaMCNPSignal_PtHatWeight,hD0DcaMCNPSignal_PtHatWeight->Integral(),hD0DcaMCNPSignal_NonHatWeightRatio->Integral());
	hD0DcaMCNPSignal_BptWeightRatio=(TH1D*)hD0DcaMCNPSignal_BptWeight->Clone("hD0DcaMCNPSignal_BptWeightRatio");
	hD0DcaMCNPSignal_BptWeightRatio->Divide(hD0DcaMCNPSignal_BptWeightRatio,hD0DcaMCNPSignal_PtHatWeight,hD0DcaMCNPSignal_PtHatWeight->Integral(),hD0DcaMCNPSignal_BptWeightRatio->Integral());
	hD0DcaMCNPSignal_BptWeightRatio_Dpt8to10=(TH1D*)hD0DcaMCNPSignal_BptWeight_Dpt8to10->Clone("hD0DcaMCNPSignal_BptWeightRatio_Dpt8to10");
  hD0DcaMCNPSignal_BptWeightRatio_Dpt8to10->Divide(hD0DcaMCNPSignal_BptWeightRatio_Dpt8to10,hD0DcaMCNPSignal_PtHatWeight,hD0DcaMCNPSignal_PtHatWeight->Integral(),hD0DcaMCNPSignal_BptWeightRatio_Dpt8to10->Integral());
 



	// project to Bpt TH1D


  TH1D *hBptMCNPSignal_PtHatWeight;
  TH1D *hBptMCNPSignal_NonHatWeight;
  TH1D *hBptMCNPSignal_BptWeight;
  TH1D *hBptMCNPSignal_BptWeight_Dpt8to10;

  TH1D *hBptMCNPSignal_NonHatWeightRatio;
  TH1D *hBptMCNPSignal_BptWeightRatio;
  TH1D *hBptMCNPSignal_BptWeightRatio_Dpt8to10;

  hMCNPSignal[0][0]->GetXaxis()->SetRangeUser(8,10);
  hMCNPSignal[0][1]->GetXaxis()->SetRangeUser(8,10);
  hMCNPSignal_BptReWeight->GetXaxis()->SetRangeUser(8,10);
  hMCNPSignal_BptReWeight_Dpt8to10->GetXaxis()->SetRangeUser(8,10);



  hBptMCNPSignal_PtHatWeight=(TH1D*)hMCNPSignal[0][0]->Project3D("z")->Clone("hBptMCNPSignal_PtHatWeight");
  hBptMCNPSignal_NonHatWeight=(TH1D*)hMCNPSignal[0][1]->Project3D("z")->Clone("hBptMCNPSignal_NonHatWeight");
  hBptMCNPSignal_BptWeight=(TH1D*)hMCNPSignal_BptReWeight->Project3D("z")->Clone("hBptMCNPSignal_BptWeight");
  hBptMCNPSignal_BptWeight_Dpt8to10=(TH1D*)hMCNPSignal_BptReWeight_Dpt8to10->Project3D("z")->Clone("hBptMCNPSignal_BptWeight_Dpt8to10");

  hBptMCNPSignal_NonHatWeightRatio=(TH1D*)hBptMCNPSignal_NonHatWeight->Clone("hBptMCNPSignal_NonHatWeightRatio");
  hBptMCNPSignal_NonHatWeightRatio->Divide(hBptMCNPSignal_NonHatWeightRatio,hBptMCNPSignal_PtHatWeight,hBptMCNPSignal_PtHatWeight->Integral(),hBptMCNPSignal_NonHatWeightRatio->Integral());
  hBptMCNPSignal_BptWeightRatio=(TH1D*)hBptMCNPSignal_BptWeight->Clone("hBptMCNPSignal_BptWeightRatio");
  hBptMCNPSignal_BptWeightRatio->Divide(hBptMCNPSignal_BptWeightRatio,hBptMCNPSignal_PtHatWeight,hBptMCNPSignal_PtHatWeight->Integral(),hBptMCNPSignal_BptWeightRatio->Integral());
  hBptMCNPSignal_BptWeightRatio_Dpt8to10=(TH1D*)hBptMCNPSignal_BptWeight_Dpt8to10->Clone("hBptMCNPSignal_BptWeightRatio_Dpt8to10");
  hBptMCNPSignal_BptWeightRatio_Dpt8to10->Divide(hBptMCNPSignal_BptWeightRatio_Dpt8to10,hBptMCNPSignal_PtHatWeight,hBptMCNPSignal_PtHatWeight->Integral(),hBptMCNPSignal_BptWeightRatio_Dpt8to10->Integral());


	// plot



	TCanvas *c_reweight= new TCanvas("c_reweight","c_reweight",800,800);
	c_reweight->Divide(2,2);

	TLegend *l_reweight[4];

	c_reweight->cd(1);
	gPad->SetLogy();
  hD0DcaMCNPSignal_PtHatWeight->SetLineColor(3);
	hD0DcaMCNPSignal_PtHatWeight->GetXaxis()->SetRangeUser(0,0.07);
	hD0DcaMCNPSignal_PtHatWeight->DrawNormalized();
  hD0DcaMCNPSignal_NonHatWeight->SetLineColor(2);
	hD0DcaMCNPSignal_NonHatWeight->DrawNormalized("SAME");
  hD0DcaMCNPSignal_BptWeight->SetLineColor(4);
	hD0DcaMCNPSignal_BptWeight->DrawNormalized("SAME");
  hD0DcaMCNPSignal_BptWeight_Dpt8to10->SetLineColor(6);
	hD0DcaMCNPSignal_BptWeight_Dpt8to10->DrawNormalized("SAME");

  cout<<"check j"<<endl;


	l_reweight[0]= new TLegend(0.65,0.7,0.88,0.88);
	l_reweight[0]->AddEntry((TObject*)0,"8<D P_{T}<10","");
	l_reweight[0]->AddEntry(hD0DcaMCNPSignal_PtHatWeight,"PtHatWeighted","l");
  l_reweight[0]->AddEntry(hD0DcaMCNPSignal_NonHatWeight,"NonWeighted","l");
  l_reweight[0]->AddEntry(hD0DcaMCNPSignal_BptWeight,"BptWeighted","l");
  l_reweight[0]->AddEntry(hD0DcaMCNPSignal_BptWeight_Dpt8to10,"BptWeighted 2","l");
	l_reweight[0]->Draw();

	c_reweight->cd(3);
	
	hD0DcaMCNPSignal_NonHatWeightRatio->SetLineColor(2);
	hD0DcaMCNPSignal_NonHatWeightRatio->GetXaxis()->SetRangeUser(0,0.07);
	hD0DcaMCNPSignal_NonHatWeightRatio->SetMinimum(0);
	hD0DcaMCNPSignal_NonHatWeightRatio->SetMaximum(4);
	hD0DcaMCNPSignal_NonHatWeightRatio->Draw();
	hD0DcaMCNPSignal_BptWeightRatio->SetLineColor(4);
	hD0DcaMCNPSignal_BptWeightRatio->Draw("SAME");
	hD0DcaMCNPSignal_BptWeightRatio_Dpt8to10->SetLineColor(6);
	hD0DcaMCNPSignal_BptWeightRatio_Dpt8to10->Draw("SAME");

  l_reweight[1]= new TLegend(0.65,0.7,0.88,0.88);
  l_reweight[1]->AddEntry((TObject*)0,"Divided by ptHatWeighted","");
  l_reweight[1]->AddEntry(hD0DcaMCNPSignal_NonHatWeightRatio,"NonWeighted","l");
  l_reweight[1]->AddEntry(hD0DcaMCNPSignal_BptWeightRatio,"BptWeighted","l");
  l_reweight[1]->AddEntry(hD0DcaMCNPSignal_BptWeightRatio_Dpt8to10,"BptWeighted 2","l");
  l_reweight[1]->Draw();


	c_reweight->cd(2);

  gPad->SetLogy();
  hBptMCNPSignal_PtHatWeight->SetLineColor(3);
	hBptMCNPSignal_PtHatWeight->GetXaxis()->SetRangeUser(0,80);
  hBptMCNPSignal_PtHatWeight->DrawNormalized();
  hBptMCNPSignal_NonHatWeight->SetLineColor(2);
  hBptMCNPSignal_NonHatWeight->DrawNormalized("SAME");
  hBptMCNPSignal_BptWeight->SetLineColor(4);
  hBptMCNPSignal_BptWeight->DrawNormalized("SAME");
  hBptMCNPSignal_BptWeight_Dpt8to10->SetLineColor(6);
  hBptMCNPSignal_BptWeight_Dpt8to10->DrawNormalized("SAME");

  cout<<"check j"<<endl;


  l_reweight[2]= new TLegend(0.65,0.7,0.88,0.88);
  l_reweight[2]->AddEntry((TObject*)0,"8<D P_{T}<10","");
  l_reweight[2]->AddEntry(hBptMCNPSignal_PtHatWeight,"PtHatWeighted","l");
  l_reweight[2]->AddEntry(hBptMCNPSignal_NonHatWeight,"NonWeighted","l");
  l_reweight[2]->AddEntry(hBptMCNPSignal_BptWeight,"BptWeighted","l");
  l_reweight[2]->AddEntry(hBptMCNPSignal_BptWeight_Dpt8to10,"BptWeighted 2","l");
  l_reweight[2]->Draw();




	c_reweight->cd(4);
	
  hBptMCNPSignal_NonHatWeightRatio->SetLineColor(2);
	hBptMCNPSignal_NonHatWeightRatio->GetXaxis()->SetRangeUser(0,80);
	hBptMCNPSignal_NonHatWeightRatio->SetMinimum(0);
	hBptMCNPSignal_NonHatWeightRatio->SetMaximum(4);
  hBptMCNPSignal_NonHatWeightRatio->Draw();
  hBptMCNPSignal_BptWeightRatio->SetLineColor(4);
  hBptMCNPSignal_BptWeightRatio->Draw("SAME");
  hBptMCNPSignal_BptWeightRatio_Dpt8to10->SetLineColor(6);
  hBptMCNPSignal_BptWeightRatio_Dpt8to10->Draw("SAME");

  l_reweight[3]= new TLegend(0.65,0.7,0.88,0.88);
  l_reweight[3]->AddEntry((TObject*)0,"Divided by ptHatWeighted","");
  l_reweight[3]->AddEntry(hBptMCNPSignal_NonHatWeightRatio,"NonWeighted","l");
  l_reweight[3]->AddEntry(hBptMCNPSignal_BptWeightRatio,"BptWeighted","l");
  l_reweight[3]->AddEntry(hBptMCNPSignal_BptWeightRatio_Dpt8to10,"BptWeighted 2","l");
  l_reweight[3]->Draw();


} // end void BptReWeight
