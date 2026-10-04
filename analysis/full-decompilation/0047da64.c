
undefined2 FUN_0047da64(void)

{
  int iVar1;
  undefined2 uVar2;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_0046fca5();
  *(undefined ***)(unaff_EBP + -0x78) = &PTR_FUN_0066643c;
  iVar1 = DAT_006e486c;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00470383(*(undefined4 *)(iVar1 + 0xc),0x8b,0);
  uVar2 = FUN_0046fbe5(0xffffffff);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00470467();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar2;
}

