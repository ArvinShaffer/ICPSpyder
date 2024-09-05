#ifndef INTERNETACCESS_H
#define INTERNETACCESS_H
#include <string>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <functional>
using namespace std;

class InternetAccess
{
public:
    virtual void ConnectTo(const string& serverHost) = 0;
};

class RealInterAccess : public InternetAccess
{
public:
    virtual void ConnectTo(const string& serverHost)
    {
        cout << "Connect to " << serverHost << endl;
    }
};

class RealInterAccess2 : public InternetAccess
{
public:
    virtual void ConnectTo(const string& serverHost)
    {
        cout << "RealInterAccess2 Connect to " << serverHost << endl;
    }
};

// Indirect layer proxy
class ProxyAccess : public InternetAccess
{
private:
    InternetAccess* m_pRealAccess;
    static vector<string> m_bannedSites;
public:
    ProxyAccess(InternetAccess* realInternet) :m_pRealAccess(realInternet){}
    virtual void ConnectTo(const string& serverHost)
    {
        // check the host is accessabile
        if(isCanAccessed(serverHost))
        {
            m_pRealAccess->ConnectTo(serverHost);
        }
        else
        {
            throw runtime_error("Access Denied: " + serverHost);
        }
    }
private:
    bool isCanAccessed(const string& serverHost)
    {
        for (const string& bannedSite: m_bannedSites)
        {
            if (serverHost.find(bannedSite) != string::npos)
            {
                return false;
            }
        }
        return true;
    }
};

// Dynamic indirect layer proxy class
class DynamicProxyAccess : public InternetAccess
{
private:
    function<void(const string& serverHost)> m_realFunction;
    static vector<string> m_bannedSites;
public:
    DynamicProxyAccess(const function<void(const string&)>& fun) :m_realFunction(fun){}
    virtual void ConnectTo(const string& serverHost)
    {
        // check the host is accessabile
        if (isCanAccessed(serverHost))
        {
            m_realFunction(serverHost);
        }
        else
        {
            throw runtime_error("Access Denied: " + serverHost);
        }
    }
private:
    bool isCanAccessed(const string& serverHost)
    {
        for (const string& bannedSite : m_bannedSites)
        {
            if (serverHost.find(bannedSite) != string::npos)
            {
                return false;
            }
        }
        return true;
    }
};

// virtual indirect layer proxy class
class VirtualProxyAccess : public InternetAccess
{
private:
    InternetAccess* m_pRealAccess;
    static vector<string> m_bannedSites;
public:
    VirtualProxyAccess() : m_pRealAccess(nullptr) {}
    virtual void ConnectTo(const string& serverHost)
    {
        // check the host is accessabile
        if (isCanAccessed(serverHost))
        {
            if (m_pRealAccess == nullptr)
            {
                m_pRealAccess = new RealInterAccess();
            }
            m_pRealAccess->ConnectTo(serverHost);
        }
        else
        {
            throw runtime_error("Access Denied: " + serverHost);
        }
    }
    virtual ~VirtualProxyAccess()
    {
        if (m_pRealAccess != nullptr)
        {
            delete m_pRealAccess;
        }
    }
private:
    bool isCanAccessed(const string& serverHost)
    {
        for (const string& bannedSite : m_bannedSites)
        {
            if (serverHost.find(bannedSite) != string::npos)
            {
                return false;
            }
        }
        return true;
    }
};

#endif // INTERNETACCESS_H
