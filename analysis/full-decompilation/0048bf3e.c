
int __fastcall FUN_0048bf3e(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined1 uVar5;
  
  iVar2 = FUN_004931a5();
  if (iVar2 != 0) {
    return iVar2;
  }
  iVar2 = *(int *)(param_1 + 0x38);
  iVar3 = 0;
  if (iVar2 == 0) {
    cVar1 = FUN_0048c193();
    if (cVar1 == '\0') goto LAB_0048bfc8;
    uVar5 = *(undefined1 *)(param_1 + 0x3c);
    iVar2 = *(int *)(param_1 + 0x24);
LAB_0048bfbd:
    iVar3 = 0;
    FUN_0048befd(*(undefined4 *)(param_1 + 0x28),iVar2,uVar5);
  }
  else {
    if (0 < iVar2) {
      if (iVar2 < 3) {
        cVar1 = FUN_0048c0eb();
        if (cVar1 != '\0') {
          iVar3 = 0;
        }
        goto LAB_0048bfc8;
      }
      if (iVar2 == 3) {
        for (puVar4 = *(undefined4 **)(param_1 + 0x2c); puVar4 != *(undefined4 **)(param_1 + 0x30);
            puVar4 = puVar4 + 1) {
          (**(code **)(*(int *)*puVar4 + 0x20))();
        }
        cVar1 = FUN_0048c22a();
        if (cVar1 == '\0') goto LAB_0048bfc8;
        uVar5 = *(undefined1 *)(param_1 + 0x3c);
        iVar2 = -*(int *)(param_1 + 0x24);
        goto LAB_0048bfbd;
      }
    }
    iVar3 = 1;
  }
LAB_0048bfc8:
  if (*(int *)(param_1 + 0x38) != 3) {
    for (puVar4 = *(undefined4 **)(param_1 + 0x2c); puVar4 != *(undefined4 **)(param_1 + 0x30);
        puVar4 = puVar4 + 1) {
      (**(code **)(*(int *)*puVar4 + 0x20))();
    }
  }
  if (iVar3 == 0) {
    iVar3 = FUN_00493181();
  }
  return iVar3;
}

