
void FUN_004744ca(void)

{
  undefined1 uVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  undefined1 *puVar5;
  int iVar6;
  int iVar7;
  int *extraout_ECX;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint _Size;
  int unaff_EBP;
  undefined4 *puVar11;
  
  FUN_00634c24();
  _Size = *(uint *)(unaff_EBP + 0xc);
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffe8;
  if (_Size != 0) {
    iVar9 = extraout_ECX[1];
    if ((uint)(extraout_ECX[2] - iVar9) < _Size) {
      uVar8 = iVar9 - *extraout_ECX;
      piVar4 = (int *)(unaff_EBP + 0xc);
      *(uint *)(unaff_EBP + -0x18) = uVar8;
      if (_Size <= uVar8) {
        piVar4 = (int *)(unaff_EBP + -0x18);
      }
      iVar9 = *piVar4 + uVar8;
      *(int *)(unaff_EBP + 0xc) = iVar9;
      if (iVar9 == 0) {
        iVar9 = 0;
      }
      else {
        iVar9 = FUN_00401742(iVar9);
      }
      iVar3 = *extraout_ECX;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      *(int *)(unaff_EBP + -0x14) = iVar9;
      puVar5 = (undefined1 *)
               FUN_004746d5(iVar3,*(undefined4 *)(unaff_EBP + 8),iVar9,
                            *(undefined4 *)(unaff_EBP + 8),0);
      for (; _Size != 0; _Size = _Size - 1) {
        *puVar5 = **(undefined1 **)(unaff_EBP + 0x10);
        puVar5 = puVar5 + 1;
      }
      iVar6 = FUN_004746d5(*(undefined4 *)(unaff_EBP + 8),extraout_ECX[1],puVar5,
                           *(undefined4 *)(unaff_EBP + 8),0);
      iVar3 = *extraout_ECX;
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      iVar7 = extraout_ECX[2] - iVar3;
      if (iVar7 != 0) {
        FUN_0040189d(iVar3,iVar7);
      }
      iVar3 = *(int *)(unaff_EBP + 0xc);
      *extraout_ECX = iVar9;
      extraout_ECX[1] = iVar6;
      extraout_ECX[2] = iVar9 + iVar3;
    }
    else {
      uVar8 = iVar9 - *(int *)(unaff_EBP + 8);
      puVar11 = (undefined4 *)extraout_ECX[1];
      uVar1 = **(undefined1 **)(unaff_EBP + 0x10);
      *(undefined1 *)(unaff_EBP + 0x13) = uVar1;
      *(uint *)(unaff_EBP + -0x14) = uVar8;
      *(undefined4 **)(unaff_EBP + -0x18) = puVar11;
      if (_Size < uVar8) {
        *(undefined4 **)(unaff_EBP + 0xc) = puVar11;
        *(int *)(unaff_EBP + 0xc) = *(int *)(unaff_EBP + 0xc) - _Size;
        FUN_004746d5(*(undefined4 *)(unaff_EBP + 0xc),puVar11,puVar11,*(undefined4 *)(unaff_EBP + 8)
                     ,0);
        iVar9 = *(int *)(unaff_EBP + 0xc);
        extraout_ECX[1] = extraout_ECX[1] + _Size;
        iVar3 = iVar9 - *(int *)(unaff_EBP + 8);
        if (0 < iVar3) {
          iVar9 = iVar9 - (int)puVar11;
          do {
            puVar5 = (undefined1 *)(iVar9 + -1 + (int)puVar11);
            puVar11 = (undefined4 *)((int)puVar11 + -1);
            iVar3 = iVar3 + -1;
            *(undefined1 *)puVar11 = *puVar5;
          } while (iVar3 != 0);
        }
        _memset(*(void **)(unaff_EBP + 8),(uint)*(byte *)(unaff_EBP + 0x13),_Size);
      }
      else {
        uVar8 = _Size - *(int *)(unaff_EBP + -0x14);
        if (uVar8 != 0) {
          _Size = *(uint *)(unaff_EBP + 0xc);
          for (uVar10 = uVar8 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
            *puVar11 = CONCAT22(CONCAT11(uVar1,uVar1),CONCAT11(uVar1,uVar1));
            puVar11 = puVar11 + 1;
          }
          for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
            *(undefined1 *)puVar11 = uVar1;
            puVar11 = (undefined4 *)((int)puVar11 + 1);
          }
          puVar11 = *(undefined4 **)(unaff_EBP + -0x18);
        }
        uVar2 = *(undefined4 *)(unaff_EBP + 8);
        extraout_ECX[1] = extraout_ECX[1] + (_Size - *(int *)(unaff_EBP + -0x14));
        FUN_004746d5(*(undefined4 *)(unaff_EBP + 8),puVar11,extraout_ECX[1],uVar2,0);
        iVar9 = *(int *)(unaff_EBP + 8);
        extraout_ECX[1] = extraout_ECX[1] + *(int *)(unaff_EBP + -0x14);
        _memset(*(void **)(unaff_EBP + 8),(uint)*(byte *)(unaff_EBP + 0x13),(int)puVar11 - iVar9);
      }
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

