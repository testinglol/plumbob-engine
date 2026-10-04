
undefined4 FUN_005c7f9b(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_005c22bb();
  FUN_005c1871(&DAT_006fe814);
  FUN_005c18db(&DAT_006fe814,&DAT_006fe80c);
  FUN_005c18db(&DAT_006fe814,&DAT_006fe808);
  FUN_005c1871(&DAT_006fe804);
  FUN_005c18db(&DAT_006fe804,&DAT_006fe800);
  FUN_005c5eb0(unaff_EBP + -0x10);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005c1871(unaff_EBP + -0x10);
  uVar1 = FUN_005c174f(&DAT_006d2ca8);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005c18db(unaff_EBP + -0x10,uVar1);
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_0042004f();
  uVar1 = FUN_005c174f(&DAT_006d2ca4);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005c18db(unaff_EBP + -0x10,uVar1);
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_0042004f();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0042004f();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 1;
}

