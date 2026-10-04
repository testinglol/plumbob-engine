
void FUN_0059bce9(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int *extraout_ECX;
  int iVar7;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffe8;
  puVar6 = (undefined4 *)extraout_ECX[1];
  if (puVar6 == (undefined4 *)extraout_ECX[2]) {
    iVar7 = (int)puVar6 - *extraout_ECX >> 2;
    if (iVar7 == 0) {
      *(undefined4 *)(unaff_EBP + -0x14) = 1;
    }
    else {
      *(int *)(unaff_EBP + -0x14) = iVar7 * 2;
    }
    if (*(int *)(unaff_EBP + -0x14) == 0) {
      iVar7 = 0;
    }
    else {
      iVar7 = FUN_0041e684(*(int *)(unaff_EBP + -0x14) << 4);
    }
    iVar5 = *extraout_ECX;
    *(int *)(unaff_EBP + -0x18) = iVar7;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    puVar6 = (undefined4 *)
             FUN_00430957(iVar5,*(undefined4 *)(unaff_EBP + 8),iVar7,*(undefined4 *)(unaff_EBP + 8),
                          0);
    if (puVar6 != (undefined4 *)0x0) {
      *puVar6 = **(undefined4 **)(unaff_EBP + 0xc);
    }
    iVar5 = FUN_00430957(*(undefined4 *)(unaff_EBP + 8),extraout_ECX[1],puVar6 + 1,
                         *(undefined4 *)(unaff_EBP + 8),0);
    if ((extraout_ECX[2] - *extraout_ECX & 0xfffffffcU) != 0) {
      FUN_0041d9a9(*extraout_ECX);
    }
    iVar4 = *(int *)(unaff_EBP + -0x14);
    *extraout_ECX = iVar7;
    extraout_ECX[1] = iVar5;
    extraout_ECX[2] = iVar7 + iVar4 * 4;
  }
  else {
    if (puVar6 != (undefined4 *)0x0) {
      *puVar6 = puVar6[-1];
    }
    extraout_ECX[1] = extraout_ECX[1] + 4;
    iVar7 = extraout_ECX[1] + -8;
    puVar6 = (undefined4 *)(extraout_ECX[1] + -4);
    uVar2 = **(undefined4 **)(unaff_EBP + 0xc);
    puVar3 = *(undefined4 **)(unaff_EBP + 8);
    iVar5 = iVar7 - (int)puVar3 >> 2;
    if (0 < iVar5) {
      do {
        puVar1 = (undefined4 *)(iVar7 + -4);
        iVar7 = iVar7 + -4;
        puVar6 = puVar6 + -1;
        iVar5 = iVar5 + -1;
        *puVar6 = *puVar1;
      } while (iVar5 != 0);
    }
    *puVar3 = uVar2;
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

