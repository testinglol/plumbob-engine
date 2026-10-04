
void FUN_0052a053(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int extraout_ECX;
  uint *puVar9;
  int iVar10;
  uint uVar11;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar6 = *(int *)(extraout_ECX + 0x114);
  puVar9 = (uint *)(extraout_ECX + 0x114);
  *(uint **)(unaff_EBP + -0x10) = puVar9;
  if (iVar6 == 0) {
    *puVar9 = 8;
  }
  uVar5 = (uint)(*(int *)(extraout_ECX + 0xf0) - *(int *)(extraout_ECX + 0xec) >> 2) / *puVar9;
  uVar11 = *(uint *)(unaff_EBP + 8);
  if ((int)uVar11 < 0) {
    uVar11 = 0;
  }
  else if ((int)(uVar5 + 1) <= (int)uVar11) {
    uVar11 = uVar5;
  }
  *(uint *)(extraout_ECX + 0x110) = uVar11;
  uVar11 = 0;
  if (*(int *)(extraout_ECX + 0xf0) - *(int *)(extraout_ECX + 0xec) >> 2 != 0) {
    do {
      if (((int)uVar11 < (int)(*(int *)(extraout_ECX + 0x110) * *puVar9)) ||
         ((int)((*(int *)(extraout_ECX + 0x110) + 1) * *puVar9) <= (int)uVar11)) {
        (**(code **)(**(int **)(*(int *)(extraout_ECX + 0xec) + uVar11 * 4) + 0x98))();
      }
      else {
        (**(code **)(**(int **)(*(int *)(extraout_ECX + 0xec) + uVar11 * 4) + 0x94))();
      }
      puVar9 = *(uint **)(unaff_EBP + -0x10);
      uVar11 = uVar11 + 1;
    } while (uVar11 < (uint)(*(int *)(extraout_ECX + 0xf0) - *(int *)(extraout_ECX + 0xec) >> 2));
  }
  if ((*(int *)(extraout_ECX + 0xf0) - *(int *)(extraout_ECX + 0xec) & 0xfffffffcU) != 0) {
    *(undefined4 *)(unaff_EBP + -0x38) = 0;
    *(undefined4 *)(unaff_EBP + -0x34) = 0;
    *(undefined4 *)(unaff_EBP + -0x30) = 0;
    *(undefined4 *)(unaff_EBP + -0x2c) = 0;
    *(undefined4 *)(unaff_EBP + -0x28) = 0;
    *(undefined4 *)(unaff_EBP + -0x24) = 0;
    *(undefined4 *)(unaff_EBP + -0x20) = 0;
    *(undefined4 *)(unaff_EBP + -0x1c) = 0;
    *(undefined4 *)(unaff_EBP + -0x18) = 0;
    piVar1 = *(int **)(extraout_ECX + 0xec);
    uVar11 = *puVar9;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    *(uint *)(unaff_EBP + 8) = uVar11;
    iVar6 = *piVar1;
    iVar2 = *(int *)(iVar6 + 0x84);
    iVar8 = *(int *)(iVar6 + 0x7c);
    iVar3 = *(int *)(iVar6 + 0x88);
    iVar6 = *(int *)(iVar6 + 0x80);
    iVar10 = *(int *)(extraout_ECX + 0x120);
    iVar4 = *(int *)(extraout_ECX + 0x11c);
    *(int *)(unaff_EBP + -0x34) = iVar10;
    *(int *)(unaff_EBP + -0x38) = iVar4;
    *(int *)(unaff_EBP + -0x28) = (iVar2 - iVar8) * ((int)uVar11 / 2) + iVar4;
    *(int *)(unaff_EBP + -0x24) = (iVar3 - iVar6) * 2 + iVar10;
    iVar6 = *piVar1;
    iVar2 = *(int *)(iVar6 + 0x88);
    iVar8 = *(int *)(iVar6 + 0x80);
    *(int *)(unaff_EBP + -0x30) = *(int *)(iVar6 + 0x84) - *(int *)(iVar6 + 0x7c);
    *(int *)(unaff_EBP + -0x2c) = iVar2 - iVar8;
    iVar6 = *piVar1;
    iVar2 = *(int *)(iVar6 + 0x84);
    iVar8 = *(int *)(iVar6 + 0x7c);
    iVar3 = *(int *)(extraout_ECX + 0xf0);
    *(int *)(unaff_EBP + -0x1c) = *(int *)(iVar6 + 0x88) - *(int *)(iVar6 + 0x80);
    iVar10 = *(int *)(unaff_EBP + 8) * *(int *)(extraout_ECX + 0x110);
    *(int *)(unaff_EBP + -0x20) = iVar2 - iVar8;
    iVar6 = iVar3 - (int)piVar1 >> 2;
    *(int *)(unaff_EBP + -0x14) = iVar6;
    *(int *)(unaff_EBP + 8) = iVar10;
    piVar7 = (int *)(unaff_EBP + -0x14);
    if (iVar10 <= iVar6) {
      piVar7 = (int *)(unaff_EBP + 8);
    }
    iVar6 = *piVar7;
    piVar7 = *(int **)(unaff_EBP + -0x10);
    iVar8 = (*(int *)(extraout_ECX + 0xf0) - *(int *)(extraout_ECX + 0xec) >> 2) - iVar6;
    iVar2 = *piVar7;
    *(int *)(unaff_EBP + 8) = iVar8;
    if (iVar8 <= iVar2) {
      piVar7 = (int *)(unaff_EBP + 8);
    }
    FUN_004ebf01(piVar1 + iVar6,*piVar7);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

