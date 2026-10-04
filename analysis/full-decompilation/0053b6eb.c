
void __thiscall FUN_0053b6eb(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  undefined4 uVar5;
  
  iVar2 = *(int *)(param_1 + 0x1e4);
  if (iVar2 == 0) {
    if (param_2 != 1) {
      if (param_2 != 2) {
        if (param_2 != 3) {
          return;
        }
        iVar2 = FUN_00401f6f();
LAB_0053b830:
        if ((iVar2 == 2) && (*(char *)(*(int *)(DAT_006f2a08 + 0x84) + 0x119) == '\0')) {
          return;
        }
LAB_0053b845:
        uVar5 = 1;
        goto LAB_0053b864;
      }
      if (*(char *)(param_1 + 0x1ec) == '\0') {
        return;
      }
LAB_0053b7fa:
      uVar5 = 3;
      goto LAB_0053b864;
    }
  }
  else {
    if (iVar2 != 1) {
      if (iVar2 == 2) {
        if (param_2 == 0) {
          iVar2 = FUN_00401f6f();
          bVar4 = iVar2 == 2;
LAB_0053b861:
          if (!bVar4) {
            return;
          }
          goto LAB_0053b863;
        }
        if (param_2 != 1) {
          return;
        }
        cVar1 = FUN_00493b85();
        if (cVar1 == '\0') {
          iVar2 = FUN_00401f6f();
          if (iVar2 != 2) goto LAB_0053b845;
          goto LAB_0053b7dc;
        }
      }
      else {
        if (iVar2 != 3) {
          return;
        }
        if (param_2 == 0) {
          bVar4 = *(char *)(param_1 + 0x1ec) == '\0';
          goto LAB_0053b861;
        }
        if (param_2 != 1) {
          if (param_2 != 2) {
            if (param_2 != 3) {
              return;
            }
            iVar2 = FUN_00401f6f();
            goto LAB_0053b830;
          }
          goto LAB_0053b863;
        }
        cVar1 = FUN_00493b85();
        if (cVar1 == '\0') {
          return;
        }
      }
LAB_0053b858:
      uVar5 = 2;
      goto LAB_0053b864;
    }
    if (param_2 != 1) {
      if (param_2 != 3) {
        return;
      }
      iVar2 = FUN_00401f6f();
      if (iVar2 != 2) {
        return;
      }
      if (*(char *)(*(int *)(DAT_006f2a08 + 0x84) + 0x119) != '\0') {
        return;
      }
      cVar1 = FUN_00493b85();
      if (cVar1 != '\0') goto LAB_0053b858;
LAB_0053b7dc:
      if (*(char *)(param_1 + 0x1ec) != '\0') {
        iVar2 = FUN_004cebb0();
        iVar3 = FUN_0046d386();
        if (iVar2 != iVar3) goto LAB_0053b7fa;
      }
LAB_0053b863:
      uVar5 = 0;
      goto LAB_0053b864;
    }
  }
  cVar1 = FUN_00493b85();
  if (cVar1 == '\0') {
    return;
  }
  uVar5 = 2;
LAB_0053b864:
  FUN_0053b871(uVar5);
  return;
}

