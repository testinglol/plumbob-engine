
undefined4 * __thiscall FUN_00405f8c(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = 10;
  puVar1 = param_1;
  do {
    *puVar1 = *(undefined4 *)((param_2 - (int)param_1) + (int)puVar1);
    puVar1 = puVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  puVar1 = param_1 + 10;
  iVar2 = 7;
  do {
    *puVar1 = *(undefined4 *)((int)puVar1 + (param_2 - (int)param_1));
    puVar1 = puVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  param_1[0x11] = *(undefined4 *)(param_2 + 0x44);
  param_1[0x12] = *(undefined4 *)(param_2 + 0x48);
  param_1[0x13] = *(undefined4 *)(param_2 + 0x4c);
  param_1[0x14] = *(undefined4 *)(param_2 + 0x50);
  FUN_0046f8e4(param_2 + 0x54);
  FUN_0046f8e4(param_2 + 0xe0);
  FUN_0046f8e4(param_2 + 0x16c);
  FUN_0046f8e4(param_2 + 0x1f8);
  FUN_0046f8e4(param_2 + 0x284);
  FUN_0046f8e4(param_2 + 0x2d0);
  FUN_0046f8e4(param_2 + 0x31c);
  FUN_0046f8e4(param_2 + 0x368);
  FUN_005d499c(param_2 + 0x3b4);
  return param_1;
}

