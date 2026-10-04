
int FUN_0047b178(void)

{
  char cVar1;
  byte bVar2;
  char *pcVar3;
  char cVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  byte *pbVar8;
  int extraout_ECX;
  int unaff_EBP;
  uint uVar9;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x20) = DAT_006f0ba8;
  pcVar3 = *(char **)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -0x14) = DAT_006efc64;
  uVar7 = DAT_006c5fe8;
  *pcVar3 = '\0';
  *(undefined4 *)(unaff_EBP + -0x24) = uVar7;
  uVar7 = *(undefined4 *)(extraout_ECX + 0x10);
  *(undefined1 *)(unaff_EBP + 8) = 0;
  *(undefined1 *)(unaff_EBP + 9) = 0;
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  *(undefined4 *)(unaff_EBP + -0x1c) = uVar7;
  *(undefined1 *)(unaff_EBP + 10) = 1;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  do {
    if ((*(byte *)(*(int *)(*(int *)(*(int *)(extraout_ECX + 0x30 + *(char *)(unaff_EBP + 10) * 4) +
                                    0xc) + *(char *)(unaff_EBP + 8) * 4) +
                  (int)*(char *)(unaff_EBP + 9)) & 0x20) == 0) {
      FUN_00479737(unaff_EBP + -0x50,unaff_EBP + 8);
      cVar4 = *pcVar3;
      uVar6 = *(uint *)(unaff_EBP + -0x50);
      *(undefined1 *)(unaff_EBP + -4) = 1;
      if ((cVar4 == '\0') && (uVar6 == 0)) {
        cVar4 = '\0';
      }
      else {
        cVar4 = '\x01';
      }
      *pcVar3 = cVar4;
      if (uVar6 == 0) {
        uVar9 = 0;
      }
      else {
        uVar9 = 1;
        if (((byte)uVar6 & 1) != 1) {
          do {
            uVar9 = uVar9 * 2;
          } while ((uVar9 & uVar6) != uVar9);
        }
      }
      do {
        if (uVar9 == 0) break;
        iVar5 = FUN_00435221(uVar9,0);
        uVar6 = (uint)*(ushort *)(unaff_EBP + -0x48 + iVar5 * 2);
        *(int *)(unaff_EBP + -0x18) =
             *(int *)(unaff_EBP + -0x18) + *(int *)(&DAT_006e57e8 + uVar6 * 4);
        if ((((uVar6 == 1) || (uVar6 == 7)) || (uVar6 == 8)) || (uVar6 == 9)) {
          uVar7 = 0;
          if (uVar9 == 0x10) {
            uVar7 = 4;
          }
          else if (uVar9 == 0x20) {
            uVar7 = 1;
          }
          iVar5 = FUN_00435221(uVar9,uVar7);
          iVar5 = FUN_004c6571(*(undefined2 *)(unaff_EBP + -0x3c + iVar5 * 2));
          *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + iVar5;
        }
        do {
          uVar9 = uVar9 * 2;
          if ((uVar9 & *(uint *)(unaff_EBP + -0x50)) == uVar9) break;
        } while ((int)uVar9 < 0x20);
      } while ((int)uVar9 < 0x20);
      uVar6 = FUN_00433166(unaff_EBP + 8);
      if (uVar6 != 0) {
        if (uVar6 == 0xff) {
          if ((((byte)*(undefined4 *)(unaff_EBP + -0x50) & 0x10) == 0x10) ||
             (((byte)*(undefined4 *)(unaff_EBP + -0x50) & 0x20) == 0x20)) {
            if (*(short *)(unaff_EBP + -0x48) != 0) {
              iVar5 = FUN_004a15df(*(short *)(unaff_EBP + -0x48));
              *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + iVar5 / 2;
            }
            uVar6 = (uint)*(ushort *)(unaff_EBP + -0x3c);
            if (uVar6 != 0) {
              iVar5 = FUN_004a15df(uVar6);
              iVar5 = iVar5 / 2;
              goto LAB_0047b302;
            }
          }
        }
        else {
          iVar5 = FUN_004a15df(uVar6);
LAB_0047b302:
          *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + iVar5;
        }
      }
      if ((*pcVar3 == '\0') && (uVar6 == 0)) {
        cVar4 = '\0';
      }
      else {
        cVar4 = '\x01';
      }
      cVar1 = *(char *)(unaff_EBP + 10);
      *pcVar3 = cVar4;
      if (cVar1 == '\x01') {
        pbVar8 = (byte *)(*(int *)(*(int *)(*(int *)(extraout_ECX + 0x60) + 0x10) +
                                  *(char *)(unaff_EBP + 8) * 4) + (int)*(char *)(unaff_EBP + 9));
        bVar2 = *pbVar8;
        if (bVar2 < 0x10) {
          iVar5 = *(int *)(unaff_EBP + -0x24);
          *pcVar3 = '\x01';
          *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + iVar5;
          bVar2 = *pbVar8;
        }
        if (bVar2 == 0x10) {
          *pcVar3 = '\x01';
        }
      }
      *(undefined1 *)(unaff_EBP + -4) = 0;
    }
    *(char *)(unaff_EBP + 8) = *(char *)(unaff_EBP + 8) + '\x01';
    if (*(int *)(unaff_EBP + -0x1c) <= (int)*(char *)(unaff_EBP + 8)) {
      *(undefined1 *)(unaff_EBP + 8) = 0;
      *(char *)(unaff_EBP + 9) = *(char *)(unaff_EBP + 9) + '\x01';
      if (*(int *)(unaff_EBP + -0x1c) <= (int)*(char *)(unaff_EBP + 9)) {
        *(undefined1 *)(unaff_EBP + 9) = 0;
        if (*(char *)(unaff_EBP + 10) == '\x02') {
          ExceptionList = *(void **)(unaff_EBP + -0xc);
          return *(int *)(unaff_EBP + -0x18) / 2 + *(int *)(unaff_EBP + -0x10);
        }
        *(char *)(unaff_EBP + 10) = *(char *)(unaff_EBP + 10) + '\x01';
      }
    }
  } while( true );
}

