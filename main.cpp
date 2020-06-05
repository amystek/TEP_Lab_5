#include "main.h"

int main()
{
    vStaticTreeTest();
    vDynamicTreeTest();
    return 0;
} //int main()

void vStaticTreeTest()
{
    cout << endl << "vStaticTreeTest()" << endl;
    CTreeStatic c_tree_stat;
    c_tree_stat.v_tree_test();   //create test tree
    c_tree_stat.vPrintTree();
} //void vStaticTreeTest()

void vDynamicTreeTest()
{
    cout << endl << "vDynamicTreeTest()" << endl;
    CTreeDynamic c_tree_dyn;
    c_tree_dyn.v_tree_test();   //create test tree
    c_tree_dyn.vPrintTree();
} //void vDynamicTreeTest()

