
undefined4 FUN_004d9f8d(void)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int unaff_EBP;
  uint uVar6;
  int iStack_158;
  int iStack_154;
  undefined *puStack_150;
  
  FUN_00634c24();
  puStack_150 = (undefined *)0x1;
  iStack_154 = 0x4d9fad;
  FUN_0063344c();
  puStack_150 = (undefined *)DAT_00689070;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iStack_154 = 1;
  iStack_158 = *(int *)(unaff_EBP + 8);
  FUN_00633510();
  if (*(int *)(unaff_EBP + -0x94 + *(int *)(*(int *)(unaff_EBP + -0x9c) + 4)) == 0) {
    puStack_150 = (undefined *)0x1;
    iStack_154 = 0x4d9feb;
    FUN_0063365a();
    puStack_150 = *(undefined **)(unaff_EBP + 0x10);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    iStack_154 = 0x4d9ff7;
    FUN_004d6581();
    puStack_150 = (undefined *)DAT_00689070;
    iStack_154 = 0x12;
    iStack_158 = *(int *)(unaff_EBP + 0x10);
    FUN_0063371e();
    puStack_150 = (undefined *)0x4da016;
    FUN_005b8680();
    puStack_150 = (undefined *)(unaff_EBP + -0x10);
    *(undefined1 *)(unaff_EBP + -4) = 2;
    iStack_154 = 0x4da029;
    FUN_00633175();
    iVar4 = 0;
    while ((*(byte *)(unaff_EBP + -0x94 + *(int *)(*(int *)(unaff_EBP + -0x9c) + 4)) & 1) == 0) {
      if (*(char *)(unaff_EBP + -0x10) == '^') {
        puStack_150 = (undefined *)(unaff_EBP + -0x10);
        iVar5 = iVar4 + 1;
        iStack_154 = 0x4da058;
        FUN_00633175();
        if (*(char *)(unaff_EBP + -0x10) == '^') {
          puStack_150 = (undefined *)(unaff_EBP + -0x10);
          iVar5 = iVar4 + 2;
          iStack_154 = 0x4da06e;
          FUN_00633175();
          if (*(char *)(unaff_EBP + -0x10) == '^') {
            puStack_150 = (undefined *)(unaff_EBP + -0x10);
            iVar5 = iVar4 + 3;
            iStack_154 = 0x4da084;
            FUN_00633175();
            if (*(char *)(unaff_EBP + -0x10) == '^') {
              iVar5 = iVar4 + 4;
            }
          }
        }
      }
      else {
        iVar5 = 0;
      }
      if (iVar5 == 4) {
        puStack_150 = &DAT_006c83a0;
        iStack_154 = 0x4da0a8;
        puStack_150 = (undefined *)FUN_005b870f();
        *(undefined1 *)(unaff_EBP + -4) = 3;
        iStack_154 = 0x4da0b5;
        FUN_005d499c();
        *(undefined1 *)(unaff_EBP + -4) = 2;
        puStack_150 = (undefined *)0x4da0c4;
        FUN_005b8770();
        puStack_150 = (undefined *)(unaff_EBP + -0x10);
        iStack_154 = 0x4da0d3;
        FUN_00633175();
        iVar5 = 4;
        if ((*(byte *)(unaff_EBP + -0x94 + *(int *)(*(int *)(unaff_EBP + -0x9c) + 4)) & 1) == 0) {
          uVar2 = *(undefined4 *)(unaff_EBP + -0x10);
          do {
            if ((iVar5 == 0) ||
               (((((cVar1 = (char)uVar2, cVar1 < '0' || ('9' < cVar1)) &&
                  ((cVar1 < 'a' || ('z' < cVar1)))) && ((cVar1 != '_' && (cVar1 != '^')))) &&
                ((cVar1 < 'A' || ('Z' < cVar1)))))) break;
            if ((cVar1 == 'X') && (*(int *)(unaff_EBP + 0x124) != -1)) {
              puStack_150 = *(undefined **)(unaff_EBP + 0x124);
              iStack_154 = unaff_EBP + -0xc4;
              iStack_158 = 0x4da13c;
              iStack_158 = FUN_004d6554();
              *(undefined1 *)(unaff_EBP + -4) = 4;
              puStack_150 = (undefined *)FUN_00412ab1(unaff_EBP + -0xac,unaff_EBP + -0x1c);
              *(undefined1 *)(unaff_EBP + -4) = 5;
              iStack_154 = 0x4da161;
              FUN_005b86bd();
              puStack_150 = (undefined *)(unaff_EBP + -0x28);
              *(undefined1 *)(unaff_EBP + -4) = 6;
              iStack_154 = 0x4da171;
              FUN_005d499c();
              *(undefined1 *)(unaff_EBP + -4) = 5;
              puStack_150 = (undefined *)0x4da17d;
              FUN_005b8770();
              *(undefined1 *)(unaff_EBP + -4) = 4;
              puStack_150 = (undefined *)0x4da18c;
              FUN_00401729();
              *(undefined1 *)(unaff_EBP + -4) = 2;
            }
            else {
              iStack_154 = 0x4da1a4;
              puStack_150 = (undefined *)uVar2;
              puStack_150 = (undefined *)FUN_005b8755();
              iStack_154 = unaff_EBP + -0x1c;
              iStack_158 = unaff_EBP + -0xf4;
              *(undefined1 *)(unaff_EBP + -4) = 7;
              puStack_150 = (undefined *)FUN_00412ab1();
              *(undefined1 *)(unaff_EBP + -4) = 8;
              iStack_154 = 0x4da1c9;
              FUN_005b86bd();
              puStack_150 = (undefined *)(unaff_EBP + -0x34);
              *(undefined1 *)(unaff_EBP + -4) = 9;
              iStack_154 = 0x4da1d9;
              FUN_005d499c();
              *(undefined1 *)(unaff_EBP + -4) = 8;
              puStack_150 = (undefined *)0x4da1e5;
              FUN_005b8770();
              *(undefined1 *)(unaff_EBP + -4) = 7;
              puStack_150 = (undefined *)0x4da1f4;
              FUN_00401729();
              *(undefined1 *)(unaff_EBP + -4) = 2;
            }
            puStack_150 = (undefined *)0x4da203;
            FUN_005b8770();
            puStack_150 = (undefined *)(unaff_EBP + -0x10);
            iStack_154 = 0x4da212;
            FUN_00633175();
            uVar2 = *(undefined4 *)(unaff_EBP + -0x10);
            if ((char)uVar2 == '^') {
              iVar5 = iVar5 + -1;
            }
            if (iVar5 == 0) {
              iStack_154 = 0x4da22a;
              puStack_150 = (undefined *)uVar2;
              puStack_150 = (undefined *)FUN_005b8755();
              iStack_154 = unaff_EBP + -0x1c;
              iStack_158 = unaff_EBP + -0xb8;
              *(undefined1 *)(unaff_EBP + -4) = 10;
              puStack_150 = (undefined *)FUN_00412ab1();
              *(undefined1 *)(unaff_EBP + -4) = 0xb;
              iStack_154 = 0x4da24f;
              FUN_005b86bd();
              puStack_150 = (undefined *)(unaff_EBP + -0x40);
              *(undefined1 *)(unaff_EBP + -4) = 0xc;
              iStack_154 = 0x4da25f;
              FUN_005d499c();
              *(undefined1 *)(unaff_EBP + -4) = 0xb;
              puStack_150 = (undefined *)0x4da26b;
              FUN_005b8770();
              *(undefined1 *)(unaff_EBP + -4) = 10;
              puStack_150 = (undefined *)0x4da27a;
              FUN_00401729();
              *(undefined1 *)(unaff_EBP + -4) = 2;
              puStack_150 = (undefined *)0x4da289;
              FUN_005b8770();
              uVar2 = *(undefined4 *)(unaff_EBP + -0x10);
            }
          } while ((*(byte *)(unaff_EBP + -0x94 + *(int *)(*(int *)(unaff_EBP + -0x9c) + 4)) & 1) ==
                   0);
        }
        *(int **)(unaff_EBP + -0xa0) = &iStack_158;
        FUN_005b86bd(unaff_EBP + -0x1c);
        iVar4 = FUN_004d8d0b(*(undefined4 *)(unaff_EBP + 0x11c));
        if (iVar4 == -1) {
          uVar6 = 0;
          if (*(int *)(unaff_EBP + -0x18) != *(int *)(unaff_EBP + -0x1c)) {
            do {
              *(undefined1 *)(unaff_EBP + 0x118) =
                   *(undefined1 *)(uVar6 + *(int *)(unaff_EBP + -0x1c));
              puStack_150 = *(undefined **)(unaff_EBP + 0x118);
              iStack_154 = 0x4da337;
              FUN_00633760();
              uVar6 = uVar6 + 1;
            } while (uVar6 < (uint)(*(int *)(unaff_EBP + -0x18) - *(int *)(unaff_EBP + -0x1c)));
          }
        }
        else {
          iVar4 = iVar4 * 0xc;
          iVar3 = **(int **)(unaff_EBP + 0x120);
          uVar6 = 0;
          if (*(int *)(iVar4 + 4 + iVar3) != *(int *)(iVar4 + iVar3)) {
            do {
              *(undefined1 *)(unaff_EBP + 8) = *(undefined1 *)(*(int *)(iVar4 + iVar3) + uVar6);
              puStack_150 = *(undefined **)(unaff_EBP + 8);
              iStack_154 = 0x4da2fa;
              FUN_00633760();
              uVar6 = uVar6 + 1;
              iVar3 = **(int **)(unaff_EBP + 0x120);
            } while (uVar6 < (uint)(*(int *)(iVar4 + 4 + iVar3) - *(int *)(iVar4 + iVar3)));
          }
        }
        iVar4 = 0;
        if (iVar5 != 0) {
          puStack_150 = *(undefined **)(unaff_EBP + -0x10);
          iStack_154 = 0x4da354;
          FUN_00633760();
          iVar4 = 0;
        }
      }
      else {
        iVar4 = iVar5;
        if (0 < iVar5) {
          iVar4 = 0;
          do {
            puStack_150 = (undefined *)0x5e;
            iStack_154 = 0x4da36d;
            FUN_00633760();
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
        }
        puStack_150 = *(undefined **)(unaff_EBP + -0x10);
        iStack_154 = 0x4da37e;
        FUN_00633760();
      }
      puStack_150 = (undefined *)(unaff_EBP + -0x10);
      iStack_154 = 0x4da38d;
      FUN_00633175();
    }
    *(undefined1 *)(unaff_EBP + -4) = 1;
    puStack_150 = (undefined *)0x4da39e;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 0;
    puStack_150 = (undefined *)0x4da3ad;
    FUN_0063370b();
    puStack_150 = (undefined *)0x4da3b8;
    FUN_00632b08();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  puStack_150 = (undefined *)0x4da3c7;
  FUN_006334fd();
  puStack_150 = (undefined *)0x4da3d2;
  FUN_00632b08();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 1;
}

