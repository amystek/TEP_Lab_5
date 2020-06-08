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

void CTreeStatic::CNodeStatic::vAddNewChild(CTreeStatic::CNodeStatic *pcNewChild)
{
    CNodeStatic c_NewNode;
    c_NewNode.vSetValue(pcNewChild->i_val);
    for (vector<CNodeStatic>::iterator ii = pcNewChild->v_children.begin(); ii != pcNewChild->v_children.end(); ii++)
    {
        c_NewNode.v_children.push_back(*ii);
    } //for (vector<CNodeStatic>::iterator ii = pcNewChild->v_children.begin(); ii != pcNewChild->v_children.end(); ii++)

    c_NewNode.pc_parent = this;
    v_children.push_back(c_NewNode);
} //void CTreeStatic::CNodeStatic::vAddNewChild(CTreeStatic::CNodeStatic *)

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
    for (vector<CNodeStatic>::iterator ii = v_children.begin(); ii != v_children.end(); ii++)
    {
        ii -> vPrintAllBelow();
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

void CTreeStatic::CNodeStatic::vEraseChild(CTreeStatic::CNodeStatic *pcChildToErase)
{
    if (pcChildToErase->pcGetParent() == NULL)
    {
        pcChildToErase = NULL;
        return;
    } //if (pcChildToErase->pcGetParent() == NULL)

    CNodeStatic* pc_ParentNode = pcChildToErase->pcGetParent();
    for (vector<CNodeStatic>::iterator ii = pc_ParentNode->v_children.begin(); ii != pc_ParentNode->v_children.end(); ii++)
    {
        if (&(*ii) == pcChildToErase)
        {
            pc_ParentNode->v_children.erase(ii);
        } //if (&(*ii) == pcChildToErase)
    } //for (vector<CNodeStatic>::iterator ii = pc_ParentNode->v_children.begin(); ii != pc_ParentNode->v_children.end(); ii++)
} //void CTreeStatic::CNodeStatic::vEraseChild(CTreeStatic::CNodeStatic *pcChildToErase)

void CTreeStatic::vPrintTree()
{
    c_root.vPrintAllBelow();
    cout << endl;
} //void CTreeStatic::vPrintTree()

bool CTreeStatic::bMoveSubtree(CTreeStatic::CNodeStatic *pcParentNode, CTreeStatic::CNodeStatic *pcNewChildNode)
{
    if (pcParentNode == NULL || pcNewChildNode == NULL) return false;
    if (pcParentNode == pcNewChildNode) return false;

    CNodeStatic *pc_tmp = pcNewChildNode;
    pcParentNode->vAddNewChild(pcNewChildNode);

    pcNewChildNode->vEraseChild(pcNewChildNode);

    return true;
} //bool CTreeStatic::bMoveSubtree(CTreeStatic::CNodeStatic *pcParentNode, CTreeStatic::CNodeStatic *pcNewChildNode)

//void CTreeStatic::v_tree_test()
//{
//    //CNodeStatic c_root;
//    c_root.vAddNewChild();
//    c_root.vAddNewChild();
//    c_root.pcGetChild(0)->vSetValue(1);
//    c_root.pcGetChild(1)->vSetValue(2);
//    c_root.pcGetChild(0)->vAddNewChild();
//    c_root.pcGetChild(0)->vAddNewChild();
//    c_root.pcGetChild(0)->pcGetChild(0)->vSetValue(11);
//    c_root.pcGetChild(0)->pcGetChild(1)->vSetValue(12);
//    c_root.pcGetChild(1)->vAddNewChild();
//    c_root.pcGetChild(1)->vAddNewChild();
//    c_root.pcGetChild(1)->pcGetChild(0)->vSetValue(21);
//    c_root.pcGetChild(1)->pcGetChild(1)->vSetValue(22);
//
//    //c_root.pcGetChild(0)->pcGetChild(1)->vPrintUp();
//} //void v_tree_test()



