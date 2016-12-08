// combine MB and trigger all pt range

#include "uti.h"
#include "../include/parameters.h"

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

Float_t hiBinMin,hiBinMax;

void efficiency(TString label="PromptPPMB")
{
  TString inputmc, selmcgen, selmcgenacceptance, cut_recoonly, cut, weightfunctiongen, weightfunctionreco, cutPt, cutPtMC;
	TString                    selmcgenacceptanceMB, cut_recoonlyMB, cutMB, cutPtMB, cutPtMCMB;

	bool pthatweightonly=false;

  selmcgen="((GisSignal==1||GisSignal==2)&&(Gy>-1&&Gy<1))";

	if(label=="PromptPP_new" || label=="PromptPPMB_new")
	  inputmc="/data/chengchi/BtoD_MC2016/pp/Dntuple_pp_prompt_mergeAll.root";
  if(label=="NonPromptPP_new" || label=="NonPromptPPMB_new")
    inputmc="/data/chengchi/BtoD_MC2016/pp/Dntuple_pp_Nonprompt_mergeAll.root";
  if(label=="PromptPP" || label=="PromptPPMB")
    inputmc="/data/HeavyFlavourRun2/MC2015/Dntuple/pp/ntD_EvtBase_20160513_DfinderMC_pp_20160502_dPt0tkPt0p5_D0Dstar_prompt_Dpt2Dy1p1tkPt0p7tkEta2Decay2p9Dalpha0p14Skim_pthatweight.root";
  if(label=="NonPromptPP" || label=="NonPromptPPMB")
    inputmc="/data/HeavyFlavourRun2/MC2015/Dntuple/pp/ntD_EvtBase_20160513_DfinderMC_pp_20160502_dPt0tkPt0p5_D0Dstar_nonprompt_Dpt2Dy1p1tkPt0p7tkEta2Decay2p9Dalpha0p14Skim_pthatweight.root";
  if(label=="PromptPbPb" || label=="PromptPbPbMB")
    inputmc="/data/HeavyFlavourRun2/MC2015/Dntuple/PbPb/ntD_EvtBase_20160513_DfinderMC_PbPb_20160502_dPt1tkPt0p5_D0_prompt_Dpt2Dy1p1tkPt0p7tkEta2Decay2p9Dalpha0p14Skim_pthatweight.root";
  if(label=="NonPromptPbPb" || label=="NonPromptPbPbMB")
    inputmc="/data/HeavyFlavourRun2/MC2015/Dntuple/PbPb/ntD_EvtBase_20160513_DfinderMC_PbPb_20160502_dPt1tkPt0p5_D0_nonprompt_Dpt2Dy1p1tkPt0p7tkEta2Decay2p9Dalpha0p14Skim_pthatweight.root";
    
  if(label=="PromptPP" || label=="NonPromptPP" || label=="PromptPP_new" || label=="NonPromptPP_new")
    {
      selmcgenacceptance="((GisSignal==1||GisSignal==2)&&(Gy>-1&&Gy<1))&&abs(Gtk1eta)<1.5&&abs(Gtk2eta)<1.5&&Gtk1pt>2.0&&Gtk2pt>2.0";
      cut_recoonly="abs(PVz)<15&&pBeamScrapingFilter&&pPAprimaryVertexFilter&&Dy>-1.&&Dy<1.&&Dtrk1highPurity&&Dtrk2highPurity&&Dtrk1Pt>2.0&&Dtrk2Pt>2.0&&abs(Dtrk1Eta)<1.5&&abs(Dtrk2Eta)<1.5&&Dtrk1PtErr/Dtrk1Pt<0.3&&Dtrk2PtErr/Dtrk2Pt<0.3";
      cut="abs(PVz)<15&&pBeamScrapingFilter&&pPAprimaryVertexFilter&&Dy>-1.&&Dy<1.&&Dtrk1highPurity&&Dtrk2highPurity&&Dtrk1Pt>2.0&&Dtrk2Pt>2.0&&(DsvpvDistance/DsvpvDisErr)>3.5&&(DlxyBS/DlxyBSErr)>2.5&&Dchi2cl>0.05&&Dalpha<0.12&&abs(Dtrk1Eta)<1.5&&abs(Dtrk2Eta)<1.5&&Dtrk1PtErr/Dtrk1Pt<0.3&&Dtrk2PtErr/Dtrk2Pt<0.3";
      weightfunctiongen="(pthatweight)*(Max$(Gpt)<pthat/1.2)*(0.0116437+Max$(Gpt)*(0.0602697)+Max$(Gpt)*Max$(Gpt)*(-0.00226879)+Max$(Gpt)*Max$(Gpt)*Max$(Gpt)*(3.91035e-05)+Max$(Gpt)*Max$(Gpt)*Max$(Gpt)*Max$(Gpt)*(-3.0699e-07)+Max$(Gpt)*Max$(Gpt)*Max$(Gpt)*Max$(Gpt)*Max$(Gpt)*(8.73234e-10))";
      weightfunctionreco="(pthatweight)*(Max$(Gpt)<pthat/1.2)*(0.0116437+Max$(Gpt)*(0.0602697)+Max$(Gpt)*Max$(Gpt)*(-0.00226879)+Max$(Gpt)*Max$(Gpt)*Max$(Gpt)*(3.91035e-05)+Max$(Gpt)*Max$(Gpt)*Max$(Gpt)*Max$(Gpt)*(-3.0699e-07)+Max$(Gpt)*Max$(Gpt)*Max$(Gpt)*Max$(Gpt)*Max$(Gpt)*(8.73234e-10))";
      cutPt="Dpt>=20";
      cutPtMC="Gpt>=20";

      selmcgenacceptanceMB="((GisSignal==1||GisSignal==2)&&(Gy>-1&&Gy<1))&&abs(Gtk1eta)<1.5&&abs(Gtk2eta)<1.5&&Gtk1pt>1.0&&Gtk2pt>1.0";
      cut_recoonlyMB="abs(PVz)<15&&pBeamScrapingFilter&&pPAprimaryVertexFilter&&Dy>-1.&&Dy<1.&&Dtrk1highPurity&&Dtrk2highPurity&&Dtrk1Pt>1.0&&Dtrk2Pt>1.0&&Dtrk1PtErr/Dtrk1Pt<0.3&&Dtrk2PtErr/Dtrk2Pt<0.3&&abs(Dtrk1Eta)<1.5&&abs(Dtrk2Eta)<1.5";
      cutMB="abs(PVz)<15&&pBeamScrapingFilter&&pPAprimaryVertexFilter&&Dy>-1.&&Dy<1.&&Dtrk1highPurity&&Dtrk2highPurity&&Dtrk1Pt>1.0&&Dtrk2Pt>1.0&&Dtrk1PtErr/Dtrk1Pt<0.3&&Dtrk2PtErr/Dtrk2Pt<0.3&&abs(Dtrk1Eta)<1.5&&abs(Dtrk2Eta)<1.5&&(DsvpvDistance/DsvpvDisErr)>3.5&&(DlxyBS/DlxyBSErr)>2.5&&Dchi2cl>0.05&&Dalpha<0.12";
//      weightfunctiongenMB="(pthatweight)*(Max$(Gpt)<pthat/1.2)*(0.0116437+Max$(Gpt)*(0.0602697)+Max$(Gpt)*Max$(Gpt)*(-0.00226879)+Max$(Gpt)*Max$(Gpt)*Max$(Gpt)*(3.91035e-05)+Max$(Gpt)*Max$(Gpt)*Max$(Gpt)*Max$(Gpt)*(-3.0699e-07)+Max$(Gpt)*Max$(Gpt)*Max$(Gpt)*Max$(Gpt)*Max$(Gpt)*(8.73234e-10))";
//      weightfunctionrecoMB="(pthatweight)*(Max$(Gpt)<pthat/1.2)*(0.0116437+Max$(Gpt)*(0.0602697)+Max$(Gpt)*Max$(Gpt)*(-0.00226879)+Max$(Gpt)*Max$(Gpt)*Max$(Gpt)*(3.91035e-05)+Max$(Gpt)*Max$(Gpt)*Max$(Gpt)*Max$(Gpt)*(-3.0699e-07)+Max$(Gpt)*Max$(Gpt)*Max$(Gpt)*Max$(Gpt)*Max$(Gpt)*(8.73234e-10))";
      cutPtMB="Dpt<20";
      cutPtMCMB="Gpt<20";
    }

/* do not tuch PbPb now
  if(label=="PromptPbPb" || label=="NonPromptPbPb")
    {
      selmcgenacceptance="((GisSignal==1||GisSignal==2)&&(Gy>-1&&Gy<1))&&abs(Gtk1eta)<1.5&&abs(Gtk2eta)<1.5&&Gtk1pt>2.0&&Gtk2pt>2.0";
      cut_recoonly="pclusterCompatibilityFilter&&pprimaryVertexFilter&&phfCoincFilter3&&abs(PVz)<15&&Dy>-1.&&Dy<1.&&Dtrk1highPurity&&Dtrk2highPurity&&Dtrk1Pt>8.5&&Dtrk2Pt>8.5&&abs(Dtrk1Eta)<1.5&&abs(Dtrk2Eta)<1.5&&Dtrk1PtErr/Dtrk1Pt<0.3&&Dtrk2PtErr/Dtrk2Pt<0.3";
      cut="pclusterCompatibilityFilter&&pprimaryVertexFilter&&phfCoincFilter3&&abs(PVz)<15&&Dy>-1.&&Dy<1.&&Dtrk1highPurity&&Dtrk2highPurity&&Dtrk1Pt>8.5&&Dtrk2Pt>8.5&&abs(Dtrk1Eta)<1.5&&abs(Dtrk2Eta)<1.5&&Dtrk1PtErr/Dtrk1Pt<0.3&&Dtrk2PtErr/Dtrk2Pt<0.3&&((DlxyBS/DlxyBSErr)>2.5&&Dalpha<0.12&&((Dpt>2&&Dpt<4&&(DsvpvDistance/DsvpvDisErr)>5.86&&Dchi2cl>0.224)||(Dpt>4&&Dpt<5&&(DsvpvDistance/DsvpvDisErr)>5.46&&Dchi2cl>0.196)||(Dpt>5&&Dpt<6&&(DsvpvDistance/DsvpvDisErr)>4.86&&Dchi2cl>0.170)||(Dpt>6&&Dpt<8&&(DsvpvDistance/DsvpvDisErr)>4.54&&Dchi2cl>0.125)||(Dpt>8&&Dpt<10&&(DsvpvDistance/DsvpvDisErr)>4.42&&Dchi2cl>0.091)||(Dpt>10&&Dpt<15&&(DsvpvDistance/DsvpvDisErr)>4.06&&Dchi2cl>0.069)||(Dpt>15&&Dpt<20&&(DsvpvDistance/DsvpvDisErr)>3.71&&Dchi2cl>0.056)||(Dpt>20&&Dpt<25&&(DsvpvDistance/DsvpvDisErr)>3.25&&Dchi2cl>0.054)||(Dpt>25&&(DsvpvDistance/DsvpvDisErr)>2.97&&Dchi2cl>0.050)))";
      weightfunctiongen="(pthatweight)*(Max$(Gpt)<pthat/1.2)*(6.14981+hiBin*(-0.156513)+hiBin*hiBin*(0.00149127)+hiBin*hiBin*hiBin*(-6.29087e-06)+hiBin*hiBin*hiBin*hiBin*(9.90029e-09))";
      weightfunctionreco="(pthatweight)*(Max$(Gpt)<pthat/1.2)*(6.14981+hiBin*(-0.156513)+hiBin*hiBin*(0.00149127)+hiBin*hiBin*hiBin*(-6.29087e-06)+hiBin*hiBin*hiBin*hiBin*(9.90029e-09))";
      cutPt="Dpt>=20";
      cutPtMC="Gpt>=20";
    }
  if(label=="PromptPbPbMB" || label=="NonPromptPbPbMB")
    {
      selmcgenacceptance="((GisSignal==1||GisSignal==2)&&(Gy>-1&&Gy<1))&&abs(Gtk1eta)<1.5&&abs(Gtk2eta)<1.5&&Gtk1pt>1.0&&Gtk2pt>1.0";
      cut_recoonly="pclusterCompatibilityFilter&&pprimaryVertexFilter&&phfCoincFilter3&&abs(PVz)<15&&Dy>-1.&&Dy<1.&&Dtrk1highPurity&&Dtrk2highPurity&&Dtrk1Pt>1.0&&Dtrk2Pt>1.0&&Dtrk1PtErr/Dtrk1Pt<0.3&&Dtrk2PtErr/Dtrk2Pt<0.3&&abs(Dtrk1Eta)<1.5&&abs(Dtrk2Eta)<1.5";
      cut="pclusterCompatibilityFilter&&pprimaryVertexFilter&&phfCoincFilter3&&abs(PVz)<15&&Dy>-1.&&Dy<1.&&Dtrk1highPurity&&Dtrk2highPurity&&Dtrk1Pt>1.0&&Dtrk2Pt>1.0&&Dtrk1PtErr/Dtrk1Pt<0.3&&Dtrk2PtErr/Dtrk2Pt<0.3&&abs(Dtrk1Eta)<1.5&&abs(Dtrk2Eta)<1.5&&((DlxyBS/DlxyBSErr)>2.5&&Dalpha<0.12&&((Dpt>1&&Dpt<2&&(DsvpvDistance/DsvpvDisErr)>6.0&&Dchi2cl>0.25)||(Dp\
t>2&&Dpt<4&&(DsvpvDistance/DsvpvDisErr)>5.86&&Dchi2cl>0.224)||(Dpt>4&&Dpt<5&&(DsvpvDistance/DsvpvDisErr)>5.46&&Dchi2cl>0.196)||(Dpt>5&&Dpt<6&&(DsvpvDistance/DsvpvDisErr)>4.86&&Dchi2cl>0.170)||(Dpt>6&&Dpt<8&&(DsvpvDistance/DsvpvDisErr)>4.54&&Dchi2cl>0.125)||(Dpt>8&&Dpt<10&&(DsvpvDistance/DsvpvDisErr)>4.42&&Dchi2cl>0.091)||(Dpt>10&&Dpt<15&&(DsvpvDistance/Dsv\
pvDisErr)>4.06&&Dchi2cl>0.069)||(Dpt>15&&Dpt<20&&(DsvpvDistance/DsvpvDisErr)>3.71&&Dchi2cl>0.056)||(Dpt>20&&Dpt<25&&(DsvpvDistance/DsvpvDisErr)>3.25&&Dchi2cl>0.054)||(Dpt>25&&(DsvpvDistance/DsvpvDisErr)>2.97&&Dchi2cl>0.050)))";
      weightfunctiongen="(pthatweight)*(Max$(Gpt)<pthat/1.2)*(6.14981+hiBin*(-0.156513)+hiBin*hiBin*(0.00149127)+hiBin*hiBin*hiBin*(-6.29087e-06)+hiBin*hiBin*hiBin*hiBin*(9.90029e-09))*(-0.00600791+Max$(Gpt)*(0.0838585)+Max$(Gpt)*Max$(Gpt)*(-0.00991096)+Max$(Gpt)*Max$(Gpt)*Max$(Gpt)*(0.000496019)+Max$(Gpt)*Max$(Gpt)*Max$(Gpt)*Max$(Gpt)*(-8.50065e-06))";
      weightfunctionreco="(pthatweight)*(Max$(Gpt)<pthat/1.2)*(6.14981+hiBin*(-0.156513)+hiBin*hiBin*(0.00149127)+hiBin*hiBin*hiBin*(-6.29087e-06)+hiBin*hiBin*hiBin*hiBin*(9.90029e-09))*(-0.00600791+Max$(Gpt)*(0.0838585)+Max$(Gpt)*Max$(Gpt)*(-0.00991096)+Max$(Gpt)*Max$(Gpt)*Max$(Gpt)*(0.000496019)+Max$(Gpt)*Max$(Gpt)*Max$(Gpt)*Max$(Gpt)*(-8.50065e-06))";
      cutPt="Dpt<20";
      cutPtMC="Gpt<20";
    }
*/
  Float_t centmin=0.;
  Float_t centmax=100.;

  if(label=="PromptPPMB_new" || label=="NonPromptPPMB_new" || label=="PromptPP_new" || label=="NonPromptPP_new"){
  weightfunctiongen="(Max$(Gpt)<pthat/1.2)*(0.0116437+Max$(Gpt)*(0.0602697)+Max$(Gpt)*Max$(Gpt)*(-0.00226879)+Max$(Gpt)*Max$(Gpt)*Max$(Gpt)*(3.91035e-05)+Max$(Gpt)*Max$(Gpt)*Max$(Gpt)*Max$(Gpt)*(-3.0699e-07)+Max$(Gpt)*Max$(Gpt)*Max$(Gpt)*Max$(Gpt)*Max$(Gpt)*(8.73234e-10))";
  weightfunctionreco="(Max$(Gpt)<pthat/1.2)*(0.0116437+Max$(Gpt)*(0.0602697)+Max$(Gpt)*Max$(Gpt)*(-0.00226879)+Max$(Gpt)*Max$(Gpt)*Max$(Gpt)*(3.91035e-05)+Max$(Gpt)*Max$(Gpt)*Max$(Gpt)*Max$(Gpt)*(-3.0699e-07)+Max$(Gpt)*Max$(Gpt)*Max$(Gpt)*Max$(Gpt)*Max$(Gpt)*(8.73234e-10))";
}

	if(pthatweightonly){

  if(label=="PromptPPMB" || label=="NonPromptPPMB" || label=="PromptPP" || label=="NonPromptPP"){
  weightfunctiongen="pthatweight*(Max$(Gpt)<pthat/1.2)";
  weightfunctionreco="pthatweight*(Max$(Gpt)<pthat/1.2)";
}
  if(label=="PromptPPMB_new" || label=="NonPromptPPMB_new" || label=="PromptPP_new" || label=="NonPromptPP_new"){
  weightfunctiongen="1*(Max$(Gpt)<pthat/1.2)";
  weightfunctionreco="1*(Max$(Gpt)<pthat/1.2)";
}
}
	
  hiBinMin = centmin*2;
  hiBinMax = centmax*2;

/*  
  if(label=="PromptPbPb" || label=="NonPromptPbPb" || label=="PromptPbPbMB" || label=="NonPromptPbPbMB")
    {
      selmcgen = selmcgen+Form("&&hiBin>=%f&&hiBin<%f",hiBinMin,hiBinMax);
      selmcgenacceptance=selmcgenacceptance+Form("&&hiBin>=%f&&hiBin<%f",hiBinMin,hiBinMax);
      cut_recoonly=cut_recoonly+Form("&&hiBin>=%f&&hiBin<%f",hiBinMin,hiBinMax);
      cut=cut+Form("&&hiBin>=%f&&hiBin<%f",hiBinMin,hiBinMax);
    }
*/

  std::cout<<"selmcgen = "<<selmcgen<<std::endl;
  std::cout<<"selmcgenacceptance = "<<selmcgenacceptance<<std::endl;
  std::cout<<"cut_recoonly = "<<cut_recoonly<<std::endl;
  std::cout<<"AAAA cut = "<<cut<<std::endl;
  std::cout<<"fit function parameters = "<<weightfunctiongen<<std::endl;

  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);
  gStyle->SetEndErrorSize(0);
  gStyle->SetMarkerStyle(20);
 
  TFile* infMC = new TFile(inputmc.Data());
  TTree* ntMC = (TTree*)infMC->Get("ntDkpi");
  TTree* ntGen = (TTree*)infMC->Get("ntGen");
  TTree* ntSkim = (TTree*)infMC->Get("ntSkim");
  ntMC->AddFriend(ntGen);
  ntMC->AddFriend(ntSkim);
  
  TTree* nthi = (TTree*)infMC->Get("ntHi");
  ntGen->AddFriend(nthi);
  ntGen->AddFriend(ntSkim);
  nthi->AddFriend(ntMC);
  ntMC->AddFriend(nthi);
  
