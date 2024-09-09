#include <QCoreApplication>
#include <iostream>
#include <map>
#include <memory>
using namespace std;

class FontFormat
{
public:
    virtual void ApplyFormat() = 0;
};

class EFontFormat : public FontFormat
{
public:
    virtual void ApplyFormat()
    {
        cout << "Applying E format" << endl;
    }
};

class NormalFormat : public FontFormat
{
public:
    virtual void ApplyFormat()
    {
        cout << "Applying Normal format" << endl;
    }
};

class FontFormatFactory
{
private:
    map<char, shared_ptr<FontFormat>> m_FontPool;
public:
    shared_ptr<FontFormat> GetFont(char key)
    {
        if (m_FontPool.find(key) == m_FontPool.end())
        {
            if (key == 'e')
            {
                m_FontPool[key] = make_shared<EFontFormat>();
            }
            else
            {
                m_FontPool[key] = make_shared<NormalFormat>();
            }
        }
        return m_FontPool[key];
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    FontFormatFactory fontFactory;
    char text[] = "This sentence is for test";
    for (int i = 0; text[i] != '\0'; i++)
    {
        shared_ptr<FontFormat> format = fontFactory.GetFont(text[i]);
        format->ApplyFormat();
    }
    return a.exec();
}








