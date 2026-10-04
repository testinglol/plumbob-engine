
uint FUN_0049004a(void)

{
  char cVar1;
  ushort uVar2;
  char cVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 *puVar6;
  char *pcVar7;
  byte *pbVar8;
  ushort *puVar9;
  int extraout_ECX;
  int iVar10;
  int *piVar11;
  int unaff_EBP;
  char *pcVar12;
  bool bVar13;
  
  uVar4 = FUN_00634c24();
  pcVar12 = *(char **)(unaff_EBP + 8);
  cVar3 = *pcVar12;
  uVar5 = CONCAT31((int3)((uint)uVar4 >> 8),cVar3);
  *(int *)(unaff_EBP + -0x24) = extraout_ECX;
  if ('\0' < cVar3) {
    uVar5 = (uint)cVar3;
    iVar10 = *(int *)(DAT_006e54dc + 0x10) + -1;
    if ((int)uVar5 < iVar10) {
      cVar1 = pcVar12[1];
      uVar5 = CONCAT31(cVar3 >> 7,cVar1);
      if (('\0' < cVar1) && (uVar5 = (uint)cVar1, (int)uVar5 < iVar10)) {
        cVar3 = pcVar12[3];
        uVar5 = CONCAT31(cVar1 >> 7,cVar3);
        if (('\0' < cVar3) && (uVar5 = (uint)cVar3, (int)uVar5 < iVar10)) {
          cVar1 = pcVar12[4];
          uVar5 = CONCAT31(cVar3 >> 7,cVar1);
          if (('\0' < cVar1) && (uVar5 = (uint)cVar1, (int)uVar5 < iVar10)) {
            *(undefined1 *)(unaff_EBP + -0x26) = 0;
            *(undefined4 *)(extraout_ECX + 0x54) = 0;
            *(undefined4 *)(unaff_EBP + -0x2c) = 0;
            *(undefined4 *)(unaff_EBP + -4) = 0;
            FUN_004619d2(unaff_EBP + -0x34);
            *(undefined1 *)(unaff_EBP + -4) = 1;
            puVar6 = (undefined4 *)FUN_004619b0(unaff_EBP + -0x3c);
            *(undefined4 *)(unaff_EBP + -0x2c) = *puVar6;
            FUN_00461b74(puVar6 + 1);
            while( true ) {
              iVar10 = FUN_004619d2(unaff_EBP + -0x3c);
              cVar3 = FUN_0046198c(iVar10 + 4);
              cVar3 = '\x01' - (cVar3 != '\0');
              *(char *)(unaff_EBP + -0xd) = cVar3;
              if (cVar3 == '\0') break;
              pcVar7 = (char *)FUN_00461941(unaff_EBP + -0x10);
              if ((((*pcVar7 < '\x01') ||
                   (iVar10 = *(int *)(DAT_006e54dc + 0x10) + -1, iVar10 <= *pcVar7)) ||
                  (pcVar7[1] < '\x01')) || (iVar10 <= pcVar7[1])) {
LAB_00490193:
                bVar13 = true;
              }
              else {
                uVar4 = FUN_00461941(unaff_EBP + -0x14);
                bVar13 = DAT_006e4a84 == 0;
                *(undefined1 *)(unaff_EBP + -4) = 3;
                uVar5 = 1;
                if (bVar13) {
                  pbVar8 = (byte *)FUN_00489c8e(uVar4);
                  uVar5 = ((byte)~*pbVar8 & 0x20) >> 5;
                }
                bVar13 = false;
                if (uVar5 == 0) goto LAB_00490193;
              }
              *(undefined1 *)(unaff_EBP + -4) = 1;
              if (bVar13) {
                uVar5 = *(uint *)(unaff_EBP + -0x24);
                *(undefined4 *)(uVar5 + 0x54) = 1;
                goto LAB_004902d9;
              }
              pcVar7 = (char *)FUN_00461941(unaff_EBP + -0x18);
              if (*(byte *)(*(int *)(*(int *)(*(int *)(*(int *)(unaff_EBP + -0x24) + 0x38) + 0x10) +
                                    *pcVar7 * 4) + (int)pcVar7[1]) < 0x10) {
                uVar4 = FUN_00461941(unaff_EBP + -0x1c);
                *(undefined1 *)(unaff_EBP + -4) = 4;
                puVar9 = (ushort *)FUN_00435bca(uVar4);
                uVar2 = *puVar9;
                *(undefined1 *)(unaff_EBP + -4) = 1;
                if (uVar2 < 0xfffb) {
                  FUN_004670a4(CONCAT22((short)((uint)pcVar12 >> 0x10),uVar2));
                  cVar3 = FUN_00468a5f();
                  if (cVar3 != '\0') {
                    for (piVar11 = *(int **)(*(int *)(*DAT_006e486c + 0x14) + 0x84);
                        piVar11 != *(int **)(*(int *)(*DAT_006e486c + 0x14) + 0x88);
                        piVar11 = piVar11 + 1) {
                      if ((*piVar11 != 0) && (*(ushort *)(*piVar11 + 0x84) == uVar2)) {
                        uVar5 = *(uint *)(unaff_EBP + -0x24);
                        *(undefined4 *)(uVar5 + 0x54) = 0x2c;
                        goto LAB_004902d9;
                      }
                    }
                  }
                }
                pcVar12 = *(char **)(unaff_EBP + 8);
              }
              uVar4 = FUN_00461941(unaff_EBP + -0x20);
              piVar11 = DAT_006e486c;
              *(undefined1 *)(unaff_EBP + -4) = 5;
              FUN_0043f371(*piVar11,uVar4,0);
              *(undefined1 *)(unaff_EBP + -4) = 1;
              while (*(int *)(unaff_EBP + -0x44) != 0) {
                iVar10 = FUN_004573f9();
                if (*(short *)(*(int *)(iVar10 + 0x60) + 0x8a) == 7) {
                  uVar5 = *(uint *)(unaff_EBP + -0x24);
                  *(undefined4 *)(uVar5 + 0x54) = 0x2d;
                  goto LAB_004902d9;
                }
                FUN_0043f3b9();
              }
              FUN_00461961();
            }
            uVar5 = FUN_0048fb2b(*(int *)(unaff_EBP + -0x24) + 0x40,
                                 *(int *)(unaff_EBP + -0x24) + 0x48);
            goto LAB_004902db;
          }
        }
      }
    }
  }
  *(undefined4 *)(extraout_ECX + 0x54) = 1;
LAB_004902d9:
  uVar5 = uVar5 & 0xffffff00;
LAB_004902db:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar5;
}

