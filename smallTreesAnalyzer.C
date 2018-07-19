#define smallTreesAnalyzer_cxx
#include "smallTreesAnalyzer.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include<iostream>
#include <TCanvas.h>
#include "TFile.h"
#include "TLorentzVector.h"
#include <string>
#include <fstream>

void smallTreesAnalyzer::Loop(TString outTxtName)
{
//   In a ROOT session, you can do:
//      root> .L smallTreesAnalyzer.C
//      root> smallTreesAnalyzer t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch

   TString outFileName = "RunII-BdPiMuNu.root";   
   TFile *oFile = new TFile(outFileName, "recreate");
   oFile->cd();
//   gStyle->SetOptStat(kFALSE);
   ofstream myoutfile(outTxtName);

   TH1F *myInvMuMumass00 = new TH1F("run-2", "", 100, 5., 5.6);
   TH1F *myInvMuMumass01 = new TH1F("run-2", "", 100, 5., 5.6);
   TH1F *myInvMuMumass = new TH1F("myInvMuMumass", "", 10, 4.9, 5.9);
   TH1F *Eta = new TH1F("Eta", "Eta", 100, 0., 2.5);

   TF1 * f1 = new TF1("f1","gaus");
//   f1->SetParameters(1,0,1);
 //  auto f1  = new TF1("f1","crystalball",5.,5.6);
 //  f1->SetParameters(1, 0, 1, 2, 0.5);
   gStyle->SetOptFit(10111);
   myInvMuMumass->SetStats(kFALSE);
   myInvMuMumass00->GetXaxis()->SetTitle("M(#mu#mu) [GeV]");
   myInvMuMumass00->GetYaxis()->SetTitle("Entries/6MeV");
   myInvMuMumass00->GetYaxis()->SetTitleOffset(1.5);
   myInvMuMumass00->GetYaxis()->SetLabelSize(0.03);
   myInvMuMumass00->SetTitle("B_{d} invariant mass");
   myInvMuMumass01->SetTitle("B_{d} invariant mass");
   myInvMuMumass01->GetYaxis()->SetTitle("Entries/6MeV");
   myInvMuMumass01->GetYaxis()->SetTitleOffset(1.5);
   myInvMuMumass01->GetXaxis()->SetTitle("M(#mu#mu) [GeV]");
   myInvMuMumass01->GetYaxis()->SetLabelSize(0.03);

   TCanvas *c = new TCanvas;
   c->Divide(2,1);
   
   TString title = "CMS Simulation";   

   TLatex *t = new TLatex();
   t->SetNDC();
//   t->SetTextColor(kBlue);
   t->SetTextSize(0.05);
   t->SetTextFont(42);
  // t->DrawLatex(0.5,0.5, "#frac{S}{S+B} (#pm1.5 #sigma)");
     
     TLatex *t1 = new TLatex();
   t1->SetNDC();
//   t1->SetTextColor(kBlue);
   t1->SetTextSize(0.05);
   t1->SetTextAlign(14);
   t1->SetTextFont(42);
   
  
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;      
     
      if(abs(eta)<1.4 && bdt>0.36)  myInvMuMumass->Fill(m);
//      if((chan==0 || chan==1)  && bdt>0.36) myInvMuMumass->Fill(m);
      Eta->Fill(abs(eta));
 //     myInvMuMumass00->Fill(m);
      if (abs(eta) < 0.7 && bdt>0.32 ) myInvMuMumass00->Fill(m);
      if ((abs(eta) > 0.7 && abs(eta) < 1.4) && bdt>0.36) myInvMuMumass01->Fill(m);
//      if(chan==1 && abs(eta) >1.4) myoutfile << abs(eta) << endl;
//myoutfile << cnc << " "  << bdt << " " << pt << " " << abs(eta) << " " << phi << " " << tau << " " << taue << " " << m << " " << me << " " <<   m1pt << " " << m1eta << " " <<  m2pt << " " << m2eta << m2pt << " " << endl;
      // if (Cut(ientry) < 0) continue;
   }


   double mean = myInvMuMumass00->GetMean();
   double limitup = mean + 2.*myInvMuMumass00->GetRMS();
   double limitdown = mean - 2.*myInvMuMumass00->GetRMS();


   double mean2 = myInvMuMumass01->GetMean();
   double limitup2 = mean2 + 2.*myInvMuMumass01->GetRMS();
   double limitdown2 = mean2 - 2.*myInvMuMumass01->GetRMS();

   gStyle->SetTitleH(0.05);
   c->cd(1);   
 //  myInvMuMumass00->Fit("f1","","",limitdown, limitup);
   myInvMuMumass00->Fit(f1);
//   myInvMuMumass00->Draw();
   t->DrawLatex(0.6,0.5, "|#eta_{f}| < 0.7");
   t->DrawLatex(0.11,0.87,title);
   c->cd(2);
//   Eta->Draw();
  // myInvMuMumass01->Fit("f1","","",limitdown2, limitup2);
   myInvMuMumass01->Fit(f1);
   myInvMuMumass01->Draw();
   t1->DrawLatex(0.6,0.5, " 1.4 >|#eta_{f}| > 0.7");
   t->DrawLatex(0.11,0.87,title);
   TCanvas *c1 = new TCanvas;
   myInvMuMumass->Draw();
//   myInvMuMumass->Fit(f1);
   oFile->Write();
 //  myoutfile.close();
}
