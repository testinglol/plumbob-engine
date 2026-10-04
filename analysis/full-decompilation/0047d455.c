
undefined4 FUN_0047d455(void)

{
  char cVar1;
  void *pvVar2;
  undefined4 uVar3;
  int extraout_ECX;
  int iVar4;
  int iVar5;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar5 = *(int *)(extraout_ECX + 8);
  *(int *)(unaff_EBP + -0x18) = iVar5;
  pvVar2 = operator_new(0x20);
  *(void **)(unaff_EBP + -0x14) = pvVar2;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar2 == (void *)0x0) {
    *(undefined4 *)(unaff_EBP + -0x14) = 0;
  }
  else {
    uVar3 = FUN_0047ce8c(iVar5);
    *(undefined4 *)(unaff_EBP + -0x14) = uVar3;
  }
  if ((*(int *)(unaff_EBP + -0x14) != 0) && (*(undefined4 *)(unaff_EBP + -0x10) = 0, 0 < iVar5)) {
    do {
      cVar1 = *(char *)(unaff_EBP + -0x10);
      iVar5 = 0;
      do {
        iVar4 = (char)iVar5 * 4;
        iVar5 = iVar5 + 1;
        *(undefined1 *)(*(int *)(iVar4 + *(int *)(*(int *)(unaff_EBP + -0x14) + 0xc)) + (int)cVar1)
             = *(undefined1 *)(*(int *)(*(int *)(extraout_ECX + 0xc) + iVar4) + (int)cVar1);
      } while (iVar5 < *(int *)(unaff_EBP + -0x18));
      *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
    } while (*(int *)(unaff_EBP + -0x10) < *(int *)(unaff_EBP + -0x18));
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x14);
}

