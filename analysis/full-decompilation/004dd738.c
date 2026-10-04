
undefined4 FUN_004dd738(void)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int unaff_EBP;
  undefined4 *puVar5;
  uint uVar6;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  *(undefined4 *)(unaff_EBP + -0x28) = 0;
  *(undefined4 *)(unaff_EBP + -0x24) = 0;
  *(undefined4 *)(unaff_EBP + -0x20) = 0;
  iVar3 = DAT_006e486c;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar2 = *(int *)(iVar3 + 0x24);
  puVar5 = *(undefined4 **)(iVar2 + 0x174);
  puVar1 = *(undefined4 **)(iVar2 + 0x178);
  if ((*(byte *)(iVar3 + 0x66) & 0x20) == 0) {
    iVar2 = 0;
    do {
      iVar2 = iVar2 + 1;
      iVar3 = FUN_00425ddf(iVar2);
      *(int *)(unaff_EBP + -0x10) = iVar3;
      if (iVar3 != 0) {
        FUN_0042eb8e(unaff_EBP + -0x10);
      }
    } while (iVar2 < 10);
  }
  else {
    for (; puVar5 != puVar1; puVar5 = puVar5 + 2) {
      if (puVar5[1] == 1) {
        iVar2 = FUN_00425ddf(*puVar5);
        *(int *)(unaff_EBP + -0x10) = iVar2;
        if (iVar2 != 0) {
          FUN_0042eb8e(unaff_EBP + -0x10);
        }
      }
    }
  }
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_004e1a40(unaff_EBP + -0x1c);
  uVar6 = 0;
  if (*(int *)(unaff_EBP + -0x18) - *(int *)(unaff_EBP + -0x1c) >> 2 != 0) {
    do {
      uVar4 = FUN_00425db3(*(undefined4 *)(*(int *)(unaff_EBP + -0x1c) + uVar6 * 4));
      *(undefined4 *)(unaff_EBP + -0x10) = uVar4;
      FUN_0042eb8e(unaff_EBP + -0x10);
      uVar6 = uVar6 + 1;
    } while (uVar6 < (uint)(*(int *)(unaff_EBP + -0x18) - *(int *)(unaff_EBP + -0x1c) >> 2));
  }
  uVar4 = FUN_004d6554(unaff_EBP + -0x34,
                       *(int *)(unaff_EBP + -0x24) - *(int *)(unaff_EBP + -0x28) >> 2);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005d499c(uVar4);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005b8770();
  uVar4 = FUN_005b870f(&DAT_006de560);
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_005d499c(uVar4);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005b8770();
  uVar4 = FUN_005b870f(&DAT_006de560);
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FUN_005d499c(uVar4);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005b8770();
  uVar4 = FUN_005b870f(&DAT_006de560);
  *(undefined1 *)(unaff_EBP + -4) = 5;
  FUN_005d499c(uVar4);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005b8770();
  uVar4 = FUN_005b870f(&DAT_006de560);
  *(undefined1 *)(unaff_EBP + -4) = 6;
  FUN_005d499c(uVar4);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005b8770();
  uVar4 = FUN_005b870f(&DAT_006de560);
  *(undefined1 *)(unaff_EBP + -4) = 7;
  FUN_005d499c(uVar4);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005b8770();
  uVar4 = FUN_005b870f(&DAT_006de560);
  *(undefined1 *)(unaff_EBP + -4) = 8;
  FUN_005d499c(uVar4);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005b8770();
  uVar4 = FUN_004d6c5c(unaff_EBP + -0x34);
  *(undefined1 *)(unaff_EBP + -4) = 9;
  FUN_005d499c(uVar4);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005b8770();
  uVar4 = FUN_004d6856(unaff_EBP + -0x34);
  *(undefined1 *)(unaff_EBP + -4) = 10;
  FUN_005d499c(uVar4);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005b8770();
  uVar4 = FUN_004d6554(unaff_EBP + -0x34,(int)*(short *)(DAT_006e486c + 0x66));
  *(undefined1 *)(unaff_EBP + -4) = 0xb;
  FUN_005d499c(uVar4);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005b8770();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_0048c4c9();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0048c4c9();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 1;
}

