
uint __fastcall FUN_005fa747(int *param_1)

{
  char cVar1;
  uint uVar2;
  int *local_c;
  int *local_8;
  
  local_c = param_1;
  local_8 = param_1;
  cVar1 = (**(code **)(*param_1 + 0x24))();
  if (cVar1 == '\0') {
    uVar2 = ((((uint)param_1[0x29] / (uint)*(ushort *)((int)param_1 + 0xb6)) * 8000) /
            (uint)param_1[0x2b]) * 1000;
  }
  else if ((char)param_1[9] == '\0') {
    (**(code **)(*(int *)param_1[0x20] + 0x10))((int *)param_1[0x20],&local_8,&local_c);
    uVar2 = (((uint)(param_1[0x29] - (int)local_8) / (uint)*(ushort *)((int)param_1 + 0xb6)) * 8000)
            / (uint)param_1[0x2b];
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

