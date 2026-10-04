
undefined4 __thiscall FUN_004ff877(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if ((*(int *)(param_1 + 0x10c) < *(int *)(param_1 + 0x114)) &&
     (*(int *)(param_1 + 0x110) < *(int *)(param_1 + 0x118))) {
    *param_2 = *(undefined4 *)(param_1 + 0x10c);
    param_2[1] = *(undefined4 *)(param_1 + 0x110);
    param_2[2] = *(undefined4 *)(param_1 + 0x114);
    param_2[3] = *(undefined4 *)(param_1 + 0x118);
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

