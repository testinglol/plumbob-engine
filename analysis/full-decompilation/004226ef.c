
void __thiscall FUN_004226ef(int *param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int *local_c;
  int *local_8;
  
  if (param_1[0x6b] == 0) {
    if ((short)param_1[0x13] != param_2) {
      iVar2 = 0;
      local_c = param_1;
      local_8 = param_1;
      do {
        if ((short)param_1[0x13] == param_2) {
          return;
        }
        (**(code **)(*param_1 + 0x4c))(1);
        iVar2 = iVar2 + 1;
      } while (iVar2 < 8);
    }
  }
  else if (*(short *)(param_1[0x6b] + 0x4c) != param_2) {
    local_c = (int *)param_1[0x6d];
    local_8 = (int *)param_1[0x6e];
    (**(code **)(*param_1 + 0x50))(1);
    iVar2 = 0;
    do {
      if (*(short *)(param_1[0x6b] + 0x4c) == param_2) break;
      (**(code **)(*param_1 + 0x4c))(1);
      iVar2 = iVar2 + 1;
    } while (iVar2 < 8);
    cVar1 = (**(code **)(*param_1 + 0x54))(&local_c,param_1[0x6f],0,0);
    if (cVar1 != '\0') {
      (**(code **)(*param_1 + 0x58))(&local_c,param_1[0x6f],0,0,1);
    }
  }
  return;
}

