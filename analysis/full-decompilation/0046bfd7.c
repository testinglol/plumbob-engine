
void __thiscall FUN_0046bfd7(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined *puVar3;
  
  iVar2 = *(int *)(param_1 + 0x20);
  if (iVar2 != *(int *)(param_1 + 0x24)) {
    do {
      puVar3 = &DAT_006c4a1c;
      uVar1 = FUN_004096c2(&DAT_006c4a1c);
      FUN_006323d0(uVar1);
      FUN_006323d0(puVar3);
      puVar3 = &DAT_006c4a1c;
      uVar1 = FUN_004096c2(&DAT_006c4a1c);
      FUN_006323d0(uVar1);
      FUN_006323d0(puVar3);
      FUN_0046ba88(param_2);
      iVar2 = iVar2 + 0x3c;
    } while (iVar2 != *(int *)(param_1 + 0x24));
  }
  return;
}

