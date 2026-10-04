
int FUN_005c0787(byte *param_1,int param_2,int param_3)

{
  char cVar1;
  byte *pbVar2;
  int local_8;
  
  local_8 = 0;
  if (param_2 != 0) {
    if ((param_3 == -2) || (param_3 == -1)) {
      param_3 = FUN_005bfe47();
    }
    if ((param_3 == 0) || (param_3 == 0x10)) {
      local_8 = param_2;
    }
    else if (param_3 == 8) {
      pbVar2 = param_1 + param_2;
      for (; param_1 < pbVar2; param_1 = param_1 + 1) {
        if ((*param_1 < 0x80) || (0xbf < *param_1)) {
          local_8 = local_8 + 1;
        }
      }
    }
    else {
      pbVar2 = param_1 + param_2;
      for (; param_1 < pbVar2; param_1 = param_1 + 1) {
        cVar1 = FUN_005c0804(*param_1,param_3);
        if (cVar1 != '\0') {
          param_1 = param_1 + 1;
        }
        local_8 = local_8 + 1;
      }
    }
  }
  return local_8;
}

