
void FUN_00534461(void)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  int *extraout_ECX;
  int *piVar4;
  int iVar5;
  int unaff_EBP;
  int iVar6;
  int iVar7;
  
  FUN_00634c24();
  uVar1 = *(uint *)(unaff_EBP + 0xc);
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffc0;
  if (uVar1 != 0) {
    if ((uint)((extraout_ECX[2] - extraout_ECX[1]) / 0x28) < uVar1) {
      uVar2 = (extraout_ECX[1] - *extraout_ECX) / 0x28;
      piVar4 = (int *)(unaff_EBP + 0xc);
      *(uint *)(unaff_EBP + -0x18) = uVar2;
      if (uVar1 <= uVar2) {
        piVar4 = (int *)(unaff_EBP + -0x18);
      }
      iVar6 = uVar2 + *piVar4;
      *(int *)(unaff_EBP + -0x18) = iVar6;
      if (iVar6 == 0) {
        iVar6 = 0;
      }
      else {
        iVar6 = FUN_00401742(iVar6 * 0x28);
      }
      iVar5 = *extraout_ECX;
      *(int *)(unaff_EBP + -0x14) = iVar6;
      *(int *)(unaff_EBP + 0xc) = iVar6;
      *(undefined4 *)(unaff_EBP + -4) = 1;
      uVar3 = FUN_00534b96(iVar5,*(undefined4 *)(unaff_EBP + 8),iVar6,*(undefined4 *)(unaff_EBP + 8)
                          );
      *(undefined4 *)(unaff_EBP + 0xc) = uVar3;
      uVar3 = FUN_00534c0a(uVar3,uVar1,*(undefined4 *)(unaff_EBP + 0x10),
                           *(undefined4 *)(unaff_EBP + 8));
      *(undefined4 *)(unaff_EBP + 0xc) = uVar3;
      uVar3 = FUN_00534b96(*(undefined4 *)(unaff_EBP + 8),extraout_ECX[1],
                           *(undefined4 *)(unaff_EBP + 0xc),*(undefined4 *)(unaff_EBP + 8));
      iVar5 = *extraout_ECX;
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      *(undefined4 *)(unaff_EBP + 0x10) = uVar3;
      iVar7 = extraout_ECX[1];
      *(int *)(unaff_EBP + 8) = iVar7;
      if (iVar5 != iVar7) {
        do {
          FUN_005b8770();
          iVar5 = iVar5 + 0x28;
        } while (iVar5 != *(int *)(unaff_EBP + 8));
      }
      iVar5 = (extraout_ECX[2] - *extraout_ECX) / 0x28;
      if (iVar5 != 0) {
        FUN_0040189d(*extraout_ECX,iVar5 * 0x28);
      }
      iVar5 = *(int *)(unaff_EBP + 0x10);
      *extraout_ECX = iVar6;
      extraout_ECX[1] = iVar5;
      extraout_ECX[2] = iVar6 + *(int *)(unaff_EBP + -0x18) * 0x28;
    }
    else {
      FUN_00533d58(*(undefined4 *)(unaff_EBP + 0x10));
      iVar6 = extraout_ECX[1];
      iVar5 = *(int *)(unaff_EBP + 8);
      *(undefined4 *)(unaff_EBP + -4) = 0;
      *(int *)(unaff_EBP + 8) = (iVar6 - iVar5) / 0x28;
      iVar6 = extraout_ECX[1];
      *(int *)(unaff_EBP + 0xc) = iVar6;
      if (uVar1 < *(uint *)(unaff_EBP + 8)) {
        *(int *)(unaff_EBP + 8) = iVar6;
        *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + uVar1 * -0x28;
        FUN_00534b96(*(undefined4 *)(unaff_EBP + 8),iVar6,iVar6,*(undefined4 *)(unaff_EBP + 8));
        extraout_ECX[1] = extraout_ECX[1] + uVar1 * 0x28;
        FUN_00534b01(iVar5,*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc),
                     *(undefined4 *)(unaff_EBP + 8),0);
        iVar6 = uVar1 * 0x28 + iVar5;
        for (; iVar5 != iVar6; iVar5 = iVar5 + 0x28) {
          FUN_00533dae(unaff_EBP + -0x40);
        }
      }
      else {
        iVar7 = uVar1 - *(int *)(unaff_EBP + 8);
        FUN_00534c0a(iVar6,iVar7,unaff_EBP + -0x40,*(undefined4 *)(unaff_EBP + 8));
        uVar3 = *(undefined4 *)(unaff_EBP + 8);
        extraout_ECX[1] = extraout_ECX[1] + iVar7 * 0x28;
        FUN_00534b96(iVar5,*(undefined4 *)(unaff_EBP + 0xc),extraout_ECX[1],uVar3);
        extraout_ECX[1] = extraout_ECX[1] + *(int *)(unaff_EBP + 8) * 0x28;
        for (; iVar5 != *(int *)(unaff_EBP + 0xc); iVar5 = iVar5 + 0x28) {
          FUN_00533dae(unaff_EBP + -0x40);
        }
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

