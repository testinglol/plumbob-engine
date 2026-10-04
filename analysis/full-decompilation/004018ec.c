
void FUN_004018ec(void)

{
  size_t sVar1;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  sVar1 = _strlen(s_basic_string_006c0970);
  FUN_00401a3c(s_basic_string_006c0970,s_basic_string_006c0970 + sVar1);
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_00401959(unaff_EBP + -0x18);
  *(undefined ***)(unaff_EBP + -0x124) = &PTR_FUN_00666444;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(unaff_EBP + -0x124,&DAT_00692f70);
}

