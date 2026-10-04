
void FUN_005712b5(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int unaff_EBP;
  undefined4 *puVar4;
  int iVar5;
  
  FUN_00634c24();
  FUN_005b86bd(*(undefined4 *)(unaff_EBP + 8));
  iVar5 = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005b86bd(*(undefined4 *)(unaff_EBP + 0xc));
  *(undefined1 *)(unaff_EBP + 0xb) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  puVar4 = (undefined4 *)(unaff_EBP + -0x48);
  do {
    if (*(char *)(unaff_EBP + 0xb) != '\0') break;
    *puVar4 = 0;
    FUN_005d4a0d(unaff_EBP + -0x18,&DAT_006c0fdc);
    *(undefined1 *)(unaff_EBP + -4) = 2;
    iVar1 = FUN_005d49d6();
    if (iVar1 == 0) {
      FUN_005d499c(unaff_EBP + -0x24);
      *(undefined1 *)(unaff_EBP + 0xb) = 1;
    }
    iVar1 = FUN_006368c3((int)**(char **)(unaff_EBP + -0x18));
    if (iVar1 == 0) {
      puVar3 = (undefined4 *)FUN_005758af(unaff_EBP + -0x18);
      uVar2 = *puVar3;
    }
    else {
      uVar2 = FUN_004096c2();
      uVar2 = FUN_005d81cf(uVar2);
    }
    *puVar4 = uVar2;
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_005b8770();
    iVar5 = iVar5 + 1;
    puVar4 = puVar4 + 1;
  } while (iVar5 < 6);
  if (iVar5 < 6) {
    puVar4 = (undefined4 *)(unaff_EBP + -0x48 + iVar5 * 4);
    for (iVar1 = 6 - iVar5; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
  }
  FUN_005724f5(unaff_EBP + -0x30,*(undefined4 *)(unaff_EBP + -0x48),
               *(undefined4 *)(unaff_EBP + -0x44),*(undefined4 *)(unaff_EBP + -0x40),
               *(undefined4 *)(unaff_EBP + -0x3c),*(undefined4 *)(unaff_EBP + -0x38),
               *(undefined4 *)(unaff_EBP + -0x34));
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005b8770();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

