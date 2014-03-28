#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class predictor{
  private:
    ifstream iFile;
    ofstream oFile; 
    string myLine;
    string myLine2;
  public:
    predictor(string ifile, string ofile);
    void write(int x, int y);
    void alwaysTaken();
    void alwaysNotTaken();
    void run(string ifile);
    void bitableSize8();
    void bitableSize16();
    void bitableSize32();
    void bitableSize128();
    void bitableSize256();
    void bitableSize512(); 
    void bitableSize1024();
    void singleBitableSize8();
    void singleBitableSize16();
    void singleBitableSize32();
    void singleBitableSize128();
    void singleBitableSize256();
    void singleBitableSize512(); 
    void singleBitableSize1024();
    void writeString(int correct, int total);
    void stringToOutput();
    void gshTable2();
    void gshTable3();
    void gshTable4();
    void gshTable5();
    void gshTable6();
    void gshTable7();
    void gshTable8();
    void gshTable9();
    void gshTable10();
};
