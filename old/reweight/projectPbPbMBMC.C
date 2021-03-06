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

	TFile* outf = new TFile("bFeedDownPbPbMBMC_FineDPt.hist.root","recreate");

	TCut cutPbPbMB = "pclusterCompatibilityFilter&&pprimaryVertexFilter&&phfCoincFilter3&&abs(PVz)<15&&Dy>-1.&&Dy<1.&&Dtrk1highPurity&&Dtrk2highPurity&&Dtrk1Pt>1.0&&Dtrk2Pt>1.0&&Dtrk1PtErr/Dtrk1Pt<0.3&&Dtrk2PtErr/Dtrk2Pt<0.3&&abs(Dtrk1Eta)<1.5&&abs(Dtrk2Eta)<1.5&&((DlxyBS/DlxyBSErr)>1.5&&Dalpha<0.12&&((Dpt>1&&Dpt<2&&(DsvpvDistance/DsvpvDisErr)>6.0&&Dchi2cl>0.25)||(Dpt>2&&Dpt<4&&(DsvpvDistance/DsvpvDisErr)>5.86&&Dchi2cl>0.224)||(Dpt>4&&Dpt<5&&(DsvpvDistance/DsvpvDisErr)>5.46&&Dchi2cl>0.196)||(Dpt>5&&Dpt<6&&(DsvpvDistance/DsvpvDisErr)>4.86&&Dchi2cl>0.170)||(Dpt>6&&Dpt<8&&(DsvpvDistance/DsvpvDisErr)>4.54&&Dchi2cl>0.125)||(Dpt>8&&Dpt<10&&(DsvpvDistance/DsvpvDisErr)>4.42&&Dchi2cl>0.091)||(Dpt>10&&Dpt<15&&(DsvpvDistance/DsvpvDisErr)>4.06&&Dchi2cl>0.069)||(Dpt>15&&Dpt<20&&(DsvpvDistance/DsvpvDisErr)>3.71&&Dchi2cl>0.056)||(Dpt>20&&Dpt<25&&(DsvpvDistance/DsvpvDisErr)>3.25&&Dchi2cl>0.054)||(Dpt>25&&(DsvpvDistance/DsvpvDisErr)>2.97&&Dchi2cl>0.050)))";

	TCut cutmc = "(Dgen==23333||Dgen==23344)";
	TCut cutmcSignal = "Dgen==23333";
	TCut cutmcSwapped = "Dgen==23344";
	TCut cutpt = "Dpt<20";
	TCut cutSignal = "abs(Dmass-1.8649)<0.025";
	TCut cutSideband = "abs(Dmass-1.8649)>0.075&&abs(Dmass-1.8649)<0.1";
	TCut cutPrompt = "DgenBAncestorpt<=0";
	TCut cutNonPrompt ="DgenBAncestorpt>0";
	TCut weightfunctionreco = "pthatweight";

	TCut cutCentralityBin = "hiBin>=0&&hiBin<200";
  TCut cutCentralityBinArr[] = {"hiBin>=0&&hiBin<200","hiBin>=0&&hiBin<20","hiBin>=20&&hiBin<60","hiBin>=60&&hiBin<100","hiBin>=100&&hiBin<200"};
	TCut weightfunctionrecoArr[]={ "pthatweight" , "1"};


