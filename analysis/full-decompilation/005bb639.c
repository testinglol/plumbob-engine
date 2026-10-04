
void FUN_005bb639(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  int extraout_ECX;
  int unaff_EBP;
  int *piVar7;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  uVar6 = *(undefined4 *)(extraout_ECX + 4);
  uVar1 = *(undefined4 *)(extraout_ECX + 8);
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffe4;
  *(int *)(unaff_EBP + -0x1c) = extraout_ECX;
  FUN_0052ea87(uVar6,uVar1);
  iVar2 = *(int *)(unaff_EBP + 8);
  FUN_005bae8b(*(int *)(iVar2 + 8) - *(int *)(iVar2 + 4) >> 2);
  iVar3 = *(int *)(iVar2 + 8);
  iVar4 = *(int *)(iVar2 + 4);
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  FUN_005bb144(*(undefined4 *)(extraout_ECX + 8),iVar3 - iVar4 >> 2,unaff_EBP + -0x18);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + 8) = 0;
  while (*(uint *)(unaff_EBP + 8) < (uint)(*(int *)(iVar2 + 8) - *(int *)(iVar2 + 4) >> 2)) {
    piVar7 = *(int **)(*(int *)(iVar2 + 4) + *(int *)(unaff_EBP + 8) * 4);
    if (piVar7 != (int *)0x0) {
      uVar6 = FUN_005bbd6c(piVar7 + 1);
      iVar3 = *(int *)(extraout_ECX + 4);
      *(undefined4 *)(unaff_EBP + -0x14) = uVar6;
      *(undefined4 *)(iVar3 + *(int *)(unaff_EBP + 8) * 4) = uVar6;
      while (piVar7 = (int *)*piVar7, piVar7 != (int *)0x0) {
        uVar6 = FUN_005bbd6c(piVar7 + 1);
        puVar5 = *(undefined4 **)(unaff_EBP + -0x14);
        *(undefined4 *)(unaff_EBP + -0x14) = uVar6;
        *puVar5 = uVar6;
      }
    }
    *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 1;
  }
  uVar6 = *(undefined4 *)(unaff_EBP + -0xc);
  *(undefined4 *)(extraout_ECX + 0x10) = *(undefined4 *)(iVar2 + 0x10);
  *unaff_FS_OFFSET = uVar6;
  return;
}

