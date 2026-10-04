
undefined4 FUN_00492b33(void)

{
  int iVar1;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar1 = *(int *)(extraout_ECX + 0x84);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00434ffd(-iVar1 & 3);
  iVar1 = *(int *)(*(int *)(*(int *)(extraout_ECX + 0x38 + *(char *)(unaff_EBP + 10) * 4) + 0xc) +
                  *(char *)(unaff_EBP + 8) * 4);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return CONCAT22((short)((uint)iVar1 >> 0x10),*(undefined2 *)(iVar1 + *(char *)(unaff_EBP + 9) * 2)
                 );
}

