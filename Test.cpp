#include "stdafx.h"
#include "Test.h"
#include "Fly2Elephant.h"

// constructor
Test::Test()
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    Test9();
    Test10();
    Test11();
}

// words file doesn't exist
void Test::Test1()
{
    Fly2Elephant f2e;
    vector<string> chain;
    string msg;

    bool res = f2e.Transform("dummy1", "dummy2", chain, msg);
    printf(!res ? "Test1:\tpassed\r\n" : "Test1:\tfailed\r\n");
}

// words file is empty
void Test::Test2()
{
    ofstream f("words");
    f.close();

    Fly2Elephant f2e;
    vector<string> chain;
    string msg;

    bool res = f2e.Transform("words", "dummy", chain, msg);
    printf(!res ? "Test2:\tpassed\r\n" : "Test2:\tfailed\r\n");

    remove("words");
}

// words file contains one word
void Test::Test3()
{
    ofstream f("words");
    f << "onlyword";
    f.close();

    Fly2Elephant f2e;
    vector<string> chain;
    string msg;

    bool res = f2e.Transform("words", "dummy", chain, msg);
    printf(!res ? "Test3:\tpassed\r\n" : "Test3:\tfailed\r\n");

    remove("words");
}

// words file contains words with different length
void Test::Test4()
{
    ofstream f("words");
    f << "word" << endl;
    f << "longword" << endl;
    f.close();

    Fly2Elephant f2e;
    vector<string> chain;
    string msg;

    bool res = f2e.Transform("words", "dummy", chain, msg);
    printf(!res ? "Test4:\tpassed\r\n" : "Test4:\tfailed\r\n");

    remove("words");
}

// words file contains equal words
void Test::Test5()
{
    ofstream f1("words");
    f1 << "word" << endl;
    f1 << "word" << endl;
    f1.close();

    ofstream f2("dict");
    f2 << "word" << endl;
    f2.close();

    Fly2Elephant f2e;
    vector<string> chain;
    string msg;

    bool res = f2e.Transform("words", "dict", chain, msg);
    res = res && chain.size() == 2 &&
                 chain[0].compare("word") == 0 &&
                 chain[1].compare("word") == 0;

    printf(res ? "Test5:\tpassed\r\n" : "Test5:\tfailed\r\n");

    remove("words");
    remove("dict");
}

// dictionary file doesn't exist
void Test::Test6()
{
    ofstream f1("words");
    f1 << "word1" << endl;
    f1 << "word2" << endl;
    f1.close();

    Fly2Elephant f2e;
    vector<string> chain;
    string msg;

    bool res = f2e.Transform("words", "dummy", chain, msg);
    printf(!res ? "Test6:\tpassed\r\n" : "Test6:\tfailed\r\n");

    remove("words");
}

// dictionary file is empty
void Test::Test7()
{
    ofstream f1("words");
    f1 << "word1" << endl;
    f1 << "word2" << endl;
    f1.close();

    ofstream f2("dict");
    f2.close();

    Fly2Elephant f2e;
    vector<string> chain;
    string msg;

    bool res = f2e.Transform("words", "dict", chain, msg);
    printf(!res ? "Test7:\tpassed\r\n" : "Test7:\tfailed\r\n");

    remove("words");
    remove("dict");
}

// words file contains word which is not present in dictionary
void Test::Test8()
{
    ofstream f1("words");
    f1 << "word1" << endl;
    f1 << "word2" << endl;
    f1.close();

    ofstream f2("dict");
    f2 << "word1" << endl;
    f2 << "word3" << endl;
    f2.close();

    Fly2Elephant f2e;
    vector<string> chain;
    string msg;

    bool res = f2e.Transform("words", "dict", chain, msg);
    printf(!res ? "Test8:\tpassed\r\n" : "Test8:\tfailed\r\n");

    remove("words");
    remove("dict");
}

// dictionary load/contains/find test
void Test::Test9()
{
    const size_t dict_size = 10;

    ofstream f("dict");
    for (size_t i = 0; i < dict_size; ++i)
        f << i << endl;
    f.close();

    Dictionary dict;
    string msg;
    bool res = dict.Load("dict", 1, msg);

    for (size_t i = 0; res && i < dict_size; ++i)
    {
        string str = to_string(i);
        res = dict.Contains(str);

        Dictionary::DictionaryData::iterator di;
        res = res && dict.Find(str, di);
        res = res && di->first.compare(str) == 0;
        res = res && di->second == false;
    }

    printf(res ? "Test9:\tpassed\r\n" : "Test9:\tfailed\r\n");

    remove("dict");
}

// transform test
void Test::Test10()
{
    ofstream f1("words");
    f1 << "shit" << endl;
    f1 << "gold" << endl;
    f1.close();

    ofstream f2("dict");
    f2 << "money" << endl;
    f2 << "bolt" << endl;
    f2 << "shot" << endl;
    f2 << "death" << endl;
    f2 << "stack" << endl;
    f2 << "shit" << endl;
    f2 << "bold" << endl;
    f2 << "sense" << endl;
    f2 << "c" << endl;
    f2 << "soot" << endl;
    f2 << "gold" << endl;
    f2 << "boot" << endl;
    f2.close();

    Fly2Elephant f2e;
    vector<string> chain;
    string msg;

    bool res = f2e.Transform("words", "dict", chain, msg);
    res = res && chain.size() == 7 &&
                 chain[0].compare("shit") == 0 &&
                 chain[1].compare("shot") == 0 &&
                 chain[2].compare("soot") == 0 &&
                 chain[3].compare("boot") == 0 &&
                 chain[4].compare("bolt") == 0 &&
                 chain[5].compare("bold") == 0 &&
                 chain[6].compare("gold") == 0;
    printf(res ? "Test10:\tpassed\r\n" : "Test10:\tfailed\r\n");

    remove("words");
    remove("dict");
}

// impossible transform test
// transform test
void Test::Test11()
{
    ofstream f1("words");
    f1 << "array" << endl;
    f1 << "queue" << endl;
    f1.close();

    ofstream f2("dict");
    f2 << "array" << endl;
    f2 << "stack" << endl;
    f2 << "queue" << endl;
    f2 << "vector" << endl;
    f2 << "heap" << endl;
    f2 << "tree" << endl;
    f2 << "trie" << endl;
    f2 << "hash" << endl;
    f2.close();

    Fly2Elephant f2e;
    vector<string> chain;
    string msg;

    bool res = f2e.Transform("words", "dict", chain, msg);
    printf(!res ? "Test10:\tpassed\r\n" : "Test10:\tfailed\r\n");

    remove("words");
    remove("dict");
}
