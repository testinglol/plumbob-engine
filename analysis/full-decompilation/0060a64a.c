
undefined1 FUN_0060a64a(void)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  if (*(char *)(extraout_ECX + 0x21) == '\0') {
    pvVar2 = operator_new(0xc);
    *(void **)(unaff_EBP + -0x10) = pvVar2;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar2 == (void *)0x0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_00609625(*(undefined4 *)(extraout_ECX + 0xc),*(undefined4 *)(extraout_ECX + 0x10),
                           *(undefined4 *)(extraout_ECX + 0x14));
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(int *)(extraout_ECX + 0x1c) = iVar3;
    if (iVar3 != 0) {
      *(undefined1 *)(extraout_ECX + 0x21) = 1;
      iVar4 = FUN_0060931d(0x41);
      iVar1 = *(int *)(extraout_ECX + 0x1c);
      *(uint *)(extraout_ECX + 0xc) = iVar4 + (*(uint *)(iVar3 + 4) & 1);
      iVar3 = FUN_0060931d(0x41);
      *(uint *)(extraout_ECX + 0x18) = iVar3 + (*(uint *)(iVar1 + 4) & 1);
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined1 *)(extraout_ECX + 0x21);
}

