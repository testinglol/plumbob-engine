
undefined4 FUN_00451e74(undefined4 param_1,undefined2 *param_2)

{
  short sVar1;
  
  sVar1 = FUN_00453181(param_2[1],*param_2,0);
  if (sVar1 != 0) {
    param_2 = (undefined2 *)0x3e;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(&param_2,&DAT_00698f30);
  }
  return 1;
}

