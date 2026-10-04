
undefined1 * FUN_0041d935(void)

{
  undefined1 uVar1;
  undefined4 uVar2;
  undefined1 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  uVar1 = **(undefined1 **)(unaff_EBP + 0xc);
  *(undefined1 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = uVar1;
  extraout_ECX[1] = **(undefined1 **)(unaff_EBP + 0x10);
  extraout_ECX[2] = *(undefined1 *)(unaff_EBP + 0xf);
  *(undefined4 *)(extraout_ECX + 4) = 0;
  *(undefined4 *)(extraout_ECX + 8) = 0;
  *(undefined4 *)(extraout_ECX + 0xc) = 0;
  uVar2 = *(undefined4 *)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(extraout_ECX + 0x10) = 0;
  FUN_0041da10(uVar2);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

