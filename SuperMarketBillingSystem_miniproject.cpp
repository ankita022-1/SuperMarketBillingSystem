//*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*PROJECT NAME-SUPERMARKET BILLING SYSTEM_*_*_*_*_*_*_*_*_*_*_*_*_*_*

//*****************************************CREATING HEADER FILE***************************************
#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>

using namespace std;

//************************************************CREATING CLASS***************************************
class supermarket{
    private:
    string  customer_name, product_name[10], str;
    int num, quantity[10], codenumber[10];
    long long int mobile_number;
    float cost[10], _discount[10], totalCost, amount, sum=0, totalDiscount=0;;    

    public:    

    void customerDetails();
    void takeOrder();     
    void amountData();
    void writeFile();
    void readFile();
    void recordDataFile();
    
};
//*****************************************Creating global file object******************************************
ofstream out("supermarket_Record.txt");   
ifstream in("supermarket_Record.txt");     
fstream rd;
//***************************************FUNCTION TO WRITE CUSTOMER DETAILS IN FILE*******************************
void supermarket:: customerDetails(){
    cout<<"\n---------------------Enter details of customer---------------------\n";    
    cout<<"Name : ";
    cin>>customer_name;    
    cout<<"Mobile number : ";
    cin>>mobile_number;     
}
//************************************************TAKE ORDER**********************************************
void supermarket :: takeOrder (){
    cout<<"\nEnter the total number of product : ";
    cin>>num;
    cout<<"---------------------Enter Details of products------------------------"<<endl;    
    for(int i=0; i<num ;i++ ){
        cout<<"Enter details of product: "<<i+1;
        cout<<"\ncode : ";
        cin>>codenumber[i];
        cout<<"\nName : ";
        cin>>product_name[i];
        cout<<"\ncost : Rs";
        cin>>cost[i];
        cout<<"\nQuantity : ";
        cin>>quantity[i];
        cout<<"\nDiscount : ";
        cin>>_discount[i];
        cout<<"\n\n";
        
    }    
}

//*************************************************ALL ABOUT MONEY *****************************************
void supermarket :: amountData(){     
    for(int i=0; i<num; i++){
       sum= sum  + quantity[i] * cost[i]; 
    }
    cout<<"Total Cost before discount : Rs "<<sum<<endl;
    for(int i=0; i<num; i++){
        totalDiscount = totalDiscount +  quantity[i]*((cost[i])*(_discount[i])/100);
    }

    cout<<"Total Discount : Rs "<<totalDiscount<<endl;
    totalCost = (sum - totalDiscount);
    cout<<"Total cost after discount : Rs "<<totalCost<<endl;

    cout<<"Enter money given by customer : Rs ";
    cin>>amount;
    cout<<"\n\n";
    if(amount < totalCost){
        cout<<"Error!! given amount is less"<<endl;
    }
    else if(amount >= totalCost){
        writeFile();
    }     
}
//************************************************WRITING IN THE FILE*********************************************
void supermarket :: writeFile(){
    //DETAILS OF CUSTOMER
    out<<"--------------------------Details of customer---------------------"<<endl;
    out<<"Name : "<<customer_name;
    out<<"\t\tMobile number : "<<mobile_number; 
    //DETAILS OF PRODUCTS
    out<<"\n-------------------------Details of products------------------------"<<endl;
    out<<"code"<<setw(20)<<"Name"<<setw(20)<<"cost"<<setw(20)<<"Quantity"<<setw(20)<<"Discount"<<endl;
    for(int i=0; i<num; i++){
         out<<codenumber[i]<<setw(20)<<product_name[i]<<setw(20)<<cost[i]<<setw(20)<<quantity[i]<<setw(20)<<_discount[i]<<endl;
    }
    //Amount
    out<<"Total Cost before discount : Rs "<<sum<<endl;
    out<<"Total Discount : Rs "<<totalDiscount<<endl;
    out<<"Total cost after discount : RS "<<totalCost<<endl;    
    out<<"money given by customer : Rs "<<amount<<endl;
    out<<"Please return Rs "<<(amount - totalCost)<<" to the customer\n\n";
    out<<"________________________________________THANKYOU_________________________________________\n\n";

    out.close();    
    readFile();
}
//************************************************READING FILE*****************************************************
void supermarket :: readFile(){    
    cout<<"--------------------------------------RECEIPT--------------------------------------------"<<endl;
    if((in.eof()) == 0){
        while(!(in.eof())){
        getline(in,str);
        cout<<str<<endl;
        }
    }
    else{
    cout<<"ERROR!! file 'supermarket_Record.txt', could not be opened"<<endl;
    cout<<"Receipt can not be generated"<<endl;
    exit(0);
    }

    in.close();      
}
//*************************************************RECORD DATA IN FILE***********************************************
void supermarket :: recordDataFile(){
    char ch;
    cout<<"If payment is done then PRESS D"<<endl; 
    cin>>ch;
       
    rd.open("record_Data.txt", ios::out | ios::app);    
    switch (ch){
        case 'D':        
        //DETAILS OF CUSTOMER
        rd<<"--------------------------Details of customer---------------------"<<endl;
        rd<<"Name : "<<customer_name;
        rd<<"\t\tMobile number : "<<mobile_number; 
        //DETAILS OF PRODUCTS
        rd<<"\n-------------------------Details of products------------------------"<<endl;
        rd<<"code"<<setw(20)<<"Name"<<setw(20)<<"cost"<<setw(20)<<"Quantity"<<setw(20)<<"Discount"<<endl;
        for(int i=0; i<num; i++){
               rd<<codenumber[i]<<setw(20)<<product_name[i]<<setw(20)<<cost[i]<<setw(20)<<quantity[i]<<setw(20)<<_discount[i]<<endl;
        }
        //Amount
        rd<<"Total Cost before discount : Rs "<<sum<<endl;
        rd<<"Total Discount : Rs "<<totalDiscount<<endl;
        rd<<"Total cost after discount :Rs "<<totalCost<<endl;

        cout<<"Data is recorded."<<endl;
        break;

        default:
        cout<<"Data is not recorded"<<endl;
        exit(0); 

        rd.close();          
    }
    
    
}

