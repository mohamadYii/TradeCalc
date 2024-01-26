#include <iostream>
#include <fstream>
#include <string>
#include <time.h>  
using namespace std;
//short position
void calc_Sh(float &sl,float &tp,float &hlp, float input) {
    float price = input;
    sl = price+(price *0.02);
    tp = price-(price *0.04);
    hlp = price-(price *0.02);

}
//long position
void calc_Ln(float &sl,float &tp,float &hlp ,float input) {
    float price = input;
    sl = price-(price *0.02);
    tp = price+(price *0.04);
    hlp = price+(price *0.02);


}
void tradeLog(string symbol,float &sl,float &tp,float &hlp, float price,int op){
    ofstream logg("trade log.txt",ios::app);
    if (logg.is_open()){
        time_t my_time = time(NULL); 
        logg << ("%s", ctime(&my_time)); 
        logg << "Symbol: "<<symbol<<endl;
        if (op==0)
        {
            logg << "Operation: Short Position"<<endl;
        }else if (op==1)
        {
            logg << "Operation: Long Position"<<endl;
        }
        logg << "OpenPrice: "<<price<<endl;
        logg << "TakeProfit: "<<tp<<endl;
        logg << "HalfProfit: "<<hlp<<endl;
        logg << "StopLost: "<<sl;
        logg << "\n*****************************\n";
        logg.close();
    }

}
main()
{ 
    cout<< "*****************************\n" << "    Welcome to tradeBot"<< "\n*****************************\n" ;
    while (true)
    {
    string symbol;
    float sl=0,tp=0,hlp=0,price = 0;
    int op=0,r=0;
    cout<<"\nEnter Symbol: ";
    cin >> symbol;
    cout << "\nShort (0) Or Long: (1)\n";
    cin >> op;
    if (op>2)
    {
        cout<<"**Error** Enter 0 or 1!!!! \n app Restart..\n\n";
        continue;
    }
    cout.precision(3);
    cout<<std::fixed;
    if (op==0)//short
    {
        cout<< "Enter Price: "<<endl;
        cin >> price;
        calc_Sh(sl,tp,hlp,price);
        cout << "\n*****************************"<< "\nShortPosition"<<"\n Price: "<<price<<"\n TakeProfit: "<<tp<<"\n HalfProfit: "<<hlp<<"\n StopLost: "<<sl<< "\n*****************************\n";
    }else if (op==1)//long
    {
        cout<< "Enter Price: "<<endl;
        cin >> price;
        calc_Ln(sl,tp,hlp,price);
        cout << "\n*****************************"<< "\nLongPosition"<<"\n Price: "<<price<<"\n TakeProfit: "<<tp<<"\n HalfProfit: "<<hlp<<"\n StopLost: "<<sl<<"\n*****************************\n";
    }
        //log
        cout<<"Log..\n";
        tradeLog(symbol,sl,tp,hlp,price,op);
        cout<<"\nType (0) for Exit and (1) for Refresh the app: "<<endl;
        cin>>r;
        if (r==1)
        {
            cout<<"\nApp reset soon..\n";
            continue;
        }else if(r==0){
            cout<<"Exit...";
            break;
        }else{
            cout<<"**Error** Enter 0 or 1!!!! \n app Restart..\n\n";
            continue;
        }
    }
    return 0;
}
