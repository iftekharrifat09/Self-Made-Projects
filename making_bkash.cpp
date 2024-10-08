#include<bits/stdc++.h>
using namespace std;
int mainBalance = 10000;
int trNum = 1;
class transactions{
    public:
    string sector;
    string number;
    float amount;
    string trId;
    transactions(string sector, string number, float amount, string trId){
        this->sector = sector;
        this->number = number;
        this->amount = amount;
        this->trId = trId;
    }
};
class userRegistrations{
    public:
    string name;
    string FatherName;
    string NID;
    string datOfBirth;
    string number;
    string pin;
    userRegistrations(string name, string FatherName, string NID, string number, string pin, string datOfBirth){
        this->name = name;
        this->FatherName = FatherName;
        this->NID = NID;
        this->number = number;
        this->pin = pin;
        this->datOfBirth = datOfBirth;
    }
};

vector<userRegistrations> users;
vector<transactions> transactionHistory;
string generateTransactionID() {
    string characters = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    string transactionID = "";
    int length = 10;

    srand(time(0)); // seed for randomness

    for (int i = 0; i < length; ++i) {
        int randomIndex = rand() % characters.length();
        transactionID += characters[randomIndex];
    }

    return transactionID;
}

void printTranasctioinHistory(){
    cout<<endl;
    for(transactions tn: transactionHistory){
        cout<<"\n----------- Transaction Number "<<trNum<<" -----------"<<endl;
        cout<<"Transaction ID: "<<tn.trId<<endl;
        cout<<"Sector: "<<tn.sector<<endl;
        cout<<"Number: "<<tn.number<<endl;
        cout<<"Amount: "<<tn.amount<<endl;
        trNum++;
    }
    cout<<"\n--------------------------------------------\n";
}
int pin(string pin){
    for(userRegistrations user : users){
        if(user.pin == pin){
            return 1;
        }
    }
    return 0;
}

void calculate(int amnt){
    mainBalance-=amnt;
    cout<<mainBalance<<endl;
}

bool operatorJustify(char x){
    if((x == '9' || x == '6' || x == '7' || x == '8' || x == '3')){
        return true;
    }
    return false;
}
bool numberJustifier(string number){
    if(number.length()==11 && number[0]=='0' && number[1]=='1' && operatorJustify(number[2])){
        return true;
    }
    return false;
}

void SendMoney(){
    cout<<"Enter the Number:\n";
    string s;
    cin>>s;
    if(numberJustifier(s)){
        int q;
        cout<<"Enter the Amount: ";
        cin>>q;
        string y;
        cout<<"Enter the Password: "<<endl;
        cin>>y;
        
        if(pin(y)){
            if(q>mainBalance){
                cout<<"Insufficient Entry"<<endl;
            }else{
                cout<<"\nSend Money SuccessFull"<<endl;
                cout<<"\nPresent Balance is: ";
                calculate(q);
                transactionHistory.emplace_back("Send Money",s, q, generateTransactionID());
                return;
            }

        }else{
            cout<<"\nomething Went Wrong"<<endl;
        }
    }else{
        cout<<"\nInvalid Number"<<endl;
    }

}

void RechargeComfirmation(int xy){
    cout<<"\nRecharge Successfull"<<endl;
    cout<<"Your Present Balance is: ";
    calculate(xy);
}

void rechargeProcess(string number){
    int xy;
        cout<<"Enter the amount: ";
        cin>>xy;
        string pass;
        cout<<"Enter the Password: ";
        cin>>pass;
        int k = pin(pass);
        if(k==1){
            if(xy>mainBalance){
                cout<<"Insufficient Entry"<<endl;
            }else{
                RechargeComfirmation(xy);
                transactionHistory.emplace_back("Recharge",number, xy, generateTransactionID());
            }
        }else{
            cout<<"Something went Wrong"<<endl;
        }
}

void mobileRecharge(){
    cout<<"1. Banglalink Exp(019********)\n"<<"2. Robi Exp(018********)\n"<<"3. Airtel Exp(016********)\n"<<"4. Grameenphone Exp(013********)\n";
    int op;  
    cout<<"Select the Operator: "<<endl;
    cin>>op;
    string ss;
    cout<<"Enter Phone Number: "<<endl;
    cin>>ss;
    if(!numberJustifier(ss)){
        cout<<"Invalid Number"<<endl;
        return;
    }
    if(op==1){
        
        if(ss[2]!='9'){
            cout<<"Invalid Operator"<<endl;
        }else{
           rechargeProcess(ss); 
        }
    }
    else if(op==2){

        if(ss[2]!='8'){
            cout<<"Invalid Operator"<<endl;
        }else{
           rechargeProcess(ss); 
        }
    }
    else if(op==3){

        if(ss[2]!='6'){
            cout<<"Invalid Operator"<<endl;
        }else{
           rechargeProcess(ss); 
        }
    }
    else if(op==4){

        if(ss[2]!='3'){
            cout<<"Invalid Operator"<<endl;
        }else{
           rechargeProcess(ss); 
        }
    }else{
        cout<<"Invalid Selection"<<endl;
    }

}

