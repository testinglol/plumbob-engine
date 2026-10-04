
undefined4 * __thiscall FUN_0046b95f(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
    param_1[4] = 0;
    param_1[5] = 0;
    param_1[6] = 0;
    param_1[7] = 0;
    param_1[8] = 0;
    param_1[9] = 0;
  }
  else {
    uVar1 = FUN_0045741b();
    *param_1 = uVar1;
    param_1[1] = *(undefined4 *)(param_2 + 0x798);
    param_1[2] = *(undefined4 *)(param_2 + 0x7a0);
    param_1[3] = *(undefined4 *)(param_2 + 0x7a4);
    param_1[4] = *(undefined4 *)(param_2 + 0x7a8);
    param_1[5] = *(undefined4 *)(param_2 + 0x7ac);
    param_1[6] = *(undefined4 *)(param_2 + 0x7b0);
    param_1[7] = *(undefined4 *)(param_2 + 0x7c0);
    param_1[8] = *(undefined4 *)(param_2 + 0x7c4);
    param_1[9] = *(undefined4 *)(param_2 + 0x7c8);
  }
  return param_1;
}

