
undefined4 * FUN_00564664(void)

{
  undefined1 uVar1;
  undefined4 *extraout_ECX;
  int iVar2;
  int unaff_EBP;
  undefined4 *puVar3;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005dbd68();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  *(undefined1 *)(extraout_ECX + 0x38) = 0;
  FUN_00635e55(extraout_ECX + 0x48,0x60,6,&LAB_00564808,&LAB_00564842);
  extraout_ECX[0xee] = 0;
  extraout_ECX[0xef] = 0;
  extraout_ECX[0xf0] = 0;
  extraout_ECX[0xf1] = 0;
  extraout_ECX[0xf2] = 0;
  extraout_ECX[0x107] = 0;
  extraout_ECX[0x108] = 0;
  extraout_ECX[0x109] = 0;
  extraout_ECX[0x10c] = 0;
  extraout_ECX[0x10d] = 0;
  extraout_ECX[0x10e] = 0;
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_004733c6();
  extraout_ECX[0xf4] = 0;
  *extraout_ECX = &PTR_FUN_00670e10;
  extraout_ECX[0xf5] = 0;
  _memset(extraout_ECX + 0xf6,0,0x24);
  _memset(extraout_ECX + 0xff,0,0x14);
  _memset(extraout_ECX + 0x39,0,0x24);
  extraout_ECX[0x114] = 0xffffffff;
  extraout_ECX[0x115] = 0x41a00000;
  extraout_ECX[0x116] = 0;
  extraout_ECX[0x118] = DAT_006fea20;
  DAT_006fea20 = DAT_006f2a98;
  uVar1 = *(undefined1 *)(unaff_EBP + 8);
  extraout_ECX[0x10f] = 0xffffffff;
  *(undefined1 *)(extraout_ECX + 0x10a) = 0;
  extraout_ECX[0x10b] = 0;
  *(undefined1 *)(extraout_ECX + 0x119) = 0;
  *(undefined1 *)(extraout_ECX + 0xed) = uVar1;
  extraout_ECX[0x42] = 0;
  extraout_ECX[0x43] = 0;
  *(undefined1 *)(extraout_ECX + 0x47) = 0;
  extraout_ECX[0x46] = 0;
  *(undefined1 *)(extraout_ECX + 0xd8) = 1;
  extraout_ECX[0xd9] = 1;
  *(undefined1 *)(extraout_ECX + 0xda) = 0;
  puVar3 = extraout_ECX + 0xdb;
  for (iVar2 = 0x12; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  extraout_ECX[0x45] = 0;
  extraout_ECX[0x44] = 0;
  return extraout_ECX;
}

