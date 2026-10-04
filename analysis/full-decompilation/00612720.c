
undefined4 FUN_00612720(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  
  uVar1 = FUN_00612680(param_1,param_2,param_3);
  if (((uVar1 & 0xff000000) != 0) && (uVar1 != param_4)) {
    return 0;
  }
  return 1;
}

