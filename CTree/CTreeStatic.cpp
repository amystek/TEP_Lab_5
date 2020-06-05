#include "CTreeStatic.h"

CTreeStatic::CNodeStatic::~CNodeStatic()
{
    //default destructor is enough
} //CNodeStatic::~CNodeStatic()

void CTreeStatic::CNodeStatic::vAddNewChild()
{
    CNodeStatic cNewNode;
    cNewNode.pc_parent = this;
    v_children.push_back(cNewNode);
} //void CNodeStatic::vAddNewChild()

CTreeStatic::CNodeStatic *CTreeStatic::CNodeStatic::pcGetChild(int iChildOffset)
{
    if (iChildOffset < 0 or iChildOffset > iGetChildrenNumber())
    {
        return NULL;
    } //if (iChildOffset < 0 or iChildOffset > iGetChildrenNumber())

    return &v_children.at(iChildOffset);
} ////CNodeStatic *CNodeStatic::pcGetChild(int iChildOffset)

void CTreeStatic::CNodeStatic::vPrintAllBelow()
{
    vPrint();
    for (vector<CNodeStatic>::iterator i = v_children.begin(); i != v_children.end(); i++)
    {
        i -> vPrintAllBelow();
    } //for (vector<string>::iterator i = sText.begin(); i != sText.end(); i++)
} //void CNodeStatic::vPrintAllBelow()

void CTreeStatic::CNodeStatic::vPrintUp()
{
    vPrint();
    if (pc_parent != NULL)
    {
        pc_parent -> vPrintUp();
    } //if (pc_parent != NULL)
} //void CNodeStatic::vPrintUp()

void CTreeStatic::v_tree_test()
{
    //CNodeStatic c_root;
    c_root.vAddNewChild();
    c_root.vAddNewChild();
    c_root.pcGetChild(0)->vSetValue(1);
    c_root.pcGetChild(1)->vSetValue(2);
    c_root.pcGetChild(0)->vAddNewChild();
    c_root.pcGetChild(0)->vAddNewChild();
    c_root.pcGetChild(0)->pcGetChild(0)->vSetValue(11);
    c_root.pcGetChild(0)->pcGetChild(1)->vSetValue(12);
    c_root.pcGetChild(1)->vAddNewChild();
    c_root.pcGetChild(1)->vAddNewChild();
    c_root.pcGetChild(1)->pcGetChild(0)->vSetValue(21);
    c_root.pcGetChild(1)->pcGetChild(1)->vSetValue(22);

    //c_root.pcGetChild(0)->pcGetChild(1)->vPrintUp();
} //void v_tree_test()

void CTreeStatic::vPrintTree()
{
    c_root.vPrintAllBelow();
} //void CTreeStatic::vPrintTree()

