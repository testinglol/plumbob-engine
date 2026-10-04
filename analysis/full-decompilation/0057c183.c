
undefined4 * FUN_0057c183(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x14) = extraout_ECX;
  FUN_0057c1e0(0xe49ec7f7);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00580cd2(unaff_EBP + -0xe,unaff_EBP + -0xd);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  extraout_ECX[0x2f] = *(undefined4 *)(unaff_EBP + 8);
  *extraout_ECX = &PTR_FUN_006717e8;
  extraout_ECX[0x30] = 0x400;
  return extraout_ECX;
}

