
void FUN_0045f1a0(void)

{
  undefined4 uVar1;
  int extraout_ECX;
  int unaff_EBP;
  char *pcVar2;
  
  FUN_00634c24();
  FUN_0046f824(unaff_EBP + -0x4c,0,0x40);
  *(undefined ***)(unaff_EBP + -0x58) = &PTR_FUN_0066651c;
  FUN_0046f824(unaff_EBP + -0x98,0,0x40);
  *(undefined ***)(unaff_EBP + -0xa4) = &PTR_FUN_0066651c;
  *(undefined2 *)(unaff_EBP + -0x50) = 0;
  **(undefined1 **)(unaff_EBP + -0x54) = 0;
  *(undefined2 *)(unaff_EBP + -0x9c) = 0;
  **(undefined1 **)(unaff_EBP + -0xa0) = 0;
  if ((*(short *)(extraout_ECX + 0x600) == 0) || (0x11 < *(short *)(extraout_ECX + 0x600))) {
    pcVar2 = s_pajama_g_b_006c45b8;
  }
  else {
    pcVar2 = s_pjs_gchd_006c45c4;
  }
  FUN_0046f847(pcVar2,0xffffffff);
  FUN_0046f847(s_pajama_g_c_006c45ac,0xffffffff);
  FUN_00408b9d();
  uVar1 = *(undefined4 *)(extraout_ECX + 0x11c);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00409377(uVar1,0);
  FUN_0040e630(unaff_EBP + -0x58);
  FUN_0040e6d6(unaff_EBP + -0xa4);
  FUN_004094f4(0);
  FUN_0046f8e4(unaff_EBP + -0x58);
  FUN_0046f8e4(unaff_EBP + -0xa4);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00408c4f();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

