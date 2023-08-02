// debug to error stream
//Warning!
//Printing too much content to the error stream can cause TLE when submitting to an OJ.
#define dbg(v)                                                                 \
	cerr << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;


//Checking for Out of Bounds
// use vector::at() instead of vector::operator[]

//slice a container in debugger watch
// (int[6])*arr

//timing your program
auto start = chrono::steady_clock::now();
//  Insert the code that will be timed
auto end = chrono::steady_clock::now();
// Store the time difference between start and end
auto diff = end - start;
cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;

