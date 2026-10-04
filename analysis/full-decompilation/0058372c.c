
undefined4 __thiscall
FUN_0058372c(int *param_1,undefined4 param_2,undefined4 param_3,int *param_4,int *param_5)

{
  int iVar1;
  
  if (param_4[1] != *param_4) {
    iVar1 = FUN_005a02d8(param_4);
    if (iVar1 != 0) {
      iVar1 = FUN_0059943e(iVar1,-(uint)(param_5[1] != *param_5) & (uint)param_5,0,0xffffffff);
      if (iVar1 != 0) {
        FUN_0058379c();
        FUN_005d499c(param_4);
        FUN_005d499c(param_5);
        *param_1 = iVar1;
        return 1;
      }
      FUN_0058379c();
    }
  }
  return 0;
}

