
undefined4 __fastcall FUN_00632edd(int param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  
  if (*(int *)(param_1 + 0x4c) == -1) {
    return 0xffffffff;
  }
  if (*(int *)(param_1 + 8) == 0) {
    uVar2 = *(uint *)(param_1 + 0x18);
    if (*(uint *)(param_1 + 0x1c) < uVar2) {
      iVar5 = 0;
    }
    else {
      iVar5 = *(uint *)(param_1 + 0x1c) - uVar2;
    }
    if ((iVar5 != 0) && (iVar3 = FUN_0063d061(*(int *)(param_1 + 0x4c),uVar2,iVar5), iVar3 != iVar5)
       ) {
      if (0 < iVar3) {
        if (*(int *)(param_1 + 0x20) != 0) {
          *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) - iVar3;
        }
        FUN_00635190(*(int *)(param_1 + 0x18),iVar3 + *(int *)(param_1 + 0x18),iVar5 - iVar3);
      }
      return 0xffffffff;
    }
    *(undefined4 *)(param_1 + 0x18) = 0;
    *(undefined4 *)(param_1 + 0x1c) = 0;
    *(undefined4 *)(param_1 + 0x20) = 0;
    iVar5 = FUN_006328dc();
    if (0 < iVar5) {
      uVar2 = *(uint *)(param_1 + 0x4c);
      bVar1 = *(byte *)((&DAT_00704000)[(int)uVar2 >> 5] + 4 + (uVar2 & 0x1f) * 0x24);
      if ((bVar1 & 0x80) != 0) {
        for (pcVar4 = *(char **)(param_1 + 0x28); pcVar4 < *(char **)(param_1 + 0x2c);
            pcVar4 = pcVar4 + 1) {
          if (*pcVar4 == '\n') {
            iVar5 = iVar5 + 1;
          }
        }
        if ((bVar1 & 2) != 0) {
          iVar5 = iVar5 + 1;
        }
      }
      iVar5 = FUN_0063d48f(uVar2,-iVar5,1);
      if (iVar5 == -1) {
        return 0xffffffff;
      }
    }
    *(undefined4 *)(param_1 + 0xc) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x24) = 0;
    *(undefined4 *)(param_1 + 0x28) = 0;
    *(undefined4 *)(param_1 + 0x2c) = 0;
  }
  return 0;
}

