#ifndef FIT_MULTIPOLES
#define FIT_MULTIPOLES

int nTrolProbes = 25;
int nPars = 10;
float mixedFreq = 61.74e3;

Double_t myRFunc(Double_t *v, Double_t *par);


TCanvas *ppmMap(Double_t *px,Double_t *py,Double_t *r,Double_t azim,bool ppm,Double_t &a,Double_t &b,Double_t &c,Double_t &d,Double_t &e,Double_t &f,Double_t &g,Double_t &h,Double_t &i);


Double_t myRFunc(Double_t *v, Double_t *par){

  double x = v[0];
  double y = v[1];

  double r = sqrt(x*x+y*y);
  double rf = r/4.5;//4.5 cm aperture 
  double theta = TMath::ATan2(y,x);

  int   nP = par[0];
  double B = par[1];

  for (int i=2; i<nP; i+=2){
    B += TMath::Power(rf,1*(i/2)) * (par[i] * cos((i/2)*theta) + par[i+1] * sin ((i/2)*theta));
  }

  return B;

}

TCanvas *ppmMap(Double_t *px,Double_t *py,Double_t *r,Double_t azim,bool mapppm,Double_t &a,Double_t &b,Double_t &c,Double_t &d,Double_t &e,Double_t &f,Double_t &gg,Double_t &hh,Double_t &i){
 
  double rE[nTrolProbes];
  double null[nTrolProbes];
  double ssUnc = 0.;
 
  for (int k=0; k<nTrolProbes; k++){
 
    null[k] = 0;
 
    rE[k] = 0;
    rE[k] = r[k] * ssUnc;
 
  }
 
  TGraph2D *gOrig = new TGraph2D(nTrolProbes,px,py,r);//get multipole moments
  //TGraph2DErrors *gOrig = new TGraph2DErrors(nTrolProbes,px,py,r,null,null,rE);//get multipole moments
 
  int nPars = 10;
 
  TF2* fitFcn = new TF2("fitFcn",myRFunc,4.5,4.5,-4.5,4.5,nPars);
  fitFcn->SetParNames("NPars","Dipole","Normal quad","Skew quad","Normal sext","Skew sext","Normal oct","Skew oct","Normal deca","Skew deca");
  fitFcn->FixParameter(0,nPars);

  gOrig->Fit("fitFcn");
 
  //QC
  double err = 0.;
  double abserr = 0.;
  double data = 0.;
  double fit = 0.;
  
  for (int i=0; i<nTrolProbes; i++){
    data = r[i];
    //gOrig->GetPoint(i,x,y,data);
    fit = fitFcn->Eval(px[i],py[i]);
    abserr += fabs(fit - data);
    err += fit - data;
    //cout<<"pt "<<i<<" x "<<px[i]<<" y "<<px[i]<<" data "<<data<<" fit "<<fit<<" running err "<<err<<endl;
  }

  double avgB0 = fitFcn->GetParameter(1);
  double avgD  = fitFcn->GetParameter(1);
  double avgNQ = fitFcn->GetParameter(2);
  double avgSQ = fitFcn->GetParameter(3);
  double avgNS = fitFcn->GetParameter(4);
  double avgSS = fitFcn->GetParameter(5);
  double avgNO = fitFcn->GetParameter(6);
  double avgSO = fitFcn->GetParameter(7);
  double avgND = fitFcn->GetParameter(8);
  double avgSD = fitFcn->GetParameter(9);

  a = fitFcn->GetParameter(1);
  b = fitFcn->GetParameter(2);
  c = fitFcn->GetParameter(3);
  d = fitFcn->GetParameter(4);
  e = fitFcn->GetParameter(5);
  f = fitFcn->GetParameter(6);
  gg = fitFcn->GetParameter(7);
  hh = fitFcn->GetParameter(8);
  i = fitFcn->GetParameter(9);

  double avg = 0.;
  double nr[nTrolProbes];

  for (int k=0; k<nTrolProbes; k++) avg += (double) r[k] / nTrolProbes;

  double min = 1e6;
  for (int k=0; k<nTrolProbes; k++){
    nr[k] = 0;
    nr[k] = (r[k]);
    if (nr[k] < min) min = nr[k];
    //nr[k] = (r[k] - avg);
    //cout<<" probe "<<k<<" ppm val "<<nr[k]<<endl;
  }   

  TGraph2D *g = new TGraph2D(nTrolProbes,px,py,nr);

  gStyle->SetNumberContours(30);

  //g->SetMaximum(+2);
  g->SetMinimum(min);

  g->GetHistogram()->GetXaxis()->SetTitle("x (cm)");
  g->GetHistogram()->GetXaxis()->CenterTitle(1);
  g->GetHistogram()->GetYaxis()->SetTitle("y (cm)");
  g->GetHistogram()->GetYaxis()->CenterTitle(1);

  g->SetTitle("");

  TString mT[9];
  mT[0] = Form("%2.2f",avgNQ);
  mT[1] = Form("%2.2f",avgSQ);
  mT[2] = Form("%2.2f",avgNS);
  mT[3] = Form("%2.2f",avgSS);
  mT[4] = Form("%2.2f",avgNO);
  mT[5] = Form("%2.2f",avgSO);
  mT[6] = Form("%2.2f",avgND);
  mT[7] = Form("%2.2f",avgSD);
  mT[8] = Form("%2.1f",avgB0);

  TString azimt = Form("%2.2f",azim);
  TString err1t = "sum err:";
  TString err2t = "abs sum err:";

  TString err1 = Form("%2.1f",err);
  TString err2 = Form("%2.1f",abserr);

  TString pos = "Position (deg):";
  TString dip = "Dipole";
  TString quad = "Quad";
  TString sext = "Sext";
  TString oct  = "Octu";
  TString deca = "Decu";
  TString norm = "Norm";
  TString skew = "Skew";
  TString mult = "B-field (ppm)";

  TLatex *l = new TLatex();
  l->SetNDC();
  l->SetTextSize(0.06);
  
  TLatex *h = new TLatex();
  h->SetNDC();
  h->SetTextSize(0.04);
  /*
  TLine *l1 = new TLine(0.37,0.86,0.73,0.86);
  l1->SetLineWidth(2);

  TLine *l2 = new TLine(0.37,0.86,0.37,0.48);
  l2->SetLineWidth(2);
  */
  TCanvas *ppm = new TCanvas("ppm","",0,0,833,500);
  TPad* p1 = new TPad("p1","",0,0,0.6,1);
  TPad* p2 = new TPad("p2","",0.6,0,1,1);

  ppm->cd();
  p1->Draw();
  p1->cd();
  g->Draw("cont4z");
  l->DrawLatex(0.39,0.93,mult.Data());

  float xStart = 0.4;
  float xStep  = 0.2;

  float yStart = 0.8;
  float yStep  = 0.1;

  ppm->cd();
  p2->Draw();
  p2->cd();
  l->DrawLatex(xStart,yStart,mT[0].Data());
  l->DrawLatex(xStart+xStep,yStart,mT[1].Data());
  l->DrawLatex(xStart,yStart-yStep,mT[2].Data());
  l->DrawLatex(xStart+xStep,yStart-yStep,mT[3].Data());
  l->DrawLatex(xStart,yStart-2*yStep,mT[4].Data());
  l->DrawLatex(xStart+xStep,yStart-2*yStep,mT[5].Data());
  l->DrawLatex(xStart,yStart-3*yStep,mT[6].Data());
  l->DrawLatex(xStart+xStep,yStart-3*yStep,mT[7].Data());
  l->DrawLatex(xStart-0.25,yStart,quad.Data());
  l->DrawLatex(xStart-0.25,yStart-yStep,sext.Data());
  l->DrawLatex(xStart-0.25,yStart-2*yStep,oct.Data());
  l->DrawLatex(xStart-0.25,yStart-3*yStep,deca.Data());
  l->DrawLatex(xStart,yStart+0.75 * yStep,norm.Data());
  l->DrawLatex(xStart+xStep,yStart+0.75 * yStep,skew.Data());
  l->DrawLatex(xStart,yStart-4*yStep,mT[8].Data());
  l->DrawLatex(xStart-0.25,yStart-4*yStep,dip.Data());
  l->DrawLatex(xStart-0.25,yStart-5*yStep,err1t.Data());
  l->DrawLatex(xStart+xStep,yStart-5*yStep,err1.Data());
  l->DrawLatex(xStart-0.25,yStart-6*yStep,err2t.Data());
  l->DrawLatex(xStart+xStep,yStart-6*yStep,err2.Data());
  
  l->DrawLatex(xStart-0.25,yStart-7*yStep,pos.Data());
  l->DrawLatex(xStart+xStep,yStart-7*yStep,azimt.Data());
  /*
  l1->Draw();
  l2->Draw();
  */
  return ppm;

}





#endif
