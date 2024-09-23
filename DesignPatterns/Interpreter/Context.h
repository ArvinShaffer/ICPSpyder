#ifndef CONTEXT_H
#define CONTEXT_H
#include <string>
#include <map>
#include <vector>
using namespace std;

class Context
{
public:
    Context() = default;
    Context(const string& input) : m_inputString(input), m_data(0) {}

    string GetInputStr() const
    {
        return m_inputString;
    }

    void SetInputStr(const string& input)
    {
        m_inputString = input;
    }

    int GetData() const
    {
        return m_data;
    }

    void SetData(int data)
    {
        m_data = data;
    }
private:
    string m_inputString;
    int m_data;
};

class Expression
{
public:
    Expression()
    {
        m_table.insert(make_pair("零", 0));
        m_table.insert(make_pair("一", 1));
        m_table.insert(make_pair("二", 2));
        m_table.insert(make_pair("三", 3));
        m_table.insert(make_pair("四", 4));
        m_table.insert(make_pair("五", 5));
        m_table.insert(make_pair("六", 6));
        m_table.insert(make_pair("七", 7));
        m_table.insert(make_pair("八", 8));
        m_table.insert(make_pair("九", 9));
    }

    virtual void Interpret(Context& context)
    {
        // form right to left
        if (context.GetInputStr().length() == 0)
        {
            return ;
        }
        for (const auto& p:m_table)
        {
            size_t found = context.GetInputStr().rfind(p.first + GetPostfix());
            if (
                found != string::npos &&
                found == (context.GetInputStr().length() - (p.first + GetPostfix()).length())
                )
            {
                context.SetData(context.GetData() + p.second * GetMultiplier());
                context.SetInputStr(context.GetInputStr().substr(0, context.GetInputStr().length() - (p.first + GetPostfix()).length()));
            }
        }
    }

    virtual string GetPostfix() const = 0;

    virtual int GetMultiplier() const = 0;
protected:
    map<string, int> m_table;
};

class GeExpression:public Expression
{
public:
    virtual string GetPostfix() const
    {
        return "";
    }

    virtual int GetMultiplier() const
    {
        return 1;
    }
};

class ShiExpression:public Expression
{
public:
    virtual string GetPostfix() const
    {
        return "十";
    }

    virtual int GetMultiplier() const
    {
        return 10;
    }
};

class BaiExpression:public Expression
{
public:
    virtual string GetPostfix() const
    {
        return "百";
    }

    virtual int GetMultiplier() const
    {
        return 100;
    }
};

class QianExpression:public Expression
{
public:
    virtual string GetPostfix() const
    {
        return "千";
    }

    virtual int GetMultiplier() const
    {
        return 1000;
    }
};

class WanExpression:public Expression
{
public:
    virtual string GetPostfix() const
    {
        return "万";
    }

    virtual int GetMultiplier() const
    {
        return 10000;
    }

    virtual void Interpret(Context& context)
    {
        if (context.GetInputStr().length() == 0)
        {
            return;
        }

        vector<Expression*> tree;
        GeExpression g;
        ShiExpression s;
        BaiExpression b;
        QianExpression q;
        tree.push_back(&g);
        tree.push_back(&s);
        tree.push_back(&b);
        tree.push_back(&q);

        for (const auto& pair : m_table) {
            size_t found = context.GetInputStr().rfind(pair.first + GetPostfix());

            if (
                found != std::string::npos &&
                found == (context.GetInputStr().length() - (pair.first + GetPostfix()).length())
                )
            {
                int tempData = context.GetData() + pair.second * GetMultiplier();
                context.SetData(0);
                context.SetInputStr(context.GetInputStr().substr(0, context.GetInputStr().length() - (pair.first + GetPostfix()).length()));

                for (auto& i : tree)
                {
                    i->Interpret(context);
                }
                context.SetData(tempData + context.GetData()*GetMultiplier());
            } // if end
        } // for end
    } // Interpret end
};

class YiExpression:public Expression
{
public:
    virtual string GetPostfix() const
    {
        return "亿";
    }

    virtual int GetMultiplier() const
    {
        return 100000000;
    }

    virtual void Interpret(Context& context)
    {
        if (context.GetInputStr().length() == 0)
        {
            return;
        }

        vector<Expression*> tree;
        GeExpression g;
        ShiExpression s;
        BaiExpression b;
        QianExpression q;
        WanExpression w;
        tree.push_back(&g);
        tree.push_back(&s);
        tree.push_back(&b);
        tree.push_back(&q);
        tree.push_back(&w);

        for (const auto& pair : m_table) {
            size_t found = context.GetInputStr().rfind(pair.first + GetPostfix());

            if (
                found != std::string::npos &&
                found == (context.GetInputStr().length() - (pair.first + GetPostfix()).length())
                )
            {
                int tempData = context.GetData() + pair.second * GetMultiplier();
                context.SetData(0);
                context.SetInputStr(context.GetInputStr().substr(0, context.GetInputStr().length() - (pair.first + GetPostfix()).length()));

                for (auto& i : tree)
                {
                    i->Interpret(context);
                }
                context.SetData(tempData + context.GetData()*GetMultiplier());
            } // if end
        } // for end
    } // Interpret end
};



#endif // CONTEXT_H
