
void FUN_00401674(void)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  int *extraout_ECX;
  undefined1 *puVar6;
  undefined1 *puVar7;
  int unaff_EBP;
  undefined1 *puVar8;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffec;
  if (*(int *)(unaff_EBP + 8) == -1) {
    FUN_004018ec();
  }
  iVar5 = extraout_ECX[1];
  iVar2 = *extraout_ECX;
  *(int *)(unaff_EBP + -0x14) = iVar5 - iVar2;
  piVar4 = (int *)(unaff_EBP + -0x14);
  if ((uint)(iVar5 - iVar2) <= *(uint *)(unaff_EBP + 8)) {
    piVar4 = (int *)(unaff_EBP + 8);
  }
  iVar5 = *piVar4 + 1;
  *(int *)(unaff_EBP + 8) = iVar5;
  if (iVar5 == 0) {
    puVar7 = (undefined1 *)0x0;
  }
  else {
    puVar7 = (undefined1 *)FUN_00401742(iVar5);
  }
  iVar5 = extraout_ECX[1];
  puVar6 = (undefined1 *)*extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined1 **)(unaff_EBP + -0x14) = puVar7;
  puVar8 = puVar7;
  for (iVar5 = iVar5 - (int)puVar6; 0 < iVar5; iVar5 = iVar5 + -1) {
    uVar1 = *puVar6;
    puVar6 = puVar6 + 1;
    *puVar8 = uVar1;
    puVar8 = puVar8 + 1;
  }
  FUN_00401651(puVar8);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00401729();
  iVar5 = *(int *)(unaff_EBP + 8);
  uVar3 = *(undefined4 *)(unaff_EBP + -0xc);
  *extraout_ECX = (int)puVar7;
  extraout_ECX[1] = (int)puVar8;
  extraout_ECX[2] = (int)(puVar7 + iVar5);
  *unaff_FS_OFFSET = uVar3;
  return;
}

