
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e4244(void)

{
  byte bVar1;
  undefined4 *puVar2;
  int *piVar3;
  char cVar4;
  short sVar5;
  undefined4 uVar6;
  int iVar7;
  size_t sVar8;
  void *pvVar9;
  char *pcVar10;
  undefined4 extraout_ECX;
  int iVar11;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x3c) = extraout_ECX;
  FUN_0046f824(unaff_EBP + -0x1b4,0,0x100);
  puVar2 = *(undefined4 **)(unaff_EBP + 8);
  *(undefined ***)(unaff_EBP + -0x1c0) = &PTR_FUN_00666524;
  FUN_00457f7a(unaff_EBP + -0x1c0);
  piVar3 = (int *)*puVar2;
  sVar5 = (**(code **)(*piVar3 + 0x34))(0x42484156);
  *(int *)(unaff_EBP + -0x14) = (int)sVar5;
  FUN_0046fca5();
  *(undefined ***)(unaff_EBP + -0xb4) = &PTR_FUN_0066643c;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00470383(piVar3,0x12d,0);
  *(undefined4 *)(unaff_EBP + -0x30) = 0;
  *(undefined4 *)(unaff_EBP + -0x2c) = 0;
  *(undefined4 *)(unaff_EBP + -0x28) = 0;
  iVar11 = puVar2[3];
  *(undefined1 *)(unaff_EBP + -4) = 1;
  *(int *)(unaff_EBP + -0x34) = iVar11;
  uVar6 = (**(code **)(**(int **)(iVar11 + 0x10) + 0x1c))();
  *(undefined4 *)(unaff_EBP + -0x24) = uVar6;
  iVar11 = 1;
  if (0 < *(int *)(unaff_EBP + -0x14)) {
    do {
      uVar6 = (**(code **)(*piVar3 + 0x40))(0x42484156,iVar11,*(undefined4 *)(unaff_EBP + -0x24));
      (**(code **)(*piVar3 + 0x50))(uVar6,unaff_EBP + 10);
      iVar7 = FUN_00401f6f();
      if (iVar7 == 0) {
        *(int *)(unaff_EBP + -0x18) = (int)*(short *)(unaff_EBP + 10);
        FUN_0042eab4(unaff_EBP + -0x18);
      }
      iVar11 = iVar11 + 1;
    } while (iVar11 <= *(int *)(unaff_EBP + -0x14));
  }
  if (1 < (uint)(*(int *)(unaff_EBP + -0x2c) - *(int *)(unaff_EBP + -0x30) >> 2)) {
    FUN_004e5101(*(undefined4 *)(unaff_EBP + -0x30),*(undefined4 *)(unaff_EBP + -0x2c));
  }
  if ((DAT_006f259c & 1) == 0) {
    DAT_006f259c = DAT_006f259c | 1;
    DAT_006f2590 = 0;
    DAT_006f2594 = 0;
    _DAT_006f2598 = 0;
    *(undefined1 *)(unaff_EBP + -4) = 2;
    sVar8 = _strlen(&DAT_006c8578);
    FUN_00401a3c(&DAT_006c8578,&DAT_006c8578 + sVar8);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_00635543(&LAB_004e4951);
  }
  if ((DAT_006f259c & 2) == 0) {
    DAT_006f259c = DAT_006f259c | 2;
    _DAT_006f2580 = 0;
    _DAT_006f2584 = 0;
    _DAT_006f2588 = 0;
    *(undefined1 *)(unaff_EBP + -4) = 3;
    sVar8 = _strlen(&DAT_006c9b78);
    FUN_00401a3c(&DAT_006c9b78,&DAT_006c9b78 + sVar8);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_00635543(&LAB_004e4947);
  }
  if ((DAT_006f259c & 4) == 0) {
    DAT_006f259c = DAT_006f259c | 4;
    DAT_006f2570 = 0;
    DAT_006f2574 = 0;
    _DAT_006f2578 = 0;
    *(undefined1 *)(unaff_EBP + -4) = 4;
    sVar8 = _strlen(&DAT_006c4a1c);
    FUN_00401a3c(&DAT_006c4a1c,&DAT_006c4a1c + sVar8);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_00635543(&LAB_004e493d);
  }
  if ((DAT_006f259c & 8) == 0) {
    DAT_006f259c = DAT_006f259c | 8;
    _DAT_006f2560 = 0;
    _DAT_006f2564 = 0;
    _DAT_006f2568 = 0;
    *(undefined1 *)(unaff_EBP + -4) = 5;
    sVar8 = _strlen(s_<TAB>_006c9b70);
    FUN_00401a3c(s_<TAB>_006c9b70,s_<TAB>_006c9b70 + sVar8);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_00635543(&LAB_004e4933);
  }
  *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x30);
  if (*(int *)(unaff_EBP + -0x30) != *(int *)(unaff_EBP + -0x2c)) {
    do {
      iVar11 = FUN_0040204f(CONCAT22((short)((uint)*(undefined2 **)(unaff_EBP + -0x1c) >> 0x10),
                                     **(undefined2 **)(unaff_EBP + -0x1c)));
      *(int *)(unaff_EBP + -0x24) = iVar11;
      if ((iVar11 != 0) &&
         (sVar5 = *(short *)(iVar11 + 2), *(undefined4 *)(unaff_EBP + -0x18) = 0, 0 < sVar5)) {
        *(int *)(unaff_EBP + -0x20) = iVar11 + 0x12;
        do {
          if ((*(ushort *)(*(int *)(unaff_EBP + -0x20) + -6) & 0x7fff) == 0x24) {
            cVar4 = FUN_004020d4(CONCAT22((short)((uint)*(undefined2 **)(unaff_EBP + -0x1c) >> 0x10)
                                          ,**(undefined2 **)(unaff_EBP + -0x1c)),
                                 *(undefined4 *)(unaff_EBP + -0x18));
            if (cVar4 != '\0') {
              pvVar9 = operator_new(0x74);
              *(void **)(unaff_EBP + 8) = pvVar9;
              *(undefined1 *)(unaff_EBP + -4) = 6;
              if (pvVar9 == (void *)0x0) {
                uVar6 = 0;
              }
              else {
                uVar6 = FUN_004e489e();
              }
              piVar3 = *(int **)(unaff_EBP + -0x3c);
              *(undefined4 *)(unaff_EBP + -0x38) = uVar6;
              *(undefined1 *)(unaff_EBP + -4) = 1;
              FUN_004e4faf(unaff_EBP + -0x38);
              iVar11 = piVar3[1];
              iVar7 = *piVar3;
              piVar3 = *(int **)(iVar7 + -4 + (iVar11 - iVar7 >> 2) * 4);
              *piVar3 = (iVar11 - iVar7 >> 2) + -1;
              *(undefined2 *)(piVar3 + 1) = **(undefined2 **)(unaff_EBP + -0x1c);
              *(undefined2 *)((int)piVar3 + 6) = *(undefined2 *)(unaff_EBP + -0x18);
              iVar11 = *(int *)(unaff_EBP + -0x20);
              piVar3[0x1b] = *(int *)(iVar11 + -2);
              piVar3[0x1c] = *(int *)(iVar11 + 2);
              FUN_0046f8e4(unaff_EBP + -0x1c0);
              bVar1 = **(byte **)(unaff_EBP + -0x20);
              *(uint *)(unaff_EBP + -0x14) = (uint)bVar1;
              pcVar10 = (char *)FUN_004705f2((uint)bVar1,0xffffffff);
              *(char **)(unaff_EBP + -0x10) = pcVar10;
              if (pcVar10 == (char *)0x0) {
                *(int **)(unaff_EBP + 8) = piVar3 + 0x15;
                sVar8 = _strlen(s____MISSING_DIALOG_STRING____ID_006c9b40);
                FUN_00431779(s____MISSING_DIALOG_STRING____ID_006c9b40,
                             s____MISSING_DIALOG_STRING____ID_006c9b40 + sVar8);
                pcVar10 = (char *)FUN_0063b26a(0x12d,unaff_EBP + -0x48,10);
                *(char **)(unaff_EBP + -0x10) = pcVar10;
                sVar8 = _strlen(pcVar10);
                FUN_00412d8a(*(undefined4 *)(unaff_EBP + -0x10),sVar8 + *(int *)(unaff_EBP + -0x10))
                ;
                sVar8 = _strlen(s___IDX_006c9b68);
                FUN_00412d8a(s___IDX_006c9b68,s___IDX_006c9b68 + sVar8);
                pcVar10 = (char *)FUN_0063b26a(*(undefined4 *)(unaff_EBP + -0x14),unaff_EBP + -0x48,
                                               10);
                *(char **)(unaff_EBP + -0x10) = pcVar10;
                sVar8 = _strlen(pcVar10);
                FUN_00412d8a(*(undefined4 *)(unaff_EBP + -0x10),sVar8 + *(int *)(unaff_EBP + -0x10))
                ;
                sVar8 = _strlen(s___in_006c9b60);
                FUN_00412d8a(s___in_006c9b60,s___in_006c9b60 + sVar8);
                *(char **)(unaff_EBP + -0x10) = *(char **)(unaff_EBP + -0x1bc);
                sVar8 = _strlen(*(char **)(unaff_EBP + -0x1bc));
                FUN_00412d8a(*(undefined4 *)(unaff_EBP + -0x10),sVar8 + *(int *)(unaff_EBP + -0x10))
                ;
              }
              else {
                *(int **)(unaff_EBP + 8) = piVar3 + 0x15;
                sVar8 = _strlen(pcVar10);
                FUN_00431779(*(undefined4 *)(unaff_EBP + -0x10),sVar8 + *(int *)(unaff_EBP + -0x10))
                ;
              }
              pcVar10 = (char *)FUN_00470631(*(undefined4 *)(unaff_EBP + -0x14),0xffffffff);
              *(char **)(unaff_EBP + -0x10) = pcVar10;
              if (pcVar10 == (char *)0x0) {
                sVar8 = _strlen(s____MISSING_DIALOG_DESCRIPTION____006c9b18);
                FUN_00431779(s____MISSING_DIALOG_DESCRIPTION____006c9b18,
                             s____MISSING_DIALOG_DESCRIPTION____006c9b18 + sVar8);
                pcVar10 = (char *)FUN_0063b26a(0x12d,unaff_EBP + -0x48,10);
                *(char **)(unaff_EBP + -0x10) = pcVar10;
                sVar8 = _strlen(pcVar10);
                FUN_00412d8a(*(undefined4 *)(unaff_EBP + -0x10),sVar8 + *(int *)(unaff_EBP + -0x10))
                ;
                sVar8 = _strlen(s___IDX_006c9b68);
                FUN_00412d8a(s___IDX_006c9b68,s___IDX_006c9b68 + sVar8);
                pcVar10 = (char *)FUN_0063b26a(*(undefined4 *)(unaff_EBP + -0x14),unaff_EBP + -0x48,
                                               10);
                *(char **)(unaff_EBP + -0x14) = pcVar10;
                sVar8 = _strlen(pcVar10);
                FUN_00412d8a(*(undefined4 *)(unaff_EBP + -0x14),sVar8 + *(int *)(unaff_EBP + -0x14))
                ;
                sVar8 = _strlen(s___in_006c9b60);
                FUN_00412d8a(s___in_006c9b60,s___in_006c9b60 + sVar8);
                *(char **)(unaff_EBP + -0x14) = *(char **)(unaff_EBP + -0x1bc);
                sVar8 = _strlen(*(char **)(unaff_EBP + -0x1bc));
                FUN_00412d8a(*(undefined4 *)(unaff_EBP + -0x14),sVar8 + *(int *)(unaff_EBP + -0x14))
                ;
              }
              else {
                sVar8 = _strlen(pcVar10);
                FUN_00431779(*(undefined4 *)(unaff_EBP + -0x10),sVar8 + *(int *)(unaff_EBP + -0x10))
                ;
              }
              while (iVar11 = FUN_004558e0(DAT_006f2590,0,DAT_006f2594 - DAT_006f2590), iVar11 != -1
                    ) {
                FUN_00455790(iVar11,DAT_006f2594 - DAT_006f2590,&DAT_006f2580);
              }
              while (iVar11 = FUN_004558e0(DAT_006f2570,0,DAT_006f2574 - DAT_006f2570), iVar11 != -1
                    ) {
                FUN_00455790(iVar11,DAT_006f2574 - DAT_006f2570,&DAT_006f2560);
              }
              while (iVar11 = FUN_004558e0(DAT_006f2590,0,DAT_006f2594 - DAT_006f2590), iVar11 != -1
                    ) {
                FUN_00455790(iVar11,DAT_006f2594 - DAT_006f2590,&DAT_006f2580);
              }
              while (iVar11 = FUN_004558e0(DAT_006f2570,0,DAT_006f2574 - DAT_006f2570), iVar11 != -1
                    ) {
                FUN_00455790(iVar11,DAT_006f2574 - DAT_006f2570,&DAT_006f2560);
              }
            }
            iVar11 = *(int *)(unaff_EBP + -0x24);
          }
          sVar5 = *(short *)(iVar11 + 2);
          *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 1;
          *(int *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + -0x20) + 0xc;
        } while (*(int *)(unaff_EBP + -0x18) < (int)sVar5);
      }
      *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + 4;
    } while (*(int *)(unaff_EBP + -0x1c) != *(int *)(unaff_EBP + -0x2c));
  }
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_0048c4c9();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00470467();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

