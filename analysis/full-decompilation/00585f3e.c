
void FUN_00585f3e(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  FUN_00634c24();
  uVar1 = FUN_005c38c0(unaff_EBP + -0x94,0,&DAT_006f6b30);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  uVar2 = FUN_005c38c0(unaff_EBP + -0x50,1,&DAT_006f6b2c);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_0049b9e6(&DAT_006f6ae8,uVar2,uVar1);
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005c4890();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005c4890();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

