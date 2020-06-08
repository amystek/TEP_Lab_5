#ifndef LAB_5_CTREESTATIC_H
#define LAB_5_CTREESTATIC_H

#include "iostream"
#include "vector"

using namespace std;

class  CTreeStatic
{
private:    //CTreeStatic
    class  CNodeStatic
    {
    public:
        CNodeStatic() {i_val = 0; pc_parent = NULL;};
        ~CNodeStatic();
        void vSetValue(int iNewVal) {i_val = iNewVal;};
        int iGetChildrenNumber() {return(v_children.size());};
        void vAddNewChild();
        void vAddNewChild(CNodeStatic*);
        void vPrint() {cout << " " << i_val;};
        void vPrintAllBelow();
        void vPrintUp();
        CNodeStatic *pcGetChild(int iChildOffset);
        CNodeStatic *pcGetParent() {return pc_parent;};
        void vEraseChild(CNodeStatic*);
//        int iGetValue() {return i_val;}
    private:
        vector<CNodeStatic> v_children;
        CNodeStatic *pc_parent;
        int i_val;
    }; //class CNodeStatic

    CNodeStatic c_root;

public:     //CTreeStatic
    CTreeStatic() { };
    ~CTreeStatic() { };
    CNodeStatic *pcGetRoot() {return(&c_root);}
    void  vPrintTree();
    bool bMoveSubtree(CNodeStatic *pcParentNode, CNodeStatic *pcNewChildNode);
//    void v_tree_test();
}; //class CTreeStatic


#endif //LAB_5_CTREESTATIC_H
