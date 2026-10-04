
void FUN_00475e2d(void)

{
  undefined2 extraout_var;
  void *pvVar1;
  undefined4 uVar2;
  int extraout_ECX;
  int iVar3;
  int unaff_EBP;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  iVar3 = *(int *)(unaff_EBP + 8);
  *(uint *)(unaff_EBP + -0x18) = CONCAT22(extraout_var,*(undefined2 *)(extraout_ECX + 4));
  *(undefined4 *)(unaff_EBP + -0x14) = 9;
  FUN_00464973(unaff_EBP + -0x18,1);
  FUN_00464973(unaff_EBP + -0x14,1);
  if (8 < *(short *)(unaff_EBP + -0x14)) {
    *(undefined1 *)(unaff_EBP + -0xd) = 1;
    FUN_0046494e(unaff_EBP + -0xd);
    if (*(char *)(unaff_EBP + -0xd) != '\0') {
      FUN_004645e3();
    }
  }
  iVar4 = 0;
  **(undefined2 **)(unaff_EBP + 0xc) = *(undefined2 *)(unaff_EBP + -0x14);
  if (*(int *)(iVar3 + 0xc) == 0) {
    if (*(int *)(extraout_ECX + 0x10) != 0) {
      if (0 < *(int *)(extraout_ECX + 4)) {
        do {
          iVar3 = *(int *)(*(int *)(extraout_ECX + 0x10) + iVar4 * 4);
          if (iVar3 != 0) {
            FUN_00476018();
            FUN_006321f0(iVar3);
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < *(int *)(extraout_ECX + 4));
        iVar3 = *(int *)(unaff_EBP + 8);
      }
      FUN_006321f0(*(undefined4 *)(extraout_ECX + 0x10));
      *(undefined4 *)(extraout_ECX + 0x10) = 0;
    }
    if (*(short *)(unaff_EBP + -0x18) == 0) {
      *(undefined4 *)(extraout_ECX + 0x10) = 0;
    }
    else {
      pvVar1 = operator_new((int)*(short *)(unaff_EBP + -0x18) << 2);
      *(void **)(extraout_ECX + 0x10) = pvVar1;
    }
  }
  if ((*(short *)(unaff_EBP + -0x14) < 8) && (6 < *(short *)(unaff_EBP + -0x14))) {
    FUN_00464567(*(undefined4 *)(extraout_ECX + 0x14),0x54544173,
                 *(undefined2 *)(extraout_ECX + 0x18));
  }
  iVar4 = 0;
  if (0 < *(short *)(unaff_EBP + -0x18)) {
    while( true ) {
      if (*(int *)(iVar3 + 0xc) == 0) {
        pvVar1 = operator_new(0x30);
        *(void **)(unaff_EBP + 0xc) = pvVar1;
        *(undefined4 *)(unaff_EBP + -4) = 0;
        if (pvVar1 == (void *)0x0) {
          uVar2 = 0;
        }
        else {
          uVar2 = FUN_00475f90(*(undefined4 *)(extraout_ECX + 8));
        }
        iVar3 = *(int *)(extraout_ECX + 0x10);
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        *(undefined4 *)(iVar3 + iVar4 * 4) = uVar2;
      }
      iVar3 = *(int *)(*(int *)(extraout_ECX + 0x10) + iVar4 * 4);
      FUN_004760ae(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + -0x14));
      if (*(short *)(unaff_EBP + -0x14) < 4) {
        *(int *)(iVar3 + 0x18) = iVar4;
      }
      iVar4 = iVar4 + 1;
      if (*(short *)(unaff_EBP + -0x18) <= iVar4) break;
      iVar3 = *(int *)(unaff_EBP + 8);
    }
  }
  uVar2 = *(undefined4 *)(unaff_EBP + -0xc);
  *(int *)(extraout_ECX + 4) = (int)*(short *)(unaff_EBP + -0x18);
  *unaff_FS_OFFSET = uVar2;
  return;
}

