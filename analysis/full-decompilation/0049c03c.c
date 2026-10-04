
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0049c03c(int *param_1,undefined4 param_2)

{
  float *pfVar1;
  float *pfVar2;
  float10 fVar3;
  undefined1 local_30 [12];
  float local_24 [5];
  float local_10;
  int local_c;
  int local_8;
  
  if (*param_1 != 0) {
    FUN_0049c12a(_DAT_006f0120,_DAT_006f0124);
    pfVar1 = operator_new(0x1000);
    if ((pfVar1 != (float *)0x0) && (local_8 = 0, 0 < param_1[4])) {
      do {
        local_c = 0;
        if (0 < param_1[3]) {
          local_10 = ((float)local_8 + _DAT_00666748) * _DAT_006683ac;
          pfVar2 = pfVar1;
          do {
            local_24[2] = local_10;
            local_24[0] = ((float)local_c + _DAT_00666748) * _DAT_006683a8;
            local_24[1] = 0.0;
            FUN_0049b849(local_30,param_2,local_24);
            fVar3 = (float10)FUN_0049b828();
            local_c = local_c + 1;
            *pfVar2 = (float)fVar3;
            pfVar2 = pfVar2 + 1;
          } while (local_c < param_1[3]);
        }
        FUN_0049c15e(((param_1[4] - local_8) + -1) * param_1[3] + *param_1,pfVar1,param_1[3]);
        local_8 = local_8 + 1;
      } while (local_8 < param_1[4]);
    }
    FUN_006321f0(pfVar1);
  }
  return;
}

