
void FUN_005407ce(void)

{
  void *pvVar1;
  int iVar2;
  int *piVar3;
  int extraout_ECX;
  int iVar4;
  int iVar5;
  int unaff_EBP;
  undefined4 *puVar6;
  
  FUN_00634c24();
  iVar5 = *(int *)(unaff_EBP + 8);
  if (iVar5 == 0) {
    *(undefined4 *)(unaff_EBP + -0x24) = 0;
    *(undefined4 *)(unaff_EBP + -0x14) = 2;
  }
  else {
    *(int *)(unaff_EBP + -0x24) = iVar5 + -1;
    *(int *)(unaff_EBP + -0x14) = iVar5;
  }
  iVar4 = *(int *)(unaff_EBP + -0x24);
  if (iVar4 < *(int *)(unaff_EBP + -0x14)) {
    do {
      puVar6 = *(undefined4 **)(extraout_ECX + 8 + iVar4 * 4);
      FUN_005410a1(*puVar6,puVar6[1]);
      puVar6 = *(undefined4 **)(extraout_ECX + 0x10 + iVar4 * 4);
      FUN_005410ee(*puVar6,puVar6[1]);
      iVar5 = DAT_006e54dc;
      *(undefined4 *)(unaff_EBP + -0x20) = 0;
      iVar5 = *(int *)(iVar5 + 0x10);
      if (0 < iVar5) {
        do {
          *(undefined4 *)(unaff_EBP + -0x1c) = 0;
          *(char *)(unaff_EBP + -0xd) = (char)iVar4;
          *(char *)(unaff_EBP + -0xd) = *(char *)(unaff_EBP + -0xd) + '\x01';
          do {
            *(undefined1 *)(unaff_EBP + -0x18) = *(undefined1 *)(unaff_EBP + -0x1c);
            *(undefined1 *)(unaff_EBP + -0x17) = *(undefined1 *)(unaff_EBP + -0x20);
            *(undefined1 *)(unaff_EBP + -0x16) = *(undefined1 *)(unaff_EBP + -0xd);
            *(undefined4 *)(unaff_EBP + -4) = 0;
            FUN_0053f84a(unaff_EBP + -0x28,unaff_EBP + -0x18);
            *(undefined1 *)(unaff_EBP + -4) = 1;
            if ((*(char *)(unaff_EBP + -0x28) != '\0') &&
               (((&DAT_006f4b20)[*(byte *)(unaff_EBP + -0x28)] != '\0' ||
                ((&DAT_006f4a20)[*(byte *)(unaff_EBP + -0x28)] != '\0')))) {
              pvVar1 = operator_new(0x60);
              *(void **)(unaff_EBP + -0x2c) = pvVar1;
              *(undefined1 *)(unaff_EBP + -4) = 2;
              if (pvVar1 == (void *)0x0) {
                iVar2 = 0;
              }
              else {
                iVar2 = FUN_0053c1f5(unaff_EBP + -0x18,0);
              }
              *(undefined1 *)(unaff_EBP + -4) = 1;
              if (iVar2 != 0) {
                *(undefined1 *)(iVar2 + 8) = *(undefined1 *)(unaff_EBP + -0x28);
                FUN_00540bd7(iVar2,iVar4 + 1);
              }
            }
            *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
            *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + 1;
          } while (*(int *)(unaff_EBP + -0x1c) < iVar5);
          *(int *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + -0x20) + 1;
        } while (*(int *)(unaff_EBP + -0x20) < iVar5);
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(unaff_EBP + -0x14));
    iVar5 = *(int *)(unaff_EBP + 8);
  }
  FUN_005409be(iVar5);
  if (*(int *)(unaff_EBP + -0x24) < *(int *)(unaff_EBP + -0x14)) {
    puVar6 = (undefined4 *)(extraout_ECX + 8 + *(int *)(unaff_EBP + -0x24) * 4);
    *(int *)(unaff_EBP + -0x24) = *(int *)(unaff_EBP + -0x14) - *(int *)(unaff_EBP + -0x24);
    do {
      piVar3 = (int *)*puVar6;
      for (iVar5 = *piVar3; iVar5 != piVar3[1]; iVar5 = iVar5 + 4) {
        FUN_0053d15c();
        piVar3 = (int *)*puVar6;
      }
      puVar6 = puVar6 + 1;
      piVar3 = (int *)(unaff_EBP + -0x24);
      *piVar3 = *piVar3 + -1;
    } while (*piVar3 != 0);
    iVar5 = *(int *)(unaff_EBP + 8);
  }
  FUN_0054066a(*(undefined4 *)(extraout_ECX + 4));
  if (iVar5 == 0) {
    *(undefined4 *)(extraout_ECX + 0x3c) = 0;
    *(undefined4 *)(extraout_ECX + 0x38) = 0;
    *(undefined4 *)(extraout_ECX + 0x44) = 0;
    *(undefined4 *)(extraout_ECX + 0x40) = 0;
  }
  else {
    *(undefined4 *)(extraout_ECX + 0x3c + iVar5 * 4) = 0;
    *(undefined4 *)(extraout_ECX + 0x34 + iVar5 * 4) = 0;
  }
  FUN_004a6a08();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

