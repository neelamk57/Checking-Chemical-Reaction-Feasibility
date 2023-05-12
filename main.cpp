#include <iostream>
#include<fstream>
#include <iomanip>
#include <ctype.h>
#include <cstring>
#include<stdlib.h>
#include<cmath>

using namespace std;

class enthalpy;
class entropy;
class gibbs;
class enthalpy_entropy;

class reaction
{
protected:
    char react[5][10];
    int rnum;
    char pro[5][10];
    int pronum;
 public:
    friend class enthalpy;
    friend class entropy;
    friend class gibbs;

       void getdata()
    {

        cout<<"Enter Number Of Reactant"<<endl;
        cin>>rnum;
        for(int i=1;i<=rnum;i++)
        {
            cout<<"Enter "<<i<<" Reactant in Balanced form"<<endl;
            cin>>react[i];


        }
        cout<<"Enter Number Of Products"<<endl;
        cin>>pronum;
        for(int i=1;i<=pronum;i++)
        {
            cout<<"Enter "<<i<<" Product in Balanced form"<<endl;
            cin>>pro[i];
        }

    }

    void display()
    {
        fstream outf;
        outf.open("Reaction.txt",ios::app|ios::out);
        cout<<endl<<endl<<"The entered reaction is:"<<endl<<endl;
        for(int i=1;i<=rnum;i++)
        {
                cout<<react[i];
                outf<<react[i];
                if(i==rnum)
                {break;}
                cout<<"  +   ";
                outf<<"  +   ";
        }
        cout<<"   =   ";
        outf<<"   =   ";
        for(int i=1;i<=pronum;i++)
        {
                cout<<pro[i];
                outf<<pro[i];
                if(i==pronum)
                {break;}
            cout<<"  +   ";
            outf<<"  +   ";

        }
        outf.close();
    }

};
class enthalpy:public reaction
{

    friend class entropy;
    friend class gibbs;

  double enthreact[5];
  double enthpro[5];
  double proenth=0;
  double reactenth=0;
  double totalenth=0;
 public:
     void getdata()
     {
                 fstream outf;
        outf.open("Reaction.txt",ios::app|ios::out);
         for(int i=1;i<=rnum;i++)
            {
                cout<<"\n\nEnter enthalpy of  "<<react[i]<<"  :  ";
                cin>>enthreact[i];
                outf<<endl<<react[i]<<"="<<enthreact[i]<<endl;
            }

            for(int i=1;i<=pronum;i++)
            {
                cout<<"\n\nEnter enthalpy of  "<<pro[i]<<"  :  ";
                cin>>enthpro[i];
                outf<<pro[i]<<"="<<enthpro[i]<<endl;
            }
            outf.close();
     }
     void calculate()
     {
        reactenth=0;
        proenth=0;
         for(int i=1;i<=rnum;i++)
         {
             reactenth=reactenth+enthreact[i];

         }
         for(int i=1;i<=pronum;i++)
         {
             proenth=proenth+enthpro[i];

         }
         totalenth=(proenth-reactenth);

     }
     void show()
     {          fstream outf;
        outf.open("Reaction.txt",ios::app|ios::out);
         cout<<"\n\n\nThe Resultant Enthalpy = "<<totalenth;
     outf<<"\n\n\nThe Resultant Enthalpy = "<<totalenth<<endl;
     outf.close();
     }


};

class entropy:public reaction
{

    friend class enthalpy;
    friend class gibbs;

 double entroreact[5];
 double entropro[5];
 double proentro=0,reactentro=0,totalentro=0;
 public:
     void getdata()
     {
                 fstream outf;
        outf.open("Reaction.txt",ios::app|ios::out);
         for(int i=1;i<=rnum;i++)
            {
                cout<<"\n\nEnter entropy of  "<<react[i]<<"  :  ";
                cin>>entroreact[i];
                outf<<endl<<react[i]<<"="<<entroreact[i]<<endl;

            }
            cout<<endl<<endl;
            for(int i=1;i<=pronum;i++)
            {
                cout<<"\n\nEnter entropy of  "<<pro[i]<<"  :  ";
                cin>>entropro[i];

                outf<<pro[i]<<"="<<entropro[i]<<endl;
            }
            outf.close();
     }
     void calculate()
     {

         for(int i=1;i<=rnum;i++)
         {
             reactentro=reactentro+entroreact[i];
         }
         for(int i=1;i<=pronum;i++)
         {
             proentro=proentro+entropro[i];
         }
         totalentro=proentro-reactentro;

     }
     void show()
     {
         fstream outf;
          outf.open("Reaction.txt",ios::app|ios::out);

         cout<<"\n\n\nThe Resultant Entropy = "<<totalentro<<endl;
            outf<<"\n\n\nThe Resultant Entropy = "<<totalentro<<endl;
            outf.close();

     }


};

