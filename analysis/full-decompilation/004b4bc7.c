
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_004b4bc7(void)

{
  ushort uVar1;
  float fVar2;
  char cVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  uint uVar8;
  char cVar9;
  int extraout_ECX;
  char cVar10;
  int unaff_EBP;
  int iVar11;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x24) = *(undefined4 *)(extraout_ECX + 0x20);
  uVar4 = FUN_004a69aa();
  *(undefined4 *)(unaff_EBP + -0x14) = uVar4;
  iVar5 = FUN_00415707();
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  iVar11 = *(int *)(extraout_ECX + 0x28);
  iVar5 = iVar5 + 0x130;
  iVar7 = *(int *)(extraout_ECX + 0x24);
  *(int *)(unaff_EBP + -0x20) = iVar5;
  if (iVar11 - iVar7 >> 2 != 0) {
    *(undefined4 *)(unaff_EBP + -0x18) = 0;
    do {
      iVar11 = *(int *)(unaff_EBP + -0x10) * 4;
      if (*(int *)(iVar11 + *(int *)(extraout_ECX + 0x24)) != 0) {
        iVar7 = *(int *)(iVar11 + *(int *)(extraout_ECX + 0x24));
        *(undefined4 *)(unaff_EBP + -0x3c) = *(undefined4 *)(iVar7 + 0x84);
        *(undefined4 *)(unaff_EBP + -0x38) = *(undefined4 *)(iVar7 + 0x88);
        *(undefined4 *)(unaff_EBP + -0x34) = *(undefined4 *)(iVar7 + 0x8c);
        puVar6 = (undefined4 *)FUN_005c3840(unaff_EBP + -0x60,unaff_EBP + -0x3c,iVar5);
        *(undefined4 *)(unaff_EBP + -0x3c) = *puVar6;
        *(undefined4 *)(unaff_EBP + -0x38) = puVar6[1];
        *(undefined4 *)(unaff_EBP + -0x34) = puVar6[2];
        FUN_0049b802();
        iVar7 = unaff_EBP + -0x3c;
        uVar4 = FUN_0045ef64(unaff_EBP + -0x6c,
                             *(int *)(unaff_EBP + -0x18) + *(int *)(extraout_ECX + 0x30),
                             extraout_ECX + 4,iVar7);
        iVar7 = FUN_005d0a0d(uVar4,iVar7);
        if (iVar7 != 0) goto LAB_004b4ee6;
        iVar7 = FUN_005d0b17(unaff_EBP + -0x24);
        if (iVar7 != 0) goto LAB_004b4ee6;
        FUN_005ceca4(*(undefined4 *)(iVar11 + *(int *)(extraout_ECX + 0x24)));
        iVar5 = *(int *)(unaff_EBP + -0x20);
      }
      iVar11 = *(int *)(extraout_ECX + 0x28);
      *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
      iVar7 = *(int *)(extraout_ECX + 0x24);
      *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 0xc;
    } while (*(uint *)(unaff_EBP + -0x10) < (uint)(iVar11 - iVar7 >> 2));
  }
  uVar4 = FUN_00433116((int *)(extraout_ECX + 0x10),1);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  cVar3 = FUN_00433136(uVar4);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (cVar3 == '\0') {
    iVar11 = *(int *)(extraout_ECX + 0x10);
    uVar4 = *(undefined4 *)(extraout_ECX + 0x18);
    cVar3 = (char)(*(int *)(extraout_ECX + 0x14) >> 4);
    *(char *)(unaff_EBP + -0x1c) = cVar3;
    cVar9 = (char)(iVar11 >> 4);
    *(char *)(unaff_EBP + -0x1b) = cVar9;
    cVar10 = (char)uVar4;
    *(char *)(unaff_EBP + -0x1a) = cVar10;
    iVar11 = DAT_006e54dc;
    *(undefined4 *)(unaff_EBP + -4) = 1;
    iVar11 = *(int *)(*(int *)(*(int *)(iVar11 + 0x28 + cVar10 * 4) + 0xc) + cVar3 * 4);
    uVar1 = *(ushort *)(iVar11 + cVar9 * 2);
    if (uVar1 < 0xfffb) {
      iVar11 = FUN_004670a4(CONCAT22((short)((uint)iVar11 >> 0x10),uVar1));
      if (iVar11 != 0) {
        iVar7 = *(int *)(iVar11 + 0x14);
        iVar5 = *(int *)(iVar11 + 0x10);
        *(undefined4 *)(unaff_EBP + -0x10) = 0;
        if ((iVar7 - iVar5 & 0xfffffffcU) != 0) {
          *(undefined4 *)(unaff_EBP + -0x18) = 0;
          do {
            iVar7 = *(int *)(iVar5 + *(int *)(unaff_EBP + -0x10) * 4);
            if (iVar7 != 0) {
              puVar6 = (undefined4 *)(*(int *)(iVar11 + 0x1c) + *(int *)(unaff_EBP + -0x18));
              *(undefined4 *)(unaff_EBP + -0x54) = *puVar6;
              *(undefined4 *)(unaff_EBP + -0x50) = puVar6[1];
              *(undefined4 *)(unaff_EBP + -0x4c) = puVar6[2];
              FUN_0049b849(unaff_EBP + -0x48,extraout_ECX + 4,unaff_EBP + -0x54);
              fVar2 = *(float *)(unaff_EBP + -0x48) * *(float *)(unaff_EBP + -0x48) +
                      *(float *)(unaff_EBP + -0x40) * *(float *)(unaff_EBP + -0x40) +
                      *(float *)(unaff_EBP + -0x44) * *(float *)(unaff_EBP + -0x44);
              if (_DAT_006687b8 < fVar2) {
                uVar4 = 0xffffffff;
              }
              else {
                if (_DAT_006687b4 <= fVar2) {
                  *(float *)(unaff_EBP + -0x20) =
                       _DAT_00666748 / ((fVar2 - _DAT_006687b4) * _DAT_00666578 + _DAT_00666748);
                }
                else {
                  *(undefined4 *)(unaff_EBP + -0x20) = 0x3f800000;
                }
                FUN_0049b802();
                FUN_005d0a0d(unaff_EBP + -0x54,unaff_EBP + -0x48);
                FUN_005d0b17(unaff_EBP + -0x20);
                *(undefined4 *)(unaff_EBP + -0x28) = 0x3f51d1d2;
                *(undefined4 *)(unaff_EBP + -0x30) = 0x3f800000;
                *(undefined4 *)(unaff_EBP + -0x2c) = 0x3f7bfbfc;
                FUN_005d0abe(unaff_EBP + -0x30,unaff_EBP + -0x2c,unaff_EBP + -0x28);
                FUN_005ceca4(iVar7);
                uVar4 = 1;
              }
              FUN_005d09fc(uVar4);
            }
            iVar7 = *(int *)(iVar11 + 0x14);
            iVar5 = *(int *)(iVar11 + 0x10);
            *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
            *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 0xc;
          } while (*(int *)(unaff_EBP + -0x10) != iVar7 - iVar5 >> 2);
        }
      }
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  }
  uVar4 = FUN_005cee4b();
  *(undefined4 *)(extraout_ECX + 0x54) = uVar4;
  uVar8 = __ftol();
  FUN_005cee2f(((uVar8 << 8 | uVar8) << 8 | uVar8) << 8 | uVar8);
  iVar7 = 0;
LAB_004b4ee6:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar7;
}

