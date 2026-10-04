
undefined4 * FUN_0057d6f8(void)

{
  char *pcVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_0057d967();
  iVar3 = 0;
  pcVar1 = (char *)(extraout_ECX + 0xa0);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined1 *)(extraout_ECX + 0x75) = 0;
  *pcVar1 = '\0';
  *extraout_ECX = &PTR_FUN_006719b4;
  if (*pcVar1 == '\0') {
    *(undefined1 *)(extraout_ECX + 0xa6) = 0;
    extraout_ECX[0xa1] = 0x1f;
    extraout_ECX[0xa2] = 0x11;
    extraout_ECX[0xa3] = extraout_ECX + 0xa7;
    do {
      *(undefined4 *)(extraout_ECX[0xa3] + iVar3 * 4) = 0x80000000;
      iVar3 = iVar3 + 1;
    } while (iVar3 < (int)extraout_ECX[0xa1]);
  }
  *pcVar1 = '\x01';
  FUN_00580664(0xd,0x32);
  uVar2 = *(undefined4 *)(unaff_EBP + 8);
  extraout_ECX[0xa4] = extraout_ECX + 0x75;
  extraout_ECX[0xa5] = &DAT_006f68f8;
  extraout_ECX[0x79] = 0;
  extraout_ECX[0x7a] = &DAT_006f6848;
  extraout_ECX[2] = uVar2;
  uVar2 = *(undefined4 *)(unaff_EBP + 0x24);
  extraout_ECX[3] = 0xa3cd96cf;
  extraout_ECX[199] = uVar2;
  extraout_ECX[0x7c] = *(undefined4 *)(unaff_EBP + 0x28);
  extraout_ECX[0x83] = *(undefined4 *)(unaff_EBP + 0x20);
  extraout_ECX[4] = *(undefined4 *)(unaff_EBP + 0x14);
  iVar3 = *(int *)(unaff_EBP + 0x1c);
  extraout_ECX[200] = iVar3;
  extraout_ECX[0x31] = extraout_ECX;
  if (iVar3 != 0) {
    FUN_0057c0ff(iVar3);
    *(undefined4 *)(unaff_EBP + 8) = extraout_ECX[2];
    FUN_0060139d(unaff_EBP + -0x18,unaff_EBP + 8);
  }
  FUN_005805fa(0x19,*(undefined4 *)(unaff_EBP + 0x18));
  FUN_005805fa(0x12,*(undefined4 *)(unaff_EBP + 0x10));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