void payments(){
    cout<<"Enter the Marcent number: "<<endl;
    string num;
    cin>>num;
    if(!numberJustifier(num)){
        cout<<"Invalid Number"<<endl;
    }else{
        int am;
        cout<<"Enter the Amount: ";
        cin>>am;
        string pas;
        cout<<"Enter the Password: ";
        cin>>pas;
        int l = pin(pas);
        if(l == 1){
            if(am>mainBalance){
                cout<<"Insufficient Entry"<<endl;
            }else{
                cout<<"\nPayment SuccessFull"<<endl;
                cout<<"Present Balance is: ";
                calculate(am);
                transactionHistory.emplace_back("Payment",num, am, generateTransactionID());
            }

        }else{
            cout<<"Something Went Wrong"<<endl;
        }
    }
}

void cashout(){
    cout<<"Enter the Agent Number: "<<endl;
    string num;
    cin>>num;
    if(!numberJustifier(num)){
        cout<<"Invalid Agent Number"<<endl;
    }else{
        int am;
        cout<<"Enter the Amount: ";
        cin>>am;
        string pas;
        cout<<"Enter the Password: ";
        cin>>pas;
        int l = pin(pas);
        if(l == 1){
            if(am>mainBalance){
                cout<<"Insufficient Entry"<<endl;
            }else{
                cout<<"\nCashout SuccessFull"<<endl;
                cout<<"Present Balance is: ";
                calculate(am);
                transactionHistory.emplace_back("Cash Out",num, am, generateTransactionID());
            }

        }else{
            cout<<"\nSomething Went Wrong"<<endl;
        }
    }
}

void cashIn(){
    cout<<"Enter Amount: ";
    int amount;
    cin>>amount;
    mainBalance+=amount;
    cout<<"\nAmount added Successfully & Your Current Balance is: "<<mainBalance<<endl;
}
void paybill(){
    cout<<"Enter the Number: "<<endl;
    string num;
    cin>>num;
    if(!numberJustifier(num)){
        cout<<"Invalid Number"<<endl;
    }else{
        int am;
        cout<<"Enter the Amount: ";
        cin>>am;
        string pas;
        cout<<"Enter the Password: ";
        cin>>pas;
        int l = pin(pas);
        if(l == 1){
            if(am>mainBalance){
                cout<<"Insufficient Entry"<<endl;
            }else{
                cout<<"Bill Paid"<<endl;
                cout<<"Present Balance is: ";
                calculate(am);
                transactionHistory.emplace_back("Bill Pay",num, am, generateTransactionID());
            }

        }else{
            cout<<"Something Went Wrong"<<endl;
        }
    }
}

bool check_information(string nam, string fnam, string nid, string DoB, string number, string pin){
    transform(nam.begin(), nam.end(), nam.begin(), ::tolower);
    transform(fnam.begin(), fnam.end(), fnam.begin(), ::tolower);
    for(userRegistrations user : users){
        if(user.number == number){
            if(user.name == nam && user.FatherName == fnam && user.NID == nid && user.datOfBirth == DoB && user.pin == pin){
                return true;
            }
        }
    }
    return false;
}

void setPinIntoUserData(string number, string newPin){
    for(userRegistrations &ur : users){
        if(ur.number == number){
            ur.pin = newPin;
            return;
        }
    }
}
bool change_pin(string number){
    string OTP = "123456";
    string otp;
    cout<<"\nGive the 6 digits OTP here: "<<endl;
    cin>>otp;
    if(otp==OTP){
        cout<<"\nGo the Link and Download this app for Face Authentication"<<endl;
        cout<<"app/facescanner/googleplaystore.com"<<endl;
        string s = "DONE";
        cout<<"\nIf face scan Complete give the Secret Code Here"<<endl;
        string ss;
        cin>>ss;
            if(ss==s){
                cout<<"\nSecurity steps Successfully Passed"<<endl;
                while(true){
                    string pass, pass2;
                    cout<<"\nEnter a New Password"<<endl;
                    cin>>pass;
                    cout<<"Confirm the Password again"<<endl;
                    cin>>pass2;
                    if(pass!=pass2){
                        cout<<"\nPasswords are Not Match. Do it Again"<<endl;
                        continue;
                    }else{
                        setPinIntoUserData(number, pass);
                        return true;
                        break;
                    }
                }
            }else{
                cout<<"You have Entered the wrong Code"<<endl;
                cout<<"Try Again Later"<<endl;
            }
            
    }else{
        cout<<"Wrong OTP"<<endl;
    }
    
    return false;
}
void resetPIN(){

    cout<<"Warning!!! You can Do this for three Times only\n";
    bool chk = false;
    int i=1;
    while(i<4){
        cout<<"Enter Your NID Number: "<<endl;
        string nid;
        cin>>nid;
        getchar();
        string nam, fathrnam, daofB, number, pin;
        cout<<"Enter Your Full Name as Like your NID: \n";
        getline(cin, nam);
        
        cout<<"Enter Your Father Name: \n";
        getline(cin, fathrnam);
        cout<<"Enter Your Date of Birth as Like your NID (dd/mm/yyyy): \n";
        cin>>daofB;
        cout<<"Enter Mobile Number: \n";
        cin>>number;
        cout<<"Enter the PIN: \n";
        cin>>pin;

        if(check_information(nam, fathrnam, nid, daofB, number, pin)){
                cout<<"\nInformations are correct. Go next....."<<endl;
                chk = change_pin(number);
                break;
            }else{
                cout<<"Wrong Information"<<endl;
                cout<<"Your "<<i<<" Attempt Over. Try Again.."<<endl;
            }        
        i++; 
    }   
        if(chk==false){
        cout<<"\nYour Account Has been Locked"<<endl<<"Go to Your Nearby Bkash customer care or Call 16234 for more information"<<endl;
        }else{
            cout<<"\nCongratulation You have been changed PIN Successfully. Try to Login Again!!!"<<endl;
        }

}

