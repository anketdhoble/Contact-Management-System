Contacts Management System

The code can be complied in console using : >g++ contact.cpp -o contact

1. Introduction

The system is designed generally to store the contacts and basic information. The
contacts are stored in two different categories like persons and business in which all the
individual person's contacts are stored under person category and A specific business
contact information under business category. All the system operation is carried out
through the Files.

2. Approach

Firstly, I have created a person base class in which I have created a function to addPerson,
showPerson, deleteAllPerson, searchPerson, deleteParticularPerson & updatePerson
which is called accordingly to the user input from the console screen & it will handle all the
operations for person contacts. Secondly, I have created another base class for business
in which I have created functions to addBusiness, showBusiness, deleteAllBusiness,
searchBusiness, deleteParticularBusiness & updateBusiness to handle all the operations
for business contacts. Then, I have created a subclass of contacts & I have given rights to
access both base class. In this class, I have created a constructor to show a total number
of person and business contacts. In this class, I have created two functions as well i.e.
showAll & deleteAll for showing & deleting all the person and business contacts. In main, I
have created the options to maintain the contacts of both person and business. Options
are made by using the while loop nested with the switch case. I have used person.txt to
store all person contacts and business.txt to store all business contacts.

3. Issues Faced

Firstly, at the time of adding new contact, I’m using a separator(‘|’) after each detail of the
record. It is working perfectly fine but at the time of deleting and updating particular contact
it is deleting & updating the record but the separators are not going to be removed from
the file. Due to this, I’m not getting the exact count of a number of contacts after deleting
and updating any contacts.

4. Function Explanation

Firstly, in each and every function I have used the char[] of heap memory to get the details
of particular contact and I have deleted the heap memory after the operation gets
completed. So there is no leakage of memory. Secondly, before reading and writing the file
gets open by open() and after reading and writing file is getting closed by close(). To check
the if the file is open or not for that I used is_open().

The functions of base class person are addPerson(), showPerson(), deleteAllPerson(),
searchPerson(), deleteParticularPerson(), updatePerson() & the functions of base class
business are addBusiness(), showBusiness(), deleteAllBusiness(), searchBusiness(),
deleteParticularBusiness(), updateBusiness(). The functions of both base class are similar
the only difference is that in business class we have some different details like company
name, address, email id, contact no, website whereas in person we are storing the details
like name, contact no, date of birth, email id by using the different char *variables of heap
memory.addPerson() or addBusiness():

Firstly, it will take the user input for the person/business name from the console and it will
check in a person.txt/business.txt file for the same name if the same name exists then it
will ask the user for some another name which is not in the existing contacts else it will
proceed for further user inputs. In the end, it will show the message of record saved
successfully.

showPerson() or showBusiness():

In this function, it is just listing all the record from the person.txt/bsuiness.txt file.

deleteAllPerson() or deleteAllBusiness():

The delete function is used to delete all the records from person.txt/business.txt. This is
just done by using ios::out | ios::trunc .

searchPerson() or searchBusiness():

This function is used to search the particular record by person name or company name
from the person.txt or business.txt till the end of the file. It will search the particular name
by comparing the name of each and every record from the file. It will return the record if
they found otherwise it will returns record not found.

deleteParticularPerson() or deleteParticularBusiness():

This function is used to delete a particular record from the file. So, for deleting the record
we need to search the record first. For searching, it works exactly the same as the search
function but instead of showing the record it is just deleting the particular record from the
file. For searching the record we just need the name from user to find delete the record.

updatePerson() or updateBusiness():

This function is used to update the existing contact. So, for updating the contact again we
need to search the contact by name, after that, we will enter the new details for the
particular record.

showAll():

In this function i just called the showPerrson() & showBusiness() to show all the records
from person.txt & business.txt. So, in this function, I just reused the same function to show
all the contacts i.e. person and business.

deleteAll():

This function works exactly the same as showAll() but instead of showing it is just deleting
all the contacts from the person.txt and business.txt.
In update and delete function I’m using temporary file temp.txt file to avoid the duplication
of record and for deleting the particular record successfully.

To test the system I have used person.txt, business.txt, temp.txt files.
