
undefined4 __thiscall FUN_004c1bec(int param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (*(int *)(param_1 + 0x1c) != 0) {
    uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x1c) + param_2 * 4);
  }
  return uVar1;
}

