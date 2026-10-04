
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0060f000(int *param_1,int param_2,int param_3,int param_4,int param_5)

{
  int *piVar1;
  byte bVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  byte local_8 [8];
  
  piVar1 = param_1;
  if ((((_DAT_0066657c <= (float)param_2 - _DAT_006da248) &&
       ((float)param_2 - _DAT_006da248 < (float)*(int *)(*param_1 + 0x10))) &&
      (_DAT_0066657c <= (float)param_3 - _DAT_006da24c)) &&
     ((float)param_3 - _DAT_006da24c < (float)*(int *)(*param_1 + 0x14))) {
    if (param_5 == 0) {
      local_8[0] = 0xff;
      local_8[1] = 0xff;
      local_8[2] = 0xff;
      local_8[3] = 0xff;
    }
    else {
      FUN_0060f280(param_5,*(undefined4 *)(param_4 + 0x30),*(undefined4 *)(param_4 + 0x34),local_8);
    }
    bVar2 = local_8[3];
    uVar3 = __ftol();
    uVar4 = __ftol();
    uVar5 = __ftol();
    param_1 = (int *)CONCAT22(CONCAT11(uVar3,uVar4),CONCAT11(uVar5,bVar2));
    uVar3 = __ftol();
    param_1 = (int *)CONCAT31(param_1._1_3_,uVar3);
    FUN_0060f210(piVar1,param_2,param_3,param_1);
    return;
  }
  return;
}

