
void FUN_00544228(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int extraout_ECX;
  int iVar7;
  int unaff_EBP;
  int iVar8;
  
  FUN_00634c24();
  if (*(int *)(extraout_ECX + 0xdc) - *(int *)(extraout_ECX + 0xd8) >> 2 != 0) {
    *(undefined4 *)(unaff_EBP + -0x34) = 0;
    *(undefined4 *)(unaff_EBP + -0x30) = 0;
    *(undefined4 *)(unaff_EBP + -0x2c) = 0;
    *(undefined4 *)(unaff_EBP + -0x28) = 0;
    *(undefined4 *)(unaff_EBP + -0x24) = 0;
    *(undefined4 *)(unaff_EBP + -0x20) = 0;
    *(undefined4 *)(unaff_EBP + -0x1c) = 0;
    *(undefined4 *)(unaff_EBP + -0x18) = 0;
    *(undefined4 *)(unaff_EBP + -0x14) = 1;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    piVar1 = *(int **)(extraout_ECX + 0xd8);
    *(int **)(unaff_EBP + -0x10) = piVar1;
    iVar2 = *(int *)(extraout_ECX + 0x104);
    iVar3 = *piVar1;
    iVar4 = *(int *)(extraout_ECX + 0x100);
    iVar5 = *(int *)(extraout_ECX + 0x108);
    iVar8 = *(int *)(iVar3 + 0x84) - *(int *)(iVar3 + 0x7c);
    iVar3 = *(int *)(extraout_ECX + 0xdc);
    iVar6 = *(int *)(extraout_ECX + 0xd8);
    *(int *)(unaff_EBP + -0x28) = iVar2;
    iVar7 = -(iVar4 * iVar2);
    *(int *)(unaff_EBP + -0x20) = (iVar3 - iVar6 >> 2) * iVar2 + iVar7 + iVar5;
    iVar3 = *(int *)(extraout_ECX + 0xdc);
    iVar4 = *(int *)(extraout_ECX + 0xd8);
    *(undefined4 *)(unaff_EBP + -0x2c) = 0;
    *(undefined4 *)(unaff_EBP + -0x34) = 0;
    *(int *)(unaff_EBP + -0x30) = iVar7 + iVar5;
    *(int *)(unaff_EBP + -0x24) = iVar8;
    *(int *)(unaff_EBP + -0x1c) = iVar8;
    *(int *)(unaff_EBP + -0x18) = iVar2;
    FUN_004ebf01(*(undefined4 *)(unaff_EBP + -0x10),iVar3 - iVar4 >> 2);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

