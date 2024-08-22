#include <QCoreApplication>
#include "ComputerBuilder.h"
#include "DellComputerBuilder.h"
#include "LenevoComputerBuilder.h"

class Director
{
public:
    Computer BuildComputer(ComputerBuilder& builder)
    {
        // Stable logic
        builder.BuildCPU();
        builder.BuildMemory();
        builder.BuildStorage();

        return builder.CreateComputer();
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Director d;
    LenevoComputerBuilder pcBuilder;
    Computer pc = d.BuildComputer(pcBuilder);
    pc.Show();

    cout << endl;
    DellComputerBuilder pcBuilder2;
    Computer pc2 = d.BuildComputer(pcBuilder2);
    pc2.Show();
    return a.exec();
}
