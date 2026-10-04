
undefined4 FUN_0060279f(void)

{
  int iVar1;
  char cVar2;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined ***)(unaff_EBP + -0x14) = &PTR_LAB_00669c88;
  iVar1 = extraout_ECX[1];
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX + 1;
  (**(code **)(iVar1 + 4))();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  while( true ) {
    cVar2 = (**(code **)(extraout_ECX[10] + 0x4c))(unaff_EBP + -0x24);
    if (cVar2 == '\0') break;
    (**(code **)*extraout_ECX)(unaff_EBP + -0x24);
  }
  iVar1 = extraout_ECX[1];
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  (**(code **)(iVar1 + 8))();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 1;
}

