
void __thiscall FUN_00475130(int *param_1,int param_2,int param_3,undefined4 *param_4)

{
  int *piVar1;
  int iVar2;
  void *pvVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  ushort local_2c;
  undefined1 auStack_2a [2];
  undefined1 local_28 [2];
  undefined1 local_26;
  undefined1 local_25;
  undefined1 local_24 [4];
  undefined1 local_20 [8];
  undefined1 local_18 [8];
  undefined4 local_10;
  uint local_c;
  undefined4 local_8;
  
  iVar2 = param_2;
  if (10 < param_3) {
    if (param_3 < 0x19) {
      FUN_00464973((int)&param_2 + 2,1);
      local_c = 0;
      if (0 < param_2._2_2_) {
        do {
          local_2c = 0xffff;
          FUN_00464973(&local_10,1);
          if ((ushort)local_10 == 0xffff) {
            _local_2c = CONCAT22(auStack_2a,0xffff);
          }
          else {
            _local_2c = CONCAT22(auStack_2a,local_2c & 0x8000 | (ushort)local_10);
          }
          FUN_00464973(auStack_2a,1);
          FUN_00464973(local_28,1);
          FUN_00464a5e(local_24,1);
          FUN_00464973((int)&local_8 + 2,1);
          FUN_00464973(local_18,4);
          (**(code **)*param_4)(local_20,iVar2,param_3);
          local_26 = 0;
          local_25 = 4;
          if (*(int *)(iVar2 + 0xc) == 0) {
            FUN_0047542b(&local_2c,local_18);
          }
          local_c = local_c + 1;
        } while ((int)local_c < (int)param_2._2_2_);
      }
    }
    else {
      piVar1 = param_1 + 2;
      local_8 = param_1[3] - *piVar1 >> 2;
      FUN_00464a5e(&local_8,1);
      if (*(int *)(iVar2 + 0xc) != 0) {
        local_c = param_1[1] - *param_1;
      }
      FUN_00464a5e(&local_c,1);
      if (*(int *)(iVar2 + 0xc) == 0) {
        pvVar3 = operator_new(local_c);
        *param_1 = (int)pvVar3;
        FUN_005a9250(pvVar3,0,4);
        param_1[1] = *param_1 + local_c;
        FUN_0052ea87(*piVar1,param_1[3]);
      }
      param_2 = 0;
      if (0 < local_8) {
        do {
          if (*(int *)(iVar2 + 0xc) == 0) {
            local_10 = FUN_00475384();
            FUN_0047554d(&local_10);
          }
          iVar4 = iVar2;
          iVar5 = param_3;
          puVar6 = param_4;
          FUN_004754ac(param_2);
          FUN_00474801(iVar4,iVar5,puVar6);
          param_2 = param_2 + 1;
        } while (param_2 < local_8);
      }
      if ((param_1[3] - *piVar1 & 0xfffffffcU) != 0) {
        FUN_004754ac((param_1[3] - *piVar1 >> 2) + -1);
        FUN_00475305();
      }
    }
  }
  return;
}

