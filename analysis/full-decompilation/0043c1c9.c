
undefined4 __thiscall FUN_0043c1c9(int param_1,short param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  if (param_2 == 0x81) {
    if (param_3 != 0) {
      for (piVar3 = *(int **)(param_1 + 0x1c); piVar3 != *(int **)(param_1 + 0x20);
          piVar3 = piVar3 + 1) {
        iVar1 = FUN_00401f6f();
        if (((iVar1 == param_3) || (iVar1 = FUN_00401f77(), iVar1 == param_3)) ||
           (iVar1 = FUN_00401f73(), iVar1 == param_3)) {
          *(undefined4 *)(*piVar3 + 0xac) = 0xffffffff;
          *(undefined4 *)(*piVar3 + 0xb0) = 0xffffffff;
        }
      }
    }
  }
  else {
    if (param_2 != 0x102) {
      return 0;
    }
    if (param_3 != 0) {
      for (piVar3 = *(int **)(param_1 + 0x1c); piVar3 != *(int **)(param_1 + 0x20);
          piVar3 = piVar3 + 1) {
        if (*(int *)(*piVar3 + 100) != 0) {
          iVar1 = FUN_00401f6f();
          iVar2 = FUN_00401f6f();
          if (iVar1 == iVar2) {
LAB_0043c249:
            iVar1 = FUN_006359f2(*(undefined4 *)(*(int *)(*piVar3 + 100) + 0x14),0,
                                 &iResFile::RTTI_Type_Descriptor,&ObjResFile::RTTI_Type_Descriptor,0
                                );
            if (iVar1 != 0) {
              FUN_00456c3e(*(undefined4 *)(*piVar3 + 100));
              *(undefined4 *)(*piVar3 + 100) = 0;
            }
          }
          else {
            iVar1 = FUN_00401f77();
            if (iVar1 != 0) {
              iVar1 = FUN_00401f77();
              iVar2 = FUN_00401f77();
              if (iVar1 == iVar2) goto LAB_0043c249;
            }
          }
        }
      }
    }
  }
  return 1;
}

