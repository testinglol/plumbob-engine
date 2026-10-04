
void __fastcall
FUN_0049911a(int param_1,int param_2,int param_3,int param_4,int param_5,ushort *param_6,int param_7
            ,int param_8,byte param_9)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  ushort *puVar5;
  undefined2 *puVar6;
  ushort *puVar7;
  undefined2 *puVar8;
  int iVar9;
  ushort *puVar10;
  int local_8;
  
  iVar4 = (int)param_6;
  iVar3 = param_5;
  iVar9 = param_4;
  if ((param_9 < 8) || (0xf7 < param_9)) {
    if (param_9 < 0xf8) {
      if (param_8 != 0) {
        puVar6 = (undefined2 *)((param_8 + -1) * param_5 + param_2);
        param_1 = (param_8 + -1) * param_4 + param_1;
        _param_9 = param_8;
        do {
          if (param_7 != 0) {
            param_4 = param_7;
            puVar8 = puVar6;
            do {
              *(undefined2 *)((param_1 - (int)puVar6) + (int)puVar8) = *puVar8;
              puVar8 = puVar8 + 1;
              param_4 = param_4 + -1;
            } while (param_4 != 0);
          }
          _param_9 = _param_9 + -1;
          param_1 = param_1 - iVar9;
          puVar6 = (undefined2 *)((int)puVar6 - param_5);
        } while (_param_9 != 0);
      }
    }
    else if (param_8 != 0) {
      puVar6 = (undefined2 *)((param_8 + -1) * (int)param_6 + param_3);
      param_1 = (param_8 + -1) * param_4 + param_1;
      _param_9 = param_8;
      do {
        if (param_7 != 0) {
          param_4 = param_7;
          puVar8 = puVar6;
          do {
            *(undefined2 *)((param_1 - (int)puVar6) + (int)puVar8) = *puVar8;
            puVar8 = puVar8 + 1;
            param_4 = param_4 + -1;
          } while (param_4 != 0);
        }
        _param_9 = _param_9 + -1;
        param_1 = param_1 - iVar9;
        puVar6 = (undefined2 *)((int)puVar6 - (int)param_6);
      } while (_param_9 != 0);
    }
  }
  else {
    iVar9 = param_8 + -1;
    if (param_8 != 0) {
      puVar5 = (ushort *)(iVar9 * param_5 + param_2);
      param_3 = iVar9 * (int)param_6 + param_3;
      puVar10 = (ushort *)(iVar9 * param_4 + param_1);
      param_5 = param_8;
      do {
        if (param_7 != 0) {
          iVar9 = (uint)(param_9 >> 3) * 0x20;
          local_8 = param_7;
          puVar7 = puVar5;
          param_6 = puVar10;
          do {
            uVar1 = *(ushort *)((param_3 - (int)puVar5) + (int)puVar7);
            uVar2 = *puVar7;
            puVar7 = puVar7 + 1;
            local_8 = local_8 + -1;
            *param_6 = ((ushort)(byte)(&DAT_006e5e5c)
                                      [(uVar2 >> 6 & 0x1f) + ((uVar1 >> 6 & 0x1f) + iVar9) * 0x20] |
                       (ushort)(byte)(&DAT_006e5e5c)
                                     [(uint)(uVar2 >> 0xb) + ((uint)(uVar1 >> 0xb) + iVar9) * 0x20]
                       << 5) << 6 |
                       (ushort)(byte)(&DAT_006e5e5c)
                                     [(uVar2 & 0x1f) + ((uVar1 & 0x1f) + iVar9) * 0x20];
            param_6 = param_6 + 1;
          } while (local_8 != 0);
        }
        param_5 = param_5 + -1;
        puVar10 = (ushort *)((int)puVar10 - param_4);
        param_3 = param_3 - iVar4;
        puVar5 = (ushort *)((int)puVar5 - iVar3);
      } while (param_5 != 0);
    }
  }
  return;
}

