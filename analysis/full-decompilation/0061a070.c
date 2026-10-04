
void FUN_0061a070(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = *(undefined4 **)(param_1 + 8);
  while (puVar2 != (undefined4 *)(param_1 + 0x10)) {
    puVar1 = (undefined4 *)*puVar2;
    FUN_005a9340(puVar2);
    puVar2 = puVar1;
  }
  *(int **)(param_1 + 0x24) = (int *)(param_1 + 0x18);
  *(int *)(param_1 + 8) = param_1 + 0x10;
  *(int *)(param_1 + 0x18) = param_1 + 0x20;
  *(int **)(param_1 + 0x14) = (int *)(param_1 + 8);
  *(int **)(param_1 + 0x34) = (int *)(param_1 + 0x28);
  *(int *)(param_1 + 0x28) = param_1 + 0x30;
  return;
}

