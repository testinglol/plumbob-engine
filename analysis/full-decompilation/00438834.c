
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00438834(void)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  byte bVar10;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar7 = *(int *)(unaff_EBP + 0xc);
  iVar2 = *(int *)(iVar7 + 0x60);
  SetRect((LPRECT)(unaff_EBP + -0x34),0x7fffffff,0x7fffffff,-0x80000000,-0x80000000);
  if (*(char *)(unaff_EBP + 0x2c) == '\0') {
    if (*(short *)(iVar2 + 0x14) != 0) {
      if (*(short *)(iVar2 + 0x16) == -1) {
        iVar2 = FUN_004b469d();
        *(int *)(unaff_EBP + 0x2c) = iVar2;
        uVar3 = __ftol();
        *(undefined4 *)(unaff_EBP + -0x20) = uVar3;
        uVar3 = __ftol();
        bVar10 = DAT_006e4b0c & 1;
        *(undefined4 *)(unaff_EBP + -0x24) = uVar3;
        if (bVar10 == 0) {
          DAT_006e4b0c = DAT_006e4b0c | 1;
          DAT_006e4b00 = 0;
          DAT_006e4b04 = 0;
          _DAT_006e4b08 = 0;
          FUN_00635543();
        }
        FUN_00439149();
        FUN_00438c61(iVar7,*(undefined4 *)(unaff_EBP + 0x1c));
        if (DAT_006e4b00 != DAT_006e4b04) {
          iVar7 = DAT_006e4b00 + 4;
          while( true ) {
            *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(unaff_EBP + -0x24);
            *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(unaff_EBP + -0x20);
            piVar4 = (int *)FUN_00422055();
            *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + piVar4[1];
            *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + *piVar4;
            iVar5 = FUN_004b46a0();
            iVar8 = *(int *)(iVar5 + 0x74);
            iVar9 = *(int *)(iVar5 + 0x6c);
            *(int *)(iVar2 + 0x10) = (*(int *)(iVar5 + 0x70) - *(int *)(iVar5 + 0x68)) / 2;
            *(int *)(iVar2 + 0x14) = (iVar8 - iVar9) / 2;
            FUN_004b97eb(unaff_EBP + -0x1c,*(undefined4 *)(iVar2 + 0xc));
            puVar6 = (undefined4 *)
                     FUN_00438834(unaff_EBP + -100,*(undefined4 *)(iVar7 + -4),
                                  *(undefined4 *)(unaff_EBP + 0x10),
                                  *(int *)(iVar7 + 4) + *(int *)(unaff_EBP + 0x14),
                                  *(int *)(iVar7 + 8) + *(int *)(unaff_EBP + 0x18),
                                  *(undefined4 *)(unaff_EBP + 0x1c),
                                  *(undefined4 *)(unaff_EBP + 0x20),
                                  *(undefined4 *)(unaff_EBP + 0x24),
                                  *(undefined4 *)(unaff_EBP + 0x28));
            *(undefined4 *)(unaff_EBP + -0x44) = *puVar6;
            *(undefined4 *)(unaff_EBP + -0x40) = puVar6[1];
            *(undefined4 *)(unaff_EBP + -0x3c) = puVar6[2];
            *(undefined4 *)(unaff_EBP + -0x38) = puVar6[3];
            *(undefined4 *)(unaff_EBP + -0x54) = *(undefined4 *)(unaff_EBP + -0x44);
            *(undefined4 *)(unaff_EBP + -0x50) = *(undefined4 *)(unaff_EBP + -0x40);
            *(undefined4 *)(unaff_EBP + -0x4c) = *(undefined4 *)(unaff_EBP + -0x3c);
            *(undefined4 *)(unaff_EBP + -0x48) = *(undefined4 *)(unaff_EBP + -0x38);
            FUN_00422698();
            if (iVar7 + 0xc == DAT_006e4b04) break;
            iVar2 = *(int *)(unaff_EBP + 0x2c);
            iVar7 = iVar7 + 0x10;
          }
        }
        goto LAB_00438c39;
      }
      goto LAB_004389e7;
    }
  }
  else {
LAB_004389e7:
    if ((*(short *)(iVar2 + 0x14) != 0) && (*(short *)(iVar2 + 0x16) == -1)) goto LAB_00438c39;
  }
  if ((int)*(short *)(iVar2 + 8) <= *(int *)(unaff_EBP + 0x24)) {
    *(undefined4 *)(unaff_EBP + 0x24) = 0;
  }
  iVar7 = FUN_004577bb();
  if (iVar7 != 0) {
    iVar7 = FUN_004078a4();
    *(int *)(unaff_EBP + 0x24) = iVar7;
    if (iVar7 != 0) {
      if ((*(int *)(unaff_EBP + 0x30) != 0) && (*(char *)(*(int *)(unaff_EBP + 0x30) + 4) != '\0'))
      {
        iVar7 = FUN_00457553();
        *(int *)(unaff_EBP + 0x2c) = iVar7;
        if (iVar7 != -1) {
          iVar7 = *(int *)(unaff_EBP + 0x10);
          bVar10 = (byte)*(undefined4 *)(iVar7 + 0x20);
          iVar8 = 8 << (bVar10 & 0x1f);
          iVar2 = *(int *)(unaff_EBP + 0x18);
          *(int *)(unaff_EBP + -0x3c) = iVar8 + *(int *)(unaff_EBP + 0x14);
          iVar9 = 4 << (bVar10 & 0x1f);
          *(int *)(unaff_EBP + -0x44) = *(int *)(unaff_EBP + 0x14) - iVar8;
          *(int *)(unaff_EBP + -0x40) = iVar2 - iVar9;
          *(int *)(unaff_EBP + -0x38) = iVar9 + iVar2;
          FUN_00422698();
          if (*(char *)(unaff_EBP + 0x28) == '\0') {
            bVar10 = *(byte *)(unaff_EBP + 0x2c);
            *(byte *)(unaff_EBP + 0x2c) = bVar10;
            *(undefined4 *)(unaff_EBP + -4) = 0;
            iVar8 = *(int *)(unaff_EBP + 0x1c) / 2;
            if (0 < iVar8) {
              *(undefined1 *)(unaff_EBP + 0x2c) = (&DAT_006efc6c)[(uint)bVar10 + iVar8 * 0x100];
            }
            FUN_00492d2c();
            FUN_004a15d2();
            *(undefined1 **)(unaff_EBP + 0x1c) = &stack0xffffff84;
            FUN_00438c54(unaff_EBP + 0x2c);
            FUN_004a3ddb(unaff_EBP + -0x24);
            bVar10 = (byte)*(undefined4 *)(iVar7 + 0x20);
            FUN_00438d9d(*(int *)(unaff_EBP + 0x14) - (8 << (bVar10 & 0x1f)),
                         iVar2 - (4 << (bVar10 & 0x1f)),unaff_EBP + -0x24,0x28);
            *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          }
        }
      }
      *(undefined4 *)(unaff_EBP + 0x2c) = 0;
      if (0 < (int)((*(int **)(unaff_EBP + 0x24))[1] - **(int **)(unaff_EBP + 0x24) & 0xffffffe0U))
      {
        do {
          puVar6 = (undefined4 *)FUN_00407ade();
          iVar7 = puVar6[1];
          uVar3 = *(undefined4 *)(*(int *)(unaff_EBP + 0xc) + 8);
          *(undefined4 *)(unaff_EBP + -0x18) = *puVar6;
          *(int *)(unaff_EBP + -0x10) = iVar7;
          *(undefined4 *)(unaff_EBP + 0x1c) = uVar3;
          iVar2 = FUN_004c8f58();
          if (iVar7 < iVar2) {
            FUN_004c8ec9(unaff_EBP + -0x24);
            cVar1 = FUN_004644a0();
            if (cVar1 == '\0') {
              iVar7 = puVar6[2] + *(int *)(unaff_EBP + 0x14);
              iVar2 = (puVar6[3] - (int)*(short *)(unaff_EBP + -0x20)) + *(int *)(unaff_EBP + 0x18);
              if ((float)puVar6[4] != _DAT_0066657c) {
                *(int *)(unaff_EBP + 0x30) =
                     1 << ((char)*(undefined4 *)(unaff_EBP + 0x20) + 1U & 0x1f);
                iVar8 = __ftol();
                iVar2 = iVar2 - iVar8;
              }
              *(int *)(unaff_EBP + -0x40) = (int)*(short *)(unaff_EBP + -0x24);
              uVar3 = puVar6[7];
              *(int *)(unaff_EBP + -0x38) = (int)*(short *)(unaff_EBP + -0x20);
              *(int *)(unaff_EBP + -0x44) = (int)*(short *)(unaff_EBP + -0x22);
              *(int *)(unaff_EBP + -0x3c) = (int)*(short *)(unaff_EBP + -0x1e);
              OffsetRect((LPRECT)(unaff_EBP + -0x44),iVar7,iVar2);
              FUN_00422698();
              if (*(char *)(unaff_EBP + 0x28) == '\0') {
                FUN_004c7387(unaff_EBP + -0x74,*(undefined4 *)(unaff_EBP + -0x18),
                             *(undefined4 *)(unaff_EBP + -0x10),iVar7,iVar2,uVar3);
              }
            }
          }
          *(int *)(unaff_EBP + 0x2c) = *(int *)(unaff_EBP + 0x2c) + 1;
        } while (*(int *)(unaff_EBP + 0x2c) <
                 (*(int **)(unaff_EBP + 0x24))[1] - **(int **)(unaff_EBP + 0x24) >> 5);
      }
    }
  }
LAB_00438c39:
  puVar6 = *(undefined4 **)(unaff_EBP + 8);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *puVar6 = *(undefined4 *)(unaff_EBP + -0x34);
  puVar6[1] = *(undefined4 *)(unaff_EBP + -0x30);
  puVar6[2] = *(undefined4 *)(unaff_EBP + -0x2c);
  puVar6[3] = *(undefined4 *)(unaff_EBP + -0x28);
  return;
}

