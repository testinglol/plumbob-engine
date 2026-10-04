
void FUN_0041bed0(void)

{
  undefined4 uVar1;
  int extraout_ECX;
  int iVar2;
  int unaff_EBP;
  int iVar3;
  
  FUN_00634c24();
  iVar2 = *(int *)(unaff_EBP + 8);
  FUN_00464a5e(extraout_ECX + 0x14,1);
  *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(extraout_ECX + 0x10);
  FUN_00464a5e(unaff_EBP + -0x20,1);
  iVar3 = *(int *)(iVar2 + 0xc);
  if ((iVar3 == 1) || (iVar3 == 2)) {
    FUN_00580a92(unaff_EBP + -0x40);
    while (*(int *)(unaff_EBP + -0x40) != 0) {
      *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(*(int *)(unaff_EBP + -0x40) + 4);
      FUN_00464a5e(unaff_EBP + -0x10,1);
      *(undefined4 *)(unaff_EBP + -0x38) = *(undefined4 *)(*(int *)(unaff_EBP + -0x40) + 0x18);
      FUN_00464a5e(unaff_EBP + -0x38,1);
      *(undefined4 *)(unaff_EBP + -4) = 0;
      FUN_0055e4e2(unaff_EBP + 0xb);
      *(undefined1 *)(unaff_EBP + -4) = 2;
      FUN_00580a92(unaff_EBP + -0x48);
      while (iVar3 = *(int *)(unaff_EBP + -0x48), iVar3 != 0) {
        *(undefined4 *)(unaff_EBP + -0x18) = 0xffffffff;
        *(int *)(unaff_EBP + -0x14) = iVar3 + 7;
        *(int *)(unaff_EBP + -0x18) = (int)*(short *)(iVar3 + 0xd);
        FUN_0041d818(unaff_EBP + -0x18);
        FUN_0041ddb4();
      }
      FUN_0041e725(*(undefined4 *)(unaff_EBP + -0x34),*(undefined4 *)(unaff_EBP + -0x30));
      iVar3 = *(int *)(unaff_EBP + -0x34);
      *(int *)(unaff_EBP + -0x28) = *(int *)(unaff_EBP + -0x30);
      if (iVar3 != *(int *)(unaff_EBP + -0x30)) {
        do {
          FUN_0041b80b(iVar2,*(undefined4 *)(unaff_EBP + 0xc));
          iVar3 = iVar3 + 8;
        } while (iVar3 != *(int *)(unaff_EBP + -0x28));
      }
      FUN_00576e56();
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_0059b3b3();
    }
  }
  else if (iVar3 == 0) {
    FUN_0041e4d9();
    *(undefined4 *)(unaff_EBP + -0x10) = 0;
    if (0 < *(int *)(unaff_EBP + -0x20)) {
      do {
        FUN_00464a5e(unaff_EBP + -0x28,1);
        FUN_00464a5e(unaff_EBP + -0x14,1);
        iVar2 = 8;
        if (0 < *(int *)(unaff_EBP + -0x14)) {
          uVar1 = *(undefined4 *)(unaff_EBP + -0x28);
          FUN_0041d852(100,unaff_EBP + -0x21,unaff_EBP + -0x19,unaff_EBP + -0x22);
          *(undefined4 *)(unaff_EBP + -4) = 3;
          *(undefined4 *)(unaff_EBP + -0x60) = uVar1;
          FUN_0041d8a2(unaff_EBP + -0x78);
          iVar3 = *(int *)(extraout_ECX + 0x10);
          *(undefined1 *)(unaff_EBP + -4) = 4;
          FUN_0041e3a4(iVar3 + 1);
          FUN_0041e2de(unaff_EBP + -0x34,unaff_EBP + -0x60);
          *(int *)(unaff_EBP + -0x38) = unaff_EBP + -0x5c;
          *(undefined1 *)(unaff_EBP + -4) = 5;
          FUN_0041dffb();
          *(undefined1 *)(unaff_EBP + -4) = 3;
          FUN_005481b6();
          *(undefined4 *)(unaff_EBP + -4) = 6;
          FUN_0041dffb();
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          FUN_005481b6();
          if (*(char *)(unaff_EBP + -0x2c) != '\0') {
            iVar2 = *(int *)(unaff_EBP + -0x34) + 8;
          }
        }
        iVar3 = 0;
        if (0 < *(int *)(unaff_EBP + -0x14)) {
          do {
            FUN_0041c16f();
            FUN_0041b80b(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc));
            *(short *)(unaff_EBP + -0xda) = (short)iVar3 + 1;
            *(char *)(unaff_EBP + -0x13e) = (char)((uint)*(undefined4 *)(unaff_EBP + -0xde) >> 8);
            *(undefined2 *)(unaff_EBP + -0x140) = *(undefined2 *)(unaff_EBP + -0xe0);
            FUN_0041ba73(unaff_EBP + -0xe0);
            FUN_0041decf(*(int *)(iVar2 + 0x10) + 1);
            FUN_0041ddf9(unaff_EBP + -0x84,unaff_EBP + -0x140);
            iVar3 = iVar3 + 1;
          } while (iVar3 < *(int *)(unaff_EBP + -0x14));
        }
        *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
      } while (*(int *)(unaff_EBP + -0x10) < *(int *)(unaff_EBP + -0x20));
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

