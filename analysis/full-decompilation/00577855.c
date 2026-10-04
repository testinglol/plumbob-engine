
undefined4 FUN_00577855(void)

{
  char cVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  int *extraout_ECX;
  undefined4 *puVar5;
  int iVar6;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar2 = DAT_006f63e8;
  *(int **)(unaff_EBP + -0x14) = &DAT_006f63e8;
  *(undefined ***)(unaff_EBP + -0x18) = &PTR_LAB_00669c88;
  (**(code **)(iVar2 + 4))();
  uVar4 = *(undefined4 *)(unaff_EBP + 0xc);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  extraout_ECX[0xd] = *(int *)(unaff_EBP + 8);
  FUN_005d499c(uVar4);
  extraout_ECX[3] = *(int *)(unaff_EBP + 0x10);
  extraout_ECX[0x1f] = -1;
  extraout_ECX[0x20] = -1;
  extraout_ECX[0x21] = -1;
  extraout_ECX[0x22] = -1;
  iVar2 = extraout_ECX[0xd];
  extraout_ECX[10] = *(int *)(iVar2 + 4);
  extraout_ECX[0x12] = 1;
  extraout_ECX[0x11] = 1;
  extraout_ECX[0x1a] = *(int *)(iVar2 + 0xc);
  extraout_ECX[0x1b] = *(int *)(iVar2 + 0x10);
  extraout_ECX[0x1d] = *(int *)(iVar2 + 0x20);
  extraout_ECX[0x1e] = *(int *)(iVar2 + 0x1c);
  if (((char)extraout_ECX[1] == '\0') &&
     (iVar6 = *(int *)(iVar2 + 0x24), *(undefined4 *)(unaff_EBP + 0x10) = 0, 0 < iVar6)) {
    *(int **)(unaff_EBP + 0xc) = extraout_ECX + 0x25;
    do {
      iVar2 = *(int *)(iVar2 + 0x28);
      *(undefined4 *)(unaff_EBP + 8) = 0;
      if (0 < iVar2) {
        puVar5 = *(undefined4 **)(unaff_EBP + 0xc);
        do {
          pvVar3 = operator_new(0x18);
          *(void **)(unaff_EBP + -0x10) = pvVar3;
          *(undefined1 *)(unaff_EBP + -4) = 1;
          if (pvVar3 == (void *)0x0) {
            uVar4 = 0;
          }
          else {
            uVar4 = FUN_00579a22(extraout_ECX);
          }
          *(undefined1 *)(unaff_EBP + -4) = 0;
          *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 1;
          iVar2 = *(int *)(unaff_EBP + 8);
          *puVar5 = uVar4;
          puVar5 = puVar5 + 1;
        } while (iVar2 < *(int *)(extraout_ECX[0xd] + 0x28));
      }
      *(int *)(unaff_EBP + 0x10) = *(int *)(unaff_EBP + 0x10) + 1;
      iVar2 = extraout_ECX[0xd];
      *(int *)(unaff_EBP + 0xc) = *(int *)(unaff_EBP + 0xc) + 0x100;
    } while (*(int *)(unaff_EBP + 0x10) < *(int *)(iVar2 + 0x24));
  }
  iVar6 = 0;
  iVar2 = extraout_ECX[0xd];
  extraout_ECX[0x15] = 0;
  if (0 < *(int *)(iVar2 + 0x24)) {
    do {
      *(undefined4 *)(unaff_EBP + 8) = 0;
      if (0 < *(int *)(iVar2 + 0x28)) {
        do {
          cVar1 = (**(code **)(*extraout_ECX + 0x84))(iVar6,*(undefined4 *)(unaff_EBP + 8));
          if (cVar1 != '\0') {
            extraout_ECX[0x15] = extraout_ECX[0x15] + 1;
          }
          *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 1;
        } while (*(int *)(unaff_EBP + 8) < *(int *)(extraout_ECX[0xd] + 0x28));
      }
      iVar2 = extraout_ECX[0xd];
      iVar6 = iVar6 + 1;
    } while (iVar6 < *(int *)(iVar2 + 0x24));
  }
  iVar2 = *(int *)(unaff_EBP + 0x14);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined1 *)(extraout_ECX + 1) = 1;
  extraout_ECX[0xe] = iVar2;
  (**(code **)(DAT_006f63e8 + 8))();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 1;
}

