#include <iostream>
#include <cstring>

using namespace std;

enum Os { ios , android , windowsphone };
enum Ram { towgb=2 , fourgb=4, eghitgb=8 , twelvegb=12 , sixteengb=16 , thirtytwogb=32 , sixtyfourgb=64 } ;
enum Storage { s16gb=16 , s32gb=32 , s64gb=64 , s128gb=128 , s256gb=256 , s512gb=512 , s1tb=1024 , s2tb=2048 } ;
enum Color { white , black } ;

struct Phone {

    string phonename;
    string factoryname;
    Os opsystem;
    Ram ram;
    Storage storage;
    Color color;
    double price ;
    int count ;
    int soldout ;

};

void add(Phone *&a ,int &s );
int Search(Phone *&p , int &s ,string pname, string fname );
void add_phone(Phone *&p , int &s, Phone ph );
void add_phone(Phone *&p , int &s ,string pname, string fname , int c );
void Remove_phone(Phone *&p, int &s, int index );
void sort_by_price(Phone *&p,int size);
void Change_mobile_info(Phone *&p,int s, string pname, string fname ,int option);
void most_sold_phones(Phone *p, int size);
void print_phones(Phone *&p, int s);
void print_phone(Phone *&p , int i);




int main()
{
    //int a[10];
    Phone *p;
    int size=0;
    p = new Phone[size];
    bool k=true;
    while(k==true){
        cout<<"1 : add a phone "<<endl;
        cout<<"2 : remove a phone "<<endl;
        cout<<"3 : sort phones by price "<<endl;
        cout<<"4 : search a phone "<<endl;
        cout<<"5 : change mobile info "<<endl;
        cout<<"6 : sell a phone "<<endl;
        cout<<"7 : print phones "<<endl;
        cout<<"8 : print phones sorted by the most sold to the least "<<endl;
        cout<<"9 : quit "<<endl;
        int option;
        cout<<"enter an option :";
        cin>>option;
        if(option==1){
            string pname,fname;
            int os;
            int r;
            int s;
            int c;
            double pr;
            int co;

            Phone ph;
            bool l=true;
            while(l==true){
                cout<<"enter phone name :";
                cin>>pname;
                cout<<"enter factory name :";
                cin>>fname;
                if ( Search(p,size,pname,fname)==-1){
                    ph.phonename=pname;
                    ph.factoryname=fname;
                    l=false;
                }else{
                    cout<<"already available !!"<<endl;
                }
            }

            l=true;
            while(l==true){
                cout<<"enter os number : "<<endl;
                cout<<"1 : ios \n2 : android \n3 : windows phone "<<endl;
                cin>>os;
                if(os==1){
                    ph.opsystem=Os::ios;
                    l=false;
                }
                else if(os==2){
                    ph.opsystem=Os::android;
                    l=false;
                }
                else if(os==3){
                    ph.opsystem=Os::windowsphone;
                    l=false;
                }
                else{
                    cout<<"invalid !!"<<endl;
                }

            }

            l=true;
            while(l==true){
                cout<<"enter ram : ";
                cin >>r;
                if (r==2){
                    ph.ram=Ram::towgb;
                    l=false;
                }
                else if (r==4){
                    ph.ram=Ram::fourgb;
                    l=false;
                }
                else if (r==8){
                    ph.ram=Ram::eghitgb;
                    l=false;
                }
                else if (r==12){
                    ph.ram=Ram::twelvegb;
                    l=false;
                }
                else if (r==16){
                    ph.ram=Ram::sixteengb;
                    l=false;
                }
                else if (r==32){
                    ph.ram=Ram::thirtytwogb;
                    l=false;
                }
                else if (r==64){
                    ph.ram=Ram::sixtyfourgb;
                    l=false;
                }
                else {
                    cout<<"invalid !! "<<endl;
                }
            }


            l=true;
            while(l==true){
                cout<<"enter storage : ";
                cin >>s;
                if (s==16){
                    ph.storage = Storage::s16gb;
                    l=false;
                }
                else if (s==32){
                    ph.storage = Storage::s32gb;
                    l=false;
                }
                else if (s==64){
                    ph.storage = Storage::s64gb;
                    l=false;
                }
                else if (s==128){
                    ph.storage = Storage::s128gb;
                    l=false;
                }
                else if (s==256){
                    ph.storage = Storage::s256gb;
                    l=false;
                }
                else if (s==512){
                    ph.storage = Storage::s512gb;
                    l=false;
                }
                else if (s==1024){
                    ph.storage = Storage::s1tb;
                    l=false;
                }
                else if (s==2048){
                    ph.storage = Storage::s2tb;
                    l=false;
                }
                else{
                    cout<<"invalid!! "<<endl;
                }
            }


            l=true;
            while(l==true){
                cout<<"1 : white \n2 : black "<<endl;
                cin>>c;
                if (c==1){
                    ph.color=Color::white;
                    l=false;
                }
                else if ( c==2 ){
                    ph.color=Color::black;
                    l=false;
                }
                else {
                    cout<<"invalid!! "<<endl;
                }
            }


            l=true;
            while(l==true){
                cout<<"enter price : ";
                cin>>pr;
                if(pr>0){
                    ph.price=pr;
                    l=false;
                }
                else {
                    cout<<"invalid!! "<<endl;
                }
            }


            l=true;
            while(l==true){
                cout<<"enter count : ";
                cin>>co;
                if(co>=1){
                    ph.count=co;
                    l=false;
                }
                else {
                    cout<<"invalid!! "<<endl;
                }
            }                       
            ph.soldout=0;
            add_phone(p,size,ph);
        }


        else if (option==2){
            string pname,fname;

            cout<<"enter phone name :";
            cin>>pname;
            cout<<"enter factory name :";
            cin>>fname;
            int index ;
            index=Search(p,size,pname,fname);
            Remove_phone(p,size,index);

        }

        else if (option==3){
            sort_by_price(p,size);
            print_phones(p,size);
        }

        else if (option==4){

            string pname,fname;
            cout<<"enter phone name : ";
            cin>>pname;
            cout<<"enter factory name : ";
            cin>>fname;

            int index;
            index=Search(p,size,pname,fname);
            if(index!=-1){
                cout<<"invalid !!"<<endl;
            }

        }
        else if (option==5){
            string pname,fname;
            cout<<"enter phone name :";
            cin>>pname;
            cout<<"enter factory name : ";
            cin>>fname;
            cout<<"1 : edit price "<<endl;
            cout<<"2 : edit count "<<endl;
            cout<<"3 : edit soldout "<<endl;
            int option;
            cout<<"enter option :";
            cin>>option;
            Change_mobile_info(p,size,pname,fname,option);

        }
        else if (option==6){
            string pname,fname;
            cout<<"enter phone name : ";
            cin>>pname;
            //getline(cin,pname);
            //cin.ignore();
            cout<<"enter factory name : ";
            cin>>fname;
            //getline(cin,fname);
            //cin.ignore();

            int index;
            index=Search(p,size,pname,fname);
            if(index==-1){
                cout<<"invalidd !!"<<endl;
            }
            else{
                p[index].count--;
                p[index].soldout++;

                if(p[index].count==0){
                    Remove_phone(p,size,index);
                }
            }
            cout<<index<<endl<<pname<<endl<<fname;
        }
        else if (option==7){
            print_phones(p,size);
        }
        else if (option==8){
            most_sold_phones(p,size) ;
        }
        else if (option==9){
             k=false;
        }
        else{
            cout<<"invalid !!"<<endl;
        }
    }
    delete[] p;
    return 0;
}

