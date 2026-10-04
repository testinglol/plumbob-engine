
void FUN_0053202c(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_0066e510;
  *(undefined4 *)(unaff_EBP + -4) = 4;
  FUN_005325ae();
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_004054b4();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_004054b4();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005b8770();
  uVar1 = extraout_ECX[0x37];
  *(undefined1 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x14) = uVar1;
  FUN_0048c4c9();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005dbeb0();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

