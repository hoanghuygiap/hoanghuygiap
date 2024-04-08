#include <bits/stdc++.h>
using namespace std;
struct Person{
    string fullname;
    Person* right = NULL;
    Person* left = NULL;
    Person(string fn){
        fullname = fn;
    }
};
void Print(Person* person){
    cout << "Hang xom cua " << person->fullname << " la: ";
    if(person->right != NULL && person->left == NULL){
        cout << person->right->fullname;
    }
    else if(person->left != NULL && person->right == NULL ){
        cout << person->left->fullname;
    }
    else{
        cout <<  person->right->fullname << " and " << person->left->fullname;
    }
}
bool Check(Person* person1,Person* person2){
    if(person1->right == person2 || person1->left == person2){
        return true;
    }
    else{
        return false;
    }
}
void Check_index(Person* person){
    if(person->left == NULL && person->right != NULL){
        cout << person->fullname << " vi tri dau xom ";
    }
    else if(person->right == NULL && person->left != NULL){
        cout << person->fullname << "  vi tri cuoi xom";
    }
    else if(person->left != NULL &&person->right != NULL){
        cout << person->fullname << " Giua xom"; 
    }
    else{
        cout << "Khong co trong xom";
    }
}
int main()
{
     Person* vu = new Person("VU");
     Person* ozawa = new Person("OZAWA");
     Person* ngoc_trinh = new Person("Ngoc Trinh");
     Person* Son_tung = new Person("Son Tung MTP");
     Person* Giap  = new Person("Hoang Huy Giap");
     {
        vu->right = ozawa;
        vu->left = NULL;
        ozawa->right = ngoc_trinh;
        ozawa->left = vu;
        ngoc_trinh->right = Son_tung;
        ngoc_trinh->left = ozawa;
        Son_tung->right = NULL;
        Son_tung->left = ngoc_trinh;
        Giap->right = NULL;
        Giap->left  = NULL;
     }
     {
        cout << "Test 1. Hang xom cua ban la " << endl;
        cout << "\t";Print(vu);cout << "\n";
        cout << "\t";Print(ozawa);cout << "\n";
        cout << "\t";Print(Son_tung);cout << endl;
     }
     {
        cout <<"\n Test 2. Kiem tra hang xom:\n";
        cout << "\t" << Check(vu,ozawa) << "\n ";
        cout << "\t" << Check(ozawa,Son_tung) << "\n";
     }
     {
        cout << "Kiem tra vi tri trong xom: " << endl;
        cout << "\t";Check_index(vu);
        cout << "\n\t";Check_index(ozawa);
        cout << "\n\t";Check_index(ngoc_trinh);
        cout << "\n\t";Check_index(Son_tung);
        cout << "\n\t";Check_index(Giap);
     }

}