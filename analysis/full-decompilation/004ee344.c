
int FUN_004ee344(byte *param_1,int param_2,int param_3)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int local_c;
  
  iVar1 = param_2;
  local_c = 0xbf;
  bVar2 = 0xbf;
  iVar4 = 0;
  if (0 < param_2) {
    iVar3 = param_3 - (int)param_1;
    do {
      if (local_c == 0) {
        local_c = 0xbf;
      }
      local_c = (char)*param_1 * local_c;
      bVar2 = *param_1 ^ bVar2;
      param_1[iVar3] = bVar2;
      param_1 = param_1 + 1;
      param_2 = param_2 + -1;
      iVar4 = iVar1;
    } while (param_2 != 0);
  }
  *(int *)(iVar4 + param_3) = local_c;
  return iVar1 + 4;
}

