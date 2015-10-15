//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Oct 15 11:49:10 2015 by ROOT version 5.34/02
// from TChain t_sync/
//////////////////////////////////////////////////////////

#ifndef t_sync_h
#define t_sync_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class t_sync {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Double_t        platform_sys_clock[28];
   Double_t        platform_gps_clock[28];
   Double_t        platform_dev_clock[28];
   Double_t        platform_snr[28];
   Double_t        platform_len[28];
   Double_t        platform_freq[28];
   Double_t        platform_ferr[28];
   Double_t        platform_freq_zc[28];
   Double_t        platform_ferr_zc[28];
   UShort_t        platform_health[28];
   UShort_t        platform_method[28];
   UShort_t        platform_trace[28][10000];
   Int_t           laser_midas_time;
   Float_t         laser_r;
   Float_t         laser_z;
   Float_t         laser_phi;

   // List of branches
   TBranch        *b_platform;   //!
   TBranch        *b_laser;   //!

   t_sync(TTree *tree=0);
   virtual ~t_sync();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef t_sync_cxx
t_sync::t_sync(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {

#ifdef SINGLE_TREE
      // The following code should be used if you want this class to access
      // a single tree instead of a chain
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("Memory Directory");
      if (!f || !f->IsOpen()) {
         f = new TFile("Memory Directory");
      }
      f->GetObject("t_sync",tree);

#else // SINGLE_TREE

      // The following code should be used if you want this class to access a chain
      // of trees.
      TChain * chain = new TChain("t_sync","");
      chain->Add("./run_00585.root/t_sync");
      chain->Add("./run_00586.root/t_sync");
      chain->Add("./run_00604.root/t_sync");
      chain->Add("./run_00605.root/t_sync");
      chain->Add("./run_00606.root/t_sync");
      chain->Add("./run_00607.root/t_sync");
      chain->Add("./run_00622.root/t_sync");
      chain->Add("./run_00630.root/t_sync");
      chain->Add("./run_00631.root/t_sync");
      chain->Add("./run_00632.root/t_sync");
      chain->Add("./run_00647.root/t_sync");
      chain->Add("./run_00648.root/t_sync");
      chain->Add("./run_00649.root/t_sync");
      chain->Add("./run_00650.root/t_sync");
      chain->Add("./run_00651.root/t_sync");
      chain->Add("./run_00660.root/t_sync");
      chain->Add("./run_00661.root/t_sync");
      tree = chain;
#endif // SINGLE_TREE

   }
   Init(tree);
}

t_sync::~t_sync()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t t_sync::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t t_sync::LoadTree(Long64_t entry)
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

void t_sync::Init(TTree *tree)
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

   fChain->SetBranchAddress("platform", platform_sys_clock, &b_platform);
   fChain->SetBranchAddress("laser", &laser_midas_time, &b_laser);
   Notify();
}

Bool_t t_sync::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void t_sync::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}

Int_t t_sync::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef t_sync_cxx
