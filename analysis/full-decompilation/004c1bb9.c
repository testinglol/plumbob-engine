
undefined4 __thiscall FUN_004c1bb9(int param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (*(int *)(param_1 + 0x10) != 0) {
    uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x10) + param_2 * 4);
  }
  return uVar1;
}

