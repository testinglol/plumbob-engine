
void __thiscall FUN_005353fa(int param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  *(undefined4 *)(param_1 + 0xd4) = *param_2;
  iVar1 = param_2[1];
  *(int *)(param_1 + 0xd8) = iVar1;
  if (*(int *)(param_1 + 0xdc) == 0) {
    *(undefined4 *)(param_1 + 0xdc) = DAT_006f2aa4;
  }
  iVar2 = (**(code **)(**(int **)(param_1 + 0xdc) + 0x58))();
  iVar3 = iVar1 / iVar2;
  if ((iVar3 + 1) * iVar2 - iVar1 < iVar1 - iVar3 * iVar2) {
    iVar3 = iVar3 + 1;
  }
  *(undefined4 *)(param_1 + 0xe4) = 0;
  *(undefined4 *)(param_1 + 0xf4) = 0;
  *(undefined4 *)(param_1 + 0xe0) = *(undefined4 *)(param_1 + 0xd4);
  *(int *)(param_1 + 0xd8) = iVar3 * iVar2;
  *(int *)(param_1 + 0xf8) = iVar3 * iVar2;
  FUN_00535494();
  return;
}

