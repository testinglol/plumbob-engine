
void FUN_00598c79(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  int extraout_ECX;
  int iVar7;
  int unaff_EBP;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x1c) = extraout_ECX;
  iVar6 = *(int *)(extraout_ECX + 0x80);
  *(undefined4 *)(unaff_EBP + -4) = 7;
  uVar5 = iVar6 - *(int *)(extraout_ECX + 0x7c);
  while ((uVar5 & 0xfffffffc) != 0) {
    FUN_005991b7(**(undefined4 **)(extraout_ECX + 0x7c));
    uVar5 = *(int *)(extraout_ECX + 0x80) - *(int *)(extraout_ECX + 0x7c);
  }
  piVar2 = (int *)(extraout_ECX + 0x88);
  while ((*(int *)(extraout_ECX + 0x8c) - *piVar2 & 0xfffffffcU) != 0) {
    FUN_00599480(*(undefined4 *)*piVar2);
  }
  iVar6 = *(int *)(extraout_ECX + 0x68);
  piVar1 = (int *)(extraout_ECX + 100);
  iVar7 = 0;
  iVar3 = *piVar1;
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  iVar6 = iVar6 - iVar3 >> 2;
  *(int *)(unaff_EBP + -0x18) = iVar6;
  if (0 < iVar6) {
    do {
      iVar6 = *(int *)(*piVar1 + iVar7 * 4);
      *(int *)(unaff_EBP + -0x14) = iVar6;
      if (iVar6 != 0) {
        FUN_00595e9a();
        FUN_006321f0(*(undefined4 *)(unaff_EBP + -0x14));
      }
      iVar7 = *(int *)(unaff_EBP + -0x10) + 1;
      *(int *)(unaff_EBP + -0x10) = iVar7;
    } while (iVar7 < *(int *)(unaff_EBP + -0x18));
  }
  iVar6 = *piVar2;
  *(undefined1 *)(unaff_EBP + -4) = 5;
  *(int *)(unaff_EBP + -0x18) = iVar6;
  FUN_0048c4c9();
  uVar4 = *(undefined4 *)(extraout_ECX + 0x7c);
  *(undefined1 *)(unaff_EBP + -4) = 4;
  *(undefined4 *)(unaff_EBP + -0x18) = uVar4;
  FUN_0048c4c9();
  uVar4 = *(undefined4 *)(extraout_ECX + 0x70);
  *(undefined1 *)(unaff_EBP + -4) = 3;
  *(undefined4 *)(unaff_EBP + -0x18) = uVar4;
  FUN_0048c4c9();
  iVar6 = *piVar1;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  *(int *)(unaff_EBP + -0x18) = iVar6;
  FUN_0048c4c9();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005c4890();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005b8770();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

