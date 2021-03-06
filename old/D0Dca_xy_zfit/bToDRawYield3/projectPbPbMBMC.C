void projectPbPbMBMC()
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

  TFile* infMCP = new TFile("/data/HeavyFlavourRun2/MC2015/Dntuple/PbPb/ntD_EvtBase_20160513_DfinderMC_PbPb_20160502_dPt1tkPt0p5_D0_prompt_Dpt2Dy1p1tkPt0p7tkEta2Decay2p9Dalpha0p14Skim_pthatweight.root");
  TFile* infMCNP = new TFile("/data/HeavyFlavourRun2/MC2015/Dntuple/PbPb/ntD_EvtBase_20160513_DfinderMC_PbPb_20160502_dPt1tkPt0p5_D0_nonprompt_Dpt2Dy1p1tkPt0p7tkEta2Decay2p9Dalpha0p14Skim_pthatweight.root");
  
  TTree* tMCP = (TTree*)infMCP->Get("ntDkpi");
  TTree* tMCNP = (TTree*)infMCNP->Get("ntDkpi");
  TTree* tMCPHI = (TTree*)infMCP->Get("ntHi");
  TTree* tMCNPHI = (TTree*)infMCNP->Get("ntHi");
  TTree* tMCPSkim = (TTree*)infMCP->Get("ntSkim");
  TTree* tMCNPSkim = (TTree*)infMCNP->Get("ntSkim");
  tMCP->AddFriend(tMCPHI);
  tMCNP->AddFriend(tMCNPHI);
  tMCP->AddFriend(tMCPSkim);
  tMCNP->AddFriend(tMCNPSkim);
  
  TFile* outf = new TFile("bFeedDownPbPbMBMC.hist.root","recreate");
  
  TCut cutPbPbMB = "pclusterCompatibilityFilter&&pprimaryVertexFilter&&phfCoincFilter3&&abs(PVz)<15&&Dy>-1.&&Dy<1.&&Dtrk1highPurity&&Dtrk2highPurity&&Dtrk1Pt>1.0&&Dtrk2Pt>1.0&&Dtrk1PtErr/Dtrk1Pt<0.3&&Dtrk2PtErr/Dtrk2Pt<0.3&&abs(Dtrk1Eta)<1.5&&abs(Dtrk2Eta)<1.5&&((DlxyBS/DlxyBSErr)>1.5&&Dalpha<0.12&&((Dpt>1&&Dpt<2&&(DsvpvDistance/DsvpvDisErr)>6.0&&Dchi2cl>0.25)||(Dpt>2&&Dpt<4&&(DsvpvDistance/DsvpvDisErr)>5.86&&Dchi2cl>0.224)||(Dpt>4&&Dpt<5&&(DsvpvDistance/DsvpvDisErr)>5.46&&Dchi2cl>0.196)||(Dpt>5&&Dpt<6&&(DsvpvDistance/DsvpvDisErr)>4.86&&Dchi2cl>0.170)||(Dpt>6&&Dpt<8&&(DsvpvDistance/DsvpvDisErr)>4.54&&Dchi2cl>0.125)||(Dpt>8&&Dpt<10&&(DsvpvDistance/DsvpvDisErr)>4.42&&Dchi2cl>0.091)||(Dpt>10&&Dpt<15&&(DsvpvDistance/DsvpvDisErr)>4.06&&Dchi2cl>0.069)||(Dpt>15&&Dpt<20&&(DsvpvDistance/DsvpvDisErr)>3.71&&Dchi2cl>0.056)||(Dpt>20&&Dpt<25&&(DsvpvDistance/DsvpvDisErr)>3.25&&Dchi2cl>0.054)||(Dpt>25&&(DsvpvDistance/DsvpvDisErr)>2.97&&Dchi2cl>0.050)))";

  TCut cutmc = "(Dgen==23333||Dgen==23344)";
  TCut cutmcSignal = "Dgen==23333";
  TCut cutmcSwapped = "Dgen==23344";
  TCut cutpt = "Dpt<20 && DgencollisionId==0 && sqrt(pow(DsvpvDistance*sin(Dalpha),2)-pow(abs(DvtxX*sin(Dphi)-DvtxY*cos(Dphi)),2))>0.003";
  TCut cutSignal = "abs(Dmass-1.8649)<0.025";
  TCut cutSideband = "abs(Dmass-1.8649)>0.075&&abs(Dmass-1.8649)<0.1";
  TCut cutPrompt = "DgenBAncestorpt<=0";
  TCut cutNonPrompt ="DgenBAncestorpt>0";
  TCut weightfunctionreco = "pthatweight";

  const int nBinX = 14;
  Float_t binsX[nBinX+1] = {2.,3.,4.,5.,6.,8.,10.,12.5,15.0,20.,25.,30.,40.,60.,100};
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
/*
  const int nBinY = 200;
  Float_t binsY[nBinY+1];
  float firstBinY = -0.1;
  float binWidthY = 0.001;
  for(int i = 0 ; i<=nBinY; i++)
    binsY[i] = firstBinY+binWidthY*i;
*/
  const int nBinY = 20;
  Float_t binsY[nBinY+1] = {-0.0734,-0.0562,-0.0428,-0.0320,-0.0236,-0.0170,-0.0118,-0.0078,-0.0046,-0.002,0.0,0.002,0.0046,0.0078,0.0118,0.0170,0.0236,0.0320,0.0428,0.0562,0.0734};

