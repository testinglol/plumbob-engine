
void FUN_004d4315(void)

{
  undefined2 uVar1;
  undefined2 *puVar2;
  int iVar3;
  undefined2 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *extraout_ECX;
  undefined2 *puVar8;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffe4;
  puVar4 = (undefined2 *)extraout_ECX[1];
  if (puVar4 == (undefined2 *)extraout_ECX[2]) {
    iVar3 = (int)puVar4 - *extraout_ECX >> 1;
    if (iVar3 == 0) {
      *(undefined4 *)(unaff_EBP + -0x14) = 1;
      iVar3 = *(int *)(unaff_EBP + -0x14);
    }
    else {
      iVar3 = iVar3 * 2;
      *(int *)(unaff_EBP + -0x14) = iVar3;
    }
    if (iVar3 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_00401742(iVar3 * 2);
    }
    iVar7 = *extraout_ECX;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    *(int *)(unaff_EBP + -0x18) = iVar3;
    *(int *)(unaff_EBP + -0x1c) = iVar3;
    puVar4 = (undefined2 *)
             FUN_004d4477(iVar7,*(undefined4 *)(unaff_EBP + 8),iVar3,*(undefined4 *)(unaff_EBP + 8))
    ;
    if (puVar4 != (undefined2 *)0x0) {
      *puVar4 = **(undefined2 **)(unaff_EBP + 0xc);
    }
    iVar5 = FUN_004d4477(*(undefined4 *)(unaff_EBP + 8),extraout_ECX[1],puVar4 + 1,
                         *(undefined4 *)(unaff_EBP + 8));
    iVar7 = extraout_ECX[1];
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    for (iVar6 = *extraout_ECX; iVar6 != iVar7; iVar6 = iVar6 + 2) {
    }
    iVar7 = extraout_ECX[2] - *extraout_ECX >> 1;
    if (iVar7 != 0) {
      FUN_0040189d(*extraout_ECX,iVar7 * 2);
    }
    iVar7 = *(int *)(unaff_EBP + -0x14);
    *extraout_ECX = iVar3;
    extraout_ECX[1] = iVar5;
    extraout_ECX[2] = iVar3 + iVar7 * 2;
  }
  else {
    if (puVar4 != (undefined2 *)0x0) {
      *puVar4 = puVar4[-1];
    }
    extraout_ECX[1] = extraout_ECX[1] + 2;
    puVar4 = (undefined2 *)(extraout_ECX[1] + -4);
    puVar8 = (undefined2 *)(extraout_ECX[1] + -2);
    uVar1 = **(undefined2 **)(unaff_EBP + 0xc);
    puVar2 = *(undefined2 **)(unaff_EBP + 8);
    iVar3 = (int)puVar4 - (int)puVar2 >> 1;
    if (0 < iVar3) {
      do {
        puVar4 = puVar4 + -1;
        puVar8 = puVar8 + -1;
        iVar3 = iVar3 + -1;
        *puVar8 = *puVar4;
      } while (iVar3 != 0);
    }
    *puVar2 = uVar1;
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

