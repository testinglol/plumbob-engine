
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005972be(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  int extraout_ECX;
  int unaff_EBP;
  int iVar6;
  
  FUN_00634c24();
  if ((*(int *)(extraout_ECX + 0x1c) == 0) && (*(int *)(extraout_ECX + 0x58) != 0)) {
    uVar3 = FUN_005c22bb();
    *(undefined4 *)(unaff_EBP + -0x10) = uVar3;
    *(undefined4 *)(unaff_EBP + -0x18) = 0;
    FUN_005c174f(&PTR_DAT_006d1d24);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_005c32ce();
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_0047354f(1);
    puVar1 = (undefined4 *)(extraout_ECX + 0x10);
    iVar4 = FUN_005c1b28(unaff_EBP + -0x40,*(undefined4 *)(extraout_ECX + 0x58),unaff_EBP + -0x14,
                         *(undefined4 *)(extraout_ECX + 0x10),1);
    if (iVar4 == 0) {
      *(undefined4 *)(unaff_EBP + -0x18) = 1;
LAB_005973a6:
      iVar4 = FUN_00401f73();
      *(int *)(unaff_EBP + -0x10) = iVar4;
      if (iVar4 != 0) {
        if (*(int *)(extraout_ECX + 0x60) != 0) {
          FUN_006321f0(*(int *)(extraout_ECX + 0x60));
          *(undefined4 *)(extraout_ECX + 0x60) = 0;
        }
        iVar4 = *(int *)(extraout_ECX + 0x5c);
        *(undefined4 *)(unaff_EBP + -0x1c) = 0;
        if (iVar4 != 0) {
          uVar3 = FUN_0041e684(iVar4 * 0xc);
          iVar4 = *(int *)(unaff_EBP + -0x18);
          *(undefined4 *)(extraout_ECX + 0x60) = uVar3;
          if (iVar4 == 0) {
            iVar6 = *(int *)(extraout_ECX + 0x5c) * 0xc;
            iVar4 = FUN_005b8e6a(uVar3,iVar6);
            if (iVar4 != iVar6) goto LAB_005974d2;
          }
          else {
            FUN_005974ee(*(undefined4 *)(unaff_EBP + -0x10),uVar3,
                         *(undefined4 *)(extraout_ECX + 0x5c),3,unaff_EBP + -0x1c);
          }
        }
        if (*(int *)(extraout_ECX + 0x68) != 0) {
          FUN_0041d9a9(*(int *)(extraout_ECX + 0x68));
          *(undefined4 *)(extraout_ECX + 0x68) = 0;
        }
        if (*(int *)(extraout_ECX + 100) != 0) {
          uVar3 = FUN_0041e684(*(int *)(extraout_ECX + 100) << 4);
          iVar4 = *(int *)(unaff_EBP + -0x18);
          *(undefined4 *)(extraout_ECX + 0x68) = uVar3;
          if (iVar4 == 0) {
            iVar6 = *(int *)(extraout_ECX + 100) << 4;
            iVar4 = FUN_005b8e6a(uVar3,iVar6);
            if (iVar4 != iVar6) goto LAB_005974d2;
          }
          else {
            FUN_005974ee(*(undefined4 *)(unaff_EBP + -0x10),uVar3,
                         *(undefined4 *)(extraout_ECX + 100),4,unaff_EBP + -0x1c);
          }
        }
        _DAT_006f7628 = _DAT_006f7628 + 1;
        if (*(int *)(unaff_EBP + -0x18) != 0) {
          _DAT_006f760c = _DAT_006f760c + *(int *)(unaff_EBP + -0x1c);
          _DAT_006f7604 =
               _DAT_006f7604 +
               *(int *)(extraout_ECX + 100) * 0x10 + *(int *)(extraout_ECX + 0x5c) * 0xc;
        }
        *(undefined1 *)(unaff_EBP + -4) = 0;
        *(undefined4 *)(extraout_ECX + 0x1c) = 1;
        FUN_005c3314();
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_0042004f();
        goto LAB_005974ac;
      }
    }
    else {
      uVar3 = *puVar1;
      uVar5 = FUN_005c174f(&PTR_DAT_006d1d20);
      uVar2 = *(undefined4 *)(extraout_ECX + 0x58);
      *(undefined1 *)(unaff_EBP + -4) = 2;
      iVar4 = FUN_005c1b28(unaff_EBP + -0x40,uVar2,uVar5,uVar3,1);
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_0042004f();
      if (iVar4 == 0) goto LAB_005973a6;
      FUN_004f7325(*(undefined4 *)(extraout_ECX + 4),*puVar1);
      FUN_00635858(unaff_EBP + -0x140,s_Could_not_load_binary___s_006d1d04,*puVar1,
                   *(undefined4 *)(extraout_ECX + 0x14),*(undefined4 *)(extraout_ECX + 0x18));
    }
LAB_005974d2:
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_005c3314();
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_0042004f();
    uVar3 = 0;
  }
  else {
LAB_005974ac:
    uVar3 = 1;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

