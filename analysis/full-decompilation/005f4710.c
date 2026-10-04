
void FUN_005f4710(void)

{
  int *piVar1;
  void *pvVar2;
  int iVar3;
  DWORD DVar4;
  int extraout_ECX;
  uint uVar5;
  int unaff_EBP;
  
  FUN_00634c24();
  if (*(char *)(extraout_ECX + 0x160) != '\0') {
    pvVar2 = operator_new(0x30);
    *(void **)(unaff_EBP + -0x10) = pvVar2;
    uVar5 = 0;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar2 == (void *)0x0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_005f4628();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(int *)(unaff_EBP + -0x14) = iVar3;
    if (iVar3 != 0) {
      FUN_005f4839(iVar3);
      piVar1 = (int *)(extraout_ECX + 0x174);
      if (*(int *)(extraout_ECX + 0x178) - *piVar1 >> 2 != 0) {
        do {
          iVar3 = *(int *)(*piVar1 + uVar5 * 4);
          *(int *)(unaff_EBP + -0x10) = iVar3;
          if (iVar3 != 0) {
            FUN_005b8770();
            FUN_006321f0(*(undefined4 *)(unaff_EBP + -0x10));
          }
          uVar5 = uVar5 + 1;
        } while (uVar5 < (uint)(*(int *)(extraout_ECX + 0x178) - *piVar1 >> 2));
      }
      FUN_0052ea87(*piVar1,*(undefined4 *)(extraout_ECX + 0x178));
      FUN_005f4a97(unaff_EBP + -0x14);
      DVar4 = timeGetTime();
      *(DWORD *)(extraout_ECX + 0x180) = DVar4;
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

