
void FUN_004f6cef(void)

{
  size_t sVar1;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  if (DAT_006f29f5 != '\0') {
    FUN_005d48d9();
    *(undefined4 *)(unaff_EBP + -4) = 0;
    sVar1 = _strlen(s_CMX_file___006cb0d8);
    FUN_00412d8a(s_CMX_file___006cb0d8,s_CMX_file___006cb0d8 + sVar1);
    sVar1 = _strlen(*(char **)(unaff_EBP + 8));
    FUN_00412d8a(*(undefined4 *)(unaff_EBP + 8),sVar1 + *(int *)(unaff_EBP + 8));
    sVar1 = _strlen(s___could_not_be_read__006cb0c0);
    FUN_00412d8a(s___could_not_be_read__006cb0c0,s___could_not_be_read__006cb0c0 + sVar1);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

