#ifndef LAB_5_CTREEDYNAMIC_H
#define LAB_5_CTREEDYNAMIC_H

#include <vector>
#include "iostream"

using namespace std;

class CTreeDynamic
{
//private:    //CTreeDynamic
public:
    class  CNodeDynamic
    {
    public:     //CNodeDynamic
        CNodeDynamic() {i_val = 0; pc_parent = NULL;};
        ~CNodeDynamic() { };
        void vSetValue(int iNewVal) {i_val = iNewVal;};
        int iGetChildrenNumber() {return v_children.size();};
        void vAddNewChild();
        void vAddNewChild(CNodeDynamic*);
        void vPrint() {cout << " " << i_val;};
        void vPrintAllBelow();
        void vPrintUp();
        CNodeDynamic *pcGetChild(int iChildOffset);
        CNodeDynamic *pcGetParent() {return pc_parent;};
        void vEraseChild(CNodeDynamic*);

    private:    //CNodeDynamic
        vector<CNodeDynamic *> v_children;
        int i_val;
        CNodeDynamic *pc_parent;
    }; //class CNodeDynamic

    CNodeDynamic *pc_root;

public:     //CTreeDynamic
    CTreeDynamic() {pc_root = new CNodeDynamic();}
    ~CTreeDynamic() {delete pc_root;}
    CNodeDynamic *pcGetRoot() {return (pc_root);}
    void  vPrintTree();
    bool bMoveSubtree(CNodeDynamic *pcParentNode, CNodeDynamic *pcNewChildNode);
//    void v_tree_test();

}; //class CTreeStatic

#endif //LAB_5_CTREEDYNAMIC_H
