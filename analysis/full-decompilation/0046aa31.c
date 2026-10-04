
undefined4 __fastcall FUN_0046aa31(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  float local_8;
  
  iVar1 = FUN_00469872(**(undefined4 **)(param_1 + 0x30));
  local_8 = *(float *)(iVar1 + 0x20);
  puVar3 = *(undefined4 **)(param_1 + 0x30);
  iVar1 = 0;
  while (puVar3 = puVar3 + 1, puVar3 != *(undefined4 **)(param_1 + 0x34)) {
    iVar2 = FUN_00469872(*puVar3);
    if (*(float *)(iVar2 + 0x20) < local_8) {
      local_8 = *(float *)(iVar2 + 0x20);
      iVar1 = (int)puVar3 - *(int *)(param_1 + 0x30) >> 2;
    }
  }
  return *(undefined4 *)(*(int *)(param_1 + 0x30) + iVar1 * 4);
}

