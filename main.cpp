#include "main.h"

int main()
{
//    vStaticTreeTest();
//    vDynamicTreeTest();
    vMoveSubTreeStatic();
    vMoveSubTreeDynamic();
    return 0;
} //int main()

void vStaticTreeTest()
{
    cout << endl << "vStaticTreeTest()" << endl;
    CTreeStatic c_tree_stat;
    c_tree_stat.pcGetRoot()->vAddNewChild();
    c_tree_stat.pcGetRoot()->vAddNewChild();
    c_tree_stat.pcGetRoot()->pcGetChild(0)->vSetValue(1);
    c_tree_stat.pcGetRoot()->pcGetChild(1)->vSetValue(2);
    c_tree_stat.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    c_tree_stat.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    c_tree_stat.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(11);
    c_tree_stat.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(12);
    c_tree_stat.pcGetRoot()->pcGetChild(1)->vAddNewChild();
    c_tree_stat.pcGetRoot()->pcGetChild(1)->vAddNewChild();
    c_tree_stat.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(21);
    c_tree_stat.pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue(22);
    c_tree_stat.vPrintTree();
} //void vStaticTreeTest()

void vDynamicTreeTest()
{
    cout << endl << "vDynamicTreeTest()" << endl;
    CTreeDynamic c_tree_dyn;
    c_tree_dyn.pcGetRoot()->vAddNewChild();
    c_tree_dyn.pcGetRoot()->vAddNewChild();
    c_tree_dyn.pcGetRoot()->pcGetChild(0)->vSetValue(1);
    c_tree_dyn.pcGetRoot()->pcGetChild(1)->vSetValue(2);
    c_tree_dyn.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    c_tree_dyn.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    c_tree_dyn.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(11);
    c_tree_dyn.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(12);
    c_tree_dyn.pcGetRoot()->pcGetChild(1)->vAddNewChild();
    c_tree_dyn.pcGetRoot()->pcGetChild(1)->vAddNewChild();
    c_tree_dyn.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(21);
    c_tree_dyn.pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue(22);
    c_tree_dyn.vPrintTree();
} //void vDynamicTreeTest()

void vMoveSubTreeStatic()
{
    cout << endl << "vMoveSubTreeTest() - static nodes" << endl;
    CTreeStatic c_tree_stat1, c_tree_stat2;

    c_tree_stat1.pcGetRoot()->vAddNewChild();
    c_tree_stat1.pcGetRoot()->vAddNewChild();
    c_tree_stat1.pcGetRoot()->vAddNewChild();
    c_tree_stat1.pcGetRoot()->pcGetChild(0)->vSetValue(1);
    c_tree_stat1.pcGetRoot()->pcGetChild(1)->vSetValue(2);
    c_tree_stat1.pcGetRoot()->pcGetChild(2)->vSetValue(3);
    c_tree_stat1.pcGetRoot()->pcGetChild(2)->vAddNewChild();
    c_tree_stat1.pcGetRoot()->pcGetChild(2)->pcGetChild(0)->vSetValue(4);

    c_tree_stat2.pcGetRoot()->vSetValue(50);
    c_tree_stat2.pcGetRoot()->vAddNewChild();
    c_tree_stat2.pcGetRoot()->vAddNewChild();
    c_tree_stat2.pcGetRoot()->pcGetChild(0)->vSetValue(54);
    c_tree_stat2.pcGetRoot()->pcGetChild(1)->vSetValue(55);
    c_tree_stat2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    c_tree_stat2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    c_tree_stat2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(56);
    c_tree_stat2.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(57);
    c_tree_stat2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vAddNewChild();
    c_tree_stat2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->pcGetChild(0)->vSetValue(58);

    cout << "Before moving subtree" << endl;
    c_tree_stat1.vPrintTree();
    c_tree_stat2.vPrintTree();

    c_tree_stat1.bMoveSubtree(c_tree_stat1.pcGetRoot()->pcGetChild(2), c_tree_stat2.pcGetRoot()->pcGetChild(0));
    cout << endl << "After moving subtree" << endl;

    c_tree_stat1.vPrintTree();
    c_tree_stat2.vPrintTree();

} //void vMoveSubTreeTest()

void vMoveSubTreeDynamic()
{
    cout << endl << "vMoveSubTreeTest() - dynamic nodes" << endl;
    CTreeDynamic c_tree_dyn1, c_tree_dyn2;

    c_tree_dyn1.pcGetRoot()->vAddNewChild();
    c_tree_dyn1.pcGetRoot()->vAddNewChild();
    c_tree_dyn1.pcGetRoot()->vAddNewChild();
    c_tree_dyn1.pcGetRoot()->pcGetChild(0)->vSetValue(1);
    c_tree_dyn1.pcGetRoot()->pcGetChild(1)->vSetValue(2);
    c_tree_dyn1.pcGetRoot()->pcGetChild(2)->vSetValue(3);
    c_tree_dyn1.pcGetRoot()->pcGetChild(2)->vAddNewChild();
    c_tree_dyn1.pcGetRoot()->pcGetChild(2)->pcGetChild(0)->vSetValue(4);

    c_tree_dyn2.pcGetRoot()->vSetValue(50);
    c_tree_dyn2.pcGetRoot()->vAddNewChild();
    c_tree_dyn2.pcGetRoot()->vAddNewChild();
    c_tree_dyn2.pcGetRoot()->pcGetChild(0)->vSetValue(54);
    c_tree_dyn2.pcGetRoot()->pcGetChild(1)->vSetValue(55);
    c_tree_dyn2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    c_tree_dyn2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    c_tree_dyn2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(56);
    c_tree_dyn2.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(57);
    c_tree_dyn2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vAddNewChild();
    c_tree_dyn2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->pcGetChild(0)->vSetValue(58);

    cout << "Before moving subtree" << endl;
    c_tree_dyn1.vPrintTree();
    c_tree_dyn2.vPrintTree();

    CTreeDynamic::CNodeDynamic *pcParent = c_tree_dyn1.pcGetRoot()->pcGetChild(2);
    CTreeDynamic::CNodeDynamic *pcChild = c_tree_dyn2.pcGetRoot()->pcGetChild(0);
    c_tree_dyn1.bMoveSubtree(pcParent , pcChild);
    cout << endl << "After moving subtree" << endl;

    c_tree_dyn1.vPrintTree();
    c_tree_dyn2.vPrintTree();


} //void vMoveSubTreeDynamic()



