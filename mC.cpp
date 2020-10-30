#include <iostream>
#include <string>
using namespace std;
int main(int argc, char const *argv[]) {
  const int Size=16;
  string element[Size]={"O","S","Se","Te","Sn","Zn","Cd","Cu","Ag","Cr","Mo","W","V","Nb","Ta"};
  double molarmass[Size]={15.999,32.06,78.971,127.6,118.71,65.38,112.41,63.546,107.87,51.996,95.95,183.84,50.942,92.906,180.95};
  int eleindex[8];
  double elenum[8];
  string instr,elestr,numstr;
  double molar;
  int i,j,k;
  bool eleornum;//Ture: element False:number
  for(;;){
    eleornum=true;
    i=0;
    k=0;
    cout<<">>";
    cin>>instr;
    do {
      if(eleornum){
        j=0;
        do {
          j++;
          i++;
        } while(instr[i]<='z'&&instr[i]>='A');
        elestr=instr.substr(i-j,j);
        for(j=0;j<Size;j++){
          if(elestr==element[j]) eleindex[k]=j;
        }
        eleornum=false;
      }
      else{
        j=0;
        do {
          j++;
          i++;
        } while(instr[i]<='9'&&instr[i]>='0'||instr[i]=='.');
        numstr=instr.substr(i-j,j);
        elenum[k]=stod(numstr);
        k++;
        eleornum=true;
      }
    } while(instr[i]!='/');
    instr=instr.substr(i+1);
    molar=stod(instr);
    for(i=0;i<k;i++){
      cout<<element[eleindex[i]]<<'\t'<<molar*elenum[i]*molarmass[eleindex[i]]<<endl;
    }
  }
  return 0;
}
