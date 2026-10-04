
uint __fastcall FUN_0048be61(int param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined1 uVar5;
  
  uVar2 = FUN_00493133();
  if (uVar2 != 0) {
    return uVar2;
  }
  iVar3 = *(int *)(param_1 + 0x38);
  if (iVar3 == 0) {
    cVar1 = FUN_0048c22a();
    if (cVar1 != '\0') {
      uVar5 = *(undefined1 *)(param_1 + 0x3c);
      iVar3 = -*(int *)(param_1 + 0x24);
LAB_0048bec5:
      uVar2 = 0;
      FUN_0048befd(*(undefined4 *)(param_1 + 0x28),iVar3,uVar5);
      goto LAB_0048bed5;
    }
  }
  else if (0 < iVar3) {
    if (iVar3 < 3) {
      cVar1 = FUN_0048c0eb();
      uVar2 = (uint)(cVar1 == '\0');
      goto LAB_0048bed5;
    }
    if ((iVar3 == 3) && (cVar1 = FUN_0048c193(), cVar1 != '\0')) {
      uVar5 = *(undefined1 *)(param_1 + 0x3c);
      iVar3 = *(int *)(param_1 + 0x24);
      goto LAB_0048bec5;
    }
  }
  uVar2 = 1;
LAB_0048bed5:
  for (puVar4 = *(undefined4 **)(param_1 + 0x2c); puVar4 != *(undefined4 **)(param_1 + 0x30);
      puVar4 = puVar4 + 1) {
    (**(code **)(*(int *)*puVar4 + 0x1c))();
  }
  if (uVar2 == 0) {
    uVar2 = FUN_0049315a();
  }
  return uVar2;
}

