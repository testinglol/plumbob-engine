
void __thiscall FUN_005d4701(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(param_1 + 4);
  for (iVar1 = 0x14; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_2;
    param_2 = param_2 + 1;
    puVar2 = puVar2 + 1;
  }
  if (*(int *)(param_1 + 0x8c) != 0) {
    *(undefined4 *)(param_1 + 0x4c) = *(undefined4 *)(*(int *)(param_1 + 0x8c) + 0xc);
  }
  (**(code **)(**(int **)(param_1 + 0x58) + 0xc))
            (*(int **)(param_1 + 0x58),(undefined4 *)(param_1 + 4));
  return;
}