void registration(){
    cout<<"Enter Your NID Number: "<<endl;
    string nid;
    cin>>nid;
    getchar();
    string nam, fathrnam, daofB, number;
    int pin;
    cout<<"Enter Your Full Name as Like your NID: \n";
    getline(cin, nam);
    
    cout<<"Enter Your Father Name: \n";
    getline(cin, fathrnam);
    cout<<"Enter Your Date of Birth as Like your NID (dd/mm/yyyy): \n";
    cin>>daofB;
    cout<<"Enter Mobile Number: \n";
    cin>>number;
    if(!numberJustifier(number)){
        cout<<"Invalid Number"<<endl;
        return;
    }
    cout<<"Enter a 5-Digits PIN: \n";
    cin>>pin;
    if (pin >= 10000 && pin <= 99999) {
        cout<<"\nPIN Selection Successful\n";
    } else {
        cout << "\nWrong PIN Selection Format!" << endl;
        return;
    }
    string pinStr = to_string(pin);
    transform(nam.begin(), nam.end(), nam.begin(), ::tolower);
    transform(fathrnam.begin(), fathrnam.end(), fathrnam.begin(), ::tolower);
    users.emplace_back(nam, fathrnam, nid, number, pinStr, daofB);
}

void myBkash(){
    cout<<"Enter The PIN: ";
    string s;
    cin>>s;
    int k = pin(s);
    if(k==1){
        cout<<"\nPresent Balance is: "<<mainBalance<<endl;
        return;
    }else{
        cout<<"\nWrong Password"<<endl;
    }
}

bool login(string number, string pin){

    for(userRegistrations user : users){
        if(user.number == number && user.pin == pin){
            cout<<"\nLogin Successful\n";
            return true;
        }
    }
    return false;
}
void firstPage(){

        while(true){
            cout<<"\n1. Send Money"<<endl<<"2. Send Money to Non-bkash User\n"<<"3. Mobile Recharge"<<
            endl<<"4. Payment\n"<<"5. Cash Out\n"<<"6. Cash In\n"<<"7. Pay Bill\n";
            cout<<"8. Download bkash app\n"<<"9. My Bkash\n"<<"10. Reset PIN\n"<<"11. Transactions History\n"<<"12. Previous\n";
            cout<<"\nEnter the option: ";
            int choice;
            cin>>choice;
            if(choice==1){
                SendMoney();
            }else if(choice==2){
                cout<<"We will develop this Feature in Future\n";
            }else if(choice==3){
                mobileRecharge();
            }else if(choice==4){
                payments();
            }else if(choice==5){
                cashout();
            }else if(choice==6){
                cashIn();
            }else if(choice==7){
                paybill();
            }else if(choice==8){
                cout<<"\nClick the link below...."<<endl;
                cout<<"bkash/app.googleplaystore.com/\n";
            }else if(choice==9){
                myBkash();
            }else if(choice==10){
                resetPIN();
                break;
            }else if(choice==11){
                printTranasctioinHistory();
            }else if(choice==12){
                break;
            }else{
                cout<<"Invalid Option. Please Try Again."<<endl;
            }
        }

}

int main(){
    cout<<"\n----------------- Welcome to Bkash ----------------\n"<<endl;
    
    while(true){
        cout<<"1. Registration \n2. Login\n3. Exit\n"<<endl;
        int command;
        cout<<"Enter Your Command: ";
        cin>>command;
        if(command==1){
            if(users.size() > 0){
                cout<<"You have already registered. Try to login"<<endl;
                continue;
            }
            registration();
            cout<<"Registration Successful. Try to login"<<endl;
        }else if(command==2){
            string number, pin;
            cout<<"Enter Your Mobile Number: ";
            cin>>number;
            cout<<"Enter Your PIN: ";
            cin>>pin;
            if(login(number, pin)){
                firstPage();
            }else{
                cout<<"Wrong Mobile Number or PIN"<<endl;
            }
        }else if(command==3){
            break;
            cout<<"Thank You for Visiting Bkash"<<endl;
        }else{
            cout<<"Invalid Command. Please Try Again."<<endl;
            continue;
        }
    }
return 0;
}