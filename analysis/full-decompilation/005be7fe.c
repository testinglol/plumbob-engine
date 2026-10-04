
undefined4 * FUN_005be7fe(void)

{
  int iVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_LAB_00672c24;
  FUN_004dc9d9();
  extraout_ECX[7] = 0xffffffff;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined1 *)(extraout_ECX + 6) = 0;
  extraout_ECX[8] = 0;
  extraout_ECX[9] = 0;
  extraout_ECX[10] = 0;
  extraout_ECX[0xb] = 0;
  extraout_ECX[0xc] = 0x20000000;
  FUN_004dc9d9();
  extraout_ECX[0x12] = 0;
  extraout_ECX[0x13] = 0;
  extraout_ECX[0x14] = 0;
  extraout_ECX[0x15] = 0;
  extraout_ECX[0x16] = 0;
  extraout_ECX[0x17] = 0;
  extraout_ECX[0x18] = 0;
  extraout_ECX[0x19] = 0;
  extraout_ECX[0x1a] = 0;
  extraout_ECX[0x1b] = 0;
  extraout_ECX[0x1c] = 0;
  extraout_ECX[0x1d] = 0;
  iVar1 = *(int *)(unaff_EBP + 8);
  *(undefined1 *)(unaff_EBP + -4) = 3;
  extraout_ECX[0x1e] = 0;
  extraout_ECX[0x1f] = 0;
  *extraout_ECX = &PTR_LAB_00672b9c;
  if (iVar1 != 0) {
    FUN_005bad81(*(undefined4 *)(unaff_EBP + 8));
    *(undefined1 *)(unaff_EBP + -4) = 4;
    FUN_005bc346(unaff_EBP + -0x24);
    *(undefined1 *)(unaff_EBP + -4) = 3;
    *(undefined ***)(unaff_EBP + -0x24) = &PTR_LAB_0066933c;
    FUN_00401729();
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return extraout_ECX;
}

