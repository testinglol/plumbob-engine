
undefined4 * FUN_0057d967(void)

{
  int iVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_0057c1e0(0x83cd96c3);
  extraout_ECX[0x2f] = 0;
  extraout_ECX[0x30] = 0;
  extraout_ECX[0x31] = 0;
  extraout_ECX[0x32] = 0;
  *(undefined1 *)(extraout_ECX + 0x33) = 0;
  *(undefined1 *)(extraout_ECX + 0x5e) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  extraout_ECX[0x65] = 0;
  extraout_ECX[0x66] = 0;
  extraout_ECX[0x67] = 0;
  extraout_ECX[0x68] = 0;
  iVar1 = FUN_00401742(0xc);
  extraout_ECX[0x6a] = iVar1;
  *(int *)iVar1 = iVar1;
  iVar1 = extraout_ECX[0x6a];
  *(int *)(iVar1 + 4) = iVar1;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_0057d56c();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *(undefined1 *)(extraout_ECX + 0x71) = 0;
  extraout_ECX[0x72] = 0;
  *(undefined1 *)((int)extraout_ECX + 0x1cf) = 0;
  extraout_ECX[0x74] = 0;
  *extraout_ECX = &PTR_FUN_00671a74;
  return extraout_ECX;
}

