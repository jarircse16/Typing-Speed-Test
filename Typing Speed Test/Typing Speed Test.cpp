#include<bits/stdc++.h>
using namespace std;
int main ()
{

    //Clock starts running, user is prompted to enter the text on-screen

    clock_t start, end;
    start = clock(); // clcck starts
    cout<< "Enter the following text as much as you can and as fast as you can: \n \n";
    string sentence; // user input string

    //Program "reads" test.text through file streaming, clock still running

    string line; // string loaded from file
    ifstream myfile ("test.txt");
    if (myfile.is_open())
    {
    while ( myfile.good() )
    {
      getline (myfile,line);
      cout << line << endl;
    //Code for data input, clock still running, this and above are visible to user from the start-up of the program
      cout<<"\n";
     p: getline(cin, sentence);
    //Code to determine input accuracy


    }
    myfile.close();
    }
    //Clock ends running, data gathered is displayed to user

    end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC; //calculating how many seconds by dividing the clock time by cpu clock per second
    cout << "\nTyping the sentence took " << seconds << " seconds.\n \n";

    int r=0; //space counter
    for (int i=0; i<sentence.size(); i++)
    {
        if (isspace(sentence[i])!=0)
            r++;
    }
    cout<<"Your typing speed is "<<((r+1)/seconds) <<" words per  second or "<< ((r+1)/seconds)*60<< " words per minute. \n \n";

    int error=0;
    if(line.size()>sentence.size())
        {
            for(int i=0;i<sentence.size();i++)
                    {
                    if(line[i]!=sentence[i])
                        error++;
                    }
        }
    else if(line.size()==sentence.size())
        {

            for(int p=0;p<line.size();p++)
                    if(line[p]!=sentence[p])
                        error++;
        }
    else
    {
        cout<<"Please donot cross the input size"<<endl;
        cout<<endl;
        goto p;
    }

    int total_accuracy= line.size()*100 - error*100;
    float accuracy = total_accuracy/line.size();


    cout<< setprecision(2)<< fixed; //to show 2 decimal points
    cout<<"Your typing accuracy is "<<accuracy<<" % "<<endl;

    system("PAUSE"); // pause for a character input
    return EXIT_SUCCESS; // program terminated successfully

    //end of program
}
