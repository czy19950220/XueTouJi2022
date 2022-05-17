#include "statusvalue.h"

bool StatusValue::bloodPumpStatue = false;
int StatusValue::currentPage = 0;
int StatusValue::currentPageProcess = 0;
StatusValue::StatusValue(QObject *parent) : QObject(parent)
{

}

