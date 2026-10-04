
undefined4 * FUN_005569af(void)

{
  undefined1 uVar1;
  float fVar2;
  undefined4 *extraout_ECX;
  int iVar3;
  int unaff_EBP;
  undefined4 *puVar4;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005dbd68();
  *extraout_ECX = &PTR_FUN_00670714;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  extraout_ECX[0x49] = 0;
  extraout_ECX[0x4a] = 0;
  extraout_ECX[0x4b] = 0;
  extraout_ECX[0x4c] = 0;
  extraout_ECX[0x4e] = 0;
  FUN_0055e4f1();
  extraout_ECX[0x69] = 0;
  extraout_ECX[0x6a] = 0;
  extraout_ECX[0x6e] = 0;
  extraout_ECX[0x6f] = 0;
  extraout_ECX[0x70] = 0;
  *(undefined1 *)(unaff_EBP + -4) = 3;
  extraout_ECX[0x35] = (-(uint)(*(char *)(unaff_EBP + 8) != '\0') & 0xfffffffc) + 4;
  extraout_ECX[0x50] = 0;
  *extraout_ECX = &PTR_FUN_006708c4;
  extraout_ECX[0x51] = 0;
  _memset(extraout_ECX + 0x55,0,0x38);
  _memset(extraout_ECX + 0x39,0,0x1c);
  FUN_0055e540();
  extraout_ECX[0x76] = 0xffffffff;
  puVar4 = extraout_ECX + 0x78;
  for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  extraout_ECX[0x77] = 0xffffffff;
  fVar2 = DAT_00673438 + DAT_00673438;
  extraout_ECX[0x7f] = 0;
  extraout_ECX[0x7e] = fVar2;
  extraout_ECX[0x81] = DAT_006fea20;
  DAT_006fea20 = DAT_006f2a98;
  uVar1 = *(undefined1 *)(unaff_EBP + 8);
  extraout_ECX[0x71] = 0xffffffff;
  *(undefined1 *)(extraout_ECX + 0x6c) = 0;
  extraout_ECX[0x6d] = 0;
  *(undefined1 *)(extraout_ECX + 0x82) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x121) = uVar1;
  *(undefined1 *)(extraout_ECX + 0x48) = 0;
  extraout_ECX[0x47] = 0;
  extraout_ECX[0x4d] = 0;
  extraout_ECX[100] = 0;
  extraout_ECX[0x65] = 0;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *(undefined1 *)(extraout_ECX + 0x46) = 0;
  *(undefined1 *)(extraout_ECX + 0x40) = 0;
  extraout_ECX[0x45] = 0;
  extraout_ECX[0x43] = 0;
  extraout_ECX[0x41] = 0;
  extraout_ECX[0x44] = 0;
  return extraout_ECX;
}

