
undefined4 * FUN_0046f5cd(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_0046f656();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *extraout_ECX = &PTR_FUN_006677bc;
  FUN_0046b266();
  FUN_0046b26e(2,&DAT_006c2648);
  FUN_0046b26e(1,&DAT_006c2648);
  FUN_0046b26e(3,&DAT_006c34cc);
  FUN_0046b26e(2,&DAT_006c4c54);
  FUN_0046b26e(2,&DAT_006c4c4c);
  FUN_0046b26e(2,&DAT_006c4c44);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return extraout_ECX;
}

