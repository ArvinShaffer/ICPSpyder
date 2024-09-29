#include <iostream>
#include "Approve.h"
using namespace std;

int main(int argc, char *argv[])
{
    Approve teamBuildingBudget("Tom", ApproType::Budget);
    Approve shortVacation("Jim", ApproType::ShortVacation);
    Approve resign("Tom", ApproType::Resign);
    Approve longVacation("Tom", ApproType::LongVacation);

    DepartmentManager deartmentManagerD("MangerD");
    HRManager deartmentManagerH("MangerH");
    President president("presidentA");
    deartmentManagerD.SetNextApprover(&deartmentManagerH);
    deartmentManagerH.SetNextApprover(&president);

    deartmentManagerD.ProcessRequest(teamBuildingBudget);
    deartmentManagerD.ProcessRequest(shortVacation);
    deartmentManagerD.ProcessRequest(resign);
    deartmentManagerD.ProcessRequest(longVacation);

    return 0;
}
