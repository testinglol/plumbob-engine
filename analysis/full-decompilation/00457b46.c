
bool FUN_00457b46(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar2 = FUN_00457e1c();
  iVar4 = 0;
  if (iVar2 != 0) {
    iVar1 = *(int *)(iVar2 + 4);
    iVar5 = 0;
    if (0 < iVar1) {
      do {
        if ((iVar5 < 0) || (*(int *)(iVar2 + 4) <= iVar5)) {
          iVar3 = 0;
        }
        else {
          iVar3 = *(int *)(*(int *)(iVar2 + 0x10) + iVar5 * 4);
        }
        if ((iVar3 != 0) && ((*(uint *)(iVar3 + 0x14) >> 7 & 1) == 0)) {
          iVar3 = FUN_0041f12e(*(undefined4 *)(iVar3 + 0x20));
          if (iVar3 != 0) {
            iVar4 = iVar4 + 1;
          }
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < iVar1);
    }
  }
  return 0 < iVar4;
}

