void projectPbPbMB()
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

  TFile* inf = new TFile("/data/jisun/PbPb2015/HF2and_ncand_skim_Dntuple_crab_PbPb_HIMinimumBias1to7_ForestAOD_D0y1p1_tkpt0p7eta1p5_goldenjson_EvtPlaneCali_03182015.root");
  TTree* tData = (TTree*)inf->Get("ntDkpi");
  TTree* tSkim = (TTree*)inf->Get("ntSkim");
  TTree* tHi = (TTree*)inf->Get("ntHi");
  TTree* tHlt = (TTree*)inf->Get("ntHlt");

  tData->AddFriend(tSkim);
  tData->AddFriend(tHi);
  tData->AddFriend(tHlt);

  TFile* outf = new TFile("bFeedDownPbPbMB.hist.root","recreate");
  
  TCut cutTriggerPbPbMB = "(HLT_HIL1MinimumBiasHF2AND_part1_v1||HLT_HIL1MinimumBiasHF2AND_part2_v1||HLT_HIL1MinimumBiasHF2AND_part3_v1)";
  TCut cutPbPbMB = "pclusterCompatibilityFilter&&pprimaryVertexFilter&&abs(PVz)<15&&phfCoincFilter3&&Dy>-1.&&Dy<1.&&Dtrk1highPurity&&Dtrk2highPurity&&Dtrk1Pt>1.0&&Dtrk2Pt>1.0&&Dtrk1PtErr/Dtrk1Pt<0.3&&Dtrk2PtErr/Dtrk2Pt<0.3&&abs(Dtrk1Eta)<1.5&&abs(Dtrk2Eta)<1.5&&((DlxyBS/DlxyBSErr)>1.5&&Dalpha<0.12&&((Dpt>1&&Dpt<2&&(DsvpvDistance/DsvpvDisErr)>6.0&&Dchi2cl>0.25)||(Dpt>2&&Dpt<4&&(DsvpvDistance/DsvpvDisErr)>5.86&&Dchi2cl>0.224)||(Dpt>4&&Dpt<5&&(DsvpvDistance/DsvpvDisErr)>5.46&&Dchi2cl>0.196)||(Dpt>5&&Dpt<6&&(DsvpvDistance/DsvpvDisErr)>4.86&&Dchi2cl>0.170)||(Dpt>6&&Dpt<8&&(DsvpvDistance/DsvpvDisErr)>4.54&&Dchi2cl>0.125)||(Dpt>8&&Dpt<10&&(DsvpvDistance/DsvpvDisErr)>4.42&&Dchi2cl>0.091)||(Dpt>10&&Dpt<15&&(DsvpvDistance/DsvpvDisErr)>4.06&&Dchi2cl>0.069)||(Dpt>15&&Dpt<20&&(DsvpvDistance/DsvpvDisErr)>3.71&&Dchi2cl>0.056)||(Dpt>20&&Dpt<25&&(DsvpvDistance/DsvpvDisErr)>3.25&&Dchi2cl>0.054)||(Dpt>25&&(DsvpvDistance/DsvpvDisErr)>2.97&&Dchi2cl>0.050)))";
  TCut cutCentralityBin = "hiBin>=0&&hiBin<200";
  TCut cutpt = "Dpt<20";
  TCut cutSignal = "abs(Dmass-1.8649)<0.025";
  TCut cutSideband = "abs(Dmass-1.8649)>0.075&&abs(Dmass-1.8649)<0.1";

  const int nBinX = 14;
  Float_t binsX[nBinX+1] = {2.,3.,4.,5.,6.,8.,10.,12.5,15.0,20.,25.,30.,40.,60.,100};

  const int nBinY = 20;
  Float_t binsY[nBinY+1];
  float firstBinYWidth = 0.001;
  float binYWidthRatio = 1.27;
  binsY[0]=0;
  for(int i=1; i<=nBinY; i++)
    binsY[i] = binsY[i-1]+firstBinYWidth*pow(binYWidthRatio,i-1);
  cout<<"last y bin: "<<binsY[nBinY]<<endl;

  const int nBinZ = 20;
  Float_t binsZ[nBinZ+1];
  float firstBinZ = 3.5;
  float binWidthZ = 5;
  for(int i=0; i<=nBinZ; i++)
    binsZ[i] = firstBinZ+binWidthZ*i;
  
  const int nBinM = 60;
  Float_t binsM[nBinM];
  float minMassBin = 1.7;
  float massBinWidth = 0.005;
  for(int i=0; i<=nBinM; i++)
    binsM[i] = minMassBin + massBinWidth*i;

  TH3D* hSideband = new TH3D("hSideband",";p_{T} (GeV/c};D^{0} DCA (cm);flight distance significance",nBinX,binsX,nBinY,binsY,nBinZ,binsZ);
  TH3D* hData = new TH3D("hData",";p_{T} (GeV/c};D^{0} DCA (cm);flight distance significance",nBinX,binsX,nBinY,binsY,nBinZ,binsZ);
  TH3D* hPtMD0Dca = new TH3D("hPtMD0Dca",";p_{T} (GeV/c);m (GeV/c^{2});D^{0} DCA (cm)",nBinX,binsX,nBinM,binsM,nBinY,binsY);
  
  hSideband->Sumw2();
  hData->Sumw2();
  hPtMD0Dca->Sumw2();
  
  tData->Draw("DsvpvDistance/DsvpvDisErr:DsvpvDistance*sin(Dalpha):Dpt>>hSideband",cutpt&&cutTriggerPbPbMB&&cutPbPbMB&&cutCentralityBin&&cutSideband);
  tData->Draw("DsvpvDistance/DsvpvDisErr:DsvpvDistance*sin(Dalpha):Dpt>>hData",cutpt&&cutTriggerPbPbMB&&cutPbPbMB&&cutCentralityBin&&cutSignal);
  tData->Draw("DsvpvDistance*sin(Dalpha):Dmass:Dpt>>hPtMD0Dca",cutpt&&cutTriggerPbPbMB&&cutPbPbMB&&cutCentralityBin);
  
  outf->Write();
}


