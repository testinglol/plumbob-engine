
void FUN_006337e2(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_006890f0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if ((extraout_ECX[0x13] != 0) && (extraout_ECX[4] != 0)) {
    if ((code *)extraout_ECX[0x18] == (code *)0x0) {
      FUN_006321f0(extraout_ECX[4]);
    }
    else {
      (*(code *)extraout_ECX[0x18])();
    }
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_006343fb();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

