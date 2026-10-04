
void FUN_0053f04f(void)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  undefined4 uVar4;
  char *pcVar5;
  byte *pbVar6;
  int extraout_ECX;
  int unaff_EBP;
  byte *pbVar7;
  
  FUN_00634c24();
  *(undefined1 *)(unaff_EBP + -0x3c) = *(undefined1 *)(extraout_ECX + 4);
  *(undefined1 *)(unaff_EBP + -0x3b) = *(undefined1 *)(extraout_ECX + 5);
  *(undefined1 *)(unaff_EBP + -0x3a) = *(undefined1 *)(extraout_ECX + 6);
  uVar4 = *(undefined4 *)(extraout_ECX + 0x10);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  uVar4 = FUN_0053c16a(uVar4);
  pbVar7 = *(byte **)(extraout_ECX + 0x30);
  *(undefined4 *)(unaff_EBP + -0x44) = uVar4;
  if (pbVar7 != *(byte **)(extraout_ECX + 0x34)) {
    do {
      *pbVar7 = 0;
      cVar3 = FUN_0053f36c((int)*(char *)(unaff_EBP + -0x3c));
      if (((cVar3 != '\0') && (pbVar7[1] != 0xff)) &&
         (cVar3 = FUN_0053cedf(pbVar7[1]), cVar3 == '\0')) {
        *pbVar7 = *pbVar7 | 1;
        if (*(int *)(unaff_EBP + -0x44) == 0x10) {
          FUN_0053f472(unaff_EBP + -0x48,unaff_EBP + -0x3c,*(undefined4 *)(extraout_ECX + 0x10));
          FUN_00461b74(&DAT_006e4822);
          *(undefined1 *)(unaff_EBP + 10) = 0;
          pcVar5 = (char *)FUN_0046185f(unaff_EBP + -0x24,unaff_EBP + 8);
          cVar3 = *pcVar5;
          *(undefined1 *)(unaff_EBP + -4) = 3;
          cVar3 = FUN_0053f36c((int)cVar3);
          if (cVar3 == '\0') {
            FUN_00461b74(&DAT_006e481c);
            *(undefined1 *)(unaff_EBP + -0xe) = 0;
            pcVar5 = (char *)FUN_0046185f(unaff_EBP + -0x28,unaff_EBP + -0x10);
            cVar3 = *pcVar5;
            *(undefined1 *)(unaff_EBP + -4) = 5;
            cVar3 = FUN_0053f36c((int)cVar3);
joined_r0x0053f272:
            if (cVar3 == '\0') goto LAB_0053f274;
          }
        }
        else {
          if (*(int *)(unaff_EBP + -0x44) != 0x20) {
            *(undefined1 *)(unaff_EBP + -0x40) = *(undefined1 *)(unaff_EBP + -0x3c);
            *(undefined1 *)(unaff_EBP + -0x3f) = *(undefined1 *)(unaff_EBP + -0x3b);
            *(undefined1 *)(unaff_EBP + -0x3e) = *(undefined1 *)(unaff_EBP + -0x3a);
            *(undefined1 *)(unaff_EBP + -4) = 0xf;
            FUN_0053c0e0(*(undefined4 *)(unaff_EBP + -0x44),unaff_EBP + -0x40);
            cVar3 = *(char *)(unaff_EBP + -0x40);
LAB_0053f268:
            cVar3 = FUN_0053f36c((int)cVar3);
            goto joined_r0x0053f272;
          }
          FUN_0053f472(unaff_EBP + -0x4c,unaff_EBP + -0x3c,*(undefined4 *)(extraout_ECX + 0x10));
          FUN_00461b74(&DAT_006e481c);
          *(undefined1 *)(unaff_EBP + -0x16) = 0;
          FUN_00461b74(&DAT_006e481c);
          *(undefined1 *)(unaff_EBP + -0x12) = 0;
          FUN_0046185f(unaff_EBP + -0x2c,unaff_EBP + -0x14);
          pcVar5 = (char *)FUN_0046185f(unaff_EBP + -0x30,unaff_EBP + -0x18);
          cVar3 = *pcVar5;
          *(undefined1 *)(unaff_EBP + -4) = 10;
          cVar3 = FUN_0053f36c((int)cVar3);
          if (cVar3 != '\0') {
            FUN_00461b74(&DAT_006e4822);
            *(undefined1 *)(unaff_EBP + -0x1e) = 0;
            FUN_00461b74(&DAT_006e4822);
            *(undefined1 *)(unaff_EBP + -0x1a) = 0;
            FUN_0046185f(unaff_EBP + -0x34,unaff_EBP + -0x1c);
            pcVar5 = (char *)FUN_0046185f(unaff_EBP + -0x38,unaff_EBP + -0x20);
            cVar3 = *pcVar5;
            *(undefined1 *)(unaff_EBP + -4) = 0xe;
            goto LAB_0053f268;
          }
LAB_0053f274:
          *pbVar7 = *pbVar7 & 0xfe;
        }
        *(undefined1 *)(unaff_EBP + -4) = 0;
      }
      if (((*pbVar7 & 1) != 0) && (cVar3 = FUN_0053d98e(pbVar7[1],1), cVar3 != '\0')) {
        *pbVar7 = *pbVar7 | 8;
      }
      pbVar7 = pbVar7 + 6;
      *(char *)(unaff_EBP + -0x3c) = *(char *)(unaff_EBP + -0x3c) + *(char *)(extraout_ECX + 10);
      *(char *)(unaff_EBP + -0x3b) = *(char *)(unaff_EBP + -0x3b) + *(char *)(extraout_ECX + 0xb);
    } while (pbVar7 != *(byte **)(extraout_ECX + 0x34));
  }
  if ((*(int *)(extraout_ECX + 0x10) == 3) || (*(int *)(extraout_ECX + 0x10) == 6)) {
    *(undefined4 *)(unaff_EBP + 8) = 4;
    *(undefined4 *)(unaff_EBP + -0x4c) = 2;
  }
  else {
    *(undefined4 *)(unaff_EBP + 8) = 2;
    *(undefined4 *)(unaff_EBP + -0x4c) = 4;
  }
  if (1 < (uint)((*(int *)(extraout_ECX + 0x34) - *(int *)(extraout_ECX + 0x30)) / 6)) {
    pbVar7 = *(byte **)(extraout_ECX + 0x30);
    while (pbVar6 = pbVar7, pbVar6 != (byte *)(*(int *)(extraout_ECX + 0x34) + -6)) {
      bVar1 = *pbVar6;
      pbVar7 = pbVar6 + 6;
      if (((pbVar6[6] ^ bVar1) & 1) != 0) {
        if ((bVar1 & 1) == 0) {
          bVar1 = pbVar6[1];
          if ((((bVar1 != 0xff) && (bVar1 != 2)) && (bVar1 != 0xc)) &&
             ((bVar1 != 0xd && (bVar1 != 0xe)))) {
            *pbVar7 = pbVar6[6] | *(byte *)(unaff_EBP + -0x4c);
          }
        }
        else {
          bVar2 = pbVar6[7];
          if (((bVar2 != 0xff) && (bVar2 != 2)) &&
             ((bVar2 != 0xc && ((bVar2 != 0xd && (bVar2 != 0xe)))))) {
            *pbVar6 = bVar1 | *(byte *)(unaff_EBP + 8);
          }
        }
      }
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

