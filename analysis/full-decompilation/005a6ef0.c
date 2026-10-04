
undefined4 FUN_005a6ef0(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = DAT_006f76e8;
  DAT_006f76e8 = param_1;
  if (param_1 != 0) {
    DAT_006f770c = 1;
    return uVar1;
  }
  DAT_006d2008 = 0xffffffff;
  return uVar1;
}

