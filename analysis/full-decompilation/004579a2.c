
uint FUN_004579a2(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  uVar3 = FUN_00457e1c();
  iVar5 = 0;
  if (uVar3 != 0) {
    iVar1 = *(int *)(uVar3 + 4);
    iVar6 = 0;
    if (0 < iVar1) {
      do {
        if ((iVar6 < 0) || (iVar1 <= iVar6)) {
          iVar4 = 0;
        }
        else {
          iVar4 = *(int *)(*(int *)(uVar3 + 0x10) + iVar6 * 4);
        }
        if (((iVar4 != 0) && (uVar2 = *(uint *)(iVar4 + 0x14), (uVar2 >> 7 & 1) == 0)) &&
           ((iVar5 = iVar5 + 1, (~(byte)(uVar2 >> 6) & 1) != 0 ||
            (((uVar2 >> 9 & 1) != 0 || ((~(byte)(uVar2 >> 4) & 1) != 0)))))) {
          return uVar3 & 0xffffff00;
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < iVar1);
    }
  }
  return (uint)(0 < iVar5);
}

