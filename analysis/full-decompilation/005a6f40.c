
undefined4 FUN_005a6f40(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = DAT_006d200c;
  DAT_006d200c = param_1;
  if (param_1 == 0) {
    DAT_006d2008 = 0xffffffff;
  }
  return uVar1;
}

