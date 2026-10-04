
undefined4 FUN_00625bd0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_00625820(param_1,param_2);
  if (iVar1 == 0) {
    iVar1 = FUN_00625860(param_1,param_2);
    if (iVar1 == 0) {
      return 1;
    }
  }
  return 0;
}

