//Input
using namespace std;
string line;
cin.ignore() // only once before first getline and after last cin
getline(cin,line);



//output
cout << setprecision(5);	//Set decimal precision (function)
cout << fixed;     // write floating-point values in fixed-point notation. 2006.00000
cout << scientific; // write floating-point values in scientific notation. 2.00600e+003

cout << setfill('*');	//Set fill character (function)
cout << setw(6);	//Set field width (function)
cout.width(6);
cout << internal << -77; //-***77
cout << left     << -77; //-77***
cout << right    << -77; //***-77

// To split string on a space
string str = "Placeholder Text", tmp;
stringstream ss(str);
while(getline(ss, s1, ' ')) {
    cout << s1 << '\n';
}
