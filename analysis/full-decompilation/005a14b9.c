
undefined4 FUN_005a14b9(void)

{
  char *_Str;
  int iVar1;
  size_t sVar2;
  int iVar3;
  undefined4 uVar4;
  void *pvVar5;
  int unaff_EBP;
  undefined1 auStack_200 [32];
  undefined4 uStack_1e0;
  int iStack_1dc;
  undefined4 uStack_1d8;
  undefined4 uStack_1d4;
  int iStack_1d0;
  undefined4 uStack_1cc;
  int iStack_1c8;
  
  FUN_00634c24();
  iVar1 = FUN_005990f7();
  if (iVar1 != 0) {
    _Str = *(char **)(unaff_EBP + 0xc);
    if (_Str != (char *)0x0) {
      sVar2 = _strlen(_Str);
      if (sVar2 != 0) {
        iStack_1c8 = 0x5a1505;
        iVar3 = _strcmp(_Str,&DAT_006d1e30);
        if (iVar3 == 0) {
          *(undefined4 *)(unaff_EBP + 8) = 0x40490fd0;
          *(undefined4 *)(unaff_EBP + -0x14) = 0;
          *(undefined4 *)(unaff_EBP + -0x18) = 0x3f000000;
          *(undefined4 *)(unaff_EBP + -0x10) = 0;
          iStack_1c8 = 0x5a1537;
          uVar4 = FUN_00462f96();
          iStack_1c8 = unaff_EBP + 8;
          *(undefined4 *)(unaff_EBP + -4) = 1;
          iStack_1d0 = unaff_EBP + -0xf4;
          uStack_1cc = 2;
          uStack_1d4 = 0x5a1552;
          uStack_1d8 = FUN_005c38c0();
          iStack_1dc = unaff_EBP + -0x6c;
          *(undefined1 *)(unaff_EBP + -4) = 2;
          uStack_1e0 = 0x5a1561;
          uStack_1d4 = uVar4;
          FUN_0049b9e6();
          *(undefined1 *)(unaff_EBP + -4) = 5;
          FUN_005c4890();
          *(undefined1 *)(unaff_EBP + -4) = 4;
          FUN_005c4890();
          pvVar5 = operator_new(0x48);
          *(void **)(unaff_EBP + 8) = pvVar5;
          *(undefined1 *)(unaff_EBP + -4) = 6;
          if (pvVar5 == (void *)0x0) {
            uVar4 = 0;
          }
          else {
            *(undefined1 **)(unaff_EBP + 0xc) = auStack_200;
            FUN_005c36c0(unaff_EBP + -0x6c);
            uVar4 = FUN_005a1865(iVar1);
          }
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        }
        else {
          iStack_1c8 = 0x5a15cc;
          iVar3 = _strcmp(_Str,(char *)&PTR_DAT_006d1e2c);
          if (iVar3 == 0) {
            *(undefined4 *)(unaff_EBP + 8) = 0xbfc90fd0;
            *(undefined4 *)(unaff_EBP + -0x14) = 0;
            *(undefined4 *)(unaff_EBP + -0x18) = 0x3f4ccccd;
            *(undefined4 *)(unaff_EBP + -0x10) = 0;
            iStack_1c8 = 0x5a15fe;
            uVar4 = FUN_00462f96();
            iStack_1c8 = unaff_EBP + 8;
            *(undefined4 *)(unaff_EBP + -4) = 7;
            iStack_1d0 = unaff_EBP + -0xb0;
            uStack_1cc = 2;
            uStack_1d4 = 0x5a1619;
            uStack_1d8 = FUN_005c38c0();
            iStack_1dc = unaff_EBP + -0x6c;
            *(undefined1 *)(unaff_EBP + -4) = 8;
            uStack_1e0 = 0x5a1628;
            uStack_1d4 = uVar4;
            FUN_0049b9e6();
            *(undefined1 *)(unaff_EBP + -4) = 0xb;
            FUN_005c4890();
            *(undefined1 *)(unaff_EBP + -4) = 10;
            FUN_005c4890();
            pvVar5 = operator_new(0x48);
            *(void **)(unaff_EBP + 8) = pvVar5;
            *(undefined1 *)(unaff_EBP + -4) = 0xc;
            if (pvVar5 == (void *)0x0) {
              uVar4 = 0;
            }
            else {
              *(undefined1 **)(unaff_EBP + 0xc) = auStack_200;
              FUN_005c36c0(unaff_EBP + -0x6c);
              uVar4 = FUN_005a1865(iVar1);
            }
            *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          }
          else {
            iStack_1c8 = 0x5a1693;
            iVar3 = _strcmp(_Str,s_HeadFake_006d1a3c);
            if (iVar3 == 0) {
              *(undefined4 *)(unaff_EBP + 8) = 0xbfc90fd0;
              *(undefined4 *)(unaff_EBP + -0x18) = 0x3f4ccccd;
              *(undefined4 *)(unaff_EBP + -0x14) = 0;
              *(undefined4 *)(unaff_EBP + -0x10) = 0x42c80000;
              iStack_1c8 = 0x5a16c7;
              uVar4 = FUN_00462f96();
              iStack_1c8 = unaff_EBP + 8;
              *(undefined4 *)(unaff_EBP + -4) = 0xd;
              iStack_1d0 = unaff_EBP + -0xb0;
              uStack_1cc = 2;
              uStack_1d4 = 0x5a16e2;
              uStack_1d8 = FUN_005c38c0();
              iStack_1dc = unaff_EBP + -0x6c;
              *(undefined1 *)(unaff_EBP + -4) = 0xe;
              uStack_1e0 = 0x5a16f1;
              uStack_1d4 = uVar4;
              FUN_0049b9e6();
              *(undefined1 *)(unaff_EBP + -4) = 0x11;
              FUN_005c4890();
              *(undefined1 *)(unaff_EBP + -4) = 0x10;
              FUN_005c4890();
              pvVar5 = operator_new(0x48);
              *(void **)(unaff_EBP + 8) = pvVar5;
              *(undefined1 *)(unaff_EBP + -4) = 0x12;
              if (pvVar5 == (void *)0x0) {
                uVar4 = 0;
              }
              else {
                *(undefined1 **)(unaff_EBP + 0xc) = auStack_200;
                FUN_005c36c0(unaff_EBP + -0x6c);
                uVar4 = FUN_005a1865(iVar1);
              }
              *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
            }
            else {
              iStack_1c8 = 0x5a175c;
              iVar3 = _strcmp(_Str,s_Shoulder_006d1e20);
              if (iVar3 != 0) goto LAB_005a1853;
              *(undefined4 *)(unaff_EBP + 0xc) = 0x40490fd0;
              *(undefined4 *)(unaff_EBP + -0x24) = 0;
              *(undefined4 *)(unaff_EBP + -0x20) = 0;
              *(undefined4 *)(unaff_EBP + -0x1c) = 0x3f800000;
              iStack_1c8 = 0x5a178c;
              uVar4 = FUN_00462f96();
              iStack_1c8 = unaff_EBP + 0xc;
              *(undefined4 *)(unaff_EBP + -4) = 0x13;
              iStack_1d0 = unaff_EBP + -0x17c;
              uStack_1cc = 2;
              uStack_1d4 = 0x5a17a7;
              uStack_1d8 = FUN_005c38c0();
              iStack_1dc = unaff_EBP + -0x138;
              *(undefined1 *)(unaff_EBP + -4) = 0x14;
              uStack_1e0 = 0x5a17b9;
              uStack_1d4 = uVar4;
              FUN_0049b9e6();
              *(undefined1 *)(unaff_EBP + -4) = 0x17;
              FUN_005c4890();
              *(undefined1 *)(unaff_EBP + -4) = 0x16;
              FUN_005c4890();
              pvVar5 = operator_new(0x48);
              *(void **)(unaff_EBP + 8) = pvVar5;
              *(undefined1 *)(unaff_EBP + -4) = 0x18;
              if (pvVar5 == (void *)0x0) {
                uVar4 = 0;
              }
              else {
                *(undefined1 **)(unaff_EBP + -0x28) = auStack_200;
                FUN_005c36c0(unaff_EBP + -0x138);
                uVar4 = FUN_005a1865(iVar1);
              }
              *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
            }
          }
        }
        FUN_005c4890();
        goto LAB_005a1855;
      }
    }
    pvVar5 = operator_new(0x48);
    *(void **)(unaff_EBP + 8) = pvVar5;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar5 != (void *)0x0) {
      *(undefined1 **)(unaff_EBP + 0xc) = auStack_200;
      FUN_005c36c0(&DAT_006fe6d0);
      uVar4 = FUN_005a1865(iVar1);
      goto LAB_005a1855;
    }
  }
LAB_005a1853:
  uVar4 = 0;
LAB_005a1855:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar4;
}

