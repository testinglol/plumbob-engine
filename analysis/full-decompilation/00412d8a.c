
int * FUN_00412d8a(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  int *extraout_ECX;
  int unaff_EBP;
  uint uVar7;
  
  FUN_00634c24();
  iVar2 = *(int *)(unaff_EBP + 0xc);
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffe8;
  if (*(int *)(unaff_EBP + 8) != iVar2) {
    uVar3 = iVar2 - *(int *)(unaff_EBP + 8);
    uVar7 = extraout_ECX[1] - *extraout_ECX;
    *(uint *)(unaff_EBP + -0x14) = uVar7;
    *(uint *)(unaff_EBP + -0x18) = uVar3;
    if ((uVar3 == 0xffffffff) || (-uVar3 - 2 < uVar7)) {
      FUN_004018ec();
      uVar3 = *(uint *)(unaff_EBP + -0x18);
    }
    if ((extraout_ECX[2] - *extraout_ECX) - 1U < uVar3 + uVar7) {
      *(uint *)(unaff_EBP + 0xc) = uVar3;
      piVar4 = (int *)(unaff_EBP + 0xc);
      if (uVar3 <= uVar7) {
        piVar4 = (int *)(unaff_EBP + -0x14);
      }
      iVar1 = *piVar4 + 1 + uVar7;
      *(int *)(unaff_EBP + -0x14) = iVar1;
      if (iVar1 == 0) {
        *(undefined4 *)(unaff_EBP + 0xc) = 0;
      }
      else {
        uVar5 = FUN_00401742(iVar1);
        *(undefined4 *)(unaff_EBP + 0xc) = uVar5;
      }
      iVar1 = extraout_ECX[1];
      iVar6 = *extraout_ECX;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      iVar6 = FUN_004746d5(iVar6,iVar1,*(undefined4 *)(unaff_EBP + 0xc),
                           *(undefined4 *)(unaff_EBP + 8),0);
      FUN_00635190(iVar6,*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + -0x18));
      iVar6 = iVar6 + (iVar2 - *(int *)(unaff_EBP + 8));
      FUN_00401651(iVar6);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_00401729();
      iVar2 = *(int *)(unaff_EBP + 0xc);
      iVar1 = *(int *)(unaff_EBP + -0x14);
      *extraout_ECX = iVar2;
      extraout_ECX[1] = iVar6;
      extraout_ECX[2] = iVar2 + iVar1;
    }
    else {
      iVar1 = *(int *)(unaff_EBP + 8) + 1;
      FUN_00635190(extraout_ECX[1] + 1,iVar1,iVar2 - iVar1);
      iVar2 = extraout_ECX[1];
      iVar1 = *(int *)(unaff_EBP + -0x18);
      *(undefined4 *)(unaff_EBP + -4) = 2;
      FUN_00401651(iVar2 + iVar1);
      *(undefined1 *)extraout_ECX[1] = **(undefined1 **)(unaff_EBP + 8);
      extraout_ECX[1] = extraout_ECX[1] + iVar1;
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

