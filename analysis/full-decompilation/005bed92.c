
char __thiscall FUN_005bed92(int *param_1,LPVOID param_2,LPDWORD param_3)

{
  int iVar1;
  int iVar2;
  BOOL BVar3;
  DWORD DVar4;
  DWORD DVar5;
  LPVOID local_c;
  char local_5;
  
  if ((char)param_1[6] == '\0') {
    local_5 = '\0';
  }
  else if (*param_3 == 0) {
    local_5 = '\x01';
  }
  else {
    if (param_1[0x1f] != 0) {
      FUN_005bf04f();
    }
    if (param_1[0x14] == 0) {
      BVar3 = ReadFile((HANDLE)param_1[7],param_2,*param_3,param_3,(LPOVERLAPPED)0x0);
      if (BVar3 == 0) {
        DVar4 = SetFilePointer((HANDLE)param_1[7],0,(PLONG)0x0,1);
        param_1[0x13] = DVar4;
        FUN_005bfa81();
      }
      else {
        param_1[0x13] = param_1[0x13] + *param_3;
      }
      param_1[0x12] = param_1[0x13];
      local_5 = BVar3 != 0;
    }
    else {
      iVar2 = param_1[0x18];
      DVar4 = *param_3;
      local_c = param_2;
      iVar1 = param_1[0x12];
      local_5 = '\x01';
      if ((iVar2 <= iVar1) && (iVar1 < param_1[0x19] + iVar2)) {
        DVar5 = param_1[0x19] - (iVar1 - iVar2);
        if ((int)DVar4 <= (int)DVar5) {
          DVar5 = DVar4;
        }
        FUN_00636510(param_2,param_1[0x15] + (iVar1 - iVar2),DVar5);
        DVar4 = DVar4 - DVar5;
        local_c = (LPVOID)((int)param_2 + DVar5);
        param_1[0x12] = param_1[0x12] + DVar5;
      }
      if (DVar4 != 0) {
        while( true ) {
          param_1[0x18] = 0;
          param_1[0x19] = 0;
          if (param_1[0x13] != param_1[0x12]) {
            iVar2 = (**(code **)(*param_1 + 0x30))(param_1[0x12]);
            local_5 = iVar2 == param_1[0x12];
          }
          if (local_5 == '\0') break;
          local_5 = FUN_005befd3();
          if ((local_5 == '\0') || (DVar5 = param_1[0x19], DVar5 == 0)) break;
          if ((int)DVar4 <= (int)DVar5) {
            DVar5 = DVar4;
          }
          FUN_00636510(local_c,param_1[0x15],DVar5);
          local_c = (LPVOID)((int)local_c + DVar5);
          param_1[0x12] = param_1[0x12] + DVar5;
          DVar4 = DVar4 - DVar5;
          if (DVar4 == 0) break;
        }
      }
      *param_3 = *param_3 - DVar4;
    }
  }
  return local_5;
}

