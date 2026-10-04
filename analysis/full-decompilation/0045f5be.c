
void FUN_0045f5be(void)

{
  int extraout_ECX;
  int unaff_EBP;
  char *pcVar1;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_0046f824(unaff_EBP + -0x50,0,0x40);
  *(undefined ***)(unaff_EBP + -0x5c) = &PTR_FUN_0066651c;
  FUN_0046f824(unaff_EBP + -0x9c,0,0x40);
  *(int *)(unaff_EBP + 0x14) = *(int *)(unaff_EBP + 0x14) + 1;
  *(undefined ***)(unaff_EBP + -0xa8) = &PTR_FUN_0066651c;
  *(undefined2 *)(unaff_EBP + -0x54) = 0;
  **(undefined1 **)(unaff_EBP + -0x58) = 0;
  *(undefined2 *)(unaff_EBP + -0xa0) = 0;
  **(undefined1 **)(unaff_EBP + -0xa4) = 0;
  if ((*(short *)(extraout_ECX + 0x600) == 0) || (0x11 < *(short *)(extraout_ECX + 0x600))) {
    FUN_0046f847(&DAT_006c465c,0xffffffff);
    FUN_0046f917(*(undefined4 *)(unaff_EBP + 0x10),0xffffffff);
    FUN_0046f847(s___gAFit__006c4640,0xffffffff);
    FUN_0046fa6f(*(undefined4 *)(unaff_EBP + 0x14),2);
    FUN_0046f847(&DAT_006c465c,0xffffffff);
    FUN_0046f917(*(undefined4 *)(unaff_EBP + 0x10),0xffffffff);
    pcVar1 = s___gAFit_c__006c4634;
  }
  else {
    FUN_0046f847(&DAT_006c465c,0xffffffff);
    FUN_0046f917(*(undefined4 *)(unaff_EBP + 0x10),0xffffffff);
    FUN_0046f847(s___gC__006c4654,0xffffffff);
    FUN_0046fa6f(*(undefined4 *)(unaff_EBP + 0x14),2);
    FUN_0046f847(&DAT_006c465c,0xffffffff);
    FUN_0046f917(*(undefined4 *)(unaff_EBP + 0x10),0xffffffff);
    pcVar1 = s___gC_c__006c464c;
  }
  FUN_0046f847(pcVar1,0xffffffff);
  FUN_0046fa6f(*(undefined4 *)(unaff_EBP + 0x14),2);
  FUN_00408b9d();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00409377(*(undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x11c),0);
  FUN_0040e630(unaff_EBP + -0x5c);
  FUN_0040e6d6(unaff_EBP + -0xa8);
  FUN_004094f4(0);
  FUN_0046f8e4(unaff_EBP + -0x5c);
  FUN_0046f8e4(unaff_EBP + -0xa8);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00408c4f();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

