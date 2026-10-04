
void FUN_0057bca4(void)

{
  undefined4 uVar1;
  int iVar2;
  int unaff_EBP;
  
  FUN_00634c24();
  uVar1 = FUN_004096c2();
  uVar1 = FUN_005d81cf(uVar1);
  FUN_0057d50a(uVar1);
  FUN_005d49d6();
  FUN_005b86bd(*(undefined4 *)(unaff_EBP + 0xc));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined1 *)(unaff_EBP + 0xf) = 0;
  do {
    FUN_005d4a0d(unaff_EBP + -0x1c,&DAT_006c0fdc);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    iVar2 = FUN_005d49d6();
    if (iVar2 == 0) {
      *(undefined1 *)(unaff_EBP + 0xf) = 1;
      FUN_005d499c(unaff_EBP + -0x28);
    }
    iVar2 = FUN_005d49d6();
    if (iVar2 != 0) {
      *(undefined4 *)(unaff_EBP + 8) = 0;
      *(undefined4 *)(unaff_EBP + -0x10) = 0;
      FUN_00634d24(*(undefined4 *)(unaff_EBP + -0x1c),s__ld__ld_006cf468,unaff_EBP + 8,
                   unaff_EBP + -0x10);
      if (*(int *)(unaff_EBP + -0x10) == 0) {
        *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(unaff_EBP + 8);
      }
      if (*(int *)(unaff_EBP + 8) <= *(int *)(unaff_EBP + -0x10)) {
        do {
          uVar1 = *(undefined4 *)(unaff_EBP + 8);
          *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 1;
          FUN_005806fe(uVar1);
        } while (*(int *)(unaff_EBP + 8) <= *(int *)(unaff_EBP + -0x10));
      }
    }
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_005b8770();
  } while (*(char *)(unaff_EBP + 0xf) == '\0');
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

