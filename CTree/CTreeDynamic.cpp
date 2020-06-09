#include "CTreeDynamic.h"

void CTreeDynamic::CNodeDynamic::vAddNewChild()
{
    CNodeDynamic *cNewNode = new CNodeDynamic;
    cNewNode->pc_parent = this;
    v_children.push_back(cNewNode);
} //void CNodeDynamic::vAddNewChild()

void CTreeDynamic::CNodeDynamic::vAddNewChild(CTreeDynamic::CNodeDynamic *pcNewChild)
{
    CNodeDynamic *c_NewNode = new CNodeDynamic();
    c_NewNode->vSetValue(pcNewChild->i_val);
    for (int ii = 0; ii < iGetChildrenNumber(); ii++)
    {
        c_NewNode->v_children.push_back(pcNewChild->pcGetChild(ii));
    } //for (vector<CNodeStatic>::iterator ii = pcNewChild->v_children.begin(); ii != pcNewChild->v_children.end(); ii++)

    c_NewNode->pc_parent = this;
    v_children.push_back(c_NewNode);
} //void CTreeDynamic::CNodeDynamic::vAddNewChild(CTreeDynamic::CNodeDynamic *)

CTreeDynamic::CNodeDynamic * CTreeDynamic::CNodeDynamic::pcGetChild(int iChildOffset)
{
    if (iChildOffset < 0 or iChildOffset > iGetChildrenNumber())
    {
        return NULL;
    } //if (iChildOffset < 0 or iChildOffset > iGetChildrenNumber())

    return v_children.at(iChildOffset);
} //CNodeDynamic *CNodeDynamic::pcGetChild(int iChildOffset)

void CTreeDynamic::vPrintTree()
{
    pc_root->vPrintAllBelow();
    cout << endl;
} //void CTreeDynamic::vPrintTree()

void CTreeDynamic::CNodeDynamic::vPrintAllBelow()
{
    vPrint();
    if (iGetChildrenNumber() == 0) return;
    for (int ii = 0; ii < iGetChildrenNumber(); ii++)
    {
        pcGetChild(ii)->vPrintAllBelow();
    } //for (int ii = 00; ii < iGetChildrenNumber(); ii++)
} //void CNodeDynamic::vPrintAllBelow()

void CTreeDynamic::CNodeDynamic::vPrintUp()
{
    vPrint();
    for (int ii = 0; ii < iGetChildrenNumber(); ii++)
    {
        pc_parent->vPrintUp();
    } //for (int ii = 00; ii < iGetChildrenNumber(); ii++)
} //void CTreeDynamic::CNodeDynamic::vPrintUp()

void CTreeDynamic::CNodeDynamic::vEraseChild(CTreeDynamic::CNodeDynamic *pcChildToErase)
{
    if (pcChildToErase->pcGetParent() == NULL)
    {
        pcChildToErase = NULL;
        return;
    } //if (pcChildToErase->pcGetParent() == NULL)

    CNodeDynamic* pc_ParentNode = pcChildToErase->pcGetParent();
    for (int ii = 0; ii < iGetChildrenNumber(); ii++)
    {
        if (pc_ParentNode->pcGetChild(ii) == pcChildToErase)
        {
            pc_ParentNode->v_children.erase(pc_ParentNode->v_children.begin() + ii);
            break;  // break FOR loop after finding first match
        } //if (&(*ii) == pcChildToErase)
    } //for (int ii = 00; ii < iGetChildrenNumber(); ii++)
} //void CTreeDynamic::CNodeDynamic::vEraseChild(CTreeDynamic::CNodeDynamic *pcChildToErase)

//TODO: fix errors, not working properly
bool CTreeDynamic::bMoveSubtree(CTreeDynamic::CNodeDynamic *pcParentNode, CTreeDynamic::CNodeDynamic *pcNewChildNode)
{
    if (pcParentNode == NULL || pcNewChildNode == NULL) return false;
    if (pcParentNode == pcNewChildNode) return false;

    CNodeDynamic *pc_tmp = pcNewChildNode;
    pcParentNode->vAddNewChild(pcNewChildNode);

    pcNewChildNode->vEraseChild(pcNewChildNode);

    return true;
} //bool CTreeDynamic::bMoveSubtree(CTreeDynamic::CNodeDynamic *pcParentNode, CTreeDynamic::CNodeDynamic *pcNewChildNode)


//void CTreeDynamic::v_tree_test()
//{
//    //CNodeStatic c_root;
//    pc_root->vAddNewChild();
//    pc_root->vAddNewChild();
//    pc_root->pcGetChild(0)->vSetValue(1);
//    pc_root->pcGetChild(1)->vSetValue(2);
//    pc_root->pcGetChild(0)->vAddNewChild();
//    pc_root->pcGetChild(0)->vAddNewChild();
//    pc_root->pcGetChild(0)->pcGetChild(0)->vSetValue(11);
//    pc_root->pcGetChild(0)->pcGetChild(1)->vSetValue(12);
//    pc_root->pcGetChild(1)->vAddNewChild();
//    pc_root->pcGetChild(1)->vAddNewChild();
//    pc_root->pcGetChild(1)->pcGetChild(0)->vSetValue(21);
//    pc_root->pcGetChild(1)->pcGetChild(1)->vSetValue(22);
//
//} //void CTreeDynamic::v_tree_test()

