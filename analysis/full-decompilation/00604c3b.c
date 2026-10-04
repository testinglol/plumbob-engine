
void __fastcall FUN_00604c3b(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uStack_14;
  undefined4 local_10;
  int local_4;
  
  puVar2 = (undefined4 *)(param_1 + 8);
  for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  uStack_14 = *(undefined4 *)(param_1 + 4);
  local_10 = uStack_14;
  local_4 = param_1;
  FUN_00602902(&uStack_14);
  FUN_00578f92(&local_4);
  return;
}

