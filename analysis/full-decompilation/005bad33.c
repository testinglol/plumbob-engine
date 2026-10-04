
undefined1 * FUN_005bad33(void)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  undefined1 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  puVar2 = *(undefined1 **)(unaff_EBP + 8);
  uVar1 = *puVar2;
  *(undefined1 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = uVar1;
  extraout_ECX[1] = puVar2[1];
  extraout_ECX[2] = puVar2[2];
  *(undefined4 *)(extraout_ECX + 4) = 0;
  *(undefined4 *)(extraout_ECX + 8) = 0;
  *(undefined4 *)(extraout_ECX + 0xc) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(extraout_ECX + 0x10) = 0;
  FUN_005bb639(puVar2);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return extraout_ECX;
}

