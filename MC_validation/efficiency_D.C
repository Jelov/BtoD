#include "./include/uti.h"
#include "./include/parameters.h"
#include "TF1.h"


#include <iostream>
#include <iomanip>
#include <utility>
#include <TFile.h>
#include <TDirectoryFile.h>
#include <TDirectory.h>
#include <TTree.h>
#include <TNtuple.h>
#include <TH1D.h>
#include <TH1F.h>
#include <TH2F.h>
#include <TGraph.h>
#include <TGraphAsymmErrors.h>
#include <TF1.h>
#include <TCanvas.h>
#include <TPad.h>
#include <TLatex.h>
#include <TLegend.h>
#include <TLine.h>
#include <TBox.h>
#include <TCut.h>
#include <TMath.h>
#include <TRandom.h>
#include <TRandom3.h>
#include <TROOT.h>
#include <TStyle.h>
#include <TProfile.h>


Double_t setparam0=100.;
Double_t setparam1=1.865;
Double_t setparam2=0.03;
Double_t setparam10=0.005;
Double_t setparam8=0.1;
Double_t setparam9=0.1;
Double_t fixparam1=1.865;
//Double_t minhisto=1.7;
//Double_t maxhisto=2.0;
//Double_t nbinsmasshisto=60;
//Double_t binwidthmass=(maxhisto-minhisto)/nbinsmasshisto;

TString weight;
TString weightgen;
TString seldata;
TString selmc;
TString selmceff;
TString selmcgen;
TString collisionsystem;
Float_t hiBinMin,hiBinMax,centMin,centMax;


