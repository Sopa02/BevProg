
#include "../std_lib_facilities.h" 

/*----------------------------------------------------------------------------------------------------------------------------------*/

int main(){
	string first_name;
	string friend_name;
	int age;
	char friend_sex = '0';
	cout << "Enter your first name:\n";
	cin >> first_name;
	cout << "Hello "<<first_name<<"!\n";
	cout << "Enter the name of the person you're writing to:\n";
	cin >> first_name;
	cout << "Dear " <<first_name<<",\n";
	cout << "How are you?, I am fine. I miss u. Life is hard.\n";
	cout << "\nEnter the name of another friend:\n";
	cin >> friend_name;
	cout << "Have you seen " <<friend_name<<" lately?\n";
	cout << " \nEnter 'm' if he is a he, or enter 'f' is she is a she!\n";
	cin >> friend_sex;

	if(friend_sex == 'm')
		cout<<"If you see "<<friend_name<<" please ask him to call me.";
	else if(friend_sex == 'f')
		cout<<"If you see "<<friend_name<<" please ask her to call me.";

	cout<<"\nEnter the age of the recipient:\n";
	cin>>age;
	if(age <= 0 || age >= 110)
		simple_error("You're kidding!");
	
	if(age<12)
		cout<<"Next year you'll be "<<age+1<<".\n";
	else if(age==17)
		cout<<"Next year you'll be able to vote!\n";
	else if(age>70)
		cout<<"I hope you're enjoying retirement!\n";

	cout<<"Yours sincerely, \n\n\n"<<first_name<<".\n"; 



	return 0;
}
