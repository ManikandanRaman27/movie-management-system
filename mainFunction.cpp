#include<bits/stdc++.h>
using namespace std;

struct movie
{
    string title;
    string releaseYear;
    string director;
    string genre;
};

vector<movie> moviesSet;
int moviesCount = 0;

void addMovie();
void editMovie();
void deleteMovie();
void searchMovie();

int main()
{
    int ch;
    do{
        cout<<endl;
        cout<<"Add Movie    -> 1 "<<endl;
        cout<<"Delete Movie -> 2 "<<endl;
        cout<<"Edit Movie   -> 3 "<<endl;
        cout<<"Search Movie -> 4 "<<endl;
        cout<<"exit -> 5 "<<endl;
        cout<<"Choice : ";
        cin>>ch;
        cout<<endl;
        switch(ch)
        {
        case 1:
            addMovie();
            break;
        case 2:
            deleteMovie();
            break;
        case 3:
            //editMovie();
            break;
        case 4:
            //searchMovie();
            break;
        case 5:
            cout<<"Exiting ..."<<endl;
            break;
        default:
            continue;
        }
    }while(ch!=5);
    return 0;
}

void addMovie()
{
    movie temp;
    fflush(stdin);
    cout<<"Movie Name           : ";
    getline(cin,temp.title);
    fflush(stdin);
    cout<<"Movie Released Date  : ";
    cin>>temp.releaseYear;
    fflush(stdin);
    cout<<"Movie Director       : ";
    getline(cin,temp.director);
    fflush(stdin);
    cout<<"Movie Genre          : ";
    getline(cin,temp.genre);

    moviesSet.push_back(temp);
    moviesCount++;
    cout<<"\nMovie Added Successfully!"<<endl;
}
void deleteMovie()
{
    if (moviesSet.empty())
    {
        cout << "Movie List is empty!" << endl;
        return;
    }

    string respected;
    fflush(stdin);
    cout<<"Enter Specifies(Movie Name,Year,Genre,Director) : ";
    getline(cin,respected);
    bool found = false;
    for(int i=0;i<moviesCount;i++)
    {
        if(moviesSet[i].title==respected || moviesSet[i].releaseYear==respected ||
            moviesSet[i].director==respected || moviesSet[i].genre==respected)
            {
                int tmp=i;
                while(tmp<moviesCount-1)
                {
                    moviesSet[tmp]=moviesSet[tmp+1];
                    tmp++;
                }
                moviesSet.pop_back();
                moviesCount--;
                cout<<" Movie Deleted Successfully!"<<endl;
                found=true;
            }
    }
    if (!found)
    {
        cout << "No Movies Present From this Criteria! " << endl;
        return;
    }
}
