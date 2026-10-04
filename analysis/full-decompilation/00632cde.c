
void FUN_00632cde(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_0068908c;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if ((int)extraout_ECX[0xc] < 0) {
    FUN_00633e5e(extraout_ECX + 0xd);
  }
  if (extraout_ECX[0x14] == 0) {
    FUN_00632edd();
  }
  else {
    FUN_00632d35();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_006343fb();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

