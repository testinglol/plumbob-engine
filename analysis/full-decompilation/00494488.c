
void FUN_00494488(void)

{
  char cVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int extraout_ECX;
  int unaff_EBP;
  undefined4 *puVar6;
  undefined4 *puVar7;
  bool bVar8;
  undefined4 auStack_b8 [7];
  undefined4 uStack_9c;
  int iStack_98;
  int iStack_94;
  int iStack_90;
  
  FUN_00634c24();
  cVar1 = *(char *)(extraout_ECX + 0xe02e);
  *(undefined4 *)(unaff_EBP + -0x28) = 0;
  *(int *)(unaff_EBP + -0x2c) = (int)cVar1;
  iVar4 = *(int *)(DAT_006e54d8 + 0x10);
  *(int *)(unaff_EBP + -0x34) = iVar4;
  if (0 < iVar4) {
    do {
      *(undefined4 *)(unaff_EBP + -0x24) = 0;
      do {
        *(undefined1 *)(unaff_EBP + -0x18) = *(undefined1 *)(unaff_EBP + -0x28);
        *(undefined1 *)(unaff_EBP + -0x17) = *(undefined1 *)(unaff_EBP + -0x24);
        *(undefined1 *)(unaff_EBP + -0x16) = *(undefined1 *)(unaff_EBP + -0x2c);
        iStack_90 = unaff_EBP + -0x18;
        iStack_94 = unaff_EBP + -0x60;
        *(undefined4 *)(unaff_EBP + -4) = 0;
        iStack_98 = 0x4944ea;
        FUN_00479737();
        *(undefined1 *)(unaff_EBP + -0xd) = 0;
        *(undefined1 *)(unaff_EBP + -4) = 1;
        if (*(int *)(unaff_EBP + -0x60) == 0) {
          *(undefined4 *)(unaff_EBP + -0x1c) = 0;
        }
        else {
          uVar3 = 1;
          if (((byte)*(undefined4 *)(unaff_EBP + -0x60) & 1) != 1) {
            do {
              uVar3 = uVar3 * 2;
            } while ((uVar3 & *(uint *)(unaff_EBP + -0x60)) != uVar3);
          }
          *(uint *)(unaff_EBP + -0x1c) = uVar3;
        }
        if (*(int *)(unaff_EBP + -0x1c) != 0) {
          do {
            iStack_90 = 0;
            iStack_94 = *(undefined4 *)(unaff_EBP + -0x1c);
            iStack_98 = 0x494529;
            iVar4 = FUN_00435221();
            sVar2 = *(short *)(unaff_EBP + -0x58 + iVar4 * 2);
            if ((((sVar2 == 2) || (sVar2 == 0xc)) || (sVar2 == 0xd)) || (sVar2 == 0xe)) {
              *(undefined1 *)(unaff_EBP + -0xe) = 1;
              if (sVar2 == 2) {
LAB_0049457a:
                *(undefined4 *)(unaff_EBP + -0x14) = 0xf8;
              }
              else if (sVar2 == 0xc) {
                *(undefined4 *)(unaff_EBP + -0x14) = 0xf9;
              }
              else if (sVar2 == 0xd) {
                *(undefined4 *)(unaff_EBP + -0x14) = 0xfa;
              }
              else {
                if (sVar2 != 0xe) goto LAB_0049457a;
                *(undefined4 *)(unaff_EBP + -0x14) = 0xfb;
              }
            }
            else {
              *(undefined1 *)(unaff_EBP + -0xe) = 0;
            }
            if (*(int *)(unaff_EBP + -0x1c) == 0x10) {
              iStack_90 = 2;
              iStack_94 = 0x10;
              iStack_98 = 0x494594;
              iVar4 = FUN_00435221();
              if (*(short *)(unaff_EBP + -0x4c + iVar4 * 2) == 0xff) {
                iStack_90 = 2;
                iStack_94 = 0x10;
                iStack_98 = 0;
                uStack_9c = 0x4945b0;
                FUN_00493b0f();
                iStack_90 = 0x10;
                iStack_94 = 1;
                iStack_98 = 0x4945bb;
                FUN_004633e3();
                *(undefined1 *)(unaff_EBP + -0xd) = 1;
              }
              if (*(char *)(unaff_EBP + -0xe) != '\0') {
                iStack_90 = 2;
                iStack_94 = 0x10;
                iStack_98 = 0x4945cc;
                iVar4 = FUN_00435221();
                if ((uint)*(ushort *)(unaff_EBP + -0x4c + iVar4 * 2) != *(uint *)(unaff_EBP + -0x14)
                   ) {
                  iStack_90 = 2;
                  iStack_94 = 0x10;
                  iStack_98 = *(undefined4 *)(unaff_EBP + -0x14);
                  uStack_9c = 0x4945e5;
                  FUN_00493b0f();
                  *(undefined1 *)(unaff_EBP + -0xd) = 1;
                }
              }
              iStack_90 = 4;
              iStack_94 = 0x10;
              iStack_98 = 0x4945f3;
              iVar4 = FUN_00435221();
              if (*(short *)(unaff_EBP + -0x4c + iVar4 * 2) == 0xff) {
                iStack_90 = 4;
                iStack_94 = 0x10;
                iStack_98 = 0;
                uStack_9c = 0x49460a;
                FUN_00493b0f();
                iStack_90 = 0x10;
                iStack_94 = 1;
                iStack_98 = 0x494615;
                FUN_004633e3();
                *(undefined1 *)(unaff_EBP + -0xd) = 1;
              }
              if (*(char *)(unaff_EBP + -0xe) != '\0') {
                iStack_90 = 4;
                iStack_94 = 0x10;
                iStack_98 = 0x49462a;
                iVar4 = FUN_00435221();
                if ((uint)*(ushort *)(unaff_EBP + -0x4c + iVar4 * 2) != *(uint *)(unaff_EBP + -0x14)
                   ) {
                  iStack_90 = 4;
                  iStack_94 = 0x10;
                  iStack_98 = *(int *)(unaff_EBP + -0x14);
                  uStack_9c = 0x494647;
                  FUN_00493b0f();
                  *(undefined1 *)(unaff_EBP + -0xd) = 1;
                }
              }
LAB_00494865:
              iStack_90 = 0x20;
            }
            else {
              iVar4 = *(int *)(unaff_EBP + -0x1c);
              if (iVar4 != 0x20) {
                iStack_90 = 0;
                iStack_98 = 0x49472b;
                iStack_94 = iVar4;
                iVar5 = FUN_00435221();
                uVar3 = (uint)*(ushort *)(unaff_EBP + -0x4c + iVar5 * 2);
                *(uint *)(unaff_EBP + -0x30) = uVar3;
                if (uVar3 == 0xff) {
                  iStack_94 = 1;
                  iStack_98 = 0x494747;
                  iStack_90 = iVar4;
                  FUN_004633e3();
                  iStack_90 = 0;
                  iStack_98 = 0;
                  uStack_9c = 0x494754;
                  iStack_94 = iVar4;
                  FUN_00493b0f();
                  *(undefined1 *)(unaff_EBP + -0xd) = 1;
                }
                *(undefined1 *)(unaff_EBP + -0x20) = *(undefined1 *)(unaff_EBP + -0x18);
                *(undefined1 *)(unaff_EBP + -0x1f) = *(undefined1 *)(unaff_EBP + -0x17);
                *(undefined1 *)(unaff_EBP + -0x1e) = *(undefined1 *)(unaff_EBP + -0x16);
                iStack_90 = unaff_EBP + -0x20;
                *(undefined1 *)(unaff_EBP + -4) = 2;
                iStack_98 = 0x494778;
                iStack_94 = iVar4;
                FUN_0053c0e0();
                uStack_9c = 0x49477e;
                iStack_98 = iVar4;
                iVar4 = FUN_0053c135();
                iStack_90 = unaff_EBP + -0x20;
                iStack_94 = unaff_EBP + -0x8c;
                iStack_98 = 0x494799;
                FUN_00479737();
                iStack_90 = 0;
                *(undefined1 *)(unaff_EBP + -4) = 3;
                if (iVar4 == 0x10) {
                  iStack_90 = 4;
                }
                else if (iVar4 == 0x20) {
                  iStack_90 = 1;
                }
                iStack_98 = 0x4947b5;
                iStack_94 = iVar4;
                iVar5 = FUN_00435221();
                uVar3 = (uint)*(ushort *)(unaff_EBP + -0x78 + iVar5 * 2);
                bVar8 = uVar3 == 0xff;
                if (bVar8) {
                  iStack_94 = 1;
                  iStack_98 = 0x4947d4;
                  iStack_90 = iVar4;
                  FUN_004633e3();
                  iStack_90 = 0;
                  iStack_98 = 0;
                  uStack_9c = 0x4947e4;
                  iStack_94 = iVar4;
                  FUN_00493b0f();
                }
                if (*(char *)(unaff_EBP + -0xe) != '\0') {
                  if (*(int *)(unaff_EBP + -0x30) != *(int *)(unaff_EBP + -0x14)) {
                    iStack_90 = 0;
                    iStack_94 = *(int *)(unaff_EBP + -0x1c);
                    uStack_9c = 0x494802;
                    iStack_98 = *(int *)(unaff_EBP + -0x14);
                    FUN_00493b0f();
                    *(undefined1 *)(unaff_EBP + -0xd) = 1;
                  }
                  if (uVar3 != *(uint *)(unaff_EBP + -0x14)) {
                    iStack_90 = 0;
                    iStack_98 = *(int *)(unaff_EBP + -0x14);
                    uStack_9c = 0x49481c;
                    iStack_94 = iVar4;
                    FUN_00493b0f();
                    bVar8 = true;
                  }
                }
                if (bVar8) {
                  *(undefined4 **)(unaff_EBP + -0x30) = auStack_b8;
                  puVar6 = (undefined4 *)(unaff_EBP + -0x8c);
                  puVar7 = auStack_b8;
                  for (iVar4 = 0xb; iVar4 != 0; iVar4 = iVar4 + -1) {
                    *puVar7 = *puVar6;
                    puVar6 = puVar6 + 1;
                    puVar7 = puVar7 + 1;
                  }
                  FUN_00479954(unaff_EBP + -0x20);
                  iStack_90 = *(undefined4 *)(DAT_006e54d8 + 0x84);
                  iStack_94 = 0x494857;
                  FUN_00434ffd();
                  iStack_90 = unaff_EBP + -0x20;
                  iStack_94 = 0x494860;
                  FUN_00492be0();
                }
                *(undefined1 *)(unaff_EBP + -4) = 1;
                goto LAB_00494865;
              }
              iStack_90 = 3;
              iStack_94 = 0x20;
              iStack_98 = 0x494668;
              iVar4 = FUN_00435221();
              if (*(short *)(unaff_EBP + -0x4c + iVar4 * 2) == 0xff) {
                iStack_90 = 3;
                iStack_94 = 0x20;
                iStack_98 = 0;
                uStack_9c = 0x494684;
                FUN_00493b0f();
                iStack_90 = 0x20;
                iStack_94 = 1;
                iStack_98 = 0x49468f;
                FUN_004633e3();
                *(undefined1 *)(unaff_EBP + -0xd) = 1;
              }
              if (*(char *)(unaff_EBP + -0xe) != '\0') {
                iStack_90 = 3;
                iStack_94 = 0x20;
                iStack_98 = 0x4946a0;
                iVar4 = FUN_00435221();
                if ((uint)*(ushort *)(unaff_EBP + -0x4c + iVar4 * 2) != *(uint *)(unaff_EBP + -0x14)
                   ) {
                  iStack_90 = 3;
                  iStack_94 = 0x20;
                  iStack_98 = *(undefined4 *)(unaff_EBP + -0x14);
                  uStack_9c = 0x4946b9;
                  FUN_00493b0f();
                  *(undefined1 *)(unaff_EBP + -0xd) = 1;
                }
              }
              iStack_90 = 1;
              iStack_94 = 0x20;
              iStack_98 = 0x4946c7;
              iVar4 = FUN_00435221();
              if (*(short *)(unaff_EBP + -0x4c + iVar4 * 2) == 0xff) {
                iStack_90 = 1;
                iStack_94 = 0x20;
                iStack_98 = 0;
                uStack_9c = 0x4946de;
                FUN_00493b0f();
                iStack_90 = 0x20;
                iStack_94 = 1;
                iStack_98 = 0x4946e8;
                FUN_004633e3();
                *(undefined1 *)(unaff_EBP + -0xd) = 1;
              }
              if (*(char *)(unaff_EBP + -0xe) != '\0') {
                iStack_90 = 1;
                iStack_94 = 0x20;
                iStack_98 = 0x4946fd;
                iVar4 = FUN_00435221();
                if ((uint)*(ushort *)(unaff_EBP + -0x4c + iVar4 * 2) != *(uint *)(unaff_EBP + -0x14)
                   ) {
                  iStack_90 = 1;
                  iStack_94 = 0x20;
                  iStack_98 = *(int *)(unaff_EBP + -0x14);
                  uStack_9c = 0x49471a;
                  FUN_00493b0f();
                  *(undefined1 *)(unaff_EBP + -0xd) = 1;
                }
              }
            }
            uVar3 = *(uint *)(unaff_EBP + -0x1c);
            do {
              uVar3 = uVar3 * 2;
              if ((uVar3 & *(uint *)(unaff_EBP + -0x60)) == uVar3) break;
            } while ((int)uVar3 < 0x20);
          } while (((int)uVar3 < 0x20) && (*(uint *)(unaff_EBP + -0x1c) = uVar3, uVar3 != 0));
          if (*(char *)(unaff_EBP + -0xd) != '\0') {
            *(undefined4 **)(unaff_EBP + -0x30) = auStack_b8;
            puVar6 = (undefined4 *)(unaff_EBP + -0x60);
            puVar7 = auStack_b8;
            for (iVar4 = 0xb; iVar4 != 0; iVar4 = iVar4 + -1) {
              *puVar7 = *puVar6;
              puVar6 = puVar6 + 1;
              puVar7 = puVar7 + 1;
            }
            FUN_00479954(unaff_EBP + -0x18);
            iStack_90 = *(undefined4 *)(DAT_006e54d8 + 0x84);
            iStack_94 = 0x4948c1;
            FUN_00434ffd();
            iStack_90 = unaff_EBP + -0x18;
            iStack_94 = 0x4948ca;
            FUN_00492be0();
          }
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        *(int *)(unaff_EBP + -0x24) = *(int *)(unaff_EBP + -0x24) + 1;
      } while (*(int *)(unaff_EBP + -0x24) < *(int *)(unaff_EBP + -0x34));
      *(int *)(unaff_EBP + -0x28) = *(int *)(unaff_EBP + -0x28) + 1;
    } while (*(int *)(unaff_EBP + -0x28) < *(int *)(unaff_EBP + -0x34));
  }
  iStack_90 = 0x4948f7;
  FUN_00540afa();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