/*
  const int nBinZ = 20;
  Float_t binsZ[nBinZ+1];
  float firstBinZ = 3.5;
  float binWidthZ = 5;
  for(int i=0; i<=nBinZ; i++)
    binsZ[i] = firstBinZ+binWidthZ*i;
*/
  const int nBinZ = 80;
  Float_t binsZ[nBinZ+1];
  for(int i=0; i<=nBinZ; i++){
    binsZ[i]=i*0.001;
  }
 
  const int nBinM = 60;
  Float_t binsM[nBinM];
  float minMassBin = 1.7;
  float massBinWidth = 0.005;
  for(int i=0; i<=nBinM; i++)
    binsM[i] = minMassBin + massBinWidth*i;

  TH3D* hMCPSignal = new TH3D("hMCPSignal",";p_{T} (GeV/c);D^{0} DCA_xy (cm);D^{0} DCA_z (cm)",nBinX,binsX,nBinY,binsY,nBinZ,binsZ);
  TH3D* hMCNPSignal = new TH3D("hMCNPSignal",";p_{T} (GeV/c);D^{0} DCA_xy (cm);D^{0} DCA_z (cm)",nBinX,binsX,nBinY,binsY,nBinZ,binsZ);
  TH3D* hPtMD0DcaMCPSignal = new TH3D("hPtMD0DcaMCPSignal",";p_{T} (GeV/c);m (GeV/c^{2});D^{0} DCA_xy (cm)",nBinX,binsX,nBinM,binsM,nBinY,binsY);
  TH3D* hPtMD0DcaMCPSwapped = new TH3D("hPtMD0DcaMCPSwapped",";p_{T} (GeV/c);m (GeV/c^{2});D^{0} DCA_xy (cm)",nBinX,binsX,nBinM,binsM,nBinY,binsY);
  
  hMCPSignal->Sumw2();
  hMCNPSignal->Sumw2();
  hPtMD0DcaMCPSignal->Sumw2();
  hPtMD0DcaMCPSwapped->Sumw2();
  
  tMCP->Draw("sqrt(pow(DsvpvDistance*sin(Dalpha),2)-pow(abs(DvtxX*sin(Dphi)-DvtxY*cos(Dphi)),2)):DvtxX*sin(Dphi)-DvtxY*cos(Dphi):Dpt>>hMCPSignal",weightfunctionreco*(cutpt&&cutPbPbMB&&cutSignal&&cutmc&&cutPrompt));
  tMCNP->Draw("sqrt(pow(DsvpvDistance*sin(Dalpha),2)-pow(abs(DvtxX*sin(Dphi)-DvtxY*cos(Dphi)),2)):DvtxX*sin(Dphi)-DvtxY*cos(Dphi):Dpt>>hMCNPSignal",weightfunctionreco*(cutpt&&cutPbPbMB&&cutSignal&&cutmc&&cutNonPrompt));
  tMCP->Draw("DvtxX*sin(Dphi)-DvtxY*cos(Dphi):Dmass:Dpt>>hPtMD0DcaMCPSignal",cutpt&&cutPbPbMB&&cutmcSignal&&cutPrompt);
  tMCP->Draw("DvtxX*sin(Dphi)-DvtxY*cos(Dphi):Dmass:Dpt>>hPtMD0DcaMCPSwapped",cutpt&&cutPbPbMB&&cutmcSwapped&&cutPrompt);
  
  outf->Write();
}

