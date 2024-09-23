#include <QCoreApplication>
#include <iostream>

#include "Context.h"

using namespace std;

int main(int argc, char *argv[])
{
    string strInput = "九亿八千七百六十五万四千三百二十一";
    Context context(strInput);

    vector<Expression*> tree;
    GeExpression g;
    ShiExpression s;
    BaiExpression b;
    QianExpression q;
    WanExpression w;
    YiExpression y;
    tree.push_back(&g);
    tree.push_back(&s);
    tree.push_back(&b);
    tree.push_back(&q);
    tree.push_back(&w);
    tree.push_back(&y);

    for (auto& i : tree)
    {
        i->Interpret(context);
    }
    cout << context.GetData() << endl;
}