//  const int nPtBins = 9;
//  Float_t ptBins[nPtBins+1] = {2.,4.,6.,8.,10.,12.,20.,40.,60.,100};

  TH1D* hPtMC = new TH1D("hPtMC",";p_{T} (GeV/c)",nPtBins,ptBins);
  TH1D* hPtMCrecoonly = new TH1D("hPtMCrecoonly",";p_{T} (GeV/c)",nPtBins,ptBins);
  TH1D* hPtGen = new TH1D("hPtGen",";p_{T} (GeV/c)",nPtBins,ptBins);
  TH1D* hPtGenAcc = new TH1D("hPtGenAcc",";p_{T} (GeV/c)",nPtBins,ptBins);
  TH1D* hPthat = new TH1D("hPthat",";p_{T} (GeV/c)",100,0,500);
  TH1D* hPthatweight = new TH1D("hPthatweight",";p_{T} (GeV/c)",100,0,500);

	// add all pt range in once  

  ntMC->Project("hPtMC","Dpt",TCut(weightfunctionreco)*((TCut(cut.Data())&&"(Dgen==23333)"&&TCut(cutPt.Data())) || (TCut(cutMB.Data())&&"(Dgen==23333)"&&TCut(cutPtMB.Data())) ));
  divideBinWidth(hPtMC);
  std::cout<<"step1"<<std::endl;
  ntMC->Project("hPtMCrecoonly","Dpt",TCut(weightfunctionreco)*((TCut(cut_recoonly.Data())&&"(Dgen==23333)"&&TCut(cutPt.Data())) || (TCut(cut_recoonlyMB.Data())&&"(Dgen==23333)"&&TCut(cutPtMB.Data()))  ));
  divideBinWidth(hPtMCrecoonly);
  std::cout<<"step2"<<std::endl;
  ntGen->Project("hPtGen","Gpt",TCut(weightfunctiongen)*( (TCut(selmcgen.Data())&&TCut(cutPtMC.Data())) || (TCut(selmcgen.Data())&&TCut(cutPtMCMB.Data()))    ));
  divideBinWidth(hPtGen);
  std::cout<<"step3"<<std::endl;
  ntGen->Project("hPtGenAcc","Gpt",TCut(weightfunctiongen)*( (TCut(selmcgenacceptance.Data())&&TCut(cutPtMC.Data())) || (TCut(selmcgenacceptanceMB.Data())&&TCut(cutPtMCMB.Data()))   ));
  divideBinWidth(hPtGenAcc);
  std::cout<<"step4"<<std::endl;

  ntMC->Project("hPthat","pthat","1");
  ntMC->Project("hPthatweight","pthat",TCut("1"));

  hPtMC->Sumw2();
  TH1D* hEff = (TH1D*)hPtMC->Clone("hEff");
  hEff->Divide(hPtGen);

  TH1D* hEffReco = (TH1D*)hPtMCrecoonly->Clone("hEffReco");
  hEffReco->Sumw2();
  hEffReco->Divide(hPtGen);

  TH1D* hEffAcc = (TH1D*)hPtGenAcc->Clone("hEffAcc");
  hEffAcc->Sumw2();
  hEffAcc->Divide(hEffAcc,hPtGen,1,1,"b");
  
  TH1D* hEffSelection = (TH1D*)hPtMC->Clone("hEffSelection");
  hEffSelection->Sumw2();
  hEffSelection->Divide(hEffSelection,hPtMCrecoonly,1,1,"b");
  
  TH2F* hemptyEff=new TH2F("hemptyEff","",50,ptBins[0]-5.,ptBins[nPtBins]+5.,10.,0,1.5);  
  hemptyEff->GetXaxis()->CenterTitle();
  hemptyEff->GetYaxis()->CenterTitle();
  hemptyEff->GetYaxis()->SetTitle("acceptance x #epsilon_{reco} x #epsilon_{sel} ");
  hemptyEff->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  hemptyEff->GetXaxis()->SetTitleOffset(0.9);
  hemptyEff->GetYaxis()->SetTitleOffset(0.95);
  hemptyEff->GetXaxis()->SetTitleSize(0.05);
  hemptyEff->GetYaxis()->SetTitleSize(0.05);
  hemptyEff->GetXaxis()->SetTitleFont(42);
  hemptyEff->GetYaxis()->SetTitleFont(42);
  hemptyEff->GetXaxis()->SetLabelFont(42);
  hemptyEff->GetYaxis()->SetLabelFont(42);
  hemptyEff->GetXaxis()->SetLabelSize(0.035);
  hemptyEff->GetYaxis()->SetLabelSize(0.035);  
  hemptyEff->SetMaximum(2);
  hemptyEff->SetMinimum(0.);
  hemptyEff->Draw();

  TH2F* hemptyEffAcc=(TH2F*)hemptyEff->Clone("hemptyEffAcc");
  TH2F* hemptyEffReco=(TH2F*)hemptyEff->Clone("hemptyEffReco");
  TH2F* hemptyEffSelection=(TH2F*)hemptyEff->Clone("hemptyEffSelection");
  
  TCanvas*canvasEff=new TCanvas("canvasEff","canvasEff",1000.,500);
  canvasEff->Divide(2,1);
  canvasEff->cd(1);
  
  hemptyEffAcc->SetYTitle("#alpha");
  hemptyEffAcc->Draw();
  hEffAcc->Draw("same");
  canvasEff->cd(2);
  hemptyEff->Draw();
  hEff->Draw("same");