int main(){
    supermarket S;
    S.customerDetails();
    S.takeOrder();   
    S.amountData();

    S.recordDataFile();
    return 0;
}

//***********************************************INPUT***********************************************
/*
--------------------------------------RECEIPT--------------------------------------------
--------------------------Details of customer---------------------
Name : Sneha            Mobile number : 19384723
-------------------------Details of products------------------------
code                Name                cost            Quantity            Discount
1003         AsianPaints                3000                   5                  21
Total Cost before discount : Rs 15000
Total Discount : Rs 3150
Total cost after discount : RS 11850
money given by customer : Rs 12000
Please return Rs 150 to the customer

________________________________________THANKYOU_________________________________________


If payment is done then PRESS D
D
Data is recorded.


--------------------------------------RECEIPT--------------------------------------------
--------------------------Details of customer---------------------
Name : Neha             Mobile number : 192839724
-------------------------Details of products------------------------
code                Name                cost            Quantity            Discount
1000               shirt                 800                   1                  10
1001               jeans                2000                   2                  25
1002               scarf                 400                   1                   0
Total Cost before discount : Rs 5200
Total Discount : Rs 1080
Total cost after discount : RS 4120
money given by customer : Rs 5000
Please return Rs 880 to the customer

________________________________________THANKYOU_________________________________________


If payment is done then PRESS D
D
Data is recorded.

---------------------Enter details of customer---------------------
Name : Rohan
Mobile number : 0039841392

Enter the total number of product : 1
---------------------Enter Details of products------------------------
Enter details of product: 1
code : 1003

Name : Watch

cost : Rs5000

Quantity : 1

Discount : 25


Total Cost before discount : Rs 5000
Total Discount : Rs 1250
Total cost after discount : Rs 3750
Enter money given by customer : Rs 4000


--------------------------------------RECEIPT--------------------------------------------
--------------------------Details of customer---------------------
Name : Rohan            Mobile number : 39841392
-------------------------Details of products------------------------
code                Name                cost            Quantity            Discount
1003               Watch                5000                   1                  25
Total Cost before discount : Rs 5000
Total Discount : Rs 1250
Total cost after discount : RS 3750
money given by customer : Rs 4000
Please return Rs 250 to the customer

________________________________________THANKYOU_________________________________________


If payment is done then PRESS D
D
Data is recorded.

*/