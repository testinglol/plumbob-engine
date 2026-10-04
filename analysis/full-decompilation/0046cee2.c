
undefined4 * FUN_0046cee2(void)

{
  undefined4 *extraout_ECX;
  int iVar1;
  int unaff_EBP;
  undefined4 *puVar2;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_004075d4();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_004733c6();
  puVar2 = extraout_ECX + 0x39;
  for (iVar1 = 0x28; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined1 *)(unaff_EBP + -4) = 1;
  puVar2 = extraout_ECX + 0x61;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  iVar1 = FUN_00401742(0x1c);
  extraout_ECX[0x69] = iVar1;
  *(int *)iVar1 = iVar1;
  iVar1 = extraout_ECX[0x69];
  *(int *)(iVar1 + 4) = iVar1;
  *extraout_ECX = &PTR_FUN_00667714;
  extraout_ECX[0x2c] = 0;
  extraout_ECX[0x2e] = 0;
  extraout_ECX[0x2f] = 0;
  extraout_ECX[0x30] = 0;
  *(undefined1 *)(extraout_ECX + 0x35) = 0;
  extraout_ECX[0x27] = 0;
  extraout_ECX[0x29] = 0;
  extraout_ECX[0x28] = 0;
  extraout_ECX[0x2d] = 0;
  puVar2 = extraout_ECX + 4;
  for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_0047342b(0x1e);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  extraout_ECX[0x36] = 0x3c;
  extraout_ECX[0x37] = 0x5a;
  return extraout_ECX;
}

