#include <iostream>
#include <fstream>
using namespace std;

// int main(){
//     ofstream fout;//create object of ofstream (Class)
//     fout.open("zoom.txt");//if the file with this name is prsent it will open it, otherwise it will create it .
//     fout<<"helllllo";
//     fout.close();
// }

// int main()
// {
//     ifstream fin;
//     fin.open("zoom.txt");
//     char C;
//     C = fin.get();
//     while (!fin.eof())
//     {
//         cout << C;
//         C = fin.get();
//     }
//     fin.close();
// }

int main(){
    int arr[5];
    cout<<"Enter the input : "<<endl;
    for (int i = 0; i < 5; i++)
        cin>>arr[i];
    

    ofstream fout;
    fout.open("zero.txt");

    for (int i = 0; i < 5; i++)
    {
       fout<<arr[i];
    }
    
    fout.close();
}