//#include "./include/parameters.h"
//#include "./include/uti.h"
//#include "./include/setBranches.h"
#include <TFile.h>
#include <TTree.h>

void MakeSkimTree(){

	//  gSystem->Load("$ROOTSYS/test/libEvent");

	//Get old file, old tree and set top branch address
	//   TFile *oldfile = TFile::Open("root://cmsxrootd.fnal.gov///store/user/chengchi/MC_Dntuple/pp/Dntuple_pp_Nonprompt_D0pt10to20.root");

	TFile *oldfile = TFile::Open("Dntuple_pp_prompt_D0pt40to60.root");
	TTree *ntDkpi_old = (TTree*)oldfile->Get("ntDkpi");
	//   Event *event   = new Event();
	//  oldtree->SetBranchAddress("event",&event);
	ntDkpi_old->SetBranchStatus("*",0);
	//   oldtree->SetBranchStatus("event",1);
	//  oldtree->SetBranchStatus("fNtrack",1);
	ntDkpi_old->SetBranchStatus("Dsize",1)
  ntDkpi_old->SetBranchStatus("Dgen",1);
	ntDkpi_old->SetBranchStatus("Dpt",1);

	TTree *ntHlt_old = (TTree*)oldfile->Get("ntHlt");

	TTree *ntSkim_old= (TTree*)oldfile->Get(nt

	//Create a new file + a clone of old tree in new file
	TFile *newfile = new TFile("small.root","recreate");
	TTree *ntD = ntDkpi->CloneTree();

	ntD->Print();
	newfile->Write();
	delete oldfile;
	delete newfile;
}
