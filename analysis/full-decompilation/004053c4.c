
undefined4 * FUN_004053c4(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = 0;
  extraout_ECX[1] = 0;
  extraout_ECX[2] = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  extraout_ECX[3] = 0;
  extraout_ECX[4] = 0;
  extraout_ECX[5] = 0;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_00635e55(extraout_ECX + 6,0xc,6,&LAB_00405420,FUN_004b503e);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  extraout_ECX[0x18] = 0;
  extraout_ECX[0x19] = 0;
  extraout_ECX[0x1a] = 0;
  return extraout_ECX;
}