//  canvasEff->SaveAs(Form("efficiency_%s.pdf",label.Data()));
  
  
  TH2F* hemptyPthat=new TH2F("hemptyPthat","",50,0.,500.,10,1e-5,1e9);  
  hemptyPthat->GetXaxis()->CenterTitle();
  hemptyPthat->GetYaxis()->CenterTitle();
  hemptyPthat->GetYaxis()->SetTitle("Entries");
  hemptyPthat->GetXaxis()->SetTitle("pthat");
  hemptyPthat->GetXaxis()->SetTitleOffset(0.9);
  hemptyPthat->GetYaxis()->SetTitleOffset(0.95);
  hemptyPthat->GetXaxis()->SetTitleSize(0.05);
  hemptyPthat->GetYaxis()->SetTitleSize(0.05);
  hemptyPthat->GetXaxis()->SetTitleFont(42);
  hemptyPthat->GetYaxis()->SetTitleFont(42);
  hemptyPthat->GetXaxis()->SetLabelFont(42);
  hemptyPthat->GetYaxis()->SetLabelFont(42);
  hemptyPthat->GetXaxis()->SetLabelSize(0.035);
  hemptyPthat->GetYaxis()->SetLabelSize(0.035);  
  hemptyPthat->SetMaximum(2);
  hemptyPthat->SetMinimum(0.);


  TH2F* hemptySpectra=new TH2F("hemptySpectra","",50,0.,130.,10,1,1e5);  
  hemptySpectra->GetXaxis()->CenterTitle();
  hemptySpectra->GetYaxis()->CenterTitle();
  hemptySpectra->GetYaxis()->SetTitle("Entries");
  hemptySpectra->GetXaxis()->SetTitle("p_{T}");
  hemptySpectra->GetXaxis()->SetTitleOffset(0.9);
  hemptySpectra->GetYaxis()->SetTitleOffset(0.95);
  hemptySpectra->GetXaxis()->SetTitleSize(0.05);
  hemptySpectra->GetYaxis()->SetTitleSize(0.05);
  hemptySpectra->GetXaxis()->SetTitleFont(42);
  hemptySpectra->GetYaxis()->SetTitleFont(42);
  hemptySpectra->GetXaxis()->SetLabelFont(42);
  hemptySpectra->GetYaxis()->SetLabelFont(42);
  hemptySpectra->GetXaxis()->SetLabelSize(0.035);
  hemptySpectra->GetYaxis()->SetLabelSize(0.035);  

  TH2F* hemptyPthatWeighted=(TH2F*)hemptyPthat->Clone("hemptyPthatWeighted");
  hemptyPthatWeighted->GetXaxis()->SetTitle("pthat reweighted");
  
  TCanvas*canvasPthat=new TCanvas("canvasPthat","canvasPthat",1000.,500);
  canvasPthat->Divide(2,1);
  canvasPthat->cd(1);
  gPad->SetLogy();
  hemptyPthat->Draw("same");
  hPthat->Draw("same");
  canvasPthat->cd(2);
  gPad->SetLogy();
  hemptyPthatWeighted->Draw();
  hPthatweight->Draw("same");
