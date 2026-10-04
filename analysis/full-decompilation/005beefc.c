
uint __thiscall FUN_005beefc(int *param_1,LPCVOID param_2,LPDWORD param_3)

{
  uint in_EAX;
  uint uVar1;
  BOOL BVar2;
  DWORD DVar3;
  
  if ((char)param_1[6] == '\0') {
    uVar1 = in_EAX & 0xffffff00;
  }
  else {
    if (param_1[0x19] != 0) {
      param_1[0x18] = 0;
      param_1[0x19] = 0;
      if (param_1[0x12] != param_1[0x13]) {
        (**(code **)(*param_1 + 0x30))(param_1[0x12]);
      }
    }
    if (param_1[0x1a] == 0) {
      BVar2 = WriteFile((HANDLE)param_1[7],param_2,*param_3,param_3,(LPOVERLAPPED)0x0);
      if (BVar2 == 0) {
        DVar3 = SetFilePointer((HANDLE)param_1[7],0,(PLONG)0x0,1);
        param_1[0x13] = DVar3;
        FUN_005bfa81();
      }
      else {
        param_1[0x13] = param_1[0x13] + *param_3;
      }
      param_1[0x12] = param_1[0x13];
      uVar1 = (uint)(BVar2 != 0);
    }
    else {
      uVar1 = FUN_005bf0b2(param_2,*param_3);
      param_1[0x12] = param_1[0x12] + *param_3;
    }
  }
  return uVar1;
}

