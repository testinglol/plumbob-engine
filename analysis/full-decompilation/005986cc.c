
undefined4 FUN_005986cc(void)

{
  undefined *puVar1;
  int iVar2;
  undefined4 extraout_ECX;
  int unaff_EBP;
  undefined **ppuVar3;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x10) = extraout_ECX;
  ppuVar3 = &PTR_DAT_006d1a78;
  do {
    puVar1 = ppuVar3[1];
    FUN_005b870f(*ppuVar3);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_005b86bd(unaff_EBP + -0x1c);
    *(undefined **)(unaff_EBP + -0x2c) = puVar1;
    iVar2 = DAT_006f6d40 + 1;
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_0059d340(iVar2);
    FUN_0059d2af(unaff_EBP + -0x28,unaff_EBP + -0x38);
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_005b8770();
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
    ppuVar3 = ppuVar3 + 2;
  } while ((int)ppuVar3 < 0x6d1bb8);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x10);
}

