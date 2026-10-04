
void __thiscall FUN_0047653c(undefined2 *param_1,undefined2 *param_2)

{
  int iVar1;
  
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  iVar1 = *(int *)(param_1 + 2);
  if (*(int *)(param_2 + 2) < *(int *)(param_1 + 2)) {
    iVar1 = *(int *)(param_2 + 2);
  }
  FUN_00420050(*(undefined4 *)(param_2 + 4),*(undefined4 *)(param_1 + 4),iVar1 * 6);
  *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_2 + 0xc);
  *(undefined4 *)(param_1 + 6) = *(undefined4 *)(param_2 + 6);
  *(undefined4 *)(param_1 + 0xe) = *(undefined4 *)(param_2 + 0xe);
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_2 + 8);
  *(undefined4 *)(param_1 + 10) = *(undefined4 *)(param_2 + 10);
  *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_2 + 0x10);
  FUN_005d499c(param_2 + 0x12);
  return;
}

