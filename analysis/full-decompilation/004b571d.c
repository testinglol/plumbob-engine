
undefined4 * FUN_004b571d(void)

{
  undefined4 *extraout_ECX;
  void *unaff_retaddr;
  
  FUN_00634c24();
  *extraout_ECX = 0;
  extraout_ECX[1] = 0;
  extraout_ECX[2] = 0;
  FUN_00635e55(extraout_ECX + 3,0xc,3,&LAB_00405420,FUN_005481b6);
  FUN_00635e55(extraout_ECX + 0xc,0xc,3,&LAB_00405420,FUN_005481b6);
  extraout_ECX[0x17] = 0;
  extraout_ECX[0x16] = 0;
  extraout_ECX[0x15] = 0;
  extraout_ECX[0x18] = 0;
  ExceptionList = unaff_retaddr;
  return extraout_ECX;
}

