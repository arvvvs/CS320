#include "predictors.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

predictor::predictor(string ifile,string ofile){
  iFile.open(ifile);  
  oFile.open(ofile);
  
}

void predictor::alwaysTaken(){
  string behavior;
  int taken=0;
  int total=0;
  unsigned long long addr;
  while(iFile >> std::hex >> addr >> behavior){
    if(behavior=="T"){
      taken++;
      total++;
    }
    else{
      total++;
    }
}
  //cout<<"total taken "<<taken<<endl;
  //cout<<"Total branches "<<total<<endl; 
  write(taken, total);
}
void predictor::alwaysNotTaken(){
  string behavior;
  int notTaken=0;
  int total=0;
  unsigned long long addr;
  while(iFile >> std::hex >> addr >> behavior){
    if(behavior=="NT"){
      notTaken++;
      total++;
    }
    else{
      total++;
    }
  }
  //cout<<"Total not taken "<<notTaken<<endl;
  //cout<<"Total "<<total<<endl;
  write(notTaken, total);
}
void predictor::run(string ifile){
  alwaysTaken();
  iFile.close();
  iFile.open(ifile);
  alwaysNotTaken();
  iFile.close();
  iFile.open(ifile);
  singleBitableSize8();
  iFile.close();
  iFile.open(ifile);
  singleBitableSize16();
  iFile.close();
  iFile.open(ifile);
  singleBitableSize32();
  iFile.close();
  iFile.open(ifile);
  singleBitableSize128();
  iFile.close();
  iFile.open(ifile);
  singleBitableSize256();
  iFile.close();
  iFile.open(ifile);
  singleBitableSize512();
  iFile.close();
  iFile.open(ifile);
  singleBitableSize1024(); 
  iFile.close();
  stringToOutput(); 
  myLine="";
  iFile.open(ifile);
  bitableSize8();
  iFile.close();
  iFile.open(ifile);
  bitableSize16();
  iFile.close();
  iFile.open(ifile);
  bitableSize32();
  iFile.close();
  iFile.open(ifile);
  bitableSize128();
  iFile.close();
  iFile.open(ifile);
  bitableSize256();
  iFile.close();
  iFile.open(ifile);
  bitableSize512();
  iFile.close();
  iFile.open(ifile);
  bitableSize1024();
  iFile.close();
  stringToOutput();
  myLine="";
  iFile.open(ifile); 
  gshTable2();
  iFile.close();
  iFile.open(ifile);
  gshTable3();
  iFile.close();
  iFile.open(ifile);
  gshTable4();
  iFile.close();
  iFile.open(ifile);
  gshTable5();
  iFile.close();
  iFile.open(ifile);
  gshTable6();
  iFile.close();
  iFile.open(ifile);
  gshTable7();
  iFile.close();
  iFile.open(ifile);
  gshTable8();
  iFile.close();
  iFile.open(ifile);
  gshTable9();
  iFile.close();
  iFile.open(ifile);
  gshTable10();
  iFile.close();
  stringToOutput();
 
}
void predictor::stringToOutput(){
 oFile<<myLine<<endl; 
}
void predictor::write(int x, int y){
  oFile<<x<<","<<y<<"; "<<' '<<endl;  
}
void predictor::writeString(int correct, int total){
 myLine.append(to_string(correct)+","+to_string(total)+"; ");
//  cout<<myLine; 

}
//0==Not taken
//1==Taken
void predictor::singleBitableSize8(){
  int table8[8];
  string behavior;
  int correct=0;
  int total=0;
  unsigned long long addr;
  for(int i=0; i<8; i++){
    table8[i]=0;
  }
  
  while(iFile >> std::hex >> addr >> behavior){
    int type8;
    if(behavior=="T"){
      type8=1;
    } 
    else if(behavior=="NT"){
      type8=0;
    }
    if(table8[addr%8]==type8){
      correct++;
      total++;
    }
    else if(table8[addr%8]!=type8){
      total++;
      table8[addr%8]=type8;
    }

  }
  //cout<<"Total correct 8 "<<correct<<endl;
//  cout<<"Total"<<total<<endl;
  writeString(correct, total);
}
void predictor::singleBitableSize16(){

  int table16[16];

  string behavior;
  int correct=0;
  int total=0;
  unsigned long long addr;
  for(int i=0; i<16; i++){
    table16[i]=0;
  }
  
  while(iFile >> std::hex >> addr >> behavior){
    int type8;
    if(behavior=="T"){
      type8=1;
    } 
    else if(behavior=="NT"){
      type8=0;
    }
    if(table16[addr%16]==type8){
      correct++;
      total++;
    }
    else if(table16[addr%16]!=type8){
      total++;
      table16[addr%16]=type8;
    }

  }
//  cout<<"Total correct 16 "<<correct<<endl;
//  cout<<"Total"<<total<<endl;
  writeString(correct, total);
}
void predictor::singleBitableSize32(){

  int table32[32];
  for(int i=0; i<32; i++){
    table32[i]=0;
  }
  
  string behavior;
  int correct=0;
  int total=0;
  unsigned long long addr;

  while(iFile >> std::hex >> addr >> behavior){
    int type8;
    if(behavior=="T"){
      type8=1;
    } 
    else if(behavior=="NT"){
      type8=0;
    }
    if(table32[addr%32]==type8){
      correct++;
      total++;
    }
    else if(table32[addr%32]!=type8){
      total++;
      table32[addr%32]=type8;
    }

  }
//  cout<<"Total correct 32 "<<correct<<endl;
//  cout<<"Total"<<total<<endl;
  writeString(correct, total);
}
void predictor::singleBitableSize128(){

  int table128[128];
  for(int i=0; i<128; i++){
    table128[i]=0;
  }

  string behavior;
  int correct=0;
  int total=0;
  unsigned long long addr;

  while(iFile >> std::hex >> addr >> behavior){
    int type8;
    if(behavior=="T"){
      type8=1;
    } 
    else if(behavior=="NT"){
      type8=0;
    }
    if(table128[addr%128]==type8){
      correct++;
      total++;
    }
    else if(table128[addr%128]!=type8){
      total++;
      table128[addr%128]=type8;
    }

  }
//  cout<<"Total correct 128 "<<correct<<endl;
 // cout<<"Total"<<total<<endl;

  writeString(correct, total);
}
void predictor::singleBitableSize256(){

  int table512[256];
  for(int i=0; i<256; i++){
    table512[i]=0;
  }

  string behavior;
  int correct=0;
  int total=0;
  unsigned long long addr;

  while(iFile >> std::hex >> addr >> behavior){
    int type8;
    if(behavior=="T"){
      type8=1;
    } 
    else if(behavior=="NT"){
      type8=0;
    }
    if(table512[addr%256]==type8){
      correct++;
      total++;
    }
    else if(table512[addr%256]!=type8){
      total++;
      table512[addr%256]=type8;
    }

  }
  //cout<<"Total correct 256 "<<correct<<endl;
  //cout<<"Total"<<total<<endl;

  writeString(correct, total);

}
void predictor::singleBitableSize512(){

  int table512[512];
  for(int i=0; i<512; i++){
    table512[i]=0;
  }

  string behavior;
  int correct=0;
  int total=0;
  unsigned long long addr;

  while(iFile >> std::hex >> addr >> behavior){
    int type8;
    if(behavior=="T"){
      type8=1;
    } 
    else if(behavior=="NT"){
      type8=0;
    }
    if(table512[addr%512]==type8){
      correct++;
      total++;
    }
    else if(table512[addr%512]!=type8){
      total++;
      table512[addr%512]=type8;
    }

  }
//  cout<<"Total correct 512 "<<correct<<endl;
 // cout<<"Total"<<total<<endl;

  writeString(correct, total);
}
void predictor::singleBitableSize1024(){

  int table16[1024];
  for(int i=0; i<1024; i++){
    table16[i]=0;
  }

  string behavior;
  int correct=0;
  int total=0;
  unsigned long long addr;

  while(iFile >> std::hex >> addr >> behavior){
    int type8;
    if(behavior=="T"){
      type8=1;
    } 
    else if(behavior=="NT"){
      type8=0;
    }
    if(table16[addr%1024]==type8){
      correct++;
      total++;
    }
    else if(table16[addr%1024]!=type8){
      total++;
      table16[addr%1024]=type8;
    }

  }
  //cout<<"Total correct 1024 "<<correct<<endl;
 // cout<<"Total"<<total<<endl;

  writeString(correct, total);
}  
void predictor::bitableSize8(){
  int table8[8];
  for(int i=0; i<8; i++){
    table8[i]=0;
  }

  string behavior;
  int correct=0;
  int total=0;
  unsigned long long addr;

  while(iFile >> std::hex >> addr >> behavior){
    int type8;
    if(behavior=="T"){
      type8=1;
    } 
    else if(behavior=="NT"){
      type8=0;
    }
    if(table8[addr%8]>1 && type8==1){
      correct++;
      total++;
      if(table8[addr%8]<3){
       table8[addr%8]++; 
      }
    }
    else if(table8[addr%8]<2 && type8==0){
      correct++;
      total++;
      if(table8[addr%8]>0){
       table8[addr%8]--;
      } 
    }
    else if(table8[addr%8]>1 && type8==0){
      total++;
      table8[addr%8]--;
    }
    else if(table8[addr%8]<2 && type8==1){
      total++;
      table8[addr%8]++;
    }

  }
//  cout<<"Total bi correct 8 "<<correct<<endl;
//  cout<<"Total"<<total<<endl;
  writeString(correct, total);
}
void predictor::bitableSize16(){

  int table16[16];
  for(int i=0; i<16; i++){
    table16[i]=0;
  }

  string behavior;
  int correct=0;
  int total=0;
  unsigned long long addr;

  while(iFile >> std::hex >> addr >> behavior){
    int type8;
    if(behavior=="T"){
      type8=1;
    } 
    else if(behavior=="NT"){
      type8=0;
    }
    if(table16[addr%16]>=2 && type8==1){
      correct++;
      total++;
      if(table16[addr%16]<3){
       table16[addr%16]++; 
      }
    }
    else if(table16[addr%16]<=1 && type8==0){
      correct++;
      total++;
      if(table16[addr%16]>0){
       table16[addr%16]--;
      } 
    }
    else if(table16[addr%16]>=2 && type8==0){
      total++;
      table16[addr%16]--;
    }
    else if(table16[addr%16]<=1 && type8==1){
      total++;
      table16[addr%16]++;
    }

  }
//  cout<<"Total bi correct 16 "<<correct<<endl;
//  cout<<"Total"<<total<<endl;
  writeString(correct, total);
}
void predictor::bitableSize32(){

  int table32[32];
  for(int i=0; i<32; i++){
    table32[i]=0;
  }

  string behavior;
  int correct=0;
  int total=0;
  unsigned long long addr;

  while(iFile >> std::hex >> addr >> behavior){
    int type8;
    if(behavior=="T"){
      type8=1;
    } 
    else if(behavior=="NT"){
      type8=0;
    }
    if(table32[addr%32]>=2 && type8==1){
      correct++;
      total++;
      if(table32[addr%32]<3){
       table32[addr%32]++; 
      }
    }
    else if(table32[addr%32]<=1 && type8==0){
      correct++;
      total++;
      if(table32[addr%32]>0){
       table32[addr%32]--;
      } 
    }
    else if(table32[addr%32]>=2 && type8==0){
      total++;
      table32[addr%32]--;
    }
    else if(table32[addr%32]<=1 && type8==1){
      total++;
      table32[addr%32]++;
    }

  }
//  cout<<"Total bi correct 32 "<<correct<<endl;
//  cout<<"Total"<<total<<endl;
  
  writeString(correct, total);
}
void predictor::bitableSize128(){

  int table128[128];
  for(int i=0; i<128; i++){
    table128[i]=0;
  }

  string behavior;
  int correct=0;
  int total=0;
  unsigned long long addr;

  while(iFile >> std::hex >> addr >> behavior){
    int type8;
    if(behavior=="T"){
      type8=1;
    } 
    else if(behavior=="NT"){
      type8=0;
    }
    if(table128[addr%128]>=2 && type8==1){
      correct++;
      total++;
      if(table128[addr%128]<3){
       table128[addr%128]++; 
      }
    }
    else if(table128[addr%128]<=1 && type8==0){
      correct++;
      total++;
      if(table128[addr%128]>0){
       table128[addr%128]--;
      } 
    }
    else if(table128[addr%128]>=2 && type8==0){
      total++;
      table128[addr%128]--;
    }
    else if(table128[addr%128]<=1 && type8==1){
      total++;
      table128[addr%128]++;
    }

  }
//  cout<<"Total bi correct 128 "<<correct<<endl;
//  cout<<"Total"<<total<<endl;
  writeString(correct, total);
}
void predictor::bitableSize256(){

  int table256[256];
  for(int i=0; i<256; i++){
    table256[i]=0;
  }

  string behavior;
  int correct=0;
  int total=0;
  unsigned long long addr;

  while(iFile >> std::hex >> addr >> behavior){
    int type8;
    if(behavior=="T"){
      type8=1;
    } 
    else if(behavior=="NT"){
      type8=0;
    }
    if(table256[addr%256]>=2 && type8==1){
      correct++;
      total++;
      if(table256[addr%256]<3){
       table256[addr%256]++; 
      }
    }
    else if(table256[addr%256]<=1 && type8==0){
      correct++;
      total++;
      if(table256[addr%256]>0){
       table256[addr%256]--;
      } 
    }
    else if(table256[addr%256]>=2 && type8==0){
      total++;
      table256[addr%256]--;
    }
    else if(table256[addr%256]<=1 && type8==1){
      total++;
      table256[addr%256]++;
    }

  }
//  cout<<"Total bi correct 256 "<<correct<<endl;
//  cout<<"Total"<<total<<endl;

  writeString(correct, total);
}
void predictor::bitableSize512(){

  int table512[512];
  for(int i=0; i<512; i++){
    table512[i]=0;
  }

  string behavior;
  int correct=0;
  int total=0;
  unsigned long long addr;

  while(iFile >> std::hex >> addr >> behavior){
    int type8;
    if(behavior=="T"){
      type8=1;
    } 
    else if(behavior=="NT"){
      type8=0;
    }
    if(table512[addr%512]>=2 && type8==1){
      correct++;
      total++;
      if(table512[addr%512]<3){
       table512[addr%512]++; 
      }
    }
    else if(table512[addr%512]<=1 && type8==0){
      correct++;
      total++;
      if(table512[addr%512]>0){
       table512[addr%512]--;
      } 
    }
    else if(table512[addr%512]>=2 && type8==0){
      total++;
      table512[addr%512]--;
    }
    else if(table512[addr%512]<=1 && type8==1){
      total++;
      table512[addr%512]++;
    }

  }
//  cout<<"Total bi correct 512 "<<correct<<endl;
//  cout<<"Total"<<total<<endl;

  writeString(correct, total);
}
void predictor::bitableSize1024(){

  int table1024[1024];
  for(int i=0; i<1024; i++){
    table1024[i]=0;
  }

  string behavior;
  int correct=0;
  int total=0;
  unsigned long long addr;

  while(iFile >> std::hex >> addr >> behavior){
    int type8;
    if(behavior=="T"){
      type8=1;
    } 
    else if(behavior=="NT"){
      type8=0;
    }
    if(table1024[addr%1024]>=2 && type8==1){
      correct++;
//      cout<<"0 "<<table1024[addr%1024]<<endl;

      total++;
      if(table1024[addr%1024]<3){
       table1024[addr%1024]++; 
      }
    }
    else if(table1024[addr%1024]<=1 && type8==0){
      correct++;
      total++;
//     cout<<type8<<endl; 
//      cout<<" 1 "<<table1024[addr%1024]<<endl;
      if(table1024[addr%1024]>0){
       table1024[addr%1024]--;
        
 //     cout<<"2 "<<table1024[addr%1024]<<endl;
      } 
    }
    else if(table1024[addr%1024]>=2 && type8==0){
      total++;
      table1024[addr%1024]--;
    }
    else if(table1024[addr%1024]<=1 && type8==1){
      total++;
      table1024[addr%1024]++; 
    }

  }
  //cout<<"Total bi correct 1024 "<<correct<<endl;
 //cout<<"Total"<<total<<endl;

  writeString(correct, total);
}
void predictor::gshTable2()
    {
  int gHist=3;    
  int mask=3;
  
//  cout<<"initial gHistory "<<gHist<<endl;
 cout<<endl;
 // int index21= gHist &= mask;
//  int index21= gHist<<=1;
//  gHist+=1; 
  
 // cout<<"index 21 is "<<index21<<endl;
  //cout<<"index 31 is "<<gHist<<endl;
  int table1024[1024];
  for(int i=0; i<1024; i++){
    table1024[i]=0;
  }

  string behavior;
  int correct=0;
  int total=0;
  unsigned long long addr;

  while(iFile >> std::hex >> addr >> behavior){
    int type8;
   
    int index2= (gHist) & 3;
    if(behavior=="T"){
      type8=1;
      gHist<<=1;
      gHist+=1;
    } 
    else if(behavior=="NT"){
      type8=0;
      gHist<<=1;
    }
    int index1= addr%1024;
//   cout<<"index  is "<<index1<<endl;
//    cout<<"Ghist is "<<index2<<endl;
 //   cout<<"index 2 is "<<index2<<endl;
    int index=(index1 ^ index2);
//    cout<<"index is "<< index<<endl;
    if(table1024[index]>=2 && type8==1){
      correct++;
      total++;
  //   cout<<"Ghistory pre push of 1 "<<gHist<<endl; 
//      gHist<<=1;
   //   cout<<"Ghistory post push of 1"<<gHist<<endl;
    //  cout<<"Ghistory pre add "<<gHist<<endl;
  //    gHist+=1;
     // cout<<"gHistory after +1 and modulo 10  "<<(gHist%10)<<endl;
      
     // cout<<"Ghistory then and2 "<<((gHist%10)&3)<<endl;
      if(table1024[index]<3){
        table1024[index]++;
      }
    }
    else if(table1024[index]<=1 && type8==0){
      correct++;
      total++;
//      gHist<<=1;
      if(table1024[index]>0){
        table1024[index]--;
      } 
    }
    else if(table1024[index]>=2 && type8==0){
      total++;
      table1024[index]--;
 //     gHist<<=1;
    }
    else if(table1024[index]<= 1 && type8==1){
      total++;
      table1024[index]++;
  //    gHist<<=1;
   //   gHist+=1;
      }
    }
 writeString(correct, total); 
}
void predictor::gshTable3()
    {

  int  gHist=7;    
  int  mask=7;
  int table1024[1024];
  for(int i=0; i<1024; i++){
    table1024[i]=0;
  }


  string behavior;
  int correct=0;
  int total=0;
  unsigned long long addr;

  while(iFile >> std::hex >> addr >> behavior){
    int type8;
    int index2= (gHist) & 7;
    if(behavior=="T"){
      type8=1;
      gHist<<=1;
      gHist+=1;
    } 
    else if(behavior=="NT"){
      type8=0;
      gHist<<=1;
    }
   int index1=addr%1024; 
    int index=(index1 ^ index2);
    if(table1024[index]>=2 && type8==1){
      correct++;
      total++;
      if(table1024[index]<3){
        table1024[index]++;
      }
    }
    else if(table1024[index]<=1 && type8==0){
      correct++;
      total++;
      if(table1024[index]>0){
        table1024[index]--;
      } 
    }
    else if(table1024[index]>=2 && type8==0){
      total++;
      table1024[index]--;
    }
    else if(table1024[index]<= 1 && type8==1){
      total++;
      table1024[index]++;
      }
    }

 writeString(correct, total); 
}
void predictor::gshTable4()
 {
/*
  int gHist=15;    
  int mask=15;
  int table1024[1024];
  for(int i=0; i<1024; i++){
    table1024[i]=0;
  }

  string behavior;
  int correct=0;
  int total=0;
  unsigned long long addr;

  while(iFile >> std::hex >> addr >> behavior){
    int type8;
    int index2= (gHist) & 15;
    if(behavior=="T"){
      type8=1;
      gHist<<=1;
      gHist+=1;
    } 
    else if(behavior=="NT"){
      type8=0;
      gHist<<1;
    }
    int index1=addr%1024;
    int index=(index1 ^ index2);
    if(table1024[index]>1 && type8==1){
      correct++;
      total++;
      if(table1024[index]<3){
        table1024[index]++;
      }
    }
    else if(table1024[index]<2 && type8==0){
      correct++;
      total++;
      if(table1024[index]>0){
        table1024[index]--;
      } 
    }
    else if(table1024[index]>1 && type8==0){
      total++;
      table1024[index]--;
    }
    else if(table1024[index]<2 && type8==1){
      total++;
      table1024[index]++;
      }
  } 
*/

  int  gHist=15;    
  int  mask=15;
  int table1024[1024];
  for(int i=0; i<1024; i++){
    table1024[i]=0;
  }

  string behavior;
  int correct=0;
  int total=0;
  unsigned long long addr;

  while(iFile >> std::hex >> addr >> behavior){
    int type8;
    int index2= (gHist) & 15; 
    if(behavior=="T"){
      type8=1;
      gHist<<=1;
      gHist+=1;
    } 
    else if(behavior=="NT"){
      type8=0;
      gHist<<=1;
    }
    int index1=addr%1024;
    int index=(index1 ^ index2);
    if(table1024[index]>1 && type8==1){
      correct++;
      total++;
      if(table1024[index]<3){
        table1024[index]++;
      }
    }
    else if(table1024[index]<2 && type8==0){
      correct++;
      total++;
      if(table1024[index]>0){
        table1024[index]--;
      } 
    }
    else if(table1024[index]>1 && type8==0){
      total++;
      table1024[index]--;
    }
    else if(table1024[index]<2 && type8==1){
      total++;
      table1024[index]++;
      }
  }
 writeString(correct, total); 
}
void predictor::gshTable5()
  {

  int  gHist=31;    
  int  mask=31;
  int table1024[1024];
  for(int i=0; i<1024; i++){
    table1024[i]=0;
  }

  string behavior;
  int correct=0;
  int total=0;
  unsigned long long addr;

  while(iFile >> std::hex >> addr >> behavior){
    int type8;
    if(behavior=="T"){
      type8=1;
    } 
    else if(behavior=="NT"){
      type8=0;
    }

    int index=((addr%1024)^(gHist&mask));
    if(table1024[index]>=2 && type8==1){
      correct++;
      total++;
      gHist<<=1;
      gHist+=1;
      if(table1024[index]<3){
        table1024[index]++;
      }
    }
    else if(table1024[index]<=1 && type8==0){
      correct++;
      total++;
      gHist<<=1;
      if(table1024[index]>0){
        table1024[index]--;
      } 
    }
    else if(table1024[index]>=2 && type8==0){
      total++;
      table1024[index]--;
      gHist<<=1;
    }
    else if(table1024[index]<= 1 && type8==1){
      total++;
      table1024[index]++;
      gHist<<=1;
      gHist+=1;
        }
  }
  writeString(correct, total);
}
void predictor::gshTable6()
  {

  int  gHist=63;    
  int  mask=63;
  int table1024[1024];
  for(int i=0; i<1024; i++){
    table1024[i]=0;
  }

  string behavior;
  int correct=0;
  int total=0;
  unsigned long long addr;

  while(iFile >> std::hex >> addr >> behavior){
    int type8;
    int index2= (gHist) & 63;
    if(behavior=="T"){
      type8=1;
      gHist<<=1;
      gHist+=1;
    } 
    else if(behavior=="NT"){
      type8=0;
      gHist<<=1;
    }
    int index1=addr%1024;
    int index=(index1 ^ index2);
    if(table1024[index]>1 && type8==1){
      correct++;
      total++;
      if(table1024[index]<3){
        table1024[index]++;
      }
    }
    else if(table1024[index]<2 && type8==0){
      correct++;
      total++;
      if(table1024[index]>0){
        table1024[index]--;
      } 
    }
    else if(table1024[index]>1 && type8==0){
      total++;
      table1024[index]--;
    }
    else if(table1024[index]<2 && type8==1){
      total++;
      table1024[index]++;
      }
  }

  writeString(correct, total);
}
void predictor::gshTable7()
  {
/*
  int  gHist=127;    
  int  mask=127;
  int table1024[1024];
  for(int i=0; i<1024; i++){
    table1024[i]=0;
  }

  string behavior;
  int correct=0;
  int total=0;
  unsigned long long addr;

  while(iFile >> std::hex >> addr >> behavior){
    int type8;
    if(behavior=="T"){
      type8=1;
    } 
    else if(behavior=="NT"){
      type8=0;
    }

    int index=((addr%1024)^(gHist&mask));
    if(table1024[index]>=2 && type8==1){
      correct++;
      total++;
      gHist<<=1;
      if(table1024[index]<3){
        table1024[index]++;
      }
    }
    else if(table1024[index]<=1 && type8==0){
      correct++;
      total++;
      gHist<<=0;
      if(table1024[index]>0){
        table1024[index]--;
      } 
    }
    else if(table1024[index]>=2 && type8==0){
      total++;
      table1024[index]--;
      gHist<<=0;
    }
    else if(table1024[index]<= 1 && type8==1){
      total++;
      table1024[addr%1024]++;
      gHist<<=1;
      }
  }
*/

  int  gHist=127;    
  int  mask=127;
  int table1024[1024];
  for(int i=0; i<1024; i++){
    table1024[i]=0;
  }

  string behavior;
  int correct=0;
  int total=0;
  unsigned long long addr;

  while(iFile >> std::hex >> addr >> behavior){
    int type8;
    int index2= (gHist) & 127;
    if(behavior=="T"){
      type8=1;
      gHist<<=1;
      gHist+=1;
    } 
    else if(behavior=="NT"){
      type8=0;
      gHist<<=1;
    }
    int index1=addr%1024;
    int index=(index1 ^ index2);
    if(table1024[index]>1 && type8==1){
      correct++;
      total++;
      if(table1024[index]<3){
        table1024[index]++;
      }
    }
    else if(table1024[index]<2 && type8==0){
      correct++;
      total++;
      if(table1024[index]>0){
        table1024[index]--;
      } 
    }
    else if(table1024[index]>1 && type8==0){
      total++;
      table1024[index]--;
    }
    else if(table1024[index]<2 && type8==1){
      total++;
      table1024[index]++;
      }
  }
  writeString(correct, total);
}
void predictor::gshTable8()
   {
/*
  int  gHist=255;    
  int  mask=255;
  int table1024[1024];
  for(int i=0; i<1024; i++){
    table1024[i]=0;
  }

  string behavior;
  int correct=0;
  int total=0;
  unsigned long long addr;

  while(iFile >> std::hex >> addr >> behavior){
    int type8;
    if(behavior=="T"){
      type8=1;
    } 
    else if(behavior=="NT"){
      type8=0;
    }
    
    int index=((addr%1024)^(gHist&mask));
    if(table1024[index]>=2 && type8==1){
      correct++;
      total++;
      gHist<<=1;
      if(table1024[index]<3){
        table1024[index]++;
      }
    }
    else if(table1024[index]<=1 && type8==0){
      correct++;
      total++;
      gHist<<=0;
      if(table1024[index]>0){
        table1024[index]--;
      } 
    }
    else if(table1024[index]>=2 && type8==0){
      total++;
      table1024[index]--;
      gHist<<=0;
    }
    else if(table1024[index]<= 1 && type8==1){
      total++;
      table1024[addr%1024]++;
      gHist<<=1;
      }
  }
*/

  int  gHist=255;    
  int  mask=255;
  int table1024[1024];
  for(int i=0; i<1024; i++){
    table1024[i]=0;
  }

  string behavior;
  int correct=0;
  int total=0;
  unsigned long long addr;

  while(iFile >> std::hex >> addr >> behavior){
    int type8;
    int index2= (gHist) & 255;
    if(behavior=="T"){
      type8=1;
      gHist<<=1;
      gHist+=1;
    } 
    else if(behavior=="NT"){
      type8=0;
      gHist<<=1;
    }
    int index1=addr%1024;
    int index=(index1 ^ index2);
    if(table1024[index]>1 && type8==1){
      correct++;
      total++;
      if(table1024[index]<3){
        table1024[index]++;
      }
    }
    else if(table1024[index]<2 && type8==0){
      correct++;
      total++;
      if(table1024[index]>0){
        table1024[index]--;
      } 
    }
    else if(table1024[index]>1 && type8==0){
      total++;
      table1024[index]--;
    }
    else if(table1024[index]<2 && type8==1){
      total++;
      table1024[index]++;
      }
  }
  writeString(correct, total);
}
void predictor::gshTable9()
    {
/*
  int  gHist=511;    
  int  mask=511;
  int table1024[1024];
  for(int i=0; i<1024; i++){
    table1024[i]=0;
  }

  string behavior;
  int correct=0;
  int total=0;
  unsigned long long addr;

  while(iFile >> std::hex >> addr >> behavior){
    int type8;
    if(behavior=="T"){
      type8=1;
    } 
    else if(behavior=="NT"){
      type8=0;
    }
    
    int index=((addr%1024)^(gHist&mask));
    if(table1024[index]>=2 && type8==1){
      correct++;
      total++;
      gHist<<=1;
      if(table1024[index]<3){
        table1024[index]++;
      }
    }
    else if(table1024[index]<=1 && type8==0){
      correct++;
      total++;
      gHist<<=0;
      if(table1024[index]>0){
        table1024[index]--;
      } 
    }
    else if(table1024[index]>=2 && type8==0){
      total++;
      table1024[index]--;
      gHist<<=0;
    }
    else if(table1024[index]<= 1 && type8==1){
      total++;
      table1024[addr%1024]++;
      gHist<<=1;
      }
    }
*/

  int  gHist=511;    
  int  mask=511;
  int table1024[1024];
  for(int i=0; i<1024; i++){
    table1024[i]=0;
  }

  string behavior;
  int correct=0;
  int total=0;
  unsigned long long addr;

  while(iFile >> std::hex >> addr >> behavior){
    int type8;
    int index2= (gHist) & 511;
    if(behavior=="T"){
      type8=1;
      gHist<<=1;
      gHist+=1;
    } 
    else if(behavior=="NT"){
      type8=0;
      gHist<<=1;
    }
    int index1=addr%1024;
    int index=(index1 ^ index2);
    if(table1024[index]>1 && type8==1){
      correct++;
      total++;
      if(table1024[index]<3){
        table1024[index]++;
      }
    }
    else if(table1024[index]<2 && type8==0){
      correct++;
      total++;
      if(table1024[index]>0){
        table1024[index]--;
      } 
    }
    else if(table1024[index]>1 && type8==0){
      total++;
      table1024[index]--;
    }
    else if(table1024[index]<2 && type8==1){
      total++;
      table1024[index]++;
      }
  }
  writeString(correct, total);
}
void predictor::gshTable10()
    {
/*
  int  gHist=1023;    
  int  mask=1023;
  int table1024[1024];
  for(int i=0; i<1024; i++){
    table1024[i]=0;
  }

  string behavior;
  int correct=0;
  int total=0;
  unsigned long long addr;

  while(iFile >> std::hex >> addr >> behavior){
    int type8;
    if(behavior=="T"){
      type8=1;
    } 
    else if(behavior=="NT"){
      type8=0;
    }
    
    int index=((addr%1024)^(gHist&mask));
    if(table1024[index]>=2 && type8==1){
      correct++;
      total++;
      gHist<<=1;
      if(table1024[index]<3){
        table1024[index]++;
      }
    }
    else if(table1024[index]<=1 && type8==0){
      correct++;
      total++;
      gHist<<=0;
      if(table1024[index]>0){
        table1024[index]--;
      } 
    }
    else if(table1024[index]>=2 && type8==0){
      total++;
      table1024[index]--;
      gHist<<=0;
    }
    else if(table1024[index]<= 1 && type8==1){
      total++;
      table1024[addr%1024]++;
      gHist<<=1;
      }
    }
*/

  int  gHist=1023;    
  int  mask=1023;
  int table1024[1024];
  for(int i=0; i<1024; i++){
    table1024[i]=0;
  }

  string behavior;
  int correct=0;
  int total=0;
  unsigned long long addr;

  while(iFile >> std::hex >> addr >> behavior){
    int type8;
    int index2= (gHist) & 1023;
    if(behavior=="T"){
      type8=1;
      gHist<<=1;
      gHist+=1;
    } 
    else if(behavior=="NT"){
      type8=0;
      gHist<<=1;
    }
    int index1=addr%1024;
    int index=(index1 ^ index2);
    if(table1024[index]>1 && type8==1){
      correct++;
      total++;
      if(table1024[index]<3){
        table1024[index]++;
      }
    }
    else if(table1024[index]<2 && type8==0){
      correct++;
      total++;
      if(table1024[index]>0){
        table1024[index]--;
      } 
    }
    else if(table1024[index]>1 && type8==0){
      total++;
      table1024[index]--;
    }
    else if(table1024[index]<2 && type8==1){
      total++;
      table1024[index]++;
      }
  }
  writeString(correct, total);
}
