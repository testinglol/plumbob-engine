
void __fastcall FUN_00475463(int param_1)

{
  int local_8;
  
  if (*(int *)(param_1 + 0xc) - *(int *)(param_1 + 8) >> 2 == 0) {
    local_8 = 0x3e9;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(&local_8,&DAT_00698f30);
  }
  local_8 = param_1;
  FUN_005db2f2(*(int *)(param_1 + 0xc) + -4);
  return;
}

