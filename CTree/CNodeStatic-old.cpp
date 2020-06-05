//#include "CNodeStatic.h"
//
//CNodeStatic::~CNodeStatic()
//{
//    //default destructor is enough
//} //CNodeStatic::~CNodeStatic()
//
//void CNodeStatic::vAddNewChild()
//{
//    CNodeStatic cNewNode;
//    cNewNode.pc_parent = this;
//    v_children.push_back(cNewNode);
//} //void CNodeStatic::vAddNewChild()
//
//CNodeStatic *CNodeStatic::pcGetChild(int iChildOffset)
//{
//    if (iChildOffset < 0 or iChildOffset > iGetChildrenNumber())
//    {
//        return NULL;
//    } //if (iChildOffset < 0 or iChildOffset > iGetChildrenNumber())
//
//    return &v_children.at(iChildOffset);
//} ////CNodeStatic *CNodeStatic::pcGetChild(int iChildOffset)
//
//void CNodeStatic::vPrintAllBelow()
//{
//    vPrint();
//    for (vector<CNodeStatic>::iterator i = v_children.begin(); i != v_children.end(); i++)
//    {
//        i -> vPrintAllBelow();
//    } //for (vector<string>::iterator i = sText.begin(); i != sText.end(); i++)
//} //void CNodeStatic::vPrintAllBelow()
//
//void CNodeStatic::vPrintUp()
//{
//    vPrint();
//    if (pc_parent != NULL)
//    {
//        pc_parent -> vPrintUp();
//    } //if (pc_parent != NULL)
//} //void CNodeStatic::vPrintUp()
//

