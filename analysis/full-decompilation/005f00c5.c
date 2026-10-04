
undefined1 __thiscall FUN_005f00c5(int param_1,char *param_2,int *param_3)

{
  undefined1 uVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  size_t sVar5;
  short *psVar6;
  short local_898 [1024];
  undefined4 local_98 [2];
  undefined4 local_90 [20];
  undefined4 local_40;
  uint local_30;
  undefined4 *local_2c;
  undefined4 local_28;
  undefined1 local_24 [12];
  LONG local_18;
  int local_14;
  undefined4 local_10;
  int *local_c;
  int *local_8;
  
  local_14 = param_1;
  if (DAT_006d6f9c == '\0') {
    piVar2 = (int *)(**(code **)*DAT_006fe8bc)();
    (**(code **)(*piVar2 + 0x30))(0);
    uVar1 = 0;
  }
  else {
    FUN_005ddda7();
    (**(code **)(*DAT_006fe8bc + 0x18))();
    FUN_005db0b7();
    local_10 = 0;
    local_2c = DAT_006fec9c;
    if ((DAT_006fec9c != (undefined4 *)0x0) &&
       (iVar3 = (**(code **)*DAT_006fec9c)(DAT_006fec9c,&DAT_00677338,&local_10), iVar3 < 0)) {
      local_10 = 0;
    }
    local_8 = (int *)0x0;
    local_c = (int *)0x0;
    if (param_3 != (int *)0x0) {
      iVar3 = (**(code **)*param_3)(param_3,&DAT_006772f8,&local_8);
      if (iVar3 < 0) {
        local_8 = (int *)0x0;
      }
      (**(code **)(*param_3 + 8))(param_3);
    }
    param_3._3_1_ = 0;
    if (local_8 != (int *)0x0) {
      _memset(local_98,0,0x6c);
      local_98[0] = 0;
      (**(code **)(*local_8 + 0x58))(local_8,local_98);
      param_3._3_1_ = (byte)(local_30 >> 9) & 1;
      local_28 = 4;
      iVar3 = (**(code **)(*local_8 + 0x30))(local_8,&local_28,&local_c);
      if (iVar3 < 0) {
        local_c = (int *)0x0;
      }
    }
    local_24._0_4_ = 0;
    local_24._4_4_ = 0;
    local_24._8_4_ = 0;
    local_18 = 0;
    if (local_8 != (int *)0x0) {
      GetClientRect(DAT_006fe8cc,(LPRECT)local_24);
      ClientToScreen(DAT_006fe8cc,(LPPOINT)local_24);
      ClientToScreen(DAT_006fe8cc,(LPPOINT)(local_24 + 8));
      _memset(local_90,0,100);
      local_90[0] = 100;
      local_40 = 0;
      if ((param_3._3_1_ != 0) &&
         ((**(code **)(*local_8 + 0x14))(local_8,local_24,0,0,0x1000400,local_90),
         local_c != (int *)0x0)) {
        (**(code **)(*local_c + 0x14))(local_c,local_24,0,0,0x1000400,local_90);
      }
    }
    if ((DAT_006fe8bc != (int *)0x0) && (iVar3 = (**(code **)(*DAT_006fe8bc + 0x14))(), iVar3 != 0))
    {
      uVar4 = (**(code **)(*DAT_006fe8bc + 0x14))
                        (0,&cITSSndSys::RTTI_Type_Descriptor,&cTSSndSys::RTTI_Type_Descriptor,0);
      iVar3 = FUN_006359f2(uVar4);
      param_1 = local_14;
      if (*(int *)(iVar3 + 0x50) != 0) {
        uVar4 = (**(code **)(*DAT_006fe8bc + 0x14))
                          (0,&cITSSndSys::RTTI_Type_Descriptor,&cTSSndSys::RTTI_Type_Descriptor,0);
        FUN_006359f2(uVar4);
        param_1 = local_14;
      }
    }
    (**(code **)(*(int *)(param_1 + 0x48) + 0x18))();
    (**(code **)(*(int *)(param_1 + 0x48) + 0x24))();
    *(int **)(param_1 + 0x78) = local_8;
    sVar5 = _strlen(param_2);
    iVar3 = 0;
    if (-1 < (int)sVar5) {
      psVar6 = local_898;
      do {
        if (param_2[iVar3] == '/') {
          *psVar6 = 0x5c;
        }
        else {
          *psVar6 = (short)param_2[iVar3];
        }
        iVar3 = iVar3 + 1;
        psVar6 = psVar6 + 1;
      } while (iVar3 <= (int)sVar5);
    }
    FUN_005f03df(local_2c,(int *)(param_1 + 0x70),local_898);
    if (*(int *)(param_1 + 0x70) == 0) {
      piVar2 = (int *)(**(code **)*DAT_006fe8bc)();
      (**(code **)(*piVar2 + 0x30))(0);
      FUN_005dddc1();
      (**(code **)(*DAT_006fe8bc + 0x18))();
      FUN_005db0b7();
    }
    uVar1 = *(undefined1 *)(param_1 + 0x74);
  }
  return uVar1;
}

