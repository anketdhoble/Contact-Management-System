#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

// Name of file containing names and phone numbers



class person           //Person Class
{
protected:
  char *name=NULL;
  char *contactNo=NULL;
  char *dateOfBirth=NULL;
  char *emailId=NULL;
  char *a=NULL;
public:
  void addPerson()                        //Inserting Person
  {
    name=new char[30];
    contactNo=new char[30];
    dateOfBirth=new char[30];
    emailId=new char[30];
    a=new char[30];
    int flag=0;
    char t;
    fstream per;
    per.open("person.txt", ios::in);
    cin.ignore();
    cout<<" \n Enter your Full Name : ";
    cin.getline(a,30);
    while (a[0]==0) {
      std::cout << "Null value not accepted please enter the valid name :";
      cin.getline(a,30);

    }
    if(per.is_open()){
      while(!per.eof())
      {
          per.getline(name,30,'|');
          per.getline(contactNo,30,'|');
          per.getline(dateOfBirth,30,'|');
          per.getline(emailId,30);
          if(strcmp(name, a)==0)
          {
            flag=1;

              break;

          }

        }
    }

      per.close();
      if (flag==1)
      {
        cout<< "\nEntered name is already available in address book please use different name \n\n press 0 key to continue...or press $ to go back..."<<endl;
        cin>>t;
        if(t!='$')
        {
          addPerson();
        }

      }
      else
      {
        per.open("person.txt", ios::app);
        cout<<" \n Enter your Phone No.(use ',' for more than one): ";
        cin.getline(contactNo,30);
        while (contactNo[0]==0) {
          std::cout << "Null value not accepted please enter the valid contact number :";
          cin.getline(contactNo,30);

        }
        cout<<" \n Enter your date of birth(Ex: 15th may 1995) : ";
        cin.getline(dateOfBirth,30);
        while (dateOfBirth[0]==0) {
          std::cout << "Null value not accepted please enter valid the date Of Birth :";
          cin.getline(dateOfBirth,30);

        }
        cout<<" \n Enter your emailId : ";
        cin.getline(emailId,30);
        while (emailId[0]==0) {
          std::cout << "Null value not accepted please enter the valid Email Id :";
          cin.getline(emailId,30);
        }
        per<< a<<'|'<<contactNo<<'|'<<dateOfBirth<<'|'<<emailId<<'\n';
        cout<< "\n\nRecord saved successfully !";
        flag=0;
        per.close();
      }
      delete[] name;
      delete[] contactNo;
      delete[] dateOfBirth;
      delete[] emailId;
      delete[] a;

  }
  void showPersonContact()                  //Show all tthe Contacts of person
  {
    name=new char[30];
    contactNo=new char[30];
    dateOfBirth=new char[30];
    emailId=new char[30];
    a=new char[30];
    fstream per;
    per.open("person.txt",ios::in);
    if(per.is_open())
    {
      if (per.eof())
      {
        std::cout << "Records Not Found" << '\n';
      }
      else
      {
        std::cout << "_________________________________________________________________________________________________________________________________" << '\n';
        cout<< " \n\t Full Name \t | \t Contact No. \t | \t Date Of Birth \t | \t Email Id \n";
        std::cout << "_________________________________________________________________________________________________________________________________" << '\n';

        while(!per.eof())
        {
            per.getline(name,30,'|');
            per.getline(contactNo,30,'|');
            per.getline(dateOfBirth,30,'|');
            per.getline(emailId,30);
            cout<< "\n \t "<< name << "\t\t"<<contactNo<<"\t\t"<<dateOfBirth<<"\t\t"<<emailId<<endl;

        }
      }
      per.close();
      delete[] name;
      delete[] contactNo;
      delete[] dateOfBirth;
      delete[] emailId;
      delete[] a;
    }
    else
    {
      std::cout << "No records found!!!" << '\n';
    }

  }
  void deleteAllPerson()            //Delete all the person records
  {
    fstream per;

    per.open("person.txt",ios::out | ios::trunc);

    per.close();

    cout<<"\n done !!! \n";
  }
  void searchPerson()               //search person records
  {
    name=new char[30];
    contactNo=new char[30];
    dateOfBirth=new char[30];
    emailId=new char[30];
    a=new char[30];
    fstream per;
    per.open("person.txt",ios::in);
    cout<<" \n Enter the Full Name to search about it : ";
    cin.ignore();
    cin.getline(a,30);
    int flag=0;
    cout<< " \n\t Full Name \t | \t Contact No. \t | \t Date Of Birth \t | \t Email Id \n";
    if(per.is_open())
    {
      while(!per.eof())
      {
          per.getline(name,30,'|');
          per.getline(contactNo,30,'|');
          per.getline(dateOfBirth,30,'|');
          per.getline(emailId,30);
          if(strcmp(name, a)==0)
          {
              cout<< "\n \t "<< name << "\t\t"<<contactNo<<"\t\t"<<dateOfBirth<<"\t\t"<<emailId<<endl;
              flag=1;
              break;
          }

      }
      if(flag==0)
      {
          cout<<" \n not found !!!!\n";
      }
      per.close();
      delete[] name;
      delete[] contactNo;
      delete[] dateOfBirth;
      delete[] emailId;
      delete[] a;
    }
    else
    {
      std::cout << "Record not found !!!" << '\n';
    }

  }
  void deletePerticularPerson()       //delete single record by name
  {
    name=new char[30];
    contactNo=new char[30];
    dateOfBirth=new char[30];
    emailId=new char[30];
    a=new char[30];
    int flag=1;
    fstream per;
    fstream temp;

    per.open("person.txt",ios::in);
    temp.open("temp.txt",ios::out);
    cin.ignore();
    cout<<" \n\t enter the Full Name to delete record : ";
    cin.getline(a,30);
    if (per.is_open()) {
      while(!per.eof())
      {
          per.getline(name,30,'|');
          per.getline(contactNo,30,'|');
          per.getline(dateOfBirth,30,'|');
          per.getline(emailId,30);
          if(strcmp(name,a)==0)
          {
            flag=0;
          }
          else
          {
              temp<< name<<'|'<<contactNo<<'|'<<dateOfBirth<<'|'<<emailId<<'\n';
              //std::cout <<name<<'|'<<contactNo<<'|'<<dateOfBirth<<'|'<<emailId<<'\n';
          }


      }
      temp.close();
      per.close();
      if(flag==0)
      {
      per.open("person.txt",ios::out);
      temp.open("temp.txt",ios::in);
      while(!temp.eof())
      {
          temp.getline(name,30,'|');
          temp.getline(contactNo,30,'|');
          temp.getline(dateOfBirth,30,'|');
          temp.getline(emailId,30);
          per<< name<<'|'<<contactNo<<'|'<<dateOfBirth<<'|'<<emailId<<'\n';
      }
      temp.close();
      per.close();
      remove("temp.txt");

        cout<<"\n Record Deleted successfully !!! \n";
      }
      else
      {
        cout<<"\n Record not found !!! \n";
      }
      delete[] name;
      delete[] contactNo;
      delete[] dateOfBirth;
      delete[] emailId;
      delete[] a;
    }
    else
    {
      std::cout << "Record not found!!!" << '\n';
    }

  }
  void updatePersonContact()
  {
    name=new char[30];
    contactNo=new char[30];
    dateOfBirth=new char[30];
    emailId=new char[30];
    a=new char[30];
    fstream per;
    fstream temp;
    int flag=0;
    per.open("person.txt",ios::in);
    temp.open("temp.txt",ios::out);
    if (per.is_open()) {
      cin.ignore();
      cout<<" \n\t enter the Full Name to update record : ";
      cin.getline(a,30);
      while (a[0]==0) {
        std::cout << "Null value not accepted please enter the valid Full Name to update record :";
        cin.getline(a,30);
      }
      while(!per.eof())
      {
          per.getline(name,30,'|');
          per.getline(contactNo,30,'|');
          per.getline(dateOfBirth,30,'|');
          per.getline(emailId,30);
          if(strcmp(name,a)==0)
          {
            flag=1;
            cout<<" \n Enter your Full Name : ";
            cin.getline(name,30);
            while (name[0]==0) {
              std::cout << "Null value not accepted please enter the valid Full Name :";
              cin.getline(name,30);
            }
            cout<<" \n Enter your Phone No.(use ',' for more than one): ";
            cin.getline(contactNo,30);
            while (contactNo[0]==0) {
              std::cout << "Null value not accepted please enter the valid Phone No.:";
              cin.getline(contactNo,30);
            }
            cout<<" \n Enter your date of birth(Ex: 15th may 1995) : ";
            cin.getline(dateOfBirth,30);
            while (dateOfBirth[0]==0) {
              std::cout << "Null value not accepted please enter the valid date of birth(Ex: 15th may 1995) :";
              cin.getline(dateOfBirth,30);
            }
            cout<<" \n Enter your emailId : ";
            cin.getline(emailId,30);
            while (emailId[0]==0) {
              std::cout << "Null value not accepted please enter the valid emailId :";
              cin.getline(emailId,30);
            }
            temp<< name<<'|'<<contactNo<<'|'<<dateOfBirth<<'|'<<emailId<<'\n';
          }
          else
          {
            temp<< name<<'|'<<contactNo<<'|'<<dateOfBirth<<'|'<<emailId<<'\n';
          }


      }
      temp.close();
      per.close();
      if(flag==1)
      {
        per.open("person.txt",ios::out);
        temp.open("temp.txt",ios::in);
        while(!temp.eof())
        {
            temp.getline(name,30,'|');
            temp.getline(contactNo,30,'|');
            temp.getline(dateOfBirth,30,'|');
            temp.getline(emailId,30);
            per<<name<<'|'<<contactNo<<'|'<<dateOfBirth<<'|'<<emailId<<'\n';
        }
        temp.close();
        per.close();
        remove("temp.txt");
        cout<<"\n done !!! \n";
      }
      else
      {
        std::cout << "\nRecord not found !!!\n please try again" << '\n';
      }
      delete[] name;
      delete[] contactNo;
      delete[] dateOfBirth;
      delete[] emailId;
      delete[] a;

    }
    else
    {
      std::cout << "Record not found !!!" << '\n';
    }

  }
};


