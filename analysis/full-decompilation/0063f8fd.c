
undefined4 FUN_0063f8fd(int param_1)

{
  int iVar1;
  
  DAT_00703ff8 = HeapCreate((uint)(param_1 == 0),0x1000,0);
  if (DAT_00703ff8 != (HANDLE)0x0) {
    DAT_00703ffc = FUN_0063f7b5();
    if (DAT_00703ffc == 3) {
      iVar1 = FUN_0063f95a(0x3f8);
    }
    else {
      if (DAT_00703ffc != 2) {
        return 1;
      }
      iVar1 = FUN_006404a1();
    }
    if (iVar1 != 0) {
      return 1;
    }
    HeapDestroy(DAT_00703ff8);
  }
  return 0;
}

