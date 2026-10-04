
undefined4 __thiscall FUN_0043ad1f(int param_1,uint param_2)

{
  undefined4 uVar1;
  
  if (((int)param_2 < 0) ||
     ((uint)(*(int *)(param_1 + 0x24) - *(int *)(param_1 + 0x20) >> 2) <= param_2)) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x20) + param_2 * 4);
  }
  return uVar1;
}

