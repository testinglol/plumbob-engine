
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_005ce101(int param_1,int *param_2)

{
  undefined4 *_Dst;
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  piVar2 = (int *)FUN_005d0135();
  puVar1 = (undefined4 *)(param_1 + 0xd8);
  iVar3 = (**(code **)(*piVar2 + 0x18))(piVar2,puVar1,0);
  *(int *)(param_1 + 0x5c) = iVar3;
  if (-1 < iVar3) {
    iVar3 = (*(code *)**(undefined4 **)*puVar1)((undefined4 *)*puVar1,&DAT_00677258,param_1 + 0xd4);
    *(int *)(param_1 + 0x5c) = iVar3;
    if (-1 < iVar3) {
      piVar2 = *(int **)(*(int *)(param_1 + 0x60) + 0x38);
      iVar3 = (**(code **)(*piVar2 + 0x14))(piVar2,*puVar1);
      *(int *)(param_1 + 0x5c) = iVar3;
      if (-1 < iVar3) {
        _Dst = (undefined4 *)(param_1 + 4);
        local_c = *(undefined4 *)(*(int *)(param_1 + 0x60) + 0x14);
        local_8 = *(undefined4 *)(*(int *)(param_1 + 0x60) + 0x18);
        _memset(_Dst,0,0x2c);
        *_Dst = 0x2c;
        if (param_2 == (int *)0x0) {
          *(undefined4 *)(param_1 + 0xc) = 0;
          *(undefined4 *)(param_1 + 8) = 0;
          *(undefined4 *)(param_1 + 0x10) = local_c;
          *(undefined4 *)(param_1 + 0x14) = local_8;
        }
        else {
          *(int *)(param_1 + 8) = *param_2;
          *(int *)(param_1 + 0xc) = param_2[1];
          *(int *)(param_1 + 0x10) = param_2[2] - *param_2;
          *(int *)(param_1 + 0x14) = param_2[3] - param_2[1];
        }
        FUN_005cf0bd();
        iVar3 = (**(code **)(*(int *)*puVar1 + 0x14))((int *)*puVar1,_Dst);
        *(int *)(param_1 + 0x5c) = iVar3;
        if (-1 < iVar3) {
          local_18 = *(int *)(param_1 + 0xc);
          local_1c = *(int *)(param_1 + 8);
          local_10 = local_18 + *(int *)(param_1 + 0x14);
          local_14 = *(int *)(param_1 + 0x10) + local_1c;
          *(int *)(param_1 + 0x68) = local_1c;
          *(int *)(param_1 + 0x6c) = local_18;
          *(int *)(param_1 + 0x70) = local_14;
          *(int *)(param_1 + 0x74) = local_10;
          FUN_004a891e();
          FUN_005cddcf(&local_1c);
          FUN_005cce97();
          FUN_004a891e();
          FUN_005cddcf(&local_1c);
          FUN_005cce97();
          if ((*(int *)(param_1 + 0x1c0) - *(int *)(param_1 + 0x1bc)) / 0x44 == 0) {
            FUN_005cf26a(&DAT_006fe6d0);
          }
          iVar3 = FUN_005ce6b8(&DAT_006d61d0,&DAT_006d6190,&DAT_006d6210);
          *(int *)(param_1 + 0x5c) = iVar3;
          if (iVar3 == 0) {
            FUN_005ce7a8();
            _memset(&local_6c,0,0x50);
            local_68 = 0;
            local_64 = 0;
            local_6c = 0x50;
            local_20 = 1;
            local_60 = 0x3f800000;
            local_28 = 0x41a00000;
            local_5c = _DAT_00666578;
            local_58 = 0;
            local_54 = 0;
            local_50 = _DAT_00666578;
            local_4c = _DAT_00666578;
            local_48 = 0;
            local_44 = 0;
            local_40 = 0x3f800000;
            local_3c = _DAT_00666578;
            local_38 = 0;
            local_34 = 0;
            local_30 = 0x3f800000;
            local_2c = _DAT_00666578;
            iVar3 = FUN_005cee52(&local_6c);
            *(int *)(param_1 + 0x5c) = iVar3;
            if (iVar3 == 0) {
              uVar4 = FUN_005cea9b(param_1 + 0x94);
              *(undefined4 *)(param_1 + 0x5c) = uVar4;
            }
          }
        }
      }
    }
  }
  return;
}

