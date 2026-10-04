
void __fastcall FUN_005f7a23(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(param_1 + 0x4c);
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined4 **)(param_1 + 0x94) = (undefined4 *)(param_1 + 0x4c);
  return;
}

