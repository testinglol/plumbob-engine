
undefined4 FUN_0057d025(void)

{
  char cVar1;
  int iVar2;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  cVar1 = *(char *)(extraout_ECX + 0x54);
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffe0;
  if (cVar1 != '\0') {
    *(int *)(extraout_ECX + 0x58) = *(int *)(extraout_ECX + 0x58) + 1;
  }
  *(undefined4 *)(extraout_ECX + 0x28) = 0;
  FUN_00580a92(unaff_EBP + -0x18);
  *(undefined4 *)(unaff_EBP + -0x20) = 0;
  while (iVar2 = *(int *)(unaff_EBP + -0x18), iVar2 != *(int *)(unaff_EBP + -0x20)) {
    if (*(int **)(iVar2 + 8) != (int *)0x0) {
      iVar2 = **(int **)(iVar2 + 8);
      *(undefined4 *)(unaff_EBP + -4) = 0;
      (**(code **)(iVar2 + 0x5c))();
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    }
    FUN_00576e56();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return CONCAT31((int3)((uint)iVar2 >> 8),1);
}

