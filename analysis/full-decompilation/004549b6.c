
undefined4 FUN_004549b6(void)

{
  float fVar1;
  byte bVar2;
  short sVar3;
  short *psVar4;
  uint uVar5;
  byte bVar6;
  char cVar7;
  int iVar8;
  int *piVar9;
  undefined4 *puVar10;
  undefined4 uVar11;
  int extraout_ECX;
  int iVar12;
  int unaff_EBP;
  int iVar13;
  uint uVar14;
  
  FUN_00634c24();
  iVar13 = *(int *)(unaff_EBP + 8);
  sVar3 = *(short *)(iVar13 + 4);
  *(int *)(unaff_EBP + -0x18) = extraout_ECX;
  iVar8 = FUN_00407498((int)sVar3);
  if (iVar8 == 0) {
    *(undefined4 *)(unaff_EBP + 0xc) = 0x15;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(unaff_EBP + 0xc,&DAT_00698f30);
  }
  psVar4 = *(short **)(unaff_EBP + 0xc);
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  sVar3 = psVar4[1];
  iVar12 = extraout_ECX;
  if (sVar3 == 2) {
    uVar11 = *(undefined4 *)(iVar8 + 0xf4);
    *(undefined1 *)(unaff_EBP + -0x30) = 0;
    *(undefined4 *)(unaff_EBP + -0x14) = uVar11;
    *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(iVar8 + 0xf8);
    uVar14 = (uint)*(short *)(extraout_ECX + 0x4c);
    *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(iVar8 + 0x110);
    sVar3 = *(short *)(iVar8 + 0x4c);
    *(undefined4 *)(unaff_EBP + 8) = 0;
    *(undefined4 *)(unaff_EBP + -0x24) = 0;
    piVar9 = (int *)FUN_004222bd((int)sVar3);
    *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + piVar9[1];
    *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + *piVar9;
  }
  else if (sVar3 == 1) {
    uVar11 = *(undefined4 *)(iVar8 + 0xf4);
    *(undefined1 *)(unaff_EBP + -0x30) = 0;
    uVar14 = (uint)*(short *)(extraout_ECX + 0x4c);
    *(undefined4 *)(unaff_EBP + -0x14) = uVar11;
    *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(iVar8 + 0xf8);
    *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(iVar8 + 0x110);
    *(int *)(unaff_EBP + 8) = iVar8;
    *(undefined4 *)(unaff_EBP + -0x24) = 0;
  }
  else {
    if (sVar3 == 0) {
      if ((*psVar4 < 0) || ((short)(ushort)*(byte *)(iVar13 + 7) <= *psVar4)) {
        *(undefined4 *)(unaff_EBP + 0xc) = 8;
                    /* WARNING: Subroutine does not return */
        __CxxThrowException_8(unaff_EBP + 0xc,&DAT_00698f30);
      }
      iVar13 = FUN_004752f8();
      sVar3 = *(short *)(iVar13 + **(short **)(unaff_EBP + 0xc) * 2);
LAB_00454ab3:
      piVar9 = (int *)(iVar8 + 0x13c);
    }
    else {
      if (sVar3 == 3) {
        sVar3 = *psVar4;
        goto LAB_00454ab3;
      }
      if (sVar3 != 4) {
        *(undefined4 *)(unaff_EBP + 0xc) = 0x24;
                    /* WARNING: Subroutine does not return */
        __CxxThrowException_8(unaff_EBP + 0xc,&DAT_00698f30);
      }
      sVar3 = *psVar4;
      piVar9 = (int *)(*(int *)(iVar8 + 0xdc) + 0x9c);
    }
    uVar14 = (uint)sVar3;
    if (((int)uVar14 < 0) || (iVar13 = *piVar9, (uint)((piVar9[1] - iVar13) / 0x3c) <= uVar14)) {
      *(undefined4 *)(unaff_EBP + 0xc) = 0x1b;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(unaff_EBP + 0xc,&DAT_00698f30);
    }
    uVar5 = *(uint *)(uVar14 * 0x3c + 0x1c + iVar13);
    iVar13 = uVar14 * 0x3c + iVar13;
    if ((uVar5 & 0x1000) == 0) {
      uVar14 = (uint)*(short *)(*(int *)(unaff_EBP + -0x18) + 0x4c);
    }
    else {
      iVar12 = 0;
      do {
        if ((uVar5 & 1 << ((byte)iVar12 & 0x1f)) != 0) goto LAB_00454b43;
        iVar12 = iVar12 + 1;
      } while (iVar12 < 7);
      iVar12 = 0;
LAB_00454b43:
      uVar14 = *(short *)(iVar8 + 0x4c) + iVar12;
    }
    if (*(int *)(iVar13 + 0x20) < 0) {
      *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(iVar8 + 0xf4);
      *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(iVar8 + 0xf8);
      *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(iVar8 + 0x110);
      FUN_004550b0(unaff_EBP + -0xa0,(int)*(short *)(iVar8 + 0x4c));
      *(undefined4 *)(unaff_EBP + -4) = 0;
      *(undefined4 *)(unaff_EBP + 8) = 0;
      FUN_00454f9c(unaff_EBP + -0x3c,unaff_EBP + -0x14,unaff_EBP + 8);
      *(undefined4 *)(unaff_EBP + 8) = 0;
      FUN_00454f0c(unaff_EBP + -0x48,iVar13,iVar13 + 4,unaff_EBP + 8);
      puVar10 = (undefined4 *)FUN_005c3840(unaff_EBP + -0x5c,unaff_EBP + -0x48,unaff_EBP + -0xa0);
      *(undefined4 *)(unaff_EBP + -0x48) = *puVar10;
      fVar1 = (float)puVar10[1];
      *(float *)(unaff_EBP + -0x44) = fVar1;
      *(undefined4 *)(unaff_EBP + -0x40) = puVar10[2];
      *(float *)(unaff_EBP + -0x3c) = *(float *)(unaff_EBP + -0x48) + *(float *)(unaff_EBP + -0x3c);
      *(float *)(unaff_EBP + -0x38) = *(float *)(unaff_EBP + -0x38) + fVar1;
      *(float *)(unaff_EBP + -0x34) = *(float *)(unaff_EBP + -0x34) + *(float *)(unaff_EBP + -0x40);
      puVar10 = (undefined4 *)FUN_00454ff9(unaff_EBP + -0x58,unaff_EBP + -0x3c);
      uVar11 = *puVar10;
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      *(undefined4 *)(unaff_EBP + -0x14) = uVar11;
      *(undefined4 *)(unaff_EBP + -0x10) = puVar10[1];
      uVar5 = *(uint *)(iVar13 + 0x1c);
      *(undefined4 *)(unaff_EBP + 8) = 0;
      *(undefined4 *)(unaff_EBP + -0x24) = 0;
      *(byte *)(unaff_EBP + -0x30) = (byte)(uVar5 >> 0xb) & 1;
      FUN_005c4890();
    }
    else {
      if (*(int *)(iVar13 + 0x20) < (*(int *)(iVar8 + 0x134) - *(int *)(iVar8 + 0x130)) / 0x24 + -1)
      {
        iVar12 = *(int *)(iVar8 + 0x130) + (*(int *)(iVar13 + 0x20) * 9 + 9) * 4;
      }
      else {
        iVar12 = 0;
      }
      if (iVar12 == 0) {
        *(undefined4 *)(unaff_EBP + 0xc) = 0x20;
                    /* WARNING: Subroutine does not return */
        __CxxThrowException_8(unaff_EBP + 0xc,&DAT_00698f30);
      }
      uVar11 = *(undefined4 *)(iVar8 + 0xf4);
      *(int *)(unaff_EBP + 8) = iVar8;
      *(undefined4 *)(unaff_EBP + -0x14) = uVar11;
      *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(iVar8 + 0xf8);
      *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(iVar8 + 0x110);
      *(undefined4 *)(unaff_EBP + -0x24) = *(undefined4 *)(iVar13 + 0x20);
      *(byte *)(unaff_EBP + -0x30) = (byte)(*(uint *)(iVar13 + 0x1c) >> 0xb) & 1;
    }
    iVar12 = *(int *)(unaff_EBP + -0x18);
  }
  iVar13 = 0;
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  bVar2 = *(byte *)(*(int *)(unaff_EBP + 0xc) + 4);
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  *(undefined4 *)(unaff_EBP + -0x4c) = 0;
  if ((bVar2 & 1) != 0) {
    iVar13 = *(int *)(iVar12 + 0xf8) - *(int *)(unaff_EBP + -0x10);
    *(int *)(unaff_EBP + -0x18) = *(int *)(iVar12 + 0xf4) - *(int *)(unaff_EBP + -0x14);
    *(int *)(unaff_EBP + -0x1c) = iVar13;
    *(uint *)(unaff_EBP + -0x4c) = (int)*(short *)(iVar12 + 0x4c) - uVar14;
  }
  iVar8 = *(int *)(unaff_EBP + 8);
  if (iVar8 == 0) goto LAB_00454da1;
  if ((*(int *)(unaff_EBP + -0x24) < 0) ||
     ((*(int *)(iVar8 + 0x134) - *(int *)(iVar8 + 0x130)) / 0x24 + -1 <= *(int *)(unaff_EBP + -0x24)
     )) {
    puVar10 = (undefined4 *)0x0;
  }
  else {
    puVar10 = (undefined4 *)
              (*(int *)(*(int *)(unaff_EBP + 8) + 0x130) + (*(int *)(unaff_EBP + -0x24) * 9 + 9) * 4
              );
  }
  if (puVar10 == (undefined4 *)0x0) goto LAB_00454da1;
  *(undefined4 *)(unaff_EBP + -0x28) = *puVar10;
  *(undefined4 *)(unaff_EBP + -0x1c) = puVar10[1];
  bVar2 = *(byte *)(*(int *)(unaff_EBP + 8) + 0x4c);
  bVar6 = bVar2 & 7;
  *(undefined4 *)(unaff_EBP + -0x2c) = 0;
  if ((bVar2 & 7) == 0) {
    *(undefined4 *)(unaff_EBP + -0x2c) = *(undefined4 *)(unaff_EBP + -0x1c);
  }
  else if (bVar6 == 2) {
    *(undefined4 *)(unaff_EBP + -0x2c) = *(undefined4 *)(unaff_EBP + -0x28);
  }
  else {
    if (bVar6 == 4) {
      fVar1 = *(float *)(unaff_EBP + -0x1c);
    }
    else {
      if (bVar6 != 6) goto LAB_00454d8c;
      fVar1 = *(float *)(unaff_EBP + -0x28);
    }
    *(float *)(unaff_EBP + -0x2c) = -fVar1;
  }
LAB_00454d8c:
  iVar8 = __ftol();
  *(int *)(unaff_EBP + -0x1c) = iVar13 + iVar8;
  iVar13 = __ftol();
  *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + iVar13;
LAB_00454da1:
  DAT_006e4a7c = 0;
  DAT_006e4a80 = 0;
  *(byte *)(unaff_EBP + -0x28) = *(byte *)(*(int *)(unaff_EBP + 0xc) + 4) >> 2 & 1;
  uVar11 = FUN_004550e0(*(undefined4 *)(unaff_EBP + -0x14),*(undefined4 *)(unaff_EBP + -0x10),
                        *(undefined4 *)(unaff_EBP + -0x20),*(undefined4 *)(unaff_EBP + 8),
                        *(undefined4 *)(unaff_EBP + -0x24),*(undefined4 *)(unaff_EBP + -0x30),
                        uVar14 & 7,*(undefined4 *)(unaff_EBP + -0x28));
  *(undefined4 *)(unaff_EBP + 8) = uVar11;
  iVar8 = FUN_006359f2(iVar12,0,&cXObject::RTTI_Type_Descriptor,&cXPerson::RTTI_Type_Descriptor,0);
  iVar13 = *(int *)(unaff_EBP + 8);
  *(int *)(unaff_EBP + -0x20) = iVar8;
  *(undefined2 *)(iVar12 + 0xb2) = 0;
  if (iVar13 == 1) {
    if (iVar8 != 0) {
      (**(code **)(**(int **)(iVar8 + 0xadc) + 0x2c))
                ((float)*(int *)(unaff_EBP + -0x1c),(float)*(int *)(unaff_EBP + -0x18),
                 (float)*(int *)(unaff_EBP + -0x4c));
    }
  }
  else {
    if (((((iVar8 != 0) && ((*(byte *)(*(int *)(unaff_EBP + 0xc) + 4) >> 1 & 1) != 0)) &&
         (DAT_006e4a7c == 0xb)) &&
        ((DAT_006e4a80 != 0 && (*(short *)(*(int *)(DAT_006e4a80 + 0x118) + 0x12) == 2)))) &&
       ((iVar13 = FUN_006359f2(DAT_006e4a80,0,&cXObject::RTTI_Type_Descriptor,
                               &cXPerson::RTTI_Type_Descriptor,0), iVar13 != 0 &&
        (cVar7 = FUN_0045beca(*(undefined4 *)(*(int *)(unaff_EBP + -0x20) + 0xa64)), cVar7 != '\0'))
       )) {
      *(undefined2 *)(iVar12 + 0xb2) = 1;
    }
    if ((*(short *)(iVar12 + 0xb2) == 0) && (DAT_006e4a7c == 1)) {
      *(undefined2 *)(iVar12 + 0xb2) = 2;
    }
    if (DAT_006e4a80 == 0) {
      *(undefined2 *)(iVar12 + 0xb6) = 0;
    }
    else {
      *(undefined2 *)(iVar12 + 0xb6) = *(undefined2 *)(DAT_006e4a80 + 0xf0);
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + 8);
}

