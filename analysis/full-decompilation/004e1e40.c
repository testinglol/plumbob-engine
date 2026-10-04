
undefined4 FUN_004e1e40(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_004e8d71(param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_00425769(iVar1);
    if (iVar1 != 0) {
      iVar1 = FUN_00427017(iVar1);
      return CONCAT31((int3)((uint)-iVar1 >> 8),'\x01' - (iVar1 != 0));
    }
  }
  return 0;
}