//	const int nBinX = 14;
//	Float_t binsX[nBinX+1] = {2.,3.,4.,5.,6.,8.,10.,12.5,15.0,20.,25.,30.,40.,60.,100};
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

	const int nCent = 5;
	const int nPtWeight = 2;
	TH3D* hMCPSignal[nCent][nPtWeight];
	TH3D* hMCNPSignal[nCent][nPtWeight];
	TH3D* hPtMD0DcaMCPSignal[nCent][nPtWeight];
	TH3D* hPtMD0DcaMCPSwapped[nCent][nPtWeight];

	const char* CentArr[] ={"cent0to100","cent0to10", "cent10to30", "cent30to50", "cent50to100"};
	const char* PtWeightArr[] ={"PtWeight","NoWeight"};

	std::string iCentStr = "eta0to15";
	std::string iPtWeightStr = "PtWeight";


	for(int iCent=0; iCent<nCent; iCent++){
		iCentStr= CentArr[iCent];
		cutCentralityBin=cutCentralityBinArr[iCent];	
		for(int iPtWeight=0 ; iPtWeight<nPtWeight ; iPtWeight++){
			iPtWeightStr= PtWeightArr[iPtWeight];
		  weightfunctionreco = weightfunctionrecoArr[iPtWeight];

			hMCPSignal[iCent][iPtWeight] = new TH3D(Form("hMCPSignal_%s%s", iCentStr.c_str(), iPtWeightStr.c_str() ),";p_{T} (GeV/c);D^{0} DCA (cm);flight distance significance",nBinX,binsX,nBinY,binsY,nBinZ,binsZ);
			hMCNPSignal[iCent][iPtWeight] = new TH3D(Form("hMCNPSignal_%s%s",  iCentStr.c_str(), iPtWeightStr.c_str() ),";p_{T} (GeV/c);D^{0} DCA (cm);flight distance significance",nBinX,binsX,nBinY,binsY,nBinZ,binsZ);
			hPtMD0DcaMCPSignal[iCent][iPtWeight] = new TH3D(Form("hPtMD0DcaMCPSignal_%s%s",  iCentStr.c_str(), iPtWeightStr.c_str() ),";p_{T} (GeV/c);m (GeV/c^{2});D^{0} DCA (cm)",nBinX,binsX,nBinM,binsM,nBinY,binsY);
			hPtMD0DcaMCPSwapped[iCent][iPtWeight] = new TH3D(Form("hPtMD0DcaMCPSwapped_%s%s",  iCentStr.c_str(), iPtWeightStr.c_str() ),";p_{T} (GeV/c);m (GeV/c^{2});D^{0} DCA (cm)",nBinX,binsX,nBinM,binsM,nBinY,binsY);

			hMCPSignal[iCent][iPtWeight]->Sumw2();
			hMCNPSignal[iCent][iPtWeight]->Sumw2();
			hPtMD0DcaMCPSignal[iCent][iPtWeight]->Sumw2();
			hPtMD0DcaMCPSwapped[iCent][iPtWeight]->Sumw2();

			tMCP->Draw(Form("DsvpvDistance/DsvpvDisErr:DsvpvDistance*sin(Dalpha):Dpt>>hMCPSignal_%s%s", iCentStr.c_str(), iPtWeightStr.c_str() ),weightfunctionreco*(cutpt&&cutPbPbMB&&cutSignal&&cutmc&&cutPrompt&&cutCentralityBin));
			tMCNP->Draw(Form("DsvpvDistance/DsvpvDisErr:DsvpvDistance*sin(Dalpha):Dpt>>hMCNPSignal_%s%s", iCentStr.c_str(), iPtWeightStr.c_str()),weightfunctionreco*(cutpt&&cutPbPbMB&&cutSignal&&cutmc&&cutNonPrompt&&cutCentralityBin));
			tMCP->Draw(Form("DsvpvDistance*sin(Dalpha):Dmass:Dpt>>hPtMD0DcaMCPSignal_%s%s",  iCentStr.c_str(), iPtWeightStr.c_str()),cutpt&&cutPbPbMB&&cutmcSignal&&cutPrompt&&cutCentralityBin);
			tMCP->Draw(Form("DsvpvDistance*sin(Dalpha):Dmass:Dpt>>hPtMD0DcaMCPSwapped_%s%s",  iCentStr.c_str(), iPtWeightStr.c_str() ),cutpt&&cutPbPbMB&&cutmcSwapped&&cutPrompt&&cutCentralityBin);

		} // end     for(int iPtWeight=0 ; iPtWeight<nPtWeight ; iPtWeight++)
	} // end   for(int iCent=0; iCent<nCent; iCent++)

	outf->Write();
}

