#ifndef MYICPSPYDER_H
#define MYICPSPYDER_H
#include "ICPSpyder.h"

class MyICPSpyder : public ICPSpyder
{
protected:
    // Mutable Methods
    virtual string HttpGet(string url)
    {
        string str;
        cout << " MyICPSpyder::HtpGet " << endl;
        return str;
    }
    virtual vector<string> Match(string html)
    {
        vector<string> v;
        cout << " MyICPSpyder::Match " << endl;
        return v;
    }

    virtual bool Write(vector<string> content)
    {
        cout << " MyICPSpyder::Write" << endl;
        return true;
    }
};

#endif // MYICPSPYDER_H
