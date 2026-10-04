
undefined4 FUN_00634581(void)

{
  void *pvVar1;
  
  pvVar1 = operator_new(0x200);
  if (pvVar1 == (void *)0x0) {
    return 0xffffffff;
  }
  FUN_006345ae(pvVar1,(int)pvVar1 + 0x200,1);
  return 1;
}

