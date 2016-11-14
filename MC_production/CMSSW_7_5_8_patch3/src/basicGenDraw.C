#include <iostream>
#include <fstream>
#include "TFile.h"
#include "TH1D.h"
#include "TH2D.h"
#include <string>
#include "TChain.h"

using namespace std;

void basicGenDraw(int startfile=0, int endfile=1, std::string filelist=""){
/*
    std::string filename;
    std::ifstream inss(filelist.c_str(), std::ifstream::in);
    int ifile=0;

    TChain *ch = new TChain("Events");
    while(inss>>filename && ifile<startfile){
        cout << "skipping " << filename << endl;
        ifile++;
    }
    while(inss>>filename && ifile<endfile){

        cout << "opening " << filename << endl;
        ch->Add(filename.c_str());
        ifile++;

    }
*/
		TChain *ch = new TChain("Events");
		ch->Add("step2_RAW2DIGI_L1Reco_RECO.root");

    TH1D *trkPt = new TH1D("trkPt","",50,0,100); trkPt->Sumw2();
    TH1D *trkEta = new TH1D("trkEta","",50,-5,5); trkEta->Sumw2();
    TH1D *impactPar = new TH1D("impactPar","",500,0,500); impactPar->Sumw2();
    TH2D *dEtdEta = new TH2D("dEtdEta","",50,2,5,500,0,1000); dEtdEta->Sumw2();

    ch->SetAlias("HepMC","edmHepMCProduct_generator__SIM.obj");
    ch->SetAlias("genParticles","recoGenParticles_hiGenParticles__SIM.obj");
    //ch->SetAlias("genParticles","recoGenParticles_genParticles__SIM.obj");

    //project "draws" without actually drawing...
//    ch->Project("trkPt","genParticles.pt()","genParticles.status()==1 && genParticles.charge()!=0 && genParticles.pt()>0.0");
//    ch->Project("trkEta","genParticles.eta()","genParticles.status()==1 && genParticles.charge()!=0 && genParticles.pt()>0.0");
    ch->Project("impactPar","HepMC.GetEvent()->heavy_ion()->Ncoll()");
    ch->Project("dEtdEta","genParticles.et():genParticles.eta()","genParticles.status()==1 && genParticles.pt()>0.0 && abs(genParticles.eta())>2 && abs(genParticles.eta())<5");

//    TFile *fout = new TFile(Form("Gen_validationHistos_year14_cent_%d.root",startfile),"recreate");
		TFile *fout = new TFile("fout.root","recreate");
    fout->cd();
    trkPt->Write();
    trkEta->Write();
    impactPar->Write();
    dEtdEta->Write();

}
