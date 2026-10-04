
void FUN_004903f2(void)

{
  int *piVar1;
  byte bVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 uVar5;
  char cVar6;
  char cVar7;
  undefined4 *puVar8;
  int iVar9;
  char *pcVar10;
  undefined4 extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x28) = extraout_ECX;
  FUN_00461c48();
  iVar9 = DAT_006e54dc;
  *(undefined1 *)(unaff_EBP + -0x12) = 1;
  uVar3 = *(undefined4 *)(iVar9 + 0x10);
  *(undefined1 *)(unaff_EBP + -0x10) = 0;
  uVar5 = (undefined1)uVar3;
  *(undefined1 *)(unaff_EBP + -0x14) = uVar5;
  *(undefined1 *)(unaff_EBP + -0x13) = uVar5;
  *(undefined1 *)(unaff_EBP + -0xf) = 0;
  *(undefined1 *)(unaff_EBP + -0xe) = 1;
  *(undefined1 *)(unaff_EBP + -0x2e) = 0;
  *(undefined1 *)(unaff_EBP + -0x2b) = 0;
  FUN_00461b74(unaff_EBP + -0x10);
  FUN_00461b74(unaff_EBP + -0x14);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x40) = 0;
  *(undefined1 *)(unaff_EBP + -0x3a) = 0;
  FUN_004619d2(unaff_EBP + -0x48);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  puVar8 = (undefined4 *)FUN_004619b0(unaff_EBP + -0x38);
  *(undefined4 *)(unaff_EBP + -0x40) = *puVar8;
  FUN_00461b74(puVar8 + 1);
  while( true ) {
    iVar9 = FUN_004619d2(unaff_EBP + -0x50);
    cVar6 = FUN_0046198c(iVar9 + 4);
    cVar6 = '\x01' - (cVar6 != '\0');
    *(char *)(unaff_EBP + -0xd) = cVar6;
    if (cVar6 == '\0') break;
    pcVar10 = (char *)FUN_00461941(unaff_EBP + -0x10);
    if (*(byte *)(*(int *)(*(int *)(*(int *)(unaff_EBP + 8) + 0x10) + *pcVar10 * 4) +
                 (int)pcVar10[1]) < 0x10) {
      *(undefined4 *)(unaff_EBP + -0x70) = 0;
      *(undefined4 *)(unaff_EBP + -0x6c) = 1;
      *(undefined4 *)(unaff_EBP + -0x68) = 2;
      *(undefined4 *)(unaff_EBP + -100) = 3;
      *(undefined4 *)(unaff_EBP + -0x60) = 4;
      *(undefined4 *)(unaff_EBP + -0x5c) = 5;
      *(undefined4 *)(unaff_EBP + -0x58) = 6;
      *(undefined4 *)(unaff_EBP + -0x54) = 7;
      *(undefined1 *)(unaff_EBP + -0x38) = 0;
      *(undefined1 *)(unaff_EBP + -0x37) = 0;
      *(undefined1 *)(unaff_EBP + -0x36) = 0;
      *(undefined1 *)(unaff_EBP + -0x35) = 0;
      *(undefined1 *)(unaff_EBP + -0x34) = 0;
      *(undefined1 *)(unaff_EBP + -0x33) = 0;
      *(undefined1 *)(unaff_EBP + -0x32) = 0;
      *(undefined1 *)(unaff_EBP + -0x31) = 0;
      *(int *)(unaff_EBP + -0x20) = unaff_EBP + -0x70;
      *(undefined4 *)(unaff_EBP + -0x24) = 8;
      do {
        iVar9 = **(int **)(unaff_EBP + -0x20);
        FUN_00461b74(&DAT_006e481c + iVar9 * 3);
        *(undefined1 *)(unaff_EBP + -0x12) = 0;
        FUN_00461941(unaff_EBP + -0x18);
        FUN_0046185f(unaff_EBP + -0x1c,unaff_EBP + -0x14);
        *(undefined1 *)(unaff_EBP + -4) = 3;
        cVar6 = *(char *)(unaff_EBP + -0x1b);
        iVar4 = *(int *)(*(int *)(*(int *)(unaff_EBP + 8) + 0x10) + *(char *)(unaff_EBP + -0x1c) * 4
                        );
        bVar2 = *(byte *)(iVar4 + cVar6);
        if ((bVar2 < 0x10) || (bVar2 == 0x10)) {
          *(undefined1 *)(unaff_EBP + -0x38 + iVar9) = 1;
        }
        else {
          cVar7 = FUN_004902ec(unaff_EBP + -0x1c,iVar9,unaff_EBP + -0x38);
          if (cVar7 != '\0') {
            *(undefined1 *)(unaff_EBP + -0x38 + iVar9) = 1;
            *(undefined1 *)(iVar4 + cVar6) = 0x10;
          }
        }
        *(int *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + -0x20) + 4;
        piVar1 = (int *)(unaff_EBP + -0x24);
        *piVar1 = *piVar1 + -1;
        *(undefined1 *)(unaff_EBP + -4) = 2;
      } while (*piVar1 != 0);
    }
    FUN_00461961();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

