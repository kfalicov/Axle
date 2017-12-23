#ifndef _UTILS
#define _UTILS

// found on https://www.geeksforgeeks.org/how-to-find-size-of-array-in-cc-without-using-sizeof-operator/
#define my_sizeof(type) ((char *)(&type+1)-(char*)(&type))

#endif
