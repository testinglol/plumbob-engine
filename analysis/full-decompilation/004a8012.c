
void __thiscall FUN_004a8012(int *param_1,int param_2,char param_3,char param_4)

{
  ushort uVar1;
  int iVar2;
  char cVar3;
  undefined1 uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  int *piVar8;
  uint uVar9;
  int iVar10;
  undefined1 local_18 [8];
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  if ((*(int *)(DAT_006e54d8 + 0x84) != param_2) || (param_3 != '\0')) {
    if (DAT_006e4870 != '\0') {
      if (*(char *)((int)param_1 + 0x17a) == '\0') {
        iVar5 = param_1[0x5c] + DAT_006f0080;
        local_8 = param_1[0x5d] + DAT_006f0084;
      }
      else {
        iVar5 = FUN_004c9d30();
        local_8 = FUN_004c9d53();
      }
      FUN_004b0542();
      param_1[0x5c] = 0;
      param_1[0x5d] = 0;
      FUN_004a83dc(iVar5,local_8,1);
    }
    FUN_004a7d6c(&local_10);
    uVar6 = FUN_00433116(&local_10,1);
    cVar3 = FUN_00434d5c(uVar6);
    if (cVar3 != '\0') {
      uVar9 = local_8 >> 0x10;
      uVar4 = (undefined1)(*(int *)(DAT_006e54d8 + 0x10) / 4);
      local_8._0_2_ = CONCAT11(uVar4,uVar4);
      local_8 = CONCAT22((short)uVar9,(undefined2)local_8) & 0xff00ffff;
      FUN_004a8000(&local_8);
      puVar7 = (undefined4 *)FUN_00434d3d(local_18);
      local_10 = *puVar7;
      local_c = puVar7[1];
    }
    FUN_0047bd91(&local_c,&local_10,-*(int *)(DAT_006e54d8 + 0x84) & 3,0x400);
    local_8 = DAT_006f008c;
    DAT_006f008c = param_2;
    FUN_00479318(param_2,0);
    FUN_004b0824();
    FUN_0047bd91(&local_c,&local_10,*(undefined4 *)(DAT_006e54d8 + 0x84),0x400);
    FUN_004a7baa(local_10,local_c,param_1[6],0,1);
    iVar10 = param_1[0x5d] + DAT_006f0084;
    iVar5 = param_1[0x5c] + DAT_006f0080;
    param_1[0x5c] = 0;
    param_1[0x5d] = 0;
    FUN_004a83dc(iVar5,iVar10,1);
    FUN_004b1de9();
    if (DAT_006f6b5c != (int *)0x0) {
      piVar8 = (int *)(**(code **)(*DAT_006f6b5c + 0x2c))();
      if (piVar8 != (int *)0x0) {
        (**(code **)(*piVar8 + 0xa4))(0);
      }
    }
    (**(code **)(*param_1 + 0x48))();
    FUN_0040766a(0x84,0);
    FUN_004a7d36();
    FUN_004b1891();
    if (param_1[7] != 0) {
      FUN_004ca03f(param_1[0x15],DAT_006f0088);
    }
    FUN_00466fe4(param_1[6]);
    if (*(char *)((int)param_1 + 0x49) != '\0') {
      FUN_004abb9e((char)param_1[0x7e]);
    }
    if (param_4 != '\0') {
      FUN_0043e0a9();
    }
    (**(code **)(*DAT_006fe8bc + 0x18))();
    FUN_005db0b7();
    if (param_3 == '\0') {
      uVar9 = FUN_00636bef(local_8 - DAT_006f008c);
      if ((uVar9 & 1) != 0) {
        _param_3 = 0;
        iVar5 = *(int *)(DAT_006e54dc + 0x10);
        if (0 < iVar5) {
          do {
            iVar10 = 0;
            do {
              iVar2 = *(int *)(*(int *)(*(int *)(DAT_006e54dc + 0x24) + 0xc) + (char)iVar10 * 4);
              uVar1 = *(ushort *)(iVar2 + param_3 * 2);
              if ((uVar1 == 10) || (uVar1 == 0xb)) {
                *(ushort *)(param_3 * 2 + iVar2) = uVar1 ^ 1;
              }
              iVar10 = iVar10 + 1;
            } while (iVar10 < iVar5);
            _param_3 = _param_3 + 1;
          } while (_param_3 < iVar5);
        }
      }
    }
    FUN_0057ac7f();
  }
  return;
}

