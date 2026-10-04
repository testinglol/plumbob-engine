
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00466d14(void)

{
  short sVar1;
  int iVar2;
  ushort *puVar3;
  undefined1 *puVar4;
  char cVar5;
  float fVar6;
  int iVar7;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *puVar8;
  bool bVar9;
  
  FUN_00634c24();
  bVar9 = DAT_006e53dc == '\0';
  *(undefined4 **)(unaff_EBP + -0x20) = extraout_ECX;
  if (bVar9) {
    FUN_004666a9();
    DAT_006e53dc = '\x01';
  }
  if (*(char *)(extraout_ECX + 0xe) == '\0') {
    FUN_004674a8();
    *(undefined1 *)(extraout_ECX + 0xe) = 1;
  }
  iVar2 = extraout_ECX[1];
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  iVar7 = *(int *)(iVar2 + 8);
  *(int *)(unaff_EBP + -0x10) = iVar7;
  puVar8 = extraout_ECX;
  if (iVar7 != iVar2) {
    do {
      puVar3 = *(ushort **)(iVar7 + 0x14);
      if ((puVar3 != (ushort *)0x0) && (*(int *)(puVar3 + 0x1a) != 0)) {
        if (((*(int *)(unaff_EBP + 8) == 0) ||
            (((*puVar3 & 0xc00) >> 10) + 1 == *(int *)(unaff_EBP + 8))) &&
           ((char)puVar3[0x38] != '\0')) {
          fVar6 = DAT_00667638;
          if ((*(char *)((int)puVar3 + 0x75) == '\0') &&
             ((((*(char *)((int)puVar3 + 0x73) == '\0' || (*(int *)(puVar3 + 0x140) != 0)) ||
               (*(int *)(puVar3 + 0x142) < 1)) || (DAT_00667638 <= *(float *)(puVar3 + 0x36))))) {
            fVar6 = *(float *)(puVar3 + 0x36);
          }
          *(float *)(unaff_EBP + -0x24) = fVar6;
          FUN_00467999();
          *(undefined1 *)(puVar3 + 0x38) = 0;
          puVar3[0x1a] = 1;
          puVar3[0x1b] = 0;
          puVar4 = *(undefined1 **)(puVar3 + 2);
          if (puVar4 != *(undefined1 **)(puVar3 + 4)) {
            *(undefined1 *)(unaff_EBP + -0x18) = *puVar4;
            *(undefined1 *)(unaff_EBP + -0x17) = puVar4[1];
            *(undefined1 *)(unaff_EBP + -0x16) = puVar4[2];
            *(undefined4 *)(unaff_EBP + -4) = 0;
            cVar5 = FUN_004790e8(unaff_EBP + -0x18);
            *(bool *)((int)puVar3 + 0x75) = cVar5 != '\0';
            iVar7 = *(int *)(puVar3 + 2);
            iVar2 = *(int *)(puVar3 + 4);
            *(int *)(unaff_EBP + -0x14) = iVar7;
            if (iVar7 != iVar2) {
              while( true ) {
                FUN_00467c93(iVar7);
                FUN_0043f371(*puVar8,iVar7,0);
                FUN_00467ee7(*(undefined4 *)(unaff_EBP + -0x30),*(undefined4 *)(unaff_EBP + -0x2c),
                             *(undefined4 *)(unaff_EBP + -0x28));
                *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 3;
                puVar8 = *(undefined4 **)(unaff_EBP + -0x20);
                if (*(int *)(unaff_EBP + -0x14) == *(int *)(puVar3 + 4)) break;
                iVar7 = *(int *)(unaff_EBP + -0x14);
              }
            }
            *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          }
          FUN_00467a62(*puVar8);
          fVar6 = DAT_00667638;
          if ((*(char *)((int)puVar3 + 0x75) == '\0') &&
             (((*(char *)((int)puVar3 + 0x73) == '\0' || (*(int *)(puVar3 + 0x140) != 0)) ||
              ((*(int *)(puVar3 + 0x142) < 1 || (DAT_00667638 <= *(float *)(puVar3 + 0x36))))))) {
            fVar6 = *(float *)(puVar3 + 0x36);
          }
          if (*(float *)(unaff_EBP + -0x24) != fVar6) {
            FUN_0040766a(0xf1,*puVar3);
          }
        }
        if ((*(int *)(puVar3 + 0x1a) != 0) && (cVar5 = FUN_00468851(), cVar5 == '\0')) {
          *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + *(int *)(puVar3 + 0x1c) / 2;
        }
      }
      FUN_0041674f();
      iVar7 = *(int *)(unaff_EBP + -0x10);
    } while (iVar7 != puVar8[1]);
  }
  iVar2 = puVar8[1];
  puVar8[0x10] = 0;
  iVar7 = *(int *)(iVar2 + 8);
  *(int *)(unaff_EBP + -0x10) = iVar7;
  if (iVar7 != iVar2) {
    do {
      iVar2 = *(int *)(iVar7 + 0x14);
      if (((iVar2 != 0) && (*(int *)(iVar2 + 0x34) != 0)) && (cVar5 = FUN_00468851(), cVar5 != '\0')
         ) {
        puVar8[0x10] = *(float *)(iVar2 + 0x68) + (float)puVar8[0x10];
      }
      FUN_0041674f();
      iVar7 = *(int *)(unaff_EBP + -0x10);
    } while (iVar7 != puVar8[1]);
  }
  fVar6 = (float)puVar8[0x10] / _DAT_006e53ac;
  puVar8[0xf] = fVar6;
  sVar1 = *(short *)(*(int *)(DAT_006e486c + 0x1c) + 0x18);
  if (sVar1 == 0) {
    fVar6 = fVar6 + _DAT_006e53a8;
  }
  else {
    if (sVar1 != 1) {
      if (sVar1 == 2) {
        fVar6 = fVar6 + _DAT_006e53a0;
        goto LAB_00466f73;
      }
      if (sVar1 != 3) goto LAB_00466f76;
    }
    fVar6 = fVar6 + _DAT_006e53a4;
  }
LAB_00466f73:
  puVar8[0xf] = fVar6;
LAB_00466f76:
  fVar6 = _DAT_00666a60;
  if (((float)puVar8[0xf] < _DAT_00666a60) ||
     (fVar6 = _DAT_0066674c, _DAT_0066674c < (float)puVar8[0xf])) {
    puVar8[0xf] = fVar6;
  }
  FUN_0046dae0(0x1b,*(undefined4 *)(unaff_EBP + -0x1c));
  iVar2 = *(int *)(unaff_EBP + 8);
  if (iVar2 == 0) {
    puVar8[0xd] = 0;
  }
  else if (iVar2 == 1) {
    puVar8[0xd] = puVar8[0xd] & 0xfffffffe;
  }
  else if (iVar2 == 2) {
    puVar8[0xd] = puVar8[0xd] & 0xfffffffd;
  }
  FUN_00466fe4(*(undefined4 *)(unaff_EBP + 8));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

