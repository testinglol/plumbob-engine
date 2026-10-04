
void __fastcall FUN_005e3a26(int param_1)

{
  char cVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  undefined4 uStack_10;
  
  if (*(int *)(param_1 + 0xf8) == 3) {
    return;
  }
  iVar3 = *(int *)(param_1 + 0xf0);
  iVar4 = *(int *)(param_1 + 0xe0);
  cVar1 = *(char *)(param_1 + 0x168);
  cVar2 = *(char *)(param_1 + 0x169);
  if ((iVar3 != 0) && (uStack_10 = 1, iVar3 != 1)) {
    if (iVar3 == 2) {
      if ((cVar1 != '\0') && ((iVar4 != 0 || (cVar2 != '\0')))) {
LAB_005e3a7c:
        *(undefined4 *)(param_1 + 0xe8) = uStack_10;
        return;
      }
    }
    else {
      uStack_10 = 4;
      if ((iVar3 == 4) || (iVar3 == 6)) {
        if (cVar1 == '\0') {
          if (iVar3 != 4) {
            if (iVar4 != 0) {
              *(undefined4 *)(param_1 + 0xe8) = 5;
              return;
            }
            goto LAB_005e3a7c;
          }
        }
        else {
          if (iVar4 == 0) {
            if (cVar2 != '\0') {
              *(undefined4 *)(param_1 + 0xe8) = 2;
              return;
            }
            goto LAB_005e3b1d;
          }
          if ((iVar3 != 6) || (cVar2 == '\0')) {
            *(undefined4 *)(param_1 + 0xe8) = 1;
            return;
          }
        }
        *(undefined4 *)(param_1 + 0xe8) = 3;
        return;
      }
      if (iVar4 < 0) {
        return;
      }
      if (cVar1 != '\0') {
        *(uint *)(param_1 + 0xe8) = (uint)(iVar4 != 0) | -(uint)(cVar2 != '\0') & 2;
        return;
      }
      if (4 < iVar3) {
        *(uint *)(param_1 + 0xe8) = (iVar4 != 0) + 4;
        return;
      }
    }
  }
LAB_005e3b1d:
  *(undefined4 *)(param_1 + 0xe8) = 0;
  return;
}

