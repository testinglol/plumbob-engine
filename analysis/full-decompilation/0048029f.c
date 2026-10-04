
void FUN_0048029f(void)

{
  undefined2 *puVar1;
  undefined *puVar2;
  undefined2 extraout_var;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_0046fa24(0x28);
  FUN_0046fca5();
  *(undefined ***)(unaff_EBP + -0x78) = &PTR_FUN_0066643c;
  puVar1 = *(undefined2 **)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00470383(**(undefined4 **)(unaff_EBP + 0xc),CONCAT22(extraout_var,*puVar1),0);
  puVar2 = (undefined *)FUN_004705f2(*(undefined1 *)(puVar1 + 2),0xffffffff);
  if (puVar2 == (undefined *)0x0) {
    puVar2 = &DAT_006c107c;
  }
  FUN_0046f847(puVar2,0xffffffff);
  FUN_0046fa24(0x29);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00470467();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

