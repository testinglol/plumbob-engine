
void __fastcall FUN_00540eed(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  iVar3 = 2;
  puVar2 = (undefined4 *)(param_1 + 0x10);
  do {
    piVar1 = (int *)*puVar2;
    for (iVar4 = *piVar1; iVar4 != piVar1[1]; iVar4 = iVar4 + 4) {
      FUN_0053ef86();
      piVar1 = (int *)*puVar2;
    }
    puVar2 = puVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  iVar3 = *(int *)(param_1 + 0x3c) + *(int *)(param_1 + 0x38);
  if (iVar3 == 0) {
    iVar3 = *(int *)(param_1 + 0x44) + *(int *)(param_1 + 0x40);
    if (iVar3 == 0) {
      return;
    }
    if (iVar3 == 2) {
      uVar5 = 0;
    }
    else {
      if (*(int *)(param_1 + 0x40) != 0) {
        FUN_00540972(1);
      }
      if (*(int *)(param_1 + 0x44) == 0) goto LAB_00540f80;
      uVar5 = 2;
    }
    FUN_00540972(uVar5);
    goto LAB_00540f80;
  }
  if (iVar3 == 2) {
    uVar5 = 0;
LAB_00540f40:
    FUN_005407ce(uVar5);
  }
  else {
    if (*(int *)(param_1 + 0x38) != 0) {
      FUN_005407ce(1);
    }
    if (*(int *)(param_1 + 0x3c) != 0) {
      uVar5 = 2;
      goto LAB_00540f40;
    }
  }
  *(undefined4 *)(param_1 + 0x3c) = 0;
  *(undefined4 *)(param_1 + 0x38) = 0;
LAB_00540f80:
  *(undefined4 *)(param_1 + 0x44) = 0;
  *(undefined4 *)(param_1 + 0x40) = 0;
  return;
}

