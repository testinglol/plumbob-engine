
undefined4 FUN_00489bba(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 extraout_ECX;
  int iVar3;
  int iVar4;
  int iVar5;
  int unaff_EBP;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x18) = extraout_ECX;
  uVar1 = FUN_00492b26();
  *(undefined4 *)(unaff_EBP + -0x14) = uVar1;
  iVar7 = (int)**(char **)(unaff_EBP + 0xc);
  iVar3 = (int)**(char **)(unaff_EBP + 8);
  iVar4 = (int)(*(char **)(unaff_EBP + 8))[1];
  iVar6 = (int)(*(char **)(unaff_EBP + 0xc))[1];
  *(int *)(unaff_EBP + -0x10) = iVar4;
  iVar5 = iVar3;
  if (iVar7 < iVar3) {
    iVar5 = iVar7;
    iVar7 = iVar3;
  }
  if (iVar6 < iVar4) {
    *(int *)(unaff_EBP + -0x10) = iVar6;
    iVar6 = iVar4;
  }
  *(int *)(unaff_EBP + 8) = iVar5;
  while (iVar5 <= iVar7) {
    for (iVar5 = *(int *)(unaff_EBP + -0x10); iVar5 <= iVar6; iVar5 = iVar5 + 1) {
      *(char *)(unaff_EBP + 0xd) = (char)iVar5;
      *(undefined1 *)(unaff_EBP + 0xc) = *(undefined1 *)(unaff_EBP + 8);
      uVar1 = *(undefined4 *)(unaff_EBP + -0x14);
      *(char *)(unaff_EBP + 0xe) = (char)uVar1;
      uVar10 = 1;
      uVar9 = 0;
      uVar8 = *(undefined4 *)(unaff_EBP + 0x10);
      *(undefined4 *)(unaff_EBP + -4) = 0;
      uVar2 = FUN_00434d3d(unaff_EBP + -0x20);
      FUN_00488de7(uVar2,uVar1,uVar8,uVar9,uVar10);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    }
    *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 1;
    iVar5 = *(int *)(unaff_EBP + 8);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 1;
}