void add_memory(Phone *&a ,int &s ){
    Phone *temp = new Phone [s+1];
    for(int i=0 ;i<s;i++){
        temp[i]=a[i];

    }
    delete[] a;
    a=temp;
    s++;
}

void add_phone(Phone *&p , int &s, Phone ph ){
    add_memory(p,s);
    p[s-1]  =ph;
}

void add_phone(Phone *&p , int &s ,string pname, string fname , int c ){
    int index=Search(p,s,pname,fname);
    if (index == -1 ){
        cout<<"not found !!";
        return;
    }
    p[index].count+=c;
}

int Search(Phone *&p , int &s ,string pname, string fname ){
    for(int i=0 ;i<s;i++ ){
        if(pname==p[i].phonename && fname==p[i].factoryname )
            return i;
    }
    return -1;
}

void Remove_phone(Phone *&p, int &s, int index ){
    if(index<0||index>=s){
        cout<<"input invalid !!";
        return;
    }
    Phone *temp=new Phone[s-1];

    int j=0;
    for(int i=0;i<s;i++){
        if(i!=index){
            temp[j]=p[i];
            j++;
        }
    }

    delete [] p;
    p=temp;
    s--;
}

void sort_by_price(Phone *&p,int size){    

        int i, j;
        for (i = 0; i < size-1; i++) {

            for (j = 0; j < size-i-1; j++){
                if (p[j].price < p[j+1].price){
                    Phone temp=p[j];
                    p[j]=p[j+1];
                    p[j+1]=temp;
                }
            }
        }
}


