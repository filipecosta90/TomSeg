#include "sliceinfo.h"

SliceInfo::SliceInfo()
{

}

SliceInfo::SliceInfo(QString fileName)
{
    this->fileName = fileName;
    this->image = QPixmap (fileName);
}