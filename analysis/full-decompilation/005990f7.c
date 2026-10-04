
undefined4 __thiscall FUN_005990f7(int param_1,undefined4 *param_2)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = FUN_00598764(*param_2);
  if (uVar1 < (uint)(*(int *)(param_1 + 0x74) - *(int *)(param_1 + 0x70) >> 2)) {
    uVar2 = *(undefined4 *)(*(int *)(param_1 + 0x70) + uVar1 * 4);
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

