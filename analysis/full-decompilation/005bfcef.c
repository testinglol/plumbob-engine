
int * FUN_005bfcef(void)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int *extraout_ECX;
  int iVar5;
  uint uVar6;
  int unaff_EBP;
  uint uVar7;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  iVar5 = *(int *)(unaff_EBP + 0xc);
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffec;
  if (*(int *)(unaff_EBP + 8) != iVar5) {
    uVar6 = iVar5 - *(int *)(unaff_EBP + 8) >> 1;
    uVar7 = extraout_ECX[1] - *extraout_ECX >> 1;
    *(uint *)(unaff_EBP + -0x14) = uVar7;
    if ((0x7ffffffe < uVar6) || (0x7ffffffe - uVar6 < uVar7)) {
      FUN_005bdc67();
      iVar5 = *(int *)(unaff_EBP + 0xc);
    }
    if ((extraout_ECX[2] - *extraout_ECX >> 1) - 1U < uVar6 + uVar7) {
      *(uint *)(unaff_EBP + 0xc) = uVar6;
      piVar2 = (int *)(unaff_EBP + 0xc);
      if (uVar6 <= uVar7) {
        piVar2 = (int *)(unaff_EBP + -0x14);
      }
      iVar5 = *piVar2 + 1 + uVar7;
      *(int *)(unaff_EBP + -0x14) = iVar5;
      if (iVar5 == 0) {
        *(undefined4 *)(unaff_EBP + 0xc) = 0;
      }
      else {
        uVar3 = FUN_00401742(iVar5 * 2);
        *(undefined4 *)(unaff_EBP + 0xc) = uVar3;
      }
      iVar5 = extraout_ECX[1];
      iVar1 = *extraout_ECX;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      iVar4 = FUN_004031c7(iVar1,iVar5,*(undefined4 *)(unaff_EBP + 0xc),
                           *(undefined4 *)(unaff_EBP + 8),0);
      FUN_00635190(iVar4,*(undefined4 *)(unaff_EBP + 8),uVar6 * 2);
      iVar4 = iVar4 + uVar6 * 2;
      FUN_005bd7e5(iVar4);
      FUN_005bdc4a();
      iVar5 = *(int *)(unaff_EBP + 0xc);
      iVar1 = *(int *)(unaff_EBP + -0x14);
      *extraout_ECX = iVar5;
      extraout_ECX[1] = iVar4;
      extraout_ECX[2] = iVar5 + iVar1 * 2;
    }
    else {
      iVar1 = *(int *)(unaff_EBP + 8) + 2;
      FUN_00635190(extraout_ECX[1] + 2,iVar1,(iVar5 - iVar1 >> 1) << 1);
      iVar5 = extraout_ECX[1];
      *(undefined4 *)(unaff_EBP + -4) = 2;
      FUN_005bd7e5(uVar6 * 2 + iVar5);
      *(undefined2 *)extraout_ECX[1] = **(undefined2 **)(unaff_EBP + 8);
      extraout_ECX[1] = extraout_ECX[1] + uVar6 * 2;
    }
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return extraout_ECX;
}

