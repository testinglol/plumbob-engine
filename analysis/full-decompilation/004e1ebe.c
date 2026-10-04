
uint FUN_004e1ebe(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_00425db3(param_1);
  uVar2 = 0;
  if (iVar1 != 0) {
    iVar1 = FUN_004e8d71(param_2);
    uVar2 = 0;
    if (iVar1 != 0) {
      iVar1 = FUN_00425769(iVar1);
      uVar2 = 0;
      if (iVar1 != 0) {
        uVar2 = FUN_00426068(iVar1);
        if (uVar2 == 0) {
          return 1;
        }
      }
    }
  }
  return uVar2 & 0xffffff00;
}

