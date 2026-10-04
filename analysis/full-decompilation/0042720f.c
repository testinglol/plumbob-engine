
bool FUN_0042720f(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = FUN_00465062(param_4);
  if (0 < iVar1) {
    iVar1 = FUN_00465062(param_2);
    if (0 < iVar1) {
      iVar1 = FUN_0046518a(param_4,0);
      if (DAT_006c4388 <= iVar1) {
        iVar1 = FUN_0046518a(param_2,0);
        return DAT_006c4388 <= iVar1;
      }
    }
  }
  return false;
}

