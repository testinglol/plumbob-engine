
undefined4 FUN_00598aff(void)

{
  char cVar1;
  void *pvVar2;
  int iVar3;
  undefined4 uVar4;
  int extraout_ECX;
  int iVar5;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  cVar1 = FUN_005b90c2(unaff_EBP + -0x120,0x100);
  if (cVar1 != '\0') {
    FUN_005b870f(unaff_EBP + -0x120);
    iVar5 = 0;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_005d499c(unaff_EBP + -0x20);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
    cVar1 = FUN_005b9095(unaff_EBP + -0x10);
    if (cVar1 != '\0') {
      if (0 < *(int *)(unaff_EBP + -0x10)) {
        do {
          pvVar2 = operator_new(0x16c);
          *(void **)(unaff_EBP + -0x14) = pvVar2;
          *(undefined4 *)(unaff_EBP + -4) = 1;
          if (pvVar2 == (void *)0x0) {
            iVar3 = 0;
          }
          else {
            iVar3 = FUN_00598953();
          }
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          cVar1 = FUN_00595963(*(undefined4 *)(unaff_EBP + 8));
          if (cVar1 == '\0') {
            if (iVar3 != 0) {
              FUN_00595e9a();
              FUN_006321f0(iVar3);
            }
            goto LAB_00598bf2;
          }
          FUN_0059903f(iVar3);
          iVar5 = iVar5 + 1;
        } while (iVar5 < *(int *)(unaff_EBP + -0x10));
      }
      *(int *)(extraout_ECX + 0xa4) = *(int *)(extraout_ECX + 0xa4) + 1;
      *(int *)(extraout_ECX + 0xac) = *(int *)(extraout_ECX + 0xac) + 1;
      *(int *)(extraout_ECX + 0xb4) = *(int *)(extraout_ECX + 0xb4) + 1;
      uVar4 = 1;
      goto LAB_00598bcf;
    }
  }
LAB_00598bf2:
  uVar4 = 0;
LAB_00598bcf:
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar4;
}

