#include <chkRanges.h>

int main()
{
    assert(*(chkrange+4) == 3);
    assert(*(chkrange+5) == 5);
    assert(*(chkrange+6) == 4);
    assert(*(chkrange+11) == 2);  
    return 0;
}
