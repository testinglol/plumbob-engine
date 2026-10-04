
/* WARNING (jumptable): Unable to track spacebase fully for stack */

undefined4 FUN_0044e108(void)

{
  byte bVar1;
  char cVar2;
  undefined2 uVar3;
  short sVar4;
  int iVar5;
  undefined4 uVar6;
  short *psVar7;
  uint uVar8;
  undefined4 uVar9;
  int iVar10;
  undefined4 uVar11;
  undefined2 *puVar12;
  int extraout_ECX;
  int unaff_EBP;
  int *piVar13;
  
  FUN_00634c24();
  iVar10 = *(int *)(unaff_EBP + 8);
  if ((*(byte *)((int)*(undefined4 **)(unaff_EBP + 0xc) + 5) & 4) == 0) {
    iVar5 = FUN_0043acf5(**(undefined4 **)(unaff_EBP + 0xc));
  }
  else {
    iVar5 = FUN_00425b48((int)*(short *)(iVar10 + 4));
  }
  *(int *)(unaff_EBP + -0x20) = iVar5;
  if (iVar5 == 0) goto LAB_0044e7e8;
  *(undefined4 *)(unaff_EBP + -0x1c) = 0xffffffff;
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  *(undefined4 *)(unaff_EBP + -0x24) = 0;
  *(undefined4 *)(unaff_EBP + -0x2c) = 0;
  uVar11 = *(undefined4 *)(extraout_ECX + 0x110);
  *(undefined1 *)(unaff_EBP + -0x15) = 1;
  *(undefined4 *)(unaff_EBP + -0x28) = 0xfffb;
  switch(*(undefined1 *)(*(int *)(unaff_EBP + 0xc) + 4)) {
  case 0:
    *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(extraout_ECX + 0xf4);
    *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(extraout_ECX + 0xf8);
    piVar13 = (int *)FUN_004222bd((int)*(short *)(extraout_ECX + 0x4c));
    *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + piVar13[1];
    *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + *piVar13;
    break;
  case 1:
    uVar9 = *(undefined4 *)(extraout_ECX + 0xf4);
    *(int *)(unaff_EBP + -0x24) = extraout_ECX;
    *(undefined4 *)(unaff_EBP + -0x14) = uVar9;
    *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(extraout_ECX + 0xf8);
    break;
  case 2:
    uVar9 = *(undefined4 *)(extraout_ECX + 0xf4);
    *(undefined4 *)(unaff_EBP + -0x2c) = 0;
    *(undefined4 *)(unaff_EBP + -0x14) = uVar9;
    *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(extraout_ECX + 0xf8);
    *(int *)(unaff_EBP + -0x24) = extraout_ECX;
    break;
  case 3:
    iVar10 = FUN_00407498((int)*(short *)(*(int *)(unaff_EBP + 8) + 4));
    if (iVar10 != 0) {
      uVar11 = *(undefined4 *)(iVar10 + 0x110);
      *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(iVar10 + 0xf4);
      *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(iVar10 + 0xf8);
      piVar13 = (int *)FUN_004222bd((int)*(short *)(iVar10 + 0x4c));
      *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + piVar13[1];
      *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + *piVar13;
      uVar3 = *(undefined2 *)(iVar10 + 0x84);
code_r0x0044e420:
      *(undefined2 *)(unaff_EBP + -0x28) = uVar3;
      break;
    }
    goto LAB_0044e7e8;
  case 4:
    iVar10 = FUN_00407498((int)*(short *)(iVar10 + 4));
    if (iVar10 != 0) {
      uVar9 = *(undefined4 *)(iVar10 + 0xf4);
      uVar11 = *(undefined4 *)(iVar10 + 0x110);
      *(undefined4 *)(unaff_EBP + -0x2c) = 0;
      *(undefined4 *)(unaff_EBP + -0x14) = uVar9;
      uVar9 = *(undefined4 *)(iVar10 + 0xf8);
      *(int *)(unaff_EBP + -0x24) = iVar10;
      *(undefined4 *)(unaff_EBP + -0x10) = uVar9;
code_r0x0044e419:
      uVar3 = *(undefined2 *)(iVar10 + 0x84);
      goto code_r0x0044e420;
    }
    goto LAB_0044e7e8;
  case 5:
    *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(extraout_ECX + 0xf4);
    uVar9 = *(undefined4 *)(extraout_ECX + 0xf8);
code_r0x0044e4db:
    *(undefined4 *)(unaff_EBP + -0x10) = uVar9;
    break;
  case 6:
    *(undefined1 *)(unaff_EBP + -0x15) = 0;
    uVar11 = 1;
    *(undefined4 *)(unaff_EBP + -0x10) = 0xfffffff0;
    *(undefined4 *)(unaff_EBP + -0x14) = 0xfffffff0;
    break;
  case 7:
    if (*(char *)(iVar10 + 7) == '\0') {
      *(undefined4 *)(unaff_EBP + -0x44) = 8;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(unaff_EBP + -0x44,&DAT_00698f30);
    }
    psVar7 = (short *)FUN_004752f8();
    iVar10 = FUN_00407498((int)*psVar7);
code_r0x0044e4be:
    if (iVar10 != 0) {
      uVar11 = *(undefined4 *)(iVar10 + 0x110);
      *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(iVar10 + 0xf4);
      uVar9 = *(undefined4 *)(iVar10 + 0xf8);
      goto code_r0x0044e4db;
    }
    goto LAB_0044e7e8;
  case 8:
    cVar2 = *(char *)(*(int *)(unaff_EBP + 0xc) + 6);
    if ((cVar2 < '\0') || ((int)(uint)*(byte *)(iVar10 + 6) <= (int)cVar2)) {
      *(undefined4 *)(unaff_EBP + -0x34) = 8;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(unaff_EBP + -0x34,&DAT_00698f30);
    }
    iVar10 = FUN_004752fc();
    uVar8 = (uint)*(short *)(iVar10 + *(char *)(*(int *)(unaff_EBP + 0xc) + 6) * 2);
    iVar10 = *(int *)(extraout_ECX + 0xdc);
    if ((0 < (int)uVar8) && (uVar8 < (*(int *)(iVar10 + 0x1c) - *(int *)(iVar10 + 0x18) >> 2) + 1U))
    {
      iVar10 = *(int *)(*(int *)(iVar10 + 0x18) + -4 + uVar8 * 4);
      goto code_r0x0044e4be;
    }
    goto LAB_0044e7e8;
  case 9:
    sVar4 = FUN_00453181(0x19,CONCAT22((short)((uint)*(int *)(unaff_EBP + 0xc) >> 0x10),
                                       (short)*(char *)(*(int *)(unaff_EBP + 0xc) + 6)),0);
    uVar6 = 0;
    uVar9 = 0;
    uVar8 = ((int)*(short *)(extraout_ECX + 0x4c) + (int)sVar4) % 8 & 7;
    if (uVar8 == 0) {
      uVar6 = 0;
      uVar9 = 0xffffffff;
    }
    else if (uVar8 == 2) {
      uVar9 = 0;
      uVar6 = 1;
    }
    else if (uVar8 == 4) {
      uVar6 = 0;
      uVar9 = 1;
    }
    else if (uVar8 == 6) {
      uVar6 = 0xffffffff;
    }
    *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(extraout_ECX + 0xf4);
    *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(extraout_ECX + 0xf8);
    piVar13 = (int *)FUN_00422055(uVar6,uVar9);
    *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + piVar13[1];
    *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + *piVar13;
    *(int *)(unaff_EBP + -0x1c) = (*(short *)(extraout_ECX + 0x4c) + 4 + (int)sVar4) % 8;
    break;
  case 10:
    uVar9 = *(undefined4 *)(extraout_ECX + 0xf4);
    *(int *)(unaff_EBP + -0x24) = extraout_ECX;
    *(undefined4 *)(unaff_EBP + -0x14) = uVar9;
    *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(extraout_ECX + 0xf8);
    *(undefined4 *)(unaff_EBP + -0x2c) = 2;
    break;
  case 0xb:
    uVar9 = *(undefined4 *)(extraout_ECX + 0xf4);
    *(int *)(unaff_EBP + -0x24) = extraout_ECX;
    *(undefined4 *)(unaff_EBP + -0x14) = uVar9;
    *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(extraout_ECX + 0xf8);
    *(undefined4 *)(unaff_EBP + -0x2c) = 3;
    break;
  case 0xc:
    iVar10 = FUN_00407498((int)*(short *)(iVar10 + 4));
    if (iVar10 != 0) {
      uVar11 = *(undefined4 *)(iVar10 + 0x110);
      *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(iVar10 + 0xf4);
      *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(iVar10 + 0xf8);
      *(int *)(unaff_EBP + -0x24) = iVar10;
      *(undefined4 *)(unaff_EBP + -0x2c) = 2;
      goto code_r0x0044e419;
    }
    goto LAB_0044e7e8;
  case 0xd:
    iVar10 = FUN_00407498((int)*(short *)(iVar10 + 4));
    if (iVar10 != 0) {
      uVar11 = *(undefined4 *)(iVar10 + 0x110);
      *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(iVar10 + 0xf4);
      *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(iVar10 + 0xf8);
      *(int *)(unaff_EBP + -0x24) = iVar10;
      *(undefined4 *)(unaff_EBP + -0x2c) = 3;
      goto code_r0x0044e419;
    }
    goto LAB_0044e7e8;
  case 0xe:
    iVar10 = FUN_00407498((int)*(short *)(iVar10 + 4));
    if (iVar10 != 0) {
      uVar11 = *(undefined4 *)(iVar10 + 0x110);
      *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(iVar10 + 0xf4);
      *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(iVar10 + 0xf8);
      *(int *)(unaff_EBP + -0x24) = iVar10;
      *(undefined4 *)(unaff_EBP + -0x2c) = 4;
      goto code_r0x0044e419;
    }
    goto LAB_0044e7e8;
  }
  *(char *)(unaff_EBP + -0x2e) = (char)uVar11;
  *(char *)(unaff_EBP + -0x30) = (char)(*(int *)(unaff_EBP + -0x10) >> 4);
  *(char *)(unaff_EBP + -0x2f) = (char)(*(int *)(unaff_EBP + -0x14) >> 4);
  iVar10 = *(int *)(unaff_EBP + 0xc);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if ((*(byte *)(iVar10 + 5) & 1) != 0) {
    FUN_0043f371(*DAT_006e486c,unaff_EBP + -0x30,0);
    while (*(int *)(unaff_EBP + -0x3c) != 0) {
      if (*(int *)(*(int *)(unaff_EBP + -0x3c) + 0x11c) == *(int *)(unaff_EBP + -0x20))
      goto LAB_0044e7e8;
      FUN_0043f3b9();
    }
  }
  if ((((*(byte *)(iVar10 + 5) & 8) == 0) ||
      (FUN_0043f371(*DAT_006e486c,unaff_EBP + -0x30,0), *(int *)(unaff_EBP + -0x3c) == 0)) &&
     ((*(char *)(unaff_EBP + -0x15) == '\0' ||
      (cVar2 = FUN_00422665(unaff_EBP + -0x14), cVar2 == '\0')))) {
    if ((*(byte *)(iVar10 + 5) & 0x40) == 0) {
      sVar4 = (short)*(undefined4 *)(unaff_EBP + -0x28);
    }
    else {
      *(undefined4 *)(unaff_EBP + -0x1c) = 0xffffffff;
      sVar4 = -5;
    }
    if ((((*(char *)(unaff_EBP + -0x15) == '\0') || (sVar4 == -5)) ||
        (*(short *)(*(int *)(*(int *)(*(int *)(DAT_006e54dc + 0x28 +
                                              *(char *)(unaff_EBP + -0x2e) * 4) + 0xc) +
                            *(char *)(unaff_EBP + -0x30) * 4) + *(char *)(unaff_EBP + -0x2f) * 2) ==
         sVar4)) &&
       ((*(int *)(unaff_EBP + -0x1c) == -1 ||
        (uVar8 = FUN_00435a8f(unaff_EBP + -0x30,*(undefined4 *)(unaff_EBP + -0x1c)),
        (uVar8 & 1) == 0)))) {
      uVar9 = FUN_00440b6d(*(undefined4 *)(unaff_EBP + -0x20));
      *(undefined4 *)(unaff_EBP + -0x28) = uVar9;
      if ((short)uVar9 != 0) {
        uVar8 = (uint)(short)uVar9;
        iVar10 = *(int *)(extraout_ECX + 0xdc);
        piVar13 = (int *)0x0;
        if ((0 < (int)uVar8) &&
           (uVar8 < (*(int *)(iVar10 + 0x1c) - *(int *)(iVar10 + 0x18) >> 2) + 1U)) {
          piVar13 = *(int **)(*(int *)(iVar10 + 0x18) + -4 + uVar8 * 4);
        }
        if (*(short *)(piVar13[0x46] + 0x12) == 2) {
          *(undefined4 *)(unaff_EBP + -0x34) = DAT_006e486c[9];
          uVar9 = FUN_006359f2(piVar13,0,&cXObject::RTTI_Type_Descriptor,
                               &cXPerson::RTTI_Type_Descriptor,0);
          FUN_0042597a(uVar9);
        }
        if ((*(byte *)(*(int *)(unaff_EBP + 0xc) + 5) & 0x20) != 0) {
          uVar8 = (uint)*(short *)(*(int *)(unaff_EBP + 8) + 4);
          iVar10 = *(int *)(extraout_ECX + 0xdc);
          if (((0 < (int)uVar8) &&
              (uVar8 < (*(int *)(iVar10 + 0x1c) - *(int *)(iVar10 + 0x18) >> 2) + 1U)) &&
             (iVar10 = *(int *)(*(int *)(iVar10 + 0x18) + -4 + uVar8 * 4), iVar10 != 0)) {
            if (*(short *)(piVar13[0x46] + 0x12) == 2) {
              *(undefined2 *)(piVar13 + 0x13) = *(undefined2 *)(iVar10 + 0x4c);
            }
            else {
              bVar1 = *(byte *)(iVar10 + 0x4c);
              *(undefined4 *)(unaff_EBP + -0x1c) = 0;
              *(uint *)(unaff_EBP + -0x34) = bVar1 & 6;
              do {
                if ((int)(short)piVar13[0x13] == *(int *)(unaff_EBP + -0x34)) break;
                (**(code **)(*piVar13 + 0x4c))(1);
                *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + 1;
              } while (*(int *)(unaff_EBP + -0x1c) < 4);
            }
          }
        }
        if ((*(short *)(piVar13[0x46] + 0x12) == 2) &&
           (((iVar10 = FUN_006359f2(piVar13,0,&cXObject::RTTI_Type_Descriptor,
                                    &cXPerson::RTTI_Type_Descriptor,0),
             (*(byte *)(iVar10 + 0x634) & 1) == 1 || ((*(byte *)(iVar10 + 0x614) & 1) == 1)) ||
            (((*(byte *)(iVar10 + 0x620) >> 1 & 1) != 0 || ((*(byte *)(iVar10 + 0x620) & 1) != 0))))
           )) {
          FUN_00458278(1);
          FUN_004cee86(0x20000000);
        }
        if (*(char *)(unaff_EBP + -0x15) != '\0') {
          iVar10 = piVar13[0x46];
          *(undefined4 *)(unaff_EBP + -0x20) = 0;
          if (*(short *)(iVar10 + 0x14) != 0) {
            iVar10 = FUN_006359f2(piVar13,0,&cXObject::RTTI_Type_Descriptor,
                                  &cXMTObject::RTTI_Type_Descriptor,0);
            *(int *)(unaff_EBP + -0x20) = iVar10;
            if ((iVar10 != 0) && (cVar2 = FUN_00423481(), cVar2 != '\0')) {
              *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffff8 | 8;
              *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) & 0xfffffff8 | 8;
            }
          }
          cVar2 = (**(code **)(*piVar13 + 0x54))
                            (unaff_EBP + -0x14,uVar11,*(undefined4 *)(unaff_EBP + -0x24),
                             *(undefined4 *)(unaff_EBP + -0x2c));
          if (cVar2 == '\0') {
            FUN_0044127f(*(undefined4 *)(unaff_EBP + -0x28));
            goto LAB_0044e7e8;
          }
          (**(code **)(*piVar13 + 0x58))
                    (unaff_EBP + -0x14,uVar11,*(undefined4 *)(unaff_EBP + -0x24),
                     *(undefined4 *)(unaff_EBP + -0x2c),1);
          if ((*(int *)(unaff_EBP + -0x20) != 0) && (cVar2 = FUN_00423481(), cVar2 != '\0')) {
            FUN_00423621();
          }
        }
        if ((((*(byte *)(*(int *)(unaff_EBP + 0xc) + 5) & 4) != 0) &&
            (iVar10 = FUN_006359f2(piVar13,0,&cXObject::RTTI_Type_Descriptor,
                                   &cXPerson::RTTI_Type_Descriptor,0), iVar10 != 0)) &&
           (*(short *)(iVar10 + 0x5cc) != 0)) {
          *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(*(int *)(iVar10 + 0x11c) + 0xc);
          FUN_0046f824(unaff_EBP + -0x94,0,0x40);
          *(undefined ***)(unaff_EBP + -0xa0) = &PTR_FUN_0066651c;
          FUN_0046f847(s_init_visitor_006c4110,0xffffffff);
          uVar11 = FUN_00402246(unaff_EBP + -0xa0);
          if ((short)uVar11 != 0) {
            FUN_00474c68(*(undefined4 *)(unaff_EBP + -0x1c),*(undefined2 *)(iVar10 + 0xf0),uVar11,0)
            ;
          }
        }
        uVar8 = (uint)*(char *)(*(int *)(unaff_EBP + 0xc) + 5);
        if ((uVar8 >> 1 & 1) == 0) {
          if ((((uVar8 >> 4 & 1) != 0) && (sVar4 = FUN_00475126(), 0 < sVar4)) &&
             (iVar10 = FUN_00475115(0), iVar10 != 0)) {
            puVar12 = (undefined2 *)FUN_004752f8();
            *puVar12 = *(undefined2 *)(extraout_ECX + 0x3a);
          }
        }
        else {
          if ((uVar8 >> 4 & 1) != 0) {
            *(undefined4 *)(unaff_EBP + 0xc) = 0x36;
                    /* WARNING: Subroutine does not return */
            __CxxThrowException_8(unaff_EBP + 0xc,&DAT_00698f30);
          }
          sVar4 = FUN_00475126();
          if ((0 < sVar4) && (iVar10 = FUN_00475115(0), iVar10 != 0)) {
            uVar3 = *(undefined2 *)(extraout_ECX + 0xf0);
            puVar12 = (undefined2 *)FUN_004752f8();
            *puVar12 = uVar3;
            *(undefined2 *)(iVar10 + 4) = *(undefined2 *)(*(int *)(unaff_EBP + 8) + 4);
          }
        }
        *(undefined2 *)(*(int *)(unaff_EBP + 8) + 4) = *(undefined2 *)(unaff_EBP + -0x28);
        uVar11 = 1;
        goto LAB_0044e95d;
      }
    }
  }
LAB_0044e7e8:
  uVar11 = 0;
LAB_0044e95d:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar11;
}

