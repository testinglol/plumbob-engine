
bool FUN_0044cd6b(void)

{
  byte bVar1;
  byte *pbVar2;
  char cVar3;
  int iVar4;
  int extraout_ECX;
  int iVar5;
  int *piVar6;
  int unaff_EBP;
  uint uVar7;
  undefined4 uVar8;
  undefined1 *puVar9;
  int iVar10;
  
  FUN_00634c24();
  pbVar2 = *(byte **)(unaff_EBP + 0xc);
  bVar1 = pbVar2[3];
  uVar7 = (uint)pbVar2[1];
  *(int *)(unaff_EBP + -0x14) = extraout_ECX;
  if ((bVar1 & 2) == 0) {
    if (*(byte *)(*(int *)(unaff_EBP + 8) + 7) < uVar7) {
      *(undefined4 *)(unaff_EBP + 8) = 8;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(unaff_EBP + 8,&DAT_00698f30);
    }
    iVar4 = FUN_004752f8();
  }
  else {
    if (*(byte *)(*(int *)(unaff_EBP + 8) + 6) < uVar7) {
      *(undefined4 *)(unaff_EBP + 8) = 0x33;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(unaff_EBP + 8,&DAT_00698f30);
    }
    iVar4 = FUN_004752fc();
  }
  uVar7 = (uint)*(short *)(iVar4 + uVar7 * 2);
  iVar4 = *(int *)(extraout_ECX + 0xdc);
  if ((((int)uVar7 < 1) || ((*(int *)(iVar4 + 0x1c) - *(int *)(iVar4 + 0x18) >> 2) + 1U <= uVar7))
     || (iVar4 = *(int *)(*(int *)(iVar4 + 0x18) + -4 + uVar7 * 4),
        *(int *)(unaff_EBP + -0x20) = iVar4, iVar4 == 0)) {
    *(undefined4 *)(unaff_EBP + 8) = 0x17;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(unaff_EBP + 8,&DAT_00698f30);
  }
  iVar4 = FUN_00457e1c();
  if (iVar4 == 0) {
    *(undefined4 *)(unaff_EBP + 8) = 0x1f;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(unaff_EBP + 8,&DAT_00698f30);
  }
  piVar6 = *(int **)(iVar4 + 0x10);
  if (piVar6 != (int *)0x0) {
    iVar10 = 0;
    if (0 < *(int *)(iVar4 + 4)) {
      do {
        iVar5 = *piVar6;
        if (*(uint *)(iVar5 + 0x18) == (uint)*pbVar2) goto LAB_0044ce4d;
        iVar10 = iVar10 + 1;
        piVar6 = piVar6 + 1;
      } while (iVar10 < *(int *)(iVar4 + 4));
    }
  }
  iVar5 = 0;
LAB_0044ce4d:
  if (iVar5 == 0) {
    *(undefined4 *)(unaff_EBP + 8) = 0x16;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(unaff_EBP + 8,&DAT_00698f30);
  }
  uVar7 = (uint)*(short *)(*(int *)(unaff_EBP + 8) + 4);
  iVar4 = *(int *)(*(int *)(unaff_EBP + -0x14) + 0xdc);
  if (((0 < (int)uVar7) && (uVar7 < (*(int *)(iVar4 + 0x1c) - *(int *)(iVar4 + 0x18) >> 2) + 1U)) &&
     (iVar4 = *(int *)(*(int *)(iVar4 + 0x18) + -4 + uVar7 * 4), iVar4 != 0)) {
    iVar10 = FUN_006359f2(iVar4,0,&cXObject::RTTI_Type_Descriptor,&cXPerson::RTTI_Type_Descriptor,0)
    ;
    iVar4 = *(int *)(iVar4 + 0x118);
    *(int *)(unaff_EBP + -0x18) = iVar10;
    if ((*(short *)(iVar4 + 0x12) == 2) && (iVar10 != 0)) {
      puVar9 = *(undefined1 **)(unaff_EBP + 0xc);
      *(undefined4 *)(unaff_EBP + -0x10) = 1;
      cVar3 = puVar9[2];
      if (cVar3 == '\0') {
        if ((*(short *)(*(int *)(*(int *)(unaff_EBP + -0x14) + 0x118) + 0x12) == 2) &&
           (iVar4 = FUN_006359f2(*(int *)(unaff_EBP + -0x14),0,&cXObject::RTTI_Type_Descriptor,
                                 &cXPerson::RTTI_Type_Descriptor,0), iVar4 != 0)) {
          *(int *)(unaff_EBP + -0x10) = (int)*(short *)(iVar4 + 0x5ce);
        }
      }
      else if (cVar3 == '\x01') {
        *(undefined4 *)(unaff_EBP + -0x10) = 100;
      }
      else if (cVar3 == '\x02') {
        *(undefined4 *)(unaff_EBP + -0x10) = 2;
      }
      else {
        if (cVar3 != '\x03') {
          *(undefined4 *)(unaff_EBP + -0x1c) = 0x2d;
                    /* WARNING: Subroutine does not return */
          __CxxThrowException_8(unaff_EBP + -0x1c,&DAT_00698f30);
        }
        *(undefined4 *)(unaff_EBP + -0x10) = 0x32;
      }
      FUN_0041f010(*(undefined4 *)(unaff_EBP + -0x18),*(undefined4 *)(unaff_EBP + -0x20),*puVar9,
                   *(undefined4 *)(unaff_EBP + -0x10));
      bVar1 = puVar9[3];
      *(undefined4 *)(unaff_EBP + -4) = 0;
      *(uint *)(unaff_EBP + -0x24) = *(uint *)(unaff_EBP + -0x24) & 0xffffffbf;
      if ((bVar1 >> 3 & 1) != 0) {
        *(uint *)(unaff_EBP + -0x24) = *(uint *)(unaff_EBP + -0x24) | 0x40;
      }
      if ((bVar1 & 1) != 0) {
        bVar1 = puVar9[4];
        if ((uint)*(byte *)(*(int *)(unaff_EBP + 8) + 6) <= (uint)bVar1) {
          *(undefined4 *)(unaff_EBP + 8) = 0x33;
                    /* WARNING: Subroutine does not return */
          __CxxThrowException_8(unaff_EBP + 8,&DAT_00698f30);
        }
        iVar4 = FUN_004752fc();
        uVar7 = (uint)*(short *)(iVar4 + (uint)bVar1 * 2);
        uVar8 = 0;
        iVar4 = *(int *)(*(int *)(unaff_EBP + -0x14) + 0xdc);
        if ((0 < (int)uVar7) &&
           (uVar7 < (*(int *)(iVar4 + 0x1c) - *(int *)(iVar4 + 0x18) >> 2) + 1U)) {
          uVar8 = *(undefined4 *)(*(int *)(iVar4 + 0x18) + -4 + uVar7 * 4);
        }
        *(undefined4 *)(unaff_EBP + -0x58) = uVar8;
        puVar9 = *(undefined1 **)(unaff_EBP + 0xc);
      }
      bVar1 = puVar9[3];
      *(uint *)(unaff_EBP + -0x24) = *(uint *)(unaff_EBP + -0x24) & 0xfffffffd;
      if ((bVar1 >> 2 & 1) != 0) {
        *(uint *)(unaff_EBP + -0x24) = *(uint *)(unaff_EBP + -0x24) | 2;
      }
      cVar3 = FUN_0045d377(unaff_EBP + -100);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
      ExceptionList = *(void **)(unaff_EBP + -0xc);
      return cVar3 != '\0';
    }
    *(undefined4 *)(unaff_EBP + 8) = 0x1c;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(unaff_EBP + 8,&DAT_00698f30);
  }
  *(undefined4 *)(unaff_EBP + 0xc) = 0x15;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(unaff_EBP + 0xc,&DAT_00698f30);
}

