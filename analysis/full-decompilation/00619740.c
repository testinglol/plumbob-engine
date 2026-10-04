
void FUN_00619740(byte *param_1,int param_2,char *param_3)

{
  byte bVar1;
  undefined4 uVar2;
  int local_10;
  
  uVar2 = FUN_00619870();
  if (0 < param_2) {
    local_10 = param_2;
    do {
      FUN_0061cf80(uVar2,&DAT_006c0a74,(double)param_1[3]);
      FUN_0061cf80(uVar2,&DAT_006c16d8,(double)param_1[2]);
      FUN_0061cf80(uVar2,&DAT_006778b4,(double)param_1[1]);
      FUN_0061cf80(uVar2,&DAT_006778b0,(double)*param_1);
      if ((param_3 != (char *)0x0) && (*param_3 != '\0')) {
        FUN_0061a0c0(uVar2,param_3);
      }
      FUN_0061a0c0(uVar2,&DAT_006c0a74);
      bVar1 = __ftol();
      param_1[3] = bVar1;
      FUN_0061a0c0(uVar2,&DAT_006c16d8);
      bVar1 = __ftol();
      param_1[2] = bVar1;
      FUN_0061a0c0(uVar2,&DAT_006778b4);
      bVar1 = __ftol();
      param_1[1] = bVar1;
      FUN_0061a0c0(uVar2,&DAT_006778b0);
      bVar1 = __ftol();
      *param_1 = bVar1;
      param_1 = param_1 + 4;
      local_10 = local_10 + -1;
    } while (local_10 != 0);
  }
  FUN_00619f60();
  return;
}