class business
{
protected:
  char *cName=NULL;
  char *cContactNo=NULL;
  char *cAdrress=NULL;
  char *cEmailId=NULL;
  char *cWebsite=NULL;
  char *ca=NULL;



public:
  void addBusiness()
  {
    cName=new char[40];
    cContactNo=new char[30];
    cAdrress=new char[30];
    cEmailId=new char[30];
    cWebsite=new char[30];
    ca=new char[40];
    int flag=0;
    char t;
    fstream busi;
    busi.open("business.txt", ios::in);
    cin.ignore();
    cout<<" \n Enter Company Name : ";
    cin.getline(ca,40);
    while (ca[0]==0) {
      std::cout << "Null value not accepted please enter the valid Company Name :";
      cin.getline(ca,40);
    }
    if(busi.is_open()){
    while(!busi.eof())
    {
        busi.getline(cName,40,'|');
        busi.getline(cAdrress,30,'|');
        busi.getline(cContactNo,30,'|');
        busi.getline(cEmailId,30,'|');
        busi.getline(cWebsite,30);
        if(strcmp(cName, ca)==0)
        {
          flag=1;

            break;

        }

      }
    }
      busi.close();

      if (flag==1)
      {
        cout<< "\nEntered Company name is already available in address book please check your company name \n\n press any key to continue...or press $ to go back..."<<endl;
        cin>>t;
        if(t!='$')
        {
          addBusiness();
        }

      }
      else
      {

        busi.open("business.txt", ios::app);
        cout<<" \n Enter the Address of company(city,postcode):";
        cin.getline(cAdrress,30);
        while (cAdrress[0]==0) {
          std::cout << "Null value not accepted please enter the valid Address of company :";
          cin.getline(cAdrress,30);
        }
        cout<<" \n Enter the contact number details of company : ";
        cin.getline(cContactNo,30);
        while (cContactNo[0]==0) {
          std::cout << "Null value not accepted please enter the valid contact number of company :";
          cin.getline(cContactNo,30);
        }
        cout<<" \n Enter the emailId of company : ";
        cin.getline(cEmailId,30);
        while (cEmailId[0]==0) {
          std::cout << "Null value not accepted please enter the valid emailId of company :";
          cin.getline(cEmailId,30);
        }
        cout<<" \n Enter the website of company : ";
        cin.getline(cWebsite,30);
        while (cWebsite[0]==0) {
          std::cout << "Null value not accepted please enter the valid website of company :";
          cin.getline(cWebsite,30);
        }
        busi<< ca<<'|'<<cAdrress<<'|'<<cContactNo<<'|'<<cEmailId<<'|'<<cWebsite<<'\n';
        cout<< "\n\nRecord saved successfully !";
        flag=0;
        busi.close();
        delete[] cName;
        delete[] cContactNo;
        delete[] cAdrress;
        delete[] cEmailId;
        delete[] cWebsite;
        delete[] ca;
      }

  }
  void showBusinessContact()
  {
    cName=new char[40];
    cContactNo=new char[30];
    cAdrress=new char[30];
    cEmailId=new char[30];
    cWebsite=new char[30];
    ca=new char[40];
    fstream busi;
    busi.open("business.txt",ios::in);
    if(busi.is_open())
    {
      if (busi.eof())
      {
        std::cout << "Records Not Found" << '\n';
      }
      else
      {
        std::cout << "_________________________________________________________________________________________________________________________________" << '\n';

        cout<< " \n\t Company Name \t | \t Address \t | \t Contact No. \t | \t Email Id \t | \t Website\n";
        std::cout << "_________________________________________________________________________________________________________________________________" << '\n';

        while(!busi.eof())
        {
          busi.getline(cName,40,'|');
          busi.getline(cAdrress,30,'|');
          busi.getline(cContactNo,30,'|');
          busi.getline(cEmailId,30,'|');
          busi.getline(cWebsite,30);
          cout<< "\n \t "<< cName << "\t\t"<<cAdrress<<"\t\t"<<cContactNo<<"\t\t"<<cEmailId<<"\t\t"<<cWebsite<<endl;
        }
      }
      busi.close();
      delete[] cName;
      delete[] cContactNo;
      delete[] cAdrress;
      delete[] cEmailId;
      delete[] cWebsite;
      delete[] ca;
    }
    else
    {
      std::cout << "No records found!!" << '\n';
    }


  }
  void deleteAllBusiness()
  {
    fstream busi;

    busi.open("business.txt",ios::out | ios::trunc);

    busi.close();

    cout<<"\n all the records are deleted successfully !!! \n";
  }
  void searchBusiness()
  {
    cName=new char[40];
    cContactNo=new char[30];
    cAdrress=new char[30];
    cEmailId=new char[30];
    cWebsite=new char[30];
    ca=new char[40];
    fstream busi;
    busi.open("business.txt",ios::in);
    if(busi.is_open())
    {
      cout<<" \n Enter the Company Name to search about it : ";
      cin.ignore();
      cin.getline(ca,40);
      int flag=0;
      cout<< " \n\t Company Name \t | \t Address \t | \t Contact No. \t | \t Email Id \t | \t Website\n";
      while(!busi.eof())
      {
          busi.getline(cName,40,'|');
          busi.getline(cAdrress,30,'|');
          busi.getline(cContactNo,30,'|');
          busi.getline(cEmailId,30,'|');
          busi.getline(cWebsite,30);
          if(strcmp(cName, ca)==0)
          {
              cout<< "\n \t "<< cName << "\t\t"<<cAdrress<<"\t\t"<<cContactNo<<"\t\t"<<cEmailId<<"\t\t"<<cWebsite<<endl;
              flag=1;
              break;
          }

      }
      if(flag==0)
      {
          cout<<" \n not found !!!!\n";
      }
      busi.close();
      delete[] cName;
      delete[] cContactNo;
      delete[] cAdrress;
      delete[] cEmailId;
      delete[] cWebsite;
      delete[] ca;
    }
    else
    {
      std::cout << "Record not found !!!" << '\n';
    }

  }
  void deletePerticularBusiness()
  {
    cName=new char[40];
    cContactNo=new char[30];
    cAdrress=new char[30];
    cEmailId=new char[30];
    cWebsite=new char[30];
    ca=new char[40];
    int flag=1;
    fstream busi;
    fstream temp;

    busi.open("business.txt",ios::in);
    temp.open("temp.txt",ios::out);
    cin.ignore();
    if (busi.is_open()) {
      cout<<" \n\t Enter the Company Name to delete record : ";
      cin.getline(ca,40);
      while(!busi.eof())
      {
        busi.getline(cName,40,'|');
        busi.getline(cAdrress,30,'|');
        busi.getline(cContactNo,30,'|');
        busi.getline(cEmailId,30,'|');
        busi.getline(cWebsite,30);
          if(strcmp(cName,ca)==0)
          {
            //cout <<"Finded";
            //std::cout << "" << '\n';
            flag=0;
          }
          else
          {
              temp<<cName<<'|'<<cAdrress<<'|'<<cContactNo<<'|'<<cEmailId<<'|'<<cWebsite<<'\n';
              //std::cout <<cName<<'|'<<cAdrress<<'|'<<cContactNo<<'|'<<cEmailId<<'|'<<cWebsite<<'\n';
          }


      }
      temp.close();
      busi.close();
      delete[] cName;
      delete[] cContactNo;
      delete[] cAdrress;
      delete[] cEmailId;
      delete[] cWebsite;
      delete[] ca;
      // per.open("person.txt",ios::out | ios::trunc);
      // std::cout << "File cleaned" << '\n';
      // per.close();
      if(flag==0)
      {
        cName=new char[40];
        cContactNo=new char[30];
        cAdrress=new char[30];
        cEmailId=new char[30];
        cWebsite=new char[30];
        ca=new char[40];
      busi.open("business.txt",ios::out);
      temp.open("temp.txt",ios::in);
      while(!temp.eof())
      {
        temp.getline(cName,40,'|');
        temp.getline(cAdrress,30,'|');
        temp.getline(cContactNo,30,'|');
        temp.getline(cEmailId,30,'|');
        temp.getline(cWebsite,30);
          busi<< cName<<'|'<<cAdrress<<'|'<<cContactNo<<'|'<<cEmailId<<'|'<<cWebsite<<'\n';
      }
      temp.close();
      busi.close();
      delete[] cName;
      delete[] cContactNo;
      delete[] cAdrress;
      delete[] cEmailId;
      delete[] cWebsite;
      delete[] ca;
      remove("temp.txt");

        cout<<"\n Record Deleted successfully !!! \n";
      }
      else
      {
        cout<<"\n Record not found !!! \n";
      }
    }
    else
    {
      std::cout << "Record not found !!!" << '\n';
    }


  }
  void updateBusiness()
  {
    cName=new char[40];
    cContactNo=new char[30];
    cAdrress=new char[30];
    cEmailId=new char[30];
    cWebsite=new char[30];
    ca=new char[40];
    fstream busi;
    fstream temp;
    int flag=0;
    busi.open("business.txt",ios::in);
    temp.open("temp.txt",ios::out);
    if (busi.is_open()) {
      cin.ignore();
      cout<<" \n\t enter the Company Name to update record : ";
      cin.getline(ca,40);
      while (ca[0]==0) {
        std::cout << "Null value not accepted please enter the valid Company Name:";
        cin.getline(ca,40);
      }
      while(!busi.eof())
      {
        busi.getline(cName,40,'|');
        busi.getline(cAdrress,30,'|');
        busi.getline(cContactNo,30,'|');
        busi.getline(cEmailId,30,'|');
        busi.getline(cWebsite,30);
          if(strcmp(cName,ca)==0)
          {
            cout<<" \n Enter the Company Name: ";
            cin.getline(cName,40);
            while (cName[0]==0) {
              std::cout << "Null value not accepted please enter the valid Company Name:";
              cin.getline(cName,40);
            }
            cout<<" \n Enter the Address of company(city,postcode):";
            cin.getline(cAdrress,30);
            while (cAdrress[0]==0) {
              std::cout << "Null value not accepted please enter the valid Address of company:";
              cin.getline(cAdrress,30);
            }
            cout<<" \n Enter the contact number details of company : ";
            cin.getline(cContactNo,30);
            while (cContactNo[0]==0) {
              std::cout << "Null value not accepted please enter the valid contact number of company:";
              cin.getline(cContactNo,30);
            }
            cout<<" \n Enter the emailId of company : ";
            cin.getline(cEmailId,30);
            while (cEmailId[0]==0) {
              std::cout << "Null value not accepted please enter the valid emailId of company:";
              cin.getline(cEmailId,30);
            }
            cout<<" \n Enter the website of company : ";
            cin.getline(cWebsite,30);
            while (cWebsite[0]==0) {
              std::cout << "Null value not accepted please enter the valid website of company:";
              cin.getline(cWebsite,30);
            }

            temp<< cName<<'|'<<cAdrress<<'|'<<cContactNo<<'|'<<cEmailId<<'|'<<cWebsite<<'\n';
            flag=1;
          }
          else
          {
            temp<< cName<<'|'<<cAdrress<<'|'<<cContactNo<<'|'<<cEmailId<<'|'<<cWebsite<<'\n';
          }


      }
      temp.close();
      busi.close();
      delete[] cName;
      delete[] cContactNo;
      delete[] cAdrress;
      delete[] cEmailId;
      delete[] cWebsite;
      delete[] ca;
      if(flag==1)
      {
        cName=new char[40];
        cContactNo=new char[30];
        cAdrress=new char[30];
        cEmailId=new char[30];
        cWebsite=new char[30];
        ca=new char[40];
        busi.open("business.txt",ios::out);
        temp.open("temp.txt",ios::in);
        while(!temp.eof())
        {
          temp.getline(cName,40,'|');
          temp.getline(cAdrress,30,'|');
          temp.getline(cContactNo,30,'|');
          temp.getline(cEmailId,30,'|');
          temp.getline(cWebsite,30);
            busi<< cName<<'|'<<cAdrress<<'|'<<cContactNo<<'|'<<cEmailId<<'|'<<cWebsite<<'\n';
        }
        temp.close();
        busi.close();
        delete[] cName;
        delete[] cContactNo;
        delete[] cAdrress;
        delete[] cEmailId;
        delete[] cWebsite;
        delete[] ca;
        remove("temp.txt");
        cout<<"\n Updation done successfully !!! \n";


      }
      else
      {
        std::cout << "Record not found!!!\nPlease try again.." << '\n';
      }
    }
    else
    {
      std::cout << "Record not found!!!" << '\n';
    }

}
};



