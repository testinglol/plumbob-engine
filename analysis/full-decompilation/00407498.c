
undefined4 __thiscall FUN_00407498(int param_1,uint param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((0 < (int)param_2) &&
     (param_2 < (*(int *)(param_1 + 0x1c) - *(int *)(param_1 + 0x18) >> 2) + 1U)) {
    uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x18) + -4 + param_2 * 4);
  }
  return uVar1;
}

