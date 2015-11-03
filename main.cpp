#include "stdafx.h"
#include "Fly2Elephant.h"

void print_vector(const vector<string> &chain)
{
    for (vector<string>::const_iterator i = chain.begin(); i != chain.end(); ++i)
        printf("%s\r\n", i->c_str());
}

#ifndef TEST
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("usage: f2e <source words file path> <dictionary file path>\r\n");
        return 0;
    }

    // do transformation
    vector<string> chain;
    string msg;

    Fly2Elephant f2e;
    bool res = f2e.Transform(argv[1], argv[2], chain, msg);

    // print result
    if (res)
        print_vector(chain);
    else
    {
        printf("failed to transform words");
        if (!msg.empty())
            printf(": %s", msg.data());
        printf("\r\n");
    }

    return res ? 0 : 255;
}
#else
#include "Test.h"

int main(int, char**)
{
    Test test;
    return 0;
}
#endif