class contacts : public person, public business
{
  int count_per=0;
  int count_busi=0;
  string line;
public:
  contacts()
  {
    ifstream per("person.txt");
    while (getline(per, line))
        count_per++;
    std::cout << "Total number of person contacts: " << count_per<<endl;

    ifstream busi("business.txt");
    while (getline(busi, line))
        count_busi++;
    std::cout << "Total number of business contacts: " << count_busi<<endl;
  }
  void showAllContact()
  {
    std::cout << "---------------------------------------------------------------------------------------------------------------------------------------------" << '\n';
    showPersonContact();
    std::cout << "---------------------------------------------------------------------------------------------------------------------------------------------" << '\n';
    showBusinessContact();
    std::cout << "---------------------------------------------------------------------------------------------------------------------------------------------" << '\n';

  }
  void deleteAllContact()
  {
    deleteAllPerson();
    deleteAllBusiness();
  }
};





void printline(char ch, int size)
{
    for(int i=0; i<size; i++)
        cout << ch;
    cout << "\n";
}

int main()
{
  system("clear");
  cout << "************** CONTACT BOOK  ***************" << endl;
  contacts ab;

    do
    {
        int choice;
        cout << "\n";
        printline('-', 40);
        cout << "1. Add Contacts" << endl
        << "2. Show Contact" << endl
        << "3. Update Contact" << endl
        << "4. Search Contact" << endl
        << "5. Delete Contacts" << endl
        << "6. Quit" << endl << endl
        << "Your choice...";
        cin >> choice;
        if(!choice)
        {
          std::cout << "please enter valid number" << '\n';
          break;

      }
      else
      {
        system("clear");
        printline('-', 20);

        switch (choice) {
          case 1:
                    int addContact;
                    char a;

                  do {
                    std::cout << "1. Add Person Contact" << '\n';
                    std::cout << "2. Add Business Contact" << '\n';
                    std::cout << "press 0 to go back" << '\n';
                    std::cin >> addContact;
                    if(addContact==1 || addContact==2)
                    {
                      switch (addContact) {
                        case 1:

                              ab.addPerson();

                              break;
                        case 2:
                              ab.addBusiness();
                              break;
                      }

                      cout<<"\nDo you want to add more Contact (y/n):";
                      cin>>a;
                    }
                    else
                    {
                      a='n';
                    }

                    system("clear");
                  } while(a=='y');
                  break;
          case 2:
                  int showContact;
                  do {
                    std::cout << "1. Show all Contacts" << '\n';
                    std::cout << "2. Person Contacts" << '\n';
                    std::cout << "3. Business Contacts" << '\n';
                    std::cout << "press 0 Go back" << '\n';
                    std::cin >> showContact;
                    system("clear");
                    switch (showContact) {
                      case 1:
                            ab.showAllContact();
                            break;
                      case 2:
                            ab.showPersonContact();
                            break;
                      case 3:
                            ab.showBusinessContact();
                            break;

                    }
                  } while(0);
                    break;
            case 3:
                  int updateContact;

                  do {
                    std::cout << "1. To Update the person contact by name" << '\n';
                    std::cout << "2. To Update the business contact by company name" << '\n';
                    std::cout << "press 0 To go back" << '\n';
                    std::cin >> updateContact;
                    switch (updateContact) {
                      case 1:
                            ab.updatePersonContact();
                            break;
                      case 2:
                            ab.updateBusiness();
                            break;
                    }
                  } while(0);
                  break;

            case 4:
                        int searchContact;

                        do {
                          std::cout << "1. Search contact from person" << '\n';
                          std::cout << "2. Search contact from business" << '\n';
                          std::cout << "3. to go back" << '\n';
                          std::cin >> searchContact;
                          switch (searchContact) {
                            case 1:
                                  ab.searchPerson();
                                  break;
                            case 2:
                                  ab.searchBusiness();
                                  break;

                          }
                        } while(0);
                        break;
                        system("clear");
            case 5:
                  int deleteContact;
                  do {
                    std::cout << "1. To delete all contacts" << '\n';
                    std::cout << "2. To delete all person contacts" << '\n';
                    std::cout << "3. To delete all Business contacts" << '\n';
                    std::cout << "4. To delete perticular Person contact by name" << '\n';
                    std::cout << "5. To delete perticular Business by Company name" << '\n';
                    std::cout << "press 0 to go back" << '\n';
                    std::cin >> deleteContact;
                    switch (deleteContact) {
                      case 1:
                            ab.deleteAllContact();
                            break;
                      case 2:
                            ab.deleteAllPerson();
                            break;
                      case 3:
                            ab.deleteAllBusiness();
                            break;
                      case 4:
                            ab.deletePerticularPerson();
                            break;
                      case 5:
                            ab.deletePerticularBusiness();
                            break;
                    }

                  } while(0);
                  break;
                case 6:
                  exit(0);

                        break;
                default :
                        std::cout << "Invalid Input" << '\n';
                        break;



        }
      }


      }while(1);


}
