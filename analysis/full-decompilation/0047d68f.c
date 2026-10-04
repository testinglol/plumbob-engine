
void FUN_0047d68f(void)

{
  undefined1 uVar1;
  uint uVar2;
  undefined1 *puVar3;
  uint uVar4;
  int *piVar5;
  undefined4 uVar6;
  int *extraout_ECX;
  int iVar7;
  int unaff_EBP;
  int iVar8;
  int iVar9;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  uVar2 = *(uint *)(unaff_EBP + 0xc);
  iVar7 = 0;
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffe8;
  if (uVar2 != 0) {
    iVar8 = extraout_ECX[1];
    if ((uint)(extraout_ECX[2] - iVar8 >> 2) < uVar2) {
      uVar4 = iVar8 - *extraout_ECX >> 2;
      *(uint *)(unaff_EBP + -0x14) = uVar4;
      piVar5 = (int *)(unaff_EBP + 0xc);
      if (uVar2 <= uVar4) {
        piVar5 = (int *)(unaff_EBP + -0x14);
      }
      iVar8 = *piVar5 + *(int *)(unaff_EBP + -0x14);
      *(int *)(unaff_EBP + 0xc) = iVar8;
      if (iVar8 != 0) {
        iVar7 = FUN_00401742(iVar8 * 4);
      }
      iVar8 = *extraout_ECX;
      *(int *)(unaff_EBP + -0x14) = iVar7;
      *(int *)(unaff_EBP + -0x18) = iVar7;
      *(undefined4 *)(unaff_EBP + -4) = 1;
      uVar6 = FUN_0047d986(iVar8,*(undefined4 *)(unaff_EBP + 8),iVar7,*(undefined4 *)(unaff_EBP + 8)
                          );
      uVar6 = FUN_0047d9b7(uVar6,uVar2,*(undefined4 *)(unaff_EBP + 0x10),
                           *(undefined4 *)(unaff_EBP + 8));
      iVar9 = FUN_0047d986(*(undefined4 *)(unaff_EBP + 8),extraout_ECX[1],uVar6,
                           *(undefined4 *)(unaff_EBP + 8));
      for (iVar8 = *extraout_ECX; iVar8 != extraout_ECX[1]; iVar8 = iVar8 + 4) {
      }
      iVar8 = extraout_ECX[2] - *extraout_ECX >> 2;
      if (iVar8 != 0) {
        FUN_0040189d(*extraout_ECX,iVar8 << 2);
      }
      iVar8 = *(int *)(unaff_EBP + 0xc);
      *extraout_ECX = iVar7;
      extraout_ECX[1] = iVar9;
      extraout_ECX[2] = iVar7 + iVar8 * 4;
    }
    else {
      puVar3 = *(undefined1 **)(unaff_EBP + 0x10);
      *(undefined1 *)(unaff_EBP + 0xc) = *puVar3;
      *(undefined1 *)(unaff_EBP + 0xd) = puVar3[1];
      uVar1 = puVar3[3];
      *(undefined1 *)(unaff_EBP + 0xe) = puVar3[2];
      *(undefined1 *)(unaff_EBP + 0xf) = uVar1;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      iVar7 = *(int *)(unaff_EBP + 8);
      *(int *)(unaff_EBP + 8) = iVar8 - iVar7 >> 2;
      iVar8 = extraout_ECX[1];
      *(int *)(unaff_EBP + 0x10) = iVar8;
      if (uVar2 < *(uint *)(unaff_EBP + 8)) {
        *(int *)(unaff_EBP + 8) = iVar8;
        *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + uVar2 * -4;
        FUN_0047d986(*(undefined4 *)(unaff_EBP + 8),iVar8,iVar8,*(undefined4 *)(unaff_EBP + 8));
        extraout_ECX[1] = extraout_ECX[1] + uVar2 * 4;
        FUN_0047d919(iVar7,*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0x10),
                     *(undefined4 *)(unaff_EBP + 8),0);
        iVar8 = uVar2 * 4 + iVar7;
        for (; iVar7 != iVar8; iVar7 = iVar7 + 4) {
          FUN_0047d85b(unaff_EBP + 0xc);
        }
      }
      else {
        iVar9 = uVar2 - *(int *)(unaff_EBP + 8);
        FUN_0047d9b7(iVar8,iVar9,unaff_EBP + 0xc,*(undefined4 *)(unaff_EBP + 8));
        uVar6 = *(undefined4 *)(unaff_EBP + 8);
        extraout_ECX[1] = extraout_ECX[1] + iVar9 * 4;
        FUN_0047d986(iVar7,*(undefined4 *)(unaff_EBP + 0x10),extraout_ECX[1],uVar6);
        extraout_ECX[1] = extraout_ECX[1] + *(int *)(unaff_EBP + 8) * 4;
        for (; iVar7 != *(int *)(unaff_EBP + 0x10); iVar7 = iVar7 + 4) {
          FUN_0047d85b(unaff_EBP + 0xc);
        }
      }
    }
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

