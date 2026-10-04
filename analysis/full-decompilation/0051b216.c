
undefined4 * __thiscall FUN_0051b216(undefined4 *param_1,byte param_2)

{
  undefined4 *puVar1;
  
  if ((param_2 & 2) == 0) {
    FUN_005a5e09();
    puVar1 = param_1;
    if ((param_2 & 1) != 0) {
      FUN_006321f0(param_1);
    }
  }
  else {
    puVar1 = param_1 + -1;
    FUN_00635f6d(param_1,4,*puVar1,FUN_005a5e09);
    if ((param_2 & 1) != 0) {
      FUN_006321f0(puVar1);
    }
  }
  return puVar1;
}

