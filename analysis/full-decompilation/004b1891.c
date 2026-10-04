
void FUN_004b1891(void)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  char cVar5;
  int extraout_ECX;
  int iVar6;
  char cVar7;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_004a891e();
  *(undefined4 *)(unaff_EBP + -0x40) = DAT_006fe838;
  DAT_006fe838 = 0;
  FUN_004aa1b9(unaff_EBP + -0x34,unaff_EBP + -0x28,unaff_EBP + -0x3c);
  *(undefined1 *)(unaff_EBP + -0x14) = 1;
  *(undefined1 *)(unaff_EBP + -0x13) = 1;
  *(undefined1 *)(unaff_EBP + -0x12) = 1;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_004a8000();
  *(undefined1 **)(unaff_EBP + -0x38) = &stack0xffffff7c;
  iVar3 = FUN_004796d9(unaff_EBP + -0x38);
  bVar1 = *(byte *)(iVar3 + 1);
  FUN_004b3e97(unaff_EBP + -0x20,unaff_EBP + -0x18);
  iVar3 = DAT_006e54d8;
  iVar4 = *(int *)(unaff_EBP + -0x18) - ((uint)bVar1 << ((char)DAT_006f0088 + 1U & 0x1f));
  *(int *)(unaff_EBP + -0x18) = iVar4;
  *(int *)(unaff_EBP + -0x3c) = iVar4 - DAT_006f0084;
  uVar2 = *(undefined4 *)(iVar3 + 0x10);
  *(undefined1 *)(unaff_EBP + -0x13) = 1;
  *(char *)(unaff_EBP + -0x14) = (char)uVar2 + -2;
  *(undefined1 *)(unaff_EBP + -0x12) = 1;
  FUN_004a8000();
  *(undefined1 **)(unaff_EBP + -0x38) = &stack0xffffff7c;
  iVar3 = FUN_004796d9(unaff_EBP + -0x38);
  bVar1 = *(byte *)(iVar3 + 1);
  FUN_004b3e97(unaff_EBP + -0x20,unaff_EBP + -0x18);
  iVar3 = DAT_006e54d8;
  *(int *)(unaff_EBP + -0x18) =
       *(int *)(unaff_EBP + -0x18) - ((uint)bVar1 << ((char)DAT_006f0088 + 1U & 0x1f));
  *(int *)(unaff_EBP + -0x28) =
       (*(int *)(extraout_ECX + 0x58) * 2 - DAT_006f0080) + *(int *)(unaff_EBP + -0x20);
  uVar2 = *(undefined4 *)(iVar3 + 0x10);
  *(undefined1 *)(unaff_EBP + -0x14) = 1;
  *(char *)(unaff_EBP + -0x13) = (char)uVar2 + -2;
  *(undefined1 *)(unaff_EBP + -0x12) = 1;
  FUN_004a8000();
  *(undefined1 **)(unaff_EBP + -0x38) = &stack0xffffff7c;
  iVar3 = FUN_004796d9(unaff_EBP + -0x38);
  bVar1 = *(byte *)(iVar3 + 1);
  FUN_004b3e97(unaff_EBP + -0x20,unaff_EBP + -0x18);
  *(int *)(unaff_EBP + -0x18) =
       *(int *)(unaff_EBP + -0x18) - ((uint)bVar1 << ((char)DAT_006f0088 + 1U & 0x1f));
  iVar3 = (*(int *)(unaff_EBP + -0x20) + *(int *)(extraout_ECX + 0x58) * -2) - DAT_006f0080;
  *(int *)(unaff_EBP + -0x34) = iVar3;
  *(int *)(unaff_EBP + -0x70) = iVar3;
  *(undefined4 *)(unaff_EBP + -0x68) = *(undefined4 *)(unaff_EBP + -0x28);
  iVar3 = *(int *)(extraout_ECX + 0x60);
  *(int *)(unaff_EBP + -100) = *(int *)(unaff_EBP + -0x3c);
  *(int *)(unaff_EBP + -0x6c) = *(int *)(unaff_EBP + -0x3c) + iVar3 * -0x14;
  FUN_005cddcf();
  _memset((void *)(unaff_EBP + -0x60),0,0x10);
  iVar4 = DAT_006e54d8;
  *(undefined4 *)(unaff_EBP + -0x2c) = 0xffffffff;
  *(undefined4 *)(unaff_EBP + -0x30) = 0xffffffff;
  iVar3 = 1;
  if (1 < *(int *)(iVar4 + 0x10) + -1) {
    do {
      *(undefined1 *)(unaff_EBP + -0x1c) = 1;
      *(char *)(unaff_EBP + -0x1b) = (char)iVar3;
      *(undefined1 *)(unaff_EBP + -0x1a) = 1;
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_004a8000();
      *(undefined1 **)(unaff_EBP + -0x38) = &stack0xffffff7c;
      iVar4 = FUN_004796d9(unaff_EBP + -0x24);
      *(undefined1 *)(unaff_EBP + -0xd) = *(undefined1 *)(iVar4 + 1);
      FUN_004b3e97(unaff_EBP + -0x20,unaff_EBP + -0x18);
      iVar6 = DAT_006f0084;
      *(int *)(unaff_EBP + -0x18) =
           *(int *)(unaff_EBP + -0x18) -
           ((uint)*(byte *)(unaff_EBP + -0xd) << ((char)DAT_006f0088 + 1U & 0x1f));
      *(undefined4 *)(unaff_EBP + -0x60) = *(undefined4 *)(unaff_EBP + -0x34);
      iVar4 = *(int *)(unaff_EBP + -0x2c);
      if (iVar4 == -1) {
        iVar4 = *(int *)(unaff_EBP + -0x18) - iVar6;
      }
      *(int *)(unaff_EBP + -0x5c) = iVar4;
      *(int *)(unaff_EBP + -0x58) =
           (*(int *)(extraout_ECX + 0x58) - DAT_006f0080) + *(int *)(unaff_EBP + -0x20);
      iVar4 = (*(int *)(extraout_ECX + 0x60) - iVar6) + *(int *)(unaff_EBP + -0x18);
      *(int *)(unaff_EBP + -0x54) = iVar4;
      *(int *)(unaff_EBP + -0x2c) = iVar4;
      FUN_005cddcf();
      *(char *)(unaff_EBP + -0x1c) = (char)iVar3;
      *(undefined1 *)(unaff_EBP + -0x1b) = 1;
      *(undefined1 *)(unaff_EBP + -0x1a) = 1;
      FUN_004a8000();
      *(undefined1 **)(unaff_EBP + -0x38) = &stack0xffffff7c;
      iVar4 = FUN_004796d9(unaff_EBP + -0x48);
      *(undefined1 *)(unaff_EBP + -0xd) = *(undefined1 *)(iVar4 + 1);
      FUN_004b3e97(unaff_EBP + -0x20,unaff_EBP + -0x18);
      iVar6 = DAT_006f0084;
      *(int *)(unaff_EBP + -0x18) =
           *(int *)(unaff_EBP + -0x18) -
           ((uint)*(byte *)(unaff_EBP + -0xd) << ((char)DAT_006f0088 + 1U & 0x1f));
      iVar4 = *(int *)(unaff_EBP + -0x30);
      if (iVar4 == -1) {
        iVar4 = *(int *)(unaff_EBP + -0x18) - iVar6;
      }
      *(int *)(unaff_EBP + -0x5c) = iVar4;
      *(undefined4 *)(unaff_EBP + -0x58) = *(undefined4 *)(unaff_EBP + -0x28);
      iVar4 = (*(int *)(extraout_ECX + 0x60) - iVar6) + *(int *)(unaff_EBP + -0x18);
      *(int *)(unaff_EBP + -0x60) =
           (*(int *)(unaff_EBP + -0x20) - *(int *)(extraout_ECX + 0x58)) - DAT_006f0080;
      *(int *)(unaff_EBP + -0x54) = iVar4;
      *(int *)(unaff_EBP + -0x30) = iVar4;
      FUN_005cddcf();
      iVar4 = DAT_006e54d8;
      *(undefined1 *)(unaff_EBP + -4) = 0;
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(iVar4 + 0x10) + -1);
  }
  iVar3 = 2;
  if (2 < *(int *)(iVar4 + 0x10) + -1) {
    do {
      uVar2 = *(undefined4 *)(iVar4 + 0x10);
      cVar7 = (char)iVar3;
      *(char *)(unaff_EBP + -0x1c) = cVar7;
      *(undefined1 *)(unaff_EBP + -0x1a) = 1;
      *(char *)(unaff_EBP + -0x1b) = (char)uVar2 + -2;
      *(undefined1 *)(unaff_EBP + -4) = 2;
      FUN_004a8000();
      *(undefined1 **)(unaff_EBP + -0x48) = &stack0xffffff7c;
      iVar4 = FUN_004796d9(unaff_EBP + -0x4c);
      *(undefined1 *)(unaff_EBP + -0xd) = *(undefined1 *)(iVar4 + 1);
      FUN_004b3e97(unaff_EBP + -0x38,unaff_EBP + -0x24);
      uVar2 = DAT_006f0088;
      *(int *)(unaff_EBP + -0x5c) = *(int *)(unaff_EBP + -0x2c);
      *(int *)(unaff_EBP + -0x60) = *(int *)(unaff_EBP + -0x34);
      *(int *)(unaff_EBP + -0x24) =
           *(int *)(unaff_EBP + -0x24) -
           ((uint)*(byte *)(unaff_EBP + -0xd) << ((char)uVar2 + 1U & 0x1f));
      *(int *)(unaff_EBP + -0x58) =
           (*(int *)(extraout_ECX + 0x58) - DAT_006f0080) + *(int *)(unaff_EBP + -0x38);
      iVar4 = (*(int *)(extraout_ECX + 0x60) - DAT_006f0084) + *(int *)(unaff_EBP + -0x24);
      *(int *)(unaff_EBP + -0x54) = iVar4;
      if ((*(int *)(unaff_EBP + -0x34) < *(int *)(unaff_EBP + -0x58)) &&
         (*(int *)(unaff_EBP + -0x2c) < iVar4)) {
        *(int *)(unaff_EBP + -0x2c) = iVar4;
        FUN_005cddcf();
      }
      iVar4 = DAT_006e54d8;
      uVar2 = *(undefined4 *)(DAT_006e54d8 + 0x10);
      *(char *)(unaff_EBP + -0x1b) = cVar7;
      cVar5 = (char)uVar2 + -2;
      *(undefined1 *)(unaff_EBP + -0x1a) = 1;
      *(char *)(unaff_EBP + -0x1c) = cVar5;
      uVar2 = *(undefined4 *)(iVar4 + 0x70);
      *(char *)(unaff_EBP + -0x1b) = (char)*(undefined4 *)(iVar4 + 0x78) + cVar7;
      *(char *)(unaff_EBP + -0x1c) = (char)uVar2 + cVar5;
      *(undefined1 **)(unaff_EBP + -0x48) = &stack0xffffff7c;
      iVar4 = FUN_004796d9(unaff_EBP + -0x50);
      *(undefined1 *)(unaff_EBP + -0xd) = *(undefined1 *)(iVar4 + 1);
      FUN_004b3e97(unaff_EBP + -0x38,unaff_EBP + -0x24);
      uVar2 = DAT_006f0088;
      *(int *)(unaff_EBP + -0x5c) = *(int *)(unaff_EBP + -0x30);
      iVar4 = *(int *)(extraout_ECX + 0x58);
      *(int *)(unaff_EBP + -0x24) =
           *(int *)(unaff_EBP + -0x24) -
           ((uint)*(byte *)(unaff_EBP + -0xd) << ((char)uVar2 + 1U & 0x1f));
      iVar4 = (*(int *)(unaff_EBP + -0x38) - iVar4) - DAT_006f0080;
      *(undefined4 *)(unaff_EBP + -0x58) = *(undefined4 *)(unaff_EBP + -0x28);
      iVar6 = *(int *)(extraout_ECX + 0x60) - DAT_006f0084;
      *(int *)(unaff_EBP + -0x60) = iVar4;
      iVar6 = iVar6 + *(int *)(unaff_EBP + -0x24);
      *(int *)(unaff_EBP + -0x54) = iVar6;
      if ((iVar4 < *(int *)(unaff_EBP + -0x28)) || (*(int *)(unaff_EBP + -0x30) < iVar6)) {
        *(int *)(unaff_EBP + -0x30) = iVar6;
        FUN_005cddcf();
      }
      iVar4 = DAT_006e54d8;
      *(undefined1 *)(unaff_EBP + -4) = 0;
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(iVar4 + 0x10) + -1);
  }
  iVar3 = *(int *)(extraout_ECX + 0x60);
  *(int *)(unaff_EBP + -0x7c) = *(int *)(unaff_EBP + -0x54);
  *(int *)(unaff_EBP + -0x74) = *(int *)(unaff_EBP + -0x54) + iVar3 * 0xc;
  *(undefined4 *)(unaff_EBP + -0x80) = *(undefined4 *)(unaff_EBP + -0x34);
  *(undefined4 *)(unaff_EBP + -0x78) = *(undefined4 *)(unaff_EBP + -0x28);
  FUN_005cddcf();
  FUN_005cce97();
  DAT_006fe838 = *(undefined4 *)(unaff_EBP + -0x40);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

