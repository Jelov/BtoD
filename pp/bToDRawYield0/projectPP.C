void projectPP()
{
  gStyle->SetTextSize(0.05);
  gStyle->SetTextFont(42);
  gStyle->SetPadRightMargin(0.043);
  gStyle->SetPadLeftMargin(0.18);
  gStyle->SetPadTopMargin(0.1);
  gStyle->SetPadBottomMargin(0.145);
  gStyle->SetTitleX(.0f);
  gStyle->SetOptFit(1111);
  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0);

  TFile* inf = new TFile("/data/dmeson2015/DataDntuple/ntD_EvtBase_20160330_HeavyFlavor_DfinderData_pp_20160329_dPt0tkPt1_D0Dstar3p5p_goldenjson_skim_myskim.root");
  TTree* tData = (TTree*)inf->Get("ntDkpi");
  TTree* tSkim = (TTree*)inf->Get("ntSkim");
  TTree* tHi = (TTree*)inf->Get("ntHi");
  TTree* tHlt = (TTree*)inf->Get("ntHlt");

  tData->AddFriend(tSkim);
  tData->AddFriend(tHi);
  tData->AddFriend(tHlt);

  TFile* outf = new TFile("bFeedDownPP.hist.root","recreate");
  
  TCut cutTriggerPP = "((HLT_DmesonPPTrackingGlobal_Dpt8_v1&&Dpt>10&&Dpt<20)||(HLT_DmesonPPTrackingGlobal_Dpt15_v1&&Dpt>20&&Dpt<40)||(HLT_DmesonPPTrackingGlobal_Dpt30_v1&&Dpt>40&&Dpt<60)||(HLT_DmesonPPTrackingGlobal_Dpt50_v1&&Dpt>60))";
  TCut cutpp = "abs(PVz)<15&&pBeamScrapingFilter&&pPAprimaryVertexFilter&&Dy>-1.&&Dy<1.&&Dtrk1highPurity&&Dtrk2highPurity&&Dtrk1Pt>2.0&&Dtrk2Pt>2.0&&(DsvpvDistance/DsvpvDisErr)>3.5&&(DlxyBS/DlxyBSErr)>2.5&&Dchi2cl>0.05&&Dalpha<0.12&&abs(Dtrk1Eta)<1.5&&abs(Dtrk2Eta)<1.5&&Dtrk1PtErr/Dtrk1Pt<0.3&&Dtrk2PtErr/Dtrk2Pt<0.3";
  TCut cutpt = "Dpt>20";
  TCut cutSignal = "abs(Dmass-1.8649)<0.025";
  TCut cutSideband = "abs(Dmass-1.8649)>0.075&&abs(Dmass-1.8649)<0.1";

  const int nBinX = 14;
  Float_t binsX[nBinX+1] = {2.,3.,4.,5.,6.,8.,10.,12,15.0,20.,25.,30.,40.,60.,100};

/*
  const int nBinY = 20;
  Float_t binsY[nBinY+1];
  float firstBinYWidth = 0.001;
  float binYWidthRatio = 1.27;
  binsY[0]=0;
  for(int i=1; i<=nBinY; i++)
    binsY[i] = binsY[i-1]+firstBinYWidth*pow(binYWidthRatio,i-1);
  cout<<"last y bin: "<<binsY[nBinY]<<endl;
*/

  const int nBinZ = 20;
  Float_t binsZ[nBinZ+1];
  float firstBinZ = 3.5;
  float binWidthZ = 5;
  for(int i=0; i<=nBinZ; i++)
    binsZ[i] = firstBinZ+binWidthZ*i;

  const int nBinY = 20;
  Float_t binsY[nBinY+1] = {-0.0734,-0.0562,-0.0428,-0.0320,-0.0236,-0.0170,-0.0118,-0.0078,-0.0046,-0.002,0.0,0.002,0.0046,0.0078,0.0118,0.0170,0.0236,0.0320,0.0428,0.0562,0.0734};


  const int nBinM = 60;
  Float_t binsM[nBinM];
  float minMassBin = 1.7;
  float massBinWidth = 0.005;
  for(int i=0; i<=nBinM; i++)
    binsM[i] = minMassBin + massBinWidth*i;
  
  TH3D* hSideband = new TH3D("hSideband",";p_{T} (GeV/c};D^{0} DCA_xy (cm);flight distance significance",nBinX,binsX,nBinY,binsY,nBinZ,binsZ);
  TH3D* hData = new TH3D("hData",";p_{T} (GeV/c};D^{0}_xy DCA (cm);flight distance significance",nBinX,binsX,nBinY,binsY,nBinZ,binsZ);
  TH3D* hPtMD0Dca = new TH3D("hPtMD0Dca",";p_{T} (GeV/c);m (GeV/c^{2});D^{0} DCA_xy (cm)",nBinX,binsX,nBinM,binsM,nBinY,binsY);
  
  hSideband->Sumw2();
  hData->Sumw2();
  hPtMD0Dca->Sumw2();
  
  tData->Draw("DsvpvDistance/DsvpvDisErr:DvtxX*sin(Dphi)-DvtxY*cos(Dphi):Dpt>>hSideband",cutpt&&cutTriggerPP&&cutpp&&cutSideband);
  tData->Draw("DsvpvDistance/DsvpvDisErr:DvtxX*sin(Dphi)-DvtxY*cos(Dphi):Dpt>>hData",cutpt&&cutTriggerPP&&cutpp&&cutSignal);
  tData->Draw("DvtxX*sin(Dphi)-DvtxY*cos(Dphi):Dmass:Dpt>>hPtMD0Dca",cutpt&&cutTriggerPP&&cutpp);
  
  outf->Write();
}