void Change_mobile_info(Phone *&p,int s, string pname, string fname ,int option){
    int index;
    index = Search (p,s,pname,fname);
    if(index==-1){
        cout<<"not found !!";
        return;
    }

    if(option==1){
        double newprice;
        cout<<"enter new price : ";
        cin>>newprice;
        if (newprice<=0){
            cout<<"invalid input !!"<<endl;
            return;
        }
        p[index].price=newprice;
    }

    if (option==2){
        int newcount;
        cout<<"enter new count : ";
        cin>>newcount;
        if (newcount<=0){
            cout<<"invalid input !!"<<endl;
            return;
        }
        p[index].count=newcount;
    }

    if (option==3){
        int newsoldout;
        cout<<"enter new soldout : ";
        cin>>newsoldout;
        if (newsoldout<=0){
            cout<<"invalid input !!"<<endl;
            return;
        }
        p[index].soldout=newsoldout;
    }
}

void sell_a_phone (Phone *&p,int s,string pname,string fname){
    int index=Search(p,s,pname,fname);

    if (index==-1){
        cout<<"invalid input !!"<<endl;
        return;
    }

        p[index].count--;
        p[index].soldout++;

        if(p[index].count==0){
            Remove_phone(p,s,index);
        }

}

void print_phones(Phone *&p, int s){
    for(int i=0;i<s;i++){
        cout<<"phone name : "<<p[i].phonename<<endl;
        cout<<"factory name: "<<p[i].factoryname<<endl;
        if( p[i].opsystem==0 ){
            cout<<"os : ios"<<endl;
        }else if( p[i].opsystem==1 ){
            cout<<"os : android"<<endl;
        }else if( p[i].opsystem==2 ){
            cout<<"os : windows phone"<<endl;
        }
        cout<<"ram : "<<p[i].ram<<"gb"<<endl;
        cout<<"storage : "<<p[i].storage<<"gb"<<endl;
        if( p[i].color==0){
            cout<<"color : white"<<endl;
        }
        else if( p[i].color==1){
            cout<<"color : black"<<endl;
        }
        cout<<"count : "<<p[i].count<<endl;
        cout<<"soldout : "<<p[i].soldout<<endl;
        cout<<"--------------------"<<endl;
    }
}

void most_sold_phones(Phone *p, int size){
    Phone *t;
    t=new Phone[size];
    for(int i=0;i<size;i++){
        t[i]=p[i];
    }

    int i, j;
    for (i = 0; i < size-1; i++) {

        for (j = 0; j < size-i-1; j++){
            if (t[j].soldout < t[j+1].soldout){
                Phone temp=t[j];
                t[j]=t[j+1];
                t[j+1]=temp;
            }
        }
    }
    print_phones(t,size);
    delete [] t;
}

void print_phone(Phone *&p , int i){
        cout<<"name : "<<p[i].phonename<<endl;
        cout<<"factory : "<<p[i].factoryname<<endl;
        cout<<"os : "<<p[i].opsystem<<endl;
        cout<<"ram : "<<p[i].ram<<"gb"<<endl;
        cout<<"storage : "<<p[i].storage<<"gb"<<endl;
        cout<<"color : "<<p[i].color<<endl;
        cout<<"count : "<<p[i].count<<endl;
        cout<<"soldout : "<<p[i].soldout<<endl;
}
