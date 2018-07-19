//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Jun 14 11:07:25 2018 by ROOT version 6.08/05
// from TTree bdpimunuMcBg/bdpimunuMcBg
// found on file: small2016GHs01-bdpimunuMcBg.root
//////////////////////////////////////////////////////////

#ifndef smallTreesAnalyzer_h
#define smallTreesAnalyzer_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class smallTreesAnalyzer {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           run;
   Int_t           evt;
   Int_t           ls;
   Int_t           ps;
   Double_t        cw8;
   Int_t           chan;
   Bool_t          muid;
   Double_t        bdt;
   Bool_t          cnc;
   Double_t        pt;
   Double_t        eta;
   Double_t        phi;
   Double_t        m;
   Double_t        me;
   Double_t        tau;
   Double_t        taue;
   Double_t        tauxy;
   Double_t        tauxye;
   Double_t        gtau;
   Double_t        m1pt;
   Double_t        m1eta;
   Double_t        m1phi;
   Double_t        m1bdt;
   Double_t        m1rbdt;
   Int_t           m1q;
   Double_t        m2pt;
   Double_t        m2eta;
   Double_t        m2phi;
   Double_t        m2bdt;
   Double_t        m2rbdt;
   Int_t           m2q;

   // List of branches
   TBranch        *b_run;   //!
   TBranch        *b_evt;   //!
   TBranch        *b_ls;   //!
   TBranch        *b_ps;   //!
   TBranch        *b_cw8;   //!
   TBranch        *b_chan;   //!
   TBranch        *b_muid;   //!
   TBranch        *b_bdt;   //!
   TBranch        *b_cnc;   //!
   TBranch        *b_pt;   //!
   TBranch        *b_eta;   //!
   TBranch        *b_phi;   //!
   TBranch        *b_m;   //!
   TBranch        *b_me;   //!
   TBranch        *b_tau;   //!
   TBranch        *b_taue;   //!
   TBranch        *b_tauxy;   //!
   TBranch        *b_tauxye;   //!
   TBranch        *b_gtau;   //!
   TBranch        *b_m1pt;   //!
   TBranch        *b_m1eta;   //!
   TBranch        *b_m1phi;   //!
   TBranch        *b_m1bdt;   //!
   TBranch        *b_m1rbdt;   //!
   TBranch        *b_m1q;   //!
   TBranch        *b_m2pt;   //!
   TBranch        *b_m2eta;   //!
   TBranch        *b_m2phi;   //!
   TBranch        *b_m2bdt;   //!
   TBranch        *b_m2rbdt;   //!
   TBranch        *b_m2q;   //!

   smallTreesAnalyzer(TTree *tree=0);
   virtual ~smallTreesAnalyzer();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop( TString outTxtName);
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef smallTreesAnalyzer_cxx
smallTreesAnalyzer::smallTreesAnalyzer(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("small2016GHs01-bdkpiMcBg.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("small2016GHs01-bdkpiMcBg.root");
      }
      f->GetObject("bdkpiMcBg",tree);

   }
   Init(tree);
}

smallTreesAnalyzer::~smallTreesAnalyzer()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t smallTreesAnalyzer::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t smallTreesAnalyzer::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void smallTreesAnalyzer::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("run", &run, &b_run);
   fChain->SetBranchAddress("evt", &evt, &b_evt);
   fChain->SetBranchAddress("ls", &ls, &b_ls);
   fChain->SetBranchAddress("ps", &ps, &b_ps);
   fChain->SetBranchAddress("cw8", &cw8, &b_cw8);
   fChain->SetBranchAddress("chan", &chan, &b_chan);
   fChain->SetBranchAddress("muid", &muid, &b_muid);
   fChain->SetBranchAddress("bdt", &bdt, &b_bdt);
   fChain->SetBranchAddress("cnc", &cnc, &b_cnc);
   fChain->SetBranchAddress("pt", &pt, &b_pt);
   fChain->SetBranchAddress("eta", &eta, &b_eta);
   fChain->SetBranchAddress("phi", &phi, &b_phi);
   fChain->SetBranchAddress("m", &m, &b_m);
   fChain->SetBranchAddress("me", &me, &b_me);
   fChain->SetBranchAddress("tau", &tau, &b_tau);
   fChain->SetBranchAddress("taue", &taue, &b_taue);
   fChain->SetBranchAddress("tauxy", &tauxy, &b_tauxy);
   fChain->SetBranchAddress("tauxye", &tauxye, &b_tauxye);
   fChain->SetBranchAddress("gtau", &gtau, &b_gtau);
   fChain->SetBranchAddress("m1pt", &m1pt, &b_m1pt);
   fChain->SetBranchAddress("m1eta", &m1eta, &b_m1eta);
   fChain->SetBranchAddress("m1phi", &m1phi, &b_m1phi);
   fChain->SetBranchAddress("m1bdt", &m1bdt, &b_m1bdt);
   fChain->SetBranchAddress("m1rbdt", &m1rbdt, &b_m1rbdt);
   fChain->SetBranchAddress("m1q", &m1q, &b_m1q);
   fChain->SetBranchAddress("m2pt", &m2pt, &b_m2pt);
   fChain->SetBranchAddress("m2eta", &m2eta, &b_m2eta);
   fChain->SetBranchAddress("m2phi", &m2phi, &b_m2phi);
   fChain->SetBranchAddress("m2bdt", &m2bdt, &b_m2bdt);
   fChain->SetBranchAddress("m2rbdt", &m2rbdt, &b_m2rbdt);
   fChain->SetBranchAddress("m2q", &m2q, &b_m2q);
   Notify();
}

Bool_t smallTreesAnalyzer::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void smallTreesAnalyzer::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t smallTreesAnalyzer::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef smallTreesAnalyzer_cxx
