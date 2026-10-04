
undefined4 * FUN_004311b4(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *(undefined4 **)(unaff_EBP + -0x14) = extraout_ECX + 4;
  extraout_ECX[4] = 0;
  extraout_ECX[5] = 0;
  extraout_ECX[6] = 0;
  FUN_00401aae(8);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00401a79();
  uVar1 = *(undefined4 *)(unaff_EBP + 8);
  extraout_ECX[1] = 0xffffffff;
  extraout_ECX[2] = 0xffffffff;
  uVar2 = *(undefined4 *)(unaff_EBP + 0x14);
  extraout_ECX[3] = 0;
  extraout_ECX[7] = uVar1;
  *extraout_ECX = DAT_006e4a64;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  DAT_006e4a64 = extraout_ECX;
  FUN_004316cf(uVar2);
  FUN_004313ae(*(undefined4 *)(unaff_EBP + 0xc),*(undefined4 *)(unaff_EBP + 0x10));
  FUN_00431380(0);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

