#include<iostream>
#include<string>
#include <cstring>
using namespace std;
class admin{
    public:
    string a_name,a_pass,ca_pass="pass1";
    string scooter_name[2]={"TVS_Ntorq","Honda_EZ"},scooter_type[2]={"Non-gear","Non-gear"},milage[2]={"40_KmpL","35KmpFC"},ftype[2]={"Petrol","Electric"};
    int cost[2]={1500,1000};
    int n=2,m=0;
    void login(){
        cout<<" Enter Username : ";
        cin>>a_name;
        cout<<" Enter password : ";
        cin>>a_pass;
        if(ca_pass==a_pass){
            cout<<" Hi!  Logged IN \n";
        }
    }
    void entry(){
        cout<<" How many Entries you want to make ? :";
        cin>>m;
        for(int i=n;i<3;i++){
            cout<<" Enter name for scooter " <<i<<":";
            cin>>scooter_name[i];
            cout<<" Enter Type for scooter "<<i<<":";
            cin>>scooter_type[i];
            cout<<" Enter Cost for scooter "<<i<<":";
            cin>>cost[i];
            cout<<" Enter milage for scooter "<<i<<":";
            cin>>milage[i];
        }
    }
int viewscooters(){
        n+=m;
    for(int i=0;i<n;i++){
        cout<<"\n * Scooter NO. "<<i<<":"<<endl;
        cout<<" Scooter Name : "<<scooter_name[i];
        cout<<" | Scooter Type : "<<scooter_type[i];
        cout<<" | Milage : "<<milage[i];
        cout<<" | Cost / day : "<<cost[i]<<endl;
    }
    return 0;
    }
};
class user: public admin{
    public:
    string u_name,u_pass,c_pass;
    string name,cu_name;
    int number;

int registers(){
    cout<<" Enter Name :";
    cin>>name;
    cout<<" Enter Number :";
    cin>>number;
    cout<<" Enter Username :";
    cin>>u_name;
    z:
    cout<<" Enter password :";
    cin>>u_pass;
    cout<<" Re-enter password :";
    cin>>c_pass;
    if(c_pass==u_pass){
        cout<<"\n Hi! "<<name<<" Your Account Has Been Created Successfully !!!\n";
    }
    else{
            cout<<"password did not match !!! Try Again \n";
            goto z;
    }
    return 0;
}
void login(){
    f:
    cout<<" Enter Username : ";
    cin>>cu_name;
    cout<<" Enter Password : ";
    cin>>u_pass;
    if(cu_name==u_name&&c_pass==u_pass){
        cout<<" \n Hi! "<<name<<" You have Successfully  Logged IN \n";
    }
    else{
        cout<<" Invalid credentials :( !!! Try again !!\n";
        goto f;
    }
}
int payment(int cost){
        int mode,upi_pin=1234,card_cvv=111,card_pin=1234,pin,cvv;
        e:
        cout<<"\n********** Payment ********** \n\n";
        cout<<" AMOUNT = Rs. "<<cost<<endl<<endl;
        cout<<" Choose Mode of payment \n 1. Card \n 2. UPI\n Enter Choice : ";
        cin>>mode;
        if(mode==1){
            cout<<" Your Saved Cards : \n Card Number : 4125 XXXX XXXX 1234\n Enter CVV : ";
            cin>>cvv;
            if(card_cvv==cvv){
                k:
                cout<<" Enter PIN : ";
                cin>>pin;
                if(pin==card_pin){
                    cout<<" \n!!You have successfully booked your ride :) !! Safe Ride Ahead !";
                }
                else{
                    cout<<"\n Wrong PIN ENTERED :( !! Try Again \n";
                    goto k;
                }
            }
            else{
                cout<<"\n Wrong CVV ENTERED :( !! Try Again \n";
                    goto e;
            }

        }
        else if(mode==2){
                o:
                cout<<" Enter your UPI PIN : ";
                cin>>pin;
                if(pin==upi_pin){
                    cout<<" You have successfully booked your ride :) !! Safe Ride Ahead !";
                }
                else{
                    cout<<" Wrong PIN ENTERED :( !! Try Again ";
                    goto o;
                }
        }
        else{
            cout<<" Error occured !!! try again ";
            goto e;
        }
        return cost;

}
};

int main(){
    int choice,x;
    user u;
    admin a;
    cout<<"\n\n*************** ONLINE SCOOTER BOOKING FOR SMIT STUDENTS *************";
    do{
        s:
    cout<<"\n\n******** Menu ******** \n";
    cout<<" 1. Admin Login \n";
    cout<<" 2. User Registration \n";
    cout<<" 3. User Login \n";
    cout<<" 4. EXIT \n\n";
    cout<<"* Enter Your Choice : ";
    cin>>choice;
    switch(choice){
        case 1:
            a.login();
            char ch;
            do{
            cout<<" \n************* Operations ********* \n";
            cout<<" a. Add Scooters \n";
            cout<<" b. View Scooters \n";
            cout<<" c. Logout \n";
            cout<<"* Enter Choice : ";
            cin>>ch;
            switch(ch){
                case 'a':
                    a.entry();
                    break;
                case 'b':
                    a.viewscooters();
                    break;
                case 'c':
                    goto s;
                    break;
                default:
                    goto s;
                    break;
            }
            }while(1);
            break;
        case 2:
            u.registers();
            break;
        case 3:
            u.login();
            do{
            cout<<" \n\n********* Operations ********* \n";
            cout<<" 1. View Scooters \n";
            cout<<" 2. Log-Out\n";
            int cho,amount;
            cout<<" Enter Choice : ";
            cin>>cho;
            switch(cho){
                case 1:
                    q:
                    a.viewscooters();
                    cout<<" Enter Scooter Number to book :";
                    cin>>cho;
                    cout<<" !!!! You have selected scooter "<<cho<<". Press 'Y' to complete payment : ";
                    char y;
                    cin>>y;
                    amount=a.cost[cho];
                    switch(y){
                    case 'y':
                        u.payment(amount);
                        break;
                    default :
                        cout<<"\n Happy Browsing :) !!!! \n\n";
                        goto q;
                    }
                    break;
                case 2:
                    cout<<"\n LOGGED OUT \n\n";
                    goto s;
                    break;
                default:
                    goto s;
                    break;
            }
            }while(1);
            break;
            case 4:
                   exit(1);
            default:
                break;
    }
    }while(1);

}
