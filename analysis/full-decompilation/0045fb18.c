
void FUN_0045fb18(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  uVar1 = extraout_ECX[1];
  uVar2 = *extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00458ef3(uVar2,uVar1);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004eb354();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

