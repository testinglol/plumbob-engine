
undefined4 * FUN_00415b87(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *extraout_ECX;
  int iVar4;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_004075d4();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005b8680();
  puVar3 = extraout_ECX + 0xe;
  iVar4 = 5;
  do {
    *puVar3 = 0;
    puVar3[1] = 0;
    puVar3 = puVar3 + 2;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  uVar1 = *(undefined4 *)(unaff_EBP + 8);
  uVar2 = *(undefined4 *)(unaff_EBP + -0xc);
  extraout_ECX[0x18] = 0;
  extraout_ECX[0x19] = 0;
  extraout_ECX[4] = 0;
  extraout_ECX[8] = 0;
  extraout_ECX[6] = 0;
  extraout_ECX[5] = 0;
  extraout_ECX[7] = 0;
  extraout_ECX[9] = 0;
  extraout_ECX[0xd] = uVar1;
  extraout_ECX[0x1a] = 0;
  extraout_ECX[0x1b] = 0;
  *extraout_ECX = &PTR_FUN_00666714;
  *unaff_FS_OFFSET = uVar2;
  return extraout_ECX;
}

