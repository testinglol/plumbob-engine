
uint FUN_00583382(undefined4 *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = 1;
  if (param_1 != (undefined4 *)0x0) {
    uVar2 = *param_1;
    FUN_005b8e25(uVar2);
    FUN_005b95c0(uVar2);
    uVar1 = FUN_005a9340(param_1);
    uVar1 = uVar1 & 1;
  }
  return uVar1;
}

