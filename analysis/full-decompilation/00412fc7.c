
undefined4 __thiscall FUN_00412fc7(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 4) == 0) {
    uVar1 = 0xffffffcf;
  }
  else {
    *param_2 = *(undefined4 *)(*(int *)(param_1 + 4) + 0x10);
    uVar1 = 0;
  }
  return uVar1;
}

