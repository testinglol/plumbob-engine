
undefined4 * FUN_00568898(void)

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
  extraout_ECX[0x4b] = 0;
  extraout_ECX[0x4c] = 0;
  extraout_ECX[0x4d] = 0;
  extraout_ECX[0x4e] = 0;
  extraout_ECX[0x4f] = 0;
  extraout_ECX[0x50] = 0;
  extraout_ECX[0x51] = 0;
  extraout_ECX[0x67] = 0;
  extraout_ECX[0x68] = 0;
  extraout_ECX[0x69] = 0;
  extraout_ECX[0x6c] = 0;
  extraout_ECX[0x6d] = 0;
  extraout_ECX[0x6e] = 0;
  extraout_ECX[0x53] = 0;
  *extraout_ECX = &PTR_FUN_00670fb8;
  extraout_ECX[0x54] = 0;
  _memset(extraout_ECX + 0x55,0,0x28);
  _memset(extraout_ECX + 0x5f,0,0x14);
  _memset(extraout_ECX + 0x38,0,0x1c);
  extraout_ECX[0x74] = 0xffffffff;
  puVar3 = extraout_ECX + 0x75;
  for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  extraout_ECX[0x7b] = DAT_00673438 + DAT_00673438;
  extraout_ECX[0x7c] = 0;
  extraout_ECX[0x7e] = DAT_006fea20;
  DAT_006fea20 = DAT_006f2a98;
  uVar1 = *(undefined1 *)(unaff_EBP + 8);
  extraout_ECX[0x6f] = 0xffffffff;
  *(undefined1 *)(extraout_ECX + 0x4a) = uVar1;
  *(undefined1 *)(extraout_ECX + 0x6a) = 0;
  extraout_ECX[0x6b] = 0;
  *(undefined1 *)(extraout_ECX + 0x7f) = 0;
  extraout_ECX[0x3f] = 0;
  extraout_ECX[0x40] = 0;
  *(undefined1 *)(extraout_ECX + 0x44) = 0;
  extraout_ECX[0x43] = 0;
  *(undefined1 *)((int)extraout_ECX + 0x111) = 0;
  extraout_ECX[0x49] = 0;
  extraout_ECX[0x47] = 0;
  extraout_ECX[0x45] = 0;
  extraout_ECX[0x48] = 0;
  extraout_ECX[0x41] = 0;
  extraout_ECX[0x42] = 0;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

