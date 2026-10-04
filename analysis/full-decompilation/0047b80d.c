
void FUN_0047b80d(int param_1,byte param_2,undefined1 param_3,byte param_4,char param_5)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  bool bVar5;
  ushort uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  byte *pbVar10;
  ushort uVar11;
  int iVar12;
  
  _param_4 = (int)((uint)param_4 * *(int *)(param_1 + 4) * *(int *)(param_1 + 8)) / 100;
  if (0 < _param_4) {
    do {
      uVar2 = *(uint *)(param_1 + 8);
      uVar7 = FUN_0046f556();
      uVar3 = *(uint *)(param_1 + 4);
      uVar8 = FUN_0046f556();
      _param_4 = _param_4 + -1;
      *(undefined1 *)(*(int *)(*(int *)(param_1 + 0xc) + (uVar7 % uVar2) * 4) + uVar8 % uVar3) =
           param_3;
    } while (_param_4 != 0);
  }
  if (param_5 != '\0') {
    iVar9 = (byte)(param_5 - 1) + 1;
    do {
      _param_3 = 0;
      if (0 < *(int *)(param_1 + 8)) {
        do {
          iVar12 = 0;
          if (0 < *(int *)(param_1 + 4)) {
            do {
              piVar1 = (int *)(*(int *)(param_1 + 0xc) + _param_3 * 4);
              pbVar10 = (byte *)(*piVar1 + iVar12);
              uVar11 = (ushort)*pbVar10;
              bVar5 = _param_3 < *(int *)(param_1 + 8) + -1;
              if (bVar5) {
                uVar11 = uVar11 + *(byte *)(*(int *)(*(int *)(param_1 + 0xc) + 4 + _param_3 * 4) +
                                           iVar12);
              }
              uVar6 = (ushort)bVar5;
              if (iVar12 < *(int *)(param_1 + 4) + -1) {
                uVar11 = uVar11 + pbVar10[1];
                uVar6 = uVar6 + 1;
              }
              if (0 < _param_3) {
                uVar11 = uVar11 + *(byte *)(piVar1[-1] + iVar12);
                uVar6 = uVar6 + 1;
              }
              if (0 < iVar12) {
                uVar11 = uVar11 + pbVar10[-1];
                uVar6 = uVar6 + 1;
              }
              iVar12 = iVar12 + 1;
              *pbVar10 = (byte)(uVar11 / uVar6);
            } while (iVar12 < *(int *)(param_1 + 4));
          }
          _param_3 = _param_3 + 1;
        } while (_param_3 < *(int *)(param_1 + 8));
      }
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
  }
  iVar9 = 0;
  _param_3 = 0;
  if (0 < *(int *)(param_1 + 8)) {
    do {
      iVar12 = 0;
      if (0 < *(int *)(param_1 + 4)) {
        do {
          iVar4 = *(int *)(*(int *)(param_1 + 0xc) + iVar9);
          if (param_2 < *(byte *)(iVar4 + iVar12)) {
            *(byte *)(iVar4 + iVar12) = param_2;
          }
          iVar12 = iVar12 + 1;
        } while (iVar12 < *(int *)(param_1 + 4));
      }
      _param_3 = _param_3 + 1;
      iVar9 = iVar9 + 4;
    } while (_param_3 < *(int *)(param_1 + 8));
  }
  return;
}

