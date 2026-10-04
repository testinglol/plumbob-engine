
void FUN_005bdaad(void)

{
  undefined1 uVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  undefined1 *puVar5;
  int iVar6;
  int *extraout_ECX;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint _Size;
  int unaff_EBP;
  undefined4 *puVar10;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  _Size = *(uint *)(unaff_EBP + 0xc);
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffe8;
  if (_Size != 0) {
    iVar8 = extraout_ECX[1];
    if ((uint)(extraout_ECX[2] - iVar8) < _Size) {
      uVar7 = iVar8 - *extraout_ECX;
      piVar4 = (int *)(unaff_EBP + 0xc);
      *(uint *)(unaff_EBP + -0x18) = uVar7;
      if (_Size <= uVar7) {
        piVar4 = (int *)(unaff_EBP + -0x18);
      }
      iVar8 = *piVar4 + uVar7;
      *(int *)(unaff_EBP + 0xc) = iVar8;
      if (iVar8 == 0) {
        iVar8 = 0;
      }
      else {
        iVar8 = FUN_00401742(iVar8);
      }
      iVar3 = *extraout_ECX;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      *(int *)(unaff_EBP + -0x14) = iVar8;
      puVar5 = (undefined1 *)
               FUN_004746d5(iVar3,*(undefined4 *)(unaff_EBP + 8),iVar8,
                            *(undefined4 *)(unaff_EBP + 8),0);
      for (; _Size != 0; _Size = _Size - 1) {
        *puVar5 = **(undefined1 **)(unaff_EBP + 0x10);
        puVar5 = puVar5 + 1;
      }
      iVar3 = FUN_004746d5(*(undefined4 *)(unaff_EBP + 8),extraout_ECX[1],puVar5,
                           *(undefined4 *)(unaff_EBP + 8),0);
      iVar6 = extraout_ECX[2] - *extraout_ECX;
      if (iVar6 != 0) {
        FUN_0040189d(*extraout_ECX,iVar6);
      }
      iVar6 = *(int *)(unaff_EBP + 0xc);
      *extraout_ECX = iVar8;
      extraout_ECX[1] = iVar3;
      extraout_ECX[2] = iVar8 + iVar6;
    }
    else {
      uVar7 = iVar8 - *(int *)(unaff_EBP + 8);
      puVar10 = (undefined4 *)extraout_ECX[1];
      uVar1 = **(undefined1 **)(unaff_EBP + 0x10);
      *(undefined1 *)(unaff_EBP + 0x13) = uVar1;
      *(uint *)(unaff_EBP + -0x14) = uVar7;
      *(undefined4 **)(unaff_EBP + -0x18) = puVar10;
      if (_Size < uVar7) {
        *(undefined4 **)(unaff_EBP + 0xc) = puVar10;
        *(int *)(unaff_EBP + 0xc) = *(int *)(unaff_EBP + 0xc) - _Size;
        FUN_004746d5(*(undefined4 *)(unaff_EBP + 0xc),puVar10,puVar10,*(undefined4 *)(unaff_EBP + 8)
                     ,0);
        iVar8 = *(int *)(unaff_EBP + 0xc);
        extraout_ECX[1] = extraout_ECX[1] + _Size;
        iVar3 = iVar8 - *(int *)(unaff_EBP + 8);
        if (0 < iVar3) {
          iVar8 = iVar8 - (int)puVar10;
          do {
            puVar5 = (undefined1 *)(iVar8 + -1 + (int)puVar10);
            puVar10 = (undefined4 *)((int)puVar10 + -1);
            iVar3 = iVar3 + -1;
            *(undefined1 *)puVar10 = *puVar5;
          } while (iVar3 != 0);
        }
        _memset(*(void **)(unaff_EBP + 8),(uint)*(byte *)(unaff_EBP + 0x13),_Size);
      }
      else {
        uVar7 = _Size - *(int *)(unaff_EBP + -0x14);
        if (uVar7 != 0) {
          _Size = *(uint *)(unaff_EBP + 0xc);
          for (uVar9 = uVar7 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
            *puVar10 = CONCAT22(CONCAT11(uVar1,uVar1),CONCAT11(uVar1,uVar1));
            puVar10 = puVar10 + 1;
          }
          for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
            *(undefined1 *)puVar10 = uVar1;
            puVar10 = (undefined4 *)((int)puVar10 + 1);
          }
          puVar10 = *(undefined4 **)(unaff_EBP + -0x18);
        }
        uVar2 = *(undefined4 *)(unaff_EBP + 8);
        extraout_ECX[1] = extraout_ECX[1] + (_Size - *(int *)(unaff_EBP + -0x14));
        FUN_004746d5(*(undefined4 *)(unaff_EBP + 8),puVar10,extraout_ECX[1],uVar2,0);
        iVar8 = *(int *)(unaff_EBP + 8);
        extraout_ECX[1] = extraout_ECX[1] + *(int *)(unaff_EBP + -0x14);
        _memset(*(void **)(unaff_EBP + 8),(uint)*(byte *)(unaff_EBP + 0x13),(int)puVar10 - iVar8);
      }
    }
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

