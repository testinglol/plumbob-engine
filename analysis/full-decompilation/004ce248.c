
undefined4 * FUN_004ce248(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int iVar2;
  int unaff_EBP;
  undefined4 *puVar3;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005d48d9();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  extraout_ECX[0x17] = *(undefined4 *)(unaff_EBP + 8);
  FUN_004733c6();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_004733c6();
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_0046f824(extraout_ECX + 0x90,0,0x100);
  extraout_ECX[0x8d] = &PTR_FUN_00666524;
  FUN_0046f824(extraout_ECX + 0xd3,0,0x100);
  extraout_ECX[0xd0] = &PTR_FUN_00666524;
  *extraout_ECX = &PTR_FUN_00668d34;
  extraout_ECX[2] = 3;
  extraout_ECX[3] = 0xffffffff;
  extraout_ECX[4] = 0;
  extraout_ECX[5] = 0;
  FUN_005d4bbf(&DAT_006c7a08);
  *(undefined1 *)(extraout_ECX + 9) = 0;
  FUN_005d4bbf(&DAT_006de560);
  extraout_ECX[0xd] = 1;
  extraout_ECX[0xe] = 0;
  extraout_ECX[0xf] = 1;
  *(undefined1 *)(extraout_ECX + 0x10) = 0;
  uVar1 = FUN_004425e2();
  extraout_ECX[0x11] = uVar1;
  extraout_ECX[0x12] = 1;
  extraout_ECX[0x13] = 0;
  extraout_ECX[0x14] = 0xffffffff;
  extraout_ECX[0x15] = 0;
  extraout_ECX[0x18] = 0;
  *(undefined1 *)(extraout_ECX + 0x19) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x65) = 0;
  extraout_ECX[0x16] = 0;
  extraout_ECX[0x7f] = 0x3f800000;
  extraout_ECX[0x7d] = 0;
  *(undefined1 *)(extraout_ECX + 0x7e) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x1f9) = 0;
  extraout_ECX[0x1a] = 0xb;
  puVar3 = extraout_ECX + 0x1b;
  for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  extraout_ECX[0x27] = 3;
  extraout_ECX[0x3a] = 0xffffffff;
  extraout_ECX[0x28] = 1;
  extraout_ECX[0x29] = 0;
  extraout_ECX[0x2a] = 0;
  extraout_ECX[0x2b] = 0;
  extraout_ECX[0x2c] = 0;
  extraout_ECX[0x2d] = 0;
  extraout_ECX[0x2e] = 0;
  extraout_ECX[0x2f] = 0;
  extraout_ECX[0x30] = 0;
  extraout_ECX[0x31] = 0;
  extraout_ECX[0x32] = 0;
  extraout_ECX[0x33] = 0;
  extraout_ECX[0x34] = 0;
  extraout_ECX[0x35] = 0;
  extraout_ECX[0x36] = 0;
  extraout_ECX[0x37] = 0;
  extraout_ECX[0x39] = 0;
  extraout_ECX[0x38] = 0;
  puVar3 = extraout_ECX + 0x3b;
  for (iVar2 = 0x40; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  extraout_ECX[0x7b] = 0xffffffff;
  FUN_004cfca7(1);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  extraout_ECX[0x7c] = 0;
  extraout_ECX[0x89] = 1;
  extraout_ECX[0x8c] = 1;
  *(undefined1 *)(extraout_ECX + 1) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x66) = 0;
  *(undefined1 *)(extraout_ECX + 0x113) = 0;
  return extraout_ECX;
}