void efficiency_D(){

//	TString inPbPbMCP_pthatFilter="/data/HeavyFlavourRun2/MC2015/Dntuple/PbPb/ntD_EvtBase_20160513_DfinderMC_PbPb_20160502_dPt1tkPt0p5_D0_prompt_Dpt2Dy1p1tkPt0p7tkEta2Decay2p9Dalpha0p14Skim_pthatweight.root" ;
	
//	TString inPbPbMCNP_pthatFilter="/data/HeavyFlavourRun2/MC2015/Dntuple/PbPb/ntD_EvtBase_20160513_DfinderMC_PbPb_20160502_dPt1tkPt0p5_D0_nonprompt_Dpt2Dy1p1tkPt0p7tkEta2Decay2p9Dalpha0p14Skim_pthatweight.root";

TString inppMCP_pthatFilter="/data/HeavyFlavourRun2/MC2015/Dntuple/pp/ntD_EvtBase_20160513_DfinderMC_pp_20160502_dPt0tkPt0p5_D0Dstar_prompt_Dpt2Dy1p1tkPt0p7tkEta2Decay2p9Dalpha0p14Skim_pthatweight.root";
TString inppMCNP_pthatFilter="/data/HeavyFlavourRun2/MC2015/Dntuple/pp/ntD_EvtBase_20160513_DfinderMC_pp_20160502_dPt0tkPt0p5_D0Dstar_nonprompt_Dpt2Dy1p1tkPt0p7tkEta2Decay2p9Dalpha0p14Skim_pthatweight.root";


  TString inppMCP_DptFilter="/data/chengchi/BtoD_MC2016/pp/Dntuple_pp_prompt_mergeAll.root" ;

  TString inppMCNP_DptFilter="/data/chengchi/BtoD_MC2016/pp/Dntuple_pp_Nonprompt_mergeAll.root";


	TString outfname="2015ppMCEffHis_PthatFilter.root";

	TString trgselection="1";

	TString cut="Dy>-1.&&Dy<1.&&Dtrk1highPurity&&Dtrk2highPurity&&Dtrk1Pt>1.0&&Dtrk2Pt>1.0&&Dtrk1PtErr/Dtrk1Pt<0.3&&Dtrk2PtErr/Dtrk2Pt<0.3&&abs(Dtrk1Eta)<1.5&&abs(Dtrk2Eta)<1.5&&((DlxyBS/DlxyBSErr)>1.5&&Dalpha<0.12&&((Dpt>1&&Dpt<2&&(DsvpvDistance/DsvpvDisErr)>6.0&&Dchi2cl>0.25)||(Dpt>2&&Dpt<4&&(DsvpvDistance/DsvpvDisErr)>5.86&&Dchi2cl>0.224)||(Dpt>4&&Dpt<5&&(DsvpvDistance/DsvpvDisErr)>5.46&&Dchi2cl>0.196)||(Dpt>5&&Dpt<6&&(DsvpvDistance/DsvpvDisErr)>4.86&&Dchi2cl>0.170)||(Dpt>6&&Dpt<8&&(DsvpvDistance/DsvpvDisErr)>4.54&&Dchi2cl>0.125)||(Dpt>8&&Dpt<10&&(DsvpvDistance/DsvpvDisErr)>4.42&&Dchi2cl>0.091)||(Dpt>10&&Dpt<15&&(DsvpvDistance/DsvpvDisErr)>4.06&&Dchi2cl>0.069)||(Dpt>15&&Dpt<20&&(DsvpvDistance/DsvpvDisErr)>3.71&&Dchi2cl>0.056)||(Dpt>20&&Dpt<25&&(DsvpvDistance/DsvpvDisErr)>3.25&&Dchi2cl>0.054)||(Dpt>25&&(DsvpvDistance/DsvpvDisErr)>2.97&&Dchi2cl>0.050)))";

 TString cutmcgen="((GisSignal==1||GisSignal==2)&&(Gy>-1&&Gy<1))";

 TString outputfile="ROOTfiles/hPtSpectrumDzeroPbPbMBppMCClosureMYTEST.root";

	bool isPbPb=false;
	int doweight=0;


  if(!isPbPb)
  {
    seldata = Form("%s&&%s",trgselection.Data(),cut.Data());
    selmceff = Form("%s",cut.Data());
    selmcgen = Form("%s",cutmcgen.Data());
  }
  else
  {
    seldata = Form("%s&&%s&&hiBin>%f&&hiBin<%f",trgselection.Data(),cut.Data(),hiBinMin,hiBinMax);
    selmceff = Form("%s&&hiBin>%f&&hiBin<%f",cut.Data(),hiBinMin,hiBinMax);
    selmcgen = Form("%s&&hiBin>%f&&hiBin<%f",cutmcgen.Data(),hiBinMin,hiBinMax);
  }

  selmc = Form("%s",cut.Data());

  gStyle->SetTextSize(0.05);
  gStyle->SetTextFont(42);
  gStyle->SetPadRightMargin(0.043);
  gStyle->SetPadLeftMargin(0.18);
  gStyle->SetPadTopMargin(0.1);
  gStyle->SetPadBottomMargin(0.145);
  gStyle->SetTitleX(.0f);
	gStyle->SetOptStat(0);

  if(doweight==0) {
    weightgen="1";
    weight="1";
  }

  // pp weight
  if(doweight==1) {
    weightgen="(pthatweight)*(Max$(Gpt)<pthat/1.2)*(0.0116437+Max$(Gpt)*(0.0602697)+Max$(Gpt)*Max$(Gpt)*(-0.00226879)+Max$(Gpt)*Max$(Gpt)*Max$(Gpt)*(3.91035e-05)+Max$(Gpt)*Max$(Gpt)*Max$(Gpt)*Max$(Gpt)*(-3.0699e-07)+Max$(Gpt)*Max$(Gpt)*Max$(Gpt)*Max$(Gpt)*Max$(Gpt)*(8.73234e-10))";
    weight="(pthatweight)*(Max$(Gpt)<pthat/1.2)*(0.0116437+Max$(Gpt)*(0.0602697)+Max$(Gpt)*Max$(Gpt)*(-0.00226879)+Max$(Gpt)*Max$(Gpt)*Max$(Gpt)*(3.91035e-05)+Max$(Gpt)*Max$(Gpt)*Max$(Gpt)*Max$(Gpt)*(-3.0699e-07)+Max$(Gpt)*Max$(Gpt)*Max$(Gpt)*Max$(Gpt)*Max$(Gpt)*(8.73234e-10))";
  }
  //PbPb weight
  if(doweight==2) {
    weightgen="(pthatweight)*(Max$(Gpt)<pthat/1.2)*(6.14981+hiBin*(-0.156513)+hiBin*hiBin*(0.00149127)+hiBin*hiBin*hiBin*(-6.29087e-06)+hiBin*hiBin*hiBin*hiBin*(9.90029e-09))";
    weight="(pthatweight)*(Max$(Gpt)<pthat/1.2)*(6.14981+hiBin*(-0.156513)+hiBin*hiBin*(0.00149127)+hiBin*hiBin*hiBin*(-6.29087e-06)+hiBin*hiBin*hiBin*hiBin*(9.90029e-09))";
  }
  //PbPb low pt weight
  if(doweight==3) {
    weightgen="(pthatweight)*(Max$(Gpt)<pthat/1.2)*(6.14981+hiBin*(-0.156513)+hiBin*hiBin*(0.00149127)+hiBin*hiBin*hiBin*(-6.29087e-06)+hiBin*hiBin*hiBin*hiBin*(9.90029e-09))*(-0.00600791+Max$(Gpt)*(0.0838585)+Max$(Gpt)*Max$(Gpt)*(-0.00991096)+Max$(Gpt)*Max$(Gpt)*Max$(Gpt)*(0.000496019)+Max$(Gpt)*Max$(Gpt)*Max$(Gpt)*Max$(Gpt)*(-8.50065e-06))";
    weight="(pthatweight)*(Max$(Gpt)<pthat/1.2)*(6.14981+hiBin*(-0.156513)+hiBin*hiBin*(0.00149127)+hiBin*hiBin*hiBin*(-6.29087e-06)+hiBin*hiBin*hiBin*hiBin*(9.90029e-09))*(-0.00600791+Max$(Gpt)*(0.0838585)+Max$(Gpt)*Max$(Gpt)*(-0.00991096)+Max$(Gpt)*Max$(Gpt)*Max$(Gpt)*(0.000496019)+Max$(Gpt)*Max$(Gpt)*Max$(Gpt)*Max$(Gpt)*(-8.50065e-06))";
  }
  if(doweight<0 || doweight>4) std::cout<<"ERROR, this weighting option is not defined"<<std::endl;

  std::cout<<"we are using weight="<<weight<<std::endl;

	weight="pthatweight";
	weightgen="pthatweight";

  TFile* infppMCP_pthatFilter = new TFile(inppMCP_pthatFilter.Data());
	
  TTree* ntGenppMCP_pthatFilter = (TTree*)infppMCP_pthatFilter->Get("ntGen");
  ntGenppMCP_pthatFilter->AddFriend("ntHlt");
  ntGenppMCP_pthatFilter->AddFriend("ntHi");

  TTree* ntppMCP_pthatFilter = (TTree*)infppMCP_pthatFilter->Get("ntDkpi");
  ntppMCP_pthatFilter->AddFriend("ntHlt");
  ntppMCP_pthatFilter->AddFriend("ntHi");
  ntppMCP_pthatFilter->AddFriend("ntSkim");
  ntppMCP_pthatFilter->AddFriend(ntGenppMCP_pthatFilter);


  TH1D* hPtppMCP_pthatFilter = new TH1D("hPtppMCP_pthatFilter","",nPtBins,ptBins);
  TH1D* hPtGenppMCP_pthatFilter = new TH1D("hPtGenppMCP_pthatFilter","",nPtBins,ptBins);

  ntppMCP_pthatFilter->Project("hPtppMCP_pthatFilter","Dpt",TCut(weight)*(TCut(selmceff.Data())&&"(Dgen==23333)"));
  divideBinWidth(hPtppMCP_pthatFilter);
  ntGenppMCP_pthatFilter->Project("hPtGenppMCP_pthatFilter","Gpt",TCut(weightgen)*(TCut(selmcgen.Data())));
	divideBinWidth(hPtGenppMCP_pthatFilter);

  hPtppMCP_pthatFilter->Sumw2();
  TH1D* hEffppMCP_pthatFilter = (TH1D*)hPtppMCP_pthatFilter->Clone("hEffppMCP_pthatFilter");
  hEffppMCP_pthatFilter->SetTitle(";D^{0} p_{T} (GeV/c);Efficiency");
  hEffppMCP_pthatFilter->Sumw2();
  hEffppMCP_pthatFilter->Divide(hPtGenppMCP_pthatFilter);
  TCanvas* cEffppMCP_pthatFilter = new TCanvas("cEffppMCP_pthatFilter","",600,600);
	hEffppMCP_pthatFilter->Draw();

	cEffppMCP_pthatFilter->SaveAs("EffppMCP_pthatFilter.png");



  TFile* infppMCNP_pthatFilter = new TFile(inppMCNP_pthatFilter.Data());

  TTree* ntGenppMCNP_pthatFilter = (TTree*)infppMCNP_pthatFilter->Get("ntGen");
  ntGenppMCNP_pthatFilter->AddFriend("ntHlt");
  ntGenppMCNP_pthatFilter->AddFriend("ntHi");

  TTree* ntppMCNP_pthatFilter = (TTree*)infppMCNP_pthatFilter->Get("ntDkpi");
  ntppMCNP_pthatFilter->AddFriend("ntHlt");
  ntppMCNP_pthatFilter->AddFriend("ntHi");
  ntppMCNP_pthatFilter->AddFriend("ntSkim");
  ntppMCNP_pthatFilter->AddFriend(ntGenppMCNP_pthatFilter);


  TH1D* hPtppMCNP_pthatFilter = new TH1D("hPtppMCNP_pthatFilter","",nPtBins,ptBins);
  TH1D* hPtGenppMCNP_pthatFilter = new TH1D("hPtGenppMCNP_pthatFilter","",nPtBins,ptBins);

  ntppMCNP_pthatFilter->Project("hPtppMCNP_pthatFilter","Dpt",TCut(weight)*(TCut(selmceff.Data())&&"(Dgen==23333)"));
  divideBinWidth(hPtppMCNP_pthatFilter);
  ntGenppMCNP_pthatFilter->Project("hPtGenppMCNP_pthatFilter","Gpt",TCut(weightgen)*(TCut(selmcgen.Data())));
  divideBinWidth(hPtGenppMCNP_pthatFilter);

  hPtppMCNP_pthatFilter->Sumw2();
  TH1D* hEffppMCNP_pthatFilter = (TH1D*)hPtppMCNP_pthatFilter->Clone("hEffppMCNP_pthatFilter");
  hEffppMCNP_pthatFilter->SetTitle(";D^{0} p_{T} (GeV/c);Efficiency");
  hEffppMCNP_pthatFilter->Sumw2();
  hEffppMCNP_pthatFilter->Divide(hPtGenppMCNP_pthatFilter);
  TCanvas* cEffppMCNP_pthatFilter = new TCanvas("cEffppMCNP_pthatFilter","",600,600);
  hEffppMCNP_pthatFilter->Draw();

  cEffppMCNP_pthatFilter->SaveAs("EffppMCNP_pthatFilter.png");

// no pthat weight for new MC sample
  weight="1";
  weightgen="1";


  TFile* infppMCP_DptFilter = new TFile(inppMCP_DptFilter.Data());
	
  TTree* ntGenppMCP_DptFilter = (TTree*)infppMCP_DptFilter->Get("ntGen");
  ntGenppMCP_DptFilter->AddFriend("ntHlt");
  ntGenppMCP_DptFilter->AddFriend("ntHi");

  TTree* ntppMCP_DptFilter = (TTree*)infppMCP_DptFilter->Get("ntDkpi");
  ntppMCP_DptFilter->AddFriend("ntHlt");
  ntppMCP_DptFilter->AddFriend("ntHi");
  ntppMCP_DptFilter->AddFriend("ntSkim");
  ntppMCP_DptFilter->AddFriend(ntGenppMCP_DptFilter);


  TH1D* hPtppMCP_DptFilter = new TH1D("hPtppMCP_DptFilter","",nPtBins,ptBins);
  TH1D* hPtGenppMCP_DptFilter = new TH1D("hPtGenppMCP_DptFilter","",nPtBins,ptBins);

  ntppMCP_DptFilter->Project("hPtppMCP_DptFilter","Dpt",TCut(weight)*(TCut(selmceff.Data())&&"(Dgen==23333)"));
  divideBinWidth(hPtppMCP_DptFilter);
  ntGenppMCP_DptFilter->Project("hPtGenppMCP_DptFilter","Gpt",TCut(weightgen)*(TCut(selmcgen.Data())));
	divideBinWidth(hPtGenppMCP_DptFilter);

  hPtppMCP_DptFilter->Sumw2();
  TH1D* hEffppMCP_DptFilter = (TH1D*)hPtppMCP_DptFilter->Clone("hEffppMCP_DptFilter");
  hEffppMCP_DptFilter->SetTitle(";D^{0} p_{T} (GeV/c);Efficiency");
  hEffppMCP_DptFilter->Sumw2();
  hEffppMCP_DptFilter->Divide(hPtGenppMCP_DptFilter);
  TCanvas* cEffppMCP_DptFilter = new TCanvas("cEffppMCP_DptFilter","",600,600);
	hEffppMCP_DptFilter->Draw();

	cEffppMCP_DptFilter->SaveAs("EffppMCP_DptFilter.png");

  TFile* infppMCNP_DptFilter = new TFile(inppMCNP_DptFilter.Data());

  TTree* ntGenppMCNP_DptFilter = (TTree*)infppMCNP_DptFilter->Get("ntGen");
  ntGenppMCNP_DptFilter->AddFriend("ntHlt");
  ntGenppMCNP_DptFilter->AddFriend("ntHi");

  TTree* ntppMCNP_DptFilter = (TTree*)infppMCNP_DptFilter->Get("ntDkpi");
  ntppMCNP_DptFilter->AddFriend("ntHlt");
  ntppMCNP_DptFilter->AddFriend("ntHi");
  ntppMCNP_DptFilter->AddFriend("ntSkim");
  ntppMCNP_DptFilter->AddFriend(ntGenppMCNP_DptFilter);


  TH1D* hPtppMCNP_DptFilter = new TH1D("hPtppMCNP_DptFilter","",nPtBins,ptBins);
  TH1D* hPtGenppMCNP_DptFilter = new TH1D("hPtGenppMCNP_DptFilter","",nPtBins,ptBins);

  ntppMCNP_DptFilter->Project("hPtppMCNP_DptFilter","Dpt",TCut(weight)*(TCut(selmceff.Data())&&"(Dgen==23333)"));
  divideBinWidth(hPtppMCNP_DptFilter);
  ntGenppMCNP_DptFilter->Project("hPtGenppMCNP_DptFilter","Gpt",TCut(weightgen)*(TCut(selmcgen.Data())));
  divideBinWidth(hPtGenppMCNP_DptFilter);

  hPtppMCNP_DptFilter->Sumw2();
  TH1D* hEffppMCNP_DptFilter = (TH1D*)hPtppMCNP_DptFilter->Clone("hEffppMCNP_DptFilter");
  hEffppMCNP_DptFilter->SetTitle(";D^{0} p_{T} (GeV/c);Efficiency");
  hEffppMCNP_DptFilter->Sumw2();
  hEffppMCNP_DptFilter->Divide(hPtGenppMCNP_DptFilter);
  TCanvas* cEffppMCNP_DptFilter = new TCanvas("cEffppMCNP_DptFilter","",600,600);
  hEffppMCNP_DptFilter->Draw();

  cEffppMCNP_DptFilter->SaveAs("EffppMCNP_DptFilter.png");


	TCanvas *c_effAll = new TCanvas("c_effAll","c_effAll",1000,1000);
	c_effAll->Divide(2,2);

	TH1D *hEffppMCP_ratio=(TH1D*)hEffppMCP_DptFilter->Clone("hEffppMCP_ratio");
	hEffppMCP_ratio->Sumw2();
	hEffppMCP_ratio->Divide(hEffppMCP_pthatFilter);

  TH1D *hEffppMCNP_ratio=(TH1D*)hEffppMCNP_DptFilter->Clone("hEffppMCNP_ratio");
  hEffppMCNP_ratio->Sumw2();
  hEffppMCNP_ratio->Divide(hEffppMCNP_pthatFilter);

  c_effAll->cd(1);
	gPad->SetLogx();
	hEffppMCP_DptFilter->Draw();
	hEffppMCP_DptFilter->SetLineColor(2);
	hEffppMCP_pthatFilter->Draw("eSAME");
	hEffppMCP_pthatFilter->SetLineColor(4);

	TLegend *le_hEffppMCP = new TLegend(0.24,0.68,0.48,0.88,NULL,"brNDC");
	le_hEffppMCP->SetBorderSize(0);
  le_hEffppMCP->AddEntry((TObject*)0,"pp MC efficiency","");
	le_hEffppMCP->AddEntry(hEffppMCP_DptFilter,"Prompt new MC");
	le_hEffppMCP->AddEntry(hEffppMCP_pthatFilter,"Prompt old MC");
	le_hEffppMCP->Draw("same");

  c_effAll->cd(2);
  gPad->SetLogx();
  hEffppMCNP_DptFilter->Draw();
  hEffppMCNP_DptFilter->SetLineColor(2);
  hEffppMCNP_pthatFilter->Draw("eSAME");
  hEffppMCNP_pthatFilter->SetLineColor(4);

  TLegend *le_hEffppMCNP = new TLegend(0.24,0.68,0.48,0.88,NULL,"brNDC");
  le_hEffppMCNP->SetBorderSize(0);
	le_hEffppMCNP->AddEntry((TObject*)0,"pp MC efficiency","");
  le_hEffppMCNP->AddEntry(hEffppMCNP_DptFilter,"Nonprompt new MC");
  le_hEffppMCNP->AddEntry(hEffppMCNP_pthatFilter,"Nonrompt old MC");
  le_hEffppMCNP->Draw("same");

	TLine *line1= new TLine(0,1,100,1);
	line1->SetLineStyle(7);

	c_effAll->cd(3);
  gPad->SetLogx();
	hEffppMCP_ratio->GetYaxis()->SetTitle("Eff Ratio");
	hEffppMCP_ratio->SetMarkerStyle(20);
	hEffppMCP_ratio->SetMarkerSize(0.8);
	hEffppMCP_ratio->SetMarkerColor(4);
	hEffppMCP_ratio->SetLineColor(4);
	hEffppMCP_ratio->Draw();
	line1->Draw("SAME");	
	TLatex* texppMCPratio = new TLatex(0.4,0.4,"pp Prompt D eff ratio new/old");
	texppMCPratio->SetNDC();
	texppMCPratio->SetTextSize(0.035);
	texppMCPratio->Draw();

	
	
	c_effAll->cd(4);
  gPad->SetLogx();
  hEffppMCNP_ratio->GetYaxis()->SetTitle("Eff Ratio");
  hEffppMCNP_ratio->SetMarkerStyle(20);
	hEffppMCNP_ratio->SetMarkerSize(0.8);
  hEffppMCNP_ratio->SetMarkerColor(4);
	hEffppMCNP_ratio->SetLineColor(4);
	hEffppMCNP_ratio->Draw();
  line1->Draw("SAME");
  TLatex* texppMCNPratio = new TLatex(0.4,0.4,"pp Nonrompt D eff ratio new/old");
  texppMCNPratio->SetNDC();
  texppMCNPratio->SetTextSize(0.035);
  texppMCNPratio->Draw();


	
	c_effAll->SaveAs("effAll.png");

// continue work here		

	weight="pthatweight";

	TH1D *h_ptMCP_pthatFilter = new TH1D("h_ptMCP_pthatFilter","h_ptMCP_pthatFilter",40,2,4);
  ntppMCP_pthatFilter->Project("h_ptMCP_pthatFilter","Dpt",TCut(weight)*(TCut(selmceff.Data())&&"(Dgen==23333)"));
	h_ptMCP_pthatFilter->Sumw2();
	h_ptMCP_pthatFilter->Scale(1.0/h_ptMCP_pthatFilter->Integral());

  TH1D *h_ptMCP_DptFilter = new TH1D("h_ptMCP_DptFilter","h_ptMCP_DptFilter",40,2,4);
  ntppMCP_DptFilter->Project("h_ptMCP_DptFilter","Dpt",(TCut(selmceff.Data())&&"(Dgen==23333)"));
	h_ptMCP_DptFilter->Sumw2();
  h_ptMCP_DptFilter->Scale(1.0/h_ptMCP_DptFilter->Integral());

	TCanvas *c_Dptdis = new TCanvas("c_Dptdis","c_Dptdis",600,600);
	c_Dptdis->cd();
	h_ptMCP_pthatFilter->Draw();
	h_ptMCP_pthatFilter->SetLineColor(4);
	h_ptMCP_DptFilter->SetLineColor(2);
	h_ptMCP_DptFilter->Draw("SAME");
	c_Dptdis->SaveAs("plot/c_Dptdis.png");


  TH1D *h_yMCP_pthatFilter = new TH1D("h_yMCP_pthatFilter","h_yMCP_pthatFilter",20,-1,1);
  ntppMCP_pthatFilter->Project("h_yMCP_pthatFilter","Dy",TCut(weight)*(TCut(selmceff.Data())&&"(Dgen==23333)&&(Dpt>2 && Dpt< 4)"));
  h_yMCP_pthatFilter->Sumw2();
  h_yMCP_pthatFilter->Scale(1.0/h_yMCP_pthatFilter->Integral());

  TH1D *h_yMCP_DptFilter = new TH1D("h_yMCP_DptFilter","h_yMCP_DptFilter",20,-1,1);
  ntppMCP_DptFilter->Project("h_yMCP_DptFilter","Dy",(TCut(selmceff.Data())&&"(Dgen==23333)&&(Dpt>2 && Dpt< 4)"));
  h_yMCP_DptFilter->Sumw2();
  h_yMCP_DptFilter->Scale(1.0/h_yMCP_DptFilter->Integral());

  TCanvas *c_Dydis = new TCanvas("c_Dydis","c_Dydis",600,600);
  c_Dydis->cd();
  h_yMCP_pthatFilter->Draw();
  h_yMCP_pthatFilter->SetLineColor(4);
  h_yMCP_DptFilter->SetLineColor(2);
  h_yMCP_DptFilter->Draw("SAME");
  c_Dydis->SaveAs("plot/c_Dydis.png");


  TH1D *h_DcaMCP_pthatFilter = new TH1D("h_DcaMCP_pthatFilter","h_DcaMCP_pthatFilter",nDcaBins,dcaBins);
  ntppMCP_pthatFilter->Project("h_DcaMCP_pthatFilter","DsvpvDistance*sin(Dalpha)",TCut(weight)*(TCut(selmceff.Data())&&"(Dgen==23333)&&(Dpt>2 && Dpt< 4)"));
  h_DcaMCP_pthatFilter->Sumw2();
  h_DcaMCP_pthatFilter->Scale(1.0/h_DcaMCP_pthatFilter->Integral());

  TH1D *h_DcaMCP_DptFilter = new TH1D("h_DcaMCP_DptFilter","h_DcaMCP_DptFilter",nDcaBins,dcaBins);
  ntppMCP_DptFilter->Project("h_DcaMCP_DptFilter","DsvpvDistance*sin(Dalpha)",(TCut(selmceff.Data())&&"(Dgen==23333)&&(Dpt>2 && Dpt< 4)"));
  h_DcaMCP_DptFilter->Sumw2();
  h_DcaMCP_DptFilter->Scale(1.0/h_DcaMCP_DptFilter->Integral());

  TCanvas *c_DDcadis = new TCanvas("c_DDcadis","c_DDcadis",600,600);
  c_DDcadis->cd();
	gPad->SetLogy();
  h_DcaMCP_pthatFilter->Draw();
  h_DcaMCP_pthatFilter->SetLineColor(4);
  h_DcaMCP_DptFilter->SetLineColor(2);
  h_DcaMCP_DptFilter->Draw("SAME");
  c_DDcadis->SaveAs("plot/c_DDcadis.png");




// end of main, save all into output file

  TFile *outf = TFile::Open(outfname.Data(),"recreate");
	outf->cd();
	hEffppMCP_pthatFilter->Write();
  hEffppMCNP_pthatFilter->Write();
  hEffppMCP_DptFilter->Write();
  hEffppMCNP_DptFilter->Write();
	hEffppMCP_ratio->Write();
	hEffppMCNP_ratio->Write();
	outf->Write();
	outf->Close();


}
