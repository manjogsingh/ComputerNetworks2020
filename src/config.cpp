#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <sstream>

using namespace std;

struct configpeer{
    int peerId;
    string hostname;
    int listport;
    bool havefile;
} confp;

struct configcommon{
    int noprfnbrs;
    int unchokint;
    int optunchokint;
    string filename;
    long filesize;
    int piecesize;
} conf;

vector<string> split (string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}

int main()
{  
//Parsing Peer Info Config file
 std::ifstream pFile ("samplePeerInfo.cfg");
    if(pFile.is_open())
    {
        string delimiter=" ";
        size_t pos = 0;
        while(pFile.good()){
            string line;
            getline(pFile,line);
            vector<string> v = split(line, delimiter);
            confp.peerId=stoi(v[0]);
            confp.hostname=v[1];
            confp.listport=stoi(v[2]);
            int hfile=stoi(v[3]);
            (hfile==1) ? confp.havefile=true : confp.havefile=false;
        }
    }
    else 
    {
        std::cerr << "Couldn't open config file for reading.\n";
    }

//Parsing Common Config file    
 std::ifstream cFile ("sampleCommon.cfg");
    if (cFile.is_open())
    {
        string delimiter=" ";
        size_t pos = 0;
        string token1,token2;

        while(cFile.good()){
            string line;
            getline(cFile,line);
            pos=line.find(delimiter);
            token1=line.substr(0,pos);
            token2=line.substr(pos+1,line.length());
            
                if(token1.compare("NumberOfPreferredNeighbors")==0){
                    conf.noprfnbrs=stoi(token2); 
                }
                else if(token1.compare("UnchokingInterval")==0)
                {
                    conf.unchokint=stoi(token2); 
                }
                else if(token1.compare("OptimisticUnchokingInterval")==0)
                {
                    conf.optunchokint=stoi(token2); 
                }
                else if(token1.compare("FileName")==0)
                {
                    conf.filename=token2; 
                }
                else if(token1.compare("FileSize")==0)
                {
                    conf.filesize=stoi(token2); 
                }
                else{
                    conf.piecesize=stoi(token2); 
                }
        }
    }
    else 
    {
        std::cerr << "Couldn't open config file for reading.\n";
    }
}

