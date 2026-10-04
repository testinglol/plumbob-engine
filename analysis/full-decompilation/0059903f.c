
undefined4 __thiscall FUN_0059903f(int param_1,undefined4 *param_2)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int local_8;
  
  local_8 = param_1;
  FUN_0059ae67(&param_2);
  uVar1 = FUN_00598764(*param_2);
  if ((uint)(*(int *)(param_1 + 0x74) - *(int *)(param_1 + 0x70) >> 2) <= uVar1) {
    local_8 = 0;
    FUN_0059ae8e(uVar1 + 1,&local_8);
  }
  *(undefined4 **)(*(int *)(param_1 + 0x70) + uVar1 * 4) = param_2;
  param_2[0x4c] = param_2[0x4c] + 1;
  param_2[0x54] = param_2[0x54] + 1;
  param_2[7] = param_1;
  if (*(int *)(param_1 + 0x60) == 0) {
    uVar2 = 0;
  }
  else {
    iVar3 = FUN_005990f7(param_2 + 4);
    if (iVar3 != 0) {
      param_2[0x4c] = param_2[0x4c] + 1;
      param_2[0x54] = param_2[0x54] + 1;
      param_2[9] = iVar3;
      param_2[8] = *(undefined4 *)(iVar3 + 0x28);
      *(undefined4 **)(iVar3 + 0x28) = param_2;
      return 0;
    }
    param_2[8] = *(undefined4 *)(param_1 + 0x60);
    uVar2 = 0xffffffff;
  }
  *(undefined4 **)(param_1 + 0x60) = param_2;
  return uVar2;
}

