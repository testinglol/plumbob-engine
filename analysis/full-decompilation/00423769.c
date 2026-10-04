
undefined2 * FUN_00423769(void)

{
  undefined2 *extraout_ECX;
  int iVar1;
  int unaff_EBP;
  undefined4 *puVar2;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  *(undefined2 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = 0;
  *(undefined4 *)(extraout_ECX + 2) = 0;
  *(undefined4 *)(extraout_ECX + 4) = 0;
  *(undefined4 *)(extraout_ECX + 6) = 0;
  *(undefined4 *)(extraout_ECX + 8) = 0;
  *(undefined4 *)(extraout_ECX + 10) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(extraout_ECX + 0x10) = 0;
  *(undefined1 *)(extraout_ECX + 0x12) = 1;
  FUN_0046f824(extraout_ECX + 0x1a,0,0x40);
  *(undefined ***)(extraout_ECX + 0x14) = &PTR_FUN_0066651c;
  *(undefined4 *)(extraout_ECX + 0xc) = 0;
  *(undefined4 *)(extraout_ECX + 0xe) = 0;
  puVar2 = (undefined4 *)(extraout_ECX + 0x3a);
  for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return extraout_ECX;
}

