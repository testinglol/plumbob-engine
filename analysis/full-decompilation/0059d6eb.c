
void FUN_0059d6eb(void)

{
  undefined4 uVar1;
  void *pvVar2;
  undefined4 uVar3;
  int unaff_EBP;
  
  FUN_00634c24();
  uVar1 = *(undefined4 *)(*(int *)(DAT_006e486c + 0x28) + 0x2c);
  pvVar2 = operator_new(0x57c);
  *(void **)(unaff_EBP + -0x10) = pvVar2;
  uVar3 = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar2 != (void *)0x0) {
    uVar3 = FUN_0059d83f();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  DAT_006f7648 = uVar3;
  FUN_00401039(uVar1,0x96);
  FUN_00401039(uVar1,0x97);
  FUN_00401039(uVar1,0x98);
  FUN_00401039(uVar1,0x99);
  FUN_00401039(uVar1,0x9a);
  FUN_00401039(uVar1,0x9b);
  FUN_00401039(uVar1,0x82);
  FUN_00401039(uVar1,0x80);
  FUN_00401039(uVar1,0x9c);
  FUN_00401039(uVar1,0x9d);
  FUN_00401039(uVar1,0x9e);
  FUN_00401039(uVar1,0x9f);
  FUN_00401039(uVar1,0xa0);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

