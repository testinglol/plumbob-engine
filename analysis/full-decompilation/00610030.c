
void FUN_00610030(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(*(int *)(param_1 + 4) + param_2 * 0x38);
  for (iVar1 = 0xe; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_3 = *puVar2;
    puVar2 = puVar2 + 1;
    param_3 = param_3 + 1;
  }
  return;
}

