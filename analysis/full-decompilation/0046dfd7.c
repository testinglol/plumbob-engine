
undefined4 * __thiscall FUN_0046dfd7(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  
  *param_1 = *(undefined4 *)(param_2 + 4);
  param_1[1] = *(undefined4 *)(param_2 + 8);
  uVar1 = *(undefined4 *)(param_2 + 0xc);
  param_1[3] = 0xffffffff;
  *(undefined2 *)(param_1 + 4) = 0;
  param_1[2] = uVar1;
  param_1[6] = *(undefined4 *)(param_2 + 0x10);
  param_1[7] = *(undefined4 *)(param_2 + 0x14);
  FUN_0046e014(*(undefined4 *)(param_2 + 0x18));
  return param_1;
}

