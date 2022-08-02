#include "chkRanges.h"

int main()
{
    chkrange();
    assert(rangeCount[0] == 4);
    assert(rangeCount[1] == 3);
    assert(rangeCount[2] == 1);
    //(*(rangeCount+) == 2);  
    return 0;
}
