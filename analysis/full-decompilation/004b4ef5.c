
int FUN_004b4ef5(void)

{
  ushort uVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  char cVar5;
  int extraout_ECX;
  char cVar6;
  int iVar7;
  int *piVar8;
  int unaff_EBP;
  int iVar9;
  
  FUN_00634c24();
  uVar3 = FUN_004a69aa();
  *(undefined4 *)(unaff_EBP + -0x14) = uVar3;
  iVar9 = *(int *)(extraout_ECX + 0x28);
  iVar4 = *(int *)(extraout_ECX + 0x24);
  iVar7 = 0;
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  if (iVar9 - iVar4 >> 2 != 0) {
    do {
      iVar9 = *(int *)(unaff_EBP + -0x10) * 4;
      if (*(int *)(iVar9 + *(int *)(extraout_ECX + 0x24)) != 0) {
        iVar4 = FUN_005d0a0d(iVar7 + *(int *)(extraout_ECX + 0x30),
                             *(int *)(extraout_ECX + 0x3c) + iVar7);
        if (iVar4 != 0) goto LAB_004b502f;
        iVar4 = FUN_005d0b17(*(int *)(extraout_ECX + 0x48) + iVar9);
        if (iVar4 != 0) goto LAB_004b502f;
        FUN_005ced0e(*(undefined4 *)(iVar9 + *(int *)(extraout_ECX + 0x24)));
      }
      iVar9 = *(int *)(extraout_ECX + 0x28);
      *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
      iVar7 = iVar7 + 0xc;
    } while (*(uint *)(unaff_EBP + -0x10) < (uint)(iVar9 - *(int *)(extraout_ECX + 0x24) >> 2));
  }
  cVar2 = FUN_00422665((int *)(extraout_ECX + 0x10));
  if (cVar2 == '\0') {
    iVar9 = *(int *)(extraout_ECX + 0x10);
    uVar3 = *(undefined4 *)(extraout_ECX + 0x18);
    cVar2 = (char)(*(int *)(extraout_ECX + 0x14) >> 4);
    *(char *)(unaff_EBP + -0x10) = cVar2;
    cVar5 = (char)(iVar9 >> 4);
    *(char *)(unaff_EBP + -0xf) = cVar5;
    cVar6 = (char)uVar3;
    *(char *)(unaff_EBP + -0xe) = cVar6;
    iVar9 = DAT_006e54dc;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    iVar9 = *(int *)(*(int *)(*(int *)(iVar9 + 0x28 + cVar6 * 4) + 0xc) + cVar2 * 4);
    uVar1 = *(ushort *)(iVar9 + cVar5 * 2);
    if (uVar1 < 0xfffb) {
      iVar9 = FUN_004670a4(CONCAT22((short)((uint)iVar9 >> 0x10),uVar1));
      if (iVar9 != 0) {
        for (piVar8 = *(int **)(iVar9 + 0x10); piVar8 != *(int **)(iVar9 + 0x14);
            piVar8 = piVar8 + 1) {
          iVar4 = *piVar8;
          *(int *)(unaff_EBP + -0x18) = iVar4;
          if (iVar4 != 0) {
            iVar4 = FUN_005d0a09();
            if (0 < iVar4) {
              FUN_005ced0e(*(undefined4 *)(unaff_EBP + -0x18));
            }
          }
        }
      }
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  }
  FUN_005cee2f(*(undefined4 *)(extraout_ECX + 0x54));
  iVar4 = 0;
LAB_004b502f:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar4;
}

