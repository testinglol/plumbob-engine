
void FUN_0043779b(void)

{
  void *pvVar1;
  undefined4 *puVar2;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  if ((*(byte *)(*(int *)(extraout_ECX + 0x118) + 0xcc) & 1) != 0) {
    FUN_00458058(1);
    pvVar1 = operator_new(0x138);
    *(void **)(unaff_EBP + -0x10) = pvVar1;
    puVar2 = (undefined4 *)0x0;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar1 != (void *)0x0) {
      puVar2 = (undefined4 *)FUN_00584822();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined4 **)(extraout_ECX + 0x120) = puVar2;
    (**(code **)*puVar2)(extraout_ECX);
    *(undefined1 *)(extraout_ECX + 0x180) = 1;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

