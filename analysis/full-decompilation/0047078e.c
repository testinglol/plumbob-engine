
int FUN_0047078e(void)

{
  char cVar1;
  undefined2 uVar2;
  short sVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  int *piVar9;
  size_t sVar10;
  size_t sVar11;
  undefined2 *puVar12;
  undefined4 *puVar13;
  undefined1 *puVar14;
  int extraout_ECX;
  short sVar15;
  undefined4 *puVar16;
  int unaff_EBP;
  int iVar17;
  char *pcVar18;
  
  FUN_00634c24();
  FUN_004706f0();
  cVar1 = *(char *)(extraout_ECX + 0x5d);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  uVar6 = *(undefined4 *)(extraout_ECX + 0x58);
  uVar2 = *(undefined2 *)(extraout_ECX + 0x54);
  uVar7 = *(undefined4 *)(extraout_ECX + 4);
  *(undefined1 *)(unaff_EBP + -0x3c) = 0;
  *(undefined4 *)(unaff_EBP + -0x94) = uVar7;
  *(undefined2 *)(unaff_EBP + -0x44) = uVar2;
  *(undefined4 *)(unaff_EBP + -0x40) = uVar6;
  if (cVar1 < '\0') {
    *(char *)(unaff_EBP + -0x3b) = *(char *)(DAT_006e486c + 100) + -1;
  }
  else {
    *(char *)(unaff_EBP + -0x3b) = cVar1;
  }
  iVar17 = 1;
  FUN_00470d9f(1,1);
  iVar4 = FUN_0046fc11(0xffffffff);
  if (0 < iVar4) {
    do {
      uVar5 = (uint)*(byte *)(extraout_ECX + 0x5d);
      uVar6 = FUN_00471509(iVar17,0xffffffff);
      FUN_0047132c(iVar17,uVar6,uVar5);
      iVar4 = FUN_00471584(iVar17,0xffffffff);
      if (iVar4 != 0) {
        uVar5 = (uint)*(byte *)(extraout_ECX + 0x5d);
        uVar6 = FUN_00471584(iVar17,0xffffffff);
        FUN_004715d3(iVar17,uVar6,uVar5);
      }
      iVar17 = iVar17 + 1;
      iVar4 = FUN_0046fc11(0xffffffff);
    } while (iVar17 <= iVar4);
  }
  iVar17 = 1;
  iVar4 = FUN_0046fc11(0xffffffff);
  if (0 < iVar4) {
    do {
      *(undefined1 *)(unaff_EBP + -0x10) = 1;
      do {
        iVar4 = FUN_00471584(iVar17,0);
        *(int *)(unaff_EBP + -0x1c) = iVar4;
        if ((iVar4 != 0) &&
           (iVar4 = FUN_00471509(iVar17,*(undefined4 *)(unaff_EBP + -0x10)), iVar4 != 0)) {
          FUN_004715d3(iVar17,*(undefined4 *)(unaff_EBP + -0x1c),*(undefined4 *)(unaff_EBP + -0x10))
          ;
        }
        *(char *)(unaff_EBP + -0x10) = *(char *)(unaff_EBP + -0x10) + '\x01';
      } while (*(char *)(unaff_EBP + -0x10) < '\x14');
      iVar17 = iVar17 + 1;
      iVar4 = FUN_0046fc11(0xffffffff);
    } while (iVar17 <= iVar4);
  }
  uVar6 = FUN_0046fc11(0);
  *(undefined4 *)(unaff_EBP + -0x1c) = uVar6;
  *(undefined1 *)(unaff_EBP + -0x10) = 1;
  *(undefined4 *)(unaff_EBP + -0x14) = 0xc;
  do {
    iVar17 = FUN_0046fc11(*(undefined4 *)(unaff_EBP + -0x10));
    iVar17 = iVar17 + 1;
    if (iVar17 <= *(int *)(unaff_EBP + -0x1c)) {
      iVar4 = iVar17 * 0xc;
      do {
        uVar6 = *(undefined4 *)(unaff_EBP + -0x10);
        uVar7 = FUN_00471509(iVar17,0);
        FUN_0047132c(iVar17,uVar7,uVar6);
        *(undefined1 *)
         (iVar4 + -4 + *(int *)(*(int *)(unaff_EBP + -0x14) + *(int *)(unaff_EBP + -0x2c))) = 0;
        iVar8 = FUN_00471584(iVar17,0);
        if (iVar8 != 0) {
          uVar6 = *(undefined4 *)(unaff_EBP + -0x10);
          uVar7 = FUN_00471584(iVar17,0);
          FUN_004715d3(iVar17,uVar7,uVar6);
        }
        iVar17 = iVar17 + 1;
        iVar4 = iVar4 + 0xc;
      } while (iVar17 <= *(int *)(unaff_EBP + -0x1c));
    }
    *(char *)(unaff_EBP + -0x10) = *(char *)(unaff_EBP + -0x10) + '\x01';
    *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 0xc;
  } while (*(char *)(unaff_EBP + -0x10) < '\x14');
  *(undefined1 *)(unaff_EBP + -0x10) = 1;
  *(undefined4 *)(unaff_EBP + -0x14) = 0xc;
  do {
    *(undefined1 *)(unaff_EBP + -0x15) = 0;
    iVar17 = 1;
    iVar4 = FUN_0046fc11(*(undefined4 *)(unaff_EBP + -0x10));
    if (iVar4 < 1) {
LAB_004709bd:
      FUN_00471287(*(undefined4 *)(unaff_EBP + -0x10));
    }
    else {
      iVar4 = 0xc;
      do {
        if (*(char *)(unaff_EBP + -0x15) != '\0') goto LAB_004709cb;
        if (*(char *)(iVar4 + -4 +
                     *(int *)(*(int *)(unaff_EBP + -0x14) + *(int *)(unaff_EBP + -0x2c))) != '\0') {
          *(undefined1 *)(unaff_EBP + -0x15) = 1;
        }
        iVar17 = iVar17 + 1;
        iVar4 = iVar4 + 0xc;
        iVar8 = FUN_0046fc11(*(undefined4 *)(unaff_EBP + -0x10));
      } while (iVar17 <= iVar8);
      if (*(char *)(unaff_EBP + -0x15) == '\0') goto LAB_004709bd;
    }
LAB_004709cb:
    *(char *)(unaff_EBP + -0x10) = *(char *)(unaff_EBP + -0x10) + '\x01';
    *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 0xc;
    if ('\x13' < *(char *)(unaff_EBP + -0x10)) {
      *(undefined4 *)(unaff_EBP + -0x14) = 0;
      iVar17 = 4;
      *(undefined4 *)(unaff_EBP + -0x1c) = 0x14;
      do {
        piVar9 = (int *)(*(int *)(unaff_EBP + -0x2c) + *(int *)(unaff_EBP + -0x14));
        puVar16 = (undefined4 *)*piVar9;
        if (puVar16 != (undefined4 *)piVar9[1]) {
          do {
            if ((char *)*puVar16 == (char *)0x0) {
              sVar10 = 0;
            }
            else {
              sVar10 = _strlen((char *)*puVar16);
            }
            if ((char *)puVar16[1] == (char *)0x0) {
              sVar11 = 0;
            }
            else {
              sVar11 = _strlen((char *)puVar16[1]);
            }
            iVar17 = iVar17 + sVar10 + 4 + sVar11;
            puVar16 = puVar16 + 3;
          } while (puVar16 !=
                   *(undefined4 **)(*(int *)(unaff_EBP + -0x14) + 4 + *(int *)(unaff_EBP + -0x2c)));
        }
        *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 0xc;
        piVar9 = (int *)(unaff_EBP + -0x1c);
        *piVar9 = *piVar9 + -1;
      } while (*piVar9 != 0);
      iVar17 = FUN_0041ffd9(iVar17);
      *(int *)(unaff_EBP + -0x20) = iVar17;
      if (iVar17 == 0) {
        iVar17 = FUN_00633a1e();
      }
      else {
        puVar12 = (undefined2 *)FUN_00420048(iVar17);
        sVar15 = 0;
        *(undefined1 *)(unaff_EBP + -0x10) = 0;
        *puVar12 = 0xfffd;
        do {
          sVar3 = FUN_0046fc11(*(undefined4 *)(unaff_EBP + -0x10));
          sVar15 = sVar15 + sVar3;
          *(char *)(unaff_EBP + -0x10) = *(char *)(unaff_EBP + -0x10) + '\x01';
        } while (*(char *)(unaff_EBP + -0x10) < '\x14');
        *(undefined1 *)(unaff_EBP + -0x10) = 0;
        puVar12[1] = sVar15;
        pcVar18 = (char *)(puVar12 + 2);
        *(undefined4 *)(unaff_EBP + -0x14) = 0;
        do {
          puVar13 = (undefined4 *)(*(int *)(unaff_EBP + -0x2c) + *(int *)(unaff_EBP + -0x14));
          puVar16 = (undefined4 *)*puVar13;
          if (puVar16 != (undefined4 *)puVar13[1]) {
            *(int *)(unaff_EBP + -0x1c) =
                 CONCAT22((short)((uint)puVar13 >> 0x10),(short)*(char *)(unaff_EBP + -0x10)) + 1;
            do {
              *(undefined2 *)pcVar18 = *(undefined2 *)(unaff_EBP + -0x1c);
              puVar14 = (undefined1 *)*puVar16;
              if (puVar14 == (undefined1 *)0x0) {
                puVar14 = &DAT_006de560;
              }
              FUN_006358b0(pcVar18 + 1,puVar14);
              sVar10 = _strlen(pcVar18 + 1);
              pcVar18 = pcVar18 + sVar10 + 2;
              puVar14 = (undefined1 *)puVar16[1];
              if (puVar14 == (undefined1 *)0x0) {
                puVar14 = &DAT_006de560;
              }
              FUN_006358b0(pcVar18,puVar14);
              sVar10 = _strlen(pcVar18);
              pcVar18 = pcVar18 + sVar10 + 1;
              puVar16 = puVar16 + 3;
            } while (puVar16 !=
                     *(undefined4 **)(*(int *)(unaff_EBP + -0x14) + 4 + *(int *)(unaff_EBP + -0x2c))
                    );
          }
          *(char *)(unaff_EBP + -0x10) = *(char *)(unaff_EBP + -0x10) + '\x01';
          *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 0xc;
        } while (*(char *)(unaff_EBP + -0x10) < '\x14');
        uVar6 = *(undefined4 *)(unaff_EBP + -0x20);
        FUN_0042004f(uVar6);
        if ((*(int *)(extraout_ECX + 0x58) == 0) || (*(int *)(extraout_ECX + 0x58) == 0x435354)) {
          *(undefined4 *)(extraout_ECX + 0x58) = 0x53545223;
        }
        (**(code **)(**(int **)(extraout_ECX + 4) + 0x74))
                  (uVar6,*(undefined4 *)(extraout_ECX + 0x58),
                   CONCAT22((short)((uint)(extraout_ECX + 8) >> 0x10),
                            *(undefined2 *)(extraout_ECX + 0x54)),extraout_ECX + 8,1);
        iVar17 = FUN_00401f6f();
        if (iVar17 == 0) {
          (**(code **)(**(int **)(extraout_ECX + 4) + 0x7c))(uVar6);
          iVar17 = FUN_00401f6f();
          if (iVar17 == 0) {
            FUN_00465a06(uVar6);
            iVar17 = FUN_00401f6f();
            if (iVar17 == 0) {
              iVar17 = 0;
            }
          }
        }
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_004712d0();
      ExceptionList = *(void **)(unaff_EBP + -0xc);
      return iVar17;
    }
  } while( true );
}

