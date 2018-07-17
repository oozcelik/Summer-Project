#include <TH1.h>
#include <TFile.h>
#include <TRandom.h>
void first() {
 TH1F *histo = new TH1F ("hgaus", "A Gauss Function", 100, -5.0, 5.0);
 TRandom rnd;
 for (int i = 0; i < 10000; ++i) {
 double x = rnd.Gaus (1.5, 1.0);
 histo->Fill (x);
 histo->Draw();
 }
}
