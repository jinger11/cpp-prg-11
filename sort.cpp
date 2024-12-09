#include <iostream>
#include <string>

using namespace std;

struct SEIT {
    int roll_no;
    string name;
    double sgpa;
};

void bubblesort_roll_number(SEIT student[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(student[j].roll_no > student[j + 1].roll_no) {
                SEIT temp = student[j];
                student[j] = student[j + 1];
                student[j + 1] = temp;
            }
        }
    }
}

void insertionsort_name(SEIT student[],int n){

	for(int i=1;i<n;i++){
		string k=student[i].name;
		int j=i-1;
		while(j>=0 && student[j].name>k){
			SEIT temp=student[j];
			student[j]=student[i];
			student[i]=temp;
			j=j-1;
		}
	}
}

void display(struct SEIT student[], int n) {
    cout << "Roll No    Name        SGPA" << endl;
    for(int i = 0; i < n; i++) {
        cout << student[i].roll_no << "    " << student[i].name << "    " << student[i].sgpa << endl;
    }
}

void search_SGPA(struct SEIT student[],double sgpa,int n){
		int found=0;
	for(int i=0;i< n;i++){
		if(student[i].sgpa==sgpa){
			cout<<student[i].name<<endl;
			found++;
		}
	}
	if(found==0){
		cout<<"No student matching the sgpa";
	}
}

string binary_search(struct SEIT student[],string name,int n){
	int low=0;
	int high=n-1;
	int mid;
	while(low<high){
		mid=(low+high)/2;
		string temp=student[mid].name;
		if(temp==name){
			return temp;
		}
		else if(temp>name){
			high=mid-1;
		}else{
			low=mid+1;
		}
		return "No such student exist";
	}
}
int main() {
     int num_students = 3;
    SEIT student[num_students];
    
    for(int i = 0; i < num_students; i++) {
        cout << "Enter the roll number of student " << (i + 1) << " : ";
        cin >> student[i].roll_no;
        cout << "Enter the name of student " << (i + 1) << " : ";
        cin.ignore();
        getline(cin, student[i].name);
        cout << "Enter the SGPA of student " << (i + 1) << " : ";
        cin >> student[i].sgpa;
    }
/* problem 1

    bubblesort_roll_number(student, num_students);
    display(student, num_students);
*/
 //insertionsort_name(student,num_students);
 //display(student,num_students);
//search_SGPA(student,9.0,num_students);
binary_search(student,"Omkar",num_students);
    return 0;
}

