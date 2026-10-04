
uint FUN_004770d1(void)

{
  undefined1 *puVar1;
  uint uVar2;
  byte bVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int unaff_EBP;
  uint *puVar8;
  bool bVar9;
  
  FUN_00634c24();
  *(char *)(unaff_EBP + 0xc) = (char)(*(int *)(unaff_EBP + 0xc) >> 4);
  *(char *)(unaff_EBP + 0xd) = (char)(*(int *)(unaff_EBP + 8) >> 4);
  *(undefined1 *)(unaff_EBP + 0xe) = *(undefined1 *)(unaff_EBP + 0x10);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  uVar4 = FUN_00479737(unaff_EBP + -0x4c,unaff_EBP + 0xc);
  bVar9 = (*(byte *)(unaff_EBP + -0x4c) & 0x30) != 0;
  uVar2 = *(uint *)(unaff_EBP + 0x18);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  uVar6 = CONCAT31((int3)((uint)uVar4 >> 8),bVar9);
  if (((uVar2 & 0x40) == 0) || (bVar9)) {
    if (((uVar2 & 0x80) == 0) && (bVar9)) {
LAB_0047713e:
      DAT_006e4a7c = 7;
    }
    else {
      if (uVar2 == 0) {
LAB_004772d1:
        uVar6 = CONCAT22((short)(uVar6 >> 0x10),1);
        goto LAB_004772d5;
      }
      if ((-*(int *)(unaff_EBP + 0x14) & 6U) != 0) {
        FUN_0053bdc6((int)(-*(int *)(unaff_EBP + 0x14) & 7U) >> 1);
      }
      if (((((*(uint *)(unaff_EBP + -0x4c) & 1) == 1) &&
           ((((byte)*(undefined4 *)(unaff_EBP + -0x4c) & 2) == 2 ||
            (((byte)*(undefined4 *)(unaff_EBP + -0x4c) & 8) == 8)))) ||
          ((bVar3 = (byte)*(undefined4 *)(unaff_EBP + -0x4c), (bVar3 & 2) == 2 && ((bVar3 & 4) == 4)
           ))) || (((bVar3 & 8) == 8 && ((bVar3 & 4) == 4)))) {
        uVar6 = 1;
      }
      else {
        uVar6 = 0;
      }
      if (((uVar2 & 0x20) == 0) || ((char)uVar6 != '\0')) {
        if (((uVar2 & 0x10) == 0) || ((char)uVar6 == '\0')) {
          *(undefined4 *)(unaff_EBP + -0x20) = 2;
          *(byte *)(unaff_EBP + 0x18) = (byte)uVar2 & 1;
          *(undefined4 *)(unaff_EBP + -0x1c) = 1;
          *(byte *)(unaff_EBP + 0x19) = (byte)(uVar2 >> 3) & 1;
          *(undefined4 *)(unaff_EBP + -0x18) = 4;
          *(byte *)(unaff_EBP + 0x1a) = (byte)(uVar2 >> 1) & 1;
          *(undefined4 *)(unaff_EBP + -0x14) = 8;
          *(byte *)(unaff_EBP + 0x1b) = (byte)(uVar2 >> 2) & 1;
          puVar8 = (uint *)(unaff_EBP + -0x20);
          *(byte *)(unaff_EBP + 0x10) = (byte)(uVar2 >> 8) & 1;
          *(byte *)(unaff_EBP + 0x11) = (byte)(uVar2 >> 0xb) & 1;
          *(byte *)(unaff_EBP + 0x13) = (byte)(uVar2 >> 10) & 1;
          *(byte *)(unaff_EBP + 0x12) = (byte)(uVar2 >> 9) & 1;
          iVar7 = 0;
          do {
            uVar2 = *puVar8;
            puVar1 = (undefined1 *)(unaff_EBP + -0x10 + iVar7);
            bVar9 = (uVar2 & *(uint *)(unaff_EBP + -0x4c)) == uVar2;
            *puVar1 = 0;
            *(bool *)(unaff_EBP + 0x14 + iVar7) = bVar9;
            if (bVar9) {
              iVar5 = FUN_00467ece(uVar2);
              if ((((iVar5 == 2) || (iVar5 == 0xc)) || (iVar5 == 0xd)) || (iVar5 == 0xe)) {
                bVar9 = true;
              }
              else {
                bVar9 = false;
              }
              *puVar1 = !bVar9;
            }
            iVar7 = iVar7 + 1;
            puVar8 = puVar8 + 1;
          } while (iVar7 < 4);
          uVar6 = 0;
          do {
            if ((*(char *)(unaff_EBP + 0x10 + uVar6) != '\0') &&
               (*(char *)(unaff_EBP + 0x14 + uVar6) != '\0')) goto LAB_0047713e;
            if ((*(char *)(unaff_EBP + 0x18 + uVar6) != '\0') &&
               (*(char *)(unaff_EBP + -0x10 + uVar6) == '\0')) {
              uVar6 = (-(uint)(*(char *)(unaff_EBP + 0x14 + uVar6) != '\0') & 0x10) + 6;
              DAT_006e4a7c = uVar6;
              goto LAB_004772f6;
            }
            uVar6 = uVar6 + 1;
          } while ((int)uVar6 < 4);
          goto LAB_004772d1;
        }
        DAT_006e4a7c = 5;
      }
      else {
        DAT_006e4a7c = 4;
      }
    }
  }
  else {
    DAT_006e4a7c = 0x17;
  }
LAB_004772f6:
  uVar6 = uVar6 & 0xffff0000;
LAB_004772d5:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar6;
}