//  canvasPthat->SaveAs(Form("ptHat_%s.pdf",label.Data()));
  
  TCanvas*canvasSpectra=new TCanvas("canvasSpectra","canvasSpectra",1000.,500);
  canvasSpectra->Divide(2,1);
  canvasSpectra->cd(1);
  gPad->SetLogy();
  hemptySpectra->Draw();
  hPtMC->Draw("same");
  canvasSpectra->cd(2);
  gPad->SetLogy();
  hemptySpectra->Draw();
  hPtGen->Draw("same");


	// add other variables

  TH1D *hPtDis2to4 = new TH1D("hPtDis2to4","hPtDis2to4",40,2,4);
  TH1D *hDcaDis2to4 = new TH1D("hDcaDis2to4","hDcaDis2to4",nDcaBins,dcaBins);
	TH1D *hDtrk1Pt2to4 = new TH1D("hDtrk1Pt2to4","hDtrk1Pt2to4",200,0,10);
  TH1D *hDtrk2Pt2to4 = new TH1D("hDtrk2Pt2to4","hDtrk2Pt2to4",200,0,10);	

  TCut cut_dpt2to4 = "Dpt>2 && Dpt<4";

  TCut cut_all= TCut(weightfunctionreco)*( ((TCut(cut.Data())&&"(Dgen==23333)"&&TCut(cutPt.Data())) || (TCut(cutMB.Data())&&"(Dgen==23333)"&&TCut(cutPtMB.Data())) ) && cut_dpt2to4 );

	TCut cut_minimum = TCut(weightfunctionreco)*(cut_dpt2to4  &&"(Dgen==23333)");

  cout<<"cut_all name = "<<cut_all.GetTitle()<<endl;
