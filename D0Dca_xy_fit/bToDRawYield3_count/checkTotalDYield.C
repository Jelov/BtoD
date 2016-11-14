void checkTotalDYield()
{
  TFile* f1 = new TFile("bFeedDownResult.root");
  TH1D* hTotalDYieldInvMassFit = f1->Get("hTotalDYieldInvMassFit");
  TFile* fGMMB = new TFile("hPtSpectrumDzeroPbPbMB_GM_approve.root");
  TFile* fGM = new TFile("hPtSpectrumDzeroPbPb_GM_approve.root");
  TH1D* hPtGMMB = fGMMB->Get("hPt");
  TH1D* hPtGM = fGM->Get("hPt");
  for(int i=1; i<=hPtGMMB->GetXaxis()->GetNbins(); i++)
    cout<<hTotalDYieldInvMassFit->GetBinContent(i)<<"   "<<hPtGMMB->GetBinContent(i)<<"     diff: "<<(hTotalDYieldInvMassFit->GetBinContent(i)/hPtGMMB->GetBinContent(i)-1)*100<<"%"<<endl;
  for(int i=1; i<=hPtGM->GetXaxis()->GetNbins(); i++)
    cout<<hTotalDYieldInvMassFit->GetBinContent(i+hPtGMMB->GetXaxis()->GetNbins())<<"   "<<hPtGM->GetBinContent(i)<<"     diff: "<<(hTotalDYieldInvMassFit->GetBinContent(i+hPtGMMB->GetXaxis()->GetNbins())/hPtGM->GetBinContent(i)-1)*100<<"%"<<endl;

}
