#include <iostream>
#include <fstream>

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

using namespace std;

void Dpt_EdgeResultion(){

  const int nBinY = 20;
  const Double_t binsY[nBinY+1] = {-0.0734,-0.0562,-0.0428,-0.0320,-0.0236,-0.0170,-0.0118,-0.0078,-0.0046,-0.002,0.0,0.002,0.0046,0.0078,0.0118,0.0170,0.0236,0.0320,0.0428,0.0562,0.0734};

  const int nBinM = 60;
  Float_t binsM[nBinM];
  float minMassBin = 1.7;
  float massBinWidth = 0.005;
  for(int i=0; i<=nBinM; i++)
    binsM[i] = minMassBin + massBinWidth*i;

	const int nBinPt = 


	TFile *fMCP = TFile::Open("/afs/cern.ch/work/c/chengchi/work/Project/BtoD/rootfiles/temp/Dntuple_pp_prompt_D0pt4to10.root")
//	TFile *fMCNP = TFile::Open("/afs/cern.ch/work/c/chengchi/work/Project/BtoD/rootfiles/temp/Dntuple_pp_Nonprompt_D0pt4to10.root")

	TTree *ntDkpi=(TTree*)fMCP->Get("ntDkpi");
	
	TCut Dgen = "Dgen==23333";
	TCut Dgenpt6to8 = "Dgenpt>6 && Dgenpt<8";

	TH1D *h_Dmass = new TH1D("h_Dmass","h_Dmass",nBinM,binsM);


	ntDkpi->Draw("Dpt",""




} // end of void  Dpt_EdgeResultion()


