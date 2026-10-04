
undefined2 * FUN_004237d4(void)

{
  undefined4 uVar1;
  undefined2 *extraout_ECX;
  int iVar2;
  int unaff_EBP;
  undefined4 *puVar3;
  
  FUN_00634c24();
  *extraout_ECX = *(undefined2 *)(unaff_EBP + 8);
  *(undefined4 *)(extraout_ECX + 4) = *(undefined4 *)(unaff_EBP + 0xc);
  *(undefined2 **)(unaff_EBP + -0x10) = extraout_ECX;
  *(undefined4 *)(extraout_ECX + 6) = 0;
  *(undefined4 *)(extraout_ECX + 8) = 0;
  *(undefined4 *)(extraout_ECX + 10) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0046f824(extraout_ECX + 0x1a,0,0x40);
  *(undefined ***)(extraout_ECX + 0x14) = &PTR_FUN_0066651c;
  uVar1 = FUN_0045741b();
  *(undefined4 *)(extraout_ECX + 2) = uVar1;
  *(undefined4 *)(extraout_ECX + 0xc) = 0;
  *(undefined4 *)(extraout_ECX + 0xe) = 0;
  puVar3 = (undefined4 *)(extraout_ECX + 0x3a);
  for (iVar2 = 0x80; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  FUN_00457f7a(extraout_ECX + 0x14);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

