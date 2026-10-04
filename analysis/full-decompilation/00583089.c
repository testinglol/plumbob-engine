
undefined4 FUN_00583089(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (DAT_006f6aa0 == (code *)0x0) {
    if (DAT_006f6ae0 == (code *)0x0) {
      uVar1 = 0;
    }
    else {
      uVar1 = (*DAT_006f6ae0)(param_1,param_2,param_3);
    }
  }
  else {
    uVar1 = (*DAT_006f6aa0)(param_1,param_2,param_3,param_4);
  }
  return uVar1;
}

