
int __fastcall FUN_0056d9a6(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x1ac) != 0) {
    iVar1 = *(int *)(param_1 + 0x1b0);
    if (4 < iVar1) {
      if (iVar1 == 5) {
        iVar1 = FUN_0040dbc1();
        return iVar1;
      }
      if (5 < iVar1) {
        if (iVar1 < 0x11) {
          return -1;
        }
        if (iVar1 == 0x11) {
          iVar1 = FUN_0040ded9();
          return iVar1;
        }
        if (iVar1 == 0x12) {
          iVar1 = FUN_0040e1f1();
          return iVar1;
        }
      }
      return param_1;
    }
    if (iVar1 == 4) {
      iVar1 = FUN_0040d591();
      return iVar1;
    }
    if (iVar1 == 0) {
      iVar1 = FUN_0040d106();
      return iVar1;
    }
    if (iVar1 != 1) {
      if (iVar1 == 2) {
        iVar1 = FUN_0040d8a9();
        return iVar1;
      }
      if (iVar1 != 3) {
        return param_1;
      }
    }
  }
  return -1;
}

