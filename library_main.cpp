#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;
class book{
public:
int id;
string author;
string title;
bool isissued=false;
void display(){
cout<<"id:"<<id<<endl;
cout<<"title:"<<title<<endl;
cout<<"author:"<<author<<endl;
if(isissued)
cout<<"status:issued\n";
else
cout<<"status:available\n";

}
};
void savetofile(vector<book> &books){
ofstream file("library.txt");
for(int i=0;i<books.size();i++){
file<<books[i].id<<endl;
file<<books[i].title<<endl;
file<<books[i].author<<endl;
file<<books[i].isissued<<endl;
}
file.close();
}
void loadFromFile(vector<book> &books){
ifstream file("library.txt");
if(!file) return;   // file not exists
while(true){
book b;
if(!(file>>b.id)) break;
file.ignore();
getline(file, b.title);
getline(file, b.author);
file>>b.isissued;
file.ignore();
books.push_back(b);
}
file.close();
}
int main(){
vector<book> books;
loadFromFile(books);
int choice;
while(true){
cout<<"\n1. Add Book\n2. View Books\n3. Search Book\n4. Delete Book\n5. Issue book\n6. Return book\n7. Exit\n";
cout<<"enter choices:";
cin>>choice;
if(choice==1){
book b;
cout<<"enter id:";
cin>>b.id;
cin.ignore();
cout<<"enter title:";
getline(cin,b.title);
cout<<"enter author:";
getline(cin,b.author);
books.push_back(b);
savetofile(books);
}
else if(choice==2){
for(int i=0;i<books.size();i++){
books[i].display();
cout<<"-----\n";
}
}
else if(choice==3){
int searchid;
cout<<"enter book id to search";
cin>>searchid;
bool found=false;
for(int i=0;i<books.size();i++){
if(books[i].id==searchid){
books[i].display();
found=true;
break;
}
}
if(!found){
cout<<"book not found\n";
}
}
else if(choice==4){
int deleteid;
cout<<"enter bookid to delete:";
cin>>deleteid;
bool found=false;
for(int i=0;i<books.size();i++){
if(books[i].id==deleteid){
books.erase(books.begin()+i);
savetofile(books);
cout<<"book deleted successfully\n";
found=true;
break;
}
}
if(!found){
cout<<"book not found"<<endl;
}
}
else if(choice==5){
int id;
cout<<"Enter book ID to issue: ";
cin>>id;
bool found=false;
for(int i=0;i<books.size();i++){
if(books[i].id==id){
if(books[i].isissued){
cout<<"Book already issued\n";
} else {
books[i].isissued = true;
savetofile(books);
cout<<"Book issued successfully\n";
}
found=true;
break;
}
}
if(!found){
cout<<"Book not found\n";
}
}
else if(choice==6){
int id;
cout<<"Enter book ID to return: ";
cin>>id;
bool found=false;
for(int i=0;i<books.size();i++){
if(books[i].id==id){
if(!books[i].isissued){
cout<<"Book is already available\n";
} else {
books[i].isissued = false;
savetofile(books);
cout<<"Book returned successfully\n";
}
found=true;
break;
}
}
if(!found){
cout<<"Book not found\n";
}
}
else if(choice==7){
cout<<"exiting program"<<endl;
break;
}
}

return 0;
}
