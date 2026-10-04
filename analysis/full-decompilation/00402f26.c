
void FUN_00402f26(void)

{
  undefined2 uVar1;
  undefined2 *puVar2;
  int iVar3;
  int iVar4;
  undefined2 *puVar5;
  int iVar6;
  int iVar7;
  int *extraout_ECX;
  undefined2 *puVar8;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffe8;
  puVar5 = (undefined2 *)extraout_ECX[1];
  if (puVar5 == (undefined2 *)extraout_ECX[2]) {
    iVar4 = (int)puVar5 - *extraout_ECX >> 1;
    if (iVar4 == 0) {
      *(undefined4 *)(unaff_EBP + -0x14) = 1;
      iVar4 = *(int *)(unaff_EBP + -0x14);
    }
    else {
      iVar4 = iVar4 * 2;
      *(int *)(unaff_EBP + -0x14) = iVar4;
    }
    if (iVar4 == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = FUN_00401742(iVar4 * 2);
    }
    iVar3 = *extraout_ECX;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    *(int *)(unaff_EBP + -0x18) = iVar4;
    puVar5 = (undefined2 *)
             FUN_004031c7(iVar3,*(undefined4 *)(unaff_EBP + 8),iVar4,*(undefined4 *)(unaff_EBP + 8),
                          0);
    if (puVar5 != (undefined2 *)0x0) {
      *puVar5 = **(undefined2 **)(unaff_EBP + 0xc);
    }
    iVar6 = FUN_004031c7(*(undefined4 *)(unaff_EBP + 8),extraout_ECX[1],puVar5 + 1,
                         *(undefined4 *)(unaff_EBP + 8),0);
    iVar3 = *extraout_ECX;
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    iVar7 = extraout_ECX[2] - iVar3 >> 1;
    if (iVar7 != 0) {
      FUN_0040189d(iVar3,iVar7 * 2);
    }
    iVar3 = *(int *)(unaff_EBP + -0x14);
    *extraout_ECX = iVar4;
    extraout_ECX[1] = iVar6;
    extraout_ECX[2] = iVar4 + iVar3 * 2;
  }
  else {
    if (puVar5 != (undefined2 *)0x0) {
      *puVar5 = puVar5[-1];
    }
    extraout_ECX[1] = extraout_ECX[1] + 2;
    puVar5 = (undefined2 *)(extraout_ECX[1] + -4);
    puVar8 = (undefined2 *)(extraout_ECX[1] + -2);
    uVar1 = **(undefined2 **)(unaff_EBP + 0xc);
    puVar2 = *(undefined2 **)(unaff_EBP + 8);
    iVar4 = (int)puVar5 - (int)puVar2 >> 1;
    if (0 < iVar4) {
      do {
        puVar5 = puVar5 + -1;
        puVar8 = puVar8 + -1;
        iVar4 = iVar4 + -1;
        *puVar8 = *puVar5;
      } while (iVar4 != 0);
    }
    *puVar2 = uVar1;
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