class gibbs:public reaction
{
        friend class enthalpy;
    friend class entropy;


 double greact[5];
 double gpro[5];
 double prog=0,reactg=0,totalg=0;
 public:
     void getdata()
     {
            fstream outf;
          outf.open("Reaction.txt",ios::app|ios::out);


         for(int i=1;i<=rnum;i++)
            {
                cout<<"\n\nEnter Gibbs Energy of  "<<react[i]<<"  :  ";
                cin>>greact[i];
                outf<<endl<<"Gibb's Energy of "<<react[i]<<" = "<<greact[i]<<endl;
            }
            cout<<endl<<endl;
            for(int i=1;i<=pronum;i++)
            {
                cout<<"\n\nEnter Gibbs Energy of  "<<pro[i]<<"  :  ";
                cin>>gpro[i];
                outf<<"Gibb's Energy of "<<pro[i]<<" = "<<gpro[i]<<endl;
            }
            outf.close();
     }
     void calculate()
     {

         for(int i=1;i<=rnum;i++)
         {
             reactg=reactg+greact[i];
         }
         for(int i=1;i<=pronum;i++)
         {
             prog=prog+gpro[i];
         }
         totalg=prog-reactg;

     }
     void show()
     {
         fstream outf;
          outf.open("Reaction.txt",ios::app|ios::out);

         cout<<"\n\n\nThe Gibbs Energy = "<<totalg;
         outf<<"\n\n\nThe Gibbs Energy = "<<totalg;
         cout<<"\n\nThe given reaction is ";
         outf<<"\n\nThe given reaction is ";
         if(totalg<0)
         {cout<<"FEASIBLE!"<<endl<<endl;
         outf<<"FEASIBLE!"<<endl<<endl;}
         else if(totalg>0)
         {cout<<"NOT FEASIBLE!!"<<endl;
         outf<<"NOT FEASIBLE!!"<<endl;}
         else if(totalg==0)
         {cout<<"Reaction is at EQUILIBRIUM!!"<<endl;
         outf<<"Reaction is at EQUILIBRIUM!!"<<endl;}
         else{cout<<"ERROR!!"<<endl;}
         outf.close();
     }


};
class enthalpy_entropy:public reaction
{
        friend class enthalpy;
    friend class entropy;


 double rH[5];
 double rS[5];
 double rHtotal=0;
 double rStotal=0;
 double pH[5];
 double pS[5];
 double pHtotal=0;
 double pStotal=0;
 double T;
 double G=0;
 public:
     void getdata()
     {
           fstream outf;
        outf.open("Reaction.txt",ios::app|ios::out);
        for(int i=1;i<=rnum;i++)
         {
                cout<<"\n\nEnter Enthalpy Change in "<<react[i]<<" :  ";
                cin>>rH[i];
                outf<<"\n"<<react[i]<<" Enthalpy Change = "<<rH[i]<<endl;
                cout<<"\n\nEnter Entropy Change in "<<react[i]<<"  :  ";
                cin>>rS[i];
                outf<<"\n"<<react[i]<<" Entropy Change = "<<rS[i]<<endl;

         }
          for(int i=1;i<=pronum;i++)
         {
                cout<<"\n\nEnter Enthalpy Change in "<<pro[i]<<" :  ";
                cin>>pH[i];
                outf<<"\n"<<pro[i]<<" Enthalpy Change = "<<pH[i]<<endl;

                cout<<"\n\nEnter Entropy Change in "<<pro[i]<<"  :  ";
                cin>>pS[i];
                outf<<"\n"<<pro[i]<<" Entropy Change = "<<pS[i]<<endl;

         }

                cout<<"\n\n Enter Temperature in Kelvin : ";
                cin>>T;
                outf<<"\n Temperature = "<<T<<endl;

outf.close();
     }
     void calculate()
     {
         for(int i=1;i<=rnum;i++)
         {
             rHtotal+=rH[i];
             rStotal+=rS[i];
         }
         for(int i=1;i<=pronum;i++)
         {
             pHtotal+=pH[i];
             pStotal+=pS[i];
         }
        G=(pHtotal-rHtotal)-(T*(pStotal-rStotal));
     }
     void show()
     {
          fstream outf;
        outf.open("Reaction.txt",ios::app|ios::out);
         cout<<"\n\n\nThe Gibbs Energy = "<<G;
         outf<<"\n\n\nThe Gibbs Energy = "<<G;
         cout<<"\n\n\nThe given reaction is ";
         outf<<"\n\n\nThe given reaction is ";
         if(G<0)
         {cout<<"FEASIBLE!"<<endl<<endl;
         outf<<"FEASIBLE!"<<endl<<endl;}
         else if(G>0)
         {cout<<"NOT FEASIBLE!!"<<endl;
         outf<<"NOT FEASIBLE!!"<<endl;}
         else if(G==0)
         {cout<<"Reaction is at EQUILIBRIUM!!"<<endl;
         outf<<"Reaction is at EQUILIBRIUM!!"<<endl;}
         else{cout<<"ERROR!!"<<endl;}
         outf.close();
     }

} ;



