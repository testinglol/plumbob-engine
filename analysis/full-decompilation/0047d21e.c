
undefined4 FUN_0047d21e(void)

{
  void *pvVar1;
  undefined4 uVar2;
  int extraout_ECX;
  int iVar3;
  int iVar4;
  int iVar5;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar4 = *(int *)(extraout_ECX + 8);
  *(int *)(unaff_EBP + -0x18) = iVar4;
  pvVar1 = operator_new(0x20);
  *(void **)(unaff_EBP + -0x14) = pvVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar1 == (void *)0x0) {
    *(undefined4 *)(unaff_EBP + -0x14) = 0;
  }
  else {
    uVar2 = FUN_0047c747(iVar4);
    *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
  }
  if ((*(int *)(unaff_EBP + -0x14) != 0) && (*(undefined4 *)(unaff_EBP + -0x10) = 0, 0 < iVar4)) {
    do {
      iVar5 = 0;
      iVar4 = *(char *)(unaff_EBP + -0x10) * 2;
      do {
        iVar3 = (char)iVar5 * 4;
        iVar5 = iVar5 + 1;
        *(undefined2 *)(*(int *)(iVar3 + *(int *)(*(int *)(unaff_EBP + -0x14) + 0xc)) + iVar4) =
             *(undefined2 *)(*(int *)(*(int *)(extraout_ECX + 0xc) + iVar3) + iVar4);
      } while (iVar5 < *(int *)(unaff_EBP + -0x18));
      *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
    } while (*(int *)(unaff_EBP + -0x10) < *(int *)(unaff_EBP + -0x18));
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x14);
}

