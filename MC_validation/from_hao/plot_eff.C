#include "uti.h"
#include "../include/parameters.h"

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

void SetHistStyle(TH1* h,int color = 1, int markerstyle =20, double markersize = 0.9 , int linestyle=1){
  h->SetLineColor(color);
  h->SetMarkerColor(color);
  h->SetMarkerStyle(markerstyle);
	h->SetMarkerSize(markersize);
  h->SetLineStyle(linestyle);
}


void plot_eff(){

	// get files and histograms

	TFile *f_ppMCP_old = TFile::Open("eff_rootFiles/efficiencyPromptPP.root");
	TFile *f_ppMCP_new = TFile::Open("eff_rootFiles/efficiencyPromptPP_new.root");
  TFile *f_ppMCNP_old = TFile::Open("eff_rootFiles/efficiencyNonPromptPP.root");
  TFile *f_ppMCNP_new = TFile::Open("eff_rootFiles/efficiencyNonPromptPP_new.root");
	
	TH1D *hEff_ppMCP_old=(TH1D*)f_ppMCP_old->Get("hEff");
  TH1D *hEffAcc_ppMCP_old=(TH1D*)f_ppMCP_old->Get("hEffAcc");

  TH1D *hEff_ppMCP_new=(TH1D*)f_ppMCP_new->Get("hEff");
  TH1D *hEffAcc_ppMCP_new=(TH1D*)f_ppMCP_new->Get("hEffAcc");

  TH1D *hEff_ppMCNP_old=(TH1D*)f_ppMCNP_old->Get("hEff");
  TH1D *hEffAcc_ppMCNP_old=(TH1D*)f_ppMCNP_old->Get("hEffAcc");

  TH1D *hEff_ppMCNP_new=(TH1D*)f_ppMCNP_new->Get("hEff");
  TH1D *hEffAcc_ppMCNP_new=(TH1D*)f_ppMCNP_new->Get("hEffAcc");

	// calculate ratio
	
	TH1D *hEff_ppMCP_ratio=(TH1D*)hEff_ppMCP_new->Clone("hEff_ppMCP_ratio");
	hEff_ppMCP_ratio->Sumw2();
	hEff_ppMCP_ratio->Divide(hEff_ppMCP_old);

  TH1D *hEffAcc_ppMCP_ratio=(TH1D*)hEffAcc_ppMCP_new->Clone("hEffAcc_ppMCP_ratio");
  hEffAcc_ppMCP_ratio->Sumw2();
  hEffAcc_ppMCP_ratio->Divide(hEffAcc_ppMCP_old);

  TH1D *hEff_ppMCNP_ratio=(TH1D*)hEff_ppMCNP_new->Clone("hEff_ppMCNP_ratio");
  hEff_ppMCNP_ratio->Sumw2();
  hEff_ppMCNP_ratio->Divide(hEff_ppMCNP_old);

  TH1D *hEffAcc_ppMCNP_ratio=(TH1D*)hEffAcc_ppMCNP_new->Clone("hEffAcc_ppMCNP_ratio");
  hEffAcc_ppMCNP_ratio->Sumw2();
  hEffAcc_ppMCNP_ratio->Divide(hEffAcc_ppMCNP_old);


	// plots

  TLine *line1= new TLine(0,1,100,1);
  line1->SetLineStyle(7);

	TCanvas *c_EffAcc = new TCanvas("c_EffAcc","c_EffAcc",1000,1000);
	c_EffAcc->Divide(2,2);

	c_EffAcc->cd(1);
	gPad->SetLogx();
	SetHistStyle(hEffAcc_ppMCP_old,4,20,0.85,1);
  SetHistStyle(hEffAcc_ppMCP_new,2,20,0.85,1);	
	hEffAcc_ppMCP_old->GetXaxis()->SetTitle("p_{T} (GeV/c)");
	hEffAcc_ppMCP_old->GetYaxis()->SetTitle("acceptance");
	hEffAcc_ppMCP_old->Draw();
	hEffAcc_ppMCP_new->Draw("SAME");

  TLegend *le_hEffAcc_ppMCP = new TLegend(0.64,0.28,0.84,0.48,NULL,"brNDC");
  le_hEffAcc_ppMCP->SetBorderSize(0);
  le_hEffAcc_ppMCP->AddEntry((TObject*)0,"pp MC Eff.Acc.","");
  le_hEffAcc_ppMCP->AddEntry(hEffAcc_ppMCP_new,"Prompt new MC");
  le_hEffAcc_ppMCP->AddEntry(hEffAcc_ppMCP_old,"Prompt old MC");
  le_hEffAcc_ppMCP->Draw("same");


  c_EffAcc->cd(2);
  gPad->SetLogx();
  SetHistStyle(hEffAcc_ppMCNP_old,4,20,0.85,1);
  SetHistStyle(hEffAcc_ppMCNP_new,2,20,0.85,1);
  hEffAcc_ppMCNP_old->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  hEffAcc_ppMCNP_old->GetYaxis()->SetTitle("acceptance");
  hEffAcc_ppMCNP_old->Draw();
  hEffAcc_ppMCNP_new->Draw("SAME");

  TLegend *le_hEffAcc_ppMCNP = new TLegend(0.64,0.28,0.84,0.48,NULL,"brNDC");
  le_hEffAcc_ppMCNP->SetBorderSize(0);
  le_hEffAcc_ppMCNP->AddEntry((TObject*)0,"pp MC Eff.Acc.","");
  le_hEffAcc_ppMCNP->AddEntry(hEffAcc_ppMCNP_new,"NonPrompt new MC");
  le_hEffAcc_ppMCNP->AddEntry(hEffAcc_ppMCNP_old,"NonPrompt old MC");
  le_hEffAcc_ppMCNP->Draw("same");


	c_EffAcc->cd(3);
  gPad->SetLogx();
  hEffAcc_ppMCP_ratio->GetYaxis()->SetTitle("Acc. Ratio");
  hEffAcc_ppMCP_ratio->GetXaxis()->SetTitle("p_{T} (GeV/c)");
	SetHistStyle(hEffAcc_ppMCP_ratio,4,20,0.8,1);
  hEffAcc_ppMCP_ratio->Draw();
  line1->Draw("SAME");
  TLatex* tex_EffAcc_ppMCP = new TLatex(0.4,0.9,"pp Prompt D Acc ratio new/old");
  tex_EffAcc_ppMCP->SetNDC();
  tex_EffAcc_ppMCP->SetTextSize(0.035);
  tex_EffAcc_ppMCP->Draw();


  c_EffAcc->cd(4);
  gPad->SetLogx();
  hEffAcc_ppMCNP_ratio->GetYaxis()->SetTitle("Acc. Ratio");
  hEffAcc_ppMCNP_ratio->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  SetHistStyle(hEffAcc_ppMCNP_ratio,4,20,0.8,1);
  hEffAcc_ppMCNP_ratio->Draw();
  line1->Draw("SAME");
  TLatex* tex_EffAcc_ppMCNP = new TLatex(0.4,0.9,"pp NonPrompt D Acc ratio new/old");
  tex_EffAcc_ppMCNP->SetNDC();
  tex_EffAcc_ppMCNP->SetTextSize(0.035);
  tex_EffAcc_ppMCNP->Draw();


	c_EffAcc->SaveAs("plots/EffAcc.png");
  c_EffAcc->SaveAs("plots/EffAcc.pdf");



	TCanvas *c_Eff = new TCanvas("c_Eff","c_Eff",1000,1000);
	c_Eff->Divide(2,2);

	c_Eff->cd(1);
	gPad->SetLogx();
	SetHistStyle(hEff_ppMCP_old,4,20,0.85,1);
  SetHistStyle(hEff_ppMCP_new,2,20,0.85,1);	
  hEff_ppMCP_old->GetYaxis()->SetTitle("Efficiency");
  hEff_ppMCP_old->GetXaxis()->SetTitle("p_{T} (GeV/c)");
	hEff_ppMCP_old->Draw();
	hEff_ppMCP_new->Draw("SAME");

  TLegend *le_hEff_ppMCP = new TLegend(0.15,0.68,0.44,0.88,NULL,"brNDC");
  le_hEff_ppMCP->SetBorderSize(0);
  le_hEff_ppMCP->AddEntry((TObject*)0,"pp MC Eff.","");
  le_hEff_ppMCP->AddEntry(hEff_ppMCP_new,"Prompt new MC");
  le_hEff_ppMCP->AddEntry(hEff_ppMCP_old,"Prompt old MC");
  le_hEff_ppMCP->Draw("same");


  c_Eff->cd(2);
  gPad->SetLogx();
  SetHistStyle(hEff_ppMCNP_old,4,20,0.85,1);
  SetHistStyle(hEff_ppMCNP_new,2,20,0.85,1);
  hEff_ppMCNP_old->GetYaxis()->SetTitle("Efficiency");
  hEff_ppMCNP_old->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  hEff_ppMCNP_old->Draw();
  hEff_ppMCNP_new->Draw("SAME");

  TLegend *le_hEff_ppMCNP = new TLegend(0.15,0.68,0.44,0.88,NULL,"brNDC");
  le_hEff_ppMCNP->SetBorderSize(0);
  le_hEff_ppMCNP->AddEntry((TObject*)0,"pp MC Eff.","");
  le_hEff_ppMCNP->AddEntry(hEff_ppMCNP_new,"NonPrompt new MC");
  le_hEff_ppMCNP->AddEntry(hEff_ppMCNP_old,"NonPrompt old MC");
  le_hEff_ppMCNP->Draw("same");


	c_Eff->cd(3);
  gPad->SetLogx();
  hEff_ppMCP_ratio->GetYaxis()->SetTitle("Eff. Ratio");
  hEff_ppMCP_ratio->GetXaxis()->SetTitle("p_{T} (GeV/c)");
	SetHistStyle(hEff_ppMCP_ratio,4,20,0.8,1);
  hEff_ppMCP_ratio->Draw();
  line1->Draw("SAME");
  TLatex* tex_Eff_ppMCP = new TLatex(0.4,0.3,"pp Prompt D eff ratio new/old");
  tex_Eff_ppMCP->SetNDC();
  tex_Eff_ppMCP->SetTextSize(0.035);
  tex_Eff_ppMCP->Draw();


  c_Eff->cd(4);
  gPad->SetLogx();
  hEff_ppMCNP_ratio->GetYaxis()->SetTitle("Eff. Ratio");
  hEff_ppMCNP_ratio->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  SetHistStyle(hEff_ppMCNP_ratio,4,20,0.8,1);
  hEff_ppMCNP_ratio->Draw();
  line1->Draw("SAME");
  TLatex* tex_Eff_ppMCNP = new TLatex(0.4,0.3,"pp NonPrompt D eff ratio new/old");
  tex_Eff_ppMCNP->SetNDC();
  tex_Eff_ppMCNP->SetTextSize(0.035);
  tex_Eff_ppMCNP->Draw();


	c_Eff->SaveAs("plots/Eff.png");
	c_Eff->SaveAs("plots/Eff.pdf");



  TH1D *hPtDis2to4_ppMCP_old=(TH1D*)f_ppMCP_old->Get("hPtDis2to4");
  TH1D *hDcaDis2to4_ppMCP_old=(TH1D*)f_ppMCP_old->Get("hDcaDis2to4");

  TH1D *hPtDis2to4_ppMCNP_old=(TH1D*)f_ppMCNP_old->Get("hPtDis2to4");
  TH1D *hDcaDis2to4_ppMCNP_old=(TH1D*)f_ppMCNP_old->Get("hDcaDis2to4");

  TH1D *hPtDis2to4_ppMCP_new=(TH1D*)f_ppMCP_new->Get("hPtDis2to4");
  TH1D *hDcaDis2to4_ppMCP_new=(TH1D*)f_ppMCP_new->Get("hDcaDis2to4");

  TH1D *hPtDis2to4_ppMCNP_new=(TH1D*)f_ppMCNP_new->Get("hPtDis2to4");
  TH1D *hDcaDis2to4_ppMCNP_new=(TH1D*)f_ppMCNP_new->Get("hDcaDis2to4");

  // calculate ratio

  TH1D *hPtDis2to4_ppMCP_ratio=(TH1D*)hPtDis2to4_ppMCP_new->Clone("hPtDis2to4_ppMCP_ratio");
  hPtDis2to4_ppMCP_ratio->Sumw2();
  hPtDis2to4_ppMCP_ratio->Divide(hPtDis2to4_ppMCP_old);

  TH1D *hDcaDis2to4_ppMCP_ratio=(TH1D*)hDcaDis2to4_ppMCP_new->Clone("hDcaDis2to4_ppMCP_ratio");
  hDcaDis2to4_ppMCP_ratio->Sumw2();
  hDcaDis2to4_ppMCP_ratio->Divide(hDcaDis2to4_ppMCP_old);

  TH1D *hPtDis2to4_ppMCNP_ratio=(TH1D*)hPtDis2to4_ppMCNP_new->Clone("hPtDis2to4_ppMCNP_ratio");
  hPtDis2to4_ppMCNP_ratio->Sumw2();
  hPtDis2to4_ppMCNP_ratio->Divide(hPtDis2to4_ppMCNP_old);

  TH1D *hDcaDis2to4_ppMCNP_ratio=(TH1D*)hDcaDis2to4_ppMCNP_new->Clone("hDcaDis2to4_ppMCNP_ratio");
  hDcaDis2to4_ppMCNP_ratio->Sumw2();
  hDcaDis2to4_ppMCNP_ratio->Divide(hDcaDis2to4_ppMCNP_old);

	// plot



	TCanvas *c_PtDis2to4 = new TCanvas("c_PtDis2to4","c_PtDis2to4",1000,1000);
	c_PtDis2to4->Divide(2,2);

	c_PtDis2to4->cd(1);
	gPad->SetLogx();
	SetHistStyle(hPtDis2to4_ppMCP_old,4,20,0.85,1);
  SetHistStyle(hPtDis2to4_ppMCP_new,2,20,0.85,1);	
  hPtDis2to4_ppMCP_old->GetYaxis()->SetTitle("PtDis2to4iciency");
  hPtDis2to4_ppMCP_old->GetXaxis()->SetTitle("p_{T} (GeV/c)");
	hPtDis2to4_ppMCP_old->Draw();
	hPtDis2to4_ppMCP_new->Draw("SAME");

  TLegend *le_hPtDis2to4_ppMCP = new TLegend(0.15,0.68,0.44,0.88,NULL,"brNDC");
  le_hPtDis2to4_ppMCP->SetBorderSize(0);
  le_hPtDis2to4_ppMCP->AddEntry((TObject*)0,"pp MC PtDis2to4.","");
  le_hPtDis2to4_ppMCP->AddEntry(hPtDis2to4_ppMCP_new,"Prompt new MC");
  le_hPtDis2to4_ppMCP->AddEntry(hPtDis2to4_ppMCP_old,"Prompt old MC");
  le_hPtDis2to4_ppMCP->Draw("same");


  c_PtDis2to4->cd(2);
  gPad->SetLogx();
  SetHistStyle(hPtDis2to4_ppMCNP_old,4,20,0.85,1);
  SetHistStyle(hPtDis2to4_ppMCNP_new,2,20,0.85,1);
  hPtDis2to4_ppMCNP_old->GetYaxis()->SetTitle("PtDis2to4iciency");
  hPtDis2to4_ppMCNP_old->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  hPtDis2to4_ppMCNP_old->Draw();
  hPtDis2to4_ppMCNP_new->Draw("SAME");

  TLegend *le_hPtDis2to4_ppMCNP = new TLegend(0.15,0.68,0.44,0.88,NULL,"brNDC");
  le_hPtDis2to4_ppMCNP->SetBorderSize(0);
  le_hPtDis2to4_ppMCNP->AddEntry((TObject*)0,"pp MC PtDis2to4.","");
  le_hPtDis2to4_ppMCNP->AddEntry(hPtDis2to4_ppMCNP_new,"NonPrompt new MC");
  le_hPtDis2to4_ppMCNP->AddEntry(hPtDis2to4_ppMCNP_old,"NonPrompt old MC");
  le_hPtDis2to4_ppMCNP->Draw("same");


	c_PtDis2to4->cd(3);
  gPad->SetLogx();
  hPtDis2to4_ppMCP_ratio->GetYaxis()->SetTitle("PtDis2to4. Ratio");
  hPtDis2to4_ppMCP_ratio->GetXaxis()->SetTitle("p_{T} (GeV/c)");
	SetHistStyle(hPtDis2to4_ppMCP_ratio,4,20,0.8,1);
  hPtDis2to4_ppMCP_ratio->Draw();
  line1->Draw("SAME");
  TLatex* tex_PtDis2to4_ppMCP = new TLatex(0.4,0.3,"pp Prompt D eff ratio new/old");
  tex_PtDis2to4_ppMCP->SetNDC();
  tex_PtDis2to4_ppMCP->SetTextSize(0.035);
  tex_PtDis2to4_ppMCP->Draw();


  c_PtDis2to4->cd(4);
  gPad->SetLogx();
  hPtDis2to4_ppMCNP_ratio->GetYaxis()->SetTitle("PtDis2to4. Ratio");
  hPtDis2to4_ppMCNP_ratio->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  SetHistStyle(hPtDis2to4_ppMCNP_ratio,4,20,0.8,1);
  hPtDis2to4_ppMCNP_ratio->Draw();
  line1->Draw("SAME");
  TLatex* tex_PtDis2to4_ppMCNP = new TLatex(0.4,0.3,"pp NonPrompt D eff ratio new/old");
  tex_PtDis2to4_ppMCNP->SetNDC();
  tex_PtDis2to4_ppMCNP->SetTextSize(0.035);
  tex_PtDis2to4_ppMCNP->Draw();


	c_PtDis2to4->SaveAs("plots/PtDis2to4.png");
	c_PtDis2to4->SaveAs("plots/PtDis2to4.pdf");



	TCanvas *c_DcaDis2to4 = new TCanvas("c_DcaDis2to4","c_DcaDis2to4",1000,1000);
	c_DcaDis2to4->Divide(2,2);

	c_DcaDis2to4->cd(1);
	gPad->SetLogx();
	gPad->SetLogy();
	SetHistStyle(hDcaDis2to4_ppMCP_old,4,20,0.85,1);
  SetHistStyle(hDcaDis2to4_ppMCP_new,2,20,0.85,1);	
  hDcaDis2to4_ppMCP_old->GetYaxis()->SetTitle("DcaDis2to4iciency");
  hDcaDis2to4_ppMCP_old->GetXaxis()->SetTitle("p_{T} (GeV/c)");
	hDcaDis2to4_ppMCP_old->Draw();
	hDcaDis2to4_ppMCP_new->Draw("SAME");

  TLegend *le_hDcaDis2to4_ppMCP = new TLegend(0.15,0.68,0.44,0.88,NULL,"brNDC");
  le_hDcaDis2to4_ppMCP->SetBorderSize(0);
  le_hDcaDis2to4_ppMCP->AddEntry((TObject*)0,"pp MC DcaDis2to4.","");
  le_hDcaDis2to4_ppMCP->AddEntry(hDcaDis2to4_ppMCP_new,"Prompt new MC");
  le_hDcaDis2to4_ppMCP->AddEntry(hDcaDis2to4_ppMCP_old,"Prompt old MC");
  le_hDcaDis2to4_ppMCP->Draw("same");


  c_DcaDis2to4->cd(2);
  gPad->SetLogx();
	gPad->SetLogy();
  SetHistStyle(hDcaDis2to4_ppMCNP_old,4,20,0.85,1);
  SetHistStyle(hDcaDis2to4_ppMCNP_new,2,20,0.85,1);
  hDcaDis2to4_ppMCNP_old->GetYaxis()->SetTitle("DcaDis2to4iciency");
  hDcaDis2to4_ppMCNP_old->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  hDcaDis2to4_ppMCNP_old->Draw();
  hDcaDis2to4_ppMCNP_new->Draw("SAME");

  TLegend *le_hDcaDis2to4_ppMCNP = new TLegend(0.15,0.68,0.44,0.88,NULL,"brNDC");
  le_hDcaDis2to4_ppMCNP->SetBorderSize(0);
  le_hDcaDis2to4_ppMCNP->AddEntry((TObject*)0,"pp MC DcaDis2to4.","");
  le_hDcaDis2to4_ppMCNP->AddEntry(hDcaDis2to4_ppMCNP_new,"NonPrompt new MC");
  le_hDcaDis2to4_ppMCNP->AddEntry(hDcaDis2to4_ppMCNP_old,"NonPrompt old MC");
  le_hDcaDis2to4_ppMCNP->Draw("same");


	c_DcaDis2to4->cd(3);
  gPad->SetLogx();
  hDcaDis2to4_ppMCP_ratio->GetYaxis()->SetTitle("DcaDis2to4. Ratio");
  hDcaDis2to4_ppMCP_ratio->GetXaxis()->SetTitle("p_{T} (GeV/c)");
	SetHistStyle(hDcaDis2to4_ppMCP_ratio,4,20,0.8,1);
  hDcaDis2to4_ppMCP_ratio->Draw();
  line1->Draw("SAME");
  TLatex* tex_DcaDis2to4_ppMCP = new TLatex(0.4,0.3,"pp Prompt D eff ratio new/old");
  tex_DcaDis2to4_ppMCP->SetNDC();
  tex_DcaDis2to4_ppMCP->SetTextSize(0.035);
  tex_DcaDis2to4_ppMCP->Draw();


  c_DcaDis2to4->cd(4);
  gPad->SetLogx();
  hDcaDis2to4_ppMCNP_ratio->GetYaxis()->SetTitle("DcaDis2to4. Ratio");
  hDcaDis2to4_ppMCNP_ratio->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  SetHistStyle(hDcaDis2to4_ppMCNP_ratio,4,20,0.8,1);
  hDcaDis2to4_ppMCNP_ratio->Draw();
  line1->Draw("SAME");
  TLatex* tex_DcaDis2to4_ppMCNP = new TLatex(0.4,0.3,"pp NonPrompt D eff ratio new/old");
  tex_DcaDis2to4_ppMCNP->SetNDC();
  tex_DcaDis2to4_ppMCNP->SetTextSize(0.035);
  tex_DcaDis2to4_ppMCNP->Draw();


	c_DcaDis2to4->SaveAs("plots/DcaDis2to4.png");
	c_DcaDis2to4->SaveAs("plots/DcaDis2to4.pdf");




}