int main()
{
    char choice;
    cout<<"\n\n\n";
    cout<<"*************************************************************************"<<"\n\n"<<endl
    <<setw(15)<<"         REACTION FEASIBILITY CALCULATOR"<<"\n\n\n"
    <<setw(15)<<"         PROJECT REPRESENTED BY : "<<"\n"<<endl
    <<setw(15)<<"         NAMRATA DAS"<<setw(21)<<" (THA075BEI026)"<<endl
    <<setw(15)<<"         NEELAM KARKI"<<setw(21)<<" (THA075BEI027) "<<endl
    <<setw(15)<<"         RAKSHYA PANTA"<<setw(19)<<" (THA075BEI029)"<<endl;
    cout<<"\n\n"<<"*********************************************************************"<<"\n\n"<<endl;


    cout<<"Enter any key to continue and 'Q' to quit."<<endl;
    cin>>choice;
    if(toupper(choice)=='Q')
    {exit(0);}
    home:
    system("cls");
      // ofstream ifile("reaction.txt");
        /* //ifile.open("E:/Feasibility/Reaction.txt");
    if(ifile.is_open())
    {
        ifile<<"File opened Successfully"<<endl;

    }
    else{cout<<"Error"<<endl;}
     //fstream ifile("E:/Feasibility/Reaction.dat",ios::binary|ios::in|iod::out);*/

    cout<<endl<<endl<<"\n\nThis program has been designed to calculate"<<endl<<" the feasibility of any chemical reaction."<<endl<<endl<<endl;

int ch;

    cout<<"\n\n\n\t\t Which data do you prefer?"<<"\n\n\n\t\tEnter 1 :"<<setw(32)<<"To Calculate Enthalpy Change"<<endl<<"\t\tEnter 2 :"<<setw(31)<<" To Calculate Entropy Change"<<
    endl<<"\t\tEnter 3 :"<<setw(37)<<"To Calculate Gibb's Energy Change"<<endl<<"\t\tEnter 4 :"<<setw(32)<<"    To Find Feasibility of Reaction "<<endl;
    cin>>ch;
    enthalpy enobj;
    entropy etobj;
    gibbs gobj;

    switch(ch)
    {
    case 1:
         system("cls");

        enobj.reaction::getdata();
      //  enobj.reaction::diskout();

        enobj.reaction::display();
        //enobj.reaction::diskread();
        enobj.getdata();
        enobj.calculate();
        enobj.show();

        break;


    case 2:
        system("cls");
        etobj.reaction::getdata();
        etobj.reaction::display();
        etobj.getdata();
        etobj.calculate();
        etobj.show();
        break;

    case 3:
        system("cls");
        gobj.reaction::getdata();
        gobj.reaction::display();
        gobj.getdata();
        gobj.calculate();
        gobj.show();
        break;
    case 4:
         system("cls");
        enthalpy_entropy tobj;
        tobj.reaction::getdata();
        tobj.reaction::display();
        tobj.getdata();
        tobj.calculate();
        tobj.show();
        break;

 //   default:cout<<"ERROR!!"<<endl;

        }


        char choose;
        cout<<endl<<"\t\tDo you want to continue?(Y/N)"<<endl;
        cin>>choose;
        if(toupper(choose)=='Y')
        {
            goto home;
        }

    return 0;
}
