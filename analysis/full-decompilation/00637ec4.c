
void FUN_00637ec4(DWORD param_1)

{
  int iVar1;
  
  if (PTR_FUN_006da908 != (undefined *)0x0) {
    (*(code *)PTR_FUN_006da908)();
  }
  iVar1 = FUN_0063e1d3();
  if (iVar1 == 0) {
    __amsg_exit(0x10);
  }
  FUN_0063e23a(iVar1);
                    /* WARNING: Subroutine does not return */
  ExitThread(param_1);
}

