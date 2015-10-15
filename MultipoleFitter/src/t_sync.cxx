#define t_sync_cxx
#include "t_sync.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

#include "TMath.h"

#include "TF1.h"
#include "TH1F.h"
#include "TFile.h"
#include <iostream>
#include <fstream>
#include "TLegend.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "TLatex.h"
#include "TGraph2D.h"



#include "TF1.h"
#include "TF2.h"
#include "TPostScript.h"
#include "THistPainter.h"
#include "TMath.h"
#include "TMatrixD.h"

#include "THStack.h"
#include "TGraph.h"
#include "TGraph2DErrors.h"
#include "TH2F.h"

/*
#include "TLine.h"
#include "TArrow.h"
#include <time.h>
#include "TPaveStats.h"
*/

#include "fitMultipoles.h"

using namespace::std;

void t_sync::Loop()
{
//   In a ROOT session, you can do:
//      Root > .L t_sync.C
//      Root > t_sync t
//      Root > t.GetEntry(12); // Fill t data members with entry number 12
//      Root > t.Show();       // Show values of entry 12
//      Root > t.Show(16);     // Read and show values of entry 16
//      Root > t.Loop();       // Loop on all entries
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
   if (fChain == 0) return;

   int nProbes = 25;
   float r1 = 2.25;
   float r2 = 4.5;
   double probePosX[nProbes];
   double probePosY[nProbes];
   double value[nProbes];
   double null[nProbes];
   double valErr[nProbes];
   for (int i=0; i<nProbes; i++){
     probePosX[i] = 0.;
     probePosY[i] = 0.;
     null[i] = 0.;
     valErr[i] = 0.;
   }
      
   TGraph *dipoleGr = new TGraph();
   TGraph *normQuadGr = new TGraph();
   TGraph *skewQuadGr = new TGraph();
   TGraph *normSextGr = new TGraph();
   TGraph *skewSextGr = new TGraph();
   TGraph *normOctGr = new TGraph();
   TGraph *skewOctGr = new TGraph();
   TGraph *normDecuGr = new TGraph();
   TGraph *skewDecuGr = new TGraph();
      
   probePosX[0] = 0.;
   probePosY[0] = 0.;

   probePosX[1] = 0.;
   probePosY[1] = -r1;

   probePosX[2] = r1*TMath::Cos(TMath::Pi()/4);
   probePosY[2] = -r1*TMath::Sin(TMath::Pi()/4);

   probePosX[3] = r1;
   probePosY[3] = 0.;

   probePosX[4] = r1*TMath::Cos(TMath::Pi()/4);
   probePosY[4] = r1*TMath::Sin(TMath::Pi()/4);

   probePosX[5] = 0.;
   probePosY[5] = r1;

   probePosX[6] = -r1*TMath::Cos(TMath::Pi()/4);
   probePosY[6] = r1*TMath::Sin(TMath::Pi()/4);

   probePosX[7] = -r1;
   probePosY[7] = 0;

   probePosX[8] = -r1*TMath::Cos(TMath::Pi()/4);
   probePosY[8] = -r1*TMath::Sin(TMath::Pi()/4);

   probePosX[9] = r2*TMath::Cos(12*TMath::Pi()/8);
   probePosY[9] = r2*TMath::Sin(12*TMath::Pi()/8);

   probePosX[10] = r2*TMath::Cos(13*TMath::Pi()/8);
   probePosY[10] = r2*TMath::Sin(13*TMath::Pi()/8);

   probePosX[11] = r2*TMath::Cos(14*TMath::Pi()/8);
   probePosY[11] = r2*TMath::Sin(14*TMath::Pi()/8);

   probePosX[12] = r2*TMath::Cos(15*TMath::Pi()/8);
   probePosY[12] = r2*TMath::Sin(15*TMath::Pi()/8);

   probePosX[13] = r2*TMath::Cos(0*TMath::Pi()/8);
   probePosY[13] = r2*TMath::Cos(0*TMath::Pi()/8);

   probePosX[14] = r2*TMath::Cos(TMath::Pi()/8);
   probePosY[14] = r2*TMath::Sin(TMath::Pi()/8);

   probePosX[15] = r2*TMath::Cos(2*TMath::Pi()/8);
   probePosY[15] = r2*TMath::Sin(2*TMath::Pi()/8);

   probePosX[16] = r2*TMath::Cos(3*TMath::Pi()/8);
   probePosY[16] = r2*TMath::Sin(3*TMath::Pi()/8);

   probePosX[17] = r2*TMath::Cos(4*TMath::Pi()/8);;
   probePosY[17] = r2*TMath::Sin(4*TMath::Pi()/8);;

   probePosX[18] = r2*TMath::Cos(5*TMath::Pi()/8);
   probePosY[18] = r2*TMath::Sin(5*TMath::Pi()/8);

   probePosX[19] = r2*TMath::Cos(6*TMath::Pi()/8);
   probePosY[19] = r2*TMath::Sin(6*TMath::Pi()/8);

   probePosX[20] = r2*TMath::Cos(7*TMath::Pi()/8);
   probePosY[20] = r2*TMath::Sin(7*TMath::Pi()/8);

   probePosX[21] = r2*TMath::Cos(8*TMath::Pi()/8);
   probePosY[21] = r2*TMath::Sin(8*TMath::Pi()/8);

   probePosX[22] = r2*TMath::Cos(9*TMath::Pi()/8);
   probePosY[22] = r2*TMath::Sin(9*TMath::Pi()/8);

   probePosX[23] = r2*TMath::Cos(10*TMath::Pi()/8);
   probePosY[23] = r2*TMath::Sin(10*TMath::Pi()/8);

   probePosX[24] = r2*TMath::Cos(11*TMath::Pi()/8);
   probePosY[24] = r2*TMath::Sin(11*TMath::Pi()/8);


   double mRes[nPars-1];
   for (int i=0; i<nPars-1; i++) mRes[i] = 0.;

   int midas_time = 0;

   bool ppm = 1;

   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   int nChan = 28;
   double phi = 0.;

   TCanvas *c1 = new TCanvas();

   double nmr_freq[nChan];
   for (int i=0; i<nChan; i++) nmr_freq[i] = 0.;



   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;

      midas_time = laser_midas_time; 

      phi = 0.;
      phi = laser_phi;

      //cout<<" midas time is "<<midas_time<<" phi is "<<phi<<endl;

      for (int i=0; i<nChan; i++){
        nmr_freq[i] = 0.;
        nmr_freq[i] = platform_freq[i];
        if (i==0) cout<<" time: "<<midas_time<<endl;
        //cout<<"\t probe "<<i+1<<" freq "<<nmr_freq[i]<<endl;
      }
      
      //convert to ppm
      for (int i=0; i<nProbes; i++) nmr_freq[i] = (nmr_freq[i])/(mixedFreq)*1e6;

      c1 = ppmMap(probePosX,probePosY,nmr_freq,phi,ppm,mRes[0],mRes[1],mRes[2],mRes[3],mRes[4],mRes[5],mRes[6],mRes[7],mRes[8]);

      if (jentry==0) c1->Print("pic_book.ps(");
      else c1->Print("pic_book.ps");

      dipoleGr->SetPoint(dipoleGr->GetN(),phi,mRes[0]);
      normQuadGr->SetPoint(normQuadGr->GetN(),phi,mRes[1]);
      skewQuadGr->SetPoint(skewQuadGr->GetN(),phi,mRes[2]);
      normSextGr->SetPoint(normSextGr->GetN(),phi,mRes[3]);
      skewSextGr->SetPoint(skewSextGr->GetN(),phi,mRes[4]);
      normOctGr->SetPoint(normOctGr->GetN(),phi,mRes[5]);
      skewOctGr->SetPoint(skewOctGr->GetN(),phi,mRes[6]);
      normDecuGr->SetPoint(normDecuGr->GetN(),phi,mRes[7]);
      skewDecuGr->SetPoint(skewDecuGr->GetN(),phi,mRes[8]);

   }

   c1->Print("pic_book.ps)");

   dipoleGr->SetMarkerStyle(20);
   dipoleGr->SetTitle("dipole moment; azimuth via laser tracker (deg); dipole amplitude (ppm)");

   normQuadGr->SetMarkerStyle(20);
   normQuadGr->SetTitle("normal quadrupole; azimuth via laser tracker (deg); normal quadrupole (ppm@4.5cm)");

   skewQuadGr->SetMarkerStyle(20);
   skewQuadGr->SetTitle("skew quadrupole; azimuth via laser tracker (deg); skew quadrupole (ppm@4.5cm)");

   normSextGr->SetMarkerStyle(20);
   normSextGr->SetTitle("normal Sextupole; azimuth via laser tracker (deg); normal sextupole (ppm@4.5cm)");

   skewSextGr->SetMarkerStyle(20);
   skewSextGr->SetTitle("skew Sextupole; azimuth via laser tracker (deg); skew sextupole (ppm@4.5cm)");

   normOctGr->SetMarkerStyle(20);
   normOctGr->SetTitle("normal Octupole; azimuth via laser tracker (deg); normal octupole (ppm@4.5cm)");

   skewOctGr->SetMarkerStyle(20);
   skewOctGr->SetTitle("skew Octupole; azimuth via laser tracker (deg); skew octupole (ppm@4.5cm)");

   normDecuGr->SetMarkerStyle(20);
   normDecuGr->SetTitle("normal Decupole; azimuth via laser tracker (deg); normal decupole (ppm@4.5cm)");

   skewDecuGr->SetMarkerStyle(20);
   skewDecuGr->SetTitle("skew Decupole; azimuth via laser tracker (deg); skew decupole (ppm@4.5cm)");

   TCanvas *c2 = new TCanvas();
   
   dipoleGr->Draw("ap");
   c2->Print("multipoles.ps(");
   normQuadGr->Draw("ap");
   c2->Print("multipoles.ps");
   skewQuadGr->Draw("ap");
   c2->Print("multipoles.ps");
   normSextGr->Draw("ap");
   c2->Print("multipoles.ps");
   skewSextGr->Draw("ap");
   c2->Print("multipoles.ps");
   normOctGr->Draw("ap");
   c2->Print("multipoles.ps");
   skewOctGr->Draw("ap");
   c2->Print("multipoles.ps");
   normDecuGr->Draw("ap");
   c2->Print("multipoles.ps");
   skewDecuGr->Draw("ap");
   c2->Print("multipoles.ps)");

   cout<<"made it out of event loop!"<<endl;

   for (int i=0; i<nProbes; i++){
     value[i] = nmr_freq[i];
   }

   TGraph2DErrors *testGr = new TGraph2DErrors(nProbes,probePosX,probePosY,value,null,null,valErr);//get multipole moments
   testGr->SetMarkerStyle(20);
   
   TF2* fitFcn = new TF2("fitFcn",myRFunc,4.5,4.5,-4.5,4.5,nPars);
   fitFcn->SetParNames("NPars","Dipole","Normal quad","Skew quad","Normal sext","Skew sext","Normal oct","Skew oct","Normal deca","Skew deca");
   fitFcn->FixParameter(0,nPars);
}
