
undefined4 FUN_0047736d(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  undefined1 *puVar5;
  int extraout_ECX;
  undefined1 *puVar6;
  int unaff_EBP;
  int iVar7;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x18) = extraout_ECX;
  if (extraout_ECX != *(int *)(unaff_EBP + 8)) {
    iVar7 = *(int *)(*(int *)(unaff_EBP + 8) + 0xc);
    iVar1 = *(int *)(extraout_ECX + 0xc);
    *(int *)(unaff_EBP + -0x14) = iVar7;
    *(int *)(unaff_EBP + -0x10) = iVar1;
    piVar3 = (int *)(unaff_EBP + -0x14);
    if (iVar1 <= iVar7) {
      piVar3 = (int *)(unaff_EBP + -0x10);
    }
    iVar7 = *piVar3;
    *(undefined4 *)(unaff_EBP + -0x10) = 0;
    *(int *)(unaff_EBP + -0x14) = iVar7;
    if (0 < iVar7) {
      do {
        iVar7 = 0;
        do {
          piVar3 = (int *)FUN_0047c7b7(unaff_EBP + -0x1c,*(undefined4 *)(unaff_EBP + -0x10));
          *(undefined4 *)(unaff_EBP + -4) = 0;
          piVar4 = (int *)FUN_0047c7b7(unaff_EBP + -0x20,*(undefined4 *)(unaff_EBP + -0x10));
          iVar1 = *piVar3;
          iVar2 = *piVar4;
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          puVar6 = (undefined1 *)(iVar1 + iVar7);
          puVar5 = (undefined1 *)(iVar2 + iVar7);
          iVar7 = iVar7 + 1;
          iVar1 = *(int *)(unaff_EBP + -0x14);
          *puVar5 = *puVar6;
        } while (iVar7 < iVar1);
        *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
      } while (*(int *)(unaff_EBP + -0x10) < *(int *)(unaff_EBP + -0x14));
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x18);
}

