#ifndef ICPSPYDER_H
#define ICPSPYDER_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class ICPSpyder
{
public:
    bool GetInfo(string url)
    {
        vector<string> strResults = Match(HttpGet(url));
        write(strResults);
        return true;
    }
protected:
    virtual string HttpGet(string url)
    {
        string str;
        cout << " ICPSpyder::HttpGet " << endl;
        return str;
    }

    virtual vector<string> Match(string html)
    {
        vector<string> v;
        cout << " ICPSpyder::Match " << endl;
        return v;
    }

    virtual bool write(vector<string> content)
    {
        cout << " ICPSpyder" << endl;
        return true;
    }
};

#endif // ICPSPYDER_H
