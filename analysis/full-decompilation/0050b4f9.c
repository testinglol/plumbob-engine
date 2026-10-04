
void FUN_0050b4f9(void)

{
  int *piVar1;
  uint uVar2;
  void *pvVar3;
  int iVar4;
  undefined4 uVar5;
  size_t sVar6;
  int extraout_ECX;
  char *pcVar7;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x14) = 0x400;
  pvVar3 = operator_new(0x400);
  *(void **)(unaff_EBP + -0x10) = pvVar3;
  *(undefined4 *)(unaff_EBP + -0x18) = 1;
  iVar4 = FUN_0047168f();
  if (0 < iVar4) {
    piVar1 = *(int **)(unaff_EBP + 8);
    do {
      uVar5 = FUN_004705f2(*(undefined4 *)(unaff_EBP + -0x18),0xffffffff);
      FUN_005d4956(uVar5);
      *(undefined4 *)(unaff_EBP + -4) = 0;
      while (*(uint *)(unaff_EBP + -0x14) <=
             (uint)(*(int *)(unaff_EBP + -0x20) - *(int *)(unaff_EBP + -0x24))) {
        FUN_006321f0(*(undefined4 *)(unaff_EBP + -0x10));
        uVar2 = *(int *)(unaff_EBP + -0x14) * 2;
        *(uint *)(unaff_EBP + -0x14) = uVar2;
        pvVar3 = operator_new(uVar2);
        *(void **)(unaff_EBP + -0x10) = pvVar3;
      }
      pcVar7 = *(char **)(unaff_EBP + -0x10);
      FUN_006358b0(pcVar7,*(undefined4 *)(unaff_EBP + -0x24));
      sVar6 = _strlen(pcVar7);
      *(char **)(unaff_EBP + 8) = pcVar7 + sVar6;
      if (pcVar7 < pcVar7 + sVar6) {
        do {
          if ((*pcVar7 == '\n') || (*pcVar7 == '\r')) {
            iVar4 = (**(code **)(*DAT_006f35fc + 0x44))(pcVar7,0xffffffff);
            *pcVar7 = '\0';
          }
          else {
            iVar4 = (**(code **)(*DAT_006f35fc + 0x44))(pcVar7,0xffffffff);
          }
          pcVar7 = pcVar7 + iVar4;
        } while (pcVar7 < *(char **)(unaff_EBP + 8));
      }
      pcVar7 = *(char **)(unaff_EBP + -0x10);
      while (pcVar7 < *(char **)(unaff_EBP + 8)) {
        uVar5 = FUN_0050b6d6(pcVar7,*piVar1);
        *(undefined1 *)(unaff_EBP + -4) = 1;
        FUN_0050bdf3(uVar5);
        *(undefined1 *)(unaff_EBP + -4) = 0;
        FUN_005b8770();
        *piVar1 = *piVar1 + 0x2ee;
        FUN_0050b812(extraout_ECX + 0x128);
        sVar6 = _strlen(pcVar7);
        if (sVar6 != 0) {
          pcVar7 = pcVar7 + sVar6;
        }
        do {
          if (*(char **)(unaff_EBP + 8) <= pcVar7) goto LAB_0050b637;
          pcVar7 = pcVar7 + 1;
          sVar6 = _strlen(pcVar7);
        } while (sVar6 == 0);
      }
LAB_0050b637:
      iVar4 = *(int *)(unaff_EBP + -0x20);
      if (((1 < (uint)(iVar4 - *(int *)(unaff_EBP + -0x24))) && (*(char *)(iVar4 + -1) == '\n')) &&
         (*(char *)(iVar4 + -2) == '\r')) {
        uVar5 = FUN_0050b6d6(&DAT_006de560,*piVar1);
        *(undefined1 *)(unaff_EBP + -4) = 2;
        FUN_0050bdf3(uVar5);
        *(undefined1 *)(unaff_EBP + -4) = 0;
        FUN_005b8770();
        *piVar1 = *piVar1 + 0x2ee;
        FUN_0050b812(extraout_ECX + 0x128);
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
      *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 1;
      iVar4 = FUN_0047168f();
    } while (*(int *)(unaff_EBP + -0x18) <= iVar4);
  }
  FUN_006321f0(*(undefined4 *)(unaff_EBP + -0x10));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