//  cout<<"cut_all ="<<cut_all<<endl; also work

  ntMC->Project("hPtDis2to4","Dpt",TCut(weightfunctionreco)*( ((TCut(cut.Data())&&"(Dgen==23333)"&&TCut(cutPt.Data())) || (TCut(cutMB.Data())&&"(Dgen==23333)"&&TCut(cutPtMB.Data())) ) && cut_dpt2to4 ) );
  ntMC->Project("hDcaDis2to4","DsvpvDistance*sin(Dalpha)",TCut(weightfunctionreco)*( ((TCut(cut.Data())&&"(Dgen==23333)"&&TCut(cutPt.Data())) || (TCut(cutMB.Data())&&"(Dgen==23333)"&&TCut(cutPtMB.Data())) ) && cut_dpt2to4 ) );
	ntMC->Project("hDtrk1Pt2to4","Dtrk1Pt",cut_minimum);
  ntMC->Project("hDtrk2Pt2to4","Dtrk2Pt",cut_minimum);




  TFile *fout=new TFile(Form("eff_rootFiles/efficiency%s.root", label.Data()),"recreate");
  fout->cd();

  hPtGen->Write();
  hEffAcc->Write();
  hEffReco->Write();
  hEffSelection->Write();
  hEff->Write();
  hPtMC->Write();

	hPtDis2to4->Write();
	hDcaDis2to4->Write();
	hDtrk1Pt2to4->Write();
	hDtrk2Pt2to4->Write();
  fout->Close();  

}





