
void FUN_0056e1dc(void)

{
  ushort uVar1;
  int iVar2;
  char cVar3;
  undefined1 uVar4;
  short sVar5;
  ushort *puVar6;
  undefined4 uVar7;
  int iVar8;
  int *piVar9;
  int extraout_ECX;
  byte *pbVar10;
  int unaff_EBP;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x3c) = extraout_ECX;
  FUN_0056e1c7();
  *(undefined4 *)(unaff_EBP + -0x30) = DAT_006e53d8;
  iVar2 = *(int *)(extraout_ECX + 0xc);
  *(int *)(unaff_EBP + -0x34) = iVar2;
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  if (0 < iVar2) {
    do {
      *(undefined4 *)(unaff_EBP + -0x20) = 0;
      *(int *)(unaff_EBP + -0x24) =
           *(int *)(unaff_EBP + -0x18) - (*(int *)(unaff_EBP + -0x18) >> 0x1f);
      *(int *)(unaff_EBP + -0x24) = *(int *)(unaff_EBP + -0x24) >> 1;
      *(int *)(unaff_EBP + -0x38) = *(char *)(unaff_EBP + 8) * 4 + 0x28;
      do {
        iVar2 = *(int *)(unaff_EBP + -0x20);
        *(char *)(unaff_EBP + -0x14) = (char)(iVar2 / 2);
        *(undefined1 *)(unaff_EBP + -0x13) = *(undefined1 *)(unaff_EBP + -0x24);
        *(undefined1 *)(unaff_EBP + -0x12) = *(undefined1 *)(unaff_EBP + 8);
        *(undefined4 *)(unaff_EBP + -4) = 0;
        puVar6 = (ushort *)FUN_00435bca(unaff_EBP + -0x14);
        uVar1 = *puVar6;
        *(undefined1 *)(unaff_EBP + -0xd) = 0;
        *(undefined1 *)(unaff_EBP + -0xe) = 0;
        *(undefined4 *)(unaff_EBP + -0x1c) = 0;
        *(undefined4 *)(unaff_EBP + -0x2c) = 0;
        if (uVar1 == 0xfffb) {
          FUN_004672d0(unaff_EBP + -0x14,unaff_EBP + -0x1c,unaff_EBP + -0x2c,unaff_EBP + -0x44,
                       unaff_EBP + -0x40);
          if (*(int *)(unaff_EBP + -0x1c) != 0) {
            cVar3 = FUN_004689d6();
            *(char *)(unaff_EBP + -0xd) = cVar3;
            if (cVar3 != '\0') goto LAB_0056e2c8;
          }
          if ((*(int *)(unaff_EBP + -0x2c) != 0) &&
             (*(int *)(unaff_EBP + -0x1c) != *(int *)(unaff_EBP + -0x2c))) {
LAB_0056e2c0:
            uVar4 = FUN_004689d6();
            *(undefined1 *)(unaff_EBP + -0xd) = uVar4;
          }
        }
        else if (uVar1 < 0xfffb) {
          uVar7 = FUN_004670a4(uVar1);
          *(undefined4 *)(unaff_EBP + -0x1c) = uVar7;
          goto LAB_0056e2c0;
        }
LAB_0056e2c8:
        if (*(int *)(unaff_EBP + 8) == 1) {
          *(char *)(unaff_EBP + -0x28) = *(char *)(unaff_EBP + -0x14);
          *(char *)(unaff_EBP + -0x27) = *(char *)(unaff_EBP + -0x13);
          *(undefined1 *)(unaff_EBP + -0x26) = 2;
          iVar8 = DAT_006e54dc;
          *(undefined1 *)(unaff_EBP + -4) = 1;
          if (*(short *)(*(int *)(*(int *)(*(int *)(iVar8 + 0x28) + 0xc) +
                                 *(char *)(unaff_EBP + -0x14) * 4) +
                        *(char *)(unaff_EBP + -0x13) * 2) != 0) {
            *(undefined1 *)(unaff_EBP + -0xd) = 0;
            *(undefined1 *)(unaff_EBP + -0xe) = 1;
          }
          sVar5 = FUN_004325af(unaff_EBP + -0x28);
          if (sVar5 != 0) {
            FUN_0043f371(*DAT_006e486c,unaff_EBP + -0x14,0);
            while (*(int *)(unaff_EBP + -0x54) != 0) {
              iVar8 = FUN_004573f9();
              if (*(short *)(*(int *)(iVar8 + 0x60) + 0x8a) == 3) {
                *(undefined1 *)(unaff_EBP + -0xd) = 0;
                *(undefined1 *)(unaff_EBP + -0xe) = 1;
                break;
              }
              FUN_0043f3b9();
            }
          }
          *(undefined1 *)(unaff_EBP + -4) = 0;
        }
        piVar9 = (int *)FUN_0047c7b7(unaff_EBP + -0x48,*(undefined4 *)(unaff_EBP + -0x18));
        iVar2 = iVar2 * 2;
        pbVar10 = (byte *)(iVar2 + *piVar9);
        if (*(char *)(unaff_EBP + -0xd) == '\0') {
          *pbVar10 = *pbVar10 & 0xfe;
        }
        else {
          *pbVar10 = *pbVar10 | 1;
        }
        piVar9 = (int *)FUN_0047c7b7(unaff_EBP + -0x4c,*(undefined4 *)(unaff_EBP + -0x18));
        pbVar10 = (byte *)(*piVar9 + iVar2);
        if (*(char *)(unaff_EBP + -0xe) == '\0') {
          *pbVar10 = *pbVar10 & 0xf7;
        }
        else {
          *pbVar10 = *pbVar10 | 8;
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        *(int *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + -0x20) + 1;
      } while (*(int *)(unaff_EBP + -0x20) < *(int *)(unaff_EBP + -0x34));
      *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 1;
    } while (*(int *)(unaff_EBP + -0x18) < *(int *)(unaff_EBP + -0x34));
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

