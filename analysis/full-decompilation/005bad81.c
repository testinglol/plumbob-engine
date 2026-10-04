
undefined4 * FUN_005bad81(void)

{
  undefined4 uVar1;
  size_t sVar2;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX + 1;
  extraout_ECX[1] = 0;
  extraout_ECX[2] = 0;
  extraout_ECX[3] = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  sVar2 = _strlen(*(char **)(unaff_EBP + 8));
  FUN_00401a3c(*(undefined4 *)(unaff_EBP + 8),sVar2 + *(int *)(unaff_EBP + 8));
  uVar1 = *(undefined4 *)(unaff_EBP + -0xc);
  extraout_ECX[4] = 0;
  *extraout_ECX = &PTR_LAB_0066933c;
  *unaff_FS_OFFSET = uVar1;
  return extraout_ECX;
}

