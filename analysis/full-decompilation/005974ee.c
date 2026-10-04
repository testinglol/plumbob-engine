
int FUN_005974ee(undefined4 param_1,float *param_2,int param_3,int param_4,int *param_5)

{
  int iVar1;
  int *piVar2;
  char cVar3;
  float *pfVar4;
  int local_18;
  float *local_14;
  float local_10;
  uint local_c;
  undefined2 local_6;
  
  FUN_005975f0();
  piVar2 = param_5;
  local_c = 0;
  local_18 = 0;
  local_10 = 0.0;
  if (0 < param_4) {
    local_14 = param_2;
    do {
      param_2 = (float *)0x0;
      pfVar4 = local_14;
      if (0 < param_3) {
        do {
          if ((int)local_c < 1) {
            cVar3 = FUN_005b9081((int)&param_5 + 3);
            if (cVar3 == '\0') {
              return 0;
            }
            *piVar2 = *piVar2 + 1;
            iVar1 = *piVar2;
            if (param_5._3_1_ == 0xff) {
              cVar3 = FUN_005b9095(&local_10);
              if (cVar3 == '\0') {
                return 0;
              }
              *piVar2 = iVar1 + 4;
            }
            else if (param_5._3_1_ == 0xfe) {
              cVar3 = FUN_005b9081(&local_6);
              if (cVar3 == '\0') {
                return 0;
              }
              cVar3 = FUN_005b9081((int)&local_6 + 1);
              if (cVar3 == '\0') {
                return 0;
              }
              local_c = (uint)local_6;
              *piVar2 = iVar1 + 2;
            }
            else {
              local_10 = local_10 + *(float *)(&DAT_006f7138 + (uint)param_5._3_1_ * 4);
            }
          }
          else {
            local_c = local_c - 1;
          }
          param_2 = (float *)((int)param_2 + 1);
          *pfVar4 = local_10;
          pfVar4 = pfVar4 + param_4;
        } while ((int)param_2 < param_3);
      }
      local_18 = local_18 + 1;
      local_14 = local_14 + 1;
    } while (local_18 < param_4);
  }
  return *piVar2;
}

