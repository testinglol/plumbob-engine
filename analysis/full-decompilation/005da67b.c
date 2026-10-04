
void __fastcall FUN_005da67b(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  uint uVar3;
  char cVar4;
  
  piVar1 = (int *)(param_1 + 0x160);
  if ((*(int *)(param_1 + 0x164) - *piVar1) / 0x14 == 0) {
    FUN_005bfaad(piVar1);
    *(undefined4 *)(param_1 + 0x16c) = 0;
  }
  if ((*(int *)(param_1 + 0x164) - *piVar1) / 0x14 != 0) {
    while (uVar3 = *(uint *)(param_1 + 0x16c),
          uVar3 < (uint)((*(int *)(param_1 + 0x164) - *piVar1) / 0x14)) {
      puVar2 = (undefined4 *)(*piVar1 + uVar3 * 0x14);
      *(uint *)(param_1 + 0x16c) = uVar3 + 1;
      cVar4 = FUN_005da398(*puVar2);
      if (cVar4 != '\0') {
        (*(code *)**(undefined4 **)*puVar2)(puVar2 + 1);
      }
    }
    if (*(int *)(param_1 + 0x16c) == (*(int *)(param_1 + 0x164) - *piVar1) / 0x14) {
      FUN_005db3e6(*piVar1,*(undefined4 *)(param_1 + 0x164));
    }
  }
  return;
}

